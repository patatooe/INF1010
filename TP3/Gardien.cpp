/************************************************************************************
*	Fichier					: Gardien.cpp
*	Auteurs					: Robin Plamondon et Patricia Manarazan
*	Description				: Implementation de la classe Gardien
*	Date de creation		: 9 octobre 2022
*	Date de modification	: 31 ocotbre 2022
************************************************************************************/

#include "Gardien.h"
#include <iostream>
using namespace std;

// Le constructeur par défaut initialise les attributs de la classe de base Joueur et les
// attributs : attaque_ = 0.1, defense_ = 1.0, stabilite_ = 0.9, reflexe_ = 1.2.
Gardien::Gardien():Joueur(), stabilite_(0.9), reflexe_(1.2) 
{
	//static_cast<Joueur>(*this).setAttaque(1.0);
	//static_cast<Joueur>(*this).setDefense(1.0);

	attaque_ = 0.1;
	defense_ = 1.0;
}

// le constructeur par parametres
Gardien::Gardien(string nom, unsigned int matchsJoues,
	unsigned int buts, unsigned int assists,
	double attaque, double defense, double stabilite, double reflexe) : Joueur(nom, matchsJoues, buts, assists, attaque, defense){ 
	stabilite_ = stabilite;
	reflexe_ = reflexe;
}

// Destructeur
Gardien::~Gardien()
{
}

// Retroune l'attribut attaque_ de la classe de base Joueur de l'objet Gardien
double Gardien::getAttaque() const {
	double temp = this->attaque_ * (stabilite_ + reflexe_) / 2.5;
	return temp;
}

// Retroune l'attribut defense_ de la classe de base Joueur de l'objet Gardien
double Gardien::getDefense() const {
	double temp = this->defense_ * (stabilite_ + reflexe_) / 2;
	return temp;
}

// Retroune l'attribut stabilite_  de l'objet Gardien
double Gardien::getStabilite() const {
	double stabilite = stabilite_;
	return stabilite;
}

// Retourne l'attribut relexe_  de l'objet Gardien
double Gardien::getReflexe() const {
	double reflexe = reflexe_;
	return reflexe;
}

// Surcharge de l'operateur<< pour la classe Gardien fait appel à la fonction globale operator << de Joueur et affiche les nouveaux attributs.
ostream& operator<<(ostream& os, const Gardien & individu)
{    
	return os << "Gardien\n" << static_cast<Joueur>(individu) << ' ' << individu.stabilite_ << ' ' << individu.reflexe_ << '\n';
}
