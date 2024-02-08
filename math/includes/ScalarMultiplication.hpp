#pragma once
#include "Matrix.hpp"
#include <memory>
#include <concepts>

namespace math
{
	template<typename T>
		requires std::integral<T> || std::floating_point<T>
	std::unique_ptr<Float_Matrix> scalar_multiply(const Float_Matrix & mat, const T scalar)
	{
		auto res = std::make_unique<Float_Matrix>(mat.m, mat.n, std::make_unique<float[]>(mat.m * mat.n));
		for (int i = 0; i < mat.m; ++i)
		{
			for (int j = 0; j < mat.n; ++j)
			{
				res->m_data[i * mat.n + j] = mat.m_data[i * mat.n + j] * scalar;
			}
		}

		return res;
	}

	template<typename T>
		requires std::integral<T> || std::floating_point<T>
	std::unique_ptr<Double_Matrix> scalar_multiply(const Double_Matrix & mat, const T scalar)
	{
		auto res = std::make_unique<Double_Matrix>(mat.m, mat.n, std::make_unique<double[]>(mat.m * mat.n));
		for (int i = 0; i < mat.m; ++i)
		{
			for (int j = 0; j < mat.n; ++j)
			{
				res->m_data[i * mat.n + j] = mat.m_data[i * mat.n + j] * scalar;
			}
		}

		return res;
	}
}