#include <iostream>
#include "mur.h"
#include "balle.h"
#include "palet.h"
#include <windows.h>
using namespace std;

int main()
{
    opengraphsize(800,800);
    palet test({400,400},{500,425});
    test.afficher();
    while(true)
    {
        cleardevice();
        test.afficher();
        test.deplacePalet();
        Sleep(20);
    }
    closegraph();
    return 0;
}
