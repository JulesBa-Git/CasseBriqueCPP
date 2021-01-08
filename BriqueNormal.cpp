#include "BriqueNormal.h"

BriqueNormale::BriqueNormale(const point &hautGauche, const point &basDroit) : brique{hautGauche,basDroit}
{}

void BriqueNormale::afficher() const
{
    setcolor(WHITE);
    brique::afficher();
}

const int BriqueNormale::NUMERO_BRIQUE{3};


