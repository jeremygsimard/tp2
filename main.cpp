#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream>
#include "Etudiant.h"
#include <iostream>

using namespace std;

int main() {

    vector<Etudiant> un_tableau;
    ifstream fichier_brute("donneesbrutes.txt");

    string ligne;
    string identifiant;
    long matricule;
    int nb_note = 0;
    int note = 0;
    int compteur = 0;


    while (std::getline(fichier_brute, ligne)) {
        stringstream fichier(ligne);
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

    ofstream fichier_moyenne("moyenne.txt");
    sort(un_tableau.begin(), un_tableau.end());

    string matriculeEtMoyenne;
    for (auto it : un_tableau) {
        matriculeEtMoyenne =  to_string(it.getMatricule()) + " " + to_string(it.calculerMoyenne()) +"\n";
        fichier_moyenne << matriculeEtMoyenne;
    }
    fichier_moyenne.close();
}
