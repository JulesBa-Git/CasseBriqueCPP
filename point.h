#include <iostream>
#include <cmath>

#ifndef POINT_H
#define POINT_H

class surfaceRebondissante;

//classe repr�sentant un point dans un espace a deux dimensions qui va compos� la balle

class point{
public :

    //constructeur par d�fault initialise le point au coordonn�es (0,0)
    point();

    point(double x,double y);

    //fonction renvoyant les coordonn�es d'un point
    double x() const ;
    double y() const ;

    //procedure permettant d'afficher et lire un point servant uniquement au test (� priori)
    void afficheSur(std::ostream& ost) const;
    void litDepuis(std::istream& ist);

    double distance(const point& p) const;

    //proc�dure permettant de modifier les coordonn�es d'un point
    void deplaceDe(double dx, double dy);
    void deplaceEn(double x, double y);

    bool operator==(const point& pt) const;

    bool estDans(surfaceRebondissante* surface)const;
    bool estEnDessousDe(const point& pt) const;
    bool estADroiteDe(const point& pt) const;
    bool estAGaucheDe(const point& pt) const;
    bool estAuDessusDe(const point& pt) const;

private :

    double d_x;
    double d_y;
};

#endif // POINT_H
