#include "Norm.hpp"

float math::get_matrix_norm(const Float_Matrix& mat)
{
	float max_norm = .0f;
	for (int i = 0; i < mat.m; ++i)
	{
		float row_sum = .0f;
		for (int j = 0; j < mat.n; ++j)
		{
			row_sum = abs(mat.m_data[i * mat.n + j]);
		}
		if (row_sum > max_norm)
		{
			max_norm = row_sum;
		}
	}
	return max_norm;
}

float math::get_matrix_norm(const Double_Matrix& mat)
{
	float max_norm = .0f;
	for (int i = 0; i < mat.m; ++i)
	{
		float row_sum = .0f;
		for (int j = 0; j < mat.n; ++j)
		{
			row_sum = abs(mat.m_data[i * mat.n + j]);
		}
		if (row_sum > max_norm)
		{
			max_norm = row_sum;
		}
	}
	return max_norm;
}