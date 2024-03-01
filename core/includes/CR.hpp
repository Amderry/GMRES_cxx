#include "Matrix.hpp"
#include "MMultiplication.hpp"
#include "ScalarMultiplication.hpp"
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
			m1.m_data[i] = i;
			std::cout << m1.m_data[i] << std::endl;
		}

		auto f2 = std::make_unique<float[]>(4);
		math::Float_Matrix m2{ 2, 2, std::move(f2) };

		for (int i = 0; i < m2.m * m2.n; ++i)
		{
			m2.m_data[i] = i;
			std::cout << m2.m_data[i] << std::endl;
		}


		auto res = math::multiply(m1, m2);

		for (int i = 0; i < res->m * res->n; ++i)
		{
			std::cout << res->m_data[i] << std::endl;
		}

		auto res2 = math::scalar_multiply(*res, 4.6);

		for (int i = 0; i < res2->m * res2->n; ++i)
		{
			std::cout << res2->m_data[i] << std::endl;
		}
	}
}