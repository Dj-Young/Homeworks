#include <iostream>
#include <iomanip>

using namespace std;


void mas_copy(unsigned long long *mas, unsigned long long *new_mas, unsigned long long new_mas_len)		//Функция копирования массивов (массивы должны быть одинаковой длины)
{
	for (unsigned long long i = 0; i < new_mas_len; i++)
		new_mas[i] = mas[i];
}


unsigned long long* increase(unsigned long long *mas, unsigned long long size, unsigned long long new_size)
{
	unsigned long long *new_mas = new unsigned long long[new_size];
	for (int i = 0; i < size; i++)
		new_mas[i] = mas[i];
	for (int i = size; i < new_size; i++)
		new_mas[i] = 0;
	return new_mas;
}

void main()
{
	//Переменные
	unsigned long long lines = 0;						//Кол-во строк треугольника паскаля
	unsigned long long pre_line_len = 2;						//Длинна предыдушей строки
	unsigned long long new_line_len = 3;						//Длинна новой 
	unsigned long long *pre_line = new unsigned long long[pre_line_len];		//Старая строка треугольника паскаля
	unsigned long long *new_line = new unsigned long long[new_line_len];
	unsigned long long *tmp_mas = new unsigned long long[new_line_len];

	//---------------------
	setlocale(LC_ALL, "Rus");
	cout << "Введите количество строк треугольника паскаля: ";
	cin >> lines;
	if (lines == 1)
		cout << setw(5) << "1";
	else if (lines == 2)
		cout << setw(5) << "1" << endl << setw(5) << "1" << setw(5) << "1" << endl;
	else
	{
		cout << setw(lines / 2) << "1" << endl << setw(lines/2) << "1" << setw(lines/2) << "1" << endl;
		pre_line[0] = 1; pre_line[1] = 1;			//Инициализация второй строки треугольника паскаля
		for (int i = 0; i < lines; i++)
		{
			new_line[0] = 1;
			for (int counter = 1; counter < pre_line_len; counter++)
			{
				new_line[counter] = pre_line[counter - 1] + pre_line[counter];
			}
			new_line[pre_line_len] = 1;
			for (int j = 0; j < new_line_len; j++)
			{
				cout << setw(lines / 2) << new_line[j];
			}
			cout << endl;
			mas_copy(new_line, tmp_mas, new_line_len);
			pre_line = increase(pre_line, pre_line_len, new_line_len);
			mas_copy(tmp_mas, pre_line, new_line_len);
			++new_line_len;
			++pre_line_len;
			new_line = increase(new_line, pre_line_len, new_line_len);
		}
	}


	delete[] pre_line;
	delete[] new_line;
}