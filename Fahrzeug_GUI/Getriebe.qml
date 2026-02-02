import QtQuick

Item {


    id: root_gang
    property double anzeigeTransparenz: 0.3
    property int gang: 0

    Image{
        id: gaenge
        width:  28
        height: 28
        source: if      (gang === -1) "Gang_R.png"
                else if (gang === 0) "Gang_0.png"
                else if (gang === 1) "Gang_1.png"
                else if (gang === 2) "Gang_2.png"
                else if (gang === 3) "Gang_3.png"
                else if (gang === 4) "Gang_4.png"
                else if (gang === 5) "Gang_5.png"
                else if (gang === 6) "Gang_6.png"

        x: 740
        y: 507
        opacity: anzeigeTransparenz
    }

    Text{
        id: te1
        anchors.horizontalCenter: gaenge.horizontalCenter
        anchors.verticalCenter:    gaenge.verticalCenter
        anchors.horizontalCenterOffset: -25
        font.family: "Helvetica"
        font.pointSize: 18
        color: "white"
        text: gang.toString()
        opacity: anzeigeTransparenz

        }

    //------------backwards kamera-----------
    Image{
        id: piccamera
        width: 1000
        height: 305
        x: 0
        y: 325
        visible: if (gang === -1) true
                 else             false
        source: "backcamera.png"
    }


}
