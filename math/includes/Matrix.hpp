#pragma once
#include <memory>

namespace math
{
	enum class Matrix_Type
	{
		M_FLOAT,
		M_DOUBLE
	};

	struct Matrix
	{
		Matrix() = delete;
		Matrix(unsigned int m, unsigned int n);

		unsigned int m;
		unsigned int n;
	};

	struct Float_Matrix : Matrix
	{
		Float_Matrix(unsigned int m, unsigned int n, std::unique_ptr<float[]> data);

		Float_Matrix(const Float_Matrix&) = delete;
		Float_Matrix& operator=(const Float_Matrix&) = delete;

		Float_Matrix(Float_Matrix&&) noexcept;
		Float_Matrix& operator=(Float_Matrix&&) noexcept;

		std::unique_ptr<float[]> m_data;
		Matrix_Type m_type = Matrix_Type::M_FLOAT;
	};

	struct Double_Matrix : Matrix
	{
		Double_Matrix(unsigned int m, unsigned int n, std::unique_ptr<double[]> data);

		Double_Matrix(const Double_Matrix&) = delete;
		Double_Matrix& operator=(const Double_Matrix&) = delete;

		Double_Matrix(Double_Matrix&&) noexcept;
		Double_Matrix& operator=(Double_Matrix&&) noexcept;

		std::unique_ptr<double[]> m_data;
		Matrix_Type m_type = Matrix_Type::M_DOUBLE;
	};
}