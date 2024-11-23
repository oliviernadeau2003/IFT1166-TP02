#include <iostream>
#include <string>
using namespace std;

#include "../header/DescripteurListeFournisseurs.h"

// Définition d'un nœud pour les fournisseurs
struct NoeudFournisseur
{
    Fournisseur fournisseur;     // Objet fournisseur
    NoeudFournisseur *suivant;   // Pointeur vers le nœud suivant
    NoeudFournisseur *precedent; // Pointeur vers le nœud précédent

    NoeudFournisseur(const Fournisseur &fournisseur) : fournisseur(fournisseur), suivant(nullptr), precedent(nullptr) {}
};

// Classe pour gérer une liste doublement chaînée de fournisseurs
DescripteurListeFournisseurs::DescripteurListeFournisseurs() : tete(nullptr), queue(nullptr), nbElems(0) {}

DescripteurListeFournisseurs::~DescripteurListeFournisseurs()
{
    while (tete)
    {
        NoeudFournisseur *temp = tete;
        tete = tete->suivant;
        delete temp;
    }
}

void DescripteurListeFournisseurs::ajouter(const Fournisseur &fournisseur)
{
    NoeudFournisseur *nouveauNoeud = new NoeudFournisseur(fournisseur);
    if (!tete) // Si la liste est vide
    {
        tete = queue = nouveauNoeud;
    }
    else
    {
        queue->suivant = nouveauNoeud;
        nouveauNoeud->precedent = queue;
        queue = nouveauNoeud;
    }
    nbElems++;
}

void DescripteurListeFournisseurs::afficher() const
{
    NoeudFournisseur *courant = tete;
    while (courant)
    {
        courant->fournisseur.afficher();
        courant = courant->suivant;
    }
}

int DescripteurListeFournisseurs::taille() const { return nbElems; }

bool DescripteurListeFournisseurs::supprimer(int id)
{
    NoeudFournisseur *courant = tete;
    while (courant)
    {
        if (courant->fournisseur.getId() == id)
        {
            if (courant->precedent)
                courant->precedent->suivant = courant->suivant;
            else
                tete = courant->suivant;

            if (courant->suivant)
                courant->suivant->precedent = courant->precedent;
            else
                queue = courant->precedent;

            delete courant;
            nbElems--;
            return true;
        }
        courant = courant->suivant;
    }
    return false;
}
