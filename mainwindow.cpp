#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <QPushButton>
#include <QQuickView>
#include <QQmlEngine>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    name = "spike";

    // 创建QML视图窗口
    quickView = new QQuickView();
    quickView->setResizeMode(QQuickView::SizeRootObjectToView);

    // 连接按钮信号
    connect(ui->pushButton, &QPushButton::clicked,
            this, &MainWindow::onShowQmlButtonClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete quickView;
}

void MainWindow::onShowQmlButtonClicked()
{
    // 加载QML文件
    setupQmlContext();
    quickView->setSource(QUrl("qrc:/test.qml"));
    quickView->resize(800, 800);
    quickView->show();
}

void MainWindow::updateQmlData()
{
    // 获取QML上下文并更新数据
    QQmlContext *context = quickView->rootContext();
    context->setContextProperty("someData", "Updated data from C++!");
}

void MainWindow::setupQmlContext()
{
    // 获取QML上下文
    QQmlContext *context = quickView->rootContext();

    // 设置属性到QML上下文
    context->setContextProperty("mainWindow", this);
    context->setContextProperty("someData", name);
}

