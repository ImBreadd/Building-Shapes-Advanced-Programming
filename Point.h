#ifndef POINT_H
#define POINT_H

class Point{
    public:
    int x; 
    int y;
    Point(){
        this->x = 0;
        this->y = 0;
    }
    Point(int x, int y){
        this->x = x;
        this->y = y;
    }
    int getX(){
        return this->x;
    }
    int getY(){
        return this->y;
    }
};
#endif