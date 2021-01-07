#include "point.h"
#include "surfaceRebondissante.h"

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

bool point::operator==(const point& pt) const
{
    return d_x==pt.d_x && d_y==pt.d_y;
}

bool point::estDans(surfaceRebondissante* surface)const
{
    if(surface == nullptr){
        return false;
    }
    bool xEstBon = estADroiteDe(surface->pointHautGauche()) && estAGaucheDe(surface->pointBasDroit());
    bool yEstBon = estEnDessousDe(surface->pointHautGauche()) && estAuDessusDe(surface->pointBasDroit());
    return xEstBon && yEstBon;
}


bool point::estEnDessousDe(const point& pt) const
{
    return d_y > pt.d_y;
}

bool point::estADroiteDe(const point& pt) const
{
    return d_x > pt.d_x;
}

bool point::estAGaucheDe(const point& pt) const
{
    return d_x < pt.d_x;
}

bool point::estAuDessusDe(const point& pt) const
{
    return d_y < pt.d_y;
}
