#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDialog>
#include <QPainter>
#include <QBrush>
#include <QTimer>
#include <QPainterPath>
namespace Ui {
class MainWindow;
}
class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QPoint Point;   /* 线条绘制点的坐标 */
protected:
    /*changeEvent 改变事件虚函数
      当前widget状态改变后触发
      该方法主要捕获改变事件,执行相关操作
    */
    virtual void changeEvent(QEvent *e);
    virtual bool eventFilter(QObject *watched, QEvent *e);
    void paintOnWidget(QWidget *w);

private slots:
    void timerUpDate();     /* 定时器槽函数 */
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    unsigned int t; /* 用来保存时间 */
    int p; /* 用来调整坐标原点 */
    QPainterPath *path;
    QTimer *timer;
};

#endif // MAINWINDOW_H
