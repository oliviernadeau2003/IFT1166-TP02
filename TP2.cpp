#include <iostream>

#include "header/Epice.h"
#include "header/Fournisseur.h"
#include "header/DescripteurListeEpices.h"
#include "header/DescripteurListeFournisseurs.h"

using namespace std;

int main()
{
    // Création de quelques fournisseurs
    Fournisseur *f1 = new Fournisseur(1, "Dupont", "Jean", "jean.dupont@example.com", "1234567890");
    Fournisseur *f2 = new Fournisseur(2, "Martin", "Sophie", "sophie.martin@example.com", "0987654321");
    Fournisseur *f3 = new Fournisseur(3, "Durand", "Alice", "alice.durand@example.com", "5678901234");

    // Création de la liste
    DescripteurListeFournisseurs liste;

    // Ajouter des fournisseurs
    liste.ajouterFournisseur(f1);
    liste.ajouterFournisseur(f2);
    liste.ajouterFournisseur(f3);

    // Afficher la liste
    liste.afficherListe();

    // Afficher la liste après suppression
    cout << "\nListe après suppression :" << endl;
    liste.afficherListe();

    // Vérifier la liste vide
    cout << "\nListe après suppression complète :" << endl;
    liste.afficherListe();

    // Créer quelques épices
    Epice *epice1 = new Epice(1, "Cumin", "Poudre", 10.5, 100, "Épice sèche");
    Epice *epice2 = new Epice(2, "Safran", "Fils", 1500, 50, "Épice rare");

    // Créer le descripteur de liste
    DescripteurListeEpices listeEpices;

    // Ajouter les épices
    listeEpices.ajouterEpice(epice1);
    epice1->ajouterFournisseur(f1);
    epice1->ajouterFournisseur(f2);

    listeEpices.ajouterEpice(epice2);
    epice2->ajouterFournisseur(f3);

    // Afficher la liste des épices
    cout << "Liste des épices :" << endl;
    listeEpices.afficherListe();

    // Supprimer une épice
    listeEpices.supprimerEpice(epice1);

    // Afficher la liste après suppression
    cout << "\nListe après suppression :" << endl;
    listeEpices.afficherListe();

    cout << "\n";
    system("Pause");
    return 0;
}
