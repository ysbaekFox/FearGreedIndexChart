import QtQuick
import FearGreedChart 1.0

Window {
    width: 1000
    height: 1000
    visible: true
    title: qsTr("Fear & Greed Chart")

    Rectangle {
        anchors {
            centerIn: parent
        }

        FearGreedChart {
            width: 800
            height: 800

            startAngle: -10
            spanAngle: 200

            dialWidth: 30
            penStyle: Qt.RoundCap

            feerBarColor: "#E6422C"
            greedBarColor: "#23FA48"
            centerPinColor: "#34495e"
            centerInnerColor: "white"

            anchors {
                centerIn: parent
            }
        }
    }
}
