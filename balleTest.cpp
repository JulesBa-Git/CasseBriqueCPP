#include"doctest.h"
#include"balle.h"
#include"surfaceRebondissante.h"

TEST_CASE("Les mouvements de la balle fonctionnent correctement")
{
    SUBCASE("Mise a jour position fonctionne correctement")
    {
        balle bal{point{0.0,0.0}, vecteur{}, 1};
        bal.MiseAjourPosition(1.0, 1.0);
        REQUIRE_EQ(bal.milieu(), point{1.0,1.0});
    }
    SUBCASE("bouger fonctionne correctement")
    {
        balle bal{point{0.0,0.0}, vecteur{1,1}, 1};
        bal.bouger(5);
        REQUIRE_EQ(bal.milieu(), point(5,5));
    }
}

TEST_CASE("rebond fonctionne correctement")
{
    SUBCASE("rebond sur le bas de la balle fonctionne correctement")
    {
        SUBCASE("quand le bas de la balle touche le haut d'une surface")
        {

        }
        SUBCASE("quand le bas de la balle touche le cote d'une surface")
        {

        }
    }
    SUBCASE("rebond sur le haut de la balle fonctionne correctement")
    {
        SUBCASE("quand le haut de la balle touche le bas d'une surface")
        {

        }
        SUBCASE("quand le haut de la balle touche le cote d'une surface")
        {

        }
    }
    SUBCASE("rebond sur la gauche de la balle fonctionne correctement")
    {
        SUBCASE("quand la gauche de la balle touche le cote droit d'une surface")
        {

        }
        SUBCASE("quand la gauche de la balle touche le haut ou le bas d'une surface")
        {

        }
    }
    SUBCASE("rebond sur la droite de la balle fonctionne correctement")
    {
        SUBCASE("quand la droite de la balle touche le cote gauche d'une surface")
        {

        }
        SUBCASE("quand la droite de la balle touche le haut ou le bas d'une surface")
        {

        }
    }
}
