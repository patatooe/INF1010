/************************************************************************************
*	Fichier					: Equipe.cpp
*	Auteurs					: Patricia Manarazan (1942503), Robin Plamondon (2119689)
*	Description				: Implementation de la classe Equipe
*	Date de creation		: 2022/10/31
*	Date de modification	: 2022/10/31
************************************************************************************/

#include "Equipe.h"
#include <iostream>

using namespace std;
/**
 * @brief Fonction qui donne un double random dans un range
 * @return double 
*/
static double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}
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
 * @brief Constructeur par parametre d'un objet de classe Equipe
 * @param pointeur a l'equipe
*/
 Equipe::Equipe (const Equipe & eq)
 {
    nom_ = eq.nom_;
    victoire_ = eq.victoire_;
    joueurs_ = eq.joueurs_;
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
Equipe& Equipe::operator =(const Equipe& eq)
{
    if (this != &eq)
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
Equipe  Equipe:: operator+(shared_ptr<Joueur> individu)
{   Equipe eq (*this);
    for ( auto joueur: eq.joueurs_) 
    {
        if (joueur->getNom() == individu->getNom()) 
            return eq ;   
    }
        eq.joueurs_.push_back(individu);  
        return eq;  
}

/**
 * @brief Surcharge de - pour Equipe
 * @param nomJoueur individu Objet de classe Joueur qui sera enleve de l'equipe
 * @return Un objet de classe Equipe
*/
Equipe Equipe::operator-(string nomJoueur)
{   Equipe eq(*this);
    for  (int  i =  0 ; i < eq.joueurs_.size(); i++)
        if (eq.joueurs_[i]->getNom() == nomJoueur){
            eq.joueurs_[i] =eq.joueurs_.back();
            eq.joueurs_.pop_back();
           return eq;
        }
   return eq;           
}

/**
 * @brief Surcharge de ++ pour Equipe
 * @param individu Objet de classe Joueur qui sera ajoute aux joueurs deja dans l'equipe
 * @return Un objet de classe Equipe
*/
Equipe & Equipe::operator++()
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
    return joueurs_.size();
}


/**
 * @brief Getter du joueur dans l'equipe
 * @return shared_ptr du joueur 
*/
shared_ptr<Joueur> Equipe::getJoueur(string nomJoueur) const
{
    for (int i = 0; i < joueurs_.size(); i++)
    {
        if (joueurs_[i]->getNom() == nomJoueur)
        {
            return joueurs_[i];
        }
    }
    return nullptr;
}

/**
 * @brief Cette méthode parcourt tous les joueurs de l’équipe(gardien, defenseur et attaquant), 
 somme toute la force d’attaque des joueurs. Chaque valeur des attaques est multipliée par une valeur aléatoire 
 entre[0.8, 1.8] avant de l’ajouter à la somme.
 * @return double pour la force d'attaque des joueurs
*/
double Equipe::calculAttaque() const 
{
    double sommeAttaque = 0;

    for (auto & elem : this->joueurs_) {
        sommeAttaque = +elem->getAttaque()*fRand(0.8, 1.8);
    }
    return sommeAttaque;
}

/**
 * @brief Cette méthode parcourt tous les joueurs de l’équipe(gardien, defenseur et attaquant), somme 
 toute la force des défenses des joueurs.Chaque valeur des défenses est multipliée par une valeur aléatoire 
 entre[0.4, 1.5] avant de l’ajouter à la somme.
 * @return double pour la force de defense des joueurs
*/
double Equipe::calculDefense() const 
{
    double sommeDefense = 0;
    for (auto& elem : this->joueurs_) {
        sommeDefense = +elem->getDefense() * fRand(0.4, 1.5);
    }
    return sommeDefense; 
}

/**
 * @brief Getter pour joueurs
 * @return vetor of shared_ptr
*/
 vector<shared_ptr <Joueur> >  Equipe::getJoueurs()
 {
     return joueurs_;
 }

 /**
 * @brief Surcharge de l'operateur<< pour afficher le nom de l’équipe, les joueurs, le nombre de victoires, la somme de la force d’attaque de 
 l’équipe, et la somme de la force de défense de l’équipe.
 * @param os
 * @param eq Equipe a etre affiche
 * @return reference a un objet de classe ostream, affichage
*/
ostream& operator<<(ostream& os, const Equipe& eq)
{
    os << eq.getNom() << '\n';
    os << "Joueurs : " << endl;
    for (auto& elem : eq.joueurs_) {
        os << *elem;
    }
    os << "Nombre de victoire>>s : " << eq.getNombreVictoire() << '\n';
    os << "Somme de la force d'attaque " << eq.calculAttaque() << '\n';
    os << "Somme de la  force de defense " << eq.calculDefense() << '\n';
    return os;
}


 