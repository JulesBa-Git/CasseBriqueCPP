#include "mur.h"

mur::mur(const point &hautGauche, const point &basDroit) : d_pointHautGauche{hautGauche}, d_pointBasDroit{basDroit}
{}

void mur::afficher() const
{
    int tableauCotes[8] = {d_pointBasDroit.x(),d_pointBasDroit.y(), d_pointHautGauche.x(),d_pointBasDroit.y(),d_pointHautGauche.x(), d_pointHautGauche.y(), d_pointBasDroit.x(),d_pointHautGauche.y()};
    fillpoly(4,tableauCotes);
}


void mur::faitRebonndir(balle& b)
{

}
