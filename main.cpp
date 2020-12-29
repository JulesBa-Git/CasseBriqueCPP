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
using namespace std;

int main()
{
    /*std::vector<std::unique_ptr<surfaceRebondissante>> surfaceTerrain{};
    surfaceTerrain.push_back(std::make_unique<mur>(point{100,100},point{110,300}));
    surfaceTerrain.push_back(std::make_unique<mur>(point{110,100},point{310,110}));
    surfaceTerrain.push_back(std::make_unique<mur>(point{310,100},point{320,300}));
    surfaceTerrain.push_back(std::make_unique<brique>(point{240,240},point{270,270}));
    surfaceTerrain.push_back(std::make_unique<mur>(point{110,290},point{310,300}));*/
    //terrain terrin{"Terrain1.txt"};
    jeu je{"Terrain1.txt"};
    opengraphsize(800,800);
    /*std::unique_ptr<palet> paletTerrain{std::make_unique<palet>(point{210,290},point{250,295})};
    balle balle{point{240,190},vecteur{3.0,1.5},10};*/
    //int temps =0;
    je.run();
    /*while(temps < 500)
    {

        cleardevice();*/
        /*balle.afficher();
        balle.bouger(1);
        paletTerrain->afficher();*/
        //paletTerrain->deplacePalet();
        //balle.rentreDans(paletTerrain.get());
        /*for(int i = 0; i< surfaceTerrain.size(); ++i)
        {
            surfaceTerrain[i]->afficher();
            balle.rentreDans(surfaceTerrain[i].get());
        }*/
        /*terrin.afficher();
        terrin.collision();
        terrin.deplacerPalet();*/

        //++temps;
        //Sleep(20);

    //}
    closegraph();
    return 0;
}
