#include "surfaceRebondissante.h"

#ifndef MUR_H
#define MUR_H

class mur : public surfaceRebondissante {
public :

    //constructeur du mur, mur créer avec son point haut gauche et bas droit
    mur(const point &hautGauche, const point &basDroit);

    //redéfinitions des methodes virtuelles
    virtual void afficher() const override;
    virtual void faitRebonndir(balle& b) override;

    //mettre des methodes qui renvoie les points

private :
    point d_pointHautGauche;
    point d_pointBasDroit;

};

#endif // MUR_H
