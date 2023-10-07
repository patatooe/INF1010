#include "Tournoi.h"
#include <algorithm>
#include <random>
#include <deque>

// a implémenter
bool Tournoi::ajouterEquipe(shared_ptr<Equipe> equipe)
{
    if (count(equipes_.begin(), equipes_.end(), equipe) == 0) {
        equipes_.push_back(equipe);
        return true;
    }
    return false;
}

// a implémenter
bool Tournoi::ajouterMatch(std::shared_ptr<Match> match)
{
}

//// a implémenter
std::vector<const Match*> Tournoi::getMatchsParDate(const Date& date) const 
{
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
