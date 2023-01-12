#include "Point.h"
#include "Movable.h"
#include<iostream>
using namespace std;
#ifndef SHAPE_H
#define SHAPE_H

class Shape{
    public:
    double area;
    bool isCircular;
    Point leftTop;
    double perimeter;

    // Methods
    virtual double calculateArea() = 0;
    virtual double calculatePerimeter() = 0;
    virtual void calculatePoints() = 0;
    // virtual void move(int x, int y) = 0;
    virtual void toString() = 0;
    virtual ~Shape() {};
};

#endif