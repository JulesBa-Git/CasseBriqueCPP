#include <iostream>
#include "mur.h"
#include "balle.h"
#include "palet.h"
#include "surfaceRebondissante.h"
#include <vector>
#include <memory>
#include "point.h"
#include "vecteur.h"
#include <windows.h>
using namespace std;

int main()
{
    std::vector<std::unique_ptr<surfaceRebondissante>> surfaceTerrain{};
    surfaceTerrain.push_back(std::make_unique<mur>(point{100,100},point{110,300}));
    surfaceTerrain.push_back(std::make_unique<mur>(point{110,100},point{310,110}));
    surfaceTerrain.push_back(std::make_unique<mur>(point{310,100},point{320,300}));
    surfaceTerrain.push_back(std::make_unique<mur>(point{110,290},point{310,300}));

    opengraphsize(800,800);

    balle balle{point{240,190},vecteur{2.0,1.0},10};
    int temps =0;
    while(temps < 200)
    {

        cleardevice();
        balle.afficher();
        balle.bouger(1);
        for(int i = 0; i< surfaceTerrain.size(); ++i)
        {
            surfaceTerrain[i]->afficher();
            balle.rentreDans(surfaceTerrain[i].get());
        }



        ++temps;
        Sleep(20);

    }
    closegraph();
    return 0;
}
