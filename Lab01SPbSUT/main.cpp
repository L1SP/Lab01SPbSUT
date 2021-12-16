#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int c = -1;
	bool read = 0;
	ifstream ifs("input.txt");
	string** s = new string * [5];
	for (int i = 0; i < 5; ++i) {
		s[i] = new string[3];
	}
	while (c != 6) {
		cout << "Выберите пункт меню:\n";
		cout << "1. Чтение данных из файла в динамический массив.\n";
		cout << "2. Просмотр данных, хранящихся в массиве.\n";
		cout << "3. Корректировка данных заданной строки.\n";
		cout << "4. Вычисления.\n";
		cout << "5. Сохранение данных в новом файле (имя файла вводится с клавиатуры).\n";
		cout << "6. Завершить работу программы.\n";
		cin >> c;
		switch (c) {
		case 1: {
			if (ifs) {
				for (int i = 0; i < 5; ++i) {
					for (int j = 0; j < 3; ++j) {
						ifs >> s[i][j];
					}
				}
				read = 1;
				cout << "Файл успешно прочитан.\n";
			}
			else {
				cout << "Ошибка при чтении файла.\n";
				return -1;
			}
			break;
		}
		case 2: {
			if (read) {
				cout << "Массив:\n";
				for (int i = 0; i < 5; ++i) {
					for (int j = 0; j < 3; ++j) {
						cout << s[i][j] << " ";
					}
					cout << endl;
				}
			}
			else {
				cout << "Файл еще не прочитан.\n";
			}
			break;
		}
		case 3: {
			if (read) {
				cout << "Введите номер строки для корректировки данных:\n";
				int tmp;
				cin >> tmp;
				cout << "Вводите новые данные строки:\n";
				for (int j = 0; j < 3; ++j) {
					cin >> s[tmp-1][j];
				}
			}
			else {
				cout << "Файл еще не прочитан.\n";
			}
			break;
		}
		case 4: {
			if (read) {
				double sum = 0;
				for (int i = 0; i < 5; ++i) {
					sum += stod(s[i][1]) * stod(s[i][2]);
				}
				cout << "Сумма заработной платы всех сотрудников: " << sum << '\n';
			}
			else {
				cout << "Файл еще не прочитан.\n";
			}
			break;
		}
		case 5: {
			if (read) {
				cout << "Введите имя файла для вывода:\n";
				string tmp;
				cin >> tmp;
				tmp+=".txt";
				ofstream outfile(tmp);
				for (int i = 0; i < 5; ++i) {
					for (int j = 0; j < 3; ++j) {
						outfile << s[i][j] << " ";
					}
					outfile << endl;
				}
				if (outfile) {
					cout << "Файл успешно создан.\n";
				}
				else {
					cout << "Не удалось создать файл.\n";
				}
			}
			else {
				cout << "Файл еще не прочитан.\n";
			}
			break;
		}
		}
	}
	for (int i = 0; i < 5; ++i) {
		delete[]s[i];
	}
	delete[]s;
	return 0;
}