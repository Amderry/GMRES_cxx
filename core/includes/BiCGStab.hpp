#pragma once
#include "Matrix.hpp"
#include <memory>

std::unique_ptr<math::Float_Matrix> bicgstab(const math::Float_Matrix& A, const math::Float_Matrix& b);
std::unique_ptr<math::Double_Matrix> bicgstab(const math::Double_Matrix& A,const math::Double_Matrix& b);