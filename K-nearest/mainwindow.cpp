#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QInputDialog>
#include <QtMath>
#include "qmath.h"
#include <float.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   bool res= m_knearst.initialize("../nodes.csv");

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    QString text = QInputDialog::getText(this, tr("QInputDialog::getText()"), tr("Number of processes:"), QLineEdit::Normal);
//    if (event->buttons() == Qt::LeftButton)
//    {
//       QString text = QInputDialog::getText(this, tr("QInputDialog::getText()"), tr("Number of processes:"), QLineEdit::Normal);
//    }
//    else if (event->buttons() == Qt::RightButton)
//    {
//        double minDistance = DBL_MAX;
//        int clusterPosition = -1;
//        for (int i = 0; i < clusterPoints.size(); i++)
//        {
//            QPoint point(event->pos().x(), event->pos().y());
//            double dist = EuclidianDistance(point, clusterPoints[i].GetPosition());
//            if (dist < minDistance)
//            {
//                minDistance = dist;
//                clusterPosition = i;
//            }
//        }

//        clusterPoints.erase(clusterPoints.begin() + clusterPosition);

//        DetermineCluster();
//    }

//    repaint();
}


void MainWindow::keyPressEvent(QKeyEvent *event)
{
    QString text = QInputDialog::getText(this, tr("QInputDialog::getText()"), tr("Number of processes:"), QLineEdit::Normal);
//    if (event->key() == Qt::Key_Escape)
//    {
//        bool mustContinue = true;
//        while (mustContinue)
//        {
//            for (auto cluster : clusterPoints)
//                cluster.ClearPointsIndex();

//            QPair<QPoint, int> pair = qMakePair(QPoint(0, 0), 0);
//            QVector<QPair<QPoint, int>> sumPosition(clusterPoints.size(), pair);

//            for (uint i = 0; i < points.size(); i++)
//            {
//                double minDist = DBL_MAX;
//                int  poz = -1;
//                for (int j = 0; j < clusterPoints.size(); j++)
//                {
//                    double dist = EuclidianDistance(points[i], clusterPoints[j].GetPosition());
//                    if (dist < minDist)
//                    {
//                        minDist = dist;
//                        poz = j;
//                    }
//                }
//                clusterPoints[poz].AddPointIndex(i, points[i]);
//                sumPosition[poz].first.setX(sumPosition[poz].first.x() + points[i].x());
//                sumPosition[poz].first.setY(sumPosition[poz].first.y() + points[i].y());
//                sumPosition[poz].second++;
//            }

//            mustContinue = false;
//            for (int j = 0; j < clusterPoints.size(); j++)
//            {
//                QPoint newPosition = sumPosition[j].first / sumPosition[j].second;
//                if (newPosition == clusterPoints[j].GetPosition())
//                    mustContinue = true;
//                clusterPoints[j].SetPosition(newPosition);
//            }
//        }
//    }
//    else if (event->key() == Qt::Key_Shift)
//        mustPrintBox = true;
//    else if (event->key() == Qt::Key_Space)
//    {
//        srand(time(NULL));

//        QString text = QInputDialog::getText(this, tr("QInputDialog::getText()"), tr("Nr. of points:"), QLineEdit::Normal);

//        int k = text.toInt();

//        for (int i = 0; i < k; i++)
//        {
//            int pozx = rand() % 1900 + 2;
//            int pozy = rand() % 1000 + 2;
//            points.push_back(QPoint(pozx, pozy));
//        }
//    }
//    repaint();
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

//    for (auto cluster : clusterPoints)
//    {
//        p.setPen(QPen(cluster.GetColor()));
//        p.drawEllipse(cluster.GetPosition().x() - 5, cluster.GetPosition().y() - 5, 10, 10);

//        for (auto pointIndex : cluster.GetPointsIndex())
//            p.drawLine(points[pointIndex].x(), points[pointIndex].y(), cluster.GetPosition().x(), cluster.GetPosition().y());

//        if (mustPrintBox)
//        {
//            auto boundingBox=cluster.GetBoundingBox();

//            p.drawRect(boundingBox.first.x(),boundingBox.first.y(),boundingBox.second.x() - boundingBox.first.x(),boundingBox.second.y() - boundingBox.first.y());
//            p.drawText(boundingBox.first,QString::number(cluster.GetDensity()));
//        }
//    }
//    mustPrintBox = false;
}
