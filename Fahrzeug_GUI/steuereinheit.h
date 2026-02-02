#ifndef STEUEREINHEIT_H
#define STEUEREINHEIT_H

#include <QObject>
#include <QDebug>

class Steuereinheit : public QObject
{
    Q_OBJECT

       //===================================================================================
       //======= Eigenschaften READ - WRITE , verbindung zwischen Cpp und Qt Dateien =======
       Q_PROPERTY(bool motorAn READ getMotorstatus WRITE Motorstatus)
       //===================================================================================

       //*************** statische Variablen ***********************************************
       // statische Variablen existieren nur einmal für alle Objekte.
       // Sie sind an die Klasse gebunden, nicht an die Objekte.
       static int geschwindigkeit;
       static int drehzahl;
       static bool motorAn;
       //***********************************************************************************

public:

       explicit Steuereinheit(QObject *parent = nullptr);

           //********************** Public Funktionen ******************************************
           int getGeschwindigkeit() const;
           int getDrehzahl() const;
           bool getMotorstatus() const;
           void setGeschwindigkeit(int);
           void setDrehzahl(int);
           void Motorstatus(bool);
           //***********************************************************************************


           virtual ~Steuereinheit();
       };

#endif // STEUEREINHEIT_H
