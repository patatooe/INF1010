//
//  Date.h


#ifndef DATE_
#define DATE_

#include <iostream>

using namespace std;

const int NBJOURDANSMOIS[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

class Date
{
public:
    Date();
    Date(unsigned int jour, unsigned int mois, unsigned int annee);
    Date(const Date &  d);
    ~Date();  
    bool operator<(const Date& d) const;
    Date operator+(unsigned int nbJours);
    Date& operator+=(unsigned int nbJours);
    Date& operator++();
    
    friend ostream& operator<<(ostream& os, const Date& d);
    
private:
    unsigned int annee_;
    unsigned int mois_;
    unsigned int jour_;
};

#endif 
