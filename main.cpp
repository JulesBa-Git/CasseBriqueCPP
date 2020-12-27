#include <iostream>
#include "mur.h"
#include "balle.h"

using namespace std;

int main()
{
    opengraphsize(800,800);
    balle test({400,400},{},10);
    test.afficher();
    getch();
    closegraph();
    return 0;
}
