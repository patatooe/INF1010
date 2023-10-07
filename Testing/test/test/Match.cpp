#include "Match.h"

using namespace std;

Match::Match():
    equipeA_(nullptr),
    equipeB_(nullptr),
    scoreA_(0),
    scoreB_(0)
{
}

Match::Match(const Date& d, shared_ptr<Equipe> a, shared_ptr<Equipe> b):
    date_(d), 
    equipeA_(a), 
    equipeB_(b), 
    scoreA_(0), 
    scoreB_(0)
{
}

Match::Match(const Match& m)
{
    *this = m;
}

Match& Match::operator=(const Match& m)
{
    if (this != &m)
    {
        date_ = m.date_;
        equipeA_ = m.equipeA_;
        equipeB_ = m.equipeB_;
        scoreA_ = m.scoreA_;
        scoreB_ = m.scoreB_;
    }
    return *this;
}

void Match::setDate(const Date& d)
{
    date_ = d;
}

void Match::setEquipeA(const shared_ptr<Equipe>& eA)
{
    equipeA_ = eA;
}

void Match::setEquipeB(const shared_ptr<Equipe>& eB)
{
    equipeB_ = eB;
}

void Match::setEquipes(const shared_ptr<Equipe>& eA, const shared_ptr<Equipe>& eB)
{
    equipeA_ = eA;
    equipeB_ = eB;
}

Date Match::getDate() const {
    return date_;
}

shared_ptr<Equipe> Match::getEquipeA() const
{
    return equipeA_;
}

shared_ptr<Equipe> Match::getEquipeB() const
{
    return equipeB_;
}

int Match::getScoreA() const
{
    return scoreA_;
}

int Match::getScoreB() const
{
    return scoreB_;
}

int Match::getScore(const shared_ptr<Equipe>& equipe)
{
    if (equipe == equipeA_)
        return scoreA_;
    else if (equipe == equipeB_)
        return scoreB_;
    else {
        return -1;
    }
}

pair<int, int> Match::getScores() const
{
    return make_pair(scoreA_, scoreB_);
}

bool Match::estVictorieuse(const shared_ptr<Equipe>& equipe)
{
    if (equipe == equipeA_)
        return scoreA_ > scoreB_;
    else if (equipe == equipeB_)
        return scoreA_ < scoreB_;
    else {
        return false;
    }
}

shared_ptr<Equipe> Match::simuler()
{
    // Le nombre de manches est aleatoire, entre 3 et 10.
    unsigned int nombreDeManches = (rand() % (10 - 3)) + 3;

    for (unsigned int i = 0; i < nombreDeManches; i++)
    {
        // Attaque de l'equipe A
        if (equipeA_->calculAttaque() >= equipeB_->calculDefense()) {
            scoreA_++;
        }
        // Attaque de l'equipe B
        if (equipeB_->calculAttaque() >= equipeA_->calculDefense()) {
            scoreB_++;
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

ostream& operator<<(ostream& os, const Match& m)
{
    os << "Match - " << m.date_ << endl;
    os << m.equipeA_->getNom() << " vs " << m.equipeB_->getNom() << endl;
    os << "Resultat : " << m.scoreA_ << " - " << m.scoreB_ << endl;
    return os;
}