#include <iostream>
#include <Eigen/Dense>

void CR_float(const Eigen::MatrixXf&, const Eigen::MatrixXf&, Eigen::MatrixXf&, float, int);
void CR_double(const Eigen::MatrixXd& A, const Eigen::MatrixXd& b, Eigen::MatrixXd& x, float, int);

int main()
{
	Eigen::MatrixXf A(2, 2);
	A(0, 0) = 3;
	A(1, 0) = 2.5;
	A(0, 1) = 2.5;
	A(1, 1) = 3;


	Eigen::MatrixXf b(2, 1);
	b(0, 0) = 2;
	b(1, 0) = 3;
	
	Eigen::MatrixXf x(2, 1);

	CR_float (A, b, x, 1e-4, 1000);
	std::cout << x;
}

void CR_float(const Eigen::MatrixXf& A, const Eigen::MatrixXf& b, Eigen::MatrixXf& x, float eps, int it)
{
	x = Eigen::MatrixXf::Zero(1, b.rows());
	x = Eigen::MatrixXf::Zero(b.rows(), 1);
	x = Eigen::MatrixXf::Zero(b.rows(), 1);
	Eigen::MatrixXf r = b - A * x;
	Eigen::MatrixXf p = r;
	Eigen::MatrixXf Ap = A * p;
	for (int k = 0; k < it && r.squaredNorm() > eps; ++k)
	{
		float a = static_cast<float>((r.transpose() * Ap).value()) / static_cast<float>((Ap.transpose() * Ap).value());
		x += a * p;
		Eigen::MatrixXf rnew = r - ((a * A) * p);
		float bt = static_cast<float>((Ap.transpose() * (A * rnew)).value()) / static_cast<float>((Ap.transpose() * Ap).value());
		p = rnew - bt * p;
		r = rnew;
		Ap = A * r - bt * Ap;
	}
}

void CR_double(const Eigen::MatrixXd& A, const Eigen::MatrixXd& b, Eigen::MatrixXd& x, float eps, int it)
{
	x = Eigen::MatrixXd::Zero(b.rows(), 1);
	x = Eigen::MatrixXd::Zero(b.rows(), 1);
	Eigen::MatrixXd r = b - A * x;
	Eigen::MatrixXd p = r;
	Eigen::MatrixXd Ap = A * p;
	for (int k = 0; k < it && r.squaredNorm() > eps; ++k)
	{
		float a = static_cast<float>((r.transpose() * Ap).value()) / static_cast<float>((Ap.transpose() * Ap).value());
		x += a * p;
		Eigen::MatrixXd rnew = r - ((a * A) * p);
		float bt = static_cast<float>((Ap.transpose() * (A * rnew)).value()) / static_cast<float>((Ap.transpose() * Ap).value());
		p = rnew - bt * p;
		r = rnew;
		Ap = A * r - bt * Ap;
	}
}