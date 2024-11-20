#include <string>
#include <iostream>
using namespace std;

// 1;Cumin;Graines;2.5;100.0;Épices;1;2
// id, nom, type, prix, quantite, categorie, ...id fournisseur
class Epice
{
private:
    int id;
    string nom;
    string type;
    double prix;
    double quantite;
    string categorie;

public:
    Epice() : id(0), nom(""), type(""), prix(0.0), quantite(0.0), categorie("") {}
    Epice(int id, string nom, string type, double prix, double quantite, string categorie)
        : id(id), nom(nom), type(type), prix(prix), quantite(quantite), categorie(categorie) {};

    void afficher() const
    {
        cout << "ID: " << this->id << " Nom: " << this->nom << " Type: " << this->type << " Prix: " << this->prix << " Quantité: " << this->quantite << " Catégorie: " << this->quantite << "\n";
    }
};