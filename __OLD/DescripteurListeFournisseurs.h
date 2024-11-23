#ifndef DESCRIPTEURLISTFOURNISSEURS_H
#define DESCRIPTEURLISTFOURNISSEURS_H

#include <iostream>
#include <string>
using namespace std;

#include "Fournisseur.h" // Inclure la classe Fournisseur

// Définition d'un nœud pour les fournisseurs
struct NoeudFournisseur
{
    Fournisseur fournisseur;     // Objet fournisseur
    NoeudFournisseur *suivant;   // Pointeur vers le nœud suivant
    NoeudFournisseur *precedent; // Pointeur vers le nœud précédent

    NoeudFournisseur(const Fournisseur &fournisseur);
};

// Classe pour gérer une liste doublement chaînée de fournisseurs
class DescripteurListeFournisseurs
{
private:
    NoeudFournisseur *tete;
    NoeudFournisseur *queue;
    int nbElems;

public:
    DescripteurListeFournisseurs();
    ~DescripteurListeFournisseurs();

    void ajouter(const Fournisseur &fournisseur);
    void afficher() const;
    int taille() const;
    bool supprimer(int id);
};

#endif // DESCRIPTEURFOURNISSEURS_H
