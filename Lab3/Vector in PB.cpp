#include <iostream>
#include "Polinomial basis.h"
#include <ctime>
#include <time.h>

int main()
{
	setlocale(LC_ALL, "ru_RU");
	string vec1;
	string vec2;
	string gener;
	string vector1;
	string vector2;
	string generator;
	int expansion;
	cout << "Введите вектор 1:" << endl;
	cin >> vec1;
	vector1=revers_big_string(vec1, vec1.length());
	cout << "Введите вектор 2:" << endl;
	cin >> vec2;
	vector2 = revers_big_string(vec2, vec2.length());
	cout << "Введите генератор:" << endl;
	cin >> gener;
	generator = revers_big_string(gener, gener.length());
	expansion = generator.length();
	cout << endl << "Степень расширения поля: " << expansion << endl;
	cout << "Конвертируем строки в масивы интов:" << endl;
	//Конвертируем вектор 1
	int* _vector_1 = new int[expansion - 1];
	element_null(_vector_1, expansion - 1);
	convert_str_to_bin(vector1, _vector_1);
	string vector11;
	for (int i = 0; i < expansion; i++)
	{
		vector11 = vector11 + bin_to_string(_vector_1[i]);
	}
	cout << "Вектор 1:" << endl;
	cout << revers_big_string(vector11, vector11.length()) << endl;
	//Конвертируем вектор 2
	int* _vector_2 = new int[expansion - 1];
	element_null(_vector_2, expansion - 1);
	convert_str_to_bin(vector2, _vector_2);
	//Конвертируем генератор
	int* _generator = new int[expansion];
	element_null(_generator, expansion);
	convert_str_to_bin(generator, _generator);
	cout << endl << "Первый вектор (reversed):" << endl;
	for (int i = 0; i < expansion; i++)
	{
		cout << _vector_1[i] << " ";
	}
	cout << endl;
	//cout << revers_output(_vector_1, expansion - 1);
	cout << endl << "Второй ветор (reversed):" << endl;
	for (int i = 0; i < expansion; i++)
	{
		cout << _vector_2[i] << " ";
	}
	cout << endl;
	//cout << revers_output(_vector_2, expansion - 1);
	cout << endl << "Генератор (reversed):" << endl;
	for (int i = 0; i < expansion; i++)
	{
		cout << _generator[i] << " ";
	}
	cout << endl;
	//cout << revers_output(_generator, expansion);

	cout << endl;
	cout << "Какую операцию Вы хотите выполнить:" << endl;
	cout << endl;
	cout << "[0]   Константный 0;" << endl;
	cout << "[1]   Константная 1;" << endl;
	cout << "[+]   Сумма;" << endl;
	cout << "[*]   Умножение;" << endl;
	cout << "[^]   Возведение в степень;" << endl;
	cout << "[s]   Возведение в квадрат;" << endl;
	cout << "[i]   Обратный элемент;" << endl;
	cout << "[t]   След;" << endl;
	cout << "Введите свой выбор:" << endl;
	char answer;
	cin >> answer;
	cout << "Ваш результат:" << endl;

	switch (answer)
	{
	case'0':
	{
		double d1;
		clock_t start1, finish1;
		srand(time(NULL));
		start1 = clock();
		int* result = new int[expansion - 1];
		cout << revers_output(element_null(result, expansion), expansion) << endl;
		finish1 = clock();
		d1 = (double)(finish1 - start1) / CLOCKS_PER_SEC;
		cout << "Время работы выведения нейтрального элемента по суммированию : " << d1 << endl;
		//delete[] result;
	}
	break;

	case'1':
	{
		double d1;
		clock_t start1, finish1;
		srand(time(NULL));
		start1 = clock();
		int* result = new int[expansion - 1];
		cout << revers_output(element_one(result, expansion), expansion) << endl;
		finish1 = clock();
		d1 = (double)(finish1 - start1) / CLOCKS_PER_SEC;
		cout << "Время работы выведения нейтрального элемента  по умножению -- 1: " << d1 << endl;
		//delete[] result;
	}
	break;

	case'+':
	{
		double d1;
		clock_t start1, finish1;
		srand(time(NULL));
		start1 = clock();
		int* result = new int[expansion - 1];
		element_null(result, expansion);
		cout << revers_output(add_vector(_vector_1, _vector_2, result, expansion), expansion) << endl;
		finish1 = clock();
		d1 = (double)(finish1 - start1) / CLOCKS_PER_SEC;
		cout << "Время работы операции + : " << d1 << endl;
		//delete[] result;
	}
	break;

	case'*':
	{
		double d1;
		clock_t start1, finish1;
		srand(time(NULL));
		start1 = clock();
		int* result = new int[expansion - 1];
		element_null(result, expansion);
		cout << revers_output(multiplicative_vector(_vector_1, _vector_2, _generator, result, expansion-1), expansion-1) << endl;
		finish1 = clock();
		d1 = (double)(finish1 - start1) / CLOCKS_PER_SEC;
		cout << "Время работы операции * : " << d1 << endl;
		//delete[] result;
	}
	break;

	case'^':
	{
		double d1;
		clock_t start1, finish1;
		srand(time(NULL));
		start1 = clock();
		string deg;
		cout << "Введите степень в бинарном виде:" << endl;
		cin >> deg;

		string degree =revers_big_string(deg, deg.length());
		int size_degree = degree.length();
		//Конвертируем степень в масив интов
		int* _degree = new int[size_degree];
		element_null(_degree, size_degree);  
		convert_str_to_bin(degree, _degree);


		cout << endl << "Возведение первого вектора в степень:" << endl;

		int* result = new int[expansion - 1];
		element_null(result, expansion);
		cout << revers_output(elevation_to_huge_degree(_vector_1, _degree, _generator, result, expansion), expansion) << endl;
		//delete[] result;


		cout << endl << "Возведение второго вектора в степень:" << endl;

		int* result_ = new int[expansion - 1];
		element_null(result_, expansion);
		cout << revers_output(elevation_to_huge_degree(_vector_2, _degree, _generator, result_, expansion), expansion) << endl;
		finish1 = clock();
		d1 = (double)(finish1 - start1) / CLOCKS_PER_SEC;
		cout << "Время работы операции возведения в большую степень для двух векторов : " << d1 << endl;
		//delete[] result_;
		//delete[] _degree;
	}
	break;

	case's':
	{
		double d1;
		clock_t start1, finish1;
		srand(time(NULL));
		start1 = clock();
		cout << endl << "Первый вектор в квадрате:" << endl;

		int* result = new int[expansion - 1]; 
		element_null(result, expansion);
		cout << revers_output(elevation_to_square(_vector_1, _generator, result, expansion), expansion) << endl;
		//delete[] result;

		cout << endl << "Второй вектор в квадрате:" << endl;

		int* result_ = new int[expansion - 1];
		element_null(result_, expansion);
		cout << revers_output(elevation_to_square(_vector_2, _generator, result_, expansion), expansion) << endl;
		finish1 = clock();
		d1 = (double)(finish1 - start1) / CLOCKS_PER_SEC;
		cout << "Время работы операции ^ для двух векторов : " << d1 << endl;
		//delete[] result_;
	}
	break;

	case't':
	{
		double d1;
		clock_t start1, finish1;
		srand(time(NULL));
		start1 = clock();
		int* result1 = new int[expansion - 1];
		int* result2 = new int[expansion - 1];
		cout << endl << "След первого вектора:" << trace_polynomial(_vector_1, _generator, expansion-1) << endl;
		cout << endl << "След второго вектора:" << trace_polynomial(_vector_2, _generator, expansion-1) << endl;
		finish1 = clock();
		d1 = (double)(finish1 - start1) / CLOCKS_PER_SEC;
		cout << "Время работы операции вычисления следа элемента : " << d1 << endl;
	}
	break;

	case'i':
	{
		double d1;
		clock_t start1, finish1;
		srand(time(NULL));
		start1 = clock();
		cout << endl << "Обратный к первому вектор:" << endl;
		int* result = new int[expansion - 1];
		element_null(result, expansion);
		cout << revers_output(inverse_vector(_vector_1, _generator, result, expansion), expansion) << endl;
		//delete[] result;

		cout << endl << "Обратный ко второму вектор:" << endl;
		int* result_ = new int[expansion - 1]; 
		element_null(result_, expansion);
		cout << revers_output(inverse_vector(_vector_2, _generator, result_, expansion), expansion) << endl;
		finish1 = clock();
		d1 = (double)(finish1 - start1) / CLOCKS_PER_SEC;
		cout << "Время работы операции поиска обратного элемента: " << d1 << endl;
		//delete[] result_;
	}
	break;

	default:
		cout << "Такого символа нет среди вышеуказаных!" << endl;
		break;

	}
	cout << "=======================================================================" << endl;
	cout << "Проверка (a+b)+c=a+(b+c)" << endl;
	string vec3;
	string vector3;
	cout << "Введите вектор 3:" << endl;
	cin >> vec3;
	vector3 = revers_big_string(vec3, vec3.length());
	int* _vector_3 = new int[expansion - 1];
	element_null(_vector_3, expansion - 1);
	convert_str_to_bin(vector3, _vector_3);
	int* resultAdd1 = new int[expansion - 1];
	element_null(resultAdd1, expansion);
	cout << "Результат (a+b):" << endl;
	cout << revers_output(add_vector(_vector_1, _vector_2, resultAdd1, expansion), expansion) << endl;
	int* resultAdd2 = new int[expansion - 1];
	element_null(resultAdd2, expansion);
	cout << "Результат (a+b)+c:" << endl;
	cout << revers_output(add_vector(resultAdd1, _vector_3, resultAdd2, expansion), expansion) << endl;
	cout << "Считаем a+(b+c):" << endl;
	int* resultAdd3 = new int[expansion - 1];
	element_null(resultAdd3, expansion);
	cout << "Результат (b+c):" << endl;
	cout << revers_output(add_vector(_vector_2, _vector_3, resultAdd3, expansion), expansion) << endl;
	int* resultAdd4 = new int[expansion - 1];
	element_null(resultAdd4, expansion);
	cout << "Результат a+(b+c):" << endl;
	cout << revers_output(add_vector(resultAdd3, _vector_1, resultAdd4, expansion), expansion) << endl;
	//delete[]resultAdd1;
	//delete[]resultAdd2;
	//delete[]resultAdd3;
	//delete[]resultAdd4;
	cout << "Проверка a+b+0=0+a+b=a+b";
	cout << "Считаем a+b+0:" << endl;
	int* resultAdd5 = new int[expansion - 1];
	element_null(resultAdd5, expansion);
	cout << "Результат a+b:" << endl;
	cout << revers_output(add_vector( _vector_1, _vector_2, resultAdd5, expansion), expansion) << endl;
	int* resultAdd6 = new int[expansion - 1];
	element_null(resultAdd6, expansion);
	int* null = new int[expansion - 1];
	element_null(null, expansion);
	cout << "Результат a+b+0:" << endl;
	cout << revers_output(add_vector(resultAdd5, null, resultAdd6, expansion), expansion) << endl;
	cout << "Считаем 0+a+b:" << endl;
	int* resultAdd7 = new int[expansion - 1];
	element_null(resultAdd7, expansion);
	cout << "Результат 0+a:" << endl;
	cout << revers_output(add_vector(null, _vector_1, resultAdd7, expansion), expansion) << endl;
	int* resultAdd8 = new int[expansion - 1];
	element_null(resultAdd8, expansion);
	cout << "Результат 0+a+b:" << endl;
	cout << revers_output(add_vector(resultAdd7, _vector_2, resultAdd8, expansion), expansion) << endl;
	int* resultAdd9 = new int[expansion - 1];
	element_null(resultAdd9, expansion);
	cout << "Результат a+b:" << endl;
	cout << revers_output(add_vector(_vector_1, _vector_2, resultAdd9, expansion), expansion) << endl;
	//delete[]resultAdd5;
	//delete[]resultAdd6;
	//delete[]resultAdd7;
	//delete[]resultAdd8;
	//delete[]resultAdd9;
	//delete[] _generator;
	//delete[] _vector_2;
	//delete[] _vector_1;
	return 0;
}

