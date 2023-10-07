/************************************************************************************
*	Fichier					: Defenseur.h
*	Auteurs					: 
*	Description				: Declaration de la classe Defenseur
*	Date de creation		: 
*	Date de modification	: 
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


