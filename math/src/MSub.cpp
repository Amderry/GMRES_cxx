#include "MSub.hpp"

namespace math
{
    std::unique_ptr<Float_Matrix> subtract(const Float_Matrix& first, const Float_Matrix& second)
    {
        if (first.m != second.m)
        {
            return nullptr;
        }
        auto res = std::make_unique<Float_Matrix>(first.m, second.n, std::make_unique<float[]>(first.m * second.n));

        for (int i = 0; i < first.m; ++i)
        {
            for (int j = 0; j < second.n; ++j)
            {
                res->m_data[i * res->n + j] = first.m_data[i * res->n + j] - second.m_data[i * res->n + j];
            }
        }

        return res;
    }

    std::unique_ptr<Double_Matrix> subtract(const Double_Matrix& first, const Double_Matrix& second)
    {
        if (first.m != second.m)
        {
            return nullptr;
        }
        auto res = std::make_unique<Double_Matrix>(first.m, second.n, std::make_unique<double[]>(first.m * second.n));

        for (int i = 0; i < first.m; ++i)
        {
            for (int j = 0; j < second.n; ++j)
            {
                res->m_data[i * res->n + j] = first.m_data[i * res->n + j] - second.m_data[i * res->n + j];
            }
        }

        return res;
    }
}