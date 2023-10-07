/************************************************************************************
*	Fichier					: Equipe.h
*	Auteurs					: Patricia Manarazan (1942503), Robin Plamondon (2119689)
*	Description				: Declaration de la classe Equipe
*	Date de creation		: 2022/06/31
*	Date de modification	: 2022/06/31
************************************************************************************/

#ifndef EQUIPE_
#define EQUIPE_

#include <vector>
#include "Joueur.h"
#include "Date.h"
#include <memory>

using namespace std;

class Equipe
{
public:
	Equipe();
    Equipe(string nom, unsigned int jour, 
	             unsigned int mois, unsigned int annee );
	Equipe (const Equipe & eq);			  
	~Equipe();
    string getNom() const;
	int getNombreVictoire() const;
	int getNombreJoueurs() const;
	shared_ptr<Joueur> getJoueur(string joueur) const;
	Equipe& operator =(const Equipe& eq);
	Equipe operator + (shared_ptr <Joueur> individu); 
    Equipe operator -(string nomJoueur);
	Equipe & operator++();

	// tp3
	double calculAttaque() const; // somme des valeurs des attaquants + random
    double calculDefense() const; // sommes des defenses + random
    vector<shared_ptr <Joueur> >  getJoueurs();

    friend ostream& operator<<(ostream& os, const Equipe& eq);

private:
	string nom_;
	unsigned int victoire_;
	// Les joueurs 
	vector<shared_ptr <Joueur> > joueurs_;  
	unique_ptr <Date> dateDeCreation_;
};

#endif
