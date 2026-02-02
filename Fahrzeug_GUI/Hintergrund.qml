import QtQuick
import Qt5Compat.GraphicalEffects

Item {

    property bool audioSichtbar: false
    property bool textInfo: false
    property bool cotextInfo: false
    property string audioSource: "qrc:/speaker.png"
    Image{
        id: picbackground
        width: 1000
        height: 630
        source: "background.png"
    }

    //info button und panel
    Image{
        id: picinfo
        width: 50
        height: 50
        x: 10
        y: 10
        source: "info.png"
    }

    Text{
        id:teinfo
        width: 400
        height: 300
        x: 80
        y: 25
        font.bold: true
        color: "white"
        visible: textInfo
        text: "Steuerung:

     Leertaste    = Motor an/aus
     Entf             = Fehleranzeige
     Pfeil hoch   = Gas geben
     Pfeil runter = Bremsen
     Pfeil links    = Gang runter
     Pfeil rechts = Gang rauf
     Taste L        = Licht an/aus
     Taste H        = Hupe"
    }

    ColorOverlay {
        id:coinfo
        anchors.fill: picinfo
        source: picinfo
        visible: cotextInfo
        color: "#80000000"
    }

    // ----------------audio Button----------------

    Image{
        id: picaudio
        width: 50
        height: 50
        x: 940
        y: 10
        source: audioSource
    }

    ColorOverlay {
        id:coaudio
        anchors.fill: picaudio
        source: picaudio
        visible: audioSichtbar
        color: "#80000000"
    }

    //---------info ende

}
