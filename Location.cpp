#include "OOP_Week03.h"
#define epsilon 0.0000000001

int LOCATION::count = 0;

LOCATION::~LOCATION()
{
	std::cout<<"Destroy 1 location => Remains "<< --count <<" locations\n";
}

LOCATION::LOCATION(double x, double y): x(x), y(y)
{
	count++;
}

LOCATION::LOCATION(const LOCATION& xy): x(xy.x), y(xy.y)
{
	count++;
}

void LOCATION::SetX(double)
{
	this->x = x;
}

void LOCATION::SetY(double)
{
	this->y = y;
}
void LOCATION::SetXY(double x, double y)
{
	this->x = x;
	this->y = y;
}

double LOCATION::GetX() const
{
	return x;
}

double LOCATION::GetY() const
{
	return y;
}

int LOCATION::GetCount()
{
	return count;
}

void LOCATION::Input()
{
	std::cout << "Input x: ";
	std::cin >> x;
	std::cout << "\n";
	std::cout << "Input y: ";
	std::cin >> y;
}

void LOCATION::Output() const
{
	std::cout << x << ", " << y;
}

void LOCATION::Move(double dx, double dy)
{
	x += dx;
	y += dy;
}

bool LOCATION::Check(const LOCATION& d) const
{
	return this->x == d.x && this->y == d.y;
}

double LOCATION::Distance(const LOCATION& d) const
{
	return sqrt(pow(x - d.x, 2) + pow(y - d.y, 2));
}

LOCATION LOCATION::Symmetric() const
{
	return LOCATION(-x == 0 ? x : -x, -y == 0 ? y : -y);
}

bool LOCATION::CheckTriangle(const LOCATION& d1, const LOCATION& d2) const
{
	double a = this->Distance(d1);
	double b = d1.Distance(d2);
	double c = d2.Distance(*this);
	return a > 0 && b > 0 && c > 0 && a + b > c && b + c > a && c + a > b;
}

bool LOCATION::CheckTriangle(double a, double b, double c) const
{
	return a > 0 && b > 0 && c > 0 && a + b > c && b + c > a && c + a > b;
}

double LOCATION::Peri(const LOCATION& d1, const LOCATION& d2) const
{
	double a = Distance(d1);
	double b = d1.Distance(d2);
	double c = d2.Distance(*this);
	return a + b + c;
}

double LOCATION::Acre(const LOCATION& d1, const LOCATION& d2) const
{
	double a = Distance(d1);
	double b = d1.Distance(d2);
	double c = d2.Distance(*this);
	double p = (a + b + c) / 2;
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

std::string LOCATION::Categorize(const LOCATION& d1, const LOCATION& d2) const
{
	double a = Distance(d1);
	double b = d1.Distance(d2);
	double c = d2.Distance(*this);
	std::string result = "";
	if (!CheckTriangle(d1, d2)) result = "Not a triangle";
	else if (a == b && b == c) result = "Even Triangle";
	else if (a == b || b == c || a == c)
		if (abs(a * a + b * b - c * c) <= epsilon || abs(a * a + c * c - b * b) <= epsilon || abs(b * b + c * c - a * a) <= epsilon)
			result = "Balance Square Triangle";
		else result = "Balance Triangle";
	else if (abs(a * a + b * b - c * c) <= epsilon || abs(a * a + c * c - b * b) <= epsilon || abs(b * b + c * c - a * a) <= epsilon)
		result = "Square Triangle";
	else
		result = "Regular Triangle";
	return result;
}