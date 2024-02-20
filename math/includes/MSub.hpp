#pragma once
#include <memory>
#include "Matrix.hpp"

namespace math
{
	std::unique_ptr<Float_Matrix> subtract(const Float_Matrix& first, const Float_Matrix& second);
	std::unique_ptr<Double_Matrix> subtract(const Double_Matrix& first, const Double_Matrix& second);
}