#ifndef DEFENSEUR_H_
#define DEFENSEUR_H_

#include "Joueur.h"
#include <string>
#include <iostream>

class Defenseur: public Joueur
{
public:
	virtual ~Defenseur() = default;
    Defenseur(	const std::string& nom = "inconnu",unsigned int matchsJoues = 0, 
				unsigned int buts = 0, unsigned int assists = 0,
				double attaque = 0.1, double defense = 0.9, 
				double reactivite = 0.8, double vision = 1.0);
 
	double getAttaque() const override;
    double getDefense() const override;
	double getReactivite() const;
	double getVision() const;

	friend std::ostream& operator<<(std::ostream& os, const Defenseur& individu);

private:
	double reactivite_;
	double vision_;
};

#endif


