#include "brique.h"

brique::brique(const point &hautGauche, const point &basDroit) : surfaceRebondissante{hautGauche,basDroit}, d_estTouchee{false}
{}


void brique::faitRebondir(balle& b,int arriveeDeLaBalle)
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
