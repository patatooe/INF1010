/// Tests automatisés. TP1
/// \author Stéphane Toyo Demanou
/// \date 2022-09-14

#include "Tests.h"
#include "Equipe.h"
#include "Joueur.h"
#include "Date.h"
#include <memory>
#include <iostream>
#include <iomanip>

using namespace std;

namespace Tests {
    /// Appelle tous les tests et affiche la somme de ceux-ci à l'écran.
    void testAll()
    {
        static constexpr double maxPointsAll = 10.0;
        double totalPointsAll = 0.0;
        totalPointsAll += testsJoueurs();
        totalPointsAll += testsEquipe();

        std::cout << "\nTotal pour tous les tests: " << totalPointsAll << '/' << maxPointsAll << "  arrondi au dixieme"  << '\n';
    }

    /// Affiche un header pour chaque section de tests à l'écran.
    /// \param nomSectionTest   Le nom de la section de tests.
    void afficherHeaderTest(const std::string& nomSectionTest) { std::cout << "\nTests pour " + nomSectionTest + ":\n--------\n"; }

    /// Affiche un footer avec les points pour chaque section de tests à l'écran.
    /// \param totalPoints  Le nombre de points obtenus à la section de tests.
    /// \param maxPoints    Le nombre de points maximal alloués à la section de tests.
    void afficherFooterTest(double totalPoints, double maxPoints)
    {
        std::cout << "--------\nTotal pour la section: " << totalPoints << "/" << maxPoints << "  arrondi au dixieme" << '\n';
    }

    /// Affiche le nom d'un test ainsi que son état de passage à l'écran.
    /// \param index        L'index du test.
    /// \param nom          Le nom du test.
    /// \param estReussi    L'état de passage du test.
    void afficherResultatTest(const std::string& nom, bool estReussi)
    {
        static int numeroTest = 0;
        static constexpr int largeurNumeroTest = 2;
        static constexpr int largeurNomTest = 80;
        std::cout << "Test " << std::right << std::setw(largeurNumeroTest) << ++numeroTest << ": " << std::left << std::setw(largeurNomTest)
            << nom << ": " << (estReussi ? "OK" : "FAILED") << '\n';
    }

    double testsJoueurs()
    {
        afficherHeaderTest("Creation/Modifications des joueurs");
        static constexpr double maxPointsSection = 5.0;

#if TESTS_CLASSE_JOUEURS
        std::vector<bool> testsReussis;

        Joueur joueur1 = Joueur("Stanley", 10, 5, 6);
        Joueur joueurInconnu = Joueur();

        //Test1 Getters
        testsReussis.push_back(joueur1.getNom() == "Stanley");
        testsReussis.push_back(joueur1.getAssists() == 6);
        testsReussis.push_back(joueur1.getButs() == 5);
        testsReussis.push_back(joueur1.getMatchsJoués() == 10);
        testsReussis.push_back(joueurInconnu.getAssists() == 0);
        afficherResultatTest("Getters de la classe Joueur", testsReussis.back());

        //Test2 Setters
        joueur1.setNom("Franklin"); joueur1.setButs(1); joueur1.setMatchsJoués(20); joueur1.setAssists(19);
        testsReussis.push_back(joueur1.getNom() == "Franklin");
        testsReussis.push_back(joueur1.getButs() == 1);
        testsReussis.push_back(joueur1.getMatchsJoués() == 20);
        testsReussis.push_back(joueur1.getAssists() == 19);
        afficherResultatTest("Setters de la classe Joueur", testsReussis.back());

        int nombreTestsReussis = static_cast<int>(std::count(testsReussis.begin(), testsReussis.end(), true));
        double totalPointsSection = static_cast<double>(nombreTestsReussis) / static_cast<double>(testsReussis.size()) * maxPointsSection;
#else
        std::cout << "[Tests desactives]\n";
        double totalPointsSection = 0.0;
#endif
        afficherFooterTest(totalPointsSection, maxPointsSection);
        return totalPointsSection;
    }

