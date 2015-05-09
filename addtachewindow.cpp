#include "addtachewindow.h"
#include <QLabel>
#include <QDebug>
#include <QHBoxLayout>
#include <QVBoxLayout>

AddTacheWindow::AddTacheWindow(QWidget* parent):QDialog(parent){
    this->setWindowTitle("Nouvelle Tache");

    QLabel* idLabel = new QLabel("Identificateur",this);
    QLabel* titreLabel =new QLabel("Titre",this);
    QLabel* dispoLabel=new QLabel("Disponibilite",this);
    QLabel* echeanceLabel= new QLabel("Echéance",this);
    QLabel* dureeLabel= new QLabel("Durée",this);
    identificateur=new QLineEdit;
    titre= new QTextEdit;
    preemptive= new QCheckBox("preemptive",this);
    disponibilite= new QDateEdit;
    disponibilite->setDate(QDate::currentDate());
    echeance = new QDateEdit;
    echeance->setDate(QDate::currentDate());
    hDuree=new QSpinBox(this);
    hDuree->setRange(0,24);hDuree->setSuffix("heure(s)");
    mDuree=new QSpinBox(this);
    mDuree->setRange(0,59);mDuree->setSuffix("minute(s)");
    ok= new QPushButton("OK",this);
    annuler= new QPushButton("Annuler",this);

    QHBoxLayout* coucheH1= new QHBoxLayout;
    coucheH1->addWidget(idLabel);
    coucheH1->addWidget(identificateur);
    coucheH1->addWidget(preemptive);

    QHBoxLayout* coucheH2= new QHBoxLayout;
    coucheH2->addWidget(titreLabel);
    coucheH2->addWidget(titre);

    QHBoxLayout* coucheH3= new QHBoxLayout;
    coucheH3->addWidget(dispoLabel);
    coucheH3->addWidget(disponibilite);
    coucheH3->addWidget(echeanceLabel);
    coucheH3->addWidget(echeance);
    coucheH3->addWidget(dureeLabel);
    coucheH3->addWidget(hDuree);
    coucheH3->addWidget(mDuree);

    QHBoxLayout* coucheH4= new QHBoxLayout;
    coucheH4->addWidget(ok);
    coucheH4->addWidget(annuler);

    QVBoxLayout* couche= new QVBoxLayout;
    couche->addLayout(coucheH1);
    couche->addLayout(coucheH2);
    couche->addLayout(coucheH3);
    couche->addLayout(coucheH4);

    setLayout(couche);

    connect(ok,SIGNAL(clicked()),this,SLOT(ajouterTache()));
    connect(annuler,SIGNAL(clicked()),this,SLOT(close()));
}

void AddTacheWindow::ajouterTache(){

}



