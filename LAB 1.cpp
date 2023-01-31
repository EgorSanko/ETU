#include <iostream>
#include <iomanip>

using namespace std;
int main()
{
    setlocale(0, "");
    //1) �������, ������� ������ (� ������) �� ����� ���������� ��������� ��� ��������� ���� ������ �� ��������������� � ���: int, short int, long int, float, double, long double, char � bool.
    cout << "int=" << sizeof(int) << setw(22) << "  ��������� " << sizeof(int) << " ����� �� ����� ����������" << endl;
    cout << "short=" << sizeof(short) << setw(20) << "  ��������� " << sizeof(short) << " ����� �� ����� ����������" << endl;
    cout << "short int =" << sizeof(short int) << setw(15) << "  ��������� " << sizeof(short int) << " ����� �� ����� ����������" << endl;
    cout << "long int=" << sizeof(long  int) << setw(17) << "  ��������� " << sizeof(long  int) << " ����� �� ����� ����������" << endl;
    cout << "float=" << sizeof(float) << setw(20) << "  ��������� " << sizeof(float) << " ����� �� ����� ����������" << endl;
    cout << "double=" << sizeof(double) << setw(19) << "  ��������� " << sizeof(double) << " ���� �� ����� ����������" << endl;
    cout << "long double=" << sizeof(long double) << setw(14) << "  ��������� " << sizeof(long double) << " ���� �� ����� ����������" << endl;
    cout << "char=" << sizeof(char) << setw(21) << "  ��������� " << sizeof(char) << " ���� �� ����� ����������" << endl;
    cout << "bool=" << sizeof(bool) << setw(21) << "  ��������� " << sizeof(bool) << " ���� �� ����� ����������" << endl;
    //2) ������� �� ����� �������� ������������� � ������ (��� �������) ������ �����. ��� ������ ���������� ��������� ���������� �������� ������ � �������� ������� ��������� ��� ������.
    cout << "Enter int: ";
    unsigned int input;
    cin >> input;
    int a = sizeof(int) * 8;
     int mask = 1 << a - 1;
    for (int i = 1; i <= a; i++)
    {
        cout << ((input & mask) ? 1 : 0);
        if (i == 1 || i % 8 == 0)
            cout << " ";

        input <<= 1;
       
    }
    
    cout << endl;
    //3)������� �� ����� �������� ������������� � ������(��� �������) ���� float.��� ������ ���������� ��������� ���������� �������� ������ ��������, �������� ������ �������(���� ����), �������� � �������.
    union {
        int tool;
        float f;
    };
    cout << "Enter float: ";
    cin >> f;
    for (int i = 1; i <= a; i++)
    {
        cout << ((tool & mask) ? 1 : 0);
        if (i == 1 || i % 8 == 0)
            cout << " ";
        tool <<= 1;
    }
    cout << endl;
    //4) ������� �� ����� �������� ������������� � ������ (��� �������) ���� double. ��� ������ ���������� ��������� ���������� �������� ������ ��������, �������� ������ ������� (���� ����), �������� � �������. (*)
    union {
        double d;
        int arr[2];
    };
    cout << "Enter double: ";
    cin >> d;
    for (int i = 1; i <= a; i++)
    {
        cout << ((arr[1] & mask) ? 1 : 0);
        if (i == 1 || i % 8 == 0)
            cout << " ";
        arr[1] <<= 1;
    }
    for (int i = 1; i <= a; i++)
    {
        cout << ((arr[0] & mask) ? 1 : 0);
        if (i % 8 == 0)
            cout << " ";
        arr[0] <<= 1;
    }
    cout << "\n\n";
}