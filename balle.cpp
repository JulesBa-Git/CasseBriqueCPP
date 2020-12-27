#include "balle.h"

balle::balle(const point& centre,const vecteur& vitesse, int rayon) : d_centre{centre},
    d_vitesse{vitesse}, d_radius{rayon}
{}

point balle::milieu() const
{
    return d_centre;
}

int balle::rayon() const
{
    return d_radius;
}

vecteur balle::vitesse() const
{
    return d_vitesse;
}

void balle::bouger(double dt)
{
    double xPos = d_centre.x() + d_vitesse.x()*dt;
    double yPos = d_centre.y() + d_vitesse.y()*dt;
    d_centre.deplaceEn(xPos,yPos);
}

void balle::deplaceCentre(double x, double y)
{
    d_centre.deplaceEn(x,y);
}

void balle::changeVitesse(const vecteur& vitesse)
{
    d_vitesse = vitesse;
}

void balle::afficher() const
{
    fillellipse(d_centre.x(),d_centre.y(),d_radius,d_radius);
}

bool balle::rentreDans(const surfaceRebondissante& surface) const
{

}
