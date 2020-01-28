#pragma once
#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#pragma warning(disable: 26495)

namespace Spisok1
{
	class Spisok
	{
	private:
		static const int QUOTA = 20;
		int SZ;
		int top;
		int* ar;
	public:
		Spisok() : SZ(QUOTA), top(0), ar(new int[QUOTA]) { }//���������������� ����������� �� ���������
		Spisok(int a) : SZ(QUOTA), top(1), ar(new int[QUOTA]) { ar[0] = a; }//���������������� ����������� ������������� ��������
		Spisok(int count, int a);//���������������� ����������� ������� ������ � ���������
		Spisok(const Spisok&);//���������� �����������
		Spisok(Spisok&&) noexcept;//������������ �����������
		~Spisok() { delete[] ar; }//����������
		int GetElem(int i) const { return ar[i]; }
		Spisok& operator=(const Spisok&);//�������� ������������
		Spisok& operator=(Spisok&&) noexcept;//������������ �������� ������������
		friend std::ostream& operator <<(std::ostream&, const Spisok&);//�����
		friend std::istream& operator >>(std::istream&, Spisok&);//����
		friend const Spisok operator+(const Spisok&, const Spisok&);//������� �������
		int sorts();//������������� �������� 
		Spisok& operator +=(int);//������������� ������ �������� � ������
		int dif_count();//���������� �����
		const Spisok& operator()(int);//������� ���������
		int comp(int a, int b) { return a < b; }//������� ���������
		int size_of_list() { return top; }//������ ������������������
		int max_size_of_list() { return SZ; }//������������ ������ ������������������
	};
}

#endif // HEADER_H