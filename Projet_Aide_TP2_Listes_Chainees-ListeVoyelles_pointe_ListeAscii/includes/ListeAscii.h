#ifndef LISTE_ASCII_H
#define LISTE_ASCII_H

#include <string>

/**
 * Classe représentant un nœud pour un caractère ASCII.
 */
class NoeudAscii
{
public:
    char caractere;          // Caractère
    std::string valeurAscii; // Valeur ASCII en hexadécimal
    NoeudAscii *suivant;     // Pointeur vers le nœud suivant

    // Constructeur du nœud
    NoeudAscii(char caractere, const std::string &valeurAscii)
        : caractere(caractere), valeurAscii(valeurAscii), suivant(nullptr) {}
};

/**
 * Classe représentant une liste chaînée pour gérer les caractères ASCII.
 */
class ListeAscii
{
private:
    NoeudAscii *tete; // Pointeur vers le premier nœud de la liste

public:
    ListeAscii();                                                 // Constructeur par défaut
    void ajouter(char caractere, const std::string &valeurAscii); // Ajouter un nœud
    NoeudAscii *trouver(char caractere) const;                    // Trouver un nœud par caractère
    void afficher() const;                                        // Afficher tous les nœuds
    ~ListeAscii();                                                // Destructeur
};

#endif
