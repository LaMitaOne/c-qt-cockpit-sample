
#ifndef FAHRVERHALTEN_H
#define FAHRVERHALTEN_H

#include "steuereinheit.h"

class Fahrverhalten : public Steuereinheit
{
    Q_OBJECT

    //===================================================================================
    //======= Eigenschaften READ - WRITE , verbindung zwischen Cpp und Qt Dateien =======
    Q_PROPERTY(int geschwindigkeit READ getBeschleunigen  WRITE beschleunigen )
    Q_PROPERTY(int drehzahl READ getDrehzahl)
    Q_PROPERTY(int bremsen WRITE bremsen)
    Q_PROPERTY(int reibung WRITE reibungsKraft)
    Q_PROPERTY(int gang READ getGang)
    Q_PROPERTY(int hochschalten WRITE hochSchalten)
    Q_PROPERTY(int runterschalten WRITE runterSchalten)
    //===================================================================================
    //===================================================================================

    //*************** Geschwindigkeit privat variablen ***************
    const int minSpeed{};
    const int maxErsterGangSpeed{20};
    const int maxZweiterGangSpeed{60};
    const int maxDritterGangSpeed{90};
    const int maxVierterGangSpeed{160};
    const int maxFuenfterGangSpeed{220};
    const int maxSpeed{260};
    //****************************************************************

    //*************** Drehzahl privat Konst-variablen **********************
    const int maxDrehzahl{5000};
    const int maxErsteStufeDrehzahl{400};
    const int umGangDrehzahl{800};
    const int maxZweiteStufeDrehzahl{4500};
    const int maxDritteStufeDrehzahl{4500};
    const int maxVierteStufeDrehzahl{4500};
    const int maxFuenfteStufeDrehzahl{4500};
    const int minDrehzahl{400};
    //****************************************************************

    //*************** Gang Variablen und Enum ************************
    int gang{};
    bool gangSchalten{};
    const int maxGang{6};
    const int minGang{-1};

    enum Gaenge
    {
        RUECKWAERTSGANG = -1,
        LEERLAUF        =  0,
        ERSTERGANG      =  1,
        ZWEITERGANG     =  2,
        DRITTERGANG     =  3,
        VIERTERGANG     =  4,
        FUENFTERGANG     =  5,
        SECHSTEGANG     =  6
    };
    //****************************************************************

    //*************** Beschleunigen Konst-Variablen ******************
    const int langsamBeschleunigen{1};
    const int normalenBeschleunigung{25};
    const int starkeBeschleunigung{80};
    //****************************************************************

public:

    explicit Fahrverhalten();

    //*************** Public Funktionen ******************************
    void hochSchalten(int);
    void runterSchalten(int);
    void beschleunigen(int);
    void bremsen(int);
    int getBeschleunigen() const;
    int getGang() const;
    void reibungsKraft(int);
    //****************************************************************
};
#endif // FAHRVERHALTEN_H

