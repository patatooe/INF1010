#include "Tournoi.h"
#include <algorithm>
#include <random>
#include <deque>

void Tournoi::ajouterEquipe(const shared_ptr<Equipe>& equipe)
{
    if (getEquipe(equipe->getNom()) == nullptr)
    {
        equipes_.push_back(equipe);
    }
    /*TODO: Si l'équipe existe déjà, lancer une exception de type invalid_argument.
     *      Vous devez choisir le texte lié au cas d'exception.*/
}

void Tournoi::supprimerEquipe(const std::shared_ptr<Equipe>& equipe) {
    auto it = remove(equipes_.begin(), equipes_.end(), equipe);
    if (it != equipes_.end()) {
        equipes_.erase(it, equipes_.end());
    }
    /*TODO: Si l'équipe n'existe pas, lancer une exception de type invalid_argument.
     *      Vous devez choisir le texte lié au cas d'exception.*/
}

const shared_ptr<Equipe>& Tournoi::getEquipe(const string& nom) {
    auto it = find_if(equipes_.begin(), equipes_.end(), [&nom](auto& e) {
        return e->getNom() == nom;
    });
    if (it != equipes_.end()) {
        return *it;
    }
    return nullptr;
}

std::vector<const Match*> Tournoi::getMatchsParDate(const Date& date) const {
    vector<const Match*> matchs;
    auto [first, last] = historiqueMatchs_.equal_range(date);
    transform(first, last, back_inserter(matchs), [](auto& pair) {
        return pair.second;
    });
    return matchs;
}

multiset<shared_ptr<Match>, FoncteurComparerParDate<Match>> Tournoi::attribuerMatchs()
{
    /* TODO: Si le nombre d'équipes est impair, lancer une exception de type domain_error. 
     *       Vous devez choisir le texte lié au cas d'exception.*/
    /* TODO: Si le nombre d'équipes n'est pas une puissance de 2, lancer une exception de type domain_error.
    *       Vous devez choisir le texte lié au cas d'exception.
    *       Indice: Trouver le logarithme en base 2 du nombre d'équipes, si la valeur trouvée n'est pas entière, 
    *       alors le nombre d'équipe n'est pas une puissance de 2*/
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

//Ajouter l'émission des signaux demandés
void Tournoi::simulerTournoi()
{
    multiset<shared_ptr<Equipe>, FoncteurComparerParVictoires<Equipe>> equipesGagnantes;
    multiset<shared_ptr<Match>, FoncteurComparerParDate<Match>> matchsTemp = attribuerMatchs();
    Date date_match((*matchsTemp.rbegin())->getDate());
    while (!matchsTemp.empty())
    {
        ++date_match;
        // Lancement des matchs
        equipesGagnantes.clear();
        transform(matchsTemp.begin(), matchsTemp.end(), inserter(equipesGagnantes, equipesGagnantes.begin()), [](auto& match) {
            return match->simuler();
        });

        matchs_.merge(matchsTemp);
        transform(matchs_.begin(), matchs_.end(), inserter(historiqueMatchs_, historiqueMatchs_.end()), [](auto& match) {
            return make_pair<Date, const Match*>(match->getDate(), match.get());
        });

        //TODO: Émettre le signal matchsTermines en lui passant la date du dernier match simulé
        
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

    /*TODO: Émettre le signal equipeGagnanteTrouvee en lui passant le nom de l'équipe gagnante.
     *      Notez que vous devez convertir le nom en QString.*/
}
