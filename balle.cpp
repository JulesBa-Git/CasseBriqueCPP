#include "balle.h"

const int balle::CONTACT_HORIZONTALE{1};
const int balle::CONTACT_VERTICALE{2};




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

void balle::MiseAjourPosition(double x, double y)
{
    d_centre.deplaceEn(x,y);
}

void balle::changeVitesse(const vecteur& vitesse)
{
    d_vitesse = vitesse;
}

void balle::changeVitesse(double x, double y)
{
    d_vitesse.devient(x,y);
}

void balle::afficher(int couleur) const
{
    setcolor(couleur);
    fillellipse(d_centre.x(),d_centre.y(),d_radius,d_radius);
}

bool balle::rentreDans(surfaceRebondissante* surface)
{
    if(contactParLaDroite(surface))
    {
        MiseAjourPosition(surface->xPointHautGauche()-d_radius, d_centre.y());
        surface->faitRebondir(*this,CONTACT_VERTICALE);
        return true;
    }
    else if(contactParLaGauche(surface))
    {
        MiseAjourPosition(surface->xPointBasDroit()+d_radius, d_centre.y());
        surface->faitRebondir(*this,CONTACT_VERTICALE);
        return true;
    }
    else if(contactParLeBas(surface))
    {
        MiseAjourPosition(d_centre.x(), surface->pointHautGauche().y()- d_radius);
        surface->faitRebondir(*this,CONTACT_HORIZONTALE);
        return true;
    }
    else if(contactParLeHaut(surface))
    {
        MiseAjourPosition(d_centre.x(), surface->pointBasDroit().y() + d_radius);
        surface->faitRebondir(*this,CONTACT_HORIZONTALE);
        return true;
    }
    else{
        return false;
    }
}

bool balle::contactParLaGauche(surfaceRebondissante* surface) const
{
    return (d_centre.x()-d_radius > surface->pointHautGauche().x() && d_centre.x()-d_radius < surface->pointBasDroit().x() && d_centre.y() > surface->pointHautGauche().y() && d_centre.y() < surface->pointBasDroit().y());
}

bool balle::contactParLaDroite(surfaceRebondissante* surface) const
{
    return (d_centre.x()+d_radius > surface->pointHautGauche().x() && d_centre.x()+d_radius < surface->pointBasDroit().x() && d_centre.y() > surface->pointHautGauche().y() && d_centre.y() < surface->pointBasDroit().y());
}

bool balle::contactParLeHaut(surfaceRebondissante* surface) const
{
    return (d_centre.y()-d_radius > surface->pointHautGauche().y() && d_centre.y()-d_radius < surface->pointBasDroit().y() && d_centre.x() > surface->pointHautGauche().x() && d_centre.x() < surface->pointBasDroit().x());
}

bool balle::contactParLeBas(surfaceRebondissante* surface) const
{
    return ( d_centre.y()+d_radius > surface->pointHautGauche().y() && d_centre.y()+d_radius < surface->pointBasDroit().y() && d_centre.x() > surface->pointHautGauche().x() && d_centre.x() < surface->pointBasDroit().x());
}


