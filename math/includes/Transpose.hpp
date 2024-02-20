#include "Matrix.hpp"
#include <memory>

namespace math
{
	void nonconst_transpose(Float_Matrix& mat);
	void nonconst_transpose(Double_Matrix& mat);
	std::unique_ptr<Float_Matrix> copy_transpose(const Float_Matrix& mat);
	std::unique_ptr<Double_Matrix> copy_transpose(const Double_Matrix& mat);
}