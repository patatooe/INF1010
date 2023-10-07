/************************************************************************************
*	Fichier					: Tournoi.cpp
*	Auteurs					: Patricia Manarazan (1942503), Robin Plamondon (2119689)
*	Description				: Implementation de la classe Tournoi
*	Date de creation		: 2022/01/12
*	Date de modification	: 2022/01/12
************************************************************************************/
#include "Tournoi.h"
#include <algorithm>
#include <random>
#include <deque>

// a implémenter

/**
 * @brief Implementation de la methode ajouterEquipe
 * @param un shared_ptr de type Equipe
 * @return Un booleen
*/
bool Tournoi::ajouterEquipe(shared_ptr<Equipe> equipe)
{
    int count_ = count(equipes_.begin(), equipes_.end(), equipe);
    if (count_ > 0)
        return false;
    else {
        equipes_.insert(equipes_.end(), equipe);
        return true;
    }
}


/**
 * @brief Implementation de la methode ajouterMatch
 * @param un shared_ptr de type Match
 * @return Un booleen
*/
// a implémenter
bool Tournoi::ajouterMatch(std::shared_ptr<Match> match)
{
    auto it = find(matchs_.begin(), matchs_.end(), match);
    if (it == matchs_.end()) {
        matchs_.insert(match);
        historiqueMatchs_.insert({ match->getDate(), match.get() });
        return true;
    }
    else {
        return false;
    }
}

/**
 * @brief Implementation de la methode getMatchsParDate
 * @param une date par reference
 * @return vecteur de pointeurs bruts pour Match
*/
//// a implémenter
std::vector<const Match*> Tournoi::getMatchsParDate(const Date& date) const 
{
    /*vector<const Match*> matchsParDate;
    if (equal(historiqueMatchs_.begin(), historiqueMatchs_.end(), date, [&date](const Match* A) { return A->getDate() == date;})) {
        matchsParDate = 
    }

    vector<Match*> devientVecteur(multimap<Date, const Match*>& x) {
        vector<Match*> matchsParDate = x.second();
        return matchsParDate;
    }

    transform(historiqueMatchs_.begin(), historiqueMatchs_.end(), rep, devientVecteur);*/

    return vector<const Match*>();
}

multiset<shared_ptr<Match>, FoncteurComparerParDate<Match>> Tournoi::attribuerMatchs()
{
    multiset<shared_ptr<Match>, FoncteurComparerParDate<Match>> matchs;
    deque<shared_ptr<Equipe>> equipesTemp;
    copy(equipes_.begin(), equipes_.end(), back_inserter(equipesTemp));
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(equipesTemp.begin(), equipesTemp.end(), g);
    Date date_match(time(0));

    // attribution des matchs aleatoirement. On suppose un nombre pair d'equipe et exposant de 2.
    while (!equipesTemp.empty()) {
        matchs.insert(make_shared<Match>(date_match, equipesTemp.front(), equipesTemp.back()));
        equipesTemp.pop_back();
        equipesTemp.pop_front();
    }
    return matchs;
}

shared_ptr<Equipe> Tournoi::simulerTournoi()
{
    Date date_match((*matchs_.rbegin())->getDate());
    multiset<shared_ptr<Equipe>, FoncteurComparerParVictoires<Equipe>> equipesGagnantes;
    multiset<shared_ptr<Match>, FoncteurComparerParDate<Match>> matchsTemp = attribuerMatchs();
    matchsTemp.merge(matchs_);
    while (!matchsTemp.empty())
    {
        ++date_match;
        // Lancement des matchs
        equipesGagnantes.clear();
        transform(matchsTemp.begin(), matchsTemp.end(), inserter(equipesGagnantes, equipesGagnantes.begin()), [](auto& match) {
            return match->simuler();
        });

        matchs_.merge(matchsTemp);
        // Creation des nouveaux matchs - on associe deux equipes pour chaque match
        
        if (equipesGagnantes.size() > 1) {
            auto it = equipesGagnantes.begin();
            auto rit = equipesGagnantes.rbegin();
            while (it != rit.base()) {
                matchsTemp.insert(make_shared<Match>(date_match, *it, *rit));
                it++;
                rit++;
            }
        }
    }

    transform(matchs_.begin(), matchs_.end(), inserter(historiqueMatchs_, historiqueMatchs_.end()), [](auto& match) {
        return make_pair<Date, const Match*>(match->getDate(), match.get());
    });

    return *equipesGagnantes.begin();
}