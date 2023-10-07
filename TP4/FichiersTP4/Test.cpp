#include "Date.h"
#include "Defenseur.h"
#include "Equipe.h"
#include "Gardien.h"
#include "Joueur.h"
#include "Match.h"
#include "Attaquant.h"
#include "Tournoi.h"
#include "foncteurs.h"
#include "Test.h"
#include <random>

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>

using namespace std;

/// Affiche le nom d'un test ainsi que son �tat de passage � l'�cran.
/// \param index        L'index du test.
/// \param nom          Le nom du test.
/// \param estReussi    L'�tat de passage du test.
void afficherResultatTest(const std::string& nom, bool estReussi)
{
	static int numeroTest = 0;
	static constexpr int largeurNumeroTest = 2;
	static constexpr int largeurNomTest = 80;
	std::cout << "Test " << std::right << std::setw(largeurNumeroTest) << ++numeroTest << ": " << std::left << std::setw(largeurNomTest)
		<< nom << ": " << (estReussi ? "OK" : "FAILED") << '\n';
}

/// Affiche un header pour chaque section de tests � l'�cran.
/// \param nomSectionTest   Le nom de la section de tests.
void afficherHeaderTest(const std::string& nomSectionTest) { std::cout << "\nTests pour " + nomSectionTest + ":\n--------\n"; }

/// Affiche un footer avec les points pour chaque section de tests � l'�cran.
/// \param totalPoints  Le nombre de points obtenus � la section de tests.
/// \param maxPoints    Le nombre de points maximal allou�s � la section de tests.
void afficherFooterTest(int totalPoints, int maxPoints)
{
	std::cout << "--------\nTotal des tests qui passent pour la section: " << totalPoints << "/" << maxPoints << " tests" << '\n';
}

/// prend un vecteur de booleen
/// renvoi true si tou le vecteur est true, false dans le cas contraire
/// \param testReussis vecteur de booleen contenant la decision sur les tests
bool decision(vector<bool> testReussis)
{
	for (int i = 0; i < testReussis.size(); i++)
	{
		if (testReussis[i] == false)
		{
			return false;
		}
	}
	return true;
}

double tests_class_foncteurs()
{
	vector<bool> testsReussis;
	afficherHeaderTest("classe foncteurs");

	// setup equipes et matchs
	Equipe equipeA = Equipe("Golden State Warriors", 12, 6, 2017);
	++equipeA; ++equipeA;

	Equipe equipeB = Equipe("Chicago Bulls", 15, 6, 1996);
	++equipeB;

	Equipe equipeC = Equipe("Boston Celtics", 7, 6, 1986);
	++equipeC; ++equipeC; ++equipeC; ++equipeC;
	
	Match nbaFinals1 = Match(Date(14, 6, 1998), make_shared<Equipe>(equipeB), make_shared<Equipe>(equipeC));
	Match nbaFinals2 = Match(Date(22, 6, 2001), make_shared<Equipe>(equipeA), make_shared<Equipe>(equipeB));

	// test foncteur ComparerParVictoires
	FoncteurComparerParVictoires<Equipe> foncteurVictoires;
	bool estInferieur = equipeA.getNombreVictoires() < equipeC.getNombreVictoires();
	bool estSuperieur = equipeB.getNombreVictoires() > equipeA.getNombreVictoires();
	testsReussis.push_back(estInferieur && foncteurVictoires(make_shared<Equipe>(equipeA), make_shared<Equipe>(equipeC)));
	testsReussis.push_back(!estSuperieur && !foncteurVictoires(make_shared<Equipe>(equipeC), make_shared<Equipe>(equipeB)));
	afficherResultatTest("FoncteurComparerParVictoires de la classe foncteur", decision(testsReussis));

	// test foncteur ComparerParNom
	FoncteurComparerParNom<Equipe> foncteurNoms;
	estSuperieur = equipeA.getNom() < equipeC.getNom();
	estInferieur = equipeC.getNom() < equipeB.getNom();
	testsReussis.push_back(!estSuperieur && !foncteurNoms(make_unique<Equipe>(equipeA), make_unique<Equipe>(equipeC)));
	testsReussis.push_back(estInferieur && foncteurNoms(make_shared<Equipe>(equipeC), make_shared<Equipe>(equipeB)));
	afficherResultatTest("FoncteurComparerParNom de la classe foncteur", decision(testsReussis));

	// test foncteur ComparerParDate
	FoncteurComparerParDate<Equipe> foncteurEquipeDate;
	FoncteurComparerParDate<Match> foncteurMatchDate;
	estInferieur = equipeB.getDate() < equipeA.getDate();
	estSuperieur = equipeA.getDate() < equipeC.getDate();
	testsReussis.push_back(estInferieur && foncteurEquipeDate(make_shared<Equipe>(equipeB), make_shared<Equipe>(equipeA)));
	testsReussis.push_back(!estSuperieur && !foncteurEquipeDate(make_unique<Equipe>(equipeA), make_unique<Equipe>(equipeC)));
	estInferieur = nbaFinals1.getDate() < nbaFinals2.getDate();
	estSuperieur = nbaFinals2.getDate() < nbaFinals1.getDate();
	testsReussis.push_back(estInferieur && foncteurMatchDate(make_shared<Match>(nbaFinals1), make_shared<Match>(nbaFinals2)));
	testsReussis.push_back(!estSuperieur && !foncteurMatchDate(make_shared<Match>(nbaFinals2), make_shared<Match>(nbaFinals1)));
	afficherResultatTest("FoncteurComparerParDate de la classe foncteur", decision(testsReussis));

	int nombreTestsReussis = static_cast<int>(std::count(testsReussis.begin(), testsReussis.end(), true));
	afficherFooterTest(nombreTestsReussis, static_cast<int>(testsReussis.size()));
	return nombreTestsReussis;
}

