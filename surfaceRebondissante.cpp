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

point surfaceRebondissante::pointHautGauche() const
{
    return d_pointHautGauche;
}

point surfaceRebondissante::pointBasDroit() const
{
    return d_pointBasDroit;
}
