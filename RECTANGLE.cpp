#include "OOP_Week03.h"

int RECTANGLE::count = 0;
bool flag00 = false;

RECTANGLE::RECTANGLE()
{
	while (!Check()) 
	{
		std::cin >> *this;
	}
	count++;
}

RECTANGLE::~RECTANGLE()
{
	if (flag00 == false)
		count--;
}

RECTANGLE::RECTANGLE(double xA, double yA, double xB, double yB) :A(xA, yA), B(xB, yB)
{
	while (!Check())
		std::cin >> *this;
	count++;
}

RECTANGLE::RECTANGLE(LOCATION AA, LOCATION BB)
{
	A = AA;
	B = BB;
	while (!Check())
		std::cin >> *this;
	count++;

}

LOCATION RECTANGLE::GetA() const
{
	return A;
}

LOCATION RECTANGLE::GetB() const
{
	return B;
}

int RECTANGLE::GetCount()
{
	return count;
}

void RECTANGLE::SetA(LOCATION AA)
{
	A = AA;
	while (!Check())
		std::cin >> A;
}

void RECTANGLE::SetB(LOCATION BB)
{
	B = BB;
	while (!Check())
		std::cin >> B;
}

void RECTANGLE::SetAB(LOCATION AA, LOCATION BB)
{
	A = AA;
	B = BB;
	while (!Check())
		std::cin >> *this;
}

void RECTANGLE::Move(double xyx, double xyy)
{
	A.Move(xyx, xyy);
	B.Move(xyx, xyy);
}

double RECTANGLE::Peri()
{
	LOCATION C(A.GetX(), B.GetY());
	LOCATION D(B.GetX(), A.GetY());
	double a = A.Distance(C);
	double b = A.Distance(D);
	return (a + b) * 2;
}

double RECTANGLE::Acre()
{
	LOCATION C(A.GetX(), B.GetY());
	LOCATION D(B.GetX(), A.GetY());
	double a = A.Distance(C);
	double b = A.Distance(D);
	return a * b;
}


void RECTANGLE::Input()
{

	do 
	{
		std::cout << "Input 2 locations :" << std::endl;
		std::cin >> A >> B;
	} 
	while (!Check());
}

void RECTANGLE::Output() const
{
	std::cout << "Rectangle has two choke points " << A << ";" << B << std::endl;
}


std::istream& operator>>(std::istream& is, RECTANGLE& cn)
{
	do 
	{
		std::cout << "Input 2 locations :" << std::endl;
		is >> cn.A >> cn.B;
	} 
	while (!cn.Check());
	return is;
}

std::ostream& operator<<(std::ostream& os, RECTANGLE cn)
{
	flag00 = true;
	os << "Rectangle has two choke points " << cn.A << ";" << cn.B << std::endl;
	return os;
}

bool RECTANGLE::Check() const
{
	double a1 = A.GetX();
	double a2 = A.GetY();
	double b1 = B.GetX();
	double b2 = B.GetY();
	if (a1 == b1 || a2 == b2)
		return false;
	else return true;
}