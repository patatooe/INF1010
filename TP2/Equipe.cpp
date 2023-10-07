/************************************************************************************
*	Fichier					: Equipe.cpp
*	Auteurs					: Patricia Manarazan (1942503), Robin Plamondon (2119689)
*	Description				: Implementation de la classe Equipe
*	Date de creation		: 2022/10/06
*	Date de modification	: 2022/10/06
************************************************************************************/

#include "Equipe.h"
#include <iostream>

using namespace std;

/**
 * @brief Constructeur par defaut d'un objet de classe Equipe
*/
Equipe::Equipe(): Equipe("inconnue", 01, 01, 2022)
{
}

/**
 * @brief Constructeur par parametre d'un objet de classe Equipe
 * @param nom Nom de l'equipe
 * @param jour d'une Date
 * @param mois d'une Date
 * @param annee d'une Date
*/
Equipe::Equipe(string nom,  unsigned int jour,
                            unsigned int mois, unsigned int annee):
    victoire_(0),
    nom_(nom),
    dateDeCreation_(make_unique<Date>(jour, mois, annee))
{
}

/**
 * @brief Constructeur de copie
 * @param eq Objet de classe Equipe a copier
*/
Equipe :: Equipe (const Equipe & eq) : nom_(eq.nom_), victoire_(eq.victoire_), joueurs_(eq.joueurs_)
{
    dateDeCreation_ = make_unique<Date>(*eq.dateDeCreation_);
}

/**
 * @brief Destructeur d'un objet de classe Equipe
*/
Equipe::~Equipe()
{
}

/**
 * @brief Surcharge de = pour Equipe
 * @param eq Objet de classe equipe sur lequel = agit
 * @return Reference a l'objet de classe Equipe
*/
Equipe& Equipe :: operator =(const Equipe& eq)
{
    if(this != &eq)
    {
        nom_ = eq.nom_;
        victoire_ = eq.victoire_;
        joueurs_ = eq.joueurs_;

        dateDeCreation_ = make_unique<Date>(*eq.dateDeCreation_);
    }
    return *this;
}

/**
 * @brief Surcharge de + pour Equipe
 * @param individu Objet de classe Joueur qui sera ajoute aux joueurs deja dans l'equipe
 * @return Un objet de classe Equipe
*/
Equipe  Equipe :: operator + (shared_ptr <Joueur> individu)
{
    bool present = false;
    for(auto& j : this->joueurs_)
    {
        if(individu == j)
            present = true;
    }
    if(!present)
        joueurs_.push_back(individu);
    
    return *this;
}

/**
 * @brief Surcharge de - pour Equipe
 * @param nomJoueur individu Objet de classe Joueur qui sera enleve de l'equipe
 * @return Un objet de classe Equipe
*/
Equipe Equipe :: operator - (string nomJoueur)
{
    for (int i = 0; i < this->joueurs_.size(); i++) {

        if (nomJoueur == this->joueurs_[i]->getNom()) {

            this->joueurs_.erase(this->joueurs_.begin() + i);

            return *this;
        }
    }

    return *this;
}

/**
 * @brief Surcharge de ++ pour Equipe
 * @return Une reference a l'objet de classe Equipe
*/
Equipe & Equipe :: operator++()
{
    victoire_++;
    return *this;

}

/**
 * @brief Getter pour le nom de l'equipe
 * @return Un string du nom de l'equipe
*/
string Equipe::getNom() const
{
	return nom_;
}

/**
 * @brief Getter du nombre de victoires de l'equipe
 * @return Un int du nombre de victoires de l'equipe
*/
int Equipe::getNombreVictoire() const
{
	return victoire_;
}

/**
 * @brief Getter du nombre de joueurs dans l'equipe
 * @return int du nombre de joueurs de l'equipe
*/
int Equipe::getNombreJoueurs() const
{
   return size(joueurs_);
}

/**
 * @brief Getter des joueurs de l'equipe qui sont de objets de classe Joueur
 * @param nomJoueur 
 * @return Un shared pointer de l'objet de classe Joueur
*/
shared_ptr<Joueur> Equipe::getJoueur(string nomJoueur) const
{
    for(auto j : joueurs_)
    {
        if (nomJoueur == j->getNom())
            return j;
    }

    return nullptr;     
}

/**
 * @brief Affichage de l'equipe
 * @param os 
 * @param eq Equipe a etre affiche
 * @return reference a un objet de classe ostream, affichage
*/
ostream& operator<<(ostream& os, const Equipe& eq)
{
    os << eq.nom_ << endl  << "Joueurs: " << endl;

    for (auto j : eq.joueurs_) {
        os << j->getNom() << " " << j->getMatchsJoues() << " " << j->getButs() << " " << j->getAssists() << endl;
    }
    os << "Nombre de victoires>>s : " << eq.getNombreVictoire() << endl;
    return os;
}
