#include <iostream>
#include <fstream>
#include <Windows.h>
#include <string>

using namespace std;

void Print(string);
string Task1(string);
string RemoveSpacebars(string);
string RemovePunctuationMarks(string);
string FixLetterCase(string);
string Task2(string);
bool NumberCheck(string);
void Task3(string);
string RemoveChar(string, string);
void Task4(string);
void LinearSearch(string, string);
void Task5(string);

int main() {
	setlocale(0, "");

	// 1) ������ ������
	// 
	string str;
	str = Task1(str);

	// 2) ����������� ������
	str = Task2(str);
	system("pause");

	// 3.3) ������� ����� ��� ����
	Task3(str);
	system("pause");

	// 4.3) ������� ����� ��� ��������� ������ ���� (��� ����)
	Task4(str);
	system("pause");

	// 5) ����� ��������� � ������
	Task5(str);

	return 0;
}

void Print(string str) {
	cout << str << endl << endl;
}
string Task1(string str) {
	cout << "\t\t\t������� 1\n";
	cout << "������� �������� ������:\n";
	getline(cin, str);
	cout << endl;
	return str;
}
string RemoveSpacebars(string str) {
	int len = str.length();
	while (str[0] == ' ')
		str.erase(0, 1);

	len = str.length();
	while (str[len - 2] == ' ') {
		str.erase(len - 2, 1);
		len = str.length();
	}

	len = str.length();
	int count = 0;
	for (int i = 0; i < len - 1 - count; i++) {
		if (str[i] == ' ' && str[i + 1] == ' ') {
			str.erase(i, 1);
			--i;
			++count;
		}
	}
	return str;
}
string RemovePunctuationMarks(string str) {
	int len = str.length();
	int count = 0;
	for (int i = 0; i < len - 1 - count; i++) {
		if ((int(str[i]) >= 33 && int(str[i]) <= 47 && str[i] == str[i + 1]) || (int(str[i]) >= 58 && int(str[i]) <= 63 && str[i] == str[i + 1])) {
			str.erase(i, 1);
			--i;
			++count;
		}
	}
	return str;
}
string FixLetterCase(string str) { // 65-90
	int len = str.length();
	for (int i = 0; i < len; i++) {
		if (int(str[i]) >= 65 && int(str[i]) <= 90)
			str[i] += 32;
	}
	return str;
}
string Task2(string str) {
	cout << "\n\t\t\t������� 2\n";
	str = RemoveSpacebars(str);
	cout << "��� ������ ��������:\n";
	Print(str);

	str = RemovePunctuationMarks(str);
	cout << "��� ������ ������ ����������:\n";
	Print(str);

	str = FixLetterCase(str);
	cout << "� ������ ��������� ����:\n";
	Print(str);

	return str;
}
bool NumberCheck(string str) {
	int len = str.length();
	for (int i = 0; i < len; i++)
		if (int(str[i]) >= 48 && int(str[i]) <= 57)
			return 0;
	return 1;
}
void Task3(string str) { // 97-122
	cout << "\n\t\t\t������� 3.3\n";
	string line = "";
	string word = "";
	int len = str.length();
	for (int i = 0; i < len; i++) {
		if (!((int(str[i]) >= 32 && int(str[i]) <= 47) || (int(str[i]) >= 58 && int(str[i]) <= 63))) {
			word += str[i];
		}
		else {
			if (NumberCheck(word)) {
				line += word;
				line += " ";
			}
			word = "";
		}
	}
	line = RemoveSpacebars(line);
	cout << "����� ��� ����:\n";
	Print(line);
}
string RemoveChar(string str, string list) {
	int len = str.length();
	int l_len = list.length();
	int count = 0;
	for (int i = 0; i < len - count; i++) {
		int help = 0;
		for (int j = 0; j < l_len; j++) {
			if (str[i + help] == list[j]) {
				str.erase(i, 1);
				--i;
				++count;
				++help;
			}
		}
	}
	return str;
}
void Task4(string str) {
	cout << "\n\t\t\t������� 4.3\n";
	string line = "";
	string word = "";
	string list;
	cout << "������� ����� ���� (��� ����), ������� ����� �������, ��� ��������:\n";
	getline(cin, list);
	int len = str.length();
	for (int i = 0; i < len; i++) {
		if (!((int(str[i]) >= 32 && int(str[i]) <= 47) || (int(str[i]) >= 58 && int(str[i]) <= 63))) {
			word += str[i];
		}
		else {
			word = RemoveChar(word, list);
			line += word;
			line += " ";
			word = "";
		}
	}
	line = RemoveSpacebars(line);
	cout << "\n����� ��� ��������� ������ ��������:\n";
	Print(line);
}
void LinearSearch(string str, string sub) {
	cout << endl;
	int len = str.length();
	int s_len = sub.length();
	bool include = 0;
	for (int i = 0; i < len - s_len + 1; i++) {
		if (str[i] == sub[0]) {
			int count = 1;
			for (int j = 1; j < s_len; j++) {
				if (str[i + j] == sub[j])
					++count;
			}
			if (count == s_len) {
				cout << i << " ";
				include = 1;
			}
		}
	}
	switch (include) {
	case 0:
		cout << "����� ��������� ��� � ������.\n";
		break;
	case 1:
		cout << "- ������(-�) ���������.\n";
		break;
	}
}
void Task5(string str) {
	cout << "\n\t\t\t������� 5\n";
	string sub;
	cout << "������� ������� ���������:\n";
	getline(cin, sub);
	bool choice;
	cout << "\n�������� ��������.\n�������� ����� - 0; ����� ��� - 1: ";
	cin >> choice;
	switch (choice) {
	case 0:
		LinearSearch(str, sub);
		break;
	}

}