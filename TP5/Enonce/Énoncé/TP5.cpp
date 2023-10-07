#include "TP5.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include "Equipe.h"
#include "Joueur.h"
#include "Defenseur.h"
#include "Attaquant.h"
#include "Gardien.h"
#include "Match.h"
#include <random>
#include <algorithm>

using namespace std;
void lectureFichier(string nomFichier, Equipe& uneEquipe)
{
    // lecture du fichier des joueurs
    ifstream fichierJoueurs;
    fichierJoueurs.open(nomFichier);
    string nom;
    unsigned int miseAuJeu;
    unsigned int buts, assists;
    random_device rd;
    default_random_engine eng(rd());
    uniform_int_distribution<int> typeJoueur(1, 3);

    while (!fichierJoueurs.eof())
    {
        fichierJoueurs >> nom >> miseAuJeu >> buts >> assists;
        if (fichierJoueurs.eof())
            break;
        // générer une valeur entre 1 et 3

        int  temp = typeJoueur(eng);
        switch (temp) {
        case 1:
            uneEquipe += (make_shared<Defenseur >(nom, miseAuJeu, buts, assists, 0.3, 1.0, 1.2, 0.5));
            break;
        case 2:
            uneEquipe += (make_shared<Attaquant >(nom, miseAuJeu, buts, assists, 1.0, 0.3, 0.9, 2, 1.7));
            break;
        case 3:
            uneEquipe += (make_shared<Gardien >(nom, miseAuJeu, buts, assists, 0.1, 1.0, 1.5, 0.8));
            break;
        }

    }

}
TP5::~TP5()
{

}

TP5::TP5(QWidget *parent)
    : QMainWindow(parent)
{
    
    ui.setupUi(this);
    QComboBox* roles = ui.tab->findChild<QComboBox*>("role");
    roles->addItem("");
    roles->addItems(ROLES);
    roles->update();

    //TODO: Ajouter le connect pour lier la sélection d'un role au Q_SLOT roleChoisi
    //TODO: Ajouter le connect pour lier le Q_SIGNAL equipeAjoutee au Q_SLOT ajouterEquipeListe
    //TODO: Ajouter le connect pour lier la sélection d'une équipe par double clique à son affichage
    //TODO: Ajouter le connect pour lier la sélection d'un joueur par double clique à son affichage
    //TODO: Ajouter le connect pour lier le bouton d'ajout d'une équipe à son ajout dans le modèle
    //TODO: Ajouter le connect pour lier le bouton d'ajout d'un joueur à son ajout dans le modèle
    //TODO: Ajouter le connect pour lier le bouton de suppression d'une équipe à son retrait du modèle
    //TODO: Ajouter le connect pour lier le bouton de suppression d'un joueur à son retrait du modèle
    //TODO: Ajouter le connect pour lier le bouton de simulation du tournoi au Q_SLOT simulerTournoi
    //TODO: Ajouter le connect pour lier le Q_SIGNAL equipeGagnanteTrouvee à la mise à jour du QLabel equipe_gagnante
    //TODO: Ajouter le connect pour lier le Q_SIGNAL matchsTermines à l'affichage des matchs

    int i = 0;
    while (i < 32) {
        shared_ptr<Equipe> equipe = make_shared<Equipe>("Equipe" + to_string(i++));
        lectureFichier("montreal.txt", *equipe);
        tournoi.ajouterEquipe(equipe);
    }

}

void TP5::simulerTournoi() {
    //TODO: Gérer les cas d'exceptions liés à la simulation du tournoi
    tournoi.simulerTournoi(); 
}

