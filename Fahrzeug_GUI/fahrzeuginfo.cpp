#include "fahrzeuginfo.h"

FahrzeugInfo::FahrzeugInfo()
{
    // Standard-Konstruktor
}

void FahrzeugInfo::streckePlus(int)
{
    int x = 0;

    if(getGeschwindigkeit() <= 20)
    {
        x = 1;
    }
    else if(getGeschwindigkeit() > 20 && getGeschwindigkeit() <= 160)
    {
        x = 4;
    }
    else if (getGeschwindigkeit() > 160)
    {
        x =7;
    }
    gesStrecke += x;
    streckeKM  += x;
    if(tankInhalt >= 10)tankInhalt -= 10;
}


QString FahrzeugInfo::getVerbrauch() const
{
    double x = getDrehzahl()/300.0;

    return QString::number(x,'g',2);
}

int FahrzeugInfo::getTemp() const
{
    int x {};

    if ( getDrehzahl() > 4000){
        x = 30;
    }
    else  x= 90;

    return (x) ;
}

double FahrzeugInfo::getGesStrecke() const{

    return gesStrecke;
}

double FahrzeugInfo::getStreckeKM() const{
    return streckeKM;
}

int FahrzeugInfo::getTankInhalt() const
{
    return tankInhalt;
}
