#pragma once

#include <string>
using namespace std;

#define POLINOMIAL_BASIS_H

string revers_big_string(string str, int str_length)
{
	int temp, i, j;
	for (i = 0, j = str_length - 1; i < j; i++, j--)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
	return str;
}


int str_char_to_bin(char symbol_of_str)
{
	if (symbol_of_str == '0')
	{
		return 0;
	}
	if (symbol_of_str == '1')
	{
		return 1;
	}
}

int* convert_str_to_bin(string vector, int* arrey)
{
	int vector_length = vector.length();
	for (int i = 0; i < vector_length; i++)
	{
		arrey[i] = str_char_to_bin(vector[i]);
	}
	return arrey;
}

string bin_to_string(int symbol_of_string)
{
	if (symbol_of_string == 0)
	{
		return "0";
	}
	if (symbol_of_string == 1)
	{
		return "1";
	}
}

string revers_output(int* arrey, int size_arrey)
{
	string result = "";
	for (int i = size_arrey - 1; i > -1; i--)
	{
		result = result + (bin_to_string(arrey[i]) + " ");
	}
	return result;
}

int* copy_array(int* arrey1, int* arrey2, int size_of_arrey2)
{
	for (int i = 0; i < size_of_arrey2; i++)
	{
		arrey1[i] = arrey2[i];
	}
	return arrey1;
}



// Algorithms for our lab

int* element_null(int* arrey, int max)
{
	for (int i = 0; i < max; i++)
	{
		arrey[i] = 0;
	}
	return arrey;
}

int* element_one(int* arrey, int max)
{
	arrey[0] = 1;
	for (int i = 1; i < max; i++)
	{
		arrey[i] = 0;
	}
	return arrey;
}

int* add_vector(int* vector_1, int* vector_2, int* result, int size)
{
	for (int i = 0; i < size; i++)
	{
		result[i] = (vector_1[i] + vector_2[i]) % 2;
	}
	return result;
}

int* long_shift_digits_to_high(int* arrey, int max, int shiftBy)
{
	int* arrey1 = new int[shiftBy];
	int j = 0;
	for (int i = max - shiftBy; i < max; i++)
	{
		arrey1[j] = arrey[i];
		j++;
	}
	for (int i = 0; i < max - shiftBy; i++)
	{
		arrey[(max - 1) - i] = arrey[(max - shiftBy - 1) - i];
	}
	for (int i = 0; i < shiftBy; i++)
	{
		arrey[i] = arrey1[i];
	}
	delete[] arrey1;
	return arrey;
}

int deg(int* vector, int size)
{
	int temp = size - 1;
	while (vector[temp] == 0)
	{
		temp--;
	}
	return temp;
}

int* mod_generator(int* vector, int* generator, int* result, int size_first, int size_second)
{
	int* vector1 = new int[size_first];
	element_null(vector1, size_first);
	copy_array(vector1, vector, size_first);

	int* generator1 = new int[size_first];
	element_null(generator1, size_first);
	copy_array(generator1, generator, size_second);

	int* result1 = new int[size_first];
	element_null(result1, size_first);

	while (deg(vector1, size_first) >= deg(generator1, size_first))
	{
		int temp = deg(vector1, size_first) - deg(generator1, size_first);

		long_shift_digits_to_high(generator1, size_first, temp);
		add_vector(vector1, generator1, result1, size_first);
		element_null(generator1, size_first);  copy_array(generator1, generator, size_second);
		copy_array(vector1, result1, size_first);
		element_null(result1, size_first);
	}
	result = copy_array(result, vector1, size_second - 1);
	delete[] result1;
	delete[] generator1;
	delete[] vector1;
	return result;
}

int* multiplicative_vector(int* vector1, int* vector2, int* generator, int* result, int size)
{
	int* result1 = new int[2 * size + 1];
	element_null(result1, 2 * size + 1);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			result1[i + j] = (result1[i + j] + vector1[i] * vector2[j]) % 2;
		}
	}
	mod_generator(result1, generator, result, 2 * size + 1, size + 1);
	delete[] result1;
	return result;
}

int* elevation_to_square(int* vector, int* generator, int* result, int size)
{
	int* result_ = new int[2 * size + 1];
	element_null(result_, 2 * size + 1);
	for (int i = 0; i < size; i++)
	{
		result_[2 * i] = vector[i];
	}
	mod_generator(result_, generator, result, 2 * size + 1, size + 1);
	delete[] result_;
	return result;
}

int* elevation_to_huge_degree(int* vector, int* degree, int* generator, int* result, int size)
{
	int* _result = new int[size]; element_one(_result, size);

	for (int i = 0; i < size; i++)
	{

		if (degree[i] == 1)
		{
			multiplicative_vector(_result, vector, generator, result, size);
			copy_array(_result, result, size); element_null(result, size);
		}

		int* result_ = new int[size];
		elevation_to_square(vector, generator, result_, size);
		copy_array(vector, result_, size);
		delete[] result_;
	}

	copy_array(result, _result, size);
	delete[] _result;
	return result;
}


/*int trace_polynomial(int* vector, int size)
{
	int result = 0;
	for (int i = 0; i < size; i++)
	{
		result = (result + vector[i]) % 2;
	}
	return result;
}*/

/*int* trace_polynomial(int* vector, int* generator, int* result, int size)
{
	/int* result1 = new int[size]; 
	element_null(result1, size); 
	copy_array(result1, vector, size);
	for (int i = 0; i < size+1; i++)
	{
		int* result_ = new int[size]; element_null(result_, size);
		elevation_to_square(vector, generator, result_, size);
		add_vector(vector, result1, result1, size);
		copy_array(vector, result1, size);
		delete[] result_;
	}
	copy_array(result, result1, size);
	delete[] result1;

	return result;
}*/

int trace_polynomial(int* vector, int* generator, int size)
{
	int* result = new int[size]; 
	element_null(result, size);
	for (int i = 0; i < size; i++)
	{
		int* result_ = new int[size];
		element_null(result_, size);
		add_vector(vector, result, result, size);
		elevation_to_square(vector, generator, result_, size);
		copy_array(vector, result_, size);
		delete[] result_;
	}

	return result[0];
}

/*int* inverse_vector(int* vector, int* generator, int* result, int size)
{
	int* degree = new int[size]; element_null(degree, size);

	degree[0] = 0;

	for (int i = 1; i < size; i++)
	{
		degree[i] = 1;
	}

	elevation_to_huge_degree(vector, degree, generator, result, size);

	delete[] degree;

	return result;
}*/

int* inverse_vector(int* vector, int* generator, int* result, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (vector[i] == 1)
		{
			result[i] = 0;
		}
		else if (vector[i] == 0)
		{
			result[i] = 1;
		}
	}
	return result;
}

