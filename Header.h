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
		Spisok() : SZ(QUOTA), top(0), ar(new int[QUOTA]) { }//инициализирующий конструктор по умолчанию
		Spisok(int a) : SZ(QUOTA), top(1), ar(new int[QUOTA]) { ar[0] = a; }//инициализирующий конструктор единственного элемента
		Spisok(int count, int a);//инициализирующий конструктор размера списка и элементов
		Spisok(const Spisok&);//копирующий конструктор
		Spisok(Spisok&&) noexcept;//перемещающий конструктор
		~Spisok() { delete[] ar; }//деструктор
		int GetElem(int i) const { return ar[i]; }
		Spisok& operator=(const Spisok&);//оператор присваивания
		Spisok& operator=(Spisok&&) noexcept;//перемещающий оператор присваивания
		friend std::ostream& operator <<(std::ostream&, const Spisok&);//вывод
		friend std::istream& operator >>(std::istream&, Spisok&);//ввод
		friend const Spisok operator+(const Spisok&, const Spisok&);//слияние списков
		int sorts();//упорядоченные элементы 
		Spisok& operator +=(int);//присоединение нового элемента в список
		int dif_count();//количество групп
		const Spisok& operator()(int);//частота появления
		int comp(int a, int b) { return a < b; }//функция сравнения
		int size_of_list() { return top; }//размер последовательности
		int max_size_of_list() { return SZ; }//максимальный размер последовательности
	};
}

#endif // HEADER_H