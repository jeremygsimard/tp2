#include "Etudiant.h"
#include "numeric"


Etudiant::Etudiant() {
}

Etudiant::Etudiant(std::string un_identifiant, long un_matricule) {
    this->identifiant = un_identifiant;
    this->matricule = un_matricule;
}
float Etudiant::calculerMoyenne() {
    int somme = accumulate(std::begin(notes), std::end(notes), 0);
    float moyennne = (float)somme /  notes.size();
    return moyennne;

}

void  Etudiant::ajouterNote(int une_note) {
    this->notes.push_back(une_note);
}

bool Etudiant::operator<(const Etudiant& etudiant_a_droite) const {
    if (this->matricule < etudiant_a_droite.matricule) return true;
    return false;
}

long Etudiant::getMatricule() {
    return this->matricule;
}
