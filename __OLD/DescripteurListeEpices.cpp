#include <iostream>
#include <string>
using namespace std;

#include "../header/DescripteurListeEpices.h"

// Définition d'un nœud pour les épices
struct NoeudEpice
{
    Epice epice;           // Objet épice
    NoeudEpice *suivant;   // Pointeur vers le nœud suivant
    NoeudEpice *precedent; // Pointeur vers le nœud précédent

    NoeudEpice(const Epice &epice) : epice(epice), suivant(nullptr), precedent(nullptr) {}
};

// Classe pour gérer une liste doublement chaînée d'épices
DescripteurListeEpices::DescripteurListeEpices() : tete(nullptr), queue(nullptr), nbElems(0) {}

DescripteurListeEpices::~DescripteurListeEpices()
{
    while (tete)
    {
        NoeudEpice *temp = tete;
        tete = tete->suivant;
        delete temp;
    }
}

void DescripteurListeEpices::ajouter(const Epice &epice)
{
    NoeudEpice *nouveauNoeud = new NoeudEpice(epice);
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

void DescripteurListeEpices::afficher() const
{
    NoeudEpice *courant = tete;
    while (courant)
    {
        courant->epice.afficher();
        courant = courant->suivant;
    }
}

int DescripteurListeEpices::taille() const { return nbElems; }

bool DescripteurListeEpices::supprimer(int id)
{
    NoeudEpice *courant = tete;
    while (courant)
    {
        if (courant->epice.getId() == id)
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
