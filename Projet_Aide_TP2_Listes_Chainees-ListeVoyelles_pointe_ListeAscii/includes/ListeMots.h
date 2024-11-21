#ifndef LISTE_MOTS_H
#define LISTE_MOTS_H

#include "ListeAscii.h"
#include "ListeVoyelles.h"

#include <string>

/**
 * Classe représentant un nœud pour un mot.
 */
class NoeudMot
{
public:
    std::string mot;     // Mot
    ListeVoyelles voyelles; // Liste des voyelles associées
    NoeudMot *suivant;   // Pointeur vers le nœud suivant

    // Constructeur du nœud
    NoeudMot(const std::string &mot) : mot(mot), suivant(nullptr) {}
};

/**
 * Classe représentant une liste chaînée pour gérer les mots.
 */
class ListeMots
{
private:
    NoeudMot *tete; // Pointeur vers le premier nœud de la liste

public:
    ListeMots();                                   // Constructeur par défaut
    void ajouter(const std::string &mot);          // Ajouter un mot
    void associerVoyelles(ListeAscii &listeAscii); // Associer les voyelles d'un mot
    void afficher() const;                         // Afficher tous les mots et leurs voyelles
    ~ListeMots();                                  // Destructeur
};

#endif
