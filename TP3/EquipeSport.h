/************************************************************************************
*	Fichier					: EquipeSport.h
*	Auteurs					: Patricia Manarazan (1942503), Robin Plamondon (2119689)
*	Description				: Declaration de la classe EquipeSport
*	Date de creation		: 2022/06/31
*	Date de modification	: 2022/06/31
************************************************************************************/


#ifndef EQUIPESPORT_
#define EQUIPESPORT_

#include <string>
#include <iostream>
using namespace std;

class EquipeSport
{
public:
	EquipeSport(string );
    string getNom() const;
	int getNombreVictoire() const;
	EquipeSport & operator++();

	// tp3
	double calculAttaque() const; 
    double calculDefense() const; 
    friend ostream& operator<<(ostream& os, const EquipeSport& eq);

private:
	string nom_;
	unsigned int victoire_;	
};

#endif
