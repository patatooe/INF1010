#include "Date.h"

using namespace std;

Date::Date(): 
    annee_((rand() % 81) + 1942),
    mois_((rand() % 12) + 1),
    jour_((rand() % NBJOURDANSMOIS[mois_ - 1]) + 1)
{
}

Date::Date(unsigned int jour, unsigned int mois, unsigned int annee)
    : jour_(jour), mois_(mois), annee_(annee)
{
}

Date::Date(time_t time) {
    struct tm ltm;
    localtime_s(&ltm, &time);
    annee_ = 1900+ ltm.tm_year;
    mois_ = 1 + ltm.tm_mon;
    jour_ = ltm.tm_mday;
}

Date::Date(const Date &  d): Date(d.jour_, d.mois_, d.annee_)
{
}

bool Date::operator<(const Date& d) const
{
    if (annee_ == d.annee_)
    {
        if (mois_ == d.mois_)
            return jour_ < d.jour_;
        else
            return mois_ < d.mois_;
    }
    else
        return annee_ < d.annee_;
}

Date Date::operator+(unsigned int nbJours) const
{
    Date temp(*this);
    temp.jour_ += nbJours;
    while (temp.jour_ > NBJOURDANSMOIS[temp.mois_])
    {
        temp.jour_ -= NBJOURDANSMOIS[temp.mois_];
        temp.mois_++;
        if (temp.mois_ > 12)
        {
            temp.mois_ = 1;
            temp.annee_++;
        }
    }
    return temp;
}

Date& Date::operator+=(unsigned int nbJours)
{
    return *this = *this + nbJours;
}

Date& Date::operator++()
{
    return *this = *this + 1;
}

bool Date::operator==(const Date& d) const {
    return (jour_ == d.jour_ && mois_ == d.mois_ && annee_ == d.annee_);
}

ostream& operator<<(ostream& os, const Date& d)
{
    os << d.annee_ << "-" << d.mois_ << "-" << d.jour_ << endl;
    return os;
}
