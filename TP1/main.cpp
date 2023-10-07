/************************************************************************************
*	Fichier					: main.cpp
*	Auteurs					: Patricia Manarazan (1942503), Robin Plamondon (2119689)
*	Description				: Main et appel des test
*	Date de creation		: 09/18/2022
*	Date de modification	: 09/18/2022
************************************************************************************/

#include <iostream>
#include "Equipe.h"
#include "Joueur.h"
#include "Tests.h"
#include <memory>

using namespace std;

int main()
{   
    srand((unsigned)time(NULL));  
    Tests::testAll();
   
}

