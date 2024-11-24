#include "../header/DescripteurListeFournisseurs.h"
#include <iostream>

using namespace std;

// Constructeur
DescripteurListeFournisseurs::DescripteurListeFournisseurs() : tete(nullptr), queue(nullptr), nbElems(0) {}

// Destructeur
DescripteurListeFournisseurs::~DescripteurListeFournisseurs()
{
    while (tete != nullptr)
    {
        Noeud *temp = tete;
        tete = tete->suivant;
        delete temp->fournisseur; // Libère la mémoire du fournisseur
        delete temp;              // Libère le noeud
    }
}

// Ajouter une fournisseur à la liste
void DescripteurListeFournisseurs::ajouterFournisseur(Fournisseur *f)
{
    Noeud *nouveauNoeud = new Noeud(f);
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

// Supprimer un fournisseur de la liste
void DescripteurListeFournisseurs::supprimerFournisseur(Fournisseur *f)
{
    Noeud *courant = tete;
    while (courant != nullptr)
    {
        if (courant->fournisseur == f) // Trouvé
        {
            if (courant->precedent)
                courant->precedent->suivant = courant->suivant;
            else
                tete = courant->suivant;

            if (courant->suivant)
                courant->suivant->precedent = courant->precedent;
            else
                queue = courant->precedent;

            delete courant->fournisseur; // Libère la mémoire du fournisseur
            delete courant;              // Libère le noeud
            nbElems--;
            return;
        }
        courant = courant->suivant;
    }
    cout << "Fournisseur non trouvé dans la liste." << endl;
}

// Supprimer un fournisseur de la liste par Id
void DescripteurListeFournisseurs::supprimerFournisseur(int id)
{
    Fournisseur *f = this->getFournisseurById(id);

    Noeud *courant = tete;
    while (courant != nullptr)
    {
        if (courant->fournisseur == f) // Trouvé
        {
            if (courant->precedent)
                courant->precedent->suivant = courant->suivant;
            else
                tete = courant->suivant;

            if (courant->suivant)
                courant->suivant->precedent = courant->precedent;
            else
                queue = courant->precedent;

            delete courant->fournisseur; // Libère la mémoire du fournisseur
            delete courant;              // Libère le noeud
            nbElems--;
            return;
        }
        courant = courant->suivant;
    }
    cout << "Fournisseur non trouvé dans la liste." << endl;
}

// Récupérer un fournisseur par son Id
Fournisseur *DescripteurListeFournisseurs::getFournisseurById(int id) const
{
    Noeud *courant = tete;
    while (courant != nullptr)
    {
        if (courant->fournisseur->getId() == id)
        {
            return courant->fournisseur;
        }
        courant = courant->suivant;
    }
    return nullptr;
}

// Afficher les informations de la liste
void DescripteurListeFournisseurs::afficherListe() const
{
    if (nbElems == 0)
    {
        cout << "La liste des fournisseurs est vide." << endl;
        return;
    }
    Noeud *courant = tete;
    cout << "Liste des fournisseurs (" << nbElems << " éléments) :" << endl;
    while (courant != nullptr)
    {
        courant->fournisseur->afficher(); // Appelle la méthode afficher() de Fournisseur
        courant = courant->suivant;
    }
}

// Obtenir le nombre d'éléments
int DescripteurListeFournisseurs::getNbElems() const
{
    return nbElems;
}

int DescripteurListeFournisseurs::getProchainIdDisponible() const
{
    int maxId = 0;

    Noeud *courant = tete;
    while (courant != nullptr)
    {
        int idEpice = courant->fournisseur->getId();
        if (idEpice > maxId)
        {
            maxId = idEpice;
        }
        courant = courant->suivant;
    }

    return maxId + 1; // Le prochain ID disponible est le plus grand ID + 1
}