#include <iostream>
#include "mur.h"
#include "balle.h"
#include "palet.h"
#include "brique.h"
#include "surfaceRebondissante.h"
#include <vector>
#include <memory>
#include "jeu.h"
#include "point.h"
#include "vecteur.h"
#include "terrain.h"

#include <windows.h>

//getch(); Le supprime pas jpp d'aller le chercher dans les td

using namespace std;

int main()
{

    jeu j{"Terrain1.txt"};

    opengraphsize(800,800);

    j.run();
    //getch();

    closegraph();

    return 0;
}
