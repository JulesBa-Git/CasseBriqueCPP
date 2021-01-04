#include "surfaceRebondissante.h"
#include "balle.h"
#include <iostream>
#ifndef MUR_H
#define MUR_H

class mur : public surfaceRebondissante {
public :

    //constructeur du mur, mur créer avec son point haut gauche et bas droit
    mur(const point &hautGauche, const point &basDroit);


};

#endif // MUR_H
