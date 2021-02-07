import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.1
import QtQuick.Controls 1.4

Rectangle {
    id: recButInp2
    width: 75
    height: 75
    border.color: "black"
    border.width: 5
    anchors.right: recDigIn.right
    anchors.rightMargin: 50
    anchors.bottom: recDigIn.bottom
    anchors.bottomMargin: 30

    Image {
        id: imButInp2
        anchors.fill: recButInp2
        anchors.margins: 5
        source: "images/inBut.jpg"
        //source: "images/presInBut.png"
    }
}
