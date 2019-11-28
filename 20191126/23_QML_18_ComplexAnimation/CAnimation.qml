import QtQuick 2.7

Rectangle{
    id: rect
    width: 240
    height: 300
    color: "grey"

    SequentialAnimation on x{
        id: rectAnim
        running: false
        loops: Animation.Infinite

        //实现往返运动
        NumberAnimation{
            from: 0
            to: 500
            duration: 8000
            easing.type: Easing.InOutBack
        }

        NumberAnimation{
            from: 500
            to: 0
            duration: 8000
            easing.type: Easing.InOutBack
        }
        //暂停一秒钟
        PauseAnimation{
            duration: 1000
        }

//        Image{
//            id: img
//            source: "image/desktop.jpg"
//            anchors.horizontalCenter: parent.horizontalCenter
//            y: 0
//            scale: 0.1
//            opacity: 0
//            rotation: 45
//        }

        SequentialAnimation{
            id: imgAnim
            loops: Animation.Infinite
            ParallelAnimation{
                //2.7里面才有
                ScaleAnimator{
                    target: img
                    to: 1
                    duration: 1500

                }
                OpacityAnimator{
                    target: img
                    to: 1
                    duration: 2000
                }
                RotationAnimator{
                    target: img
                    to: 360
                    duration: 1500
                }
                NumberAnimation{
                    target: img
                    property: "y"
                    to: rect.height - img.height
                    easing.type: Easing.OutBounce
                    duration: 5000
                }
            }

            PauseAnimation {
                duration: 2000
            }
            ParallelAnimation{
                NumberAnimation{
                    target: img
                    property: "y"
                    to: 0
                    easing.type: Easing.OutQuad
                    duration: 1000
                }
                OpacityAnimator{
                    target: img
                    to: 0
                    duration: 1000
                }
            }
//没有找到编译错误的原因
//            MouseArea{
//                anchors.fill: parent
//                onClicked: {
//                    rectAnim.running = true
//                    imgAnim.running = true
//                }
//            }
            MouseArea{
                anchors.fill: parent
                onClicked: {
                    rectAnim.running = true
                    imgAnim.running = true
                }
            }
        }
    }
}
