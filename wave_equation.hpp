#pragma once
#include <string>
#include <vector>


class WaveEquation
{
public:
	//������������ ������ �� ��������� �� ����� (hardcode)
	WaveEquation();

	//��������� ���������� �����
	void calculating() const;

private:
	//��������� ��������� �� ������ �������� ������� n_save
	void saveData(const std::vector<double>& data, const std::string& file_name) const;

	//��������� �������� ������� ��������� ��������� (������� ������)
	double func(double t) const;

	//�������������� ��� �������� ���������� ������� � ���� ������ ��� ������������ �������
	inline size_t pos(size_t indexX, size_t indexY) const;

private:
	//����� ����� ������� - ���������� ����� �� ����������� x
	size_t Nx;
	//����� ����� ������� - ���������� ����� �� ����������� y
	size_t Ny;
	//����� ��������
	size_t Nt;
	//��� ������������� �� x
	double hx;
	//��� ������������� �� y
	double hy;
	//��� �� �������
	double tau;
	//������� ��������
	std::vector<float> c;
	//������������ ������� �������� ������
	double f;
	//���������� ��������� �� x
	double xs;
	//���������� ��������� �� y
	double ys;
	//������� ���������� �������� �������
	size_t n_save;
};
