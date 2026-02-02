import QtQuick

Item {
    id:speedroot

    readonly property int maxTempoDisplay: 132      // 260 km/h
    readonly property int minTempoDisplay: -132     // 0km/h
    readonly property int auflTempoDisplay: 260     // Auflösung vom Tacho

    property double anzeigeTransparenz: 0.3
    property int tempo: 0
    property int drehen: 0

    Image{
        id: pickmh
        width: 290
        height: 290
        x: 100
        y: 325
        source: "pictacho.png"
        opacity: anzeigeTransparenz
    }

    Rectangle{
        id: fahranzeige

        width: 80
        height: 30
        anchors.horizontalCenter: pickmh.horizontalCenter
        anchors.verticalCenter:    pickmh.verticalCenter
        anchors.verticalCenterOffset: 55
        border.color: "#595a59"
        border.width: 2
        opacity: 0.5
        color: "black"

    }

    Text{
        id: te1
        anchors {
            top: fahranzeige.top;
            bottom: fahranzeige.bottom;
            right: fahranzeige.right
            margins:3
            rightMargin: 10
        }

        font.family: "Helvetica"
        font.pointSize: 15
        color: "white"
        text: tempo.toString()
        opacity: anzeigeTransparenz



    }

    Image{
        id: zeigkmh
        width: 270
        height: 270
        anchors.horizontalCenter: pickmh.horizontalCenter
        anchors.verticalCenter:    pickmh.verticalCenter
        rotation: drehen+minTempoDisplay
        source: "picneedle.png"
        opacity: anzeigeTransparenz

        Behavior on rotation {
            SpringAnimation {
                spring: 2
                damping: 1.0
            }
        }
    }


}
