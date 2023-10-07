#ifndef MATCH_
#define MATCH_

#include <iostream>
#include "Date.h"

using namespace std;

template <typename E>
class Match {
public:
    Match();
    Match(Date d, shared_ptr<E> a, shared_ptr<E> b);
    Match(const Match& m);
    ~Match();

    Match<E>& operator=(const Match& m);

    shared_ptr<E>simuler();

    void setDate(Date d);
    void setEquipeA(const shared_ptr<E>& eA);
    void setEquipeB(const shared_ptr<E>& eB);
    void setEquipes(const shared_ptr<E>& eA,
        const shared_ptr<E>& eB);

    shared_ptr<E> getEquipeA() const;
    shared_ptr<E> getEquipeB() const;

    int getScoreA() const;
    int getScoreB() const;
    int getScore(const shared_ptr<E>& equipe);
    pair<int, int> getScores() const;

    bool estVictorieuse(const shared_ptr<E>& equipe);

    template<typename Eq>
    friend ostream& operator<<(ostream& os, const Match<Eq>& m) {
        os << "Match - " << m.date_ << endl;
        os << m.getEquipeA()->getNom() << " VS " << m.getEquipeB()->getNom() << endl;
        os << "Resultat: " << m.getScoreA() << " - " << m.getScoreB() << endl;
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
