#include <iostream>
#include <Eigen/Dense>

void CR_float(const Eigen::MatrixXf&, const Eigen::MatrixXf&, Eigen::MatrixXf&, float eps = 1e-4, int it = 1000);
void CR_double(const Eigen::MatrixXd& A, const Eigen::MatrixXd& b, Eigen::MatrixXd& x, float eps = 1e-4, int it = 1000);

int main()
{
	Eigen::MatrixXd A(2, 2);
	A(0, 0) = 3;
	A(1, 0) = 2.5;
	A(0, 1) = 2.5;
	A(1, 1) = 3;


	Eigen::MatrixXd b(2, 1);
	b(0, 0) = 2;
	b(1, 0) = 3;
	
	Eigen::MatrixXd x(2, 1);

	CR_double (A, b, x);
	std::cout << x.transpose();
}