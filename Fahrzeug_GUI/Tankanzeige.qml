import QtQuick
import Qt5Compat.GraphicalEffects

Item {

    readonly property int maxTankDisplay: -30  // Tank voll
    readonly property int minTankDisplay: -150 // Tank leer
    readonly property int auflTankDisplay: 100 // Auflösung der Tankanzeige

    property double anzeigeTransparenz: 0.3
    property int drehen: 0
    property bool fastleer: false
    property bool leer: false

    Image{
        id: picfuel
        x: 15
        y: 465
        source: "Fuel.png"
        opacity: anzeigeTransparenz
    }

    Image{
        id:tanksymbol
        source: "Fuel-Station-256.png"
        width:20
        height:20
        anchors.horizontalCenter: picfuel.horizontalCenter
        anchors.verticalCenter:    picfuel.verticalCenter
        opacity: anzeigeTransparenz

    }

    ColorOverlay {
        id:tankfastleer
        anchors.fill: tanksymbol
        source: tanksymbol
        visible: fastleer
        color: "#000000"

        ColorAnimation on color{
            from:"#00000000"
            to:"#FF8800"
        }
    }

    ColorOverlay {
        id:tankleer
        anchors.fill: tanksymbol
        source: tanksymbol
        visible: leer
        color: "#000000"

        ColorAnimation on color{
            from:"#00000000"
            to:"#FF0000"
        }
    }



    Image{
        id: zeigTank
        width: 100
        height: 100
        anchors.horizontalCenter: picfuel.horizontalCenter
        anchors.verticalCenter:    picfuel.verticalCenter
        anchors.horizontalCenterOffset: 30
        rotation: minTankDisplay-drehen*(minTankDisplay-maxTankDisplay)/auflTankDisplay
        source: "picneedle.png"
        opacity: anzeigeTransparenz
        Behavior on rotation {
            SpringAnimation {
                spring: .5
                damping: 1.5
            }
        }

    }

}
