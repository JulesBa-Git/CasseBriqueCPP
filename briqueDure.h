#include "brique.h"
#include "graphics.h"


#ifndef BRIQUEDURE_H
#define BRIQUEDURE_H

class briqueDure : public brique {
public :
    briqueDure(const point &hautGauche, const point &basDroit);
    virtual void afficher() const override;
    virtual void faitRebondir(balle& b,int arriveeDeLaBalle) override;
private :
    static constexpr double d_accelerationPourcentage = 1.25;

};

#endif // BRIQUEDURE_H
