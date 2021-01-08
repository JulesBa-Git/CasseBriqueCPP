#include "surfaceRebondissante.h"

#ifndef PALET_H
#define PALET_H

/*! \class palet
 *  \brief classe heritee de la classe abstraite "surfaceRebondissante"
 *
 *  La classe gere l'initialisation d'un palet dans le terrain
 */

class palet : public surfaceRebondissante{
public :

    /*!
    *  \brief Constructeur
    *
    *  Constructeur de la classe mur
    *
    *  \param hautGauche : point correspondant au coin superieur gauche du palet
    *  \param basDroit : point correspondant au coin inferieur droit du palet
    */
    palet(const point &hautGauche, const point &basDroit);

    /*!
    *  \brief Rebond de la balle sur le palet
    *
    *  Redefinition de la methode "faitRebondir" de la classe "surfaceRebondissante"
    *  Methode qui permet de faire rebondir la balle sur le palet
    *
    *  \param b : objet de type balle
    *  \param arriveeDeLaBalle : entier correspondant a une surface de contact du terrain
    */
    void deplacePalet();


    /*!
    *  \brief Deplace le palet
    *
    *  Methode qui permet de deplacer le palet dans le terrain, entre les murs verticales
    */
    void deplacePalet(int distance);

    double largeurPalet() const;

    double positionBalleRelativeAuPalet(const balle& b) const;

private :


    static const int TAILLE_DEPLACEMENT = 20; /*!< Entier constant correspondant a la taille de deplacement du plalet. */

};

#endif // PALET_H
