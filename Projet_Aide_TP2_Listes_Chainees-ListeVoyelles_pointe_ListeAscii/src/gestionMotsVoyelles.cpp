#include "../includes/ListeAscii.h"
#include "../includes/ListeMots.h"
#include <fstream>
#include <iostream>
using namespace std;

void chargerAscii(const string &fichier, ListeAscii &listeAscii)
{
    ifstream inFile(fichier);
    if (!inFile)
    {
        cerr << "Erreur : impossible d'ouvrir le fichier ASCII." << endl;
        return;
    }

    char caractere;
    string valeurAscii;
    while (inFile >> caractere >> valeurAscii)
    {
        listeAscii.ajouter(caractere, valeurAscii);
    }
    inFile.close();
}

void chargerMots(const std::string &nomFichier, ListeMots &listeMots)
{
    std::ifstream fichierEntree(nomFichier);
    if (!fichierEntree)
    {
        std::cerr << "Erreur : impossible d'ouvrir le fichier texte." << std::endl;
        return;
    }

    std::string ligne;
    while (std::getline(fichierEntree, ligne))
    {
        // Supprimer la partie après le ';' si elle existe
        size_t pos = ligne.find(';');
        if (pos != std::string::npos)
        {
            ligne = ligne.substr(0, pos);
        }

        // Ajouter le mot nettoyé à la liste
        listeMots.ajouter(ligne);
    }

    fichierEntree.close();
}

int main()
{
    ListeAscii listeAscii;
    ListeMots listeMots;

    // Charger les données
    chargerAscii("src/donnees/alpha_ascii.txt", listeAscii);
    chargerMots("src/donnees/mots.txt", listeMots);

    // Associer les voyelles
    listeMots.associerVoyelles(listeAscii);

    // Afficher les mots et leurs voyelles
    listeMots.afficher();

    return 0;
}
