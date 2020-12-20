#include <iostream>
#include <fstream>
#include <string>

using namespace std;

fstream Open_file()
{
	fstream file;
	string filename;
	cout << "Введите имя файла: ";
	cin >> filename;
	file.open(filename);
	while (!file.is_open())
	{
		system("cls");
		cout << "Имя файла введено не верно!" << endl << "Введите имя заново: ";
		cin >> filename;
		file.open(filename);
	}
	cout << "Файл открыт!";
	return file;
}

void main()
{
	setlocale(LC_ALL, "Rus");
	fstream file;
	ofstream new_file;
	string new_file_name;
	file = Open_file();
	int lett;

	int* mas = new int[255];
	for (int i = 0; i < 255; ++i)
		mas[i] = 0;

	while(!file.eof())
		if(file.get() != '\n')
			++mas[int(file.get())];

	cout << endl << "Введите имя файла для Гистограммы: ";
	cin >> new_file_name;
	new_file.open(new_file_name);
	if (!new_file.is_open())
	{
		cout << "Ошибка открытия!";
		exit(-1);
	}
	int max = 0;
	for (int i = 0; i < 255; ++i)
		if (mas[i] > max)
			max = mas[i];
	for (int i = 0; i < max; ++i)
	{
		for (int j = 0; j < 255; ++j)
		{
			if (max - mas[j] > i && mas[j] > 0)
				new_file << "   ";
			else if(mas[j] > 0 && max - mas[j] <= i)
				new_file << " * ";
		}
		new_file << endl;
	}
	bool is_first = false;
	for (int i = 0; i < 255; ++i)
	{
		if (i == 10)
		{
			if (is_first == false)
				new_file << "\\n" << " ";
			else
				new_file << "" << "\\n" << "";
			continue;
		}
		if (mas[i] > 0)
		{
			if (is_first == false)
			{
				cout << char(i) << "";
				is_first = true;
			}
			new_file << " " << char(i) << " ";
		}
	}
}
