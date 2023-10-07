/************************************************************************************
*	Fichier					: Joueur.cpp
*	Auteurs					: Patricia Manarazan (1942503), Robin Plamondon (2119689)
*	Description				: Implementation de la classe Joueur
*	Date de creation		: 2022/10/31
*	Date de modification	: 2022/10/31
************************************************************************************/

#include "Joueur.h"
#include <iostream>
using namespace std;
/**
 * @brief onstructeur par defaut pour un objet de classe Joueur
*/
Joueur:: Joueur() {
	nom_ = "inconnu";
	matchsJoues_ = buts_ = assists_ = attaque_ = defense_ = 0;
}
/**
 * @brief Constructeur par parametre d'un objet de classe Joueur
 * @param nom Nom du joueur
 * @param matchsJoues Nombre de match joues par le joueur
 * @param buts Nombre de buts marques par le joueur
 * @param assists Nombre d'assists du joueur
 * @param attaque Force d'attaque
 * @param defense Force de defense
*/
Joueur::Joueur(string nom, unsigned int matchsJoues, unsigned int buts, unsigned int assists, double attaque, double defense) 
				: nom_(nom), matchsJoues_(matchsJoues), buts_(buts), assists_(assists), attaque_(attaque), defense_(defense)
{}

// setters des attributs de Joueur
void Joueur::setAttaque(double attaque) 
{
	attaque_ = attaque;
}
void Joueur::setDefense(double defense) 
{
	defense_ = defense;
}


// getters des attributs de Joueur
double Joueur::getAttaque() const 
{
	double attaque = attaque_;
	return attaque;
}
double Joueur::getDefense() const 
{
	double defense = defense_;
	return defense;
}

/**
 * @brief Destructeur d'un objet de classe Joueur
*/
Joueur::~Joueur()
{
}
/**
 * @brief Setter du nom
*/
void Joueur::setNom(string nom)
{
	nom_ = nom;
}
/**
 * @brief Setter des matchs joues
*/
void Joueur::setMatchsJoues(unsigned int matchJoues)
{
	matchsJoues_ = matchJoues;
}
/**
 * @brief Setter du nombre de buts
*/
void Joueur::setButs(unsigned int buts )
{
	buts_ = buts;
}
/**
 * @brief Setter du nombre d'assists
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
 * @brief Getter du nombre d'assits du joueur
 * @return Un int de nombre d'assists du joueur
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
 * @brief Surcharge de < pour Equipe
 * @param reference a un individu
 * @return bool true ou false
*/
bool Joueur::operator <(const Joueur& ind)
{
    return (buts_< ind.buts_ || assists_< ind.assists_);
}


// La fonction globale operator << pour ajouter l’affichage des nouveaux attributs.
// printAttendu = "Andrew 13 10 3 15 21\n";

/**
 * @brief Affichage de l'objet de classe Joueur
 * @param os
 * @param individu Individu a afficher
 * @return un reference a un objet de classe ostream, affichage
*/
ostream& operator<<(ostream& os, const Joueur& individu)
{
	return os << individu.getNom() << ' ' << individu.getMatchsJoues() << ' ' 
		<< individu.getButs() << ' ' << individu.getAssists() << ' ' << individu.getAttaque() << ' ' << individu.getDefense() << "\n";
}

 