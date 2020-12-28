#include "mur.h"

mur::mur(const point &hautGauche, const point &basDroit) : surfaceRebondissante{hautGauche,basDroit}
{}




void mur::faitRebondir(balle& b,int arriveeDeLaBalle)
{
    if(arriveeDeLaBalle == b.CONTACT_VERTICALE)
    {
        double NewX = (b.vitesse().x())*(-1.0);
        b.changeVitesse(NewX,b.vitesse().y());
    }
    else if (arriveeDeLaBalle == b.CONTACT_HORIZONTALE)
    {
        double NewY = (b.vitesse().y())*(-1.0);
        b.changeVitesse(b.vitesse().x(),NewY);
    }
}
