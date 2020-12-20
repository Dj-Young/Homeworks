#include <iostream>
#include <string>
#include <fstream>

using namespace std;

char Base64Char_decode(char b) {
	if (b == '=') return 0;
	char Base64Alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
	for (int i = 0; i < strlen(Base64Alphabet); ++i)
		if (b == Base64Alphabet[i])
			return i;
}

string base64_decode(char* str64,int str_len)
{
	string decoded = "";
	for (int i = 0; i < str_len; i += 4)
	{
		int a1, a2, a3, a4;
		char b1, b2, b3;

		a1 = Base64Char_decode(str64[i]);
		if (i + 1 < str_len) a2 = Base64Char_decode(str64[i + 1]);
		if (i + 2 < str_len) a3 = Base64Char_decode(str64[i + 2]);
		if (i + 3 < str_len) a4 = Base64Char_decode(str64[i + 3]);

		a1 = a1 << 2; a2 = a2 << 2; a3 = a3 << 2; a4 = a4 << 2;

		b1 = (a1 | a2 >> 6) & 0xFF;
		b2 = (a2 << 2 | a3 >> 4) & 0xFF;
		b3 = (a3 << 4 | a4 >> 2) & 0xFF;
		decoded += b1; decoded += b2; decoded += b3;
	}
	return decoded;
}

void main()
{
	setlocale(LC_ALL, "Rus");
	ifstream in_file;
	ofstream out_file;
	string in_filename, out_filename, result;
	char* str = new char[1024];
	do
	{
		cout << "Введите название входного файла: ";
		cin >> in_filename;
		in_file.open(in_filename);
		if (!in_file.is_open())
			cout << "Файл не найден!" << endl;
	} while (!in_file.is_open());

	do
	{
	cout << "Введите название входного файла: ";
	cin >> in_filename;
	out_file.open(in_filename);
	if (!out_file.is_open())
		cout << "Недостаточно прав для чтения или создания файла!" << endl;
	} while (!out_file.is_open());

	in_file.getline(str,1024);

	out_file << base64_decode(str, strlen(str));
	in_file.close();
	out_file.close();
}
