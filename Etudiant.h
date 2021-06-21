#ifndef __ETUDIANT_H__
#define __ETUDIANT_H__
#include <vector>
#include <iostream>

using namespace std;

class Etudiant
{
private:
    vector<int> notes;
    string identifiant;
    long matricule;
    float moyenne, somme;


public:
    Etudiant();
    Etudiant(string un_identifiant, long un_matricule);

    float calculerMoyenne();
    void ajouterNote(int une_note);
    long getMatricule() const;
    bool operator<(const Etudiant& etudiant_a_droite) const;

};
#endif
