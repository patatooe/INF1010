#include "Date.h"
#include "Defenseur.h"
#include "Equipe.h"
#include "EquipeSport.h"
#include "Gardien.h"
#include "Joueur.h"
#include "Match.h"
#include "Attaquant.h"
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

/// <summary>
///  Test des fonctions de la classe joueur
/// </summary>
void tests_classe_joueur()
{
	vector<bool> testsReussis;
	afficherHeaderTest("classe Joueur");

	// test constructeur par defaut
	Joueur joueur1 = Joueur();
	testsReussis.push_back(joueur1.getNom() == "inconnu");
	testsReussis.push_back(joueur1.getMatchsJoues() == 0);
	testsReussis.push_back(joueur1.getButs() == 0);
	testsReussis.push_back(joueur1.getAssists() == 0);
	testsReussis.push_back(joueur1.getAttaque() == 0);
	testsReussis.push_back(joueur1.getDefense() == 0);
	afficherResultatTest("Constructeur par defaut de la classe Joueur", decision(testsReussis));

	// test constructeur par parametres
	Joueur joueur2 = Joueur("Stanley", 10, 5, 6, 13, 2);
	testsReussis.push_back(joueur2.getNom() == "Stanley");
	testsReussis.push_back(joueur2.getMatchsJoues() == 10);
	testsReussis.push_back(joueur2.getButs() == 5);
	testsReussis.push_back(joueur2.getAssists() == 6);
	testsReussis.push_back(joueur2.getAttaque() == 13);
	testsReussis.push_back(joueur2.getDefense() == 2);
	afficherResultatTest("Constructeur par parametres de la classe Joueur", decision(testsReussis));

	// test setters et getters
	joueur2.setNom("Andrew");
	joueur2.setMatchsJoues(13);
	joueur2.setButs(10);
	joueur2.setAssists(3);
	joueur2.setAttaque(15);
	joueur2.setDefense(21);
	testsReussis.push_back(joueur2.getNom() == "Andrew");
	testsReussis.push_back(joueur2.getMatchsJoues() == 13);
	testsReussis.push_back(joueur2.getButs() == 10);
	testsReussis.push_back(joueur2.getAssists() == 3);
	testsReussis.push_back(joueur2.getAttaque() == 15);
	testsReussis.push_back(joueur2.getDefense() == 21);
	afficherResultatTest("Setteurs et getters de la classe Joueur", decision(testsReussis));

	// test operateur <<
	string printAttendu = "Andrew 13 10 3 15 21\n";
	stringstream outJoueur;
	outJoueur << joueur2;
	testsReussis.push_back(outJoueur.str() == printAttendu);
	afficherResultatTest("operateur << de la classe Joueur", decision(testsReussis));

	int nombreTestsReussis = static_cast<int>(std::count(testsReussis.begin(), testsReussis.end(), true));
	afficherFooterTest(nombreTestsReussis, testsReussis.size());
}

