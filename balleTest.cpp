#include"doctest.h"
#include"balle.h"

TEST_CASE("Les mouvements de la balle fonctionnent correctement")
{
    balle bal{point{0.0,0.0}, vecteur{}, 1};
    SUBCASE("Mise a jour position fonctionne correctement")
    {
        bal.MiseAjourPosition(1.0, 1.0);
        REQUIRE_EQ(bal.milieu(), point{1.0,1.0});
    }
}
