#include "palet.h"
#include <iostream>

palet::palet(const point &hautGauche, const point &basDroit) : surfaceRebondissante{hautGauche,basDroit}
{}

void palet::deplacePalet()
{
    if(kbhit() != 0)
        {
            switch(getch())
            {
            case static_cast<int>(char{'q'}) : //a faire ! verifier que la balle est dans le terrain
                deplacePalet(-TAILLE_DEPLACEMENT);
                break;
            case static_cast<int>(char{'d'}) :
                deplacePalet(TAILLE_DEPLACEMENT);
                break;
            default :
                std::cout<<"unkown key pressed"<<std::endl;
                break;
            }
        }
}


double palet::largeurPalet() const
{
    return pointBasDroit().x() - pointHautGauche().x();
}

double palet::positionBalleRelativeAuPalet(const balle& b) const
{
    return b.milieu().x() - pointHautGauche().x();
}

void palet::deplacePalet(int distance)
{
    d_pointBasDroit.deplaceDe(distance,0);
    d_pointHautGauche.deplaceDe(distance,0);
}

