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

        for(int i=xPointHautGauche+60; i<=largeur+60; i+=60)
            for(int j=yPointHautGauche+60; j<=hauteur-100; j+=30)
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

void terrain::afficherToutTerrain()
{
    for(const auto& mur : d_surfaceMur)
        mur->afficher();

    for(int i = 0; i < d_surfaceBrique.size(); ++i)
    {
        if(d_surfaceBrique[i]->estTouchee())
        {
            supprimeBriqueTouchee(i);
        }
    }
    for(int i = 0; i < d_surfaceBrique.size(); ++i)
    {
        d_surfaceBrique[i]->afficher();
    }

    d_palet->afficher();
    d_balle.bouger(1);
    d_balle.afficher(WHITE);
}

void terrain::afficherBalle()
{
    d_balle.afficher(BLACK);
    d_balle.bouger(1);
    d_balle.afficher(WHITE);
}

/*
void terrain::afficherPalet()
{
    d_palet->afficher();
}
*/

bool terrain::collision()
{
    for(auto& mur : d_surfaceMur)
    {
        if (d_balle.rebonditSur(mur.get()))
        {
            return true;
        }

    }
    for(auto& briques : d_surfaceBrique)
    {
        if (d_balle.rebonditSur(briques.get()))
        {
            return true;
        }
    }
    if (d_balle.rebonditSur(d_palet.get()))
    {
        return true;
    }
    return false;
}

void terrain::deplacementPalet()
{
    d_palet->deplacePalet();
    if (paletADroiteDuTerrain())
    {
        int distanceADeplacer;
        distanceADeplacer = d_palet->xPointBasDroit() - d_surfaceMur.back()->xPointHautGauche();
        d_palet->deplacePalet(-distanceADeplacer);
    }else if (paletAGaucheDuTerrain())
    {
        int distanceADeplacer;
        distanceADeplacer =  d_surfaceMur.front()->xPointBasDroit() - d_palet->xPointHautGauche();
        d_palet->deplacePalet(distanceADeplacer);
    }
}

void terrain::modifierPalet()
{
    d_palet->afficher(BLACK);
    deplacementPalet();
    d_palet->afficher(WHITE);
}

bool terrain::paletAGaucheDuTerrain()
{
    return  d_surfaceMur.front()->xPointBasDroit() > d_palet->xPointHautGauche();
}

bool terrain::paletADroiteDuTerrain()
{
    return d_palet->xPointBasDroit() > d_surfaceMur.back()->xPointHautGauche();
}

void terrain::supprimeBriqueTouchee(int i)
{
    d_surfaceBrique.erase(d_surfaceBrique.begin() + i);
}

bool terrain::plusDeBrique() const
{
    return d_surfaceBrique.empty();
}

bool terrain::balleSousTerrain() const
{
    return (d_balle.milieu().y() > d_palet->yPointBasDroit());
}
