import QtQuick
import Qt5Compat.GraphicalEffects

Item {



    id:root
    property bool lichtsichtbar      : false
    property var locale              : Qt.locale()
    property bool infoSichtbar       : false
    property double verbrauchDisplay : 0.0
    property bool errorblink         : false
    property bool errMotorSichtbar   : false
    property bool errTempSichtbar    : false
    property bool coerrMotorSichtbar : false
    property bool coerrTempSichtbar  : false
    property double streckeKM        : 0
    property double gesstreckeKM     : 0



    Image{
        id:ibar
        source: "panel.png"
        width: 150
        height: 250
        x:425
        y:320
    }

    //------light-----------
    Image{
        id: piclights
        width: 40
        height: 30
        x: 590
        y: 340
        visible: lichtsichtbar
        source: "lights.png"
    }

    //light ende ---------------

    //-----------------error start-------------

    Image{
        id: errheat
        width: 40
        height: 30
        x: 360
        y: 340
        visible: errTempSichtbar
        source: "errheat.png"
    }

    Image{
        id: errengine
        width: 40
        height: 30
        x: 310
        y: 305
        visible: errMotorSichtbar
        source: "errengine.png"
    }

    //error blinking:

    ColorOverlay {
        id:coerrheat
        anchors.fill: errheat
        source: errheat
        visible: coerrTempSichtbar
        //color: "#000000"

        ColorAnimation on color{
            from:"#00000000"
            to:"#80000000"
            duration: 1000
            running: errorblink
            loops : Animation.Infinite
            onRunningChanged: if(!running)  {coerrheat.color = "#000000"}
        }

    }

    ColorOverlay {
        id:coerrengine
        anchors.fill: errengine
        source: errengine
        visible: coerrMotorSichtbar

        ColorAnimation on color{
            from:"#00000000"
            to:"#80000000"
            duration: 1000
            running: errorblink
            loops : Animation.Infinite
            onRunningChanged: if(!running)  {coerrengine.color = "#000000"}
        }

    }

    //-----------------error ende

    Rectangle{
        id : linebottom
        width: 140
        height: 2
        visible: infoSichtbar
        anchors.horizontalCenter:  ibar.horizontalCenter
        anchors.bottom: ibar.bottom
        anchors.bottomMargin: 38
        color: "darkgrey"

    }

    Rectangle{
        id: linetop
        width: 140
        height: 2
        visible: infoSichtbar
        anchors.horizontalCenter:  ibar.horizontalCenter
        anchors.top: ibar.top
        anchors.topMargin: 25
        color: "darkgrey"

    }

    Text{
        id: textkm
        visible: infoSichtbar
        anchors.top: linebottom.bottom
        anchors.left: linebottom.left
        anchors.topMargin:2
        font.family: "Helvetica"
        font.pointSize: 8
        color: "white"
        text: "km"
    }

    Text{
        id: textkmValue
        visible:infoSichtbar
        anchors.top: textkm.bottom
        anchors.left: textkm.left
        //anchors.topMargin:2
        font.family: "Helvetica"
        font.pointSize: 13
        color: "white"
        text: gesstreckeKM.toString()
    }

    Text{
        id: textTrip
        visible: infoSichtbar
        anchors.top: linebottom.bottom
        anchors.right: linebottom.right
        anchors.topMargin:2
        font.family: "Helvetica"
        font.pointSize: 8
        color: "white"
        text: "trip"
    }

    Text{
        id: textTripValue
        visible: infoSichtbar
        anchors.top: textTrip.bottom
        anchors.right: textTrip.right
        //anchors.topMargin:2
        font.family: "Helvetica"
        font.pointSize: 13
        color: "white"
        text: streckeKM.toString()
    }

    Timer {
        id: timerDate
        interval: 500; running: true ; repeat: true
        onTriggered: {

            time.text     = new Date().toLocaleTimeString(locale, Locale.ShortFormat)
            date.text     = new Date().toLocaleDateString(locale,Locale.ShortFormat)
        }

    }

    Text {
        id: time
        visible: infoSichtbar
        anchors.bottom: linetop.top
        anchors.left: linetop.left
        anchors.topMargin:2
        font.family: "Helvetica"
        font.pointSize: 8
        color: "white"
    }

    Text {
        id: date
        visible: infoSichtbar
        anchors.bottom: linetop.top
        anchors.right: linetop.right
        anchors.topMargin:2
        font.family: "Helvetica"
        font.pointSize: 8
        color: "white"
    }

    Text {
        id: verbrauch
        visible: infoSichtbar
        anchors.centerIn: ibar

        font.family: "Helvetica"
        font.pointSize: 25
        color: "white"
        text: verbrauchDisplay
    }

    Text {
        id: verbrauchText
        visible: infoSichtbar
        anchors.top: verbrauch.bottom
        anchors.horizontalCenter: verbrauch.horizontalCenter


        font.family: "Helvetica"
        font.pointSize: 10
        color: "white"
        text: "l/100km"
    }





}
