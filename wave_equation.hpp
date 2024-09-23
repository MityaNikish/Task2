#pragma once
#include <string>
#include <vector>


class WaveEquation
{
public:
	//Конструирует объект по значениям из файла (hardcode)
	WaveEquation();

	//Вычисляет разностную схему
	void calculating() const;

private:
	//Сохраняет результат на каждой итерации кратной n_save
	void saveData(const std::vector<double>& data, const std::string& file_name) const;

	//Вычисляет значение функции точечного источника (импульс Рикера)
	double func(double t) const;

	//Интерпритирует два индексна двумерного массива в один индекс для одноменрного массива
	inline size_t pos(size_t indexX, size_t indexY) const;

private:
	//Число узлов конечно - разностной схемы по направлению x
	size_t Nx;
	//Число узлов конечно - разностной схемы по направлению y
	size_t Ny;
	//Число итераций
	size_t Nt;
	//Шаг дискретизации по x
	double hx;
	//Шаг дискретизации по y
	double hy;
	//Шаг по времени
	double tau;
	//Фазовая скорость
	std::vector<float> c;
	//Доминирующая частота импульса Рикера
	double f;
	//Координата источника по x
	double xs;
	//Координата источника по y
	double ys;
	//Частота сохранения сеточной функции
	size_t n_save;
};
