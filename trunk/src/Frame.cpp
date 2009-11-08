#include "Frame.h"

#include <QtGui>

Frame::Frame()
{
}

Frame::~Frame()
{
}

void Frame::addPoint(const Point& point)
{
	_points.append(point);
}

QRectF Frame::boundingRect() const
{
	return QRectF(65535.0f / 2.0f * -1.0f, 65535.0f / 2.0f * -1.0f, 65535.0f, 65535.0f);
}

void Frame::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
	int i = 0;
	int pointCount = _points.count();
	
	while (i < pointCount)
	{
		const Point& p = _points[i];
		
		if (!p.isBlanked())
		{
			QPainterPath path;
			painter->setPen(QPen(p.color()));
			path.moveTo(p);
			
			while (++i < pointCount && ! _points[i].isBlanked())
			{
				//painter->setPen(QPen(_points[i].color()));
				path.lineTo( _points[i]);
			}
			
			if (i < pointCount)
			{
				//painter->setPen(QPen(_points[i].color()));
				path.lineTo(_points[i]);
			}

			painter->drawPath(path);
		}
		else
			i++;
	}
	
}
