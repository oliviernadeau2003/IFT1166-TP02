#include "../includes/ListeAscii.h"
#include <iostream>
#include <set> // Pour éviter les doublons

using namespace std;

ListeAscii::ListeAscii() : tete(nullptr) {}

void ListeAscii::ajouter(char caractere, const std::string &valeurAsciiBrut)
{
    // Supprimer le ';' au début de la valeur ASCII, si présent
    std::string valeurAscii = valeurAsciiBrut;
    if (!valeurAscii.empty() && valeurAscii[0] == ';')
    {
        valeurAscii = valeurAscii.substr(1); // Enlève le premier caractère (;)
    }

    // Ajouter le nœud à la liste
    NoeudAscii *nouveau = new NoeudAscii(caractere, valeurAscii);
    nouveau->suivant = tete;
    tete = nouveau;
}

NoeudAscii *ListeAscii::trouver(char caractere) const
{
    NoeudAscii *courant = tete;
    while (courant)
    {
        if (courant->caractere == caractere)
        {
            return courant;
        }
        courant = courant->suivant;
    }
    return nullptr;
}

void ListeAscii::afficher() const
{
    NoeudAscii *courant = tete;
    std::set<char> voyellesAffichees; // Pour éviter les répétitions

    while (courant)
    {
        // Si la voyelle n'a pas encore été affichée
        if (voyellesAffichees.find(courant->caractere) == voyellesAffichees.end())
        {
            // Affiche le caractère et sa valeur ASCII sans point-virgule
            cout << courant->caractere << "(" << courant->valeurAscii << ") ";
            voyellesAffichees.insert(courant->caractere); // Marquer comme affichée
        }
        courant = courant->suivant;
    }
    cout << endl; // Nouvelle ligne après avoir affiché toutes les voyelles
}

ListeAscii::~ListeAscii()
{
    while (tete)
    {
        NoeudAscii *tmp = tete;
        tete = tete->suivant;
        delete tmp;
    }
}
