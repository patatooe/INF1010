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

//TODO: Ajouter la classe au mod�le QT
class Tournoi
{

public:
    void ajouterEquipe(const std::shared_ptr<Equipe>& equipe); // ajoute une equipe dans la liste des equipes
    const shared_ptr<Equipe>& getEquipe(const std::string& nom);
    void supprimerEquipe(const std::shared_ptr<Equipe>& equipe);
    //Retourne tous les matchs jou�s � une date donn�e
    std::vector<const Match*> getMatchsParDate(const Date&) const;
    //Retourne toutes les �quipes inscrites au tournoi dans l'ordre sp�cifi� par le comparateur
    template<typename Comparateur = FoncteurComparerParNom<Equipe>>
    std::list<std::shared_ptr<Equipe>> getEquipes() const;
    //Simule et cr�e tous les matchs jusqu'� l'obtention d'une �quipe gagnante
    void simulerTournoi();

//TODO: Ajouter le signal equipeAjoutee qui prend une r�f�rence constante de string en param�tre
//TODO: Ajouter le signal equipeGagnanteTrouvee qui prend une r�f�rence constante de QString en param�tre
//TODO: Ajouter le signal matchsTermines qui prend une r�f�rence constante de Date en param�tre

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

template<typename Comparateur>
std::list<std::shared_ptr<Equipe>> Tournoi::getEquipes() const
{
    std::list<std::shared_ptr<Equipe>> equipesTemp = equipes_;
    equipesTemp.sort(Comparateur());
    return equipesTemp;
}

#endif /* TOURNOI__ */
