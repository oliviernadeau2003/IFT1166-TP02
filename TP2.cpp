#include <stdio.h>
#include <iostream>

#include "classe/Epice.cpp"
#include "classe/Fournisseur.cpp"

using namespace std;

int main()
{
    Epice myEpice = Epice(8, "Cardamome", "Graines", 10.0, 60.0, "Épices");
    Fournisseur myFournisseur = Fournisseur(8, "Noir", "Pierre", "pierre.noir@email.com", "7788990011");

    myEpice.afficher();
    myFournisseur.afficher();

    system("pause"); //! REMOVE LATER
    return 0;
}