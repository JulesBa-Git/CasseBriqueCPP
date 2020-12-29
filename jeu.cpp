#include "jeu.h"

jeu::jeu(const std::string& nomFichierTerrain) : d_terrain{nomFichierTerrain}, d_GameOver{false}
{}

void jeu::run()
{
    d_terrain.afficherToutTerrain();
    while(!d_GameOver)
    {


        if (d_terrain.collision())
        {
            cleardevice();
            d_terrain.afficherToutTerrain();
        }
        else{
            d_terrain.afficherBalle();
            d_terrain.afficherPalet();
        }
        d_terrain.deplacerPalet();
        d_GameOver = d_terrain.plusDeBrique() || d_terrain.balleSousTerrain();
        Sleep(20);
    }
}

void jeu::afficher()
{
    d_terrain.afficherToutTerrain();
}
