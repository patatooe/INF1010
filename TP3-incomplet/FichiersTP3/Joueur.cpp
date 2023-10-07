/************************************************************************************
*	Fichier					: Joueur.cpp
*	Auteurs					: 
*	Description				: Implementation de la classe Joueur
*	Date de creation		: 
*	Date de modification	: 
************************************************************************************/

#include "Joueur.h"
#include <iostream>
using namespace std;

// do to constructeur
Joueur::Joueur() {
	nom_ = "inconnu";
	matchsJoues_ = buts_ = assists_ = attaque_ = defense_ = 0;
}

Joueur::Joueur(string nom, unsigned int matchsJoues,
	unsigned int buts, unsigned int assists,
	double attaque, double defense) : nom_(nom), matchsJoues_ (matchsJoues), buts_(buts), assists_(assists), attaque_(attaque), defense_(defense)
{
}

Joueur::~Joueur()
{
}

void Joueur::setNom(string nom)
{
	nom_ = nom;
}

void Joueur::setMatchsJoues(unsigned int matchJoues)
{
	matchsJoues_ = matchJoues;
}

void Joueur::setButs(unsigned int buts )
{
	buts_ = buts;
}

void Joueur::setAssists(unsigned int assists)
{
	assists_ = assists;
}

void Joueur::setAttaque(double attaque) 
{
	this->attaque_ = attaque;
}

void Joueur::setDefense(double defense) 
{
	this->defense_ = defense; 
}

string Joueur::getNom() const
{
	return nom_;
}

unsigned int Joueur::getMatchsJoues() const
{
	return matchsJoues_;
}

unsigned int Joueur::getButs() const
{
	return buts_;
}

unsigned int Joueur::getAssists() const
{
	return assists_;
}

bool Joueur::operator <(const Joueur& ind)
{
    return (buts_< ind.buts_ || assists_< ind.assists_);
}

double Joueur::getAttaque() const
{
	return this->attaque_;
}
double Joueur::getDefense() const
{
	return this->defense_;
}

ostream& operator<<(ostream& os, const Joueur& individu)
{

	//  to do
	return os << individu.nom_ << ' ' << individu.matchsJoues_ << ' ' << individu.buts_ << ' ' << individu.assists_ << ' ' << individu.attaque_ << ' ' << individu.defense_ << endl;
}

 