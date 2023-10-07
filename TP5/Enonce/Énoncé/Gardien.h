#ifndef GARDIEN_H_
#define GARDIEN_H_

#include "Joueur.h"
#include <string>
#include <iostream>

class Gardien: public Joueur
{
public:
	virtual ~Gardien() = default;
    Gardien(const std::string& nom = "inconnu", unsigned int matchsJoues = 0, 
			unsigned int buts = 0, unsigned int assists = 0,
			double attaque = 0.1, double defense = 1.0, double stabilite = 0.9, 
			double reflexe = 1.2);

	double getAttaque() const override;
    double getDefense() const override;
	double getStabilite() const;
	double getReflexe() const;

	friend std::ostream& operator<<(std::ostream& os, const Gardien & individu);

private:
	double stabilite_;
	double reflexe_;
};

#endif

