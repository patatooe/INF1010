/************************************************************************************
*	Fichier					: Joueur.cpp
*	Auteurs					: Patricia Manarazan (1942503), Robin Plamondon (2119689)
*	Description				: Implementation de la classe Joueur
*	Date de creation		: 2022/10/06
*	Date de modification	: 2022/10/06
************************************************************************************/

#include "Joueur.h"
#include <iostream>
using namespace std;

/**
 * @brief onstructeur par defaut pour un objet de classe Joueur
*/
Joueur::Joueur(): Joueur("inconnu", 0, 0, 0)
{
}

/**
 * @brief Constructeur par parametre d'un objet de classe Joueur
 * @param nom Nom du joueur
 * @param matchsJoues Nombre de match joues par le joueur
 * @param buts Nombre de buts marques par le joueur
 * @param assists Nombre d'assists du joueur
*/
Joueur::Joueur(string nom, unsigned int matchsJoues, unsigned int buts, unsigned int assists)
    : nom_(nom), matchsJoues_(matchsJoues), buts_(buts), assists_(assists)
{
}

/**
 * @brief Destructeur d'un objet de classe Joueur
*/
Joueur::~Joueur()
{
}

/**
 * @brief Setter du nom du joueur
 * @param nom 
*/
void Joueur::setNom(string nom)
{
	nom_ = nom;
}

/**
 * @brief Setter du nombre de matchs joues par le joueur
 * @param matchJoues 
*/
void Joueur::setMatchsJoues(unsigned int matchJoues)
{
	matchsJoues_ = matchJoues;
}

/**
 * @brief Setter du nombre de buts du joueur
 * @param buts 
*/
void Joueur::setButs(unsigned int buts )
{
	buts_ = buts;
}

/**
 * @brief Setter du nombre d'assists du joueur
 * @param assists 
*/
void Joueur::setAssists(unsigned int assists)
{
	assists_ = assists;
}

/**
 * @brief Getter du nom du joueur
 * @return Un string du nom du joueur
*/
string Joueur::getNom() const
{
	return nom_;
}

/**
 * @brief Getter du nombre de match joues par le joueur
 * @return Un int du nombre de match que le joueur a joue
*/
unsigned int Joueur::getMatchsJoues() const
{
	return matchsJoues_;
}

/**
 * @brief Getter du nombre de puts du joueur
 * @return Un int du nombre de buts du joueur
*/
unsigned int Joueur::getButs() const
{
	return buts_;
}

/**
 * @brief Getter du nombre d'assits du joueur
 * @return Un int de nombre d'assists du joueur
*/
unsigned int Joueur::getAssists() const
{
	return assists_;
}

/**
 * @brief Surcharge de <
 * @param ind Un objet de class Joueur sur lequel < sera affecte
 * @return Un bool qui donne false si compare les stats du jouer
*/
bool Joueur :: operator <(const Joueur& ind)
{
	if(buts_ == ind.buts_){
		if(assists_ < ind.assists_)
			return true;
		else
			return false;
	}
	else if(buts_ < ind.buts_)
		return true;
	else
		return false;
}

/**
 * @brief Affichage de l'objet de classe Joueur
 * @param os 
 * @param individu Individu a afficher
 * @return un reference a un objet de classe ostream, affichage
*/
ostream& operator<<(ostream& os, const Joueur& individu)
{
	return os << individu.nom_ << ' ' << individu.matchsJoues_ << ' ' << individu.buts_ << ' ' << individu.assists_ << endl;
}