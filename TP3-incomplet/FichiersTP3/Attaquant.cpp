/************************************************************************************
*	Fichier					: Attaquant.cpp
*	Auteurs					: 
*	Description				: Implementation de la classe Attaquant
*	Date de creation		: 
*	Date de modification	: 
************************************************************************************/

#include "Attaquant.h"
#include <iostream>
using namespace std;

// to do constructeurs
Attaquant::Attaquant() {
	attaque_ = 1.0; 
	defense_ = 0.3; 
	vitesse_ = 1.0; 
	agilite_ = 0.8; 
	precision_ = 1.0;
}

Attaquant::~Attaquant()
{
}
Attaquant::Attaquant(string nom, unsigned int matchsJoues,
	unsigned int buts, unsigned int assists,
	double attaque, double defense,
	double vitesse, double agilite, double precision) : Joueur(nom, matchsJoues,
		buts, assists, attaque, defense), vitesse_(vitesse), agilite_(agilite), precision_(precision)
{
}

//  to do les méthodes 
double Attaquant::getAttaque() const 
{
	double temp = this->attaque_*(vitesse_ + agilite_ + precision_) / 3;
	return temp;
}

double Attaquant::getDefense() const 
{
	double temp = this->defense_*(vitesse_ + agilite_ + precision_) / 3.5;
	return temp;
}

double Attaquant::getVitesse() const 
{
	return this->vitesse_;
}

double Attaquant::getAgilite() const 
{
	return this->agilite_;
}

double Attaquant::getPrecision() const 
{
	return this->precision_;
}

ostream& operator<<(ostream& os, const Attaquant & individu)
{   // to do
	return os << "Attaquant" << endl << static_cast<Joueur>(individu) << individu.vitesse_ << ' ' << individu.agilite_ << ' ' << individu.precision_ << endl;
}
