
#include "widget.h"
#include "ui_widget.h"
#include <QPainter>

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    setFixedSize(1800, 1000); // Фиксированный размер окна
    ui->setupUi(this);

    edges.push_back({100,100,200,200});
    edges.push_back({300,300,400,400});

    nodes.push_back({{100,100},Qt::red});

    nodes.push_back({{200,200},Qt::green});
    nodes.push_back({{300,300},Qt::blue});
    nodes.push_back({{400,400},Qt::yellow});
}


Widget::~Widget()
{
    delete ui;
}


void Widget::paintEvent(QPaintEvent * event) {
    QPainter painter(this);

    QPen pen;
    pen.setWidth(3);
    pen.setBrush(Qt::red);

    painter.setPen(pen);

    for(auto & edge : edges){
        QPen pen;
        pen.setWidth(3);
        pen.setBrush(Qt::black);
        painter.setPen(pen);
        painter.drawLine(edge.first.x,
                         edge.first.y,
                         edge.second.x,
                         edge.second.y);
    }

    for(auto & node : nodes){
        QPen pen;
        pen.setWidth(3);
        pen.setBrush(node.second);
        painter.setPen(pen);
        painter.setBrush(node.second);
        painter.drawEllipse(node.first.x-50,node.first.y-50,100,100);
    }
}
