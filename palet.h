#include "surfaceRebondissante.h"

#ifndef PALET_H
#define PALET_H

class palet : public surfaceRebondissante{
public :
    //constructeur de palet avec le point haut gauche et le point bas droit
    palet(const point &hautGauche, const point &basDroit);


    //redéfinitions des methodes virtuelles
    virtual void afficher() const override;
    virtual void faitRebonndir(balle& b) override;

    //methodes permettant de deplacer le palet
    void deplacePalet();

private :
    point d_pointHautGauche;
    point d_pointBasDroit;

};

#endif // PALET_H
