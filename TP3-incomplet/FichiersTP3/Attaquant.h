/************************************************************************************
*	Fichier					: Attaquant.h
*	Auteurs					: 
*	Description				: Declaration de la classe Attaquant
*	Date de creation		: 
*	Date de modification	: 
************************************************************************************/

#ifndef ATTAQUANT_
#define ATTAQUANT_

#include "Joueur.h"
#include <string>
using namespace std;

class Attaquant: public Joueur
{
public:
	Attaquant();
    Attaquant(string nom, unsigned int matchsJoues, 
              unsigned int buts, unsigned int assists,
              double attaque, double defense,
	          double vitesse, double agilite, double precision);
	~Attaquant();
    
    double getAttaque() const;
    double getDefense() const;
    
    double getVitesse() const;
    double getAgilite() const;
    double getPrecision() const;

    friend ostream& operator<<(ostream& os, const Attaquant & individu);
private:
	double vitesse_;
	double agilite_;
	double precision_;
};

#endif
