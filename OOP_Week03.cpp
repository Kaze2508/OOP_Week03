#include <iostream>
#include "OOP_Week03.h"

int select = 0;

int main(int argc, char* argv[])
{
    {
        std::cout << "What you want to solve?" << std::endl;
        std::cout << "1. Location (Diem)" << std::endl;
        std::cout << "2. Triangle (Tam Giac)" << std::endl;
        std::cout << "3. Rectangle (Hinh Chu Nhat)" << std::endl;
        std::cout << "4. Circle (Hinh Tron)" << std::endl;
        std::cout << "You choose : ";
        std::cin >> select;
        std::cout << std::endl;
    }
    switch (select)
    {
    case 1:
    {
        LOCATION loc1;
        std::cin >> loc1;
        std::cout << std::endl;
        std::cout << loc1;
        std::cout << std::endl;
        break;
    }
    case 2:
    {
        TRIANGLE Tri1, Tri2(-1, 0, 2, 0, 0, 4), Tri3(LOCATION(0, 0), LOCATION(3, 0), LOCATION(0, 4));
        std::cout << Tri1 << Tri2 << Tri3;
        std::cout << "Triangle 1 "; Tri1.Categorize(); std::cout << "\nPerimeter: " << Tri1.Peri() << "\nAcre: " << Tri1.Acre() << std::endl;
        std::cout << std::endl;
        std::cout << "Triangle 2 "; Tri2.Categorize(); std::cout << "\nPerimeter: " << Tri2.Peri() << "\nAcre: " << Tri2.Acre() << std::endl;
        std::cout << std::endl;
        std::cout << "Triangle 3 "; Tri3.Categorize(); std::cout << "\nPerimeter: " << Tri3.Peri() << "\nAcre: " << Tri3.Acre() << std::endl;
        std::cout << std::endl;
        std::cout << "Number of Triangles : " << Tri1.GetCount() << std::endl;
    }
    case 3:
    {
        RECTANGLE Rec1, Rec2(1, 2, 5, 6), Rec3(LOCATION(1, 1), LOCATION(3, 3));
        std::cout << Rec1 << Rec2 << Rec3;
        std::cout << "Rectangle 1 : \nPerimeter :" << Rec1.Peri() << "\nAcre :" << Rec1.Acre() << std::endl;
        std::cout << std::endl;
        std::cout << "Rectangle 2 : \nPerimeter :" << Rec2.Peri() << "\nAcre :" << Rec2.Acre() << std::endl;
        std::cout << std::endl;
        std::cout << "Rectangle 3 : \nPerimeter :" << Rec3.Peri() << "\nAcre :" << Rec3.Acre() << std::endl;
        std::cout << std::endl;
        std::cout << "Number of Rectangles:" << Rec1.GetCount();
    }
    case 4:
    {
        CIRCLE Cir1, Cir2(1, 2, 5), Cir3(LOCATION(2, 3), 4);
        std::cout << Cir1 << Cir2 << Cir3;
        std::cout << "Circle 1 perimeter : " << Cir1.Peri() << "\tAcre: " << Cir1.Acre() << std::endl;
        std::cout << "Circle 2 perimeter : " << Cir2.Peri() << "\tAcre: " << Cir2.Acre() << std::endl;
        std::cout << "Circle 3 perimeter : " << Cir3.Peri() << "\tAcre: " << Cir3.Acre() << std::endl;
        std::cout << "Number of circles : " << Cir1.GetCount();
    }
    }
    return 0;
}