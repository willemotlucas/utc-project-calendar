#ifndef PROGRAMMATIONMANAGER_H
#define PROGRAMMATIONMANAGER_H

#include "calendarexception.h"
#include "tache.h"
#include "programmation.h"
#include <QTime>
#include <QDate>

class ProgrammationManager {
private:
    Programmation** programmations;
    unsigned int nb;
    unsigned int nbMax;
    void addItem(Programmation* t);
    Programmation* trouverProgrammation(const Tache& t) const;
public:
    ProgrammationManager();
    ~ProgrammationManager();
    ProgrammationManager(const ProgrammationManager& um);
    ProgrammationManager& operator=(const ProgrammationManager& um);
    void ajouterProgrammation(const Tache& t, const QDate& d, const QTime& h);
};

#endif // PROGRAMMATIONMANAGER_H
