#include "brique.h"

brique::brique(const point &hautGauche, const point &basDroit) : d_pointHautGauche{hautGauche}, d_pointBasDroit{basDroit}, d_estTouchee{false}
{}


void brique::afficher() const
{
    int tableauCotes[8] = {d_pointBasDroit.x(),d_pointBasDroit.y(), d_pointHautGauche.x(),d_pointBasDroit.y(),d_pointHautGauche.x(), d_pointHautGauche.y(), d_pointBasDroit.x(),d_pointHautGauche.y()};
    fillpoly(4,tableauCotes);
}

void brique::faitRebonndir(balle& b)
{

}

bool brique::estTouchee() const
{
    return d_estTouchee;
}

void brique::AeteTouchee()
{
    d_estTouchee = true;
}
