#include "EquipeSport.h"
#include <iostream>

using namespace std;
static double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}
EquipeSport::EquipeSport(string nom ): nom_(nom), victoire_(0)
{
}

EquipeSport & EquipeSport::operator++()
{
    victoire_++;
    return *this;
}

string EquipeSport::getNom() const
{
	return nom_;
}

int EquipeSport::getNombreVictoire() const
{
	return victoire_;
}

double EquipeSport::calculAttaque() const //  random
{
    return  fRand(0.5, 1.8);
}

double EquipeSport::calculDefense() const // random
{
   return fRand(0.3, 1.4);
    
}

ostream& operator<<(ostream& os, const EquipeSport& eq)
{
	os << endl << eq.nom_ << endl;
	os << "Nombre de victoire>>s : " << eq.victoire_ << endl;
    os << "Force d'attaque " << eq.calculAttaque()<< endl;
    os << "Force de defense " <<eq.calculDefense()<< endl;
    return os;
}


