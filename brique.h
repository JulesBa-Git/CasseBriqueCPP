#include "surfaceRebondissante.h"

#ifndef BRIQUE_H
#define BRIQUE_H

class brique : public surfaceRebondissante {
public :
    //constructeur de brique, crée avec le point haut gauche et bas droit
    brique(const point &hautGauche, const point &basDroit);


    //redéfinitions des methodes virtuelles
    virtual void afficher() const override;
    virtual void faitRebonndir(balle& b) override;

    //methode permettant de savoir si la balle est touchee ou non et l'autre permettant de modifier son etat
    bool estTouchee() const;
    void AeteTouchee();

private :
    point d_pointHautGauche;
    point d_pointBasDroit;
    bool d_estTouchee;

};

#endif // BRIQUE_H
