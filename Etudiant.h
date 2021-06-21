#ifndef __ETUDIANT_H__
#define __ETUDIANT_H__
#include <vector>
#include <iostream>

class Etudiant
{
private:
    std::vector<int> notes;
    std::string identifiant;
    long matricule;

public:
    Etudiant();
    Etudiant(std::string un_identifiant, long un_matricule);

    float calculerMoyenne();
    void ajouterNote(int une_note);
    long getMatricule() const;
    bool operator<(const Etudiant& etudiant_a_droite) const;

};
#endif



