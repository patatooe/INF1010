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
    //Retourne tous les matchs jou�s � une date donn�e
    std::vector<const Match*> getMatchsParDate(const Date&) const;
    //Retourne toutes les �quipes inscrites au tournoi dans l'ordre sp�cifi� par le comparateur
    template<typename Comparateur = FoncteurComparerParNom<Equipe>>
    std::list<std::shared_ptr<Equipe>> getEquipes() const;

    //Simule et cr�e tous les matchs jusqu'� l'obtention d'une �quipe gagnante
    std::shared_ptr<Equipe> simulerTournoi();
private:
    //Attribut les matchs de mani�re al�atoire
    multiset<shared_ptr<Match>, FoncteurComparerParDate<Match>> attribuerMatchs();

    //Tous les matchs du tournoi
    std::multiset<std::shared_ptr<Match>, FoncteurComparerParDate<Match>> matchs_;
    //Archives de tous les matchs du tournoi associ�s � leur date 
    std::multimap<Date, const Match*> historiqueMatchs_;
    //Toutes les �quipes inscrites au tournoi
    std::list<std::shared_ptr<Equipe>> equipes_;
};

// a implementer
template<typename Comparateur>
std::list<std::shared_ptr<Equipe>> Tournoi::getEquipes() const
{

}
#endif /* TOURNOI__ */
