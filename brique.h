#include "surfaceRebondissante.h"

#ifndef BRIQUE_H
#define BRIQUE_H

/*! \class brique
 *  \brief classe heritee de la classe abstraite "surfaceRebondissante"
 *
 *  La classe gere l'initialisation d'une brique avec une seule vie et surface de rebond normal
 */

class brique : public surfaceRebondissante {
public :

    /*!
    *  \brief Constructeur
    *
    *  Constructeur de la classe brique
    *
    *  \param hautGauche : point correspondant au coin superieur gauche de la brique
    *  \param basDroit : point correspondant au coin inferieur droit de la brique
    */
    brique(const point &hautGauche, const point &basDroit);

    /*!
    *  \brief Affiche une brique
    *
    *  Redefinition de la methode virtuelle "afficher" de la classe "surfaceRebondissante"
    *  Methode qui permet d'afficher une brique dans le terrain
    */
    virtual void afficher() const override;

    /*!
    *  \brief Rebond sur la brique
    *
    *  Redefinition de la methode virtuelle "faitRebondir" de la classe "surfaceRebondissante"
    *  Methode qui permet de faire rebondir la balle sur une brique
    *
    *  \param b : Objet de type "balle"
    *  \param arriveeDeLaBalle : entier correspondant a une surface de contact
    */
    virtual void faitRebondir(balle& b,int arriveeDeLaBalle) override;

    /*!
    *  \brief La balle est touchee
    *
    *  Methode qui permet de savoir si la balle a touchee ou non une surface
    *
    *  \return true si la balle touche une surface,
    *   false sinon
    */
    bool estTouchee() const;

    /*!
    *  \brief Etat de la balle
    *
    *  Methode qui permet de modifier l'etat de la balle
    *  pour dire que celle-ci a ete touche
    */
    void aEteTouchee();

private :
    bool d_estTouchee; /*!< Booleen permettant de savoir si la balle a ete touche ou non. */

};

#endif // BRIQUE_H
