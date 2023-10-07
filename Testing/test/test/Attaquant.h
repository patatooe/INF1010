#ifndef ATTAQUANT_
#define ATTAQUANT_

#include "Joueur.h"
#include <string>
#include <iostream>

class Attaquant : public Joueur
{
public:
    virtual ~Attaquant() = default;
    Attaquant(const std::string& nom = "inconnu", unsigned int matchsJoues = 0,
        unsigned int buts = 0, unsigned int assists = 0,
        double attaque = 1.0, double defense = 0.3,
        double vitesse = 1.0, double agilite = 0.8, double precision = 1.0);

    double getAttaque() const override;
    double getDefense() const override;
    double getVitesse() const;
    double getAgilite() const;
    double getPrecision() const;

    friend std::ostream& operator<<(std::ostream& os, const Attaquant& individu);
private:
    double vitesse_;
    double agilite_;
    double precision_;
};

#endif
