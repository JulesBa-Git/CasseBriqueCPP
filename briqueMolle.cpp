#include "briqueMolle.h"

briqueMolle::briqueMolle(const point &hautGauche, const point &basDroit) : brique{hautGauche,basDroit}
{}

void briqueMolle::afficher() const
{
    setcolor(RED);
    brique::afficher();
}

void briqueMolle::faitRebondir(balle& b,int arriveeDeLaBalle)
{
     if(arriveeDeLaBalle == b.CONTACT_HORIZONTAL)
    {
        double NewX = (b.vitesse().x())*(-1.0);
        double NewY = b.vitesse().y();
        NewX *= d_decelerationPourcentage;
        b.changeVitesse(NewX,NewY);
    }
    else if (arriveeDeLaBalle == b.CONTACT_VERTICAL)
    {
        double NewY = (b.vitesse().y())*(-1.0);
        NewY*= d_decelerationPourcentage;
        double NewX = b.vitesse().x();
        b.changeVitesse(NewX,NewY);
    }
    aEteTouchee();
}
