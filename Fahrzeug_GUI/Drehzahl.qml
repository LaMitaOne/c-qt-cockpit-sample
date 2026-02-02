import QtQuick

Item {

    readonly property int maxDhzDisplay: 130    // maximale Drehzahl
    readonly property int minDhzDisplay: -130   // minimale Drehzahl
    readonly property int auflDhzDisplay: 5000  // Auflösung Drehzahl

    property int drehen: 0
    property double anzeigeTransparenz: 0.3

    Image{
        id: picrounds
        width: 290
        height: 290
        x: 600
        y: 325
        source: "picrounds.png"
        opacity: anzeigeTransparenz
    }

    Rectangle{
        id: dhzanzeige

        width: 60
        height: 35
        anchors.horizontalCenter: picrounds.horizontalCenter
        anchors.verticalCenter:    picrounds.verticalCenter
        anchors.verticalCenterOffset: 50
        border.color: "#595a59"
        border.width: 2
        opacity: 0.5
        color: "black"

    }

    Image{
        id: zeigDhz
        width: 180
        height: 180
        anchors.horizontalCenter: picrounds.horizontalCenter
        anchors.verticalCenter:    picrounds.verticalCenter
        rotation: minDhzDisplay+(maxDhzDisplay-minDhzDisplay)/auflDhzDisplay*drehen
        source: "picneedle.png"
        opacity: anzeigeTransparenz
        Behavior on rotation {
            SpringAnimation {
                spring: 3
                damping: 1.0
            }
        }
    }


}
