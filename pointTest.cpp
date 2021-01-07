#include"doctest.h"
#include"point.h"

TEST_CASE("Les deplacements du points fonctionnent correctement")
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
