import QtQuick
import FearGreedChart 1.0

Window {
    width: 1000
    height: 1000
    visible: true
    title: qsTr("Fear & Greed Chart")

    FearGreedChart {
        anchors {
            centerIn: parent
        }
    }
}
