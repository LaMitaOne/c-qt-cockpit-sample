#ifndef FAHRZEUGINFO_H
#define FAHRZEUGINFO_H

#include <QDebug>
#include <QDateTime>
#include "steuereinheit.h"

class FahrzeugInfo : public Steuereinheit
{
    Q_OBJECT

    //===================================================================================
    //======= Eigenschaften READ - WRITE , verbindung zwischen Cpp und Qt Dateien =======
    Q_PROPERTY(QString verbrauch READ getVerbrauch)
    Q_PROPERTY(int temp READ getTemp)
    Q_PROPERTY(int strecke WRITE streckePlus)
    Q_PROPERTY(int gesStrecke READ getGesStrecke)
    Q_PROPERTY(int streckeKM READ getStreckeKM)
    Q_PROPERTY(int tankinhalt READ getTankInhalt)
    //===================================================================================
    //===================================================================================

    //*************** privat variablen ***************
    double streckeKM{};
    double gesStrecke{125438.0};
    int aktuelleZeit{};
    int tankInhalt{100};
    //************************************************

public:

    explicit FahrzeugInfo();

    //********************** Public Funktionen *******
    void streckePlus(int);
    double getGesStrecke() const;
    double getStreckeKM() const;
    QString getVerbrauch() const;
    int getTemp() const;
    int getTankInhalt() const;
    //************************************************
};
#endif // FAHRZEUGINFO_H
