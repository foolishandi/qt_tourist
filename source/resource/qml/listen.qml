import QtQuick 2.14
import QtQuick.Window 2.14
import QtQuick.Controls 2.3
import QtGraphicalEffects 1.0
import QtQuick.Layouts 1.3

Item {
    id:control
    visible: true
    width: 736
    height: 290

    signal sliderMoved(real v);
    signal playClicked();
    signal pauseClicked();
    signal updatePlayProgress(real v);
    property string  title: qsTr("《一起来听红楼梦》2")
    property var totalTimeValue: 20000
    property var curTimeValue : 100

    function setPlayState()
    {
        playbtn.source ="qrc:/resource/images/pause.png";
    }

    function setTitle(str)
    {
        title = str;
    }

    function setTotalTime(v)
    {
        totalTimeValue = v;
    }

    function setCurTime(v)
    {
        curTimeValue = v;
    }

    function currentTimeMMSS(time)
    {
        var sec= Math.floor(time/1000);
        var hours=Math.floor(sec/3600);
        var minutes=Math.floor((sec-hours*3600)/60);
        var seconds=sec-hours*3600-minutes*60;
        var hh,mm,ss;
        if(hours.toString().length<2)
            hh="0"+hours.toString();
        else
            hh=hours.toString();
        if(minutes.toString().length<2)
            mm="0"+minutes.toString();
        else
            mm=minutes.toString();
        if(seconds.toString().length<2)
            ss="0"+seconds.toString();
        else
            ss=seconds.toString();

        if(hh !== "00")
        {
            return hh + ":" + mm+":"+ss;
        }
        else
        {
            return mm+":"+ss;
        }

    }

    Rectangle {
        id:root
        anchors.fill: parent
        color: "#101A24"
        radius: 40
        clip:true


        Text {
            id: name
            text: title
            anchors.verticalCenter: playbtn.verticalCenter
            anchors.left: parent.left
            anchors.leftMargin: 48
            width: 520
            elide: Text.ElideRight

            font.pixelSize: 52
            font.family: "PingFang SC"
            font.weight: Font.Medium;
            color: "#FFFFFF";
            //lineHeight: 64
        }

        ParallelAnimation{ //点击动画
            id: clickedAnimation
            PropertyAnimation{
                target: playbtn
                property: "opacity"
                to: 0.5
                //from: 0
                duration: 300
            }
            PropertyAnimation{
                target: playbtn
                property: "scale"
                to: 1.3
                //from: 1
                duration: 300
            }
        }

        ParallelAnimation{ //取消点击动画
            id: releaseAnimation
            PropertyAnimation{
                target: playbtn
                property: "opacity"
                //from: 0.5
                to: 1
                duration: 300
            }
            PropertyAnimation{
                target: playbtn
                property: "scale"
                //from: 1.3
                to: 1
                duration: 300
            }
        }

        Image {
            id:playbtn
            source: "qrc:/resource/images/play.png"
            anchors.right: parent.right
            anchors.rightMargin: 48
            anchors.top: parent.top
            anchors.topMargin: 48
            width:96
            height: 96

            MouseArea
            {
                id:mouse
                anchors.fill: parent
                anchors.margins: -16

                onClicked:
                {
                    console.log("clicked")
                    if(playbtn.source == "qrc:/resource/images/pause.png")
                    {
                        playbtn.source = "qrc:/resource/images/play.png";
                        pauseClicked();

                    }
                    else
                    {
                        playbtn.source = "qrc:/resource/images/pause.png"
                        playClicked();
                    }
                }

                onPressed:
                {
                    clickedAnimation.start();
                }

                onReleased: {
                    releaseAnimation.start()
                }
            }
        }


        Slider{

            id: slider
            anchors.left: parent.left
            anchors.leftMargin: 48
            anchors.bottom: curTime.top
            anchors.bottomMargin: 16

            implicitWidth: 640;
            implicitHeight: 16;
            orientation:Qt.Horizontal
            padding: 0

            from: 0
            value: curTimeValue
            to:totalTimeValue
            stepSize: 1

            onMoved: {
                sliderMoved(slider.value)
            }

            background: Rectangle {
                id:bg
                implicitWidth: slider.implicitWidth
                implicitHeight: slider.implicitHeight
                color: "#2D4247"
                radius: 16
                layer.enabled: true
                layer.effect: OpacityMask {
                    maskSource: Rectangle {
                        width: bg.width
                        height: bg.height
                        radius: bg.radius
                    }
                }

                Rectangle {
                    y: slider.horizontal ? 0 : slider.visualPosition * parent.height
                    width: slider.horizontal ? slider.position * parent.width : parent.width
                    height: slider.horizontal ? parent.height : slider.position * parent.height
                    //                    color: "#12CFA7"
                    opacity: 1
                    radius:16
                    LinearGradient {            ///--[Mark]
                        anchors.fill: parent
                        start: Qt.point(0, 0)
                        end: Qt.point(parent.width, 0)      ///1.横向渐变
                        //end: Qt.point(0, height)     ///2.竖向渐变
                        //end: Qt.point(width, height) ///3.斜向渐变
                        gradient: Gradient {
                            GradientStop {  position: 0.0;    color: "#618CFF" }
                            GradientStop {  position: 1.0;    color: "#FF7A6A" }
                        }
                    }
                }
            }

            handle: Item {
                x: slider.leftPadding + (slider.horizontal ? slider.visualPosition * (slider.availableWidth - width) : (slider.availableWidth - width) / 2)
                y: slider.topPadding + (slider.horizontal ? (slider.availableHeight - height) / 2 : slider.visualPosition * (slider.availableHeight - height))
                implicitWidth: 28
                implicitHeight: 28
                Rectangle{
                    id:rect_out
                    anchors.fill: parent
                    radius: width/2
                    color:"#ffffff"
                }

            }
        }


        Text {
            id: curTime
            text: currentTimeMMSS(curTimeValue)
            color: "#ffffff"
            font.pixelSize: 28
            anchors.left: parent.left
            anchors.leftMargin: 48
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 48
        }


        Text {
            id: totalTime
            text: currentTimeMMSS(totalTimeValue)
            color: "#ffffff"
            font.pixelSize: 28
            anchors.right: parent.right
            anchors.rightMargin: 48
            anchors.bottom: parent.bottom
            anchors.bottomMargin: 48
        }
    }

    Component.onCompleted: {
        control.updatePlayProgress.connect(control.setCurTime)
    }

    Component.onDestruction:{
        control.updatePlayProgress.disconnect(control.setCurTime)
    }
}
