#include "terrain.h"
#include <windows.h>
#ifndef JEU_H
#define JEU_H

//class qui va permettre au jeu de se derouler grace aux terrain qui sera composer des differents elements
class jeu{
public :
    jeu(const std::string& nomFichierTerrain);
    void run();
    void afficher();

private :
    terrain d_terrain;
    bool d_GameOver;
};
#endif // JEU_H