void TP5::afficherMatchs(const Date& date) {
    std::vector<const Match*> matchs = tournoi.getMatchsParDate(date);
    QTableWidget* table = ui.tab_2->findChild<QTableWidget*>("matchs");
    table->setColumnCount(table->columnCount()+1);
    table->setRowCount(std::max(table->rowCount(), static_cast<int>(matchs.size())));
    ostringstream strDate("");
    strDate << date;
    dates.append(QString::fromStdString(strDate.str()));
    table->setHorizontalHeaderLabels(dates);
    int i = 0;
    for (auto& m : matchs){
        ostringstream strMatch("");
        strMatch << *m;
        table->setItem(i,table->columnCount() - 1, new QTableWidgetItem(QString::fromStdString(strMatch.str())));
        i++;
    }
    table->resizeColumnsToContents();
    table->resizeRowsToContents();
}

void TP5::ajouterEquipe() {
    QDate date = ui.tab->findChild<QDateEdit*>("date_creation")->date();
    shared_ptr<Equipe> equipe = make_shared<Equipe>(ui.tab->findChild<QLineEdit*>("nom_equipe")->text().toStdString(),
        date.day(), date.month(), date.year());
    //TODO: Ajouter le connect pour lié le Q_SIGNAL jouerAjoutee à l'ajout du nom dans la liste
    //TODO: Gérer les cas d'exceptions liés à l'ajout d'une équipe
    tournoi.ajouterEquipe(equipe);
    equipeCourante = equipe;  
}

void TP5::ajouterJoueur() {
    QComboBox* role = ui.tab->findChild<QComboBox*>("role");
    shared_ptr<Joueur> joueur = nullptr;

    string nom = ui.tab->findChild<QLineEdit*>("nom_joueur")->text().toStdString();
    int matchsJoues = ui.tab->findChild<QLCDNumber*>("matchs_joues")->intValue();
    int nbButs = ui.tab->findChild<QLCDNumber*>("buts")->intValue();
    int nbAssists = ui.tab->findChild<QLCDNumber*>("assistances")->intValue();
    double attaque = ui.tab->findChild<QDoubleSpinBox*>("attaque")->value();
    double defense = ui.tab->findChild<QDoubleSpinBox*>("defense")->value();
    
    switch (role->currentIndex()) {
    case 0:
        //TODO: Faire l'affichage de ce cas d'exceptions au travers du GUI
        cout << "Un role doit etre selectionne!" << endl;
        return;
    case 1:
        joueur = make_shared<Attaquant>(nom, matchsJoues, nbButs, nbAssists, attaque, defense,
            ui.tab->findChild<QDoubleSpinBox*>("vitesse")->value(),
            ui.tab->findChild<QDoubleSpinBox*>("agilite")->value(),
            ui.tab->findChild<QDoubleSpinBox*>("precision")->value());
        break;
    case 2:
        joueur = make_shared<Defenseur>(nom, matchsJoues, nbButs, nbAssists, attaque, defense,
            ui.tab->findChild<QDoubleSpinBox*>("reactivite")->value(),
            ui.tab->findChild<QDoubleSpinBox*>("vision")->value());
        break;
    case 3:
        joueur = make_shared<Gardien>(nom, matchsJoues, nbButs, nbAssists, attaque, defense, 
            ui.tab->findChild<QDoubleSpinBox*>("stabilite")->value(),
            ui.tab->findChild<QDoubleSpinBox*>("reflexe")->value());
        break;
    }

    //TODO: Gérer les cas d'exceptions liés à l'ajout d'un joueur
    *equipeCourante += joueur;
}

void TP5::supprimerEquipe() {
    //TODO: Gérer les cas d'exceptions liés au retrait d'une équipe
    tournoi.supprimerEquipe(equipeCourante);
    resetAffichageJoueur();
    resetAffichageEquipe();
    QListWidget* liste = ui.tab->findChild<QListWidget*>("liste_equipes");
    QList<QListWidgetItem*> items = liste->findItems(QString::fromStdString(equipeCourante->getNom()), Qt::MatchExactly);
    for (auto& item : items) {
        delete item;
    }
    equipeCourante = nullptr;
}

