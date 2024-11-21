#include "ListeVoyelles.h"
#include "ListeAscii.h"
#include <set> // Pour éviter les doublons
/**
 * Constructeur pour un nœud de la liste des voyelles.
 */
NoeudVoyelle::NoeudVoyelle(NoeudAscii *pointeurNoeudAscii)
    : pointeurNoeudAscii(pointeurNoeudAscii), suivant(nullptr) {}

/**
 * Constructeur par défaut pour la liste des voyelles.
 */
ListeVoyelles::ListeVoyelles() : tete(nullptr) {}

/** 
 * Ajouter une voyelle à la liste (en pointant vers un nœud de ListeAscii).
 */
void ListeVoyelles::ajouter(NoeudAscii *noeudAscii)
{
    NoeudVoyelle *nouveau = new NoeudVoyelle(noeudAscii);
    nouveau->suivant = tete;
    tete = nouveau;
}

void ListeVoyelles::afficher() const
{
    std::set<NoeudAscii *> voyellesAffichees; // Utilisé pour éviter les doublons
    NoeudVoyelle *courant = tete;

    while (courant)
    {
        if (voyellesAffichees.find(courant->pointeurNoeudAscii) == voyellesAffichees.end())
        {
            // Afficher la voyelle si elle n'a pas encore été affichée
            std::cout << courant->pointeurNoeudAscii->caractere << "("
                      << courant->pointeurNoeudAscii->valeurAscii << ") ";
            voyellesAffichees.insert(courant->pointeurNoeudAscii); // Marquer comme affichée
        }
        courant = courant->suivant;
    }
    std::cout << std::endl; // Nouvelle ligne après avoir affiché toutes les voyelles
}

/**
 * Destructeur pour libérer la mémoire allouée.
 */
ListeVoyelles::~ListeVoyelles()
{
    while (tete)
    {
        NoeudVoyelle *tmp = tete;
        tete = tete->suivant;
        delete tmp;
    }
}
