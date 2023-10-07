//
//  Date.cpp
#include "Date.h"

Date::Date()
{
    annee_ = mois_ = jour_ = 0;
}

Date::Date(unsigned int jour, unsigned int mois, unsigned int annee)
    : jour_(jour), mois_(mois), annee_(annee)
{
}
Date::Date(const Date &  d): jour_(d.jour_), mois_(d.mois_), annee_(d.annee_)
{}
Date::~Date()
{
}

bool Date::operator < (const Date& d) const
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

Date Date::operator+(unsigned int nbJours)
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


ostream& operator<<(ostream& os, const Date& d)
{
    os << d.annee_ << "-" << d.mois_ << "-" << d.jour_ << endl;
    return os;
}
