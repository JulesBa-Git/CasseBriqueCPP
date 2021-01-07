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

/*! \class jeu
 *  \brief classe permettant de lancer le jeu
 *
 *  La classe va permettre au jeu de se derouler grace aux terrain qui sera composer des differents elements
 */

class jeu{
public :

    /*!
    *  \brief Constructeur
    *
    *  Constructeur de la classe jeu
    *
    *  \param nomFichierTerrain : fichier contenant les parametres du terrain
    */
    jeu(const std::string& nomFichierTerrain);

    /*!
    *  \brief Lancement du jeu
    *
    *  Methode qui permet le lancement du jeu
    */
    void run();

    /*!
    *  \brief Affiche le terrain
    *
    *  Methode qui permet l'affichage du terrain au lancement du jeu grace a la classe "terrain"

    */
    void afficher();

private :


    ///Terrain utilisé par le jeu
    terrain d_terrain;

    ///Boolean utilisé pour mettre fin à la partie
    bool d_GameOver;

    terrain d_terrain; /*!< Objet de la classe terrain. */
    bool d_GameOver; /*!< Booleen permettant de savoir si le jeu est fini ou non. */

};
#endif // JEU_H
