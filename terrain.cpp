#include "terrain.h"

terrain::terrain(const std::string& nomFichierTerrain):
    d_surfaceMur{}, d_surfaceBrique{}, d_palet{std::make_unique<palet>(point{0.0,0.0},point{0.0,0.0})},
    d_balle{point{0.0,0.0},vecteur{0.0,0.0},0}, d_nomFichierTerrain{nomFichierTerrain}
    {
        std::ifstream ist(d_nomFichierTerrain);

        if(!ist)
            std::cout<<"Impossible d'ouvrir "<<d_nomFichierTerrain<<std::endl;

        //Murs

        double xPointHautGauche, yPointHautGauche, xPointBasDroit, yPointBasDroit;

        ist>>xPointHautGauche>>yPointHautGauche>>xPointBasDroit>>yPointBasDroit;

        d_surfaceMur.push_back(std::make_unique<mur>(point{xPointHautGauche,yPointHautGauche},point{xPointHautGauche+10,yPointBasDroit}));
        d_surfaceMur.push_back(std::make_unique<mur>(point{xPointHautGauche+10,yPointHautGauche},point{xPointBasDroit-10,yPointHautGauche+10}));
        d_surfaceMur.push_back(std::make_unique<mur>(point{xPointBasDroit-10,yPointHautGauche},point{xPointBasDroit,yPointBasDroit}));

        //Palet

        d_palet = std::make_unique<palet>(point{(xPointBasDroit/2)-20, yPointBasDroit-5}, point{(xPointBasDroit/2)+20, yPointBasDroit});

        //Briques test avec plusieurs briques auto

        int hauteur = yPointBasDroit-yPointHautGauche-10;
        int largeur = xPointBasDroit-xPointHautGauche-10;

        /*hauteur-=100;
        largeur-=100;*/

        for(int i=xPointHautGauche+60; i<=largeur+60; i+=20)
            for(int j=yPointHautGauche+60; j<=hauteur-100; j+=10)
                d_surfaceBrique.push_back(std::make_unique<brique>(point{i,j},point{i+20,j+10}));



        /*for(int i=0; i<nombreDeBrique; ++i)
        {
            ist>>xPointHautGauche>>yPointHautGauche>>xPointBasDroit>>yPointBasDroit;
            d_surfaceBrique.push_back(std::make_unique<brique>(point{xPointHautGauche,yPointHautGauche},point{xPointBasDroit,yPointBasDroit}));
        }*/

        //Balle

        double xCentre, yCentre, xVitesse, yVitesse, radius;

        ist>>xCentre>>yCentre>>xVitesse>>yVitesse>>radius;
        d_balle = {point{xCentre, yCentre}, vecteur{xVitesse, yVitesse}, radius};
        ist.close();


    }

balle terrain::balleDuTerrain() const
{
    return d_balle;
}

const palet* terrain::paletDuTerrain() const
{
    return d_palet.get();
}

void terrain::afficher()
{
    for(const auto& mur : d_surfaceMur)
        mur->afficher();

    for(int i = 0; i < d_surfaceBrique.size(); ++i)
    {
        if(d_surfaceBrique[i]->estTouchee())
        {
            supprimeBriqueTouchee(i);
        }
        else
        {
            d_surfaceBrique[i]->afficher();
        }
    }


    d_palet->afficher();
    d_balle.bouger(1);
    d_balle.afficher();
}

void terrain::collision()
{
    for(auto& mur : d_surfaceMur)
    {
        d_balle.rentreDans(mur.get());
    }
    for(auto& briques : d_surfaceBrique)
    {
        d_balle.rentreDans(briques.get());
    }
    d_balle.rentreDans(d_palet.get());
}

void terrain::deplacerPalet()
{
    d_palet->deplacePalet();
}


void terrain::supprimeBriqueTouchee(int i)
{
    d_surfaceBrique.erase(d_surfaceBrique.begin() + i);
}

bool terrain::plusDeBrique() const
{
    return d_surfaceBrique.empty();
}


