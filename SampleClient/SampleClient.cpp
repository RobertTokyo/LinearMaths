// SampleClient.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "Matrix.h"
#include "Matrix.inl"

using namespace LinearAlgebra;

int main()
{
    std::cout << "Hello World!\n";

	std::vector<std::vector<int>> v1{ std::vector<int>{1, 2}, std::vector<int>{3, 2} };
	const Matrix<int> m1{ v1 };
	std::vector<std::vector<int>> v2{ std::vector<int>{2, 2}, std::vector<int>{2, 2} };
	Matrix<int> m2{ v2 };

	Matrix<int> m3 = m1 + m2;


}
