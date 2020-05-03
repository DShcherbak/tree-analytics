#ifndef WIDGET_H
#define WIDGET_H

#include "paintevent.h"
#include <QWidget>
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

struct Point{
    int x, y;

    Point() = default;

    Point(int _x, int _y){
        x = _x;
        y = _y;
    }
};

struct Edge{
    Point first, second;

    Edge() = default;

    Edge(const Point& _first, const Point& _second){
        first  = Point(_first.x, _first.y);
        second = Point(_second.x, _second.y);
    }

    Edge(int x1, int y1, int x2, int y2){
        first  = Point(x1, y1);
        second = Point(x2, y2);
    }
};

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    std::vector <std::pair<Point, Qt::GlobalColor>> nodes;
    std::vector <Edge> edges;
    void paintEvent(QPaintEvent * event);
    //void myPaintEvent(PaintEvent * event);
    ~Widget();

private:
    Ui::Widget *ui;
    Qt::WindowState defaultState = Qt::WindowFullScreen;
};
#endif // WIDGET_H
