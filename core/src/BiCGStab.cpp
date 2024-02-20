#include "BiCGStab.hpp"
#include "Norm.hpp"
#include "MMultiplication.hpp"
#include "ScalarMultiplication.hpp"
#include "MSub.hpp"
#include "MSum.hpp"

std::unique_ptr<math::Float_Matrix> bicgstab(const math::Float_Matrix& A, const math::Float_Matrix& b)
{
	auto x0 = std::make_unique<math::Float_Matrix>(A.m, 1, std::make_unique<float[]>(A.m));

	auto r0 = math::subtract(b, *math::multiply(A, *x0));
	return r0;
}
