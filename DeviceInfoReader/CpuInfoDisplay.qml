import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls 2.2
Item {
    id:root
    Column{
        Row{
            id: headerRow
            Text {
                width: 160
                    id: headerDescr
                    text: qsTr("Description")
                    font.bold: true
                    font.pixelSize: 17
                    font.italic: true
                }
            Text {

                text: qsTr("Values")
                font:headerDescr.font
            }
        }
        Row{
            id:rowParent
            width: root.width-135
            height: root.height
            spacing: 2

            Rectangle{
                id:rectDescr
                width: 160
                height: rowParent.height-2
                color:"#c5ccd3"
                border.color: "black"
                border.width: 2
                clip: true
                Rectangle{
                    width: rectDescr.width-10
                    height: rectDescr.height-10
                    anchors.verticalCenter: rectDescr.verticalCenter
                    anchors.horizontalCenter:  rectDescr.horizontalCenter
                    color:"#c5ccd3"
                    border.color: "black"
                    border.width: 1
                    clip: true
                    ListView{
                        id:descrList
                        width: rectDescr.width-10
                        height: rectDescr.height-10
                        model: mainModel.cpuInfoModelProp[1]
                        spacing:2
                        clip:true
                        delegate: Rectangle
                        {
                            width: descrList.width
                            height: 17
                            color: "#c5ccd3"
                            border.color: "black"
                            border.width: 1
                            Text {
                                text: model.modelData.descrProp
                                font.bold: true
                            }

                        }
                    }
                }
            }

            Rectangle{
                id:rectCpufInfo
                width: rowParent.width
                height: rowParent.height-2
                color:"#c5ccd3"
                border.color: "black"
                border.width: 2
                clip: true
                ListView{
                    ScrollBar.vertical: ScrollBar {
                        parent: cpuInfoCollection.parent
                        anchors.top: cpuInfoCollection.top
                        anchors.left: cpuInfoCollection.right
                        anchors.bottom: cpuInfoCollection.bottom
                    }
                    id:cpuInfoCollection
                    width: rectCpufInfo.width-10
                    height: rectCpufInfo.height-10
                    anchors.verticalCenter: rectCpufInfo.verticalCenter
                    anchors.horizontalCenter:  rectCpufInfo.horizontalCenter
                    orientation: ListView.Horizontal
                    spacing: 2
                    model: mainModel.cpuInfoModelProp
                    clip: true
                    delegate: Rectangle
                    {
                        id:rectColumns
                        width: 150
                        height: cpuInfoCollection.height
                        color:"#c5ccd3"
                        border.color: "black"
                        border.width: 1

                        ListView{
                            width: rectColumns.width
                            height: rectColumns.height-2
                            model: modelData
                            spacing:2
                            clip:true
                            delegate: Rectangle
                            {
                                border.color: "black"
                                border.width: 1
                                width: parent.width
                                height: 17
                                color: "#c5ccd3"
                                Text {
                                    text: model.modelData.descrValProp
                                }

                            }
                        }
                    }
                }
            }
        }
    }
}
