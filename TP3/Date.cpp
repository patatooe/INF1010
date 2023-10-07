/************************************************************************************
*	Fichier					: Date.cpp
*	Auteurs					: Patricia Manarazan (1942503), Robin Plamondon (2119689)
*	Description				: Implementation de la classe Date
*	Date de creation		: 2022/10/31
*	Date de modification	: 2022/10/31
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
 * @brief Constructeur par parametres d'un objet de classe Date
 * @param reference a une date
*/
Date::Date(const Date &  d): jour_(d.jour_), mois_(d.mois_), annee_(d.annee_)
{}
/**
 * @brief Destructeur d'un ojet de classe Date
*/
Date::~Date()
{
}
/**
 * @brief Surcharge de < pour date
 * @param d Date sur laquelle < est utilise
 * @return false si qlq chose est plus petit, true si c'est plus grand
*/
bool Date::operator < (const Date& d) const
{
    if (annee_ == d.annee_)
    {
        if (mois_ == d.mois_)
            return jour_ < d.jour_;
        else
            return mois_ < d.mois_;
    }
    else
        return annee_ < d.annee_;
}
/**
 * @brief Surcharge de + pour Date
 * @param nbJours Nombre de jours a ajouter a la date
 * @return Un objet de type Date
*/
Date Date::operator+(unsigned int nbJours)
{
    Date temp(*this);
    temp.jour_ += nbJours;
    while (temp.jour_ > NBJOURDANSMOIS[temp.mois_])
    {
        temp.jour_ -= NBJOURDANSMOIS[temp.mois_];
        temp.mois_++;
        if (temp.mois_ > 12)
        {
            temp.mois_ = 1;
            temp.annee_++;
        }
    }
    return temp;
}
/**
 * @brief Surcharge de += pour Date
 * @param nbJours Nombre de jours a ajouter a la date
 * @return Reference a l'objet de classe date
*/
Date& Date::operator+=(unsigned int nbJours)
{
    return *this = *this + nbJours;
}
/**
 * @brief Surcharge de ++ pour Date
 * @return Reference a l'objet de classe Date
*/
Date& Date::operator++()
{
    return *this = *this + 1;
}
/**
 * @brief Surcharge de << pour Date, affichage de la date
 * @param os
 * @param d
 * @return Reference a objet de type ostream, affichage de la date
*/
ostream& operator<<(ostream& os, const Date& d)
{
    os << d.annee_ << "-" << d.mois_ << "-" << d.jour_ << endl;
    return os;
}
