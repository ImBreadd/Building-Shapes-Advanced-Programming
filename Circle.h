#include "Shape.h"
#include "Point.h"
#include "Movable.h"
#include<iostream>
using namespace std;
class Circle : public virtual Shape, public virtual Movable{
    public:
    int radius;
    Point topLeft;
    Point bottomRight;

    Circle(int x, int y, int radius){
        this->topLeft = Point(x, y);
        this->radius = radius;
        this->leftTop = this->topLeft;
        this->calculatePoints();
    }
    void move(int x, int y){
        // Move the circle to a new point x,y
        this->topLeft = Point(x, y);
        calculatePoints();
    }
    void scale(double x, double y){
        // Scales the circle
        if(x==y){
            this->radius = this->radius*x;
            calculatePoints();
        }
        else{
            cout<<"Scale is not possible for two different scaling factor at x and y axis as this will make the circle eclipse."<<endl;
        }
    }
    double calculateArea(){
        // Calculates the area
        this->area = 3.142 * this->radius * this->radius;
        return 3.142 * this->radius * this->radius;
    }
    double calculatePerimeter(){
        // Calculate the perimeter
        this->perimeter = 2 * 3.142 * this->radius;
        return 2 * 3.142 * double(this->radius);
    }
    void calculatePoints(){
        // Calculates the points
        this->bottomRight = Point(topLeft.x + 2*radius, topLeft.y + 2*radius);
    }
    void toString(){
        cout<<"Circle[r="<<radius<<"]"<<endl;
        cout<<"Points[("<<topLeft.x<<","<<topLeft.y<<"),("<<bottomRight.x<<","<<bottomRight.y<<")]"<<endl;
        cout<<"Area="<<this->calculateArea()<<"  Perimeter="<<this->calculatePerimeter()<< endl;
    }
};