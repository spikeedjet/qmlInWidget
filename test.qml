// import QtQuick 2.15
// import QtQuick.Controls
// import QtCharts

// Item {



//     //![1]
//     ChartView {
//         title: "Line Chart"
//         anchors.fill: parent
//         antialiasing: true

//         LineSeries {
//             name: "Line"
//             XYPoint { x: 0; y: 0 }
//             XYPoint { x: 1.1; y: 2.1 }
//             XYPoint { x: 1.9; y: 3.3 }
//             XYPoint { x: 2.1; y: 2.1 }
//             XYPoint { x: 2.9; y: 4.9 }
//             XYPoint { x: 3.4; y: 3.0 }
//             XYPoint { x: 4.1; y: 3.3 }
//         }
//     }
//     //![1]


// }



// import QtQuick 2.15

// Rectangle {
//     width: 200
//     height: 200
//     color: "lightblue"

//     Text {
//         anchors.centerIn: parent
//         text: someData  // 使用从C++传递的数据
//     }
// }



// Copyright (C) 2023 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR GPL-3.0-only

import QtQuick
import QtCharts

//![1]
PolarChartView {
    title: "Two Series, Common Axes"
    anchors.fill: parent
    legend.visible: false
    antialiasing: true

    ValueAxis {
        id: axisAngular
        min: 0
        max: 20
        tickCount: 9
    }

    ValueAxis {
        id: axisRadial
        min: -0.5
        max: 1.5
    }

    SplineSeries {
        id: series1
        axisAngular: axisAngular
        axisRadial: axisRadial
        pointsVisible: true
    }

    ScatterSeries {
        id: series2
        axisAngular: axisAngular
        axisRadial: axisRadial
        markerSize: 10
    }

    // Add data dynamically to the series
    Component.onCompleted: {
        for (var i = 0; i <= 20; i++) {
            series1.append(i, Math.random());
            series2.append(i, Math.random());
        }
    }
}
//![1]

