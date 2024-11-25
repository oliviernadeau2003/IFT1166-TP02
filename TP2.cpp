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

    cout << "Données chargées avec succès.\n\n";
    // listeEpices.afficherListe();
    // listeFournisseurs.afficherListe();

    // --- Opération sur la liste doublement chainée

    // Épice
    Epice *nouvelleEpice = new Epice(25, "Gingembre", "Racine", 5.0, 30.0, "Épices fraîches");
    listeEpices.ajouterEpice(nouvelleEpice);
    nouvelleEpice->ajouterFournisseur(listeFournisseurs.getFournisseurById(2));
    nouvelleEpice->ajouterFournisseur(listeFournisseurs.getFournisseurById(6));
    cout << "Nouvelle épice ajouté avec succès.\n";
    nouvelleEpice->afficher();

    cout << endl;
    listeEpices.supprimerEpice(1); // Suprimer epice par Id

    cout << endl;
    Epice *epiceId2 = listeEpices.getEpiceById(2); // Recherche par Id
    cout << "Épice avec l'id 2 : \n";
    epiceId2->afficher();

    Epice *epiceId88 = listeEpices.getEpiceById(88);
    if (epiceId88 != nullptr)
        epiceId88->afficher();

    cout << endl;
    Epice *epiceNomMenthe = listeEpices.getEpiceByName("Menthe"); // Recherche par Nom
    cout << "Épice avec le nom Menthe : \n";
    epiceNomMenthe->afficher();

    Epice *epiceNomVanille76 = listeEpices.getEpiceByName("Vanille76");
    if (epiceNomVanille76 != nullptr)
        epiceNomVanille76->afficher();

    // listeEpices.afficherListe(); // Afficher toutes les épices

    // Fournisseur
    cout << endl;
    Fournisseur *nouveauFournisseur = new Fournisseur(44, "Moreau", "Claire", "claire.moreau@example.com", "1122334455");
    listeFournisseurs.ajouterFournisseur(nouveauFournisseur);
    epiceNomMenthe->ajouterFournisseur(nouveauFournisseur);
    cout << "Nouveau fournisseur ajouté avec succès.\n";
    epiceNomMenthe->afficher();

    cout << endl;
    epiceNomMenthe->supprimerFournisseur(9);
    epiceNomMenthe->supprimerFournisseur(3);
    epiceNomMenthe->supprimerFournisseur(nullptr);

    cout << endl;
    nouvelleEpice->afficherFournisseurs();

    // --- Requêtes sur les données
    cout << endl;
    listeEpices.afficherFournisseursParEpice(3);
    cout << endl;
    listeEpices.afficherFournisseursParEpice("Piment");

    cout << endl;
    listeEpices.afficherFournisseursParEpice(102);
    listeEpices.afficherFournisseursParEpice("Piment99");

    cout << endl;
    listeEpices.afficherEpicesParFournisseur(4);

    cout << endl;
    listeEpices.afficherEpicesParFournisseur(902);

    cout << endl;
    Epice *epiceCategorieCondiments = listeEpices.getEpiceByCategory("Condiments");
    cout << "Épice avec comme catégorie Condiments : \n";
    epiceCategorieCondiments->afficher();

    Epice *epiceCategorieCondiments006 = listeEpices.getEpiceByCategory("Condiments006");
    if (epiceCategorieCondiments006 != nullptr)
        epiceCategorieCondiments006->afficher();
    cout << endl;

    // ---
    system("\nPause");
    return 0;
}
