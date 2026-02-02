import QtQuick
import QtQml

Item {
    id: root

    readonly property int maxTempDisplay: 20
    readonly property int minTempDisplay: 160
    readonly property int auflTempDisplay: 80

    property double anzeigeTransparenz: 0.3
    property int drehen: minTempDisplay

    Image{
        id: tempIni
        source: "temp.png"
        width: 80
        height: 145
        x: 895
        y: 448
        opacity: anzeigeTransparenz
    }

    Image{
        id: ndlfuel

        width: 110
        height: 110
        anchors.horizontalCenter: tempIni.horizontalCenter
        anchors.verticalCenter:    tempIni.verticalCenter
        anchors.horizontalCenterOffset: -30
        anchors.verticalCenterOffset: 3
        rotation: drehen
        source: "picneedle.png"
        opacity: anzeigeTransparenz


        Behavior on rotation {

            SpringAnimation {
                spring: .05
                damping: 1.5
            }
        }

    }

}
