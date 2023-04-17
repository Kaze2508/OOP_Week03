#include "OOP_Week03.h"

int TRIANGLE::count = 0;
const double epsilon = 0.0000001;
bool flag = false;

TRIANGLE::TRIANGLE()
{
	if (!Check())
		Input();
	count++;
}

TRIANGLE::~TRIANGLE()
{
	std::cout << "Destroy 1 triangle => Remains " << --count << " triangles\n";
}

TRIANGLE::TRIANGLE(double xA, double yA, double xB, double yB, double xC, double yC) :A(xA, yA), B(xB, yB), C(xC, yC)
{
	while (!Check())
		std::cin >> *this;
	count++;
}

TRIANGLE::TRIANGLE(const LOCATION& A, const LOCATION& B, const LOCATION& C) : A(A), B(B), C(C)
{
	if (!Check())
		Input();
	count++;
}

void TRIANGLE::Input()
{
	do
	{
		std::cout << "Input 3 locations:\n";
		A.Input();
		B.Input();
		C.Input();
	} while (!Check());
}

void TRIANGLE::Output() const
{
	std::cout << "A("; A.Output(); std::cout << ") ";
	std::cout << "B("; B.Output(); std::cout << ") ";
	std::cout << "C("; C.Output(); std::cout << ") ";
	/*std::cout << Categorize();
	std::cout << "\tPerimeter: " << Peri();
	std::cout << "\tAcremeter: " << Acre();*/
}

bool TRIANGLE::Check() const
{
	return A.CheckTriangle(B, C);
}

LOCATION TRIANGLE::GetA()
{
	return A;
}

LOCATION TRIANGLE::GetB()
{
	return B;
}

LOCATION TRIANGLE::GetC()
{
	return C;
}

void TRIANGLE::SetA(LOCATION xy)
{
	A = xy;
	while (!Check())
		std::cin >> A;
}

void TRIANGLE::SetB(LOCATION xy)
{
	B = xy;
	while (!Check())
		std::cin >> B;
}

void TRIANGLE::SetC(LOCATION xy)
{
	C = xy;
	while (!Check())
		std::cin >> C;
}

void TRIANGLE::SetABC(LOCATION AA, LOCATION BB, LOCATION CC)
{
	A = AA;
	B = BB;
	C = CC;
	while (!Check())
		std::cin >> *this;
}

int TRIANGLE::GetCount()
{
	return count;
}

void TRIANGLE::Move(double xx, double yy)
{
	A.Move(xx, yy);
	B.Move(xx, yy);
	C.Move(xx, yy);
}

double TRIANGLE::Peri()
{
	double a = A.Distance(B);
	double b = B.Distance(C);
	double c = C.Distance(A);
	return a + b + c;
}

double TRIANGLE::Acre()
{
	double a = A.Distance(B);
	double b = B.Distance(C);
	double c = C.Distance(A);
	double p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

void TRIANGLE::Categorize()
{
	if (Check()) 
	{
		double a = A.Distance(B);
		double b = B.Distance(C);
		double c = C.Distance(A);
		if (a == b && b == c)
			std::cout << "Even Triangle";
		else if (a == b || b == c || c == a)
		{
			if (abs(b * b + c * c - a * a) <= epsilon || abs(a * a + c * c - b * b) <= epsilon || abs(a * a + b * b - c * c) <= epsilon)
				std::cout << "Balance Square Triangle";
			else
				std::cout << "Balance Triangle";
		}
		else if (a * a == b * b + c * c || b * b == a * a + c * c || c * c == a * a + b * b)
			std::cout << "Square Triangle";
		else std::cout << "Regular Triangle";
	}
	else std::cout << "Invalid Triangle";
}

std::istream& operator>>(std::istream& is, TRIANGLE& Tri)
{
	do 
	{
		std::cout << "Input 3 locations of triangle :\n";
		is >> Tri.A >> Tri.B >> Tri.C;
	} 
	while (!Tri.Check());
	return is;
}

std::ostream& operator<<(std::ostream& os, TRIANGLE Tri)
{
	flag = true;
	os << "Triangle: " << Tri.A << ";" << Tri.B << ";" << Tri.C << std::endl;
	return os;
}