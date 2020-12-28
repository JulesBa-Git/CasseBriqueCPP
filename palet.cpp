#include "palet.h"
#include <iostream>

palet::palet(const point &hautGauche, const point &basDroit) : surfaceRebondissante{hautGauche,basDroit}
{}


void palet::faitRebondir(balle& b,int arriveeDeLaBalle)
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

