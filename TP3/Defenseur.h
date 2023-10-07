/************************************************************************************
*	Fichier					: Defenseur.h
*	Auteurs					: Patricia Manarazan (1942503), Robin Plamondon (2119689)
*	Description				: Declaration de la classe Defenseur
*	Date de creation		: 2022/06/31
*	Date de modification	: 2022/06/31
************************************************************************************/

#ifndef DEFENSEUR_H_
#define DEFENSEUR_H_

#include "Joueur.h"
#include <string>
using namespace std;
// TP3
class Defenseur: public Joueur
{
public:
	Defenseur();
    Defenseur(string nom,unsigned int matchsJoues, 
        unsigned int buts, unsigned int assists,
         double attaque, double defense, 
	     double reactivite, double vision);
	~Defenseur();
 
	double getAttaque() const;
    double getDefense() const;
	 
	double getReactivite() const;
	double getVision() const;

	friend ostream& operator<<(ostream& os, const Defenseur& individu);

private:
	double reactivite_;
	double vision_;
};

#endif


