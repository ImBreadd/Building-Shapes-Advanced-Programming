#include "Movable.h"
#include "Shape.h"
#include<iostream>

using namespace std;

#ifndef SQUARE_H
#define SQUARE_H

class Square : public virtual Shape, public virtual Movable{
    public:

    int edge_length;
    Point leftTop;
    Point rightTop;
    Point leftBottom;
    Point rightBottom;
    
    Square(int x, int y, int edge_length){
        this->leftTop = Point(x, y);
        this->edge_length = edge_length;
        this->calculatePoints();
        
        
    }
    
    void move(int x, int y){
        // move the square
        this->leftTop = Point(x, y);
        calculatePoints();
    }
    void scale(double x, double y){
        // scales the square
        if(x==y){
            this->edge_length = x*this->edge_length;
            calculatePoints();
        }
        else{
            cout << "Scalling of square will make it reactangle if the scaling factor is different" << endl;
        }
    }
    double calculateArea(){
        // calculates the area of the square
        return double(this->edge_length) * double(this->edge_length);
    }

    double calculatePerimeter(){
        // calculates the perimeter of the square
        return 4 * double(this->edge_length);
    }

    void calculatePoints(){
        // calculates the points of the square
        this->rightTop = Point(this->leftTop.getX() + edge_length, this->leftTop.getY());
        this->leftBottom = Point(this->leftTop.getX(), this->leftTop.getY() + edge_length);
        this->rightBottom = Point(this->leftTop.getX() + edge_length, this->leftTop.getY() + edge_length);
    }

    void toString(){
        // prints the details of the square
        cout << "Square[e=" << this->edge_length <<"]" << endl;
        cout << "Points[(" << this->leftTop.x << "," << this->leftTop.y << "),(" << this->rightTop.x << "," << this->rightTop.y << "),(" << this->rightBottom.x << "," << this->rightBottom.y << "),(" << this->leftBottom.x << "," << this->leftBottom.y << ")]" << endl;
        cout << "Area=" << this->calculateArea() << " Perimeter= " << this->calculatePerimeter()<<endl;
    }
};
#endif