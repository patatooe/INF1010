#include <iostream>
#include "Match.h"
using namespace std;

template <typename E>
Match<E>::Match() {

}
template <typename E>
Match<E>::Match(Date d, shared_ptr<E> a, shared_ptr<E> b): date_(d), equipeA_(a), equipeB_(b), scoreA_(0), scoreB_(0) {

}
template <typename E>
Match<E>::Match(const Match& m): date_(m.date_), equipeA_(m.equipeA_), equipeB_(m.equipeB_), scoreA_(m.scoreA_), scoreB_(m.scoreB_) {

}
template <typename E>
Match<E>::~Match() {

}
template <typename E>
Match<E>& Match<E>::operator=(const Match& m) {
    if (this != &m) {
        date_(m.date_);
        scoreA_(m.scoreA_);
        scoreB_(m.scoreB_);
        equipeA_(m.equipeA_);
        equipeB_(m.equipeB_);
    }
}

template <typename E>
shared_ptr<E> Match<E>::simuler() {
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

template <typename E>
void Match<E>::setDate(Date d) {
    date_ = d;
}

template <typename E>
void Match<E>::setEquipeA(const shared_ptr<E>& eA) {
    equipeA_(eA);
}

template <typename E>
void Match<E>::setEquipeB(const shared_ptr<E>& eB) {
    equipeB_(eB);
}

template <typename E>
void Match<E>::setEquipes(const shared_ptr<E>& eA, const shared_ptr<E>& eB) {
    equipeA_(eA);
    equipeB_(eB);
}

template <typename E>
shared_ptr<E> Match<E>::getEquipeA() const {
    return equipeA_;
}

template <typename E>
shared_ptr<E> Match<E>::getEquipeB() const {
    return equipeB_;
}

template <typename E>
int Match<E>::getScoreA() const {
    return scoreA_;
}

template <typename E>
int Match<E>::getScoreB() const {
    return scoreB_;
}

template <typename E>
int Match<E>::getScore(const shared_ptr<E>& equipe) {
    if (equipe = equipeA_) {
        return scoreA_;
    } else if (equipe = equipeB_) {
        return scoreB_;
    }
}

template <typename E>
pair<int, int> Match<E>::getScores() const {
    pair<int, int> scores;
    scores.first = scoreA_;
    scores.second = scoreB_;
    return scores;
}

template <typename E>
bool Match<E>::estVictorieuse(const shared_ptr<E>& equipe) {
    if (equipe.get() == equipeA_.get()) {
        return (scoreA_ > scoreB_);
    }
    else if (equipe.get() == equipeB_.get()) {
        return (scoreB_ > scoreA_); 
    }
    else {
        return false;
    }
}