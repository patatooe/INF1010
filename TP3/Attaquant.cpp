/************************************************************************************
*	Fichier					: Attaquant.cpp
*	Auteurs					: Robin Plamondon et Patricia Manarazan
*	Description				: Implementation de la classe Attaquant
*	Date de creation		: 9 octobre 2022
*	Date de modification	: 31 ocotbre 2022
************************************************************************************/

#include "Attaquant.h"
#include <iostream>
using namespace std;

// to do constructeurs

/**
 * @brief Le constructeur par défaut initialise les attributs de la classe Attaquant
*/
Attaquant::Attaquant() : Joueur(), vitesse_(1.0), agilite_(0.8), precision_(1.0)
{
	attaque_ = 1.0;
	defense_ = 0.3;
}

/**
 * @brief Constructeur par parametres d'un objet de classe Attaquant
 * @param nom
 * @param matchsJoues
 * @param buts
 * @param assists
 * @param attaque
 * @param defense
 * @param vitesse
 * @param agilite
 * @param precision
*/
Attaquant :: Attaquant(string nom, unsigned int matchsJoues, unsigned int buts, unsigned int assists,
	double attaque, double defense, double vitesse, double agilite, double precision) : Joueur(nom, matchsJoues, buts, assists, attaque, defense),
	vitesse_(vitesse), agilite_(agilite), precision_(precision) {}

/**
 * @brief Destructeur d'un ojet de classe Attaquanr
*/
Attaquant::~Attaquant()
{
}
/**
 * @brief La méthode getAttaque est changée pour attaque_*(vitesse_+agilite_+precision_)/3
 * @return double
*/
double Attaquant::getAttaque() const {
	double temp = Joueur :: getAttaque() * (vitesse_ + agilite_ + precision_) / 3;
	return temp;
}

/**
 * @brief La méthode getDefense est changée pour defense_*(vitesse_+agilite_+precision_)/3.5
 * @return double
*/
double Attaquant::getDefense() const {
	double temp = Joueur :: getDefense() * (vitesse_ + agilite_ + precision_) / 3.5;
	return temp;
}
/**
 * @brief Getter de la vitesse des attaquants
*/
double Attaquant::getVitesse() const {
	return vitesse_;
}

/**
 * @brief Getter de l'agilite des attaquants
*/
double Attaquant::getAgilite() const {
	return agilite_;
}
/**
 * @brief Getter de la precision des attaquants
*/
double Attaquant::getPrecision() const {
	return precision_;
}
 
/**
 * @brief La fonction globale operator << pour afficher « Attaquant », faire appel à la fonction
 globale operator << et afficher les nouveaux attributs.
 * @param os
 * @param individu
 * @return Reference a objet de type ostream
*/
ostream& operator<<(ostream& os, const Attaquant & individu){ 
	return os << " Attaquant \n" << static_cast<Joueur>(individu) << " " << individu.vitesse_ << " " << individu.agilite_ << " " << individu.precision_ << '\n';
}
