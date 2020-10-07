#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void main()
{
	setlocale(LC_ALL, "Rus");

	string from_file, to_file;
	char buff[1024];
	cout << "Введите из какого файла нужно скопировать: ";
	cin >> from_file;
	cout << "Введите в какой файл нужно копировать(Если файл не будет найден, будет создан новый): ";
	cin >> to_file;

	ofstream out_file;			//В этот файл записываем
	ifstream in_file;			//Из этого файла считываем
	in_file.open(from_file);
	out_file.open(to_file);

	if (!in_file)
	{
		cout << "Исходный файл не найден!";
		return;
	}

	do
	{
		in_file.getline(buff, 1024);
		out_file << buff << '\n';
	} while (!in_file.eof());

	cout << "Копирование закончилось!";

	in_file.close(); out_file.close();
	system("pause");
}