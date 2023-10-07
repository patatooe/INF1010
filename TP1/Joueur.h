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
    Joueur(string nom, unsigned int matchsJoués, 
        unsigned int buts, unsigned int assists);
	~Joueur();
	void setNom(string nom);
    void setMatchsJoués(unsigned int matchsJoués);
    void setButs(unsigned int buts);
    void setAssists(unsigned int assists);

	string getNom() const;
    unsigned int  getMatchsJoués() const;
    unsigned int  getButs() const;
    unsigned int  getAssists() const;

    void afficher() const;

protected:
    string nom_;
    unsigned int matchsJoués_;
    unsigned int buts_;
    unsigned int assists_;
};

#endif
