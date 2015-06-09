#include <QFile>
#include <QTextCodec>
#include <QtXml>
#include <QDebug>
#include <QMetaEnum>

#include "tacheunitaire.h"
#include "global.h"

QDomElement& TacheUnitaire::write(QDomDocument* dom) {
    //On crée le noeud <tache> que l'on veut ajouter et tous ses éléments
    QDomElement* tache = new QDomElement(dom->createElement("tache"));
    tache->setAttribute("type", "unitaire");
    tache->setAttribute("etat", (int)this->getEtat());

    QDomElement idTache = dom->createElement("identifiant");
    QDomText idTacheText = dom->createTextNode(this->getId());
    idTache.appendChild(idTacheText);

    QDomElement titreTache = dom->createElement("titre");
    QDomText titreTacheText = dom->createTextNode(this->titre);
    titreTache.appendChild(titreTacheText);

    QDomElement dispoTache = dom->createElement("disponibilite");
    QDomText dispoTacheText = dom->createTextNode(this->getDateDisponibilite().toString(Qt::TextDate));
    dispoTache.appendChild(dispoTacheText);

    QDomElement echeanceTache = dom->createElement("echeance");
    QDomText echeanceTacheText = dom->createTextNode(this->getDateEcheance().toString(Qt::TextDate));
    echeanceTache.appendChild(echeanceTacheText);

    QDomElement dureeTache = dom->createElement("duree");
    dureeTache.setAttribute("heure", QString::number(this->getDuree().hour()));
    dureeTache.setAttribute("minute", QString::number(this->getDuree().minute()));

    //On ajoute au noeau tache tous ses elements
    tache->appendChild(idTache);
    tache->appendChild(titreTache);
    tache->appendChild(dispoTache);
    tache->appendChild(echeanceTache);
    tache->appendChild(dureeTache);
    return *tache;
}

//    //Construction de l'arborescence du projet

//    for(Projet::contTache::iterator it = projetOuvert->begin(); it != projetOuvert->end(); ++it)
//    {
//        //On cree le noeud de l'arborescence
//        QTreeWidgetItem* tacheTree = new QTreeWidgetItem();
//        tacheTree->setText(0, (*it)->getId());

//        //Si il est composite on lui ajoute ses sous-taches
//        if(dynamic_cast<TacheComposite&>(it)){
//            for(TacheComposite::contTache::const_iterator i = it.soustaches.begin();i != it.soustaches.end();++i){
//                QTreeWidgetItem* sousTacheTree = new QTreeWidgetItem();
//                sousTacheTree->setText(1,(*i)->getId());
//                tacheTree->addChild(sousTacheTree);
//            }

//        }
//        //On relie le nom a l'arborescence
//        rootTree->addChild(tacheTree);
//    }
