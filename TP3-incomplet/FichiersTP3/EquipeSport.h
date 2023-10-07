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
