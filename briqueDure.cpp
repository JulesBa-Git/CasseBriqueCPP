#include "briqueDure.h"

briqueDure::briqueDure(const point &hautGauche, const point &basDroit) : brique{hautGauche,basDroit}
{}

void briqueDure::afficher() const
{
    setcolor(BLUE);
    brique::afficher();
}

void briqueDure::faitRebondir(balle& b,int arriveeDeLaBalle)
{
     if(arriveeDeLaBalle == b.CONTACT_HORIZONTAL)
    {
        double NewX = (b.vitesse().x())*(-1.0);
        double NewY = b.vitesse().y();
        NewX *= d_accelerationPourcentage;
        b.changeVitesse(NewX,NewY);
    }
    else if (arriveeDeLaBalle == b.CONTACT_VERTICAL)
    {
        double NewY = (b.vitesse().y())*(-1.0);
        NewY*= d_accelerationPourcentage;
        double NewX = b.vitesse().x();
        b.changeVitesse(NewX,NewY);
    }
    aEteTouchee();
}
