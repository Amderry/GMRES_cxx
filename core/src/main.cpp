#include "BiCGStab.hpp"
#include "Transpose.hpp"
#include <iostream>

int main()
{
	auto a_data = std::make_unique<float[]>(4);
	
	for (int i = 0; i < 4; ++i)
	{
		a_data[i] = (float)(i + 1.29);
	}
	
	auto A = std::make_unique<math::Float_Matrix>(2, 2, std::move(a_data));

	auto b_data = std::make_unique<float[]>(2);

	for (int i = 0; i < 2; ++i)
	{
		b_data[i] = (float)i + 89;
	}

	auto b = std::make_unique<math::Float_Matrix>(2, 1, std::move(b_data));

	auto solve = bicgstab(*A, *b);
}