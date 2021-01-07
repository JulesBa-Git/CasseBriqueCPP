#include <iostream>
#include <cmath>

#ifndef POINT_H
#define POINT_H

class surfaceRebondissante;

//classe représentant un point dans un espace a deux dimensions qui va composé la balle

class point{
public :

    //constructeur par défault initialise le point au coordonnées (0,0)
    point();

    point(double x,double y);

    //fonction renvoyant les coordonnées d'un point
    double x() const ;
    double y() const ;

    //procedure permettant d'afficher et lire un point servant uniquement au test (à priori)
    void afficheSur(std::ostream& ost) const;
    void litDepuis(std::istream& ist);

    double distance(const point& p) const;

    //procédure permettant de modifier les coordonnées d'un point
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
