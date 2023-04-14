#include "OOP_Week03.h"

int TRIANGLE::count = 0;

TRIANGLE::~TRIANGLE()
{
	std::cout << "Destroy 1 triangle => Remains " << --count << " triangles\n";
}

TRIANGLE::TRIANGLE()
{
	A.SetXY(0, 0);
	B.SetXY(0, 1);
	C.SetXY(1, 0);
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