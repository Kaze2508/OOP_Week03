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
	~LOCATION();
	LOCATION(double = 0, double = 0);
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
	// friend std::istream& operator >>(std::istream& dInput, Location& loc0);
	// friend std::ostream& operator <<(std::ostream& dOutput, Location loc0);
};

class TRIANGLE
{
private:
	LOCATION A, B, C;
	static int count;
public:
	~TRIANGLE();
	TRIANGLE();
	TRIANGLE(const LOCATION&, const LOCATION&, const LOCATION&);
	void Input();
	void Output() const;
	bool Check() const;
};
#endif