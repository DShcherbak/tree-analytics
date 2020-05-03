#ifndef PAINTEVENT_H
#define PAINTEVENT_H
#include <QPaintEvent>


class PaintEvent : public QPaintEvent
{
public:
    PaintEvent(std::string _type, const QRect &paintRect);
    ~PaintEvent() = default;
    std::string event_type = "";
};

#endif // PAINTEVENT_H
