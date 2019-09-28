#ifndef MYVECTOR_H
#define MYVECTOR_H
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

class Vector
{
public:
    Vector();
    Vector(float x_, float y_);
    Vector(const sf::Vector2f& v);
    Vector(const sf::Vector2i& v);
    double Mag() const;
    Vector Unit() const;
    friend Vector operator + (const Vector& lhs, const Vector& rhs);
    friend Vector operator - (const Vector& lhs, const Vector& rhs);
    friend Vector operator * (const Vector& lhs, const Vector& rhs);
    friend Vector operator * (const Vector& lhs, double rhs);
    friend Vector operator / (const Vector& lhs, double rhs);

    friend ostream& operator <<(ostream& outs, const Vector& v);

    //this is the same as subtract vectors
    double Distance(const Vector& other) const;

    sf::Vector2f V();
    float& X();
    float& Y();
private:
    float x;
    float y;
};

#endif // MyVECTOR_H
