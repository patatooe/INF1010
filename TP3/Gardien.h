/************************************************************************************
*	Fichier					: Guardien.h
*	Auteurs					: Patricia Manarazan (1942503), Robin Plamondon (2119689)
*	Description				: Declaration de la classe Guardien
*	Date de creation		: 2022/06/31
*	Date de modification	: 2022/06/31
************************************************************************************/

#ifndef GARDIEN_H_
#define GARDIEN_H_

#include "Joueur.h"
#include <string>
#include <iostream>
using namespace std;

class Gardien: public Joueur
{
public:
	Gardien();
    Gardien( string nom, unsigned int matchsJoues, 
        unsigned int buts, unsigned int assists,
         double attaque, double defense, double stabilite, double reflexe);
	~Gardien();

	double getAttaque() const;
    double getDefense() const;
	
	double getStabilite() const;
	double getReflexe() const;

	friend ostream& operator<<(ostream& os, const Gardien & individu);

private:
	double stabilite_;
	double reflexe_;
};

#endif

