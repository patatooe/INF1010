#ifndef TOURNOI__
#define TOURNOI__

#include <list>
#include <map>
#include <set>
#include <memory>
#include "Date.h"
#include "Match.h"
#include "Equipe.h"
#include "foncteurs.h"

class Tournoi
{
public:
    bool ajouterEquipe(std::shared_ptr<Equipe> equipe); // ajoute une equipe dans la liste des equipes
    bool ajouterMatch(std::shared_ptr<Match> match); // ajoute un match dans le multiset de matchs et met a jour l'historique de matchs
    //Retourne tous les matchs joués à une date donnée
    std::vector<const Match*> getMatchsParDate(const Date&) const;
    //Retourne toutes les équipes inscrites au tournoi dans l'ordre spécifié par le comparateur
    template<typename Comparateur = FoncteurComparerParNom<Equipe>>
    std::list<std::shared_ptr<Equipe>> getEquipes() const;

    //Simule et crée tous les matchs jusqu'à l'obtention d'une équipe gagnante
    std::shared_ptr<Equipe> simulerTournoi();
private:
    //Attribut les matchs de manière aléatoire
    multiset<shared_ptr<Match>, FoncteurComparerParDate<Match>> attribuerMatchs();

    //Tous les matchs du tournoi
    std::multiset<std::shared_ptr<Match>, FoncteurComparerParDate<Match>> matchs_;
    //Archives de tous les matchs du tournoi associés à leur date 
    std::multimap<Date, const Match*> historiqueMatchs_;
    //Toutes les équipes inscrites au tournoi
    std::list<std::shared_ptr<Equipe>> equipes_;
};

// a implementer
template<typename Comparateur>
std::list<std::shared_ptr<Equipe>> Tournoi::getEquipes() const
{

}
#endif /* TOURNOI__ */
