#ifndef MATCH_
#define MATCH_

#include <iostream>
#include "Date.h"

using namespace std;

template <typename E>
class Match {
public:
    // Constructeur par defaut
    Match() {}

    // Constructeur par parametres
    Match(Date d, shared_ptr<E> a, shared_ptr<E> b) :date_(d), equipeA_(a), equipeB_(b),
        scoreA_(0), scoreB_(0) {}

    // Constructeur de copie
    Match(const Match& m) {
        date_ = m.date_;
        equipeA_ = m.equipeA_;
        equipeB_ = m.equipeB_;
        scoreA_ = m.scoreA_;
        scoreB_ = m.scoreB_; 
    }
    ~Match() {};
    
    // surcharge de l'operateur d'asssignation =
    Match<E>& operator=(const Match& m) {
        if (this != &m) {
            date_(m.date_);
            scoreA_(m.scoreA_);
            scoreB_(m.scoreB_);
            equipeA_(m.equipeA_);
            equipeB_(m.equipeB_);
        }
    }
    
    // Methode qui permet d’affronter les équipes selon leur force d’attaque et de défense.
    shared_ptr<E>simuler() {
        // Le nombre de manches est aleatoire, entre 3 et 10.
        unsigned int nombreDeManches = (rand() % (10 - 3)) + 3;

        for (unsigned int i = 0; i < nombreDeManches; i++)
        {
            // Attaque de l'equipe A
            if (equipeA_->calculAttaque() >= equipeB_->calculDefense()) {
                scoreA_ += 1;
            }
            // Attaque de l'equipe B
            if (equipeB_->calculAttaque() >= equipeA_->calculDefense()) {
                scoreB_ += 1;
            }
        }
        if (scoreA_ >= scoreB_) {
            ++* equipeA_;
            return equipeA_;
        }
        else {
            ++* equipeB_;
            return equipeB_;
        }

    }
    
    // Setters des attributs date_, equipeA_, equipeB_
    void setDate(Date d) { date_ = d;}
    void setEquipeA(const shared_ptr<E> & eA) { equipeA_ = eA; }
    void setEquipeB(const shared_ptr<E>  &eB) { equipeB_ = eB; }
    void setEquipes(const shared_ptr<E>  &eA, const shared_ptr<E>  & eB) { equipeA_ = eA; equipeB_ = eB;}
    
    //Methodes qui retournent respectivement le vecteur equipeA_ et equipeB_ contenant les membres de template <typename E>
    shared_ptr<E> getEquipeA() const { return equipeA_; }
    shared_ptr<E> getEquipeB() const { return equipeB_; }
    
    //Methodes qui retournent respectivement le score de l'equipe A et B
    int getScoreA() const { return scoreA_; }
    int getScoreB() const { return scoreB_; }

    // Methode qui retourne le score de l'equipe en parametre
    int getScore(const shared_ptr<E> & equipe){
        if (equipe.get() == equipeA_.get())
            return scoreA_;
        else if (equipe.get() == equipeB_.get())
            return scoreB_;
        else
            return -1;
    }

    // Cette méthode retourne une pair de valeurs entières des scores de l’équipe A et de l’équipe B.
    pair<int,int> getScores() const{
        pair<int, int> scores(scoreA_, scoreB_);
        return scores;
    }

    // Methode qui permet de vérifier que le paramètre equipe est l’équipe victorieuse selon le score obtenu des 2 équipes.Si le
    // paramètre equipe ne correspond ni à l’équipeA, ni l’équipeB on retourne faux.
    bool estVictorieuse(const shared_ptr<E>  & equipe){
        if (equipe.get() == equipeA_.get())
            return (scoreA_ > scoreB_);

        else if (equipe.get() == equipeB_.get())
            return (scoreB_ > scoreA_);

        else
            return false;
    }
    
    // Surcharge de l'operateur << qui affiche la date, le nom des 2 équipes, et le score des 2
    // équipes.
    template<typename Eq>
    friend ostream& operator<<(ostream& os, const Match<Eq>& m) {
        os << "Match - " << m.date_ << '\n'
         << m.getEquipeA()->getNom() << " vs " << m.getEquipeB()->getNom() << '\n'
          << "Resultat : " << m.getScoreA() << " - " << m.getScoreB() << '\n';
        return os;
    }
    
private:
    Date date_;
    shared_ptr<E> equipeA_;
	shared_ptr<E> equipeB_;
    int scoreA_;
	int scoreB_;
};

#endif 