void TP5::supprimerJoueur() {
    //TODO: Gérer les cas d'exceptions liés au retrait d'un joueur
    QListWidget* liste = ui.tab->findChild<QListWidget*>("liste_joueurs");
    *equipeCourante -= liste->currentItem()->text().toStdString();
    resetAffichageJoueur();

    QList<QListWidgetItem*> items = liste->findItems(liste->currentItem()->text(), Qt::MatchExactly);
    for (auto& item : items) {
        delete item;
    }
}

void TP5::ajouterEquipeListe(const std::string& equipe) {
    ui.tab->findChild<QListWidget*>("liste_equipes")->addItem(QString::fromStdString(equipe));
}

void TP5::ajouterJoueurListe(const std::string& joueur) {
    ui.tab->findChild<QListWidget*>("liste_joueurs")->addItem(QString::fromStdString(joueur));
}

void TP5::resetAffichageEquipe() {
    ui.tab->findChild<QLineEdit*>("nom_equipe")->clear();
    ui.tab->findChild<QDateEdit*>("date_creation")->clear();
    ui.tab->findChild<QLCDNumber*>("nombre_victoires")->display(0);
    ui.tab->findChild<QLCDNumber*>("defense_totale")->display(0);
    ui.tab->findChild<QLCDNumber*>("attaque_totale")->display(0);
    ui.tab->findChild<QListWidget*>("liste_joueurs")->clear();
    ui.tab->findChild<QPushButton*>("supprimer_equipe")->setEnabled(false);
}

void TP5::afficherEquipe(QListWidgetItem* item) {
    equipeCourante = tournoi.getEquipe(item->text().toStdString());
    if (equipeCourante == nullptr) {
        //TODO: Faire l'affichage de ce cas d'exceptions au travers du GUI
        cout << "L'equipe sélectionnee est introuvable dans le tournoi!" << endl;
    }
    else {
        ui.tab->findChild<QPushButton*>("supprimer_equipe")->setEnabled(true);
        ui.tab->findChild<QLineEdit*>("nom_equipe")->setText(item->text());
        QDate date(equipeCourante->getDate().getAnnee(), equipeCourante->getDate().getMois(), equipeCourante->getDate().getJour());
        ui.tab->findChild<QDateEdit*>("date_creation")->setDate(date);
        ui.tab->findChild<QLCDNumber*>("nombre_victoires")->display(equipeCourante->getNombreVictoires());
        ui.tab->findChild<QLCDNumber*>("defense_totale")->display(equipeCourante->calculDefense());
        ui.tab->findChild<QLCDNumber*>("attaque_totale")->display(equipeCourante->calculAttaque());
        QListWidget* listeJoueurs = ui.tab->findChild<QListWidget*>("liste_joueurs");
        listeJoueurs->clear();
        auto joueurs = equipeCourante->getJoueurs();
        for (auto& joueur : joueurs) {
            listeJoueurs->addItem(QString::fromStdString(joueur->getNom()));
        }
    }
}

void TP5::resetAffichageJoueur() {
    ui.tab->findChild<QLineEdit*>("nom_joueur")->clear();
    ui.tab->findChild<QDoubleSpinBox*>("vitesse")->setValue(0);
    ui.tab->findChild<QDoubleSpinBox*>("agilite")->setValue(0);
    ui.tab->findChild<QDoubleSpinBox*>("precision")->setValue(0);
    ui.tab->findChild<QDoubleSpinBox*>("reactivite")->setValue(0);
    ui.tab->findChild<QDoubleSpinBox*>("vision")->setValue(0);
    ui.tab->findChild<QDoubleSpinBox*>("stabilite")->setValue(0);
    ui.tab->findChild<QDoubleSpinBox*>("reflexe")->setValue(0);
    ui.tab->findChild<QComboBox*>("role")->setCurrentText("");
    roleChoisi("");
    ui.tab->findChild<QLCDNumber*>("matchs_joues")->display(0);
    ui.tab->findChild<QLCDNumber*>("buts")->display(0);
    ui.tab->findChild<QLCDNumber*>("assistances")->display(0);
    ui.tab->findChild<QDoubleSpinBox*>("attaque")->setValue(0);
    ui.tab->findChild<QDoubleSpinBox*>("defense")->setValue(0);
    ui.tab->findChild<QPushButton*>("supprimer_joueur")->setEnabled(false);
}

