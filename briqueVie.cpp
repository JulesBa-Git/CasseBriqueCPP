#include "briqueVie.h"

briqueVie::briqueVie(const point &hautGauche, const point &basDroit) : brique{hautGauche,basDroit}, d_nbVie{0}
{
    srand(time(NULL));
    int nbVie = 2+rand() %2;
    d_nbVie = nbVie;
}

void briqueVie::afficher() const
{
    if(d_nbVie == 1)
    {
        setcolor(LIGHTGRAY);
    }
    else if (d_nbVie == 2)
    {
        setcolor(BROWN);
    }
    else {
        setcolor(DARKGRAY);
    }

    brique::afficher();
}

void briqueVie::faitRebondir(balle& b,int arriveeDeLaBalle)
{
    if(arriveeDeLaBalle == b.CONTACT_HORIZONTAL)
    {
        double NewX = (b.vitesse().x())*(-1.0);
        double NewY = b.vitesse().y();
        b.changeVitesse(NewX,NewY);
    }
    else if (arriveeDeLaBalle == b.CONTACT_VERTICAL)
    {
        double NewY = (b.vitesse().y())*(-1.0);
        double NewX = b.vitesse().x();
        b.changeVitesse(NewX,NewY);
    }
    aEteTouchee();
}

double briqueVie::nombreVie()
{
    return d_nbVie;
}

void briqueVie::aEteTouchee()
{
    d_nbVie--;
    if(d_nbVie <= 0)
    {
        brique::aEteTouchee();
    }
}
