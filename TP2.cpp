#include <iostream>
#include "header/Epice.h"
#include "header/Fournisseur.h" // Décommentez cette ligne pour inclure Fournisseur

using namespace std;

int main()
{
    // Créer une instance d'Epice
    Epice myEpice;

    // Créer une instance de Fournisseur
    Fournisseur myFournisseur(8, "Noir", "Pierre", "pierre.noir@email.com", "7788990011");

    // Ajouter le fournisseur à l'épice
    myEpice.ajouterFournisseur(&myFournisseur);

    // Afficher les informations de l'épice et de ses fournisseurs
    myEpice.afficher();

    system("Pause");
    return 0;
}
