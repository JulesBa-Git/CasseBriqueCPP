#ifndef BALLE_H
#define BALLE_H
#include "point.h"
#include "vecteur.h"
#include "graphics.h"

class balle{
public :
    //constructeur de balle, ici une balle est construite avec un point qui est son centre, son vecteur vitesse et son rayon
    balle(const point& centre,const vecteur& vitesse, int rayon);

    //méthode permettant l'acces au données privés
    point milieu() const;
    int rayon() const;
    vecteur vitesse() const;

    //permet de deplacer la balle par rapport au temps grace a son vecteur vitesse (dt constante a definir ?)
    void bouger(double dt);

    //permet de deplacer la bale de maniere absolue (quand la balle va trop loin dans un mur p.ex)
    void deplaceCentre(double x, double y);

    //permet de mofifier le vecteur vitesse de la balle
    void changeVitesse(const vecteur& vitesse);

    //permet d'afficher la balle
    void afficher() const;

private :
    point d_centre;
    vecteur d_vitesse;
    int d_radius;

};

#endif // BALLE_H
