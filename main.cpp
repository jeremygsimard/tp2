#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream>
#include "Etudiant.h"
#include <iostream>


int main() {
    std::vector<Etudiant> un_tableau; // conteneur vector pour les etudiants

    std::ifstream data_student("donneesbrutes.txt");  // objet pour lire fichier txt de raw data

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


    std::ofstream data_student2("moyennes.txt");  // print dans un nouveau fichier txt

    std::sort(un_tableau.begin(), un_tableau.end());   // organisation des valeurs par le matricule

    std::string matriculeEtMoyenne;
    for (auto it : un_tableau) {
        matriculeEtMoyenne =  std::to_string(it.getMatricule()) + " " + std::to_string(it.calculerMoyenne()) +"\n";
        data_student2 << matriculeEtMoyenne;
    }

    data_student2.close();
}
