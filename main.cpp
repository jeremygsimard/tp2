#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream>
#include "Etudiant.h"
#include <iostream>


int main() {
    std::vector<Etudiant> un_tableau;

    std::ifstream data_student("donneesbrutes.txt");

    std::string ligne;
    std::string identifiant;
    long matricule;
    int nb_note = 0;
    int note = 0;
    int compteur = 0;


    while (std::getline(data_student, ligne)) {
        std::stringstream fichier(ligne);
        fichier >> identifiant >> matricule >> nb_note>>note;



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
    data_student.close();


    std::ofstream data_student2("moyennes.txt");

    std::sort(un_tableau.begin(), un_tableau.end());

    std::string matriculeEtMoyenne;
    for (auto it : un_tableau) {
        matriculeEtMoyenne =  std::to_string(it.getMatricule()) + " " + std::to_string(it.calculerMoyenne()) +"\n";
        data_student2 << matriculeEtMoyenne;
    }

    data_student2.close();
}