#include "brique.h"
#include "point.h"
#ifndef BRIQUENORMALE_H
#define BRIQUENORMALE_H

/*! \class BriqueNormale
 *  \brief classe heritee de la classe "brique"
 *
 *  La classe gere l'initialisation d'une brique normal dans le terrain
 */

class BriqueNormale : public brique {
public :

    /*!
    *  \brief Constructeur
    *
    *  Constructeur de la classe BriqueNormale
    *
    *  \param hautGauche : point correspondant au coin superieur gauche de la brique
    *  \param basDroit : point correspondant au coin inferieur droit de la brique
    */
    BriqueNormale(const point &hautGauche, const point &basDroit);

    virtual void afficher() const override;

    static const int NUMERO_BRIQUE; /*!< Numero (entier) correspondant a ce type de brique (brique normale). */
};

#endif // BRIQUENORMALE_H
