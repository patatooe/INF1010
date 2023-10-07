#include "Equipe.h"
#include <algorithm>
#include <numeric>

using namespace std;

Equipe::Equipe(const string& nom,  unsigned int jour,
                unsigned int mois, unsigned int annee):
    victoire_(0),
    nom_(nom),
    dateDeCreation_(make_unique<Date>(jour, mois, annee))
{
}

Equipe::Equipe(const string& nom): 
    nom_(nom),
    victoire_(0),
    dateDeCreation_(make_unique<Date>())
{
}

 Equipe::Equipe(const Equipe& eq)
 {
     *this = eq;
 }

Equipe& Equipe::operator=(const Equipe& eq)
{
    if (this != &eq)
    {   
        nom_ = eq.nom_;
        victoire_ = eq.victoire_;
        joueurs_ = eq.joueurs_;
        dateDeCreation_ = make_unique<Date>(*eq.dateDeCreation_);   
    }
    return *this;
}

string Equipe::getNom() const
{
    return nom_;
}

Date Equipe::getDate() const {
    return *dateDeCreation_;
}

int Equipe::getNombreVictoires() const
{
    return victoire_;
}

int Equipe::getNombreJoueurs() const
{
    return joueurs_.size();
}

shared_ptr<Joueur> Equipe::getJoueur(const std::string& joueur) const {
    
    auto it = find_if(joueurs_.begin(), joueurs_.end(), [&joueur](const shared_ptr<Joueur> joueurEquipe) { return joueurEquipe->getNom() == joueur;});

    if (it == joueurs_.end()) {
        return nullptr;
    }
    return *it; 
}

vector<std::shared_ptr<Joueur>> Equipe::getJoueurs() {

    sort(joueurs_.begin(), joueurs_.end(), FoncteurComparerParNom<Joueur>());

    return joueurs_; 
}

double Equipe::calculAttaque() const {

   auto sommeAttaque =  accumulate(joueurs_.begin(), joueurs_.end(), 0.0, [](double accumulator, const shared_ptr<Joueur> joueurEquipe) { return accumulator + fRand(0.8,1.8)*(joueurEquipe->getAttaque());});

   return sommeAttaque;
}

double Equipe::calculDefense() const {

    auto sommeDefense = accumulate(joueurs_.begin(), joueurs_.end(), 0.0, [](double accumulator, const shared_ptr<Joueur> joueurEquipe) { return accumulator + fRand(0.4, 1.5) * (joueurEquipe->getDefense());});

    return sommeDefense;
}

Equipe & Equipe::operator++()
{
    victoire_++;
    return *this;
}

Equipe Equipe::operator+ (const std::shared_ptr<Joueur>& individu) const {

    Equipe A;
    A = *this;
    A.joueurs_.push_back(individu);
    return A;

}

Equipe Equipe::operator-(const std::string& nomJoueur) const {

    Equipe A;
    A = *this;
    auto it = remove_if(joueurs_.begin(), joueurs_.end(), [&nomJoueur](const shared_ptr<Joueur> joueurEquipe) { return joueurEquipe->getNom() == nomJoueur;});
    A.joueurs_.erase(it);
    return A;
}

ostream& operator<<(ostream& os, const Equipe& eq)
{
	os << endl << eq.nom_ << endl;
	os << "Joueurs : " << endl;
	for (const auto& joueur: eq.joueurs_)
		os << *joueur;
	os << "Nombre de victoire>>s : " << eq.victoire_ << endl;
    os << "Somme de la force d'attaque " << eq.calculAttaque()<< endl;
    os << "Somme de la  force de defense " <<eq.calculDefense()<< endl;
    return os;
}