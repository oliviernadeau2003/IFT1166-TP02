#ifndef DESCRIPTEURLISTEEPICES_H
#define DESCRIPTEURLISTEEPICES_H

#include "Epice.h"

class DescripteurListeEpices
{
private:
    struct Noeud
    {
        Epice *epice;     // Pointeur vers une épice
        Noeud *suivant;   // Noeud suivant
        Noeud *precedent; // Noeud précédent

        Noeud(Epice *epice, Noeud *suiv = nullptr, Noeud *prec = nullptr)
            : epice(epice), suivant(suiv), precedent(prec) {}
    };

    Noeud *tete;  // Début de la liste
    Noeud *queue; // Fin de la liste
    int nbElems;  // Nombre d'éléments dans la liste

public:
    // Constructeur et destructeur
    DescripteurListeEpices();
    ~DescripteurListeEpices();

    // Méthodes principales
    void ajouterEpice(Epice *epice);
    void supprimerEpice(Epice *epice);
    void afficherListe() const;
    int getNbElems() const;
};

#endif
