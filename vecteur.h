#include <iostream>

#ifndef VECTEUR_H
#define VECTEUR_H

//classe repr�sentant un vecteur deux dimensions qui va nous servir a representer la vitesse de la balle


class vecteur {
public:
//constructeur :
//par default initialise un vecteur a (0,0)
    vecteur();
//avec ses deux composantes (x,y)
    vecteur(double x,double y);

//fonctions renvoyant les composantes x et y du vecteur
    double x() const;
    double y() const;

//proc�dure permettant de modifier le vecteur
    void devient(double x, double y);

//op�rateur unaire permettant d'inverser le vecteur
    vecteur  operator-() const;

//op�rateur permettant de multiplier un vecteur par un r�el, nous servira a modifier la vitesse en fonction d'un pourcentage
    vecteur& operator*=(double reel);
    vecteur  operator*(double reel) const;

//proc�dures permettant de tester les constructeur u vecteur
    void print(std::ostream& ost) const;
    void read(std::istream& ist);
private:
    double d_x;
    double d_y;
};

//op�rateur permettant de faciliter l'usage de la multiplication entre reel et vecteur pr�sente dans la classe
vecteur operator*(double val, const vecteur& v);

#endif // VECTEUR_H
