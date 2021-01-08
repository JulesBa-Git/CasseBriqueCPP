#include "brique.h"
#include <ctime>
#include <random>

#ifndef BRIQUEVIE_H
#define BRIQUEVIE_H

class briqueVie : public brique {
public :
    briqueVie(const point &hautGauche, const point &basDroit);
    virtual void afficher() const override;
    virtual void faitRebondir(balle& b,int arriveeDeLaBalle) override;
    double nombreVie();
    virtual void aEteTouchee() override;
private :
    double d_nbVie;

};

#endif // BRIQUEVIE_H
