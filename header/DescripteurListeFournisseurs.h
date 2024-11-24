#ifndef DESCRIPTEURLISTEFOURNISSEURS_H
#define DESCRIPTEURLISTEFOURNISSEURS_H

#include "Fournisseur.h"

class DescripteurListeFournisseurs
{
private:
    struct Noeud
    {
        Fournisseur *fournisseur; // Pointeur vers un fournisseur
        Noeud *suivant;           // Noeud suivant
        Noeud *precedent;         // Noeud précédent

        Noeud(Fournisseur *fournisseur, Noeud *suiv = nullptr, Noeud *prec = nullptr)
            : fournisseur(fournisseur), suivant(suiv), precedent(prec) {}
    };

    Noeud *tete;  // Début de la liste
    Noeud *queue; // Fin de la liste
    int nbElems;  // Nombre d'éléments dans la liste

public:
    // Constructeur et destructeur
    DescripteurListeFournisseurs();
    ~DescripteurListeFournisseurs();

    // Méthodes principales
    void ajouterFournisseur(Fournisseur *fournisseur);
    void supprimerFournisseur(Fournisseur *fournisseur);
    void afficherListe() const;
    int getNbElems() const;
};

#endif
