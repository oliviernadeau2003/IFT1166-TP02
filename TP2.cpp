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

    // Initialisation de la liste
    DescripteurListeEpices listeEpices;
    DescripteurListeFournisseurs listeFournisseurs;

    Utils::chargerFichierFournisseur(PATHFICHIERFOURNISSEUR, listeFournisseurs);

    Utils::chargerFichierEpices(PATHFICHIEREPICE, listeEpices, listeFournisseurs);

    // cout << "\n";
    // listeFournisseurs.afficherListe();
    // listeEpices.afficherListe();

    // Epice *newEpice = new Epice(listeEpices.getProchainIdDisponible(), "Cumin2", "Graines", 6.8, 200.0, "Épices");
    // listeEpices.ajouterEpice(newEpice);

    // Epice *epice = listeEpices.getEpiceByName("Romarin");
    // epice->afficher();

    // 5;Ivanov;Dmitry;dmitry.ivanov@email.com;3344556677
    // Fournisseur *newFournisseur = new Fournisseur(listeFournisseurs.getProchainIdDisponible(), "Ivanov33", "Dmitry", "dmitry.ivanov@email.com", "3344556677");
    // listeFournisseurs.ajouterFournisseur(newFournisseur);

    // Fournisseur *fournisseur = listeFournisseurs.getFournisseurById(4);
    // fournisseur->afficher();

    // fournisseur = listeFournisseurs.getFournisseurById(11);
    // fournisseur->afficher();

    // Epice *epice = listeEpices.getEpiceByName("Romarin");
    // epice->supprimerFournisseur(2);

    // epice->afficher();

    // epice = listeEpices.getEpiceById(1);
    // epice->afficherFournisseurs();

    // Epice *epice = listeEpices.getEpiceByCategory("Herbes");
    // epice->afficher();

    // listeEpices.afficherFournisseursParEpice("Curcuma");
    // listeEpices.afficherFournisseursParEpice(13);

    // listeEpices.afficherEpicesParFournisseur(1);
    // listeEpices.afficherEpicesParFournisseur(11);

    system("Pause");
    return 0;
}
