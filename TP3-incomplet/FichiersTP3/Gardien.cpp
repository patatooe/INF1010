/************************************************************************************
*	Fichier					: Gardien.cpp
*	Auteurs					: 
*	Description				: Implementation de la classe Gardien
*	Date de creation		: 
*	Date de modification	: 
************************************************************************************/

#include "Gardien.h"
#include <iostream>
using namespace std;

// to do constructeurs 
Gardien::Gardien(): Joueur() { //essayer avec :Joeur() et sans
	attaque_ = 0.1;
	defense_ = 1.0; 
	stabilite_ = 0.9;
	reflexe_ = 1.2;
}

Gardien::Gardien(string nom, unsigned int matchsJoues,
	unsigned int buts, unsigned int assists,
	double attaque, double defense, double stabilite, double reflexe): Joueur(nom, matchsJoues,
		buts, assists, attaque, defense), stabilite_(stabilite), reflexe_(reflexe){
}


Gardien::~Gardien()
{
}
// to do les méthodes

double Gardien::getAttaque() const 
{
	double temp = this->attaque_ * (stabilite_ + reflexe_) / 2.5;
	return temp; 
}
double Gardien::getDefense() const 
{
	double temp = this->defense_* (stabilite_ + reflexe_) / 2;
	return temp;
}

double Gardien::getStabilite() const 
{
	return this->stabilite_;
}
double Gardien::getReflexe() const 
{
	return this->reflexe_;
}

ostream& operator<<(ostream& os, const Gardien & individu)
{   
	return os << "Guardien" <<endl << static_cast<Joueur>(individu) << individu.stabilite_ << ' ' << individu.reflexe_ << ' ' << endl; // pk pas individu.getReflexe() etc
}
