#include "brique.h"

brique::brique(const point &hautGauche, const point &basDroit) : surfaceRebondissante{hautGauche,basDroit}, d_estTouchee{false}
{}

//affichage different si la balle a ete touchée ou non
void brique::afficher() const
{
    surfaceRebondissante::afficher();
}

void brique::faitRebondir(balle& b,int arriveeDeLaBalle)
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
    AeteTouchee();
}

bool brique::estTouchee() const
{
    return d_estTouchee;
}

void brique::AeteTouchee()
{
    d_estTouchee = true;
}