void TP5::afficherJoueur(QListWidgetItem* item) {
    shared_ptr<Joueur> joueur = equipeCourante->getJoueur(item->text().toStdString());
    if (joueur == nullptr) {
        //TODO: Faire l'affichage de ce cas d'exceptions au travers du GUI
        cout << "Le joueur sélectionne est introuvable dans l'equipe!" << endl;
    }
    else {
        ui.tab->findChild<QPushButton*>("supprimer_joueur")->setEnabled(true);
        ui.tab->findChild<QLineEdit*>("nom_joueur")->setText(item->text());
        QString role = "";
        if (Attaquant* a = dynamic_cast<Attaquant*>(joueur.get())) {
            role = ROLES[0];
            ui.tab->findChild<QDoubleSpinBox*>("vitesse")->setValue(a->getVitesse());
            ui.tab->findChild<QDoubleSpinBox*>("agilite")->setValue(a->getAgilite());
            ui.tab->findChild<QDoubleSpinBox*>("precision")->setValue(a->getPrecision());
        }
        else if (Defenseur* d = dynamic_cast<Defenseur*>(joueur.get())) {
            role = ROLES[1];
            ui.tab->findChild<QDoubleSpinBox*>("reactivite")->setValue(d->getReactivite());
            ui.tab->findChild<QDoubleSpinBox*>("vision")->setValue(d->getVision());
        }
        else if (Gardien* g = dynamic_cast<Gardien*>(joueur.get())) {
            role = ROLES[2];
            ui.tab->findChild<QDoubleSpinBox*>("stabilite")->setValue(g->getStabilite());
            ui.tab->findChild<QDoubleSpinBox*>("reflexe")->setValue(g->getReflexe());
        }
        ui.tab->findChild<QComboBox*>("role")->setCurrentText(role);
        roleChoisi(role);

        ui.tab->findChild<QLCDNumber*>("matchs_joues")->display(static_cast<int>(joueur->getMatchsJoues()));
        ui.tab->findChild<QLCDNumber*>("buts")->display(static_cast<int>(joueur->getButs()));
        ui.tab->findChild<QLCDNumber*>("assistances")->display(static_cast<int>(joueur->getAssists()));
        ui.tab->findChild<QDoubleSpinBox*>("attaque")->setValue(joueur->getAttaque());
        ui.tab->findChild<QDoubleSpinBox*>("defense")->setValue(joueur->getDefense());
    }
}

void TP5::roleChoisi(const QString& role) {
    bool activerAttaquant = false, activerDefenseur = false, activerGardien = false;
    if (role == "Attaquant") {
        activerAttaquant = true;
    }
    else if (role == "Defenseur") {
        activerDefenseur = true;
    }
    else if (role == "Gardien") {
        activerGardien = true;
    }

    activerEditionAttaquant(activerAttaquant);
    activerEditionDefenseur(activerDefenseur);
    activerEditionGardien(activerGardien);
}

void TP5::activerEditionAttaquant(bool activer) {
    ui.tab->findChild<QDoubleSpinBox*>("vitesse")->setEnabled(activer);
    ui.tab->findChild<QDoubleSpinBox*>("agilite")->setEnabled(activer);
    ui.tab->findChild<QDoubleSpinBox*>("precision")->setEnabled(activer);
}


void TP5::activerEditionDefenseur(bool activer) {
    ui.tab->findChild<QDoubleSpinBox*>("reactivite")->setEnabled(activer);
    ui.tab->findChild<QDoubleSpinBox*>("vision")->setEnabled(activer);
}


void TP5::activerEditionGardien(bool activer) {
    ui.tab->findChild<QDoubleSpinBox*>("stabilite")->setEnabled(activer);
    ui.tab->findChild<QDoubleSpinBox*>("reflexe")->setEnabled(activer);
}

