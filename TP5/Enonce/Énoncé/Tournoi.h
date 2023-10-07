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

//TODO: Ajouter la classe au modèle QT
class Tournoi
{

public:
    void ajouterEquipe(const std::shared_ptr<Equipe>& equipe); // ajoute une equipe dans la liste des equipes
    const shared_ptr<Equipe>& getEquipe(const std::string& nom);
    void supprimerEquipe(const std::shared_ptr<Equipe>& equipe);
    //Retourne tous les matchs joués à une date donnée
    std::vector<const Match*> getMatchsParDate(const Date&) const;
    //Retourne toutes les équipes inscrites au tournoi dans l'ordre spécifié par le comparateur
    template<typename Comparateur = FoncteurComparerParNom<Equipe>>
    std::list<std::shared_ptr<Equipe>> getEquipes() const;
    //Simule et crée tous les matchs jusqu'à l'obtention d'une équipe gagnante
    void simulerTournoi();

//TODO: Ajouter le signal equipeAjoutee qui prend une référence constante de string en paramètre
//TODO: Ajouter le signal equipeGagnanteTrouvee qui prend une référence constante de QString en paramètre
//TODO: Ajouter le signal matchsTermines qui prend une référence constante de Date en paramètre

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

template<typename Comparateur>
std::list<std::shared_ptr<Equipe>> Tournoi::getEquipes() const
{
    std::list<std::shared_ptr<Equipe>> equipesTemp = equipes_;
    equipesTemp.sort(Comparateur());
    return equipesTemp;
}

#endif /* TOURNOI__ */
