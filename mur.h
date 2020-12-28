#include "surfaceRebondissante.h"

#ifndef MUR_H
#define MUR_H

class mur : public surfaceRebondissante {
public :

    //constructeur du mur, mur créer avec son point haut gauche et bas droit
    mur(const point &hautGauche, const point &basDroit);

    //redéfinitions des methodes virtuelles
    virtual void faitRebonndir(balle& b) override;

};

#endif // MUR_H
