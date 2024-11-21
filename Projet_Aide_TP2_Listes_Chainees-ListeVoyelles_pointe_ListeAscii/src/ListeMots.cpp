#include "ListeMots.h"
#include "ListeVoyelles.h"
#include <iostream>
#include <cctype>
using namespace std;

ListeMots::ListeMots() : tete(nullptr) {}

void ListeMots::ajouter(const std::string &mot)
{
    NoeudMot *nouveau = new NoeudMot(mot);

    if (tete == nullptr)
    {
        // Si la liste est vide, le nouveau mot devient la tête
        tete = nouveau;
    }
    else
    {
        // Parcourir jusqu'au dernier nœud
        NoeudMot *courant = tete;
        while (courant->suivant != nullptr)
        {
            courant = courant->suivant;
        }
        // Ajouter le nouveau nœud à la fin
        courant->suivant = nouveau;
    }
}

void ListeMots::associerVoyelles(ListeAscii &listeAscii)
{
    NoeudMot *courant = tete;
    while (courant)
    {
        for (char c : courant->mot)
        {
            char lower = tolower(c);
            if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u' || lower == 'y')
            {
                // Rechercher le nœud correspondant dans ListeAscii
                NoeudAscii *noeudAscii = listeAscii.trouver(toupper(c));
                if (noeudAscii)
                {
                    // Ajouter un pointeur vers ce nœud dans ListeVoyelles
                    courant->voyelles.ajouter(noeudAscii);
                }
            }
        }
        courant = courant->suivant;
    }
}

void ListeMots::afficher() const
{
    NoeudMot *courant = tete;
    while (courant)
    {
        // Affiche uniquement le mot
        cout << "Mot : " << courant->mot << endl;

        // Affiche les voyelles associées sans répétition
        cout << "Voyelles : ";
        courant->voyelles.afficher(); // Appelle la méthode afficher de ListeAscii
        courant = courant->suivant;
    }
}

ListeMots::~ListeMots()
{
    while (tete)
    {
        NoeudMot *tmp = tete;
        tete = tete->suivant;
        delete tmp;
    }
}
