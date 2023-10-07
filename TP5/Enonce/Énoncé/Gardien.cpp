#include "Gardien.h"

using namespace std;

Gardien::Gardien(const string& nom, unsigned int matchsJoues,
        unsigned int buts, unsigned int assists,
         double attaque, double defense,
          double stabilite, double reflexe)
         : Joueur(nom,matchsJoues,buts, assists, attaque, defense), 
          stabilite_(stabilite), reflexe_(reflexe)
{
}

double Gardien::getAttaque() const
{
    return Joueur::getAttaque()*(stabilite_+reflexe_)/2.5;
}

double Gardien::getDefense() const
{
    return Joueur::getDefense()*(stabilite_+reflexe_)/2;
}

double  Gardien::getStabilite() const
{
    return stabilite_;
}

double   Gardien::getReflexe() const
{
    return reflexe_;
}


ostream& operator<<(ostream& os, const Gardien & individu)
{    
    return os << "Gardien" << endl<< static_cast< const Joueur &> (individu)<<" "<< 
    individu.stabilite_ << " " << 
    individu.reflexe_ << endl;
}
