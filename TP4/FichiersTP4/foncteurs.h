/************************************************************************************
*	Fichier					: foncteurs,h
*	Auteurs					: Patricia Manarazan (1942503), Robin Plamondon (2119689)
*	Description				: Declaration des foncteurs
*	Date de creation		: 2022/01/12
*	Date de modification	: 2022/01/12
************************************************************************************/

#ifndef foncteurs_h
#define foncteurs_h

#include <memory>

using namespace std;

static double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

/**
 * @brief Implementation du foncteur FoncteurComparerParVictoires
 * @param
 * @return Les operateur() retourne un bool de comparaison entre deux objets
*/
// implémenter les foncteurs
template <typename T>
class FoncteurComparerParVictoires {
public:
    bool operator()(const T* a, const T* b) const {
        return a->getNombreVictoires() < b->getNombreVictoires();
    }

    bool operator()(shared_ptr<T> a, shared_ptr<T> b) const {
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
    bool operator()(const T* a, const T* b) const{
        return a->getDate() < b->getDate();
    }

    bool operator()(const shared_ptr<T>& a, const shared_ptr<T>& b) const{
        return (*this)(a.get(), b.get());
    }

    bool operator()(const unique_ptr<T>& a, const unique_ptr<T>& b) const{
        return (*this)(a.get(), b.get());
    }
};

#endif
