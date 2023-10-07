#include "Defenseur.h"

using namespace std;

Defenseur::Defenseur(const string& nom, unsigned int matchsJoues, 
                     unsigned int buts, unsigned int assists,
                     double attaque, double defense,
                     double reactivite, double vision)
	: Joueur(nom, matchsJoues,buts, assists, attaque, defense), 
    reactivite_(reactivite), vision_(vision)
{
}

double Defenseur::getAttaque() const
{
    return Joueur::getAttaque()*(reactivite_+vision_)/2.5;
}

double Defenseur::getDefense() const
{
    return Joueur::getDefense()*(reactivite_+vision_)/2;
}

double  Defenseur::getReactivite() const
{
    return reactivite_;
}

double  Defenseur::getVision() const
{
    return vision_;
}

ostream& operator<<(ostream& os, const Defenseur& individu)
{    os<<" Defenseur "<< endl;
     os << static_cast< const Joueur &>  (individu)<< " " <<
         individu.reactivite_ << " " <<
         individu.vision_ << endl;
    return os;
}