void tests_classe_gardien()
{
	vector<bool> testsReussis;
	afficherHeaderTest("classe Gardien");

	// test constructeur par defaut
	Gardien gardien1 = Gardien();
	testsReussis.push_back(gardien1.getNom() == "inconnu");
	testsReussis.push_back(gardien1.getMatchsJoues() == 0);
	testsReussis.push_back(gardien1.getButs() == 0);
	testsReussis.push_back(gardien1.getAssists() == 0);
	testsReussis.push_back(static_cast<Joueur>(gardien1).getAttaque() == 0.1);
	testsReussis.push_back(static_cast<Joueur>(gardien1).getDefense() == 1.0);
	testsReussis.push_back(gardien1.getStabilite() == 0.9);
	testsReussis.push_back(gardien1.getReflexe() == 1.2);
	afficherResultatTest("Constructeur par defaut de la classe Gardien", decision(testsReussis));

	// test constructeur par parametre
	Gardien gardien2 = Gardien("Andrew", 13, 10, 3, 15, 21, 0.9, 1.2);
	testsReussis.push_back(gardien2.getNom() == "Andrew");
	testsReussis.push_back(gardien2.getMatchsJoues() == 13);
	testsReussis.push_back(gardien2.getButs() == 10);
	testsReussis.push_back(gardien2.getAssists() == 3);
	testsReussis.push_back(static_cast<Joueur>(gardien2).getAttaque() == 15);
	testsReussis.push_back(static_cast<Joueur>(gardien2).getDefense() == 21);
	testsReussis.push_back(gardien2.getStabilite() == 0.9);
	testsReussis.push_back(gardien2.getReflexe() == 1.2);
	afficherResultatTest("Constructeur par parametre de la classe Gardien", decision(testsReussis));

	// test getters
	Gardien gardien3 = Gardien("Patrick", 16, 0, 2, 15, 30, 0.9, 1.2);
	testsReussis.push_back(gardien3.getNom() == "Patrick");
	testsReussis.push_back(gardien3.getMatchsJoues() == 16);
	testsReussis.push_back(gardien3.getButs() == 0);
	testsReussis.push_back(gardien3.getAssists() == 2);
	testsReussis.push_back(gardien3.getAttaque() == 12.6);
	testsReussis.push_back(gardien3.getDefense() == 31.5);
	testsReussis.push_back(gardien3.getStabilite() == 0.9);
	testsReussis.push_back(gardien3.getReflexe() == 1.2);
	afficherResultatTest("Getters de la classe Gardien", decision(testsReussis));

	// test operateur <<
	string printAttendu =  string("Gardien\n") + string("Patrick 16 0 2 15 30\n") + string(" 0.9 1.2\n");
	stringstream outGardien;
	outGardien << gardien3;
	testsReussis.push_back(outGardien.str() == printAttendu);
	afficherResultatTest("operateur << de la classe Joueur", decision(testsReussis));

	int nombreTestsReussis = static_cast<int>(std::count(testsReussis.begin(), testsReussis.end(), true));
	afficherFooterTest(nombreTestsReussis, testsReussis.size());
}

void tests_Classe_attaquant()
{
	vector<bool> testsReussis;
	afficherHeaderTest("classe Attaquant");

	// test constructeur par defaut
	Attaquant messi = Attaquant();
	testsReussis.push_back(static_cast<const Joueur> (messi).getAttaque() == 1.0);
	testsReussis.push_back(static_cast<const Joueur> (messi).getDefense() == 0.3);
	testsReussis.push_back(messi.getAgilite() == 0.8);
	testsReussis.push_back(messi.getPrecision() == 1.0);
	afficherResultatTest("constructeur par defaut de la classe Attaquant", decision(testsReussis));

	// test constructeur par parametres
	Attaquant drogba = Attaquant("Drogba", 189, 250, 235, 98, 89, 30, 45, 12.5);
	testsReussis.push_back(static_cast<const Joueur> (drogba).getAttaque() == 98);
	testsReussis.push_back(static_cast<const Joueur> (drogba).getDefense() == 89);
	testsReussis.push_back(drogba.getAgilite() == 45);
	testsReussis.push_back(drogba.getPrecision() == 12.5);
	afficherResultatTest("constructeur par parametre de la classe Attaquant", decision(testsReussis));

	// test getters
	testsReussis.push_back(drogba.getAttaque() - 2858.33 < 1);
	testsReussis.push_back(drogba.getDefense() == 2225);
	testsReussis.push_back(drogba.getVitesse() == 30);
	testsReussis.push_back(drogba.getAgilite() == 45);
	testsReussis.push_back(drogba.getPrecision() == 12.5);
	afficherResultatTest("getters de la classe Attaquant", decision(testsReussis));

	// test operateur <<
	string printAttendu = string(" Attaquant \n") + string("Drogba 189 250 235 98 89\n") + string(" 30 45 12.5\n");
	stringstream outAttaquant;
	outAttaquant << drogba;
	testsReussis.push_back(outAttaquant.str() == printAttendu);
	afficherResultatTest("operateur << de la classe Attaquant", decision(testsReussis));

	int nombreTestsReussis = static_cast<int>(std::count(testsReussis.begin(), testsReussis.end(), true));
	afficherFooterTest(nombreTestsReussis, testsReussis.size());
}

