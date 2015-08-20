#include "Point.h"
#include <iostream>
#include <cmath>

double truncateDouble (double number);
bool isEven ( double number );

void Point::addNumber ( void )
{
	number++;
}

void Point::addLayer ( void )
{
	layer++;
}

void Point::setEven ( bool value )
{
	even = value;
}

void Point::setNumber ( double value )
{
	number = value;
}

void Point::setXpos ( double value )
{
	xpos = value;
}

void Point::setYpos ( double value )
{
	ypos = value;
}

void Point::setLayer ( double value )
{
	layer = value;
}

void Point::setSqroot ( double value )
{
	sqroot = value;
}

bool Point::getEven ( void ) // Gonna get even with you
{
	return even;
}

double Point::getNumber ( void )
{
	return number;
}

double Point::getXpos ( void )
{
	return xpos;
}

double Point::getYpos ( void )
{
	return ypos;
}

double Point::getLayer ( void )
{
	return layer;
}

double Point::getSqroot ( void )
{
	return sqroot;
}

void Point::findLayer (void)
{
	if ( isEven (sqroot) )
	{
		layer = truncateDouble( sqroot / 2 );
	}
	else
		layer = truncateDouble( ( sqroot - 1 ) / 2);
		
}	

void Point::relPosition ( Point* ptr )
{
	if ( isEven ( sqroot ) )
	{
		xpos = ( ptr -> getXpos() ) - ( ( sqroot  ) / 2 );
		ypos = ( ptr -> getYpos() ) - ( ( sqroot  ) / 2 ) + 1;
	}
	else
	{
		xpos = ( ptr -> getXpos() ) + ( ( sqroot - 1 ) / 2 );
		ypos = ( ptr -> getYpos() ) + ( ( sqroot - 1 ) / 2 );
	}
}

void Point::goNorth ( void )
{
	xpos--;
}

void Point::goSouth ( void )
{
	xpos++;
}

void Point::goWest ( void )
{
	ypos--;
}

void Point::goEast ( void )
{
	ypos++;
}
