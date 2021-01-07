#include "balle.h"
#include"surfaceRebondissante.h"


const int balle::CONTACT_VERTICAL{1};
const int balle::CONTACT_HORIZONTAL{2};




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

bool balle::rebonditSur(surfaceRebondissante* surface)
{
    if(contactParLaDroite(surface))
    {
        MiseAjourPosition(surface->xPointHautGauche()-d_radius, d_centre.y());
        if(seDeplaceVersLaDroite())
            surface->faitRebondir(*this,CONTACT_HORIZONTAL);
        else
            surface->faitRebondir(*this,CONTACT_VERTICAL);
        return true;
    }
    else if(contactParLaGauche(surface))
    {
        MiseAjourPosition(surface->xPointBasDroit()+d_radius, d_centre.y());
        if(seDeplaceVersLaGauche())
            surface->faitRebondir(*this,CONTACT_HORIZONTAL);
        else
            surface->faitRebondir(*this,CONTACT_VERTICAL);
        return true;
    }
    else if(contactParLeBas(surface))
    {
        MiseAjourPosition(d_centre.x(), surface->pointHautGauche().y()- d_radius);
        if(seDeplaceVersLeBas())
            surface->faitRebondir(*this,CONTACT_VERTICAL);
        else
            surface->faitRebondir(*this,CONTACT_HORIZONTAL);
        return true;
    }
    else if(contactParLeHaut(surface))
    {
        MiseAjourPosition(d_centre.x(), surface->pointBasDroit().y() + d_radius);
        if(seDeplaceVersLeHaut())
            surface->faitRebondir(*this,CONTACT_VERTICAL);
        else
            surface->faitRebondir(*this,CONTACT_HORIZONTAL);
        return true;
    }
    else
    {
        return false;
    }
}

bool balle::seDeplaceVersLaDroite() const
{
    return d_vitesse.x() > 0;
}

bool balle::seDeplaceVersLaGauche() const
{
    return d_vitesse.x() < 0;
}

bool balle::seDeplaceVersLeHaut() const
{
    return d_vitesse.y() < 0;
}

bool balle::seDeplaceVersLeBas() const
{
    return d_vitesse.y() > 0;
}

bool balle::contactParLeHaut(surfaceRebondissante* surface)const
{
    point hautDeLaBalle{d_centre.x(), d_centre.y()-d_radius};
    return hautDeLaBalle.estDans(surface);
}

bool balle::contactParLeBas(surfaceRebondissante* surface) const
{
    point basDeLaBalle{d_centre.x(),d_centre.y()+d_radius};
    return basDeLaBalle.estDans(surface);
}

bool balle::contactParLaGauche(surfaceRebondissante* surface)const
{
    point gaucheDeLaBalle{d_centre.x()-d_radius,d_centre.y()};
    return gaucheDeLaBalle.estDans(surface);
}

bool balle::contactParLaDroite(surfaceRebondissante* surface)const
{
    point droiteDeLaBalle{d_centre.x()+d_radius,d_centre.y()};
    return droiteDeLaBalle.estDans(surface);
}


