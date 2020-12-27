#include "graphics.h"
#include "point.h"

#ifndef SURFACEREBONDISSANTE_H
#define SURFACEREBONDISSANTE_H
class balle;
// -classe abstraite représentant les surface rebondissantes (mur, palet, briques) qui vont tous devoir d'afficher et pouvoir faire rebondir la balle
//l'idée de faireRebondir est de pouvoir tester si la balle est en collision avec une surface rebondissante et en fonction de quelle surface rebondissante, on va pouvoir faire rebondir la balle
// -toutes les surfaces rebondissantes seront rectangulaires on peut peut etre faire un constructeur commun ?

class surfaceRebondissante{
public :
    virtual ~surfaceRebondissante();
    virtual void afficher() const =0;
    virtual void faitRebonndir(balle& b) =0;
};
#endif // SURFACEREBONDISSANTE_H
