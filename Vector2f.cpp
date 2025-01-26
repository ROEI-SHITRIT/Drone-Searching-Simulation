#include "Vector2f.h"


Vector2f::Vector2f():x(0),y(0) {
}

Vector2f::Vector2f(double x, double y):x(x),y(y){
}

Vector2f::Vector2f(const Vector2f &vector2F): Vector2f(vector2F.getX(),vector2F.getY()) {
}



double Vector2f::getX()const {
    return this->x;
}

double Vector2f::getY()const {
    return this->y;
}

void Vector2f::setX(double num) {
    this->x=num;
}

void Vector2f::setY(double num) {
    this->y=num;
}

Vector2f& Vector2f::operator=(const Vector2f &vector) {
    setX(vector.getX());
    setY(vector.getY());
    return *this;
}

Vector2f Vector2f::operator+(const Vector2f &vector)const {
    Vector2f vec;
    vec.setX((getX()+vector.getX()));
    vec.setY(getY()+vector.getY());
    return vec;
}

void Vector2f::operator+=(const Vector2f &voctor) {
    setX(getX()+voctor.getX());
    setY(getY()+voctor.getY());
}

Vector2f Vector2f::operator-(const Vector2f &vector)const {
    Vector2f vec;
    vec.setX((getX()-vector.getX()));
    vec.setY(getY()-vector.getY());
    return vec;
}

Vector2f Vector2f::operator*(const double &num)const {
    Vector2f vec;
    vec.setX((getX()*num));
    vec.setY((getY()*num));
    return vec;
}



std::ostream &operator<<(std::ostream &out, const Vector2f &vec) {
    out << "("<<vec.getX()<<","<<vec.getY()<<")";
    return out;
}
//checks distance between 2 points by d=sqrt((x2−x1)**2+(y2−y1)**2)
double Vector2f::distance(const Vector2f &vector) const {

    return sqrt(((getX()-vector.getX())*(getX()-vector.getX()))+((getY()-vector.getY())*(getY()-vector.getY())));
}

void Vector2f::operator*=(const double &num) {
    setX(getX()*num);
    setY(getY()*num);

}













