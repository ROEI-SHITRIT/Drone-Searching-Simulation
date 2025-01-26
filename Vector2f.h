#ifndef HW02CPP_VECTOR2F_H
#define HW02CPP_VECTOR2F_H
#include <iostream>
#include <cmath>
class Vector2f {
private:
    //fields
    double x;
    double y;

public:
    //builders
    explicit Vector2f();
    explicit Vector2f(double x,double y);
    Vector2f(const Vector2f &vector2F);
    ~Vector2f()=default;
    //get+set
    double getX()const;
    double getY()const;
    void setX(double num);
    void setY(double num);
    //operators
    Vector2f& operator = (const Vector2f &vector);
    Vector2f operator +(const Vector2f &vector)const;
    void operator +=(const Vector2f &voctor);
    Vector2f operator - (const Vector2f &vector)const;
    Vector2f operator *(const double &num)const;
    void operator *=(const double  &num);
    friend std::ostream &operator << (std::ostream &out,const Vector2f &vec);
    //distance met
    double distance(const Vector2f &vector)const;//distance between 2 points.
};


#endif //HW02CPP_VECTOR2F_H
