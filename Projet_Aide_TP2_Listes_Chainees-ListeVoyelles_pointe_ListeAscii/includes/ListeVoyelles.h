#ifndef LISTE_VOYELLES_H
#define LISTE_VOYELLES_H

#include "ListeAscii.h"
#include <iostream>

/**
 * Classe représentant un nœud dans la liste des voyelles associées à un mot.
 */
class NoeudVoyelle
{
public:
    NoeudAscii *pointeurNoeudAscii; // Pointeur vers un nœud de ListeAscii
    NoeudVoyelle *suivant;          // Pointeur vers le prochain nœud de ListeVoyelles

    // Constructeur
    NoeudVoyelle(NoeudAscii *pointeurNoeudAscii);
};

/**
 * Classe représentant une liste chaînée de voyelles pour un mot.
 */
class ListeVoyelles
{
private:
    NoeudVoyelle *tete; // Pointeur vers le premier nœud

public:
    // Constructeur par défaut
    ListeVoyelles();

    // Ajouter une voyelle (pointeur vers un NoeudAscii existant)
    void ajouter(NoeudAscii *noeudAscii);

    // Afficher toutes les voyelles de la liste
    void afficher() const;

    // Destructeur pour libérer la mémoire
    ~ListeVoyelles();
};

#endif // LISTE_VOYELLES_H
