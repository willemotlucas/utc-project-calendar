#ifndef DUREE_H
#define DUREE_H

/*!
 * \file Duree.h
 * \brief Fichier permettant de definir des durees
 * \author Professeurs de LO21
 * \version 0.1
 */
#include <QTextStream>

#include "calendarexception.h"

/*! \class Duree
 *   \brief Classe permettant de manipuler des durees
 *      L'utilisation de cette classe necessite des dates valides au sens commun du terme.
 *      Declenchement d'exception dans le cas contraire
 */
class Duree{
public:
    /*! \class Constructeur a partir de heure et minute
     *  \param h heure avec h>=0
     *  \param m minute avec 0<=m<=59
     */
    Duree(unsigned int h, unsigned int m):nb_minutes(h*60+m) {if (m>59) throw CalendarException("erreur: initialisation duree invalide");}

    /*! Constructeur a partir de minute
     * \param m minute avec m>=0
     */
    Duree(unsigned int m=0):nb_minutes(m) {}
    void setDuree(unsigned int minutes) { nb_minutes=minutes; }
    void setDuree(unsigned int heures, unsigned int minutes) { if (heures==0 && minutes>59) throw CalendarException("erreur: initialisation duree invalide"); nb_minutes=heures*60+minutes; }
    unsigned int getDureeEnMinutes() const { return nb_minutes; }/*!< Retourne la duree en minutes*/
    double getDureeEnHeures() const { return double(nb_minutes)/60; } /*!< Retourne la duree en heures*/
    unsigned int getMinute() const { return nb_minutes%60; }
    unsigned int getHeure() const { return nb_minutes/60; }
    void afficher(QTextStream& f) const;/*!< Affiche la duree sous le format hhHmm*/
private:
    unsigned int nb_minutes;
};

QTextStream& operator<<(QTextStream& f, const Duree & d);
QTextStream& operator>>(QTextStream&, Duree&); //lecture format hhHmm

#endif // DUREE_H
