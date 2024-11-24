#include <fstream>
#include <sstream> // Pour std::istringstream
#include <iostream>

#include "../header/DescripteurListeEpices.h"
#include "../header/DescripteurListeFournisseurs.h"

namespace Utils
{
    void chargerFichierFournisseur(const string &nomFichier, DescripteurListeFournisseurs &listeFournisseurs)
    {
        ifstream fichier(nomFichier);
        if (!fichier)
        {
            cerr << "Erreur : Ouverture du fichier '" << nomFichier << "' impossible." << endl;
            return;
        }

        string ligne;
        while (getline(fichier, ligne))
        {
            stringstream ss(ligne);
            string idStr, nom, prenom, email, telephone;

            // Découpage de la ligne par le séparateur ';'
            getline(ss, idStr, ';');
            getline(ss, nom, ';');
            getline(ss, prenom, ';');
            getline(ss, email, ';');
            getline(ss, telephone, ';');

            int id = stoi(idStr);

            Fournisseur *fournisseur = new Fournisseur(id, nom, prenom, email, telephone);
            listeFournisseurs.ajouterFournisseur(fournisseur);
        }

        fichier.close();
    }

    void chargerFichierEpices(const string &nomFichier, DescripteurListeEpices &listeEpices, DescripteurListeFournisseurs &listeFournisseurs)
    {
        ifstream fichier(nomFichier);
        if (!fichier)
        {
            cerr << "Erreur : Ouverture du fichier '" << nomFichier << "' impossible." << endl;
            return;
        }

        string ligne;
        while (getline(fichier, ligne))
        {
            stringstream ss(ligne);
            string idStr, nom, type, prixStr, quantiteStr, categorie, fournisseursStr;

            // Découpage de la ligne par le séparateur ';'
            getline(ss, idStr, ';');
            getline(ss, nom, ';');
            getline(ss, type, ';');
            getline(ss, prixStr, ';');
            getline(ss, quantiteStr, ';');
            getline(ss, categorie, ';');
            getline(ss, fournisseursStr); // Fournisseurs (jusqu'à la fin de la ligne)

            int id = stoi(idStr);
            float prix = stof(prixStr);
            float quantite = stof(quantiteStr);

            Epice *epice = new Epice(id, nom, type, prix, quantite, categorie);

            // Ajout des fournisseurs associés
            stringstream ssFournisseurs(fournisseursStr);
            string fournisseurIdStr;
            while (getline(ssFournisseurs, fournisseurIdStr, ';'))
            {
                int fournisseurId = stoi(fournisseurIdStr);

                // Recherche du fournisseur correspondant dans la liste des fournisseurs
                Fournisseur *fournisseur = listeFournisseurs.getFournisseurById(fournisseurId);
                if (fournisseur)
                    epice->ajouterFournisseur(fournisseur);
            }

            listeEpices.ajouterEpice(epice);
        }

        fichier.close();
    }
};