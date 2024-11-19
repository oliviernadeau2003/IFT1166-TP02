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
};