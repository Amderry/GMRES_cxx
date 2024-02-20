#include "Transpose.hpp"

namespace math
{
	void nonconst_transpose(Float_Matrix& mat)
	{
		for (int i = 0; i < mat.m; ++i)
		{
			for (int j = 0; j < mat.n; ++j)
			{
				float tmp = mat.m_data[j * mat.m + i];
				mat.m_data[j * mat.m + i] = mat.m_data[i * mat.m + j];
				mat.m_data[i * mat.m + j] = tmp;
			}
		}
		int tmp = mat.m;
		mat.m = mat.n;
		mat.n = tmp;
	}

	void nonconst_transpose(Double_Matrix& mat)
	{
		for (int i = 0; i < mat.m; ++i)
		{
			for (int j = 0; j < mat.n; ++j)
			{
				float tmp = mat.m_data[j * mat.m + i];
				mat.m_data[j * mat.m + i] = mat.m_data[i * mat.m + j];
				mat.m_data[i * mat.m + j] = tmp;
			}
		}
		int tmp = mat.m;
		mat.m = mat.n;
		mat.n = tmp;
	}
	std::unique_ptr<Float_Matrix> copy_transpose(const Float_Matrix& mat)
	{
		auto res = mat.copy();

		for (int i = 0; i < res->m; ++i)
		{
			for (int j = 0; j < res->n; ++j)
			{
				float tmp = res->m_data[j * res->m + i];
				res->m_data[j * res->m + i] = res->m_data[i * res->m + j];
				res->m_data[i * res->m + j] = tmp;
			}
		}
		int tmp = res->m;
		res->m = res->n;
		res->n = tmp;

		return res;
	}

	std::unique_ptr<Double_Matrix> copy_transpose(const Double_Matrix& mat)
	{
		auto res = mat.copy();

		for (int i = 0; i < res->m; ++i)
		{
			for (int j = 0; j < res->n; ++j)
			{
				float tmp = res->m_data[j * res->m + i];
				res->m_data[j * res->m + i] = res->m_data[i * res->m + j];
				res->m_data[i * res->m + j] = tmp;
			}
		}
		int tmp = res->m;
		res->m = res->n;
		res->n = tmp;

		return res;
	}
}