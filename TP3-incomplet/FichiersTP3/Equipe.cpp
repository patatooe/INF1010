#include "Equipe.h"
#include <iostream>

using namespace std;
static double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}
Equipe::Equipe(): Equipe("inconnue", 01, 01, 2022)
{
}

Equipe::Equipe(string nom,  unsigned int jour,
                unsigned int mois, unsigned int annee):
    victoire_(0),
    nom_(nom),
    dateDeCreation_(make_unique<Date>(jour, mois, annee))
{
}
 Equipe::Equipe (const Equipe & eq)
 {
    nom_ = eq.nom_;
    victoire_ = eq.victoire_;
    joueurs_ = eq.joueurs_;
    dateDeCreation_ = make_unique<Date>(*eq.dateDeCreation_);
 }
Equipe::~Equipe()
{
}

Equipe& Equipe::operator =(const Equipe& eq)
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
Equipe  Equipe:: operator+(shared_ptr<Joueur> individu)
{   Equipe eq (*this);
    for ( auto joueur: eq.joueurs_) 
    {
        if (joueur->getNom() == individu->getNom()) 
            return eq ;   
    }
        eq.joueurs_.push_back(individu);  
        return eq;  
}

Equipe Equipe::operator-(string nomJoueur)
{   Equipe eq(*this);
    for  (int  i =  0 ; i < eq.joueurs_.size(); i++)
        if (eq.joueurs_[i]->getNom() == nomJoueur){
            eq.joueurs_[i] =eq.joueurs_.back();
            eq.joueurs_.pop_back();
           return eq;
        }
   return eq;           
}

Equipe & Equipe::operator++()
{
    victoire_++;
    return *this;
}

string Equipe::getNom() const
{
	return nom_;
}

int Equipe::getNombreVictoire() const
{
	return victoire_;
}

int Equipe::getNombreJoueurs() const
{
    return joueurs_.size();
}

shared_ptr<Joueur> Equipe::getJoueur(string nomJoueur) const
{
    for (int i = 0; i < joueurs_.size(); i++)
    {
        if (joueurs_[i]->getNom() == nomJoueur)
        {
            return joueurs_[i];
        }
    }
    return nullptr;
}

double Equipe::calculAttaque() const // somme des valeurs des attaquants + random
{
       // to do 
    double sommeAttaque = 0;
    for (int i = 0; i < joueurs_.size(); i++) {
        sommeAttaque =+ this->joueurs_[i]->getAttaque()*fRand(0.8, 1.8); 
    }
    return sommeAttaque;
}

double Equipe::calculDefense() const // sommes des defenses + random
{
  // to do
    double sommeDefense = 0;
    for (int i = 0; i < joueurs_.size(); i++) {
        sommeDefense =+ this->joueurs_[i]->getDefense() * fRand(0.4, 1.5);
    }
    return sommeDefense;
}
 vector<shared_ptr <Joueur> >  Equipe::getJoueurs(){
    // to do 
     return this->joueurs_;
 }

ostream& operator<<(ostream& os, const Equipe& eq)
{
	// to do
    os << eq.nom_ << endl;
    os << "Joueurs" << endl;
    for (int i = 0; i < eq.joueurs_.size(); i++) {
        os << eq.joueurs_[i];
    }
    os << "Nombre de victoire>>s : " << eq.getNombreVictoire() << endl;
    os << "Somme de la force d'attaque " << eq.calculAttaque() << endl;
    os << "Somme de la force de defense " << eq.calculDefense() << endl;
    return os;
}


