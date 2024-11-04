#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QQuickView>
#include <QQmlContext>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onShowQmlButtonClicked();
    void updateQmlData();

private:
    Ui::MainWindow *ui;
    QQuickView *quickView;
    void setupQmlContext();
    QString name;
};
#endif // MAINWINDOW_H
