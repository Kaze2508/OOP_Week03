#include "OOP_Week03.h"

int CIRCLE::count = 0;
bool flag01 = false;
const double pi = 3.14;

CIRCLE::CIRCLE()
{
	while (!Check())
		std::cin >> *this;
	count++;
}

CIRCLE::~CIRCLE()
{
	if (flag01 == false)
		count--;
}

CIRCLE::CIRCLE(double xO, double yO, double rr) :O(xO, yO), R(rr)
{
	while (!Check())
		std::cin >> *this;
	count++;
}

CIRCLE::CIRCLE(LOCATION oo, double r)
{
	O = oo;
	R = r;
	while (!Check())
		std::cin >> *this;
	count++;
}

LOCATION CIRCLE::GetO() const
{
	return O;
}

double CIRCLE::GetR() const
{
	return R;
}

int CIRCLE::GetCount()
{
	return count;
}

void CIRCLE::SetO(LOCATION oo)
{
	O = oo;
	while (!Check())
		std::cin >> O;
}

void CIRCLE::SetR(double r)
{
	R = r;
	while (!Check())
		std::cin >> R;
}

void CIRCLE::SetOR(LOCATION o, double r)
{
	O = o;
	R = r;
	while (!Check())
		std::cin >> *this;

}

void CIRCLE::Move(double xyx, double xyy)
{
	O.Move(xyx, xyy);
}

double CIRCLE::Peri()
{
	return 2 * pi * R;
}

double CIRCLE::Acre()
{
	return pi * R * R;
}

void CIRCLE::Input()
{
	do
	{
		std::cout << "Input centor O location :\n";
		std::cin >> O;
		std::cout << "\nInput radius R :";
		std::cin >> R;
	} 
	while (!Check());
}

void CIRCLE::Output() const
{
	std::cout << "Circle has center O " << O << "  radius R = " << R;
}

bool CIRCLE::Check() const
{
	if (R <= 0) return false;
	else return true;
}

std::istream& operator>>(std::istream& is, CIRCLE& tr)
{
	do
	{
		std::cout << "Input centor O location :\n";
		is >> tr.O;
		std::cout << "\nInput radius R :";
		is >> tr.R;
	} 
	while (!tr.Check());
	return is;
}

std::ostream& operator<<(std::ostream& os, CIRCLE tr)
{
	flag01 = true;
	os << "Circle has center O " << tr.O << "  radius R = " << tr.R << std::endl;
	return os;
}