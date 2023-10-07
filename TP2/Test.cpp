#include "Date.h"
#include "Equipe.h"
#include "Joueur.h"

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

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
void afficherFooterTest(double totalPoints, double maxPoints)
{
	std::cout << "--------\nTotal pour la section: " << totalPoints << "/" << maxPoints << "  arrondi au dixieme" << '\n';
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

// test toutes les fonctions et operateurs de la classe equipe
void tests_classe_equipe()
{
	afficherHeaderTest("classe Equipe");
	vector<bool> testsReussis;
	static constexpr double maxPointsSection = 5.0;


	Equipe equipe = Equipe("Canadiens de Montreal", 2022, 01, 01);

	// test getters
	testsReussis.push_back(equipe.getNom() == "Canadiens de Montreal");
	testsReussis.push_back(equipe.getNombreJoueurs() == 0);
	testsReussis.push_back(equipe.getNombreVictoire() == 0);
	testsReussis.push_back(equipe.getJoueur("joueurInexistant") == nullptr);
	afficherResultatTest("Getters de la classe Equipe", decision(testsReussis));


	// test copy construction
	testsReussis.clear();
	Equipe copyEquipe1 = Equipe(equipe);
	testsReussis.push_back(copyEquipe1.getNom() == equipe.getNom());
	shared_ptr<Joueur> nouveauJoueur = make_shared<Joueur>();
	copyEquipe1 = copyEquipe1 + nouveauJoueur;
	testsReussis.push_back(copyEquipe1.getNombreJoueurs() != equipe.getNombreJoueurs());
	testsReussis.push_back(copyEquipe1.getNombreVictoire() == equipe.getNombreVictoire());
	afficherResultatTest("constructeur par copie de la classe Equipe", decision(testsReussis));

	// Test operateur =
	testsReussis.clear();
	Equipe copyEquipe2 = equipe;
	testsReussis.push_back(copyEquipe2.getNom() == equipe.getNom());
	testsReussis.push_back(copyEquipe2.getNombreJoueurs() == equipe.getNombreJoueurs());
	testsReussis.push_back(copyEquipe2.getNombreVictoire() == equipe.getNombreVictoire());
	afficherResultatTest("operateur = de la classe Equipe", decision(testsReussis));


	// test operateur + (ajouter nouveau joueur)
	testsReussis.clear();
	shared_ptr<Joueur> joueur1 = make_shared<Joueur>("Stanley", 10, 5, 6);
	shared_ptr<Joueur> joueur2 = make_shared<Joueur>("Shea", 81, 23, 30);
	shared_ptr<Joueur> joueur3 = make_shared<Joueur>("Joueur3", 82, 21, 40);
	shared_ptr<Joueur> joueur4 = make_shared<Joueur>("Joueur4", 82, 21, 40);
	shared_ptr<Joueur> joueur5 = make_shared<Joueur>("Joueur5", 82, 21, 40);
	shared_ptr<Joueur> joueur6 = make_shared < Joueur>("Joueur6", 82, 21, 40);
	shared_ptr<Joueur> joueur7 = make_shared<Joueur>("Joueur7", 82, 21, 40);
	equipe = equipe + joueur1;
	testsReussis.push_back(equipe.getNombreJoueurs() == 1);
	equipe = equipe + joueur2;
	testsReussis.push_back(equipe.getNombreJoueurs() == 2);
	equipe = equipe + joueur3;
	testsReussis.push_back(equipe.getNombreJoueurs() == 3);
	equipe = equipe + joueur4;
	testsReussis.push_back(equipe.getNombreJoueurs() == 4);
	equipe = equipe + joueur5;
	testsReussis.push_back(equipe.getNombreJoueurs() == 5);
	equipe = equipe + joueur6;
	testsReussis.push_back(equipe.getNombreJoueurs() == 6);
	equipe = equipe + joueur7;
	testsReussis.push_back(equipe.getNombreJoueurs() == 7);
	testsReussis.push_back(equipe.getJoueur(joueur1->getNom()) != nullptr);
	testsReussis.push_back(equipe.getJoueur(joueur7->getNom()) != nullptr);
	afficherResultatTest("operateur + de la classe Equipe", decision(testsReussis));


	// test operateur -
	testsReussis.clear();
	equipe = equipe - joueur1->getNom();
	testsReussis.push_back(equipe.getNombreJoueurs() == 6);
	equipe = equipe - joueur7->getNom();
	testsReussis.push_back(equipe.getNombreJoueurs() == 5);
	testsReussis.push_back(equipe.getJoueur(joueur1->getNom()) == nullptr);
	testsReussis.push_back(equipe.getJoueur(joueur7->getNom()) == nullptr);
	afficherResultatTest("operateur - de la classe Equipe", decision(testsReussis));

	// test operateur ++
	testsReussis.clear();
	++equipe;
	++equipe;
	testsReussis.push_back(equipe.getNombreVictoire() == 2);
	afficherResultatTest("operateur ++ de la classe Equipe", decision(testsReussis));

	// test operateur <<
	testsReussis.clear();
	stringstream outEquipe;
	outEquipe << equipe;
	string printAttendu = "\nCanadiens de Montreal\n" +
		string("Joueurs : \n")+
		string("Joueur6 82 21 40\n")+
		string("Shea 81 23 30\n") +
		string("Joueur3 82 21 40\n")+
		string("Joueur4 82 21 40\n")+
		string("Joueur5 82 21 40\n")+
		string("Nombre de victoire>>s : 2\n");
	testsReussis.push_back(outEquipe.str().size() == printAttendu.size());
	afficherResultatTest("operateur << de la classe Equipe", decision(testsReussis));

	int nombreTestsReussis = static_cast<int>(std::count(testsReussis.begin(), testsReussis.end(), true));
	double totalPointsSection = static_cast<double>(nombreTestsReussis) / static_cast<double>(testsReussis.size()) * maxPointsSection;

	afficherFooterTest(totalPointsSection, maxPointsSection);
}

// test toutes les fonctions et operateurs de la classe joueur
void tests_classe_joueur()
{
	afficherHeaderTest("classe Joueur");
	vector<bool> testsReussis;
	static constexpr double maxPointsSection = 3.0;
	Joueur joueur1 = Joueur("Stanley", 10, 5, 6);
	Joueur joueurInconnu = Joueur();

	//Test1 Getters
	testsReussis.push_back(joueur1.getNom() == "Stanley");
	testsReussis.push_back(joueur1.getAssists() == 6);
	testsReussis.push_back(joueur1.getButs() == 5);
	testsReussis.push_back(joueur1.getMatchsJoues() == 10);
	testsReussis.push_back(joueurInconnu.getAssists() == 0);
	afficherResultatTest("Getters de la classe Joueur", decision(testsReussis));

	//Test2 Setters
	testsReussis.clear();
	joueur1.setNom("Franklin"); joueur1.setButs(1); joueur1.setMatchsJoues(20); joueur1.setAssists(19);
	testsReussis.push_back(joueur1.getNom() == "Franklin");
	testsReussis.push_back(joueur1.getButs() == 1);
	testsReussis.push_back(joueur1.getMatchsJoues() == 20);
	testsReussis.push_back(joueur1.getAssists() == 19);
	afficherResultatTest("Setters de la classe Joueur", decision(testsReussis));
	
	// operateur <
	testsReussis.clear();
	Joueur j1("j1", 10, 3, 4),j2("j2", 15, 5, 3);
	Joueur joueur3 = Joueur("Joueur3", 82, 21, 40);
	Joueur joueur4 = Joueur("Joueur4", 82, 100, 40);
	Joueur joueur5 = Joueur("Joueur5", 82, 21, 100);
	testsReussis.push_back(j1 < j2 == true);
	testsReussis.push_back(joueur3 < joueur4 == true);
	testsReussis.push_back(joueur5 < joueur3 == false);
	testsReussis.push_back(joueur5 < joueur4 == true);
	afficherResultatTest("operateur < de la classe Joueur", decision(testsReussis));

	// operateur <<
	testsReussis.clear();
	string printAttendu = "Joueur3 82 21 40\n";
	stringstream outJoueur;
	outJoueur << joueur3;
	testsReussis.push_back(outJoueur.str() == printAttendu);
	afficherResultatTest("operateur << de la classe Joueur", decision(testsReussis));

	int nombreTestsReussis = static_cast<int>(std::count(testsReussis.begin(), testsReussis.end(), true));
	double totalPointsSection = static_cast<double>(nombreTestsReussis) / static_cast<double>(testsReussis.size()) * maxPointsSection;

	afficherFooterTest(totalPointsSection, maxPointsSection);
}

// test toutes les fonctions et operateurs de la classe Date
void tests_classe_date()
{
	afficherHeaderTest("classe Date");
	vector<bool> testsReussis;
	static constexpr double maxPointsSection = 2.0;

	Date jour1(20, 9, 2022), jour2(15, 10, 2022);
	Date jour3(17, 9, 2022), jour4(20, 9, 2023);
	testsReussis.push_back(jour1 < jour2 == true);
	testsReussis.push_back(jour1 < jour3 == false);
	testsReussis.push_back(jour1 < jour4 == true);
	afficherResultatTest("operateur < de la classe Date", decision(testsReussis));

	testsReussis.clear();
	jour3 = jour1 + 30;
	stringstream outJour3;
	outJour3 << jour3;
	testsReussis.push_back(outJour3.str() == "2022-10-20\n");
	afficherResultatTest("operateur + de la classe Date", decision(testsReussis));

	testsReussis.clear();
	jour1 += 40;
	stringstream outJoueur1;
	outJoueur1 << jour1;
	testsReussis.push_back(outJoueur1.str() == "2022-10-30\n");
	afficherResultatTest("operateur += de la classe Date", decision(testsReussis));

	testsReussis.clear();
	++jour1;
	stringstream outJoueur;
	outJoueur << jour1;
	testsReussis.push_back(outJoueur.str() == "2022-10-31\n");
	afficherResultatTest("operateur ++ de la classe Date", decision(testsReussis));

	int nombreTestsReussis = static_cast<int>(std::count(testsReussis.begin(), testsReussis.end(), true));
	double totalPointsSection = static_cast<double>(nombreTestsReussis) / static_cast<double>(testsReussis.size()) * maxPointsSection;
	afficherFooterTest(totalPointsSection, maxPointsSection);
}

// lance tous les tests
void runTest()
{
	tests_classe_equipe();
	tests_classe_joueur();
	tests_classe_date();
}

