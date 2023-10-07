#ifndef EQUIPE_
#define EQUIPE_

#include <vector>
#include <memory>
#include <iostream>
#include "Joueur.h"
#include "Date.h"
#include "foncteurs.h"

//TODO: Ajouter la classe au mod�le QT
class Equipe
{

public:
    Equipe(const std::string& nom, unsigned int jour, 
	             unsigned int mois, unsigned int annee );
	Equipe(const string& nom = "inconnu");
	Equipe (const Equipe& eq);	
	Equipe& operator=(const Equipe& eq);

    std::string getNom() const;
	Date getDate() const;
	int getNombreVictoires() const;
	int getNombreJoueurs() const;
	//Retourne le joueur correspondant s'il existe, sinon retourne nullptr
	std::shared_ptr<Joueur> getJoueur(const std::string& joueur) const;
	//Retourne tous les joueurs tri�s par nom
	std::vector<std::shared_ptr<Joueur>> getJoueurs();

	//Calcul la force d'attaque compl�te de l'�quipe
	double calculAttaque() const;
	//Calcul la force de d�fense compl�te de l'�quipe
	double calculDefense() const;

	//Ajoute un joueur � l'�quipe s'il n'existe pas d�j�
	Equipe& operator+= (const std::shared_ptr<Joueur>& individu);
	//Retire un joueur de l'�quipe s'il existe
    Equipe& operator-=(const std::string& nomJoueur);
	Equipe& operator++();
    friend std::ostream& operator<<(std::ostream& os, const Equipe& eq);

// TODO: Ajouter le signal joueurAjoutee qui prend une r�f�rence constante de string comme param�tre

private:
	std::string nom_;
	unsigned int victoire_;
	// Tous les joueurs de l'�quipe
	std::vector<std::shared_ptr <Joueur> > joueurs_;
	std::unique_ptr<Date> dateDeCreation_;
};
#endif
