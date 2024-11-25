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
            cout << "Épice " << e->getNom() << " suprimer avec succès.\n";
            return;
        }
        courant = courant->suivant;
    }
}

// Supprimer une épice de la liste par Id
void DescripteurListeEpices::supprimerEpice(int id)
{
    Epice *e = this->getEpiceById(id);

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
            cout << "Épice " << id << " suprimer avec succès.\n";
            return;
        }
        courant = courant->suivant;
    }
}

// Récupérer une épice par son Id
Epice *DescripteurListeEpices::getEpiceById(int id) const
{
    Noeud *courant = tete;
    while (courant != nullptr)
    {
        if (courant->epice->getId() == id)
        {
            return courant->epice;
        }
        courant = courant->suivant;
    }
    cout << "Erreur : Aucune épice trouvée." << endl;
    return nullptr;
}

// Récupérer une épice par son Nom
Epice *DescripteurListeEpices::getEpiceByName(string nom) const
{
    Noeud *courant = tete;
    while (courant != nullptr)
    {
        if (courant->epice->getNom() == nom)
        {
            return courant->epice;
        }
        courant = courant->suivant;
    }
    cout << "Erreur : Aucune épice trouvée." << endl;
    return nullptr;
}

// Récupérer une épice par sa catégorie
Epice *DescripteurListeEpices::getEpiceByCategory(string categorie) const
{
    Noeud *courant = tete;
    while (courant != nullptr)
    {
        if (courant->epice->getCategorie() == categorie)
        {
            return courant->epice;
        }
        courant = courant->suivant;
    }
    cout << "Erreur : Aucune épice trouvée." << endl;
    return nullptr;
}

// Afficher les fournisseurs d'un épice par nom
void DescripteurListeEpices::afficherFournisseursParEpice(const string &nom) const
{
    Noeud *courant = tete;
    bool epiceTrouvee = false;

    while (courant != nullptr)
    {
        Epice *epice = courant->epice;

        if (epice->getNom() == nom)
        {
            epiceTrouvee = true;
            cout << "Épice trouvée : " << epice->getNom() << endl;

            // Affichage des fournisseurs associés
            cout << "Fournisseurs associés :" << endl;
            const set<Fournisseur *> &fournisseurs = epice->getFournisseurs();
            if (fournisseurs.empty())
                cout << "Aucun fournisseur associé." << endl;
            else
                for (Fournisseur *fournisseur : fournisseurs)
                    fournisseur->afficher();
            break;
        }

        courant = courant->suivant;
    }

    if (!epiceTrouvee)
        cout << "Aucune épice trouvée avec le nom : " << nom << endl;
}

// Afficher les fournisseurs d'un épice par id
void DescripteurListeEpices::afficherFournisseursParEpice(const int id) const
{
    Noeud *courant = tete;
    bool epiceTrouvee = false;

    while (courant != nullptr)
    {
        Epice *epice = courant->epice;

        if (epice->getId() == id)
        {
            epiceTrouvee = true;
            cout << "Épice trouvée : " << epice->getNom() << endl;

            // Affichage des fournisseurs associés
            cout << "Fournisseurs associés :" << endl;
            const set<Fournisseur *> &fournisseurs = epice->getFournisseurs();
            if (fournisseurs.empty())
            {
                cout << "Aucun fournisseur associé." << endl;
            }
            else
                for (Fournisseur *fournisseur : fournisseurs)
                    fournisseur->afficher();

            break;
        }

        courant = courant->suivant;
    }

    if (!epiceTrouvee)
        cout << "Aucune épice trouvée avec l'ID : " << id << endl;
}

void DescripteurListeEpices::afficherEpicesParFournisseur(int id) const
{
    Noeud *courant = tete;
    bool epicesTrouvees = false;

    cout << "Liste des épices vendues par le fournisseur ID " << id << " :" << endl
         << endl;

    while (courant != nullptr)
    {
        Epice *epice = courant->epice;

        // Vérifier si le fournisseur est associé à cette épice
        const set<Fournisseur *> &fournisseurs = epice->getFournisseurs();
        for (Fournisseur *fournisseur : fournisseurs)
        {
            if (fournisseur->getId() == id)
            {
                epice->afficher(); // Afficher les informations de l'épice
                epicesTrouvees = true;
                break;
            }
        }

        courant = courant->suivant; // Passer au noeud suivant
    }

    if (!epicesTrouvees)
        cout << "Aucune épice n'est associée au fournisseur avec l'ID : " << id << endl;
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

int DescripteurListeEpices::getProchainIdDisponible() const
{
    int maxId = 0;

    Noeud *courant = tete;
    while (courant != nullptr)
    {
        int idEpice = courant->epice->getId();
        if (idEpice > maxId)
        {
            maxId = idEpice;
        }
        courant = courant->suivant;
    }

    return maxId + 1; // Le prochain ID disponible est le plus grand ID + 1
}