void tests_classe_defenseur()
{
	vector<bool> testsReussis;
	afficherHeaderTest("classe Defenseur");

	// test constructeur par defaut
	Defenseur defenseur1 = Defenseur();
	testsReussis.push_back(defenseur1.getNom() == "inconnu");
	testsReussis.push_back(defenseur1.getMatchsJoues() == 0);
	testsReussis.push_back(defenseur1.getButs() == 0);
	testsReussis.push_back(defenseur1.getAssists() == 0);
	testsReussis.push_back(static_cast<Joueur>(defenseur1).getAttaque() == 0.1);
	testsReussis.push_back(static_cast<Joueur>(defenseur1).getDefense() == 0.9);
	testsReussis.push_back(defenseur1.getReactivite() == 0.8);
	testsReussis.push_back(defenseur1.getVision() == 1.0);
	afficherResultatTest("Constructeur par defaut de la classe Defenseur", decision(testsReussis));

	// test constructeur par parametre
	Defenseur defenseur2 = Defenseur("Carles Puyol", 32, 3, 13, 35, 80, 1.2, 1.0);
	testsReussis.push_back(defenseur2.getNom() == "Carles Puyol");
	testsReussis.push_back(defenseur2.getMatchsJoues() == 32);
	testsReussis.push_back(defenseur2.getButs() == 3);
	testsReussis.push_back(defenseur2.getAssists() == 13);
	testsReussis.push_back(static_cast<Joueur>(defenseur2).getAttaque() == 35);
	testsReussis.push_back(static_cast<Joueur>(defenseur2).getDefense() == 80);
	testsReussis.push_back(defenseur2.getReactivite() == 1.2);
	testsReussis.push_back(defenseur2.getVision() == 1.0);
	afficherResultatTest("Constructeur par parametre de la classe Defenseur", decision(testsReussis));

	// test getters
	Defenseur defenseur3 = Defenseur("Rio ferdinand", 53, 5, 16, 12.0, 26.5, 1.2, 0.8);
	testsReussis.push_back(defenseur3.getNom() == "Rio ferdinand");
	testsReussis.push_back(defenseur3.getMatchsJoues() == 53);
	testsReussis.push_back(defenseur3.getButs() == 5);
	testsReussis.push_back(defenseur3.getAssists() == 16);
	testsReussis.push_back(defenseur3.getAttaque() == 9.6);
	testsReussis.push_back(defenseur3.getDefense() == 26.5);
	testsReussis.push_back(defenseur3.getReactivite() == 1.2);
	testsReussis.push_back(defenseur3.getVision() == 0.8);
	afficherResultatTest("getters de la classe Defenseur", decision(testsReussis));

	// test operateur <<
	string printAttendu = string(" Defenseur \n") + string("Rio ferdinand 53 5 16 12 26.5\n") + string(" 1.2 0.8\n");
	stringstream outDefenseur;
	outDefenseur << defenseur3;
	testsReussis.push_back(outDefenseur.str() == printAttendu);
	afficherResultatTest("operateur << de la classe Defenseur", decision(testsReussis));

	int nombreTestsReussis = static_cast<int>(std::count(testsReussis.begin(), testsReussis.end(), true));
	afficherFooterTest(nombreTestsReussis, testsReussis.size());
}

