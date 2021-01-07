#ifndef BALLE_H
#define BALLE_H
#include "point.h"
#include "vecteur.h"
#include "graphics.h"
#include "surfaceRebondissante.h"


/**
    Classe representant une balle
*/

class balle{
public :
    ///constructeur de balle, ici une balle est construite avec un point qui est son centre, son vecteur vitesse et son rayon
    balle(const point& centre,const vecteur& vitesse, int rayon);

    ///méthode permettant l'acces au données privés

/*! \class balle
 *  \brief classe representant la balle du jeu
 *
 *  La classe gere l'initialisation de la balle dans le terrain
 */

class balle{
public :

    /*!
    *  \brief Constructeur
    *
    *  Constructeur de la classe balle
    *
    *  \param centre : point correspondant au centre de la balle
    *  \param vitesse : vecteur correspondant a la vitesse de la balle
    *  \param rayon : entier correspondant au rayon de la balle
    */
    balle(const point& centre,const vecteur& vitesse, int rayon);

    /*!
    *  \brief Milieu de la balle
    *
    *  Methode qui permet l'acces au données privés.
    *  Elle permet de connaitre la position (point) du centre de la balle
    *
    *  \return un point correspondant au centre de la balle
    */

    point milieu() const;

    /*!
    *  \brief Rayon de la balle
    *
    *  Methode qui permet de renvoyer la longueur du rayon de la balle
    *
    *  \return un entier correspondant au rayon de la balle
    */
    int rayon() const;

    /*!
    *  \brief Vitesse de la balle
    *
    *  Methode qui permet de renvoyer la vitesse de la balle grace aux donnees de la classe "vecteur"
    *
    *  \return un vecteur correspondant a la vitesse de la balle
    */
    vecteur vitesse() const;

    ///permet de deplacer la balle par rapport au temps grace a son vecteur vitesse (dt constante a definir ?)
    void bouger(double dt);

    ///permet de deplacer la bale de maniere absolue (quand la balle va trop loin dans un mur p.ex)
    void MiseAjourPosition(double x, double y);

    /**
        Permet de mofifier le vecteur vitesse de la balle
        @param vitesse
    */
    void changeVitesse(const vecteur& vitesse);

    /**
        Permet de mofifier le vecteur vitesse de la balle
        @param x
        @param y
    */
    void changeVitesse(double x, double y);

    /**
        permet d'afficher la balle
        @param couleur la couleur de la balle
    */
    void afficher(int couleur) const;

    /**
        Savoir si la balle est rentrée dans une surface rebondissante pour reagir avec un rebond
        @param surface
        @return vrai si
    */
    bool rebonditSur(surfaceRebondissante* surface);

    /**
        Detecter les contacts par la gauche
        @return vrai si la balle touche une surface gauche
    */
    bool contactParLaGauche(surfaceRebondissante* surface) const;
    /**
        Detecter les contacts par la droite
        @return vrai si la balle touche une surface droite
    */
    bool contactParLaDroite(surfaceRebondissante* surface) const;
    /**
        Detecter les contacts par le haut
        @return vrai si la balle touche une surface par le haute
    */
    bool contactParLeHaut(surfaceRebondissante* surface) const;
    /**
        Detecter les contacts par le bas
        @return vrai si la balle touche une surface par le bas
    */
    bool contactParLeBas(surfaceRebondissante* surface) const;

    /**
        Renvoyer vrai si la balle se déplace vers la droite
    */
    bool seDeplaceVersLaDroite() const;

    /**
        Renvoyer vrai si la balle se déplace vers la gauche
    */
    bool seDeplaceVersLaGauche() const;

    /**
        Renvoyer vrai si la balle se déplace vers le haut
    */
    bool seDeplaceVersLeHaut() const;

    /**
        Renvoyer vrai si la balle se déplace vers le bas
    */
    bool seDeplaceVersLeBas() const;

    static const int CONTACT_VERTICAL;
    static const int CONTACT_HORIZONTAL;

    /*!
    *  \brief Deplace la balle
    *
    *  Methode qui permet de deplacer la balle par rapport au temps grace a son vecteur vitesse
    *
    *  \param dt : reel correspondant a un temps
    */
    void bouger(double dt);

    /*!
    *  \brief Mise a jour de la position de la balle
    *
    *  Methode qui permet de deplacer la balle de maniere absolue grace a deux entiers (x et y)
    *  et de la classe "point" avec la methode "deplaceEn(x,y)"
    *  (exemple : quand la balle va trop loin dans un mur)
    *
    *  \param x : entier correspondant a l'abscisse x d'un point
    *  \param y : entier correspondant a l'ordonnee y d'un point
    */
    void MiseAjourPosition(double x, double y);

    /*!
    *  \brief Change la vitesse de la balle
    *
    *  Methode qui permet de mofifier le vecteur vitesse de la balle
    *  grace a un nouveau vecteur vitesse
    *
    *  \param vitesse : vecteur correspondant a la nouvelle vitesse de la balle
    */
    void changeVitesse(const vecteur& vitesse);

    /*!
    *  \brief Change la vitesse de la balle
    *
    *  Methode qui permet de mofifier le vecteur vitesse de la balle
    *  grace a deux entiers (x et y) et de la classe "vecteur" avec la methode "devient(x,y)"
    *
    *  \param x : entier correspondant a la nouvelle coordonnee x du vecteur vitesse
    *  \param y : entier correspondant a la nouvelle coordonnee y du vecteur vitesse
    */
    void changeVitesse(double x, double y);

    /*!
    *  \brief Affiche la balle
    *
    *  Methode qui permet d'afficher la balle d'une certaine couleur dans le terrain
    *
    *  \param couleur : entier correspondant a la couleur de la balle
    */
    void afficher(int couleur) const;

    /*!
    *  \brief Surface rebondissante en contact avec la balle
    *
    *  Methode qui permet de savoir si la balle est rentree en contact avec
    *  une surface rebondissante pour ensuite reagir avec un rebond
    *
    *  \param surface : correspond a un pointeur sur une surface rebondissante
    *   de la classe "surfaceRebondissante"
    *
    *  \return true si la balle est rentree en contact avec une surface rebondissante,
    *   false sinon
    */
    bool rebonditSur(surfaceRebondissante* surface);

    /*!
    *  \brief Contact par la gauche
    *
    *  Methode qui permet de savoir si la balle est rentree en contact
    *  avec une surface rebondissante sur la gauche de celle-ci
    *
    *  \param surface : correspond a un pointeur sur une surface rebondissante
    *   de la classe "surfaceRebondissante"
    *
    *  \return true si la balle est rentree en contact a gauche d'une surface rebondissante,
    *   false sinon
    */
    bool contactParLaGauche(surfaceRebondissante* surface) const;

    /*!
    *  \brief Contact par la droite
    *
    *  Methode qui permet de savoir si la balle est rentree en contact
    *  avec une surface rebondissante sur la droite de celle-ci
    *
    *  \param surface : correspond a un pointeur sur une surface rebondissante
    *   de la classe "surfaceRebondissante"
    *
    *  \return true si la balle est rentree en contact a doite d'une surface rebondissante,
    *   false sinon
    */
    bool contactParLaDroite(surfaceRebondissante* surface) const;

    /*!
    *  \brief Contact par le haut
    *
    *  Methode qui permet de savoir si la balle est rentree en contact
    *  avec une surface rebondissante sur le haut de celle-ci
    *
    *  \param surface : correspond a un pointeur sur une surface rebondissante
    *   de la classe "surfaceRebondissante"
    *
    *  \return true si la balle est rentree en contact par le haut d'une surface rebondissante,
    *   false sinon
    */
    bool contactParLeHaut(surfaceRebondissante* surface) const;

    /*!
    *  \brief Contact par le bas
    *
    *  Methode qui permet de savoir si la balle est rentree en contact
    *  avec une surface rebondissante sur le bas de celle-ci
    *
    *  \param surface : correspond a un pointeur sur une surface rebondissante
    *   de la classe "surfaceRebondissante"
    *
    *  \return true si la balle est rentree en contact par le bas d'une surface rebondissante,
    *   false sinon
    */
    bool contactParLeBas(surfaceRebondissante* surface) const;

    /*!
    *  \brief Se deplace vers la droite
    *
    *  Methode qui permet de savoir si la balle se deplace vers la droite
    *  dans le terrain
    *
    *  \return true si la balle se déplace vers la droite,
    *   false sinon
    */
    bool seDeplaceVersLaDroite() const;

    /*!
    *  \brief Se deplace vers la gauche
    *
    *  Methode qui permet de savoir si la balle se deplace vers la gauche
    *  dans le terrain
    *
    *  \return true si la balle se déplace vers la gauche,
    *   false sinon
    */
    bool seDeplaceVersLaGauche() const;

    /*!
    *  \brief Se deplace vers le haut
    *
    *  Methode qui permet de savoir si la balle se deplace vers le haut
    *  dans le terrain
    *
    *  \return true si la balle se déplace vers le haut,
    *   false sinon
    */
    bool seDeplaceVersLeHaut() const;

    /*!
    *  \brief Se deplace vers le bas
    *
    *  Methode qui permet de savoir si la balle se deplace vers le bas
    *  dans le terrain
    *
    *  \return true si la balle se déplace vers le bas,
    *   false sinon
    */
    bool seDeplaceVersLeBas() const;

    static const int CONTACT_VERTICAL; /*!< Nombre de contact verticale avec la balle (mur verticale du terrain). */
    static const int CONTACT_HORIZONTAL; /*!< Nombre de contact horizontale avec la balle (mur horizontale du terrain). */

private :

    point d_centre; /*!< Objet de la classe point (centre de la balle) . */
    vecteur d_vitesse; /*!< Objet de la classe vecteur (vitesse de la balle). */
    int d_radius; /*!< Entier correspondant au rayon de la balle). */

};

#endif // BALLE_H
