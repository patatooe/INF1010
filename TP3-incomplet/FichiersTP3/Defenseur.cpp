/************************************************************************************
*	Fichier					: Defenseur.cpp
*	Auteurs					: 
*	Description				: Implementation de la classe Defenseur
*	Date de creation		: 
*	Date de modification	: 
************************************************************************************/

#include "Defenseur.h"
#include <iostream>
using namespace std;

// to do constructeurs
Defenseur::Defenseur() {
	attaque_ = 0.1; 
	defense_ = 0.9; 
	reactivite_ = 0.8; 
	vision_ = 1.0;
}

Defenseur::Defenseur(string nom, unsigned int matchsJoues,
	unsigned int buts, unsigned int assists,
	double attaque, double defense,
	double reactivite, double vision): Joueur(nom, matchsJoues,
		buts, assists, attaque, defense), reactivite_(reactivite), vision_(vision)
{
}

Defenseur::~Defenseur()
{
}

// to do les méthodes 
double Defenseur::getAttaque() const 
{
	double temp = this->attaque_*(reactivite_ + vision_) / 2.5;
	return temp;
}
double Defenseur::getDefense() const 
{
	double temp = this->defense_*(reactivite_ + vision_) / 2;
	return temp;
}

double Defenseur::getReactivite() const 
{
	return this->reactivite_;
}
double Defenseur::getVision() const 
{
	return this->vision_;
}

ostream& operator<<(ostream& os, const Defenseur& individu)
{   //  to do
	return os << "Attaquant" << endl << static_cast<Joueur>(individu) << individu.reactivite_ << ' ' << individu.vision_ << endl;

}


