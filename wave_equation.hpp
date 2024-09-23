#pragma once
#include <string>
#include <vector>


class WaveEquation
{
public:
	//	конструирует обьект по значени€м из файла (hardcode)
	WaveEquation();

	//	вычисл€ет разностную схему
	void calculating() const;

private:
	//	сохран€ет результат на каждой итерации кратной n_save
	void saveData(const std::vector<double>& data, const std::string& file_name) const;

	//	вычисл€ет значение функции точечного источника (импульс –икера)
	double func(double t) const;

	//	интерпритирует два индексна двумерного массива в один индекс дл€ одноменрного массива
	size_t pos(size_t indexX, size_t indexY) const;

private:
	//	Nx Ц число узлов конечно - разностной схемы по направлению x
	size_t Nx;
	//	Ny - число узлов конечно - разностной схемы по направлению y
	size_t Ny;
	//	Nt Ц число итераций
	size_t Nt;
	//	hx Ц шаг дискретизации по x
	double hx;
	//	hy Ц шаг дискретизации по y
	double hy;
	//	tau Ц шаг по времени
	double tau;
	//	с Ц фазова€ скорость
	std::vector<float> c;
	//	f Ц доминирующа€ частота импульса –икера
	double f;
	//	xs Ц x - координата источника
	double xs;
	//	ys Ц y - координата источника
	double ys;
	//	n_save Ц частота сохранени€ сеточной функции
	size_t n_save;
};
