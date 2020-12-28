#include <iostream>
#include "mur.h"
#include "balle.h"
#include "palet.h"
#include "surfaceRebondissante.h"
#include <vector>
#include <memory>
#include "point.h"
#include <windows.h>
using namespace std;

int main()
{
    std::vector<std::unique_ptr<surfaceRebondissante>> surfaceTerrain{};
    surfaceTerrain.push_back(std::make_unique<mur>(point{100,100},point{110,300}));
    surfaceTerrain.push_back(std::make_unique<mur>(point{110,100},point{310,110}));
    surfaceTerrain.push_back(std::make_unique<mur>(point{310,100},point{320,300}));

    opengraphsize(800,800);
    palet palet({210,290},{235,290});
    palet.afficher();
    while(true)
    {
        cleardevice();
        for(int i = 0; i< surfaceTerrain.size(); ++i)
        {
            surfaceTerrain[i]->afficher();
        }
        palet.afficher();
        palet.deplacePalet();

        Sleep(20);
    }
    closegraph();
    return 0;
}
