#include "MyVector.h"
#include <cmath>
using namespace std;

Vector::Vector():x(0), y(0)
{
}

Vector::Vector(float x_, float y_):x(x_), y(y_){

}
Vector::Vector(const sf::Vector2f& v):x(v.x), y(v.y){
}

Vector::Vector(const sf::Vector2i& v):x(v.x), y(v.y){
}

double Vector::Mag() const{
    return sqrt(pow(x,2) + pow(y,2));
}

Vector Vector::Unit() const{
    double mag = Mag();
    return Vector(x/mag, y/mag);
}

Vector operator + (const Vector& lhs, const Vector& rhs){
    return Vector(lhs.x+rhs.x, lhs.y+rhs.y);
}

Vector operator - (const Vector& lhs, const Vector& rhs){
    return Vector(lhs.x-rhs.x, lhs.y-rhs.y);

}

Vector operator * (const Vector& lhs, const Vector& rhs){
    return Vector(lhs.x*rhs.x, lhs.y*rhs.y);

}

Vector operator * (const Vector& lhs, double rhs){
    return Vector(lhs.x*rhs, lhs.y*rhs);

}

Vector operator / (const Vector& lhs, double rhs){
    if (rhs ==0)
    {
        cout<<"division by zero: Vector/0"<<endl;
        return lhs;
    }
    return Vector(lhs.x/rhs, lhs.y/rhs);

}

ostream& operator <<(ostream& outs, const Vector& v){
    outs<<"("<<v.x<<", "<<v.y<<")";
    return outs;
}

double Vector::Distance(const Vector& other) const{
    return (*this - other).Mag();
}


sf::Vector2f Vector::V(){
    return sf::Vector2f(x, y);
}


float& Vector::X(){
    return x;
}

float& Vector::Y(){
    return y;
}
