#include "terrain.h"
#include <windows.h>
#ifndef JEU_H
#define JEU_H

/**
    class qui va permettre au jeu de se derouler grace aux terrain qui sera composer des differents elements
*/
class jeu{
public :

    /**
        Constructeur d'un jeu qui construit et g�re un terrain � partir d'un nom de terrain
    */
    jeu(const std::string& nomFichierTerrain);

    /**
        Methode qui g�re l'evenementiel du jeu (while)
    */
    void run();

    /**
        M�thode d'affichage d'un jeu
    */
    void afficher();

private :

    ///Terrain utilis� par le jeu
    terrain d_terrain;

    ///Boolean utilis� pour mettre fin � la partie
    bool d_GameOver;
};
#endif // JEU_H
