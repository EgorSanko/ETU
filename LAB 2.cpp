#include <iostream>
#include <chrono>
#include <time.h>
using namespace std;
using namespace chrono;

int main()
{
	setlocale(LC_ALL, "Russian");
	// 1) создаём массив
	cout << "Задание 1" << endl;
	cout << "Неотсортированнный массив:" << endl;
	const int N = 100;
	int arr[N], arr3[N];
	srand(time(0));
	for (int i = 0; i < N; i++)
	{
		arr[i] = rand() % 199 - 99;
		arr3[i] = arr[i];
	}
	for (int i = 0; i < N; i++)
		cout << arr[i] << " ";
	cout << endl << endl;



	// 2) сортируем и определяем затраченное время
	cout << "Задание 2" << endl;
	cout << "Отсортированный массив:" << endl;
	auto start = system_clock::now();
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
				swap(arr[j], arr[j + 1]);
		}
	}
	auto end = system_clock::now();
	auto result = duration_cast<nanoseconds>(end - start);
	for (int i = 0; i < N; i++)
		cout << arr[i] << " ";
	cout << endl;
	cout << "Время сортировки составляет " << result.count() << " nanosec." << endl << endl;//Выводим время сортировки.

	// 3) Находим макс. и мин., считаем время 
	cout << "Задание 3" << endl;
	auto start0 = system_clock::now(); // отсортированный массив
	int mx0 = arr[0], mn0 = arr[0];
	for (int i = 1; i < N; i++)
	{
		if (arr[i] > mx0)
			mx0 = arr[i];
		if (arr[i] < mn0)
			mn0 = arr[i];
	}
	auto end0 = system_clock::now();
	auto result0 = duration_cast<nanoseconds>(end0 - start0);

	auto start1 = system_clock::now(); // неотсортированный массив
	int mx1 = arr3[0], mn1 = arr3[0];
	for (int i = 1; i < N; i++)
	{
		if (arr3[i] > mx1)
			mx1 = arr3[i];
		if (arr3[i] < mn1)
			mn1 = arr3[i];
	}
	auto end1 = system_clock::now();
	auto result1 = duration_cast<nanoseconds>(end1 - start1);

	auto start2 = system_clock::now(); // альтернативный способ для отсортированного массива
	int mx2 = arr[N - 1], mn2 = arr[0];
	auto end2 = system_clock::now();
	auto result2 = duration_cast<nanoseconds>(end2 - start2);

	cout << "Минимальный элемент массива: " << mn0 << endl << "Макс. элемент массива: " << mx0 << endl;
	cout << "Время отсортированного массива: " << result0.count() << " nanosec." << endl << "Время неотсортированного массива: " << result1.count() << " nanosec." << endl << "Альтернативное время сортировки массива: " << result2.count() << " nanosec." << endl << endl;

	// 4) Среднее значение, индексы элементов
	cout << "Задание 4" << endl;
	int average;
	if ((mn0 * (-1)) > mx0)
	{
		if ((mx0 % 2 == 1 && mn0 % 2 == 0) || (mx0 % 2 == 0 && mn0 % 2 == -1))
			average = (mx0 + mn0) / 2 - 1;
		else
			average = (mx0 + mn0) / 2;
	}
	else
	{
		if ((mx0 % 2 == 1 && mn0 % 2 == 0) || (mx0 % 2 == 0 && mn0 % 2 == -1))
			average = (mx0 + mn0) / 2 + 1;
		else
			average = (mx0 + mn0) / 2;
	}
	cout << "Среднее значение между " << mn0 << " и " << mx0 << " это " << average << endl;

	int number = 0;
	cout << "Несортированные индекс(ы) массива: ";
	for (int i = 0; i < N; i++) // неотсортированный массив
	{
		if (arr3[i] == average)
		{
			cout << i << " ";
			number += 1;
		}
	}
	if (number == 0)
		cout << "В текущем массиве нет чисел, равных среднему значению";
	cout << endl;
	cout << "Отсортированные индекс(ы) массива: ";
	number = 0;
	for (int i = 0; i < N; i++) // отсортированный массив
	{
		if (arr[i] == average)
		{
			cout << i << " ";
			number += 1;
		}
	}
	if (number == 0)
		cout << "В текущем массиве нет чисел, равных среднему значению";
	cout << endl;
	cout << "Количество индексов равно " << number << endl << endl;

	// 5) Вывод кол-ва элементов меньших a
	cout << "Задание 5" << endl;
	int a;
	cout << "Введите значение a: ";
	cin >> a;
	cout << "Количество элементов меньше a равно: ";
	if (a > arr[N - 1])
		cout << N << endl << endl;
	else if (a <= arr[0])
		cout << 0 << endl << endl;
	else
	{
		for (int i = 0; i < N; i++)
		{
			if (a <= arr[i])
			{
				cout << i << endl << endl;
				break;
			}
		}
	}

	// 6) Вывод кол-ва элементов больших b
	cout << "Задание 6" << endl;
	int b;
	cout << "Введите значение b: ";
	cin >> b;
	cout << "Количество элементов, большее b, равно ";
	if (b < arr[0])
		cout << N << endl << endl;
	else if (b >= arr[N - 1])
		cout << 0 << endl << endl;
	else
	{
		for (int i = 0; i < N; i++)
		{
			if (b < arr[i])
			{
				cout << (N - i) << endl << endl;
				break;
			}
		}
	}

	// 7) Нахождение числа в массиве
	cout << "Задание 7" << endl;
	int value;
	cout << "Введите значение: ";
	cin >> value;
	bool A = 0;
	auto start3 = system_clock::now();
	for (int i = 0; i < N; i++) // обычный перебор
	{
		if (arr[i] == value)
		{
			A = 1;
			break;
		}
	}
	auto end3 = system_clock::now();
	auto result3 = duration_cast<nanoseconds>(end3 - start3);

	if (A)
		cout << "Значение НАХОДИТСЯ в массиве" << endl;
	else
		cout << "Значение ОТСУТСТВУЕТ в массиве" << endl;
	A = 0;

	auto start4 = system_clock::now();
	int low = 0, high = N - 1, mid, const_value = value;
	while (low <= high) // бинарный поиск
	{
		mid = (low + high) / 2;
		if (value == arr[mid])
		{
			A = 1;
			break;
		}
		else if (value > arr[mid])
			low = mid + 1;
		else
			high = mid - 1;
	}
	auto end4 = system_clock::now();
	auto result4 = duration_cast<nanoseconds>(end4 - start4);

	if (A)
		cout << "Значение " << const_value << " находится по индексу " << mid << endl;
	A = 0;

	cout << "Линейное время поиска: " << result3.count() << " nanosec." << endl << "Время бинарного поиска: " << result4.count() << " nanosec." << endl << endl;

	// 8) Смена местами элементов массива
	cout << "Задание 8" << endl;
	cout << "Введите индексы: ";
	int m, n;
	cin >> m >> n;
	if ((m >= 0 && m < N) && (n >= 0 && n < N))
	{
		auto start5 = system_clock::now();
		swap(arr[m], arr[n]);
		auto end5 = system_clock::now();
		auto result5 = duration_cast<nanoseconds>(end5 - start5);
		cout << "Время замены составляет " << result5.count() << " nanosec." << endl;
		cout << "The array after swapping " << m << " и " << n << " элементы:" << endl;
		for (int i = 0; i < N; i++)
			cout << arr[i] << " ";
		cout << endl;
	}
	else
		cout << "Неправильные индексы" << endl;
}