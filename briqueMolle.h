#include "brique.h"
#include "graphics.h"


#ifndef  BRIQUEMOLLE_H
#define BRIQUEMOLLE_H

class briqueMolle : public brique {
public :
    briqueMolle(const point &hautGauche, const point &basDroit);
    virtual void afficher() const override;
    virtual void faitRebondir(balle& b,int arriveeDeLaBalle) override;
private :
    static constexpr double d_decelerationPourcentage = 0.85;


};

#endif // BRIQUEMOLLE_H
