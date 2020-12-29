#include <iostream>
#include <vector>
#include "surfaceRebondissante.h"
#include "balle.h"
#include "palet.h"
#include "mur.h"
#include "brique.h"
#include <memory>
#include <fstream>

#ifndef TERRAIN_H
#define TERRAIN_H

//classe representant le terrain qui va contenir tous les elements necessaire au deroulement du jeu c'est a dire surface rebondissantes et la balle (on pourrait rajouter un systeme de vies)
class terrain{
public :
    //constructeur de terrain a partir d'un fichier car on veut pouvoir creer un terrain a partir d'un fichier puis le sauvegarder
    terrain(const std::string& nomFichierTerrain);

    //renvoie la balle du terrain au jeu et le palet
    balle balleDuTerrain() const;
    const palet* paletDuTerrain() const;

    //afficher le terrain
    void afficherToutTerrain();
    void afficherBalle();

    //void afficherPalet(); plus utilisé

    bool collision();
    void deplacementPalet();

    void supprimeBriqueTouchee(int i);

    bool plusDeBrique() const;
    bool balleSousTerrain() const;

    bool paletAGaucheDuTerrain();
    bool paletADroiteDuTerrain();

    void modifierPalet();

    //sauvegarder le terrain
    void sauver() const;

private :
    std::vector<std::unique_ptr<mur>> d_surfaceMur;
    std::vector<std::unique_ptr<brique>> d_surfaceBrique;
    std::unique_ptr<palet> d_palet;
    balle d_balle;
    std::string d_nomFichierTerrain;



};

#endif
