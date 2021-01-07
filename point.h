#include <iostream>
#include <cmath>

#ifndef POINT_H
#define POINT_H

class surfaceRebondissante;


/*! \class point
 *  \brief classe representant un point
 *
 *  La classe gere l'initialisation d'un point dans un espace a deux dimensions (qui va composer la balle)
 */


class point{
public :

    /*!
    *  \brief Constructeur
    *
    *  Constructeur de la classe point (qui initialise le point au coordonnées (0,0))
    */
    point();

    /*!
    *  \brief Constructeur
    *
    *  Constructeur de la classe point
    *
    *  \param x : reel correspondant a l'abscisse du point
    *  \param y : reel correspondant a l'ordonnee du point
    */
    point(double x,double y);

    /*!
    *  \brief L'abscisse d'un point
    *
    *  Methode qui permet de renvoyer l'abscisse d'un point
    *
    *  \return le reel correspondant a l'abscisse du point
    */
    double x() const ;

    /*!
    *  \brief L'ordonnee d'un point
    *
    *  Methode qui permet de renvoyer l'ordonnee d'un point
    *
    *  \return le reel correspondant a l'ordonnee du point
    */
    double y() const ;

    /*!
    *  \brief Affiche un point
    *
    *  Methode qui permet d'afficher un point servant uniquement au test
    *
    *  \param ost : objet de type ostream (pour afficher dans la console)
    */
    void afficheSur(std::ostream& ost) const;

    /*!
    *  \brief Lit un point
    *
    *  Methode qui permet de lire un point servant uniquement au test
    *
    *  \param ist : objet de type istream (pour lire depuis la console)
    */
    void litDepuis(std::istream& ist);

    /*!
    *  \brief Distance entre deux points
    *
    *  Methode qui permet de calculer et de renvoyer la distance entre deux points
    *
    *  \param p : un point passe en parametre
    *
    *  \return un reel correspondant a la distance entre les deux points
    */
    double distance(const point& p) const;

    /*!
    *  \brief Deplace un point
    *
    *  Methode qui permet de deplacer un point en additionant ses coordonnees
    *  actuelles avec celles passees en parametre (dx et dy)
    *
    *  \param dx : reel additionne a la valeur de l'abscisse du point
    *  \param dy : reel additionne a la valeur de l'ordonnee du point
    */
    void deplaceDe(double dx, double dy);

    /*!
    *  \brief Deplace un point
    *
    *  Methode qui permet de deplacer un point avec de nouvelles coordonnes
    *  passees en parametre (x et y)
    *
    *  \param x : reel correspondant a la nouvelle abscisse du point
    *  \param y : reel correspondant a la nouvelle ordonnee du point
    */
    void deplaceEn(double x, double y);


    /*!
    *  \brief Operateur d'egalite
    *
    *  Methode qui permet de savoir si le point passe en parametre
    *  est egal que l'objet de la methode
    *
    *  \param pt : correspond a un point
    *
    *  \return true si le point passe en parametre est egal al'objet de la methode,
    *   false sinon
    */
    bool operator==(const point& pt) const;

    /*!
    *  \brief Point dans la surface
    *
    *  Methode qui permet de savoir si un point se trouve dans
    *  une surface rebondissante
    *
    *  \param surface : correspond a une surfaceRebondissante
    *
    *  \return true si le point se trouve dans la surface rebondissante,
    *   false sinon
    */
    bool estDans(surfaceRebondissante* surface)const;

    /*!
    *  \brief Point est en dessous
    *
    *  Methode qui permet de savoir si un point se trouve en dessous
    *  du point passe en parametre
    *
    *  \param pt : correspond a un point
    *
    *  \return true si le point se trouve en dessous du point en parametre,
    *   false sinon
    */
    bool estEnDessousDe(const point& pt) const;

    /*!
    *  \brief Point est au dessus
    *
    *  Methode qui permet de savoir si un point se trouve au dessus
    *  du point passe en parametre
    *
    *  \param pt : correspond a un point
    *
    *  \return true si le point se trouve au dessus du point en parametre,
    *   false sinon
    */
    bool estAuDessusDe(const point& pt) const;

    /*!
    *  \brief Point est a droite
    *
    *  Methode qui permet de savoir si un point se trouve a droite
    *  du point passe en parametre
    *
    *  \param pt : correspond a un point
    *
    *  \return true si le point se trouve a droite du point en parametre,
    *   false sinon
    */
    bool estADroiteDe(const point& pt) const;

    /*!
    *  \brief Point est a gauche
    *
    *  Methode qui permet de savoir si un point se trouve a gauche
    *  du point passe en parametre
    *
    *  \param pt : correspond a un point
    *
    *  \return true si le point se trouve a gauche du point en parametre,
    *   false sinon
    */
    bool estAGaucheDe(const point& pt) const;


private :

    double d_x; /*!< L'abscisse du point (reel). */
    double d_y; /*!< L'ordonnee du point (reel). */

};

#endif // POINT_H
