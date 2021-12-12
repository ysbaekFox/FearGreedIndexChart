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

            feerStartAngle: 90
            feerSpanAngle: 100

            greedStartAngle: -10
            greedSpanAngle: 100

            greedDialWidth: 20
            greedPenStyle: Qt.RoundCap

            backgroundColor: "#34495e"

            anchors {
                centerIn: parent
            }
        }
    }
}