void tests_classe_equipe()
{
	vector<bool> testsReussis;
	afficherHeaderTest("classe Equipe");

	// test calculAttaque 
	Equipe equipe1 = Equipe();
	testsReussis.push_back(equipe1.calculAttaque() == 0.0);
	shared_ptr<Joueur> joueur1 = make_shared<Joueur>("Stanley",10, 5, 6, 12, 15);
	shared_ptr<Joueur> joueur2 = make_shared<Joueur>("Shea", 81, 23, 30, 85, 80);
	shared_ptr<Joueur> joueur3 = make_shared<Joueur>("Joueur3", 82, 21, 40, 13, 60);
	shared_ptr<Joueur> joueur4 = make_shared<Joueur>("Joueur4", 82, 21, 40, 77, 89);
	shared_ptr<Joueur> joueur5 = make_shared<Joueur>("Joueur5", 82, 21, 40, 60.5, 45.4);
	shared_ptr<Joueur> joueur6 = make_shared < Joueur>("Joueur6", 82, 21, 40, 55.7, 78.8);
	shared_ptr<Joueur> joueur7 = make_shared<Joueur>("Joueur7", 82, 21, 40, 45.3, 98.5);
	equipe1 = equipe1 + joueur1;
	equipe1 = equipe1 + joueur2;
	equipe1 = equipe1 + joueur3;
	equipe1 = equipe1 + joueur4;
	equipe1 = equipe1 + joueur5;
	equipe1 = equipe1 + joueur6;
	equipe1 = equipe1 + joueur7;
	testsReussis.push_back(equipe1.calculAttaque() > 0.0);
	Equipe equipe2 = Equipe(equipe1);
	testsReussis.push_back(equipe1.calculAttaque() != equipe2.calculAttaque());
	afficherResultatTest("test de calculAttaque de la classe Equipe", decision(testsReussis));

	// test calcul defense
	Equipe equipe3 = Equipe();
	testsReussis.push_back(equipe3.calculDefense() == 0.0);
	equipe3 = equipe3 + joueur1;
	equipe3 = equipe3 + joueur2;
	equipe3 = equipe3 + joueur3;
	equipe3 = equipe3 + joueur4;
	equipe3 = equipe3 + joueur5;
	equipe3 = equipe3 + joueur6;
	equipe3 = equipe3 + joueur7;
	testsReussis.push_back(equipe3.calculDefense() > 0.0);
	Equipe equipe4 = Equipe(equipe3);
	testsReussis.push_back(equipe3.calculDefense() != equipe4.calculDefense());
	afficherResultatTest("test de calculDefense de la classe Equipe", decision(testsReussis));

	// test getter
	testsReussis.push_back(equipe3.getJoueurs().size() == 7);
	afficherResultatTest("getter de la classe Equipe", decision(testsReussis));

	// test operateur <<
	stringstream outEquipe;
	outEquipe << equipe3;
	testsReussis.push_back(outEquipe.str().find(equipe3.getNom()) != string::npos);
	testsReussis.push_back(outEquipe.str().find("Joueurs : ") != string::npos);
	testsReussis.push_back(outEquipe.str().find("Stanley 10 5 6 12 15\n") != string::npos);
	testsReussis.push_back(outEquipe.str().find("Shea 81 23 30 85 80\n") != string::npos);
	testsReussis.push_back(outEquipe.str().find("Joueur3 82 21 40 13 60\n") != string::npos);
	testsReussis.push_back(outEquipe.str().find("Joueur4 82 21 40 77 89\n") != string::npos);
	testsReussis.push_back(outEquipe.str().find("Joueur5 82 21 40 60.5 45.4\n") != string::npos);
	testsReussis.push_back(outEquipe.str().find("Joueur6 82 21 40 55.7 78.8\n") != string::npos);
	testsReussis.push_back(outEquipe.str().find("Joueur7 82 21 40 45.3 98.5\n") != string::npos);
	testsReussis.push_back(outEquipe.str().find("Nombre de victoire>>s : 0\n") != string::npos);
	testsReussis.push_back(outEquipe.str().find("Somme de la force d'attaque ") != string::npos);
	testsReussis.push_back(outEquipe.str().find("Somme de la  force de defense ") != string::npos);
	afficherResultatTest("operateur << de la classe Equipe", decision(testsReussis));

	int nombreTestsReussis = static_cast<int>(std::count(testsReussis.begin(), testsReussis.end(), true));
	afficherFooterTest(nombreTestsReussis, testsReussis.size());
}

