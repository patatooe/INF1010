#ifndef MATCH_
#define MATCH_

#include <iostream>
#include "Equipe.h"
#include "Date.h"

class Match
{
public:
    Match();
    Match(  const Date& d, 
            std::shared_ptr<Equipe> a, 
            std::shared_ptr<Equipe> b);
    Match(const Match& m);
    Match& operator=(const Match& m);
    
    void setDate(const Date& d);
    void setEquipeA(const std::shared_ptr<Equipe>& eA);
    void setEquipeB(const std::shared_ptr<Equipe>& eB);
    void setEquipes(const std::shared_ptr<Equipe>& eA,
                    const std::shared_ptr<Equipe>& eB);
    
    Date getDate() const;
    std::shared_ptr<Equipe> getEquipeA() const;
    std::shared_ptr<Equipe> getEquipeB() const;
    int getScoreA() const;
    int getScoreB() const;
    int getScore(const std::shared_ptr<Equipe> & equipe);
    std::pair<int,int> getScores() const;
    
    bool estVictorieuse(const std::shared_ptr<Equipe>  & equipe);
    std::shared_ptr<Equipe> simuler();

    friend std::ostream& operator<<(std::ostream& os, const Match& m);
    
private:
    Date date_;
    std::shared_ptr<Equipe> equipeA_;
    std::shared_ptr<Equipe> equipeB_;
    int scoreA_;
	int scoreB_;
};

#endif 
