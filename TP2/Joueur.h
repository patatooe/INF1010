/************************************************************************************
*	Fichier					: Joueur.h
*	Auteurs					: Patricia Manarazan (1942503), Robin Plamondon (2119689)
*	Description				: Declaration de la classe Joueur
*	Date de creation		: 2022/06/10
*	Date de modification	: 2022/06/10
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
        unsigned int buts, unsigned int assists);
	~Joueur();
	void setNom(string nom);
    void setMatchsJoues(unsigned int matchsJoues);
    void setButs(unsigned int buts);
    void setAssists(unsigned int assists);

	string getNom() const;
    unsigned int  getMatchsJoues() const;
    unsigned int  getButs() const;
    unsigned int  getAssists() const;
    bool operator <(const Joueur& ind);
    friend ostream& operator<<(ostream& os, const Joueur& individu);

protected:
    string nom_;
    unsigned int matchsJoues_;
    unsigned int buts_;
    unsigned int assists_;
};

#endif
