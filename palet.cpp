#include "palet.h"
#include <iostream>

palet::palet(const point &hautGauche, const point &basDroit) : d_pointHautGauche{hautGauche}, d_pointBasDroit{basDroit}
{}

void palet::afficher() const
{
    int tableauCotes[8] = {d_pointBasDroit.x(),d_pointBasDroit.y(), d_pointHautGauche.x(),d_pointBasDroit.y(),d_pointHautGauche.x(), d_pointHautGauche.y(), d_pointBasDroit.x(),d_pointHautGauche.y()};
    fillpoly(4,tableauCotes);
}

void palet::faitRebonndir(balle& b)
{

}


void palet::deplacePalet()
{
if(kbhit() != 0)
    {
        switch(getch())
        {
        case static_cast<int>(char{'q'}) : //a faire ! verifier que la balle est dans le terrain
            d_pointBasDroit.deplaceDe(-20,0);
            d_pointHautGauche.deplaceDe(-20,0);
            break;
        case static_cast<int>(char{'d'}) :
            d_pointBasDroit.deplaceDe(20,0);
            d_pointHautGauche.deplaceDe(20,0);
            break;
        default :
            std::cout<<"unkown key pressed"<<std::endl;
            break;
        }
    }
}

