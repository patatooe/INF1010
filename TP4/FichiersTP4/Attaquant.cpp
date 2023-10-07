#include "Attaquant.h"

using namespace std;
    
Attaquant::Attaquant(const string& nom, unsigned int matchsJoues, 
              unsigned int buts, unsigned int assists,
              double attaque, double defense,
	          double vitesse, double agilite, double precision)
             : Joueur(nom,matchsJoues,buts, assists,attaque, defense), 
             vitesse_(vitesse), agilite_(agilite), precision_(precision)
{
}

double Attaquant::getAttaque() const
{
    return Joueur::getAttaque()*(vitesse_+agilite_+precision_)/3;
}

double Attaquant::getDefense() const
{
    return Joueur::getDefense() *(vitesse_+agilite_+precision_)/3.5;
}
double Attaquant::getVitesse() const
{
    return vitesse_;
}
double Attaquant::getAgilite() const
{
    return agilite_;
}
double Attaquant::getPrecision() const
{
    return precision_;
}
ostream& operator<<(ostream& os, const Attaquant & individu)
{   os<<" Attaquant "<< endl;
    os << static_cast< const Joueur &> (individu)<<" "<< 
    individu.vitesse_ << " " << 
    individu.agilite_ << " " <<
    individu.precision_<< endl;
     return os;

}
