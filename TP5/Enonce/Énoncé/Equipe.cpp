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

shared_ptr<Joueur> Equipe::getJoueur(const string& nomJoueur) const
{
    auto it = find_if(joueurs_.begin(), joueurs_.end(), [&nomJoueur](auto j) {
        return j->getNom() == nomJoueur;
    });

    if (it != joueurs_.end())
    {
        return *it;
    }
    return nullptr;
}

std::vector<std::shared_ptr <Joueur>> Equipe::getJoueurs() {
    std::vector<shared_ptr <Joueur>> joueurs = joueurs_;
    sort(joueurs.begin(), joueurs.end(), FoncteurComparerParNom<Joueur>());
    return joueurs;
}

double Equipe::calculAttaque() const // somme des valeurs des attaquants + random
{
    return accumulate(joueurs_.begin(), joueurs_.end(), 0.0,
        [](double sommeAttaque, auto j) {
        return sommeAttaque + j->getAttaque() * fRand(0.8, 1.8);
    });
}

double Equipe::calculDefense() const // sommes des defenses + random
{
    return accumulate(joueurs_.begin(), joueurs_.end(), 0.0,
        [](double sommeDefense, auto j) {
        return sommeDefense + j->getDefense() * fRand(0.4, 1.5);
    });
}

Equipe& Equipe::operator+=(const shared_ptr<Joueur>& individu)
{   
    if (getJoueur(individu->getNom()) == nullptr) {
        joueurs_.push_back(individu);
        // TODO: Émettre le signal joueurAjoutee en lui passant le nom du joueur en paramètre
    }
    /*TODO: Si le joueur existe déjà, lancer une exception de type invalid_argument.
     *      Vous devez choisir le texte lié au cas d'exception.*/ 
    return *this;
}

Equipe& Equipe::operator-=(const string& nomJoueur)
{   
    auto it = remove_if(joueurs_.begin(), joueurs_.end(),
        [&nomJoueur](auto joueur) {
            return joueur->getNom() == nomJoueur;
        });
    if (it != joueurs_.end()) {
        joueurs_.erase(it, joueurs_.end());
    }
    /*TODO: Si le joueur n'existe pas, lancer une exception de type invalid_argument.
     *      Vous devez choisir le texte lié au cas d'exception.*/
    return *this;           
}

Equipe & Equipe::operator++()
{
    victoire_++;
    return *this;
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