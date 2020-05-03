#include "paintevent.h"

PaintEvent::PaintEvent(std::string _type, const QRect &paintRect):QPaintEvent(paintRect)
{
    event_type = _type;
}
