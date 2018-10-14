#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->widget->installEventFilter(this);

    p = t = 0;
    Point.setX(0);  /* 初始化起始点的纵坐标为0 */
    Point.setY(0);  /* 初始化起始点的横坐标为0 */

    path = new QPainterPath;
    timer = new QTimer(this);

    connect(timer,SIGNAL(timeout()),this,SLOT(on_pushButton_clicked()));  //关联定时器计满信号和相应的槽函数
    //timer->start(500);

}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
bool MainWindow::eventFilter(QObject *watched, QEvent *e) {

    if (watched == ui->widget) {
        if (e->type() == QEvent::Paint) {
            paintOnWidget(ui->widget);
            return true;
        }
    }
    return QWidget::eventFilter(watched, e);
}
void MainWindow::timerUpDate()
{
    t += 20;
    Point.setX(t);       /* 时间加二秒 */
    Point.setY(qrand() % 200);    /* 设置纵坐标值 */
    path->lineTo(Point);    /* */
    /* 当时间值 T大于窗口的宽度时需调整坐标原点  */
    //p -= 10;    /* 调整坐标原点 */
    if(t > width())
    {
        timer->stop();
    }
    update();
}

void MainWindow::paintOnWidget(QWidget *w)
{
    QPainter painter(w);
    painter.setPen(QPen(Qt::blue,5));
    painter.translate(p,0);
    painter.drawPath(*path);
    //painter.drawLine( 10,10, 400, 10);
}

void MainWindow::on_pushButton_clicked()
{
    timerUpDate();
    timer->start(500);
}
