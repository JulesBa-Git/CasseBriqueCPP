#include"doctest.h"
#include"jeu.h"

void mainTest()
{
    jeu j{"Terrain1.txt"};

    opengraphsize(800,800);

    j.run();

    closegraph();
}

TEST_CASE("Test du terrain"){
    SUBCASE("Affichage et run d'un terrain")
    {
        mainTest();
    }
}