double tests_classe_equipe()
{
	vector<bool> testsReussis;
	afficherHeaderTest("classe Equipe");

	// test constructeur et getters
	Equipe equipe1 = Equipe("Canadiens de Montreal", 11, 9, 2001);
	testsReussis.push_back(equipe1.getNombreVictoires() == 0);
	testsReussis.push_back(equipe1.getNom() == "Canadiens de Montreal");
	testsReussis.push_back(equipe1.getJoueurs().size() == 0);
	testsReussis.push_back(equipe1.getJoueur("Shea") == nullptr);

	Equipe equipe2(equipe1);
	testsReussis.push_back(equipe2.getNom() == "Canadiens de Montreal");
	afficherResultatTest("Constructeurs de la classe Equipe", decision(testsReussis));

	shared_ptr<Joueur> joueur1 = make_shared<Joueur>("Stanley", 10, 5, 6, 12, 15);
	shared_ptr<Joueur> joueur2 = make_shared<Joueur>("Shea", 81, 23, 30, 85, 80);
	shared_ptr<Joueur> joueur3 = make_shared<Joueur>("Joueur3", 82, 21, 40, 13, 60);
	shared_ptr<Joueur> joueur4 = make_shared<Joueur>("Joueur4", 82, 21, 40, 77, 89);
	shared_ptr<Joueur> joueur5 = make_shared<Joueur>("Joueur5", 82, 21, 40, 60.5, 45.4);

	// test operator+
	equipe1 = equipe1 + joueur1;
	equipe1 = equipe1 + joueur2;
	equipe1 = equipe1 + joueur3;
	equipe1 = equipe1 + joueur4;
	equipe1 = equipe1 + joueur5;

	Equipe equipe3 = equipe1;
	std::vector<shared_ptr<Joueur>> joueurs = vector<shared_ptr<Joueur>>();
	joueurs.push_back(joueur3); joueurs.push_back(joueur4); joueurs.push_back(joueur5); joueurs.push_back(joueur2); joueurs.push_back(joueur1);
	testsReussis.push_back(equipe3.getJoueurs() == joueurs && equipe3.getJoueurs().size() == joueurs.size() && 
		equipe3.getJoueur("Shea") == joueur2 && equipe3.getJoueur("inexistant") == nullptr);
	afficherResultatTest("Operateur+ et Getters de la classe Equipe", decision(testsReussis));

	// test operator-
	equipe3 = equipe3 - "joueur5";
	equipe3 = equipe3 - "Shea";
	equipe2 = equipe3;
	testsReussis.push_back((equipe2.getJoueur("Shea") == nullptr) && (equipe2.getJoueur("Joueur3") == joueur3));
	afficherResultatTest("Operateur- et Getters de la classe Equipe", decision(testsReussis));

	// test calcul attaque
	
	// test calcul defense 

	int nombreTestsReussis = static_cast<int>(std::count(testsReussis.begin(), testsReussis.end(), true));
	afficherFooterTest(nombreTestsReussis, static_cast<int>(testsReussis.size()));
	return nombreTestsReussis;
}

