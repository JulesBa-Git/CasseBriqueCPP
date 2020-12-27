#include "vecteur.h"

vecteur::vecteur() : d_x{0.0}, d_y{0.0}
{}

vecteur::vecteur(double x,double y) : d_x{x}, d_y{y}
{}


double vecteur::x() const
{
    return d_x;
}

double vecteur::y() const
{
    return d_y;
}


void vecteur::devient(double x, double y)
{
    d_x = x;
    d_y = y;
}

vecteur vecteur::operator-() const
{
    return {-d_x,-d_y};
}

vecteur& vecteur::operator*=(double l)
{
    d_x *= l;
    d_y *= l;
    return *this;
}

vecteur vecteur::operator*(double l) const
{
    vecteur res{*this};
    res *= l;
    return res;
}

void vecteur::print(std::ostream& ost) const
{
  ost<<'('<<d_x<<','<<d_y<<')';
}

void vecteur::read(std::istream& ist)
{
    char c;
    double x,y;
    ist>>c>>x>>c>>y>>c;
    if (ist.good())
    {
        d_x = x;
        d_y = y;
    }
}

vecteur operator*(double val, const vecteur& v)
{
    return v*val;
}
