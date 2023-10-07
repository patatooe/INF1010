/************************************************************************************
*	Fichier					: Defenseur.cpp
*	Auteurs					: Robin Plamondon et Patricia Manarazan
*	Description				: Implementation de la classe Defenseur
*	Date de creation		: 9 octobre 2022
*	Date de modification	: 31 oct0bre 2022
************************************************************************************/

#include "Defenseur.h"
#include <iostream>
using namespace std;

// to do constructeurs

//Le constructeur par défaut initialise les attributs de la classe de base Joueur et les
//attributs : attaque_ = 0.1; defense_ = 0.9; reactivite_ = 0.8; vision_ = 1.0;
Defenseur::Defenseur() : Joueur()// , reactivite_(0.8), vision_(1.0) 
{
	attaque_ = 0.1; 
	defense_ = 0.9; 
	reactivite_ = 0.8; 
	vision_ = 1.0;
}

Defenseur::Defenseur(string nom, unsigned int matchsJoues,
	unsigned int buts, unsigned int assists,
	double attaque, double defense,
	double reactivite, double vision) : Joueur(nom, matchsJoues, buts, assists, attaque, defense), reactivite_(reactivite), vision_(vision)
{}

Defenseur::~Defenseur()
{}


// Getters des attributs  attaque et defense selon une formule
double Defenseur::getAttaque() const 
{
	return attaque_ * (reactivite_ + vision_) / 2.5;
}
double Defenseur::getDefense() const 
{
	return defense_ * (reactivite_ + vision_) / 2;
}

// Methode qui retourne la reactivite du defenseur
double Defenseur::getReactivite() const {
	return reactivite_;
}

// Methode qui retourne la vision du defenseur
double Defenseur::getVision() const {
	return vision_;
}

// La fonction globale operator << pour afficher « Defenseur », faire appel à la fonction
// globale operator << de Joueur et afficher les nouveaux attributs.
// string printAttendu = string(" Defenseur \n") + string("Rio ferdinand 53 5 16 12 26.5\n") + string(" 1.2 0.8\n");
ostream& operator<<(ostream& os, const Defenseur& individu){   //  to do
	return os << " Defenseur \n" << static_cast<Joueur>(individu) << ' ' << individu.reactivite_ << ' ' << individu.vision_ << '\n';

}


