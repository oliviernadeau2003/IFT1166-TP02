#include <string>
#include <iostream>
using namespace std;

// id, nom, prenom, courriel, telephone
// 7;García;María;maria.garcia@email.com;0987654321
class Fournisseur
{
private:
    int id;
    string nom;
    string prenom;
    string courriel;
    string telephone;

public:
    Fournisseur() : id(0), nom(""), prenom(""), courriel(""), telephone("") {}
    Fournisseur(int id, string nom, string prenom, string courriel, string telephone)
        : id(id), nom(nom), prenom(prenom), courriel(courriel), telephone(telephone) {};

    // Getters - Setters
    int getId() const { return this->id; }
    void setID(int id) { this->id = id; }

    string getNom() const { return this->nom; }
    void setNom(string nom) { this->nom = nom; }

    string getPrenom() const { return this->prenom; }
    void setPrenom(string prenom) { this->prenom = prenom; }

    string getCourriel() const { return this->courriel; }
    void getCourriel(string courriel) { this->courriel = courriel; }

    string getTelephone() const { return this->telephone; }
    void setTelephone(string telephone) { this->telephone = telephone; }

    void afficher()
    {
        cout << "ID: " << this->id << ", Nom: " << this->nom << ", Prénom: " << this->prenom << ", Courriel: " << this->courriel << ", Téléphone: " << this->telephone << "\n";
    }
};