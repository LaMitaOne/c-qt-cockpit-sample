import QtQuick
import QtMultimedia

Item {

    property int soundtyp: 0
    property MediaPlayer mediaplayer: player
    property Timer timerplay: timeraudio
    property MediaPlayer mediaplayerhupe: playerhupe


    //-------------sounds start

    MediaPlayer {
        id: player
        audioOutput: AudioOutput {}
        source: "qrc:/Car-Engine-Starting.mp3"
        onMediaStatusChanged: {
            if (mediaStatus == MediaPlayer.EndOfMedia) //sound wiederholen
            {
                if (soundtyp === 3)
                {
                    player.source = "qrc:/Car-Engine-Speeddown.mp3"
                    player.play()
                }
                else if (soundtyp === 2)
                {
                    player.source = "qrc:/Car-Engine-Speedup.mp3"
                    player.play()
                }
                else if (soundtyp === 1)
                {
                    player.source = "qrc:/Car-Engine-Idle.mp3"
                    player.play()
                }
            }
        }
    }

    MediaPlayer {
        id: playerhupe
        audioOutput: AudioOutput {}
        source: "qrc:/Hupe.mp3"
    }

    Timer
    {
        id: timeraudio
        interval: 400;  //zu idle ton umschalten
        running: false;
        repeat: false
        onTriggered: {
            player.source = "qrc:/Car-Engine-Idle.mp3"
            soundtyp = 1
            player.play()
        }
    }

    //-------------sounds ende

}
