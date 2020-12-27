#include "point.h"

using std::cin;
using std::cout;

point::point() : d_x{0.0}, d_y{0.0}
 {}

point::point(double x,double y) : d_x{x}, d_y{y}
 {}

double  point::x() const
 {
     return d_x;
 }

double point::y() const
 {
     return d_y;
 }


void point::afficheSur(std::ostream& ost) const
{
    ost<<"("<<d_x<<","<<d_y<<")"<<std::endl;
}

void point::litDepuis(std::istream& ist)
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

double point::distance(const point & p) const
{
    double x = p.d_x - d_x;
    double y = p.d_y - d_y;
    return sqrt(((x*x) +(y*y)));
}

void point::deplaceDe(double dx,double dy)
{
    d_x+=dx;
    d_y+=dy;
}

void point::deplaceEn(double x, double y)
{
    d_x = x;
    d_y = y;
}

