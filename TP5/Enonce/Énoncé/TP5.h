#pragma once

#include <QtWidgets/QMainWindow>
#include <QMessageBox>
#include "ui_TP5.h"
#include "Tournoi.h"

using namespace std;

class TP5 : public QMainWindow
{
    Q_OBJECT

public:
    TP5(QWidget *parent = nullptr);
    ~TP5();

private Q_SLOTS:
    void roleChoisi(const QString&);
    void ajouterEquipeListe(const std::string&);
    void ajouterJoueurListe(const std::string&);
    void afficherEquipe(QListWidgetItem*);
    void afficherJoueur(QListWidgetItem*);
    void ajouterEquipe();
    void ajouterJoueur();
    void supprimerEquipe();
    void supprimerJoueur();
    void afficherMatchs(const Date&);
    void simulerTournoi();

private:
    Ui::TP5Class ui;
    const static inline QStringList ROLES = {"Attaquant", "Defenseur", "Gardien"};

    void activerEditionAttaquant(bool);
    void activerEditionDefenseur(bool);
    void activerEditionGardien(bool);
    void resetAffichageEquipe();
    void resetAffichageJoueur();

    Tournoi tournoi;
    shared_ptr<Equipe> equipeCourante;
    QStringList dates;
};
