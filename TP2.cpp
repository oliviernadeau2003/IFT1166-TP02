#include <iostream>

#include "header/Epice.h"
#include "classe/Utils.cpp" // namespace
#include "header/Fournisseur.h"
#include "header/DescripteurListeEpices.h"
#include "header/DescripteurListeFournisseurs.h"

using namespace std;

int main()
{
    system("chcp 65001 > NUL"); // Set l'encodeur a UTF-8 pour lire et écrire des charactère spéciaux (... > NUL permet de 'suprimer' l'output")
    const string PATHFICHIEREPICE = "./data/epices.txt";
    const string PATHFICHIERFOURNISSEUR = "./data/fournisseurs.txt";

    // Initialisation de la liste
    DescripteurListeEpices listeEpices;
    DescripteurListeFournisseurs listeFournisseurs;

    Utils::chargerFichierFournisseur(PATHFICHIERFOURNISSEUR, listeFournisseurs);
    Utils::chargerFichierEpices(PATHFICHIEREPICE, listeEpices, listeFournisseurs);

    cout << "Données chargées avec succès.\n";
    listeEpices.afficherListe();
    listeFournisseurs.afficherListe();

    // ---
    // ---
    // ---
    // ---
    // ---
    cout << "\n";
    system("Pause");
    return 0;
}
