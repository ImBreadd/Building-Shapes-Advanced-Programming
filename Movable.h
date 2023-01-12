#ifndef MOVABLE_H
#define MOVABLE_H

class Movable{
    public:
    virtual void move(int x, int y) =  0;
    virtual void scale(double x, double y) = 0;
    virtual ~Movable() {};
};

#endif