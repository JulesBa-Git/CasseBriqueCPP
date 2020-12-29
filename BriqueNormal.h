#include "brique.h"
#include "point.h"
#ifndef BRIQUENORMALE_H
#define BRIQUENORMALE_H

class BriqueNormale : public brique {
public :
    BriqueNormale(const point &hautGauche, const point &basDroit);
    static const int NUMERO_BRIQUE;
};

#endif // BRIQUENORMALE_H
