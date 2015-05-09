#include "newprojectwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QLabel>

NewProjectWindow::NewProjectWindow(QWidget *parent) : QDialog(parent)
{
    //Declaration des elements
    QFormLayout* form = new QFormLayout;
    nom = new QLineEdit;
    form->addRow("&Nom de la classe",nom);

    dateDispo = new QDateEdit;
    dateDispo->setDate(QDate::currentDate());
    QLabel* dispo = new QLabel("Date disponibilite");

    QHBoxLayout* date= new QHBoxLayout;
    date->addWidget(dispo);
    date->addWidget(dateDispo);
    QLabel* desc = new QLabel("Description du projet");
    description = new QTextEdit;

    ok = new QPushButton("OK");
    annuler = new QPushButton("Annuler");
    QHBoxLayout* choix = new QHBoxLayout;
    choix->addWidget(ok);
    choix->addWidget(annuler);



    //Disposition dans la fenetre
    QVBoxLayout* fenetre = new QVBoxLayout(this);
    fenetre->addLayout(form);
    fenetre->addLayout(date);
    fenetre->addWidget(desc);
    fenetre->addWidget(description);
    fenetre->addLayout(choix);
    setWindowTitle("Nouveau Projet");

    //connection des boutons
    connect(annuler,SIGNAL(clicked()),this,SLOT(close()));
    connect(ok,SIGNAL(clicked()),this,SLOT(creationNouveauProjet()));

}

void NewProjectWindow::creationNouveauProjet(){

}

