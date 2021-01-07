#include "graphics.h"
#include "point.h"
#include "balle.h"

#ifndef SURFACEREBONDISSANTE_H
#define SURFACEREBONDISSANTE_H

/*!
 *  \class balle
 */

class balle;

/*! \class surfaceRebondissante
 *  \brief classe abstraite des classes "brique", "palet" et "mur"
 *
 *  La classe represente les surface rebondissantes (mur, palet, briques)
 *  qui vont tous devoir s'afficher et pouvoir faire rebondir la balle.
 */

class surfaceRebondissante{
public :

    /*!
    *  \brief Destructeur
    *
    *  Destructeur de la classe surfaceRebondissante
    */
    virtual ~surfaceRebondissante();

    /*!
    *  \brief Constructeur
    *
    *  Constructeur de la classe surfaceRebondissante
    *
    *  \param hautGauche : point correspondant au coin superieur gauche d'une surface rebondissante
    *  \param basDroit : point correspondant au coin inferieur droit d'une surface rebondissante
    */
    surfaceRebondissante(const point &hautGauche, const point &basDroit);

    /*!
    *  \brief Affiche une surface rebondissante
    *
    *  Methode virtuelle qui permet d'afficher une surface rebondissante dans le terrain
    */
    virtual void afficher() const;

    virtual void afficher(int couleur) const;
    virtual void faitRebondir(balle& b,int arriveeDeLaBalle);


    /*!
    *  \brief Affiche une surface rebondissante
    *
    *  Methode virtuelle qui permet d'afficher une surface rebondissante en couleur
    *  dans le terrain
    *
    *  \param couleur : entier correspondant a une couleur
    */
    virtual void afficher(int couleur) const;

    /*!
    *  \brief Rebond sur une surface rebondissante
    *
    *  Methode virtuelle abstraite qui permet de faire rebondir la balle sur une surface rebondissante
    *
    *  \param b : Objet de type "balle"
    *  \param arriveeDeLaBalle : entier correspondant a une surface de contact
    */
    virtual void faitRebondir(balle& b,int arriveeDeLaBalle);

    /*!
    *  \brief L'abscisse du point superieur gauche
    *
    *  Methode qui permet de renvoyer l'abscisse du point superieur gauche d'une surface rebondissante
    *
    *  \return d_pointHautGauche.x() : l'abscisse du point superieur gauche
    */

    double xPointHautGauche() const;

    /*!
    *  \brief L'ordonnee du point superieur gauche
    *
    *  Methode qui permet de renvoyer l'ordonnee du point superieur gauche d'une surface rebondissante
    *
    *  \return d_pointHautGauche.y() : l'ordonnee du point superieur gauche
    */
    double yPointHautGauche() const;

    /*!
    *  \brief L'abscisse du point inferieur droit
    *
    *  Methode qui permet de renvoyer l'abscisse du point inferieur droit d'une surface rebondissante
    *
    *  \return d_pointBasDroit.x() : l'abscisse du point inferieur droit
    */
    double xPointBasDroit() const;

    /*!
    *  \brief L'ordonnee du point inferieur droit
    *
    *  Methode qui permet de renvoyer l'ordonnee du point inferieur droit d'une surface rebondissante
    *
    *  \return d_pointBasDroit.y() : l'ordonnee du point inferieur droit
    */
    double yPointBasDroit() const;

    /*!
    *  \brief Le point superieur gauche
    *
    *  Methode qui permet de renvoyer le point superieur gauche d'une surface rebondissante
    *
    *  \return d_pointHautGauche : le point superieur gauche
    */
    point pointHautGauche() const;

    /*!
    *  \brief Le point inferieur droit
    *
    *  Methode qui permet de renvoyer le point inferieur droit d'une surface rebondissante
    *
    *  \return d_pointBasDroit : le point inferieur droit
    */
    point pointBasDroit() const;

protected :

    point d_pointHautGauche; /*!< Point superieur gauche d'une surface rebondissante. */
    point d_pointBasDroit; /*!< Point inferieur droit d'une surface rebondissante. */

};
#endif // SURFACEREBONDISSANTE_H
