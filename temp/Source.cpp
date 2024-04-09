/*
Program name: AbstractClassShape.cpp
Programmer: Tyler Davies
Date: 10-3-21
Version: 1.0
Description: This program contains and tests the following class hierarchy: abstract base class
             Shape; Point class (derived from Shape); Circle class (derived from Point); Cylinder
             class (derived from Circle). The main function instantiates an object from each derived
             class. To test the objects, the main function: prints the results; updates the x cordinate,
             y cordinate, radius, and height respectively for each object; then prints the results again.
*/

#include<iostream>
#include<iomanip>
#include<cmath>

using namespace std;

//Abstract base class Shape has two pure virtual functions (printShapeName and print), and two 
//virtual functions (area and volume) which have default implementation that returns a value of zero.
class Shape
{
public:
    Shape(){}
    virtual void printShapeName() = 0;
    virtual void print() = 0;
    virtual double area()
        { return 0.0; }
    virtual double volume()
        { return 0.0; }
    virtual ~Shape(){}
};

//Point class (derived from Shape with public inheritance) inherits the implementations for area 
//and volume (both remain zero). Point adds x and y coordinate private members.
class Point : public Shape
{
private:
    double x, y;
public:
    Point() : Shape()
    {
        x = 0.0;
        y = 0.0;
    }
    virtual void printShapeName()
        { cout << left << "Point" << endl; }
    virtual void print();
    void setXCordinate(double number)
        { x = number; }
    void setYCordinate(double number)
        { y = number; }
    double getXCordinate()
        { return x; }
    double getYCordinate()
        { return y; }
    virtual ~Point(){}
};

//Print function for Point class.
void Point::print()
{
    this->printShapeName();
    cout << left << fixed << setprecision(1) << setw(15) << "X Cordinate: " << x << endl;
    cout << setw(15) << "Y Cordinate: " << y << endl << endl;
}

/*
Circle class (derived from Point with public inheritance) has a volume of 0.0 (volume function not
overridden), and a nonzero area (area function overridden). Circle adds member functions for 
updating and returning its radius protected member.
*/
class Circle : public Point
{
protected:    //Potected access specifier treats member as private, but gives access to derived classes.
    double radius;
public:
    Circle() : Point()
        { radius = 1.0; }    //Circle will have a nonzero area, unless user sets radius to zero.
    virtual void printShapeName()
        { cout << left << "Circle" << endl; }
    virtual void print();
    virtual double area()    //Area of a circle equals pi times radius squared.
        { return 3.14 * pow(radius, 2); }
    void setRadius(double number)
        { radius = number; }
    double getRadius()
        { return radius; }
    virtual ~Circle(){}
};

//Print function for Circle class.
void Circle::print()
{
    this->printShapeName();
    cout << left << fixed << setprecision(1) << setw(15) << "Radius: " << radius << endl;
    cout << setw(15) << "Area: " << this->area() << " (squared units)" << endl << endl;
}

//Cylinder class (derived from Circle with public inheritance) has overridden area and volume
//functions. Cylinder adds member functions for updating and returning its height private member.
class Cylinder : public Circle
{
private:
    double height;
public:
    Cylinder() : Circle()
        { height = 1.0; }    //Cylinder will have a nonzero area and volume, unless user sets height or radius to zero.
    virtual void printShapeName()
        { cout << left << "Cylinder" << endl; }
    virtual void print();
    virtual double area()    //Area of a cylinder equals two times pi times radius times height, plus 2 times pi times radius squared.
        { return (2 * 3.14 * radius * height) + (2 * 3.14 * pow(radius, 2)); }
    virtual double volume()    //Volume of a cylinder equals pi times radius squared times height. 
        { return 3.14 * pow(radius, 2) * height; }
    void setHeight(double number)
        { height = number; }
    double getHeight()
        { return height; }
    virtual ~Cylinder(){}
};

//Print function for Cylinder class.
void Cylinder::print()
{
    this->printShapeName();
    cout << left << fixed << setprecision(1) << setw(15) << "Radius: " << radius << endl;
    cout << setw(15) << "Height: " << height << endl;
    cout << setw(15) << "Area: " << this->area() << " (squared units)" << endl;
    cout << setw(15) << "Volume: " << this->volume() << " (cubed units)" << endl << endl;
}

/*
The main function instantiates an object from each derived class. It then tests the objects by:
printing the results; updating the x cordinate, y cordinate, radius, and height respectively for
each object; then printing the results again.
*/
int main()
{
    Point point;
    Circle circle;
    Cylinder cylinder;

    point.print();
    circle.print();
    cylinder.print();

    point.setXCordinate(10.0);
    point.setYCordinate(10.0);
    circle.setRadius(10.0);
    cylinder.setRadius(10.0);
    cylinder.setHeight(10.0);

    cout << left << endl << "Updated Objects:" << endl << endl;
    point.print();
    circle.print();
    cylinder.print();

    exit(0);
}