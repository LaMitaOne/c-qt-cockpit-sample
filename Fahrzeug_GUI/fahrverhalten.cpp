#include "fahrverhalten.h"

Fahrverhalten::Fahrverhalten()
{
    // Standard-Konstruktor
}


void Fahrverhalten::hochSchalten(int)
{
    if(gang < maxGang)
    {
        gang++;
        gangSchalten = true;    //Hilfsvariable

        while(getDrehzahl() > umGangDrehzahl)
            setDrehzahl(getDrehzahl() - 1);
    }
    else
        gang = maxGang; //Überschreitung vermeiden
}


void Fahrverhalten::runterSchalten(int)
{
    if(gang > minGang)
    {
        gang--;
        gangSchalten = true; //Hilfsvariable

        while(getDrehzahl() > umGangDrehzahl)
            setDrehzahl(getDrehzahl() - 1);
    }
    else gang = minGang; //Unterschreitung vermeiden
}


void Fahrverhalten::reibungsKraft(int)
{
    if(getMotorstatus()) //Prüfen (Motor-AN) Funktion aus der Basisklasse
    {
        if(getGeschwindigkeit() > 0)    setGeschwindigkeit(getGeschwindigkeit() - 1);
        if(getDrehzahl() > minDrehzahl)   setDrehzahl(getDrehzahl() - 50);
    }
}


void Fahrverhalten::beschleunigen(int)
{

    if(getMotorstatus()) //Prüfen (Motor-AN) Funktion aus der Basisklasse
    {
        switch (gang)   // (Gang Prüfen) Schrittkette
        {
        case RUECKWAERTSGANG:
            if(getDrehzahl() <= maxFuenfteStufeDrehzahl)
            {
                if (getDrehzahl() < maxDritteStufeDrehzahl && gangSchalten)
                {
                    setDrehzahl(getDrehzahl() + starkeBeschleunigung);

                }
                else if (getDrehzahl() < maxVierteStufeDrehzahl && gangSchalten)
                {
                    setDrehzahl(getDrehzahl() + normalenBeschleunigung);
                }
                else
                    setDrehzahl(getDrehzahl() + langsamBeschleunigen);
            }
            else
                gangSchalten = false;

            if(getGeschwindigkeit() < maxErsterGangSpeed)
                setGeschwindigkeit(getGeschwindigkeit() + 1);
            break;

        case LEERLAUF:
            if (getDrehzahl() < maxDrehzahl)
                setDrehzahl(getDrehzahl() + 100);
            setGeschwindigkeit(minSpeed);
            break;
        case ERSTERGANG:
            if(getDrehzahl() <= maxFuenfteStufeDrehzahl)
            {
                if (getDrehzahl() < maxDritteStufeDrehzahl && gangSchalten)
                {
                    setDrehzahl(getDrehzahl() + starkeBeschleunigung);

                }
                else if (getDrehzahl() < maxVierteStufeDrehzahl && gangSchalten)
                {
                    setDrehzahl(getDrehzahl() + normalenBeschleunigung);
                }
                else
                    setDrehzahl(getDrehzahl() + langsamBeschleunigen);
            }
            else
                gangSchalten = false;

            if(getGeschwindigkeit() < maxErsterGangSpeed)
                setGeschwindigkeit(getGeschwindigkeit() + 1);
            break;
        case ZWEITERGANG:
            if(getDrehzahl() <= maxFuenfteStufeDrehzahl)
            {
                if (getDrehzahl() < maxDritteStufeDrehzahl && gangSchalten)
                {
                    setDrehzahl(getDrehzahl() + starkeBeschleunigung);

                }
                else if (getDrehzahl() < maxVierteStufeDrehzahl && gangSchalten)
                {
                    setDrehzahl(getDrehzahl() + normalenBeschleunigung);
                }
                else
                    setDrehzahl(getDrehzahl() + langsamBeschleunigen);

            }
            else
                gangSchalten = false;

            if(getGeschwindigkeit() < maxZweiterGangSpeed)
                setGeschwindigkeit(getGeschwindigkeit() + 1);

            break;
        case DRITTERGANG:
            if(getDrehzahl() <= maxFuenfteStufeDrehzahl)
            {
                if (getDrehzahl() < maxDritteStufeDrehzahl && gangSchalten)
                {
                    setDrehzahl(getDrehzahl() + starkeBeschleunigung);

                }
                else if (getDrehzahl() < maxVierteStufeDrehzahl && gangSchalten)
                {
                    setDrehzahl(getDrehzahl() + normalenBeschleunigung);
                }
                else
                    setDrehzahl(getDrehzahl() + langsamBeschleunigen);

            }
            else
                gangSchalten = false;


            if(getGeschwindigkeit() < maxDritterGangSpeed)
                setGeschwindigkeit(getGeschwindigkeit() + 1);
            break;
        case VIERTERGANG:
            if(getDrehzahl() <= maxFuenfteStufeDrehzahl)
            {
                if (getDrehzahl() < maxDritteStufeDrehzahl && gangSchalten)
                {
                    setDrehzahl(getDrehzahl() + starkeBeschleunigung);

                }
                else if (getDrehzahl() < maxVierteStufeDrehzahl && gangSchalten)
                {
                    setDrehzahl(getDrehzahl() + normalenBeschleunigung);
                }
                else
                    setDrehzahl(getDrehzahl() + langsamBeschleunigen);

            }
            else
                gangSchalten = false;


            if(getGeschwindigkeit() < maxVierterGangSpeed)
                setGeschwindigkeit(getGeschwindigkeit() + 1);
            break;

        case FUENFTERGANG:
            if(getDrehzahl() <= maxFuenfteStufeDrehzahl)
            {
                if (getDrehzahl() < maxDritteStufeDrehzahl && gangSchalten)
                {
                    setDrehzahl(getDrehzahl() + starkeBeschleunigung);

                }
                else if (getDrehzahl() < maxVierteStufeDrehzahl && gangSchalten)
                {
                    setDrehzahl(getDrehzahl() + normalenBeschleunigung);
                }
                else
                    setDrehzahl(getDrehzahl() + 1);
            }
            else
                gangSchalten = false;

            if(getGeschwindigkeit() < maxFuenfterGangSpeed)
                setGeschwindigkeit(getGeschwindigkeit() + 1);
            break;
        case SECHSTEGANG:
            if(getDrehzahl() <= maxFuenfteStufeDrehzahl)
            {
                if (getDrehzahl() < maxDritteStufeDrehzahl && gangSchalten)
                {
                    setDrehzahl(getDrehzahl() + starkeBeschleunigung);
                }
                else if (getDrehzahl() < maxVierteStufeDrehzahl && gangSchalten)
                {
                    setDrehzahl(getDrehzahl() + normalenBeschleunigung);
                }
                else
                    setDrehzahl(getDrehzahl() + 1);
            }
            else
                gangSchalten = false;

            if(getGeschwindigkeit() < maxSpeed)
                setGeschwindigkeit(getGeschwindigkeit()+ 1);
            break;
        default:
            break;
        }
    }
}


void Fahrverhalten::bremsen(int)
{
    if(getGeschwindigkeit() > minSpeed)
    {
        if (getGeschwindigkeit() >= 2)
            setGeschwindigkeit(getGeschwindigkeit() - 2);
        else
            setGeschwindigkeit(0);
    }
    if(getDrehzahl() > minDrehzahl)
        setDrehzahl(getDrehzahl() - 80);
}


int Fahrverhalten::getBeschleunigen() const
{
    return getGeschwindigkeit();
}


int Fahrverhalten::getGang() const
{
    return gang;
}

