#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>

using namespace std;

fstream open_file(string filename)
{
	fstream read_file;
	char* file = new char[1024];
	
	do
	{
		system("cls");
		cout << "������� ��� ����� (�� ��������� test.txt): ";
		cin.get(file,1024);
		if (file == "\0")
			read_file.open(file);
		else
			read_file.open(filename);
		if (!read_file.is_open())
			cout << "������� ������� ��� �����!";
	} while (!read_file.is_open());
	return read_file;
}

void MSD_sort(string* str_mas, const unsigned int str_counter)
{
	string** stack = new string* [26];
	for (int i = 0; i < 26; ++i)
		stack[i] = new string[str_counter];
	for (int i = 0; i < 26; ++i)
		for (int j = 0; j < str_counter; ++j)
			stack[i][j] = "0";

	string str, tmp;
	unsigned int letter_num = 0;
	int k = 0;

	for (int i = 0; i < str_counter; ++i)
	{
		str = str_mas[i];
		letter_num = tolower(str[0]) - 97;
		k = 0;
		while (stack[letter_num][k] != "0")
			++k;
		stack[letter_num][k] = str;
	}
	int offset = 1;
	for(int i = 0;i<26;++i)
		for (int j = 0; j < str_counter; ++j)
		{
			if (stack[i][j] != "0" && stack[i][j+1] != "0")
			{
				str = stack[i][j];
				tmp = stack[i][j + 1];
				if (str[offset] != ' ' && tmp[offset] != ' ' && tolower(str[offset]) > tolower(tmp[offset]))
					swap(stack[i][j], stack[i][j + 1]);
			}
		}

	int r = 0;
	for (int i = 0; i < 26; ++i)
		for (int j = 0; j < str_counter; ++j)
			if (stack[i][j] != "0")
			{
					str_mas[r] = stack[i][j];
					++r;
			}

	for (int i = 0; i < 26; ++i)
		delete[] stack[i];
	delete[] stack;
}

void main()
{
	setlocale(LC_ALL, "Rus");
	//������������� ������ � ����� � ���������� �������

	string filename = "test.txt";
	char* str = new char[1024];				//������ �� �����
	unsigned int str_counter = 0;			//���-�� ����� � �����
	fstream file;							//����

	//��������� ����
	file = open_file(filename);

	//������� ���-�� ����� � �����
	while (!file.eof())
	{
		file.getline(str, 1024, '\n');
		if (strlen(str) > 1)
			++str_counter;
	}

	string* string_mas = new string[str_counter];	//������ �� ����� �������� �� �����

	//������������ � ������ �����
	file.clear(); file.seekg(0);

	//�������� ��� ������ � ������
	for (int i = 0;i < str_counter;)
	{
		file.getline(str, 1024, '\n');
		if (strlen(str) > 1)
		{
			string_mas[i] = str;
			++i;
		}
	}

	MSD_sort(string_mas, str_counter);
	file.clear(); file.seekg(0);
	for (int i = 0; i < str_counter; ++i)
	{
		file << string_mas[i] << '\n';
	}

	file.close();
}