double tests_classe_tournoi()
{
	vector<bool> testsReussis;
	afficherHeaderTest("classe Tournoi");

	// setup tournoi et équipes et matchs
	Equipe equipeA = Equipe("Golden State Warriors", 12, 6, 2017);

	Equipe equipeB = Equipe("Chicago Bulls", 15, 6, 1996);

	Equipe equipeC = Equipe("Miami Heat", 20, 6, 2013);

	shared_ptr<Equipe> equipeA1 = make_shared<Equipe>(equipeA);
	shared_ptr<Equipe> equipeB1 = make_shared<Equipe>(equipeB);
	shared_ptr<Equipe> equipeC1 = make_shared<Equipe>(equipeC);

	shared_ptr<Match> nbaFinals1 = make_shared<Match>(Date(14, 6, 1998), equipeB1, equipeC1);
	shared_ptr<Match> nbaFinals2 = make_shared<Match>(Date(12, 6, 2001), equipeA1, equipeB1);
	shared_ptr<Match> nbaFinals3 = make_shared<Match>(Date(12, 6, 2001), equipeA1, equipeC1);

	Tournoi nbaPlayoffs;

	// test ajouterEquipe
	testsReussis.push_back(nbaPlayoffs.ajouterEquipe(equipeA1));
	testsReussis.push_back(nbaPlayoffs.ajouterEquipe(equipeB1));
	testsReussis.push_back(nbaPlayoffs.ajouterEquipe(equipeC1));
	testsReussis.push_back(!nbaPlayoffs.ajouterEquipe(equipeA1));
	afficherResultatTest("ajouterEquipe de la classe Tournoi", decision(testsReussis));

	// test ajouterMatch
	testsReussis.push_back(nbaPlayoffs.ajouterMatch(nbaFinals1));
	testsReussis.push_back(nbaPlayoffs.ajouterMatch(nbaFinals3));
	testsReussis.push_back(nbaPlayoffs.ajouterMatch(nbaFinals2));
	afficherResultatTest("ajouterMatch de la classe Tournoi", decision(testsReussis));

	// test getMatchParDate
	testsReussis.push_back(nbaPlayoffs.getMatchsParDate(Date(14, 6, 1999)).size() == 0);
	testsReussis.push_back(nbaPlayoffs.getMatchsParDate(Date(12, 6, 2001)).size() == 2);
	afficherResultatTest("getMatchParDate de la classe Tournoi", decision(testsReussis));

	// test getEquipes
	testsReussis.push_back(nbaPlayoffs.getEquipes().front()->getNom() == "Chicago Bulls");
	testsReussis.push_back(nbaPlayoffs.getEquipes().back()->getNom() == "Miami Heat");
	afficherResultatTest("getEquipes de la classe Tournoi", decision(testsReussis));

	

	int nombreTestsReussis = static_cast<int>(std::count(testsReussis.begin(), testsReussis.end(), true));
	afficherFooterTest(nombreTestsReussis, static_cast<int>(testsReussis.size()));
	return nombreTestsReussis;
}


void runTest()
{
	static constexpr double maxPointsAll = 10.0;
	double totalPointsAll = 0.0;
	totalPointsAll += tests_class_foncteurs();
	totalPointsAll += tests_classe_equipe();
	totalPointsAll += tests_classe_tournoi();
	double  remiseADix = maxPointsAll / totalPointsAll;
	float noteFinaleSurDix = float(totalPointsAll * remiseADix);
	std::cout << "\nTotal pour tous les tests: " << noteFinaleSurDix << '/' << maxPointsAll << "  arrondi au dixieme" << '\n';
}