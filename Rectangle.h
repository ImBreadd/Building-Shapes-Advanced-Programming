#include "Shape.h"
#include "Point.h"
#include "Movable.h"
#include<iostream>
using namespace std;

#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle : public virtual Shape, public virtual Movable{
    public:

    int width;
    int height;
    Point leftTop;
    Point leftBottom;
    Point rightTop;
    Point rightBottom;

    Rectangle(int x, int y, int height, int width){
        this->width = width;
        this->height = height;
        this->leftTop = Point(x, y);
        this->calculatePoints();
        
    }
    void move(int x, int y){
        this->leftTop = Point(x, y);
        this->calculatePoints();
    }
    void scale(double x, double y){
        this->width = this->width*x;
        this->height = this->height*y;
        calculatePoints();
    }
    double calculateArea(){
        return double(this->width)*double(this->height);
    }
    double calculatePerimeter(){
        return 2*(double(this->width)+double(this->height));
    }
    void calculatePoints(){
        this->rightTop=Point(leftTop.x+width, leftTop.y);
        this->rightBottom = Point(leftTop.x+width, leftTop.y+height);
        this->leftBottom=Point(leftTop.x, leftTop.y+height);
    }
    void toString(){
        cout<<"Rectangle[h="<<height<<",w="<<width<<"]"<<endl;
        cout<<"Points[("<<leftTop.x<<","<<leftTop.y<<"),("<<rightTop.x<<","<<rightTop.y<<"),("<<rightBottom.x<<","<<rightBottom.y<<"),("<<leftBottom.x<<","<<leftBottom.y<<")]"<<endl;
        cout<<"Area="<<this->calculateArea()<<"  Perimeter="<<this->calculatePerimeter()<< endl;
    }

    
};

#endif