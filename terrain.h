#include <iostream>
#include <vector>
#include <memory>
#include <fstream>

#include "surfaceRebondissante.h"
#include "balle.h"
#include "palet.h"
#include "mur.h"
#include "brique.h"


#ifndef TERRAIN_H
#define TERRAIN_H


/**
    classe representant le terrain qui va contenir tous les elements necessaire au deroulement du jeu c'est a dire surface rebondissantes et la balle (on pourrait rajouter un systeme de vies)
*/
class terrain{
public :
    ///constructeur de terrain a partir d'un fichier car on veut pouvoir creer un terrain a partir d'un fichier puis le sauvegarder
    terrain(const std::string& nomFichierTerrain);

    ///renvoie la balle du terrain au jeu et le palet

/*! \class terrain
 *  \brief classe representant le terrain du jeu
 *
 *  La classe gere l'initialisation du terrain qui lui va contenir tous les elements necessaire
 *  au deroulement du jeu, c'est a dire, surfaces rebondissantes et la balle (on pourrait rajouter un systeme de vies)
 */

class terrain{
public :

    ///constructeur de terrain a partir d'un fichier car on veut pouvoir creer un terrain a partir d'un fichier puis le sauvegarder
    /*!
    *  \brief Constructeur
    *
    *  Constructeur de la classe terrain
    *  On veut pouvoir creer un terrain a partir d'un fichier puis le sauvegarder
    *
    *  \param nomFichierTerrain : fichier contenant les parametres du terrain
    */
    terrain(const std::string& nomFichierTerrain);

    /*!
    *  \brief Renvoie la balle
    *
    *  Methode qui permet de renvoyer la balle du terrain au jeu
    *
    *  \return la balle du terrain
    */

    balle balleDuTerrain() const;

    /*!
    *  \brief Renvoie le palet
    *
    *  Methode qui permet de renvoyer un pointeur sur le palet du terrain au jeu
    *
    *  \return un pointeur sur le palet
    */
    const palet* paletDuTerrain() const;


    ///afficher le terrain
    void afficherToutTerrain();
    void afficherBalle();


    bool collision();
    void deplacementPalet();

    /*!
    *  \brief Affiche le terrain
    *
    *  Methode qui permet d'afficher tout le terrain (les murs, la balle, le palet, les briques)
    */
    void afficherToutTerrain();


    /*!
    *  \brief Affiche la balle
    *
    *  Methode qui permet d'afficher la balle grace a la classe "balle"
    */
    void afficherBalle();

    /*!
    *  \brief Detection de collisions
    *
    *  Methode qui permet de renvoyer un booleen si un objet est rentre
    *  en collision avec la balle
    *
    *  \return true si la balle rentre en collision avec un objet,
    *   false sinon
    */
    bool collision();

    /*!
    *  \brief Deplace le palet
    *
    *  Methode qui appelle la methode "deplacePalet()" de la classe "palet"
    */
    void deplacementPalet();

    /*!
    *  \brief Supprime une brique touchee
    *
    *  Methode qui permet de supprimer une brique touchee par la balle
    *
    *  \param i : un entier correspondant a
    */
    void supprimeBriqueTouchee(int i);

    /*!
    *  \brief Plus de brique
    *
    *  Methode qui permet de savoir si il reste des briques dans le terrain
    *
    *  \return true si il n'y a plus de briques dans le terrain (le tableau de briques est vide),
    *   false sinon
    */
    bool plusDeBrique() const;
    bool balleSousTerrain() const;

    bool paletAGaucheDuTerrain();
    bool paletADroiteDuTerrain();

    void modifierPalet();


    ///sauvegarder le terrain

    /*!
    *  \brief Balle en dehors su terrain
    *
    *  Methode qui permet de savoir si la balle est sortie du terrain
    *
    *  \return true si la balle est sortie du terrain,
    *   false sinon
    */
    bool balleSousTerrain() const;

    /*!
    *  \brief Palet a gauche du terrain
    *
    *  Methode qui permet de savoir si le palet est a gauche du terrain
    *
    *  \return true si le palet est a gauche du terrain,
    *   false sinon
    */
    bool paletAGaucheDuTerrain();

    /*!
    *  \brief Palet a droite du terrain
    *
    *  Methode qui permet de savoir si le palet est a droite du terrain
    *
    *  \return true si le palet est a droite du terrain,
    *   false sinon
    */
    bool paletADroiteDuTerrain();

    /*!
    *  \brief Modifie le palet
    *
    *  Methode qui permet de modifier le palet grace a la classe "palet".
    *  Elle modifie la couleur du palet et le deplace
    */
    void modifierPalet();

    /*!
    *  \brief Sauvegarde du terrain
    *
    *  Methode qui permet de sauvergarder le terrain
    */

    void sauver() const;

private :

    std::vector<std::unique_ptr<mur>> d_surfaceMur; /*!< Tableau de pointeurs de murs. */
    std::vector<std::unique_ptr<brique>> d_surfaceBrique; /*!< Tableau de pointeurs de briques. */
    std::unique_ptr<palet> d_palet;/*!< Pointeur de palets. */
    balle d_balle; /*!< Objet de la classe balle. */
    std::string d_nomFichierTerrain; /*!< Nom du fichier contenant le terrain. */

};

#endif
