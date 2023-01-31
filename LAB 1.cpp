#include <iostream>
#include <iomanip>

using namespace std;
int main()
{
    setlocale(0, "");
    //1) Вывести, сколько памяти (в байтах) на вашем компьютере отводится под различные типы данных со спецификаторами и без: int, short int, long int, float, double, long double, char и bool.
    cout << "int=" << sizeof(int) << setw(22) << "  Отводится " << sizeof(int) << " байта на вашем компьютере" << endl;
    cout << "short=" << sizeof(short) << setw(20) << "  Отводится " << sizeof(short) << " байта на вашем компьютере" << endl;
    cout << "short int =" << sizeof(short int) << setw(15) << "  Отводится " << sizeof(short int) << " байта на вашем компьютере" << endl;
    cout << "long int=" << sizeof(long  int) << setw(17) << "  Отводится " << sizeof(long  int) << " байта на вашем компьютере" << endl;
    cout << "float=" << sizeof(float) << setw(20) << "  Отводится " << sizeof(float) << " байта на вашем компьютере" << endl;
    cout << "double=" << sizeof(double) << setw(19) << "  Отводится " << sizeof(double) << " байт на вашем компьютере" << endl;
    cout << "long double=" << sizeof(long double) << setw(14) << "  Отводится " << sizeof(long double) << " байт на вашем компьютере" << endl;
    cout << "char=" << sizeof(char) << setw(21) << "  Отводится " << sizeof(char) << " байт на вашем компьютере" << endl;
    cout << "bool=" << sizeof(bool) << setw(21) << "  Отводится " << sizeof(bool) << " байт на вашем компьютере" << endl;
    //2) Вывести на экран двоичное представление в памяти (все разряды) целого числа. При выводе необходимо визуально обозначить знаковый разряд и значащие разряды отступами или цветом.
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
    //3)Вывести на экран двоичное представление в памяти(все разряды) типа float.При выводе необходимо визуально обозначить знаковый разряд мантиссы, знаковый разряд порядка(если есть), мантиссу и порядок.
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
    //4) Вывести на экран двоичное представление в памяти (все разряды) типа double. При выводе необходимо визуально обозначить знаковый разряд мантиссы, знаковый разряд порядка (если есть), мантиссу и порядок. (*)
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