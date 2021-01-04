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
    point milieu() const;
    int rayon() const;
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


private :
    point d_centre;
    vecteur d_vitesse;
    int d_radius;

};

#endif // BALLE_H
