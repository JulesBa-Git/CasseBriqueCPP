#include "surfaceRebondissante.h"
#include "balle.h"
#include <iostream>
#ifndef MUR_H
#define MUR_H

/*! \class mur
 *  \brief classe heritee de la classe abstraite "surfaceRebondissante"
 *
 *  La classe gere l'initialisation d'un mur dans le terrain
 */

class mur : public surfaceRebondissante {
public :

    /*!
    *  \brief Constructeur
    *
    *  Constructeur de la classe mur
    *
    *  \param hautGauche : point correspondant au coin superieur gauche du mur
    *  \param basDroit : point correspondant au coin inferieur droit du mur
    */
    mur(const point &hautGauche, const point &basDroit);

};

#endif // MUR_H
