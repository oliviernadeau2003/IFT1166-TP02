#include "../header/DescripteurListeEpices.h"
#include <iostream>

using namespace std;

// Constructeur
DescripteurListeEpices::DescripteurListeEpices() : tete(nullptr), queue(nullptr), nbElems(0) {}

// Destructeur
DescripteurListeEpices::~DescripteurListeEpices()
{
    while (tete != nullptr)
    {
        Noeud *temp = tete;
        tete = tete->suivant;
        delete temp->epice; // Libère la mémoire de l'épice
        delete temp;        // Libère le noeud
    }
}

// Ajouter une épice à la liste
void DescripteurListeEpices::ajouterEpice(Epice *e)
{
    Noeud *nouveauNoeud = new Noeud(e);
    if (tete == nullptr) // Si la liste est vide
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

// Supprimer une épice de la liste
void DescripteurListeEpices::supprimerEpice(Epice *e)
{
    Noeud *courant = tete;
    while (courant != nullptr)
    {
        if (courant->epice == e) // Trouvé
        {
            if (courant->precedent)
                courant->precedent->suivant = courant->suivant;
            else
                tete = courant->suivant;

            if (courant->suivant)
                courant->suivant->precedent = courant->precedent;
            else
                queue = courant->precedent;

            delete courant->epice; // Libère la mémoire de l'épice
            delete courant;        // Libère le noeud
            nbElems--;
            return;
        }
        courant = courant->suivant;
    }
}

// Afficher les informations de la liste
void DescripteurListeEpices::afficherListe() const
{
    Noeud *courant = tete;
    cout << "Liste des épices (" << nbElems << " éléments) :" << endl;
    while (courant != nullptr)
    {
        courant->epice->afficher(); // Appelle la méthode afficher() d'Epice
        courant = courant->suivant;
    }
}

// Obtenir le nombre d'éléments
int DescripteurListeEpices::getNbElems() const
{
    return nbElems;
}
