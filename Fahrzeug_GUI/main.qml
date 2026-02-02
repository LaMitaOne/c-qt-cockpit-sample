import QtQuick
import QtQuick.Window
import Qt5Compat.GraphicalEffects
import SDLF.com 1.0
import QtMultimedia

Window {
    id: root
    maximumWidth: 1000
    maximumHeight: 630
    minimumWidth: 1000
    minimumHeight: 630
    visible: true
    color: "black"
    title: qsTr("Fahrzeug")

    property bool audioactive  : true
    property int  timerhelper  : 0
    property bool engineactive : false

    Fahrverhalten   {id:fahrverhalten}
    FahrzeugInfo    {id:fahrzeuginfo}
    Steuereinheit   {id:steuereinheit}

    //==============Implementierung der QMl Dateien================
    Hintergrund{id:hintergrund}
    Infoleiste{id:infoleiste}
    Drehzahl{id:drehzahl}
    Tempo{id: tempoanzeige}
    Tankanzeige{id: tankanzeige}
    Temperatur{id: temperatur }
    Getriebe{id: getriebe}
    Sound{id:sound}
    //==========ENDE Implementierung der QMl Dateien================

    Item {
        focus: true

        Keys.onReleased: function(event){
            if(event.key === Qt.Key_Up)
            {
                if (engineactive === true)
                    if (!event.isAutoRepeat)
                    {

                        timerreibung.start()                        // Starten des Timers zur Reduzierung der Drehzahl und Geschwindigkeit
                                                                    // nach Loslassen der Beschleunigungstaste
                        sound.mediaplayer.stop()
                        sound.soundtyp = 1
                        sound.mediaplayer.source =
                                "qrc:/Car-Engine-Idle.mp3"
                        if (audioactive) sound.mediaplayer.play()
                    }
            }
            else if (event.key === Qt.Key_Down)
            {
                if (engineactive === true)
                    if (!event.isAutoRepeat)
                    {
                        sound.mediaplayer.stop()
                        sound.soundtyp = 1
                        sound.mediaplayer.source =
                                "qrc:/Car-Engine-Idle.mp3"
                        if (audioactive) sound.mediaplayer.play()
                    }
            }
        }

        Keys.onPressed: function(event) {

        // ======================== MOTOR (AN / AUS) ==================================
            if(event.key === Qt.Key_Space)
            {

                engineactive = steuereinheit.motorAn                        // Readfunktion: Auslesen vom Motor (An/Aus) und übergeben der Variable ins GUI

                if (engineactive === false)
                {
        // ----------------------- Motor an -------------------------------------------
                    steuereinheit.motorAn   = true                          // Writefunktion: Motor starten
                    engineactive            = steuereinheit.motorAn         // Readfunktion: Auslesen vom Motor (An/Aus) und übergeben der Variable ins GUI
                    tankanzeige.drehen      = tankanzeige.auflTankDisplay   // Tank voll
                    infoleiste.infoSichtbar = true                          // Die Infoleiste wird angeschaltet

                    timersensor.start()                                     // Starten des Timers zur Aktualisierung folgender Attribute
                                                                            // Geschwindigkeit, Verbrauch, Drehzahl, Tank und Strecke

                    drehzahl.anzeigeTransparenz     = 1                     // Beleuchtung des Tachos anschalten
                    getriebe.anzeigeTransparenz     = 1
                    tankanzeige.anzeigeTransparenz  = 1
                    temperatur.anzeigeTransparenz   = 1
                    tempoanzeige.anzeigeTransparenz = 1

                    // Sound - starte motor
                    sound.mediaplayer.stop()
                    sound.soundtyp = 0
                    sound.mediaplayer.source = "qrc:/Car-Engine-Starting.mp3"
                    if (audioactive) sound.timerplay.start()                   // timer startet danach engine idle sound
                    if (audioactive) sound.mediaplayer.play()
                }
                else
                {
        // ----------------------- Motor aus -------------------------------------------
                    steuereinheit.motorAn         = true                       // Writefunktion: Ausschalten des Motors
                    engineactive                  = steuereinheit.motorAn      // Readfunktion: Auslesen vom Motor (An/Aus) und übergeben der Variable ins GUI
                    tankanzeige.drehen            = 0                          // Tankanzeige auf null
                    drehzahl.drehen               = drehzahl.minDhzDisplay     // Drehzahl auf null
                    tempoanzeige.drehen           = 0                          // kmh auf null
                    infoleiste.errTempSichtbar    = false                      // erroranzeige aus
                    infoleiste.errMotorSichtbar   = false                      // erroranzeige aus
                    temperatur.drehen             = temperatur.minTempDisplay  // Temperaturanzeige auf null
                    infoleiste.infoSichtbar       = false                      // Infoleiste ausschalten
                    tankanzeige.leer              = false                      // Reserveanzeige (Tank) ausschalten
                    tankanzeige.fastleer          = false
                    infoleiste.errorblink         = false                      // Eigenschaften der erroranzeige aus
                    infoleiste.coerrTempSichtbar  = false                      // Eigenschaften der erroranzeige aus
                    infoleiste.coerrMotorSichtbar = false                      // Eigenschaften der erroranzeige aus

                    timersensor.stop()                                         // Stoppen des Timers zur Aktualisierung folgender Attribute
                                                                               // Geschwindigkeit, Verbrauch, Drehzahl, Tank und Strecke
                    timerreibung.stop()                                        // Stoppen des Timers zur Reduzierung der Drehzahl und Geschwindigkeit
                                                                               // nach Loslassen der Beschleunigungstaste

                    drehzahl.anzeigeTransparenz     = 0.3                      // Beleuchtung des Tachos ausschalten
                    getriebe.anzeigeTransparenz     = 0.3
                    tankanzeige.anzeigeTransparenz  = 0.3
                    temperatur.anzeigeTransparenz   = 0.3
                    tempoanzeige.anzeigeTransparenz = 0.3

                    // sound - stoppe motor
                    sound.soundtyp        = 0
                    sound.timerplay.stop()
                    sound.mediaplayer.stop()
                    sound.mediaplayer.source      = "qrc:/Car-Engine-Stopping.mp3"
                    if (audioactive) sound.mediaplayer.play()
                    //----------------------
                }
            }

        // ======================== Gas geben ==========================================
            else if(event.key === Qt.Key_Up)
            {

                if (engineactive === true && fahrzeuginfo.tankinhalt > 0 )
                {
                    timerreibung.stop()                                         // Stoppen des Timers zur Reduzierung der Drehzahl und Geschwindigkeit
                                                                                // nach Loslassen der Beschleunigungstaste
                    tempoanzeige.drehen      = fahrverhalten.geschwindigkeit    // Readfunktion: Auslesen der Geschwindigkeit und übergeben der Variable an die Anzeige
                    drehzahl.drehen          = fahrverhalten.drehzahl           // Readfunktion: Auslesen der Drehzahl und übergeben der Variable an die Anzeige

                    if (drehzahl.drehen < 125) drehzahl.drehen = fahrverhalten.drehzahl
                    if (tempoanzeige.drehen+tempoanzeige.minTempoDisplay < tempoanzeige.maxTempoDisplay)
                    {
                        fahrverhalten.geschwindigkeit   = 1                             // Writefunktion: Aufrufen der Funktion beschleunigen
                        tempoanzeige.drehen             = fahrverhalten.geschwindigkeit // Readfunktion: Auslesen der Geschwindigkeit und übergeben der Variable an die Anzeige
                        tempoanzeige.tempo              = fahrverhalten.geschwindigkeit // Readfunktion: Auslesen der Geschwindigkeit und übergeben der Variable an die digitale Anzeige
                    }

                    // sound - gas geben
                    if (sound.soundtyp === 1)
                    {
                        sound.mediaplayer.stop()
                        sound.soundtyp = 2
                        sound.mediaplayer.source = "qrc:/Car-Engine-Speedup.mp3"
                        if (audioactive) sound.mediaplayer.play()
                    }
                    //----------------------

                }

            }

        // ========================= bremsen ===========================================
            else  if(event.key === Qt.Key_Down)
            {
                if (engineactive === true)
                {
                    if (drehzahl.drehen > -125) drehzahl.drehen = fahrverhalten.drehzahl
                    if (tempoanzeige.drehen+tempoanzeige.minTempoDisplay > tempoanzeige.minTempoDisplay)
                    {
                        fahrverhalten.bremsen = 1                            // Writefunktion: Aufrufen der Funktion bremsen der Klasse Fahrverhalten
                        tempoanzeige.drehen = fahrverhalten.geschwindigkeit  // Readfunktion: Auslesen der Geschwindigkeit und übergeben der Variable an die Anzeige
                        tempoanzeige.tempo = fahrverhalten.geschwindigkeit   // Readfunktion: Auslesen der Geschwindigkeit und übergeben der Variable an die digitale Anzeige
                    }

                    //sound - bremsen
                    if (sound.soundtyp === 1)
                    {
                        sound.mediaplayer.stop()
                        sound.soundtyp = 3
                        sound.mediaplayer.source = "qrc:/Car-Engine-Speeddown.mp3"
                        if (audioactive) sound.mediaplayer.play()
                    }
                    //----------------------
                }

            }

        // ========================= Gang runterschalten ===============================
            else if (event.key === Qt.Key_Left)
            {
                if (engineactive === true)
                {
                    fahrverhalten.runterschalten = 1
                    getriebe.gang = fahrverhalten.gang
                }
            }

        // ========================= Gang hochschalten ===============================
            else if(event.key === Qt.Key_Right)
            {

                //gang rauf
                if (engineactive === true)
                {
                    fahrverhalten.hochschalten = 1
                    getriebe.gang = fahrverhalten.gang
                }
            }

        // ========================= Fehleranzeige ===============================
            else if(event.key === Qt.Key_Delete)
            {
                //error
                if (engineactive === true)
                    if (infoleiste.errorblink === false)
                    {
                        infoleiste.errorblink           = true
                        infoleiste.coerrTempSichtbar    = true
                        infoleiste.coerrMotorSichtbar   = true
                        infoleiste.errTempSichtbar      = true
                        infoleiste.errMotorSichtbar     = true

                    }
                    else
                    {
                        infoleiste.errorblink           = false
                        infoleiste.coerrTempSichtbar    = false
                        infoleiste.coerrMotorSichtbar   = false
                        infoleiste.errTempSichtbar      = false
                        infoleiste.errMotorSichtbar     = false

                    }
            }
        // ========================= Licht (AN / AUS) ===============================
            else if(event.key === Qt.Key_L)
            {
                if (infoleiste.lichtsichtbar === false)
                    infoleiste.lichtsichtbar = true
                else
                    infoleiste.lichtsichtbar = false  //bei motor off dann auch
            }

        // ========================= Hupe  ==========================================
            else if(event.key === Qt.Key_H)
            {
                sound.mediaplayerhupe.stop()
                sound.mediaplayerhupe.source = "qrc:/Hupe.mp3"
                if (audioactive) sound.mediaplayerhupe.play()
            }

        }
    }


       // ========================= AUDIO Button  =====================================
    MouseArea{
        id: maaudio
        width: 50
        height: 50
        hoverEnabled: true
        x: 940
        y: 10
        onEntered:
        {
           hintergrund.audioSichtbar = true
        }
        onExited:
        {
            hintergrund.audioSichtbar = false
        }
        onClicked:
        {
            audioactive  = !audioactive
            if (audioactive === false)
            {
                sound.mediaplayer.stop()
                hintergrund.audioSource = "qrc:/speaker_off.png"
            }
            else
            {
                hintergrund.audioSource = "qrc:/speaker.png"
                if (engineactive === true)
                {
                sound.soundtyp = 1
                sound.mediaplayer.source = "qrc:/Car-Engine-Idle.mp3"
                sound.mediaplayer.play()
                }
            }
        }
    }

       // ========================= Bedienungsanleitung  =================================

    MouseArea{
        id: mainfo
        width: 50
        height: 50
        hoverEnabled: true
        x: 10
        y: 10
        onEntered:
        {
            hintergrund.textInfo = true
            hintergrund.cotextInfo = true
        }
        onExited:
        {
            hintergrund.textInfo = false
            hintergrund.cotextInfo = false
        }
    }

       // ========================= Timer  =================================

    Timer               // Dieser Timer aktualisiert alle halbe Sekunde alle aufgeführte Daten
    {
        id: timersensor
        interval: 500;
        running: false;
        repeat: true
        onTriggered: {
            infoleiste.verbrauchDisplay = fahrzeuginfo.verbrauch
            temperatur.drehen           = fahrzeuginfo.temp
            tempoanzeige.drehen         = fahrverhalten.geschwindigkeit
            tempoanzeige.tempo          = fahrverhalten.geschwindigkeit
            drehzahl.drehen             = fahrverhalten.drehzahl
            infoleiste.streckeKM        = fahrzeuginfo.streckeKM
            infoleiste.gesstreckeKM     = fahrzeuginfo.gesStrecke
            tankanzeige.drehen          = fahrzeuginfo.tankinhalt

            timerhelper = timerhelper +1                //Zähler erhöhen
            if (timerhelper >= 10)                      //5 Sekunden vergangen
            {
                timerhelper = 0                         //Zurücksetzen des Zählers
                if (fahrverhalten.geschwindigkeit > 0)
                {
                    if (fahrzeuginfo.tankinhalt < 30 && fahrzeuginfo.tankinhalt >= 5 ) tankanzeige.fastleer = true // Wenn der Tank unter 30% fällt -> ReserveLampe an
                    if (fahrzeuginfo.tankinhalt === 0 ) tankanzeige.leer = true
                    fahrzeuginfo.strecke = 1            // Writefunktion: Aufruf der Funktion streckePlus der Klasse FahrzeugInfo
                }
            }
        }
    }

    Timer                             // Timer zur Reduzierung der Drehzahl und Geschwindigkeit
    {
        id: timerreibung
        interval: 500;
        running: false;
        repeat: true
        onTriggered: {
            fahrverhalten.reibung = 1 // Writefunktion: Aufruf der Funktion reibungsKraft der Klasse Fahrverhalten
        }
    }

}
