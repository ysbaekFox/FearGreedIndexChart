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
            width: 500
            height: 500

            startAngle: -10
            spanAngle: 200

            greedDialWidth: 20
            greedPenStyle: Qt.RoundCap

            feerBarColor: "#E6422C"
            greedBarColor: "#23FA48"
            centerPinColor: "#34495e"

            anchors {
                centerIn: parent
            }
        }
    }
}
