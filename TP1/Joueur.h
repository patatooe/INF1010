/************************************************************************************
*	Fichier					: Joueur.h
*	Auteurs					: Patricia Manarazan (1942503), Robin Plamondon (2119689)
*	Description				: Classe Joueur
*	Date de creation		: 09/18/2022
*	Date de modification	: 09/18/2022
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
    Joueur(string nom, unsigned int matchsJou�s, 
        unsigned int buts, unsigned int assists);
	~Joueur();
	void setNom(string nom);
    void setMatchsJou�s(unsigned int matchsJou�s);
    void setButs(unsigned int buts);
    void setAssists(unsigned int assists);

	string getNom() const;
    unsigned int  getMatchsJou�s() const;
    unsigned int  getButs() const;
    unsigned int  getAssists() const;

    void afficher() const;

protected:
    string nom_;
    unsigned int matchsJou�s_;
    unsigned int buts_;
    unsigned int assists_;
};

#endif
