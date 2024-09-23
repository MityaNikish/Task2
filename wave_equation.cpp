#include "wave_equation.hpp"
#include <fstream>
#include <iostream>
#include <cmath>

namespace
{
	constexpr double PI = 3.14159265358979;
}

WaveEquation::WaveEquation()
{
	std::ifstream fin1("input.txt");
	fin1 >> Nx;
	fin1 >> Ny;
	fin1 >> Nt;
	fin1 >> hx;
	fin1 >> hy;
	fin1 >> tau;
	fin1 >> f;
	fin1 >> xs;
	fin1 >> ys;
	fin1 >> n_save;
	fin1.close();

	//std::cout << Nx << std::endl;
	//std::cout << Ny << std::endl;
	//std::cout << Nt << std::endl;
	//std::cout << hx << std::endl;
	//std::cout << hy << std::endl;
	//std::cout << tau << std::endl;
	//std::cout << f << std::endl;
	//std::cout << xs << std::endl;
	//std::cout << ys << std::endl;
	//std::cout << n_save << std::endl;

	c.resize(Nx * Ny, 0);

	std::ifstream fin2("c.raw", std::ios_base::binary);
	fin2.read((char*)(c.data()), sizeof(float) * Nx * Ny);
	fin2.close();

}

void WaveEquation::calculating() const
{
	std::vector<double> data_pref(Nx * Ny, 0);
	std::vector<double> data(Nx * Ny, 0);
	std::vector<double> data_next(Nx * Ny, 0);

	const double hx_sqr = hx * hx;
	const double hy_sqr = hy * hy;
	const double tau_sqr = tau * tau;

	for (size_t n = 1; n <= Nt; ++n)
	{
		for (size_t j = 0; j < Ny; ++j)
		{
			for (size_t i = 0; i < Nx; ++i)
			{
				const double t = tau * static_cast<double>(n);

				const double Lx_plus = i == (Nx - 1) ? 0 : (data[pos(i + 1, j)] - data[pos(i, j)]);
				const double Lx_minus = i == 0 ? 0 : (data[pos(i, j)] - data[pos(i - 1, j)]);
				const double Lxx = (Lx_plus - Lx_minus) / hx_sqr;

				const double Ly_plus = j == (Ny - 1) ? 0 : (data[pos(i, j + 1)] - data[pos(i, j)]);
				const double Ly_minus = j == 0 ? 0 : (data[pos(i, j)] - data[pos(i, j - 1)]);
				const double Lyy = (Ly_plus - Ly_minus) / hy_sqr;

				const double core = c[pos(i, j)] * c[pos(i, j)] * (Lxx + Lyy) + (i * hx == xs && j * hy == ys) ? 0 : func(t) / (hx * hy);
				data_next[pos(i, j)] = tau_sqr * core + 2 * data[pos(i, j)] - data_pref[pos(i, j)];
			}
		}
		std::swap(data_pref, data);
		std::swap(data, data_next);
		if (n % n_save == 0)
		{
			saveData(data, "save\\output_" + std::to_string(n) + ".raw");
		}
	}
}

void WaveEquation::saveData(const std::vector<double>& data, const std::string& file_name) const
{
	std::ofstream fout(file_name, std::ios_base::binary);
	fout.write((char*)(data.data()), sizeof(double) * Nx * Ny);
	fout.close();
}

double WaveEquation::func(const double t) const
{
	const double part = PI * f * pow(t - 2 / f, 2);
	return (1 - 2 * PI * f * part) * exp(-part);
}

size_t WaveEquation::pos(size_t indexX, size_t indexY) const
{
	return indexY * Nx + indexX;
}