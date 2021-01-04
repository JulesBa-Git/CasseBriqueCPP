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
        Constructeur d'un jeu qui construit et gère un terrain à partir d'un nom de terrain
    */
    jeu(const std::string& nomFichierTerrain);

    /**
        Methode qui gère l'evenementiel du jeu (while)
    */
    void run();

    /**
        Méthode d'affichage d'un jeu
    */
    void afficher();

private :

    ///Terrain utilisé par le jeu
    terrain d_terrain;

    ///Boolean utilisé pour mettre fin à la partie
    bool d_GameOver;
};
#endif // JEU_H