void tests_classe_match()
{
	vector<bool> testsReussis;
	afficherHeaderTest("classe Match");

	// test constructeur par defaut
	Match<Equipe> match = Match<Equipe>();
	testsReussis.push_back(match.getScoreA() == 0);
	testsReussis.push_back(match.getScoreB() == 0);
	testsReussis.push_back(match.getEquipeA() == nullptr);
	testsReussis.push_back(match.getEquipeB() == nullptr);
	afficherResultatTest("Constructeur par defaut de la classe Match", decision(testsReussis));

	// test constructeur par parametre
	Date date = Date(01, 01, 2022);
	shared_ptr<Equipe> equipe1 = make_shared<Equipe>("Manchester United", 2, 2, 1990);
	shared_ptr<Equipe> equipe2 = make_shared<Equipe>("Manchester City", 1, 8, 1991);
	Match<Equipe> match2 = Match<Equipe>(date, equipe1, equipe2);
	testsReussis.push_back(match2.getScoreA() == 0);
	testsReussis.push_back(match2.getScoreB() == 0);
	testsReussis.push_back(match2.getEquipeA()->getNom() == "Manchester United");
	testsReussis.push_back(match2.getEquipeB()->getNom() == "Manchester City");
	afficherResultatTest("Constructeur par parametre de la classe Match", decision(testsReussis));

	// test constructeur par copie
	Match<Equipe> match3(match2);
	testsReussis.push_back(match3.getScoreA() == match2.getScoreA());
	testsReussis.push_back(match3.getScoreB() == match2.getScoreB());
	testsReussis.push_back(match3.getEquipeA()->getNom() == match2.getEquipeA()->getNom());
	testsReussis.push_back(match3.getEquipeB()->getNom() == match2.getEquipeB()->getNom());
	afficherResultatTest("Constructeur par copie de la classe Match", decision(testsReussis));

	// test operateur =
	Date date2 = Date(01, 10, 2022);
	shared_ptr<Equipe> equipe3 = make_shared<Equipe>("Arsenal", 3, 11, 1997);
	shared_ptr<Equipe> equipe4 = make_shared<Equipe>("Chelsea", 1, 12, 1987);
	Match<Equipe> match4 = Match<Equipe>(date2, equipe3, equipe4);
	Match<Equipe> match5 = match4;
	testsReussis.push_back(match4.getScoreA() == match5.getScoreA());
	testsReussis.push_back(match4.getScoreB() == match5.getScoreB());
	testsReussis.push_back(match4.getEquipeA()->getNom() == match5.getEquipeA()->getNom());
	testsReussis.push_back(match4.getEquipeB()->getNom() == match5.getEquipeB()->getNom());
	afficherResultatTest("operateur = de la classe Match", decision(testsReussis));

	// tests setters et getters partie 1
	Match<Equipe> match6 = Match<Equipe>();
	match6.setDate(Date(1,1,2021));
	match6.setEquipeA(equipe1);
	match6.setEquipeB(equipe2);
	testsReussis.push_back(match6.getEquipeA()->getNom() == "Manchester United");
	testsReussis.push_back(match6.getEquipeB()->getNom() == "Manchester City");
	testsReussis.push_back(match6.getScoreA() == 0);
	testsReussis.push_back(match6.getScoreB() == 0);
	afficherResultatTest("Setters et getters de la classe Match partie 1", decision(testsReussis));

	// tests setters et getters partie 2
	match6.setEquipes(equipe3, equipe4);
	pair<int, int> scores = match6.getScores();
	testsReussis.push_back(match6.getEquipeA()->getNom() == "Arsenal");
	testsReussis.push_back(match6.getEquipeB()->getNom() == "Chelsea");
	testsReussis.push_back(scores.first == 0 && scores.second == 0);
	afficherResultatTest("Setters et getters de la classe Match partie 2", decision(testsReussis));

	// test estVictorieuse
	bool estVictorieuse = match6.estVictorieuse(equipe3);
	testsReussis.push_back(estVictorieuse == false);
	estVictorieuse = match6.estVictorieuse(equipe4);
	testsReussis.push_back(estVictorieuse == false);
	estVictorieuse = match6.estVictorieuse(equipe1);
	testsReussis.push_back(estVictorieuse == false);
	afficherResultatTest("fonction estVictorieuse de la classe Match", decision(testsReussis));

	// test operateur <<
	stringstream outMatch;
	outMatch << match6;
	string printAttendu = "Match - 2021-1-1" + string("\n") + string("\n")
		+ string("Arsenal") + string(" vs ") + string("Chelsea\n") + string("Resultat : ") + string("0 - 0\n");
	testsReussis.push_back(outMatch.str() == printAttendu);
	afficherResultatTest("operateur << de la classe Match", decision(testsReussis));

	int nombreTestsReussis = static_cast<int>(std::count(testsReussis.begin(), testsReussis.end(), true));
	afficherFooterTest(nombreTestsReussis, testsReussis.size());

}

void tests_classe_equipe_sport()
{
	vector<bool> testsReussis;
	afficherHeaderTest("classe EquipeSport");

	EquipeSport equipeSport("Juventus");
	testsReussis.push_back(equipeSport.calculAttaque() != equipeSport.calculAttaque());
	afficherResultatTest("fonction calculAttaque de classe EquipeSport", decision(testsReussis));
	testsReussis.push_back(equipeSport.calculDefense() != equipeSport.calculDefense());
	afficherResultatTest("fonction calculDefense de classe EquipeSport", decision(testsReussis));

	int nombreTestsReussis = static_cast<int>(std::count(testsReussis.begin(), testsReussis.end(), true));
	afficherFooterTest(nombreTestsReussis, testsReussis.size());
}

void runTest()
{
	tests_classe_joueur();
	tests_classe_gardien();
	tests_Classe_attaquant();
	tests_classe_defenseur();
	tests_classe_equipe();
	tests_classe_match();
	tests_classe_equipe_sport();
}