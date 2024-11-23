#ifndef DESCRIPTEURLISTPICES_H
#define DESCRIPTEURLISTPICES_H

#include <iostream>
#include <string>
using namespace std;

#include "Epice.h" // Inclure la classe Epice

// Définition d'un nœud pour les épices
struct NoeudEpice
{
    Epice epice;           // Objet épice
    NoeudEpice *suivant;   // Pointeur vers le nœud suivant
    NoeudEpice *precedent; // Pointeur vers le nœud précédent

    NoeudEpice(const Epice &epice);
};

// Classe pour gérer une liste doublement chaînée d'épices
class DescripteurListeEpices
{
private:
    NoeudEpice *tete;
    NoeudEpice *queue;
    int nbElems;

public:
    DescripteurListeEpices();
    ~DescripteurListeEpices();

    void ajouter(const Epice &epice);
    void afficher() const;
    int taille() const;
    bool supprimer(int id);
};

#endif // DESCRIPTEUREPICES_H
