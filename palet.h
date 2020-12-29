#include "surfaceRebondissante.h"

#ifndef PALET_H
#define PALET_H

class palet : public surfaceRebondissante{
public :
    //constructeur de palet avec le point haut gauche et le point bas droit
    palet(const point &hautGauche, const point &basDroit);


    //redéfinitions des methodes virtuelles


    //methodes permettant de deplacer le palet
    void deplacePalet();
    void deplacePalet(int distance);

private :
    static const int TAILLE_DEPLACEMENT = 20;


};

#endif // PALET_H
