#ifndef EQUIPE_
#define EQUIPE_

#include <vector>
#include <memory>
#include <iostream>
#include "Joueur.h"
#include "Date.h"
#include "foncteurs.h"

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
	//Retourne tous les joueurs triés par nom
	std::vector<std::shared_ptr<Joueur>> getJoueurs();

	//Calcul la force d'attaque complète de l'équipe
	double calculAttaque() const;
	//Calcul la force de défense complète de l'équipe
	double calculDefense() const;

	//Ajoute un joueur à l'équipe s'il n'existe pas déjà
	Equipe operator+ (const std::shared_ptr<Joueur>& individu) const;
	//Retire un joueur de l'équipe s'il existe
    Equipe operator-(const std::string& nomJoueur) const;
	Equipe& operator++();
    friend std::ostream& operator<<(std::ostream& os, const Equipe& eq);

private:
	std::string nom_;
	unsigned int victoire_;
	// Tous les joueurs de l'équipe
	std::vector<std::shared_ptr <Joueur> > joueurs_;
	std::unique_ptr<Date> dateDeCreation_;
};
#endif
