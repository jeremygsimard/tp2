#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream>
#include "Etudiant.h"
#include <iostream>

int main() {

    std::vector<Etudiant> un_tableau;
    std::ifstream fichier_brute("donneesbrutes.txt");

    std::string ligne;
    std::string identifiant;
    long matricule;
    int nb_note = 0;
    int note = 0;
    int compteur = 0;


    while (std::getline(fichier_brute, ligne)) {
        std::stringstream fichier(ligne);
        fichier >> identifiant >> matricule >> nb_note;

        un_tableau.push_back(Etudiant(identifiant,matricule));
        while (true) {
            fichier >> note;
            if (fichier.fail()) {
                break;
            }
            un_tableau[compteur].ajouterNote(note);

        }
        compteur++;

    }
    fichier_brute.close();

    std::ofstream fichier_moyenne("moyenne.txt");
    std::sort(un_tableau.begin(), un_tableau.end());

    std::string matriculeEtMoyenne;
    for (auto it : un_tableau) {
        matriculeEtMoyenne =  std::to_string(it.getMatricule()) + " " + std::to_string(it.calculerMoyenne()) +"\n";
        fichier_moyenne << matriculeEtMoyenne;
    }
    fichier_moyenne.close();
}
