#include <stdio.h>
#include <iostream>
#include "classe/Epice.cpp"
using namespace std;

int main()
{
    Epice myEpice = Epice(8, "Cardamome", "Graines", 10.0, 60.0, "Épices");

    myEpice.afficher();

    system("pause"); //! REMOVE LATER
    return 0;
}