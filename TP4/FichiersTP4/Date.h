#ifndef DATE_
#define DATE_

#include <iostream>
#include <ctime>

const unsigned int NBJOURDANSMOIS[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

class Date
{
public:
    Date();
    Date(unsigned int jour, unsigned int mois, unsigned int annee);
    Date(time_t time);
    Date(const Date &  d);

    bool operator<(const Date& d) const;
    Date operator+(unsigned int nbJours) const;
    Date& operator+=(unsigned int nbJours);
    bool operator==(const Date& d) const;
    Date& operator++();
    
    friend std::ostream& operator<<(std::ostream& os, const Date& d);
    
private:
    unsigned int annee_;
    unsigned int mois_;
    unsigned int jour_;
};

#endif 
