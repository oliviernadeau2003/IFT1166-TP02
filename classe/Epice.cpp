#include "../header/Epice.h"
#include "../header/Fournisseur.h"

#include <iostream>
#include <set>

using namespace std;

// Constructeurs de la classe Epice
Epice::Epice() : id(0), nom(""), type(""), prix(0.0), quantite(0.0), categorie("") {}

Epice::Epice(int id, string nom, string type, double prix, double quantite, string categorie)
    : id(id), nom(nom), type(type), prix(prix), quantite(quantite), categorie(categorie) {}

// Getters et Setters
int Epice::getId() const { return this->id; }
void Epice::setId(int id) { this->id = id; }

string Epice::getNom() const { return this->nom; }
void Epice::setNom(const string &nom) { this->nom = nom; }

string Epice::getType() const { return this->type; }
void Epice::setType(const string &type) { this->type = type; }

double Epice::getPrix() const { return this->prix; }
void Epice::setPrix(double prix) { this->prix = prix; }

double Epice::getQuantite() const { return this->quantite; }
void Epice::setQuantite(double quantite) { this->quantite = quantite; }

string Epice::getCategorie() const { return this->categorie; }
void Epice::setCategorie(const string &categorie) { this->categorie = categorie; }

const set<Fournisseur *> Epice::getFournisseurs() const { return fournisseurs; }

// Ajouter un fournisseur associé
void Epice::ajouterFournisseur(Fournisseur *fournisseur)
{
    fournisseurs.insert(fournisseur);
}

// Supprimer fournisseur par pointeur
void Epice::supprimerFournisseur(Fournisseur *fournisseur)
{
    fournisseurs.erase(fournisseur);
}

// Supprimer fournisseur par Id
void Epice::supprimerFournisseur(int id)
{
    for (Fournisseur *fournisseur : fournisseurs)
        if (fournisseur->getId() == id)
            fournisseurs.erase(fournisseur);
}

// Afficher les informations de l'épice et ses fournisseurs
void Epice::afficher() const
{
    cout << "ID: " << this->id << ", Nom: " << this->nom << ", Type: " << this->type
         << ", Prix: " << this->prix << ", Quantité: " << this->quantite << ", Catégorie: " << this->categorie << "\n";
    afficherFournisseurs();
    cout << "\n";
}

void Epice::afficherFournisseurs() const
{
    cout << "  Fournisseurs associés :\n";
    if (fournisseurs.size() > 0)
        for (Fournisseur *fournisseur : fournisseurs)
        {
            cout << "    - ";
            fournisseur->afficher();
        }
    else
        cout << "    Aucun fournisseur";
}
