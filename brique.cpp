#include "brique.h"
#include "surfaceRebondissante.h"

brique::brique(const point &hautGauche, const point &basDroit) : surfaceRebondissante{hautGauche,basDroit}, d_estTouchee{false}
{}

//affichage different si la balle a ete touchée ou non
void brique::afficher() const
{
    surfaceRebondissante::afficher();
}

void brique::faitRebondir(balle& b,int arriveeDeLaBalle)
{
    surfaceRebondissante::faitRebondir(b,arriveeDeLaBalle);
    aEteTouchee();
}

bool brique::estTouchee() const
{
    return d_estTouchee;
}

void brique::aEteTouchee()
{
    d_estTouchee = true;
}
