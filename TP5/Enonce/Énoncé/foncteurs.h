#ifndef foncteurs_h
#define foncteurs_h

#include <memory>

using namespace std;

static double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

template<typename T>
class FoncteurComparerParVictoires
{
public:
    bool operator()(const shared_ptr<T> eA, const shared_ptr<T> eB) const
    {
        return (*this)(eA.get(), eB.get());
    }

    bool operator()(const T* eA, const T* eB) const {
        return eA->getNombreVictoires() < eB->getNombreVictoires();
    }
};

template<typename T>
class FoncteurComparerParNom
{
public:
    bool operator()(const shared_ptr<T>& eA, const shared_ptr<T>& eB) const
    {
        return (*this)(eA.get(), eB.get());
    }

    bool operator()(const T* eA, const T* eB) const {
        return eA->getNom() < eB->getNom();
    }
};

template<typename T>
class FoncteurComparerParDate
{
public:
    bool operator()(const shared_ptr<T>& eA, const shared_ptr<T>& eB) const
    {
        return (*this)(eA.get(), eB.get());
    }

    bool operator()(const unique_ptr<T>& eA, const unique_ptr<T>& eB) const
    {
        return (*this)(eA.get(), eB.get());
    }

    bool operator()(const T* eA, const T* eB) const {
        return eA->getDate() < eB->getDate();
    }
};

#endif
