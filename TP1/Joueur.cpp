/************************************************************************************
*	Fichier					: Joueur.cpp
*	Auteurs					: Patricia Manarazan (1942503), Robin Plamondon (2119689)
*	Description				: Implementation de la classe Joueur
*	Date de creation		: 09/18/2022
*	Date de modification	: 09/18/2022
************************************************************************************/

#include "Joueur.h"
#include <iostream>
using namespace std;

Joueur :: Joueur() : nom_("inconnu"), matchsJou�s_(0), buts_(0), assists_(0) {

}

Joueur :: Joueur(string nom, unsigned int matchsJou�s,
    unsigned int buts, unsigned int assists) : nom_(nom), matchsJou�s_(matchsJou�s), buts_(buts), assists_(assists) {

}

Joueur :: ~Joueur() {

}

void Joueur :: setNom(string nom) {
    nom_ = nom;
}

void Joueur :: setMatchsJou�s(unsigned int matchsJou�s) {
    matchsJou�s_ = matchsJou�s;
}

void Joueur :: setButs(unsigned int buts) {
    buts_ = buts;
}

void Joueur :: setAssists(unsigned int assists) {
    assists_ = assists;
}

string Joueur::getNom() const {
    return nom_;
}

unsigned int Joueur :: getMatchsJou�s() const {
    return matchsJou�s_;
}

unsigned int Joueur :: getButs() const {
    return buts_;
}

unsigned int Joueur :: getAssists() const {
    return assists_;
}

void Joueur :: afficher() const {
    cout << nom_ << " " << matchsJou�s_ << " " << buts_ << "  " << assists_ << endl;
}
