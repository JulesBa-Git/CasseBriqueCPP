#include "graphics.h"
#include "point.h"
#include "balle.h"

#ifndef SURFACEREBONDISSANTE_H
#define SURFACEREBONDISSANTE_H
class balle;
// -classe abstraite représentant les surface rebondissantes (mur, palet, briques) qui vont tous devoir d'afficher et pouvoir faire rebondir la balle
//l'idée de faireRebondir est de pouvoir tester si la balle est en collision avec une surface rebondissante et en fonction de quelle surface rebondissante, on va pouvoir faire rebondir la balle
// -toutes les surfaces rebondissantes seront rectangulaires on peut peut etre faire un constructeur commun ?

class surfaceRebondissante{
public :
    virtual ~surfaceRebondissante();
    surfaceRebondissante(const point &hautGauche, const point &basDroit);
    virtual void afficher() const;
    virtual void faitRebondir(balle& b,int arriveeDeLaBalle) =0;
    double xPointHautGauche() const;
    double yPointHautGauche() const;
    double xPointBasDroit() const;
    double yPointBasDroit() const;

    //acceder aux points
    point pointHautGauche() const;
    point pointBasDroit() const;

protected :
    point d_pointHautGauche;
    point d_pointBasDroit;

};
#endif // SURFACEREBONDISSANTE_H
