/************************************************************************************
*	Fichier					: Date.cpp
*	Auteurs					: Patricia Manarazan (1942503), Robin Plamondon (2119689)
*	Description				: Implementation de la classe Date
*	Date de creation		: 2022/10/06
*	Date de modification	: 2022/10/06
************************************************************************************/

#include "Date.h"
/**
 * @brief Constructeur par defaut d'un objet de classe Date
*/
Date::Date()
{
    annee_ = mois_ = jour_ = 0;
}

/**
 * @brief Constructeur par parametres d'un objet de classe Date
 * @param jour Jour de l'objet Date
 * @param mois Mois de l'objet Date
 * @param annee Annee de l'objet Date
*/
Date::Date(unsigned int jour, unsigned int mois, unsigned int annee)
    : jour_(jour), mois_(mois), annee_(annee)
{
}

/**
 * @brief Destructeur d'un ojet de classe Date
*/
Date::~Date()
{
}

/**
 * @brief Contructeur par copie d'un objet de classe Date
 * @param d Date a copier
*/
Date :: Date(const Date &  d): jour_(d.jour_), mois_(d.mois_), annee_(d.annee_) {}

/**
 * @brief Surcharge de < pour date
 * @param d Date sur laquelle < est utilise
 * @return false si qlq chose est plus petit, true si c'est plu grand
*/
bool Date :: operator<(const Date& d) const{

    if(annee_ == d.annee_){
        if(mois_ == d.mois_){
            if(jour_ < d.jour_)
                return true;
            else
                false;
        }
        if(mois_ < d.mois_)
            return true;
        else
            return false;
    }

    if(annee_ < d.annee_)
        return true;
    else
        return false;
}

/**
 * @brief Surcharge de + pour Date
 * @param nbJours Nombre de jours a ajouter a la date
 * @return Un objet de type Date
*/
Date Date :: operator+(unsigned int nbJours){
    Date temp = *this;

    return temp += nbJours;
}

/**
 * @brief Surcharge de += pour Date
 * @param nbJours Nombre de jours a ajouter a la date
 * @return Reference a l'objet de classe date
*/
Date& Date :: operator+=(unsigned int nbJours){

    for (int i = 0; i < nbJours; i++) {
        jour_ = jour_ + 1;
        if (jour_ > NBJOURDANSMOIS[mois_ - 1]) {
            mois_ = mois_ + 1;
            jour_ = 1;
            if (mois_ > 12) {
                mois_ = 1;
                annee_ = annee_ + 1;
            }
        }
    }

    return *this;
}

/**
 * @brief Surcharge de ++ pour Date
 * @return Reference a l'objet de classe Date
*/
Date& Date :: operator++(){

    return *this = *this + 1;
}

/**
 * @brief Surcharge de << pour Date, affichage de la date
 * @param os 
 * @param d 
 * @return Reference a objet de type ostream, affichage de la date
*/
ostream& operator<<(ostream& os, const Date& d){

    return os << d.annee_ << '-' << d.mois_ << '-' << d.jour_ << endl;
}