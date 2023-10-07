#ifndef JOUEUR_
#define JOUEUR_

#include <string>
#include <iostream>

class Joueur
{
public:
    virtual ~Joueur() = default;
    Joueur(const std::string& nom = "inconnu", unsigned int matchsJoues = 0, 
        unsigned int buts = 0, unsigned int assists = 0,
         double attaque = 0.0, double defense = 0.0);

	void setNom(const std::string& nom);
    void setMatchsJoues(unsigned int matchsJoues);
    void setButs(unsigned int buts);
    void setAssists(unsigned int assists);
    void setAttaque(double attaque);
    void setDefense(double defense);

	std::string getNom() const;
    unsigned int  getMatchsJoues() const;
    unsigned int  getButs() const;
    unsigned int  getAssists() const;
    virtual double getAttaque() const;
    virtual double getDefense() const;

    bool operator <(const Joueur& ind);
    friend std::ostream& operator<<(std::ostream& os, const Joueur& individu);

private:
    std::string nom_;
    unsigned int matchsJoues_;
    unsigned int buts_;
    unsigned int assists_;
    double attaque_;
    double defense_;
};

#endif
