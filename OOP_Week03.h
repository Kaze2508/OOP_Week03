#pragma once
#ifndef _OOP_Week03

#include <iostream>
#include <string>
#include <string.h>

class LOCATION
{
private:
	double x, y;
	static int count;
public:
	LOCATION();
	~LOCATION();
	LOCATION(double);
	LOCATION(double, double);
	LOCATION(const LOCATION&);
	void SetX(double);
	void SetY(double);
	void SetXY(double, double);
	double GetX() const;
	double GetY() const;
	static int GetCount();
	void Input();
	void Output() const;
	void Move(double, double);
	bool Check(const LOCATION&) const;
	double Distance(const LOCATION&) const;
	LOCATION Symmetric() const;
	bool CheckTriangle(const LOCATION&, const LOCATION&) const;
	bool CheckTriangle(double, double, double) const;
	double Peri(const LOCATION&, const LOCATION&) const;
	double Acre(const LOCATION&, const LOCATION&) const;
	std::string Categorize(const LOCATION&, const LOCATION&) const;
	friend std::istream& operator>>(std::istream&, LOCATION&);
	friend std::ostream& operator<<(std::ostream&, LOCATION&);
};

class TRIANGLE
{
private:
	LOCATION A, B, C;
	static int count;
public:
	TRIANGLE();
	~TRIANGLE();
	TRIANGLE(double, double, double, double, double, double);
	TRIANGLE(const LOCATION&, const LOCATION&, const LOCATION&);
	void Input();
	void Output() const;
	bool Check() const;
	LOCATION GetA();
	LOCATION GetB();
	LOCATION GetC();
	void SetA(LOCATION);
	void SetB(LOCATION);
	void SetC(LOCATION);
	void SetABC(LOCATION, LOCATION, LOCATION);
	static int GetCount();
	void Move(double, double);
	double Peri();
	double Acre();
	void Categorize();
	friend std::istream& operator>>(std::istream&, TRIANGLE&);
	friend std::ostream& operator<<(std::ostream&, TRIANGLE);
};
#endif