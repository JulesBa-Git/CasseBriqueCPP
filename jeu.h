#include "terrain.h"
#include <windows.h>
#ifndef JEU_H
#define JEU_H


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


    terrain d_terrain; /*!< Objet de la classe terrain. */
    bool d_GameOver; /*!< Booleen permettant de savoir si le jeu est fini ou non. */

};
#endif // JEU_H
