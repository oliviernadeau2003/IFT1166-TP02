#include <iostream>

#include "header/Epice.h"
#include "classe/Utils.cpp" // namespace
#include "header/Fournisseur.h"
#include "header/DescripteurListeEpices.h"
#include "header/DescripteurListeFournisseurs.h"

using namespace std;

int main()
{
    const string PATHFICHIEREPICE = "./data/epices.txt";
    const string PATHFICHIERFOURNISSEUR = "./data/fournisseurs.txt";

    // Création de la liste
    DescripteurListeEpices listeEpices;
    DescripteurListeFournisseurs listeFournisseurs;

    Utils::chargerFichierFournisseur(PATHFICHIERFOURNISSEUR, listeFournisseurs);
    listeFournisseurs.afficherListe();

    cout << "\n";
    Utils::chargerFichierEpices(PATHFICHIEREPICE, listeEpices, listeFournisseurs);
    listeEpices.afficherListe();

    cout << "\n";
    system("Pause");
    return 0;
}
