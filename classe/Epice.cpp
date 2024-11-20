#include <string>
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

public:
    Epice() : id(0), nom(""), type(""), prix(0.0), quantite(0.0) {};
    Epice(int id, string nom, string type, double prix, double quantite) : id(id), nom(nom), type(type), prix(prix), quantite(quantite) {}
};