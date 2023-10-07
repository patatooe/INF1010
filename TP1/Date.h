/************************************************************************************
*	Fichier					: Date.h
*	Auteurs					: Patricia Manarazan (1942503), Robin Plamondon (2119689)
*	Description				: Classe Date
*	Date de creation		: 09/18/2022
*	Date de modification	: 09/18/2022
************************************************************************************/


#ifndef DATE__
#define DATE__

#include <iostream>

using namespace std;

const int NBJOURDANSMOIS[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

class Date
{
public:
    Date();
    Date(unsigned int jour, unsigned int mois, unsigned int annee);
    ~Date();  
    void afficher() const;
    
private:
    unsigned int annee_;
    unsigned int mois_;
    unsigned int jour_;
};

#endif 
