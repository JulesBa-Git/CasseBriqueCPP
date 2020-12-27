#include <iostream>
#include <vector>
#include "surfaceRebondissante.h"
#include "balle.h"
#ifndef TERRAIN_H
#define TERRAIN_H

//classe representant le terrain qui va contenir tous les elements necessaire au deroulement du jeu c'est a dire surface rebondissantes et la balle (on pourrait rajouter un systeme de vies)
class terrain{
public :
    //constructeur de terrain a partir d'un fichier car on veut pouvoir creer un terrain a partir d'un fichier puis le sauvegarder
    terrain(const std::string& nomFichierTerrain);

    //afficher le terrain
    void afficher() const;

    //sauvegarder le terrain
    void sauver();

private :
    std::vector<surfaceRebondissante> d_surfaceRebondissantes;
    balle d_balle;
    std::string NomFichierTerrain;



};

#endif