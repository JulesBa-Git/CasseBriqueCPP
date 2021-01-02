#include "surfaceRebondissante.h"


surfaceRebondissante::~surfaceRebondissante()
{

}

surfaceRebondissante::surfaceRebondissante(const point &hautGauche, const point &basDroit) : d_pointHautGauche{hautGauche}, d_pointBasDroit{basDroit}
{}

void surfaceRebondissante::afficher() const
{
    int tableauCotes[8] = {d_pointBasDroit.x(),d_pointBasDroit.y(), d_pointHautGauche.x(),d_pointBasDroit.y(),d_pointHautGauche.x(), d_pointHautGauche.y(), d_pointBasDroit.x(),d_pointHautGauche.y()};
    fillpoly(4,tableauCotes);
}

void surfaceRebondissante::afficher(int couleur) const
{
    setcolor(couleur);
    afficher();
}

void surfaceRebondissante::faitRebondir(balle& b,int arriveeDeLaBalle)
{
    if(arriveeDeLaBalle == b.CONTACT_VERTICAL)
    {
        double NewX = (b.vitesse().x())*(-1.0);
        b.changeVitesse(NewX,b.vitesse().y());
    }
    else if (arriveeDeLaBalle == b.CONTACT_HORIZONTAL)
    {
        double NewY = (b.vitesse().y())*(-1.0);
        b.changeVitesse(b.vitesse().x(),NewY);
    }
}

point surfaceRebondissante::pointHautGauche() const
{
    return d_pointHautGauche;
}

point surfaceRebondissante::pointBasDroit() const
{
    return d_pointBasDroit;
}

double surfaceRebondissante::xPointHautGauche() const
{
    return d_pointHautGauche.x();
}

double surfaceRebondissante::yPointHautGauche() const
{
    return d_pointHautGauche.y();
}

double surfaceRebondissante::xPointBasDroit() const
{
    return d_pointBasDroit.x();
}

double surfaceRebondissante::yPointBasDroit() const
{
    return d_pointBasDroit.y();
}

