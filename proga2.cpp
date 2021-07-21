﻿// proga2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "polynom.h"

int main()
{
	CPolynom t({ 1, 0 , 2, 3, -15, 56, 2, 1});
	std::cout << t[0] << std::endl;
	t[0] = 5;
	std::cout << t[0] << std::endl;
	CPolynom e = t;
	std::cout << e[0] << " " << (t + t)[0] << std::endl << (t == e) << " " << (t == (t + t)) << std::endl << (t == (t + t - t)) << std::endl;
	std::cout << t * (t + t) << std::endl << "Input:\n";
	std::cin >> e;
	std::cout << e;
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
