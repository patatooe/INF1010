/************************************************************************************
*	Fichier					: Equipe.h
*	Auteurs					: Patricia Manarazan (1942503), Robin Plamondon (2119689)
*	Description				: Declaration de la classe Equipe
*	Date de creation		: 2022/06/31
*	Date de modification	: 2022/06/31
************************************************************************************/

#ifndef JOUEUR_
#define JOUEUR_

#include <string>
using namespace std;
#include <memory>
class Joueur
{
public:
	Joueur();
    Joueur(string nom, unsigned int matchsJoues, 
        unsigned int buts, unsigned int assists,
         double attaque, double defense);
	~Joueur();
	void setNom(string nom);
    void setMatchsJoues(unsigned int matchsJoues);
    void setButs(unsigned int buts);
    void setAssists(unsigned int assists);
    // TP3
    void setAttaque(double attaque);
    void setDefense(double defense);

	string getNom() const;
    unsigned int  getMatchsJoues() const;
    unsigned int  getButs() const;
    unsigned int  getAssists() const;
    bool operator <(const Joueur& ind);

    // TP3
    double getAttaque() const;
    double getDefense() const;

    friend ostream& operator<<(ostream& os, const Joueur& individu);

protected:
    string nom_;
    unsigned int matchsJoues_;
    unsigned int buts_;
    unsigned int assists_;
    // TP3
    double attaque_;
    double defense_;
};

#endif
