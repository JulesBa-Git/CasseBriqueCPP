#include <iostream>

#ifndef VECTEUR_H
#define VECTEUR_H

/*! \class vecteur
 *  \brief classe representant un vecteur
 *
 *  Classe representant un vecteur a deux dimensions qui va servir a representer la vitesse de la balle
 */

class vecteur {
public:

    /*!
    *  \brief Constructeur
    *
    *  Constructeur par default de la classe vecteur (qui initialise un vecteur a (0,0))
    */
    vecteur();

    /*!
    *  \brief Constructeur
    *
    *  Constructeur de la classe vecteur
    *
    *  \param x : reel correspondant a l'abscisse d'un vecteur
    *  \param y : reel correspondant a l'ordonnee d'un vecteur
    */
    vecteur(double x,double y);

    /*!
    *  \brief L'abscisse du vecteur
    *
    *   Methode qui permet de renvoyer l'abscisse d'un vecteur
    *
    *  \return d_x : reel correspondant a l'abscisse d'un vecteur
    */
    double x() const;

    /*!
    *  \brief L'ordonnee du vecteur
    *
    *   Methode qui permet de renvoyer l'ordonnee d'un vecteur
    *
    *  \return d_y : reel correspondant a l'ordonnee d'un vecteur
    */
    double y() const;

    /*!
    *  \brief Modifie le vecteur
    *
    *   Methode qui permet de modifier un vecteur
    */
    void devient(double x, double y);

    /*!
    *  \brief Inverse un vecteur
    *
    *   Operateur qui permet d'inverser un vecteur
    *
    *  \return le vecteur de signe oppose (-x et -y)
    */
    vecteur  operator-() const;

    /*!
    *  \brief Multiplie un vecteur par un pourcentage
    *
    *   Operateur qui permet de multiplier un vecteur par un réel
    *   Servira a modifier la vitesse en fonction d'un pourcentage
    *   Modifie l'objet
    *
    *  \return ce vecteur multiplie par un reel
    */
    vecteur& operator*=(double reel);

    /*!
    *  \brief Multiplie un vecteur par un pourcentage
    *
    *   Operateur qui permet de multiplier un vecteur par un réel
    *   Servira a modifier la vitesse en fonction d'un pourcentage
    *
    *  \return le vecteur multiplie par un reel
    */
    vecteur operator*(double reel) const;

    /*!
    *  \brief Affiche un vecteur
    *
    *   Methode qui permet de tester les constructeurs d'un vecteur
    *   Affiche un vecteur sur un flux (ost)
    */
    void print(std::ostream& ost) const;

    /*!
    *  \brief Lit un vecteur
    *
    *   Methode qui permet de tester les constructeurs d'un vecteur
    *   Lit un vecteur depuis un flux (ist)
    */
    void read(std::istream& ist);

private:

    double d_x; /*!< Reel correspondant a l'abscisse d'un vecteur. */
    double d_y; /*!< Reel correspondant a l'ordonnee d'un vecteur. */

};

/*!
 *  \brief Multiplie un vecteur par un reel
 *
 *   Opérateur qui permet de multiplier un vecteur par un réel presents dans la classe
 *
 *  \return le vecteur multiplie par un reel
 */
vecteur operator*(double val, const vecteur& v);

#endif // VECTEUR_H
