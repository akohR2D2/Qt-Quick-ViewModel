import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

ApplicationWindow {
    id: applicationWindow
    visible: true
    width: 800
    height: 635
    title: qsTr("Device Info Reader")
    color: "#c5ccd3"

    Row{
        anchors.fill: parent
        Column {
            id: buttonArea
            width: 150
            height: parent.height
            spacing: 5
            padding: 10

            Button {
                anchors.horizontalCenter: buttonArea.horizontalCenter
                width: buttonArea.width-10
                height: 30
                id: buttonCpuInfo
                text: qsTr("Show Cpu Info")

                onClicked: {
                    pageLoader.source = "CpuInfoDisplay.qml"
                    mainModel.onButtonClicked(qsTr("cpuInfo"))
                }

            }
            Button {
                anchors.horizontalCenter: buttonArea.horizontalCenter
                width: buttonArea.width-10
                height: 30
                id: buttonST
                text: qsTr("Show ...")
                onClicked: {
                    pageLoader.source = "MakeYourPage.qml"
                    mainModel.onButtonClicked(qsTr("show..."))
                }
            }
        }

        Row {
            id: descrArea
            width: parent.width-buttonArea.width -40
//            anchors.left: buttonArea.right
            height: parent.height -24
            Text{
                width: descrArea.width
                height: 40
                text: mainModel.headerCpuInfoProp
                font.bold: true
                font.pixelSize: 20
            }
            Loader {
                width: descrArea.width
                height: descrArea.height
                anchors.topMargin:30
                id: pageLoader
                anchors.fill: parent
            }
        }
    }
}
