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
    void supprimerEpice(int id);
    Epice *getEpiceById(int id) const;
    Epice *getEpiceByName(string nom) const;
    Epice *getEpiceByCategory(string categorie) const;
    void afficherFournisseursParEpice(const string &nom) const;
    void afficherFournisseursParEpice(const int id) const;
    void afficherEpicesParFournisseur(int id) const;
    void afficherListe() const;
    int getNbElems() const;
    int getProchainIdDisponible() const;
};

#endif
