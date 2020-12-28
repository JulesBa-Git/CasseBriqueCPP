#include "surfaceRebondissante.h"

#ifndef PALET_H
#define PALET_H

class palet : public surfaceRebondissante{
public :
    //constructeur de palet avec le point haut gauche et le point bas droit
    palet(const point &hautGauche, const point &basDroit);


    //redéfinitions des methodes virtuelles
    virtual void faitRebondir(balle& b,int arriveeDeLaBalle) override;

    //methodes permettant de deplacer le palet
    void deplacePalet();


};

#endif // PALET_H
