/************************************************************************************
*	Fichier					: Date.cpp
*	Auteurs					: Patricia Manarazan (1942503), Robin Plamondon (2119689)
*	Description				: Implementation de la classe Date
*	Date de creation		: 09/18/2022
*	Date de modification	: 09/18/2022
************************************************************************************/

//
//  Date.cpp
#include "Date.h"

//Coonstructeur par defaut
Date :: Date() : annee_(0), mois_(0), jour_(0)
{

}
//constructeur par parametre
Date :: Date(unsigned int jour, unsigned int mois, unsigned int annee) : jour_(jour), mois_(mois), annee_(annee) {

}
//Destructeur
Date :: ~Date() {

}
//Affichage de la date
void Date :: afficher() const {
	cout << jour_ << " " << mois_ << " " << annee_ << endl;
}