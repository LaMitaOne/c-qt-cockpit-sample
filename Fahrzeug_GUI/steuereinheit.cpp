#include "steuereinheit.h"

//**************** Implizierung der statischen Variable ***************************
int Steuereinheit::geschwindigkeit{};
int Steuereinheit::drehzahl{};
bool Steuereinheit::motorAn{false};
//*********************************************************************************

Steuereinheit::Steuereinheit(QObject *parent)
    : QObject{parent}
{
    // Standard-Konstruktor
}

void Steuereinheit::Motorstatus(bool)
{
    // Prüfen Motor ein/aus
    if (motorAn)  // Ein
    {
        motorAn =false;
        drehzahl = 0;
        geschwindigkeit = 0;
    }
    else          // Aus
    {
        motorAn=true;
        drehzahl = 400;     //400 unsere untere Grenze im Bild
    }
}

bool Steuereinheit::getMotorstatus() const
{
    return motorAn;
}


int Steuereinheit::getGeschwindigkeit() const
{
    return geschwindigkeit;
}

int Steuereinheit::getDrehzahl() const
{
    return drehzahl;
}

void Steuereinheit::setGeschwindigkeit(int g)
{
    geschwindigkeit = g;
}

void Steuereinheit::setDrehzahl(int d)
{
    drehzahl = d;
}

Steuereinheit::~Steuereinheit()
{
    // Standard-Destruktor
}
