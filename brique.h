#include "surfaceRebondissante.h"

#ifndef BRIQUE_H
#define BRIQUE_H

//class brique classiqe avec une seule vie et surface de rebond normal
class brique : public surfaceRebondissante {
public :
    //constructeur de brique, crée avec le point haut gauche et bas droit
    brique(const point &hautGauche, const point &basDroit);


    //redéfinitions des methodes virtuelles
    virtual void afficher() const override;

    virtual void faitRebondir(balle& b,int arriveeDeLaBalle) override;

    //methode permettant de savoir si la balle est touchee ou non et l'autre permettant de modifier son etat
    bool estTouchee() const;
    void aEteTouchee();

private :
    bool d_estTouchee;

};

#endif // BRIQUE_H
