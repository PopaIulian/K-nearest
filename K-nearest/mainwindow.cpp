#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include <QtMath>
#include "qmath.h"
#include <float.h>
#include "QMessageBox"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , m_knearst (KNearst(3))
{

    ui->setupUi(this);
    m_knearst.initialize("../nodes.csv");
    QString text = QInputDialog::getText(this, tr("QInputDialog::getText()"), tr("N-Normal \nW-Weight"), QLineEdit::Normal);
    AlgorithmType type;
    if (text == "N")
    {
        m_type =AlgorithmType::E_WITHOUT_WEIGHT;
    }
    else
    {
        m_type =AlgorithmType::E_WITH_WEIGHT;
    }

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{

    QPoint point(event->pos().x(), event->pos().y());
    if(m_type ==E_WITH_WEIGHT)
        m_knearst.InsertNewPoint(point);
    else
        m_knearst.InsertNewPointWeight(point);

    repaint();
}


void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Escape)
    {
        int k=m_knearst.CalculateMaxK();
        QString s = QString::number(k);

        QMessageBox::information(this, tr("Best k value"),s,QMessageBox::Ok);
    }
}

void MainWindow::paintEvent(QPaintEvent *event)
{

    QPainter p;
    p.begin(this);


    auto points =m_knearst.GetPoints();
    for(auto point : points)
    {
        p.setPen(QPen(point.GetColor()));
        p.drawEllipse(point.GetPoint(), 5,5);
    }
}
