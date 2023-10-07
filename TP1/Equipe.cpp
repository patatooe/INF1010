/************************************************************************************
*	Fichier					: Equipe.cpp
*	Auteurs					: Patricia Manarazan (1942503), Robin Plamondon (2119689)
*	Description				: Implementation de la classe Equipe
*	Date de creation		: 09/18/2022
*	Date de modification	: 09/18/2022
************************************************************************************/

#include "Equipe.h"
#include <iostream>

using namespace std;

//Le constructeur par defaut est inclu dans le constructeur par parametre pour ne pas repeter du code (voir fichier Equipe.h)
Equipe::Equipe(string nom, unsigned int annee, unsigned int mois, unsigned int jour) : nbJoueurs_(0), victoire_(0), nom_(nom),
																						joueurs_(new shared_ptr<Joueur>[capacite_]) {
	unique_ptr <Date> dateDeCreation_ = make_unique<Date>(jour, mois, annee);
	
}
//Destructeur
Equipe::~Equipe() {

}
//-----------------------------------------------------------------------------Debut des getters-------------------------------------------------------------
string Equipe::getNom() const {
	return nom_;
}
int Equipe::getNombreVictoire() const {
	return victoire_;
}
int Equipe::getNombreJoueurs() const {
	return nbJoueurs_;
}
shared_ptr<Joueur> Equipe::getJoueur(string joueur) const {
	//on boucle a traves tout le contenu de l'attribut joueurs_ pour retrouver l'objet ayant le nom demande
	for (int i = 0; i < nbJoueurs_; i++) {
		if (joueur == joueurs_[i]->getNom()) {
			return joueurs_[i];
		}
	}
	//Ce return n'est pas considere si le premiers l'est, car la boucle s'arrete
	return nullptr;
}
//------------------------------------------------------------------------Debut des fonction modificatrices----------------------------------------------------------
bool Equipe::ajouterJoueur(shared_ptr <Joueur> individu) {

	bool individuPasPresent = true;
	// on dereference individu pour avoir acces au tableau de shared_ptr et pouvoir boucler pour comparer le contenu de joueurs_ 
	//a individu et s'assurer qu'il n'est pas present
	for (int i = 0; i < nbJoueurs_; i++) {
		if (individu->getNom() == joueurs_[i]->getNom()) {
			individuPasPresent = false;
		}
	}
	//Lorsque individu n'est pas present dan joueurs_ on veut l'ajouter
	if (individuPasPresent) {
		//nombre de joueurs deja dans joueurs_ est necessairement < capacte_, donc le nouveau joueur doit etre a la position nbJoueurs_+1
		if (nbJoueurs_+1 > capacite_) {

			//Lorsque la capacite est trop petite, on l'augmente
			capacite_ = capacite_ * 2;

			//On cree un nouveau unique_ptr contenant un tableau de shared_ptr temporaire (avec la nouvelle capacite agrandie) pour stocker ce qui etait dans notre 
			//tableau initial
			unique_ptr <shared_ptr <Joueur>[]> temp (new shared_ptr<Joueur>[capacite_]);

			for (int j = 0; j < nbJoueurs_; j++) {
				
				//Pour chaque shared_ptr temporaire, il faut manuellement donner le contenu des shared_ptr originaux
				temp[j] = joueurs_[j];
			}
			//On bouge le contenu du unique_ptr temporaire vers celui original, ce qui efface la capacite originale
			joueurs_ = move(temp);
		}
		//On ajoute un nouveau shared_ptr dans le tableau et on y met individu
		joueurs_[nbJoueurs_++] = individu;
	}
	return individuPasPresent;
}
bool Equipe::supprimerJoueur(string nomJoueur) {

	bool joueurPresent = false;

	for (int i = 0; i < nbJoueurs_; i++) {
		//On verifie que le joueur soit present
		if (nomJoueur == joueurs_[i]->getNom()) {
			joueurPresent = true;
		}
		//S'il est present, on decale tout le contenu et on donne le prochain joueur a la position actuelle
		if (joueurPresent) {
			joueurs_[i] = joueurs_[i + 1];
		}
	}
	if (joueurPresent) {

		//On enleve alors le contenu du dernier joueur
		joueurs_[nbJoueurs_] = nullptr;
		//On reduit le nombre de joueurs
		nbJoueurs_--;
	}
	return joueurPresent;
}
//L'orsque appellee, la methode ajoute une victoire au nombre deja la
void Equipe::ajouterVictoire() {
	victoire_++;
}
//Affichage de l'equipe
void Equipe::afficher() const {
	cout << nom_ << endl;
	//Comme on est dans la class Equipe et comme le unique_ptr avec le tableau de shared_ptr contenant des joueurs est un attribut, 
	//on doit dereferncer 1 fois pour avoir acces a ce tableau de shared_ptr et pouvoir boucler et utiliser la fonction afficher de la classe joueur
	cout << "Joueurs : " << endl;
	for (int i = 0; i < nbJoueurs_; i++) {
		joueurs_[i]->afficher();
	}
	cout << "Nombre de victoires : " << victoire_ << endl;
}