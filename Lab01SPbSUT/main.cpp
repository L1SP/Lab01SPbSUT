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
		cout << "�������� ����� ����:\n";
		cout << "1. ������ ������ �� ����� � ������������ ������.\n";
		cout << "2. �������� ������, ���������� � �������.\n";
		cout << "3. ������������� ������ �������� ������.\n";
		cout << "4. ����������.\n";
		cout << "5. ���������� ������ � ����� ����� (��� ����� �������� � ����������).\n";
		cout << "6. ��������� ������ ���������.\n";
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
				cout << "���� ������� ��������.\n";
			}
			else {
				cout << "������ ��� ������ �����.\n";
				return -1;
			}
			break;
		}
		case 2: {
			if (read) {
				cout << "������:\n";
				for (int i = 0; i < 5; ++i) {
					for (int j = 0; j < 3; ++j) {
						cout << s[i][j] << " ";
					}
					cout << endl;
				}
			}
			else {
				cout << "���� ��� �� ��������.\n";
			}
			break;
		}
		case 3: {
			if (read) {
				cout << "������� ����� ������ ��� ������������� ������:\n";
				int tmp;
				cin >> tmp;
				cout << "������� ����� ������ ������:\n";
				for (int j = 0; j < 3; ++j) {
					cin >> s[tmp-1][j];
				}
			}
			else {
				cout << "���� ��� �� ��������.\n";
			}
			break;
		}
		case 4: {
			if (read) {
				double sum = 0;
				for (int i = 0; i < 5; ++i) {
					sum += stod(s[i][1]) * stod(s[i][2]);
				}
				cout << "����� ���������� ����� ���� �����������: " << sum << '\n';
			}
			else {
				cout << "���� ��� �� ��������.\n";
			}
			break;
		}
		case 5: {
			if (read) {
				cout << "������� ��� ����� ��� ������:\n";
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
					cout << "���� ������� ������.\n";
				}
				else {
					cout << "�� ������� ������� ����.\n";
				}
			}
			else {
				cout << "���� ��� �� ��������.\n";
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