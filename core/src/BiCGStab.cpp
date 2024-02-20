#include "BiCGStab.hpp"
#include "Norm.hpp"
#include "MMultiplication.hpp"
#include "ScalarMultiplication.hpp"
#include "MSub.hpp"
#include "MSum.hpp"
#include "Transpose.hpp"

std::unique_ptr<math::Float_Matrix> bicgstab(const math::Float_Matrix& A, const math::Float_Matrix& b)
{
	auto x = std::make_unique<math::Float_Matrix>(A.m, 1, std::make_unique<float[]>(A.m));

	auto r = math::subtract(b, *math::multiply(A, *x));
	auto r0_st = r->copy();
	math::nonconst_transpose(*r0_st);
	auto p = r->copy();

	while (math::get_matrix_norm(*r) > 0.01)
	{
		float alpha = math::multiply(*r, *r0_st)->m_data[0] / math::multiply(*math::multiply(A, *p), *r0_st)->m_data[0];
		auto s = math::subtract(*r, *math::multiply(*math::scalar_multiply(A, alpha), *p));
		float w = math::multiply(*math::multiply(A, *s), *math::copy_transpose(*s))->m_data[0];
		int b = 0;
	}

	return x;
}
