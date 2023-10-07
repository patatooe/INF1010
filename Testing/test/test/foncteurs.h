#ifndef foncteurs_h
#define foncteurs_h

#include <memory>

using namespace std;

static double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}


// implémenter les foncteurs
template <typename T>
class FoncteurComparerParVictoires {
public:
    bool operator()(const T* a, const T* b) {
        return a->getNombreVictoires() < b->getNombreVictoires();
    }

    bool operator()(shared_ptr<T> a, shared_ptr<T> b) {
        return (*this)(a.get(), b.get());
    }
};

template <typename T>
class FoncteurComparerParNom {
public:
    bool operator()(const T* a, const T* b) {
        return a->getNom() < b->getNom();
    }

    bool operator()(shared_ptr<T> a, shared_ptr<T> b) {
        return (*this)(a.get(), b.get());
    }
};

template <typename T>
class FoncteurComparerParDate {
public:
    bool operator()(const T* a, const T* b) {
        return a->getDate() < b->getDate();
    }

    bool operator()(shared_ptr<T> a, shared_ptr<T> b) {
        return (*this)(a.get(), b.get());
    }

    bool operator()(unique_ptr<T> a, unique_ptr<T> b) {
        return (*this)(a.get(), b.get());
    }
};


#endif
