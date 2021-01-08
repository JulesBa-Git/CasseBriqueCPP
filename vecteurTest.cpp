#include"doctest.h"
#include"vecteur.h"

TEST_CASE("fonctions mathématiques de vecteur fonctionnent correctement")
{
    SUBCASE("operateur * fonctionne correctement")
    {
        vecteur v1{5,5};
        vecteur v2{5.0*v1};
        REQUIRE_EQ(v2.x(), 25);
        REQUIRE_EQ(v2.x(), 25);
    }
    SUBCASE("operateur *= fonctionne correctement")
    {
        vecteur v1{5,5};
        v1 *= 4;
        REQUIRE_EQ(v1.x(), 20);
        REQUIRE_EQ(v1.y(), 20);
    }
    SUBCASE("operateur - fonctionne correctement")
    {
        vecteur v1{5,5};
        vecteur v2{-v1};
        REQUIRE_EQ(v2.x(), -5);
        REQUIRE_EQ(v2.y(), -5);
    }
}
