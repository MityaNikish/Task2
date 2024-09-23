#pragma once
#include <string>
#include <vector>


class WaveEquation
{
public:
	//	������������ ������ �� ��������� �� ����� (hardcode)
	WaveEquation();

	//	��������� ���������� �����
	void calculating() const;

private:
	//	��������� ��������� �� ������ �������� ������� n_save
	void saveData(const std::vector<double>& data, const std::string& file_name) const;

	//	��������� �������� ������� ��������� ��������� (������� ������)
	double func(double t) const;

	//	�������������� ��� �������� ���������� ������� � ���� ������ ��� ������������ �������
	size_t pos(size_t indexX, size_t indexY) const;

private:
	//	Nx � ����� ����� ������� - ���������� ����� �� ����������� x
	size_t Nx;
	//	Ny - ����� ����� ������� - ���������� ����� �� ����������� y
	size_t Ny;
	//	Nt � ����� ��������
	size_t Nt;
	//	hx � ��� ������������� �� x
	double hx;
	//	hy � ��� ������������� �� y
	double hy;
	//	tau � ��� �� �������
	double tau;
	//	� � ������� ��������
	std::vector<float> c;
	//	f � ������������ ������� �������� ������
	double f;
	//	xs � x - ���������� ���������
	double xs;
	//	ys � y - ���������� ���������
	double ys;
	//	n_save � ������� ���������� �������� �������
	size_t n_save;
};
