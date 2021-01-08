#include"doctest.h"
#include"point.h"
#include"surfaceRebondissante.h"

TEST_CASE("Les deplacements du point fonctionnent correctement")
{

    SUBCASE("fonction \"Deplace en\" fonctionne bien")
    {
        point pt{12,4.5};
        pt.deplaceEn(-5.5, 10);
        REQUIRE_EQ(pt, point{-5.5, 10});
    }
    SUBCASE("fonction \"deplace de\" fonctionne bien")
    {
        point pt{-5.5, 10};
        pt.deplaceDe(1.1,-4.2);
        REQUIRE_EQ(pt, point{-4.4, 5.8});
    }
}

TEST_CASE("Les fonctions vérifiant la position relative du point fonctionnent correctement")
{
    SUBCASE("estEnDessousDe fonctionne correctement")
    {
        point p1{10, 20};
        point p2{20, 20};
        point p3{10, 30};
        REQUIRE_FALSE(p1.estEnDessousDe(p2));
        REQUIRE_FALSE(p1.estEnDessousDe(p3));
        REQUIRE(p3.estEnDessousDe(p1));
    }
    SUBCASE("estAuDessusDe fonctionne correctement")
    {
        point p1{10, 20};
        point p2{20, 20};
        point p3{10, 30};
        REQUIRE_FALSE(p1.estAuDessusDe(p2));
        REQUIRE(p1.estAuDessusDe(p3));
        REQUIRE_FALSE(p3.estAuDessusDe(p1));
    }
    SUBCASE("estAGaucheDe fonctionne correctement")
    {
        point p1{10, 20};
        point p2{20, 20};
        point p3{10, 30};
        REQUIRE(p1.estAGaucheDe(p2));
        REQUIRE_FALSE(p1.estAGaucheDe(p3));
        REQUIRE_FALSE(p3.estAGaucheDe(p1));
    }
    SUBCASE("estADroiteDe fonctionne correctement")
    {
        point p1{10, 20};
        point p2{20, 20};
        point p3{10, 30};
        REQUIRE_FALSE(p1.estADroiteDe(p2));
        REQUIRE_FALSE(p1.estADroiteDe(p3));
        REQUIRE_FALSE(p3.estADroiteDe(p1));
    }

    SUBCASE("estDans fonctionne correctement")
    {
        point p1{10, 20};
        point p2{20, 30};
        point p3{10, 30};
        point p4{15, 25};
        surfaceRebondissante *surf;
        surfaceRebondissante sr {p1,p2};
        surf = &sr;
        REQUIRE_FALSE(p1.estDans(surf));
        REQUIRE_FALSE(p2.estDans(surf));
        REQUIRE_FALSE(p3.estDans(surf));
        REQUIRE(p4.estDans(surf));
    }

}
