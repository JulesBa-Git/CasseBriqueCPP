#include "jeu.h"

jeu::jeu(const std::string& nomFichierTerrain) : d_terrain{nomFichierTerrain}, d_GameOver{false}
{}

void jeu::run()
{
    while(!d_GameOver)
    {
        cleardevice();
        d_terrain.afficher();
        d_terrain.collision();
        d_terrain.deplacerPalet();
        d_GameOver = d_terrain.plusDeBrique();
        Sleep(20);
    }
}

void jeu::afficher()
{
    d_terrain.afficher();
}
