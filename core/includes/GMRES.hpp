#include "Matrix.hpp"
#include <memory>
#include <iostream>

namespace gmres
{
	void print()
	{
		auto f1 = std::make_unique<float[]>(4);
		math::Float_Matrix m1{ 2, 2, std::move(f1) };

		for (int i = 0; i < m1.m * m1.n; ++i)
		{
			std::cout << m1.m_data[i] << std::endl;
		}

		math::Float_Matrix m2{ std::move(m1) };

		for (int i = 0; i < m1.m * m1.n; ++i)
		{
			std::cout << m1.m_data[i] << std::endl;
		}

		for (int i = 0; i < m2.m * m2.n; ++i)
		{
			std::cout << m2.m_data[i] << std::endl;
		}
	}
}