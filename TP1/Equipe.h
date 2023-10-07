/************************************************************************************
*	Fichier					: Equipe.h
*	Auteurs					: Patricia Manarazan (1942503), Robin Plamondon (2119689)
*	Description				: Classe Equipe
*	Date de creation		: 09/18/2022
*	Date de modification	: 09/18/2022
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
	//Equipe(); Le constructeur par defaut est inclu dans le constructeur par parametre pour ne pas repeter du code
    Equipe(string nom="inconnue", unsigned int annee=2022,
	             unsigned int mois=1, unsigned int jour=1 );
	~Equipe();
    string getNom() const;
	int getNombreVictoire() const;
	int getNombreJoueurs() const;
	shared_ptr<Joueur> getJoueur(string joueur) const;
	bool ajouterJoueur(shared_ptr <Joueur> individu); 
    bool supprimerJoueur(string nomJoueur);
	void ajouterVictoire();
    void afficher() const;

private:
	string nom_;
	unsigned int victoire_;
	// Les joueurs 
	unsigned int capacite_ = 10;
	unsigned int nbJoueurs_;
	unique_ptr <shared_ptr <Joueur>[]> joueurs_;  
	unique_ptr <Date> dateDeCreation_;
};

#endif