    double testsEquipe()
    {
        afficherHeaderTest("Creation/Modification des equipes");
        static constexpr double maxPointsSection = 5.0;

#if TESTS_CLASSE_EQUIPE
        std::vector<bool> testsReussis;

        // Test3
        {
            Equipe equipeParDefaut = Equipe();
            Equipe canadiensMontreal = Equipe("Canadiens de Montreal", 2022, 12, 01);
            
            testsReussis.push_back(canadiensMontreal.getNom() == "Canadiens de Montreal");
            testsReussis.push_back(canadiensMontreal.getNombreVictoire() == 0);
            testsReussis.push_back(equipeParDefaut.getNom() == "inconnue");
            afficherResultatTest("Constructeurs et Getters du nom de l equipe et du nombre de victoires", testsReussis.back());
        } 

        //Test 4
        {
            Equipe canadiensMontreal = Equipe("Canadiens de Montreal", 2022, 01, 01);

            canadiensMontreal.ajouterVictoire();
            canadiensMontreal.ajouterVictoire();
            canadiensMontreal.ajouterVictoire();
            canadiensMontreal.ajouterVictoire();
            canadiensMontreal.ajouterVictoire();
            testsReussis.push_back(canadiensMontreal.getNombreVictoire() == 5);
            afficherResultatTest("Fonction ajouterVictoire() et obtenir le bon nombre de victoires", testsReussis.back());
        }

        // Test 5
        {
            Equipe canadiensMontreal = Equipe("Canadiens de Montreal", 2022, 01, 01);
            shared_ptr<Joueur> Weber = make_shared<Joueur>("Shea", 81, 23, 30);
            shared_ptr<Joueur> Suzuki = make_shared<Joueur>("Nick", 82, 21, 40);
            canadiensMontreal.ajouterJoueur(Weber);
            canadiensMontreal.ajouterJoueur(Suzuki);
            canadiensMontreal.ajouterJoueur(Suzuki);
            testsReussis.push_back(canadiensMontreal.getNombreJoueurs() == 2);
            afficherResultatTest("Fonction ajouterJoueur() ajoute des joueurs", testsReussis.back());
        }

        // Test 6
        {
            Equipe canadiensMontreal = Equipe("Canadiens de Montreal", 2022, 01, 01);
            shared_ptr<Joueur> Weber = make_shared<Joueur>("Shea", 81, 23, 30);
            shared_ptr<Joueur> Suzuki = make_shared<Joueur>("Nick", 82, 21, 40);
            shared_ptr<Joueur> joueur3 = make_shared<Joueur>("Joueur3", 82, 21, 40);
            shared_ptr<Joueur> joueur4 = make_shared<Joueur>("Joueur4", 82, 21, 40);
            shared_ptr<Joueur> joueur5 = make_shared<Joueur>("Joueur5", 82, 21, 40);
            shared_ptr<Joueur> joueur6 = make_shared < Joueur>("Joueur6", 82, 21, 40);
            shared_ptr<Joueur> joueur7 = make_shared<Joueur>("Joueur7", 82, 21, 40);
            shared_ptr<Joueur> joueur8 = make_shared<Joueur>("Joueur8", 82, 21, 40);
            shared_ptr<Joueur> joueur9 = make_shared<Joueur>("Joueur9", 82, 21, 40);
            shared_ptr<Joueur> joueur10 = make_shared<Joueur>("Joueur10", 82, 21, 40);
            shared_ptr<Joueur> joueur11 = make_shared<Joueur>("Joueur11", 82, 21, 40);
            shared_ptr<Joueur> joueur12 = make_shared<Joueur>("Joueur12", 82, 21, 40);
            canadiensMontreal.ajouterJoueur(Weber);
            canadiensMontreal.ajouterJoueur(Suzuki);
            canadiensMontreal.ajouterJoueur(joueur3);
            canadiensMontreal.ajouterJoueur(joueur4);
            canadiensMontreal.ajouterJoueur(joueur5);
            canadiensMontreal.ajouterJoueur(joueur6);
            canadiensMontreal.ajouterJoueur(joueur7);
            canadiensMontreal.ajouterJoueur(joueur8);
            canadiensMontreal.ajouterJoueur(joueur9);
            canadiensMontreal.ajouterJoueur(joueur10);
            canadiensMontreal.ajouterJoueur(joueur11);
            canadiensMontreal.ajouterJoueur(joueur12);
            testsReussis.push_back(canadiensMontreal.getNombreJoueurs() == 12);
            afficherResultatTest("AjouterJoueur() lorsque le nombre de joueurs > capactite du tableau", testsReussis.back()); testsReussis.clear();
        }

        //Test 7
        {
            Equipe canadiensMontreal = Equipe("Canadiens de Montreal", 2022, 01, 01);
            testsReussis.push_back(canadiensMontreal.supprimerJoueur("JoueurInexistant") == false);
            afficherResultatTest("Fonction supprimerJoueur() si le joueur n existe pas", testsReussis.back());

        }

        //Test 8
        {
            Equipe canadiensMontreal = Equipe("Canadiens de Montreal", 2022, 01, 01);
            shared_ptr<Joueur> Weber = make_shared<Joueur>("Shea", 81, 23, 30);
            shared_ptr<Joueur> Suzuki = make_shared<Joueur>("Nick", 82, 21, 40);
            shared_ptr<Joueur> Savard = make_shared<Joueur>("David", 62, 3, 14);
            canadiensMontreal.ajouterJoueur(Weber);
            canadiensMontreal.ajouterJoueur(Suzuki);
            canadiensMontreal.ajouterJoueur(Savard);
            testsReussis.push_back(canadiensMontreal.supprimerJoueur(Weber->getNom()));
            testsReussis.push_back(canadiensMontreal.supprimerJoueur(Suzuki->getNom()));
            testsReussis.push_back(canadiensMontreal.getNombreJoueurs() == 1);
            afficherResultatTest("Fonction supprimerJoueur() et get le bon nombre de joueurs apres suppression", testsReussis.back());
        }

        //Test 9
        {
            Equipe canadiensMontreal = Equipe("Canadiens de Montreal", 2022, 01, 01);
            testsReussis.clear();
            shared_ptr<Joueur> Weber = make_shared<Joueur>("Shea", 81, 23, 30);
            shared_ptr<Joueur> Suzuki = make_shared<Joueur>("Nick", 82, 21, 40);
            shared_ptr<Joueur> Savard = make_shared<Joueur>("David", 62, 3, 14);
            canadiensMontreal.ajouterJoueur(Weber);
            canadiensMontreal.ajouterJoueur(Suzuki);
            canadiensMontreal.ajouterJoueur(Savard);
            testsReussis.push_back(canadiensMontreal.getNombreJoueurs() == 3);
            bool supressions = canadiensMontreal.supprimerJoueur(Weber->getNom()) && canadiensMontreal.supprimerJoueur(Suzuki->getNom());
            testsReussis.push_back(supressions && canadiensMontreal.getNombreJoueurs() == 1);
            testsReussis.push_back(canadiensMontreal.getJoueur(Savard->getNom())->getMatchsJoués() == Savard->getMatchsJoués());
            afficherResultatTest("Test de getJoueur() et mix des autres fonctions", testsReussis.back());
        }

        int nombreTestsReussis = static_cast<int>(std::count(testsReussis.begin(), testsReussis.end(), true));
        double totalPointsSection = static_cast<double>(nombreTestsReussis) / static_cast<double>(testsReussis.size()) * maxPointsSection;
#else 
        std::cout << "[Tests desactives]\n";
        double totalPointsSection = 0.0;
#endif
        afficherFooterTest(totalPointsSection, maxPointsSection);
        return totalPointsSection;
    }

}

