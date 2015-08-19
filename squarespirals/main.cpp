#include <iostream>
#include <cmath>

using namespace std;

double truncateDouble (double number)
{
	int truncInt = (int) number;
	double truncDouble = (double) truncInt;
	return truncDouble;
}

bool isEven ( double number )
{
	bool result;
	
	if ( (int) truncateDouble (number) % 2 == 0 )
		result = true;
	else
		result = false;
	
	return result;
}

double lenLayer ( double layer )
{
	double length;
	
	length = 2 * layer + 1 ;
	
	return length;
}

int main ( void )
{
	// Read user input
	double size;
	double tmpTarget;
	
	Point target, center;
	Point bound1, bound2;
	
	cin >> size;
	cin >> tmpTarget;
	
	target.setNumber( tmpTarget );
	
	//cout << "size:" << size << " num:" << target.getNumber() << endl;
	
	// Get square root of the target for determining layer
	target.setSqroot ( truncateDouble ( sqrt ( target.getNumber() ) ) );
	
	// Use square root calculate target's layer
	target.findLayer();
	
	// Calculate center point
	center.setSqroot ( 1 );
	center.setNumber ( 1 );
	center.setLayer ( 1 );
	center.setXpos ( (size + 1) / 2 );
	center.setYpos ( (size + 1) / 2 );
	
	// Get coordinates of boundary roots	
	bound1.setSqroot( target.getSqroot() );
	bound1.setNumber( pow ( bound1.getSqroot() , 2 ) );
	bound1.findLayer();
	
	bound2.setSqroot ( target.getSqroot() + 1 );
	bound2.setNumber ( pow ( bound2.getSqroot() , 2 ) );
	bound2.findLayer();
	
	Point *ptr = new Point;
	*ptr = center;
	
	bound1.relPosition ( ptr );
	bound2.relPosition ( ptr );
	
	bound1.setEven ( isEven ( bound1.getNumber() ) );
	bound2.setEven ( isEven ( bound2.getNumber() ) );
	
	// Crawling
	Point pivot;
	
	pivot.setNumber ( bound1.getNumber() );
	pivot.setXpos ( bound1.getXpos() );
	pivot.setYpos ( bound1.getYpos() );
	pivot.setLayer ( bound1.getLayer() );
	
	double lengthLayer;
	bool found ;
	found = false;
	
	if ( bound1.getNumber() == target.getNumber() || bound2.getNumber() == target.getNumber() )
	{
		found = true;
		//cout << "lol root";
	}
	
	if ( bound1.getEven() && found == false )
	{
		pivot.goWest();
		pivot.addNumber();
		
		lengthLayer = 2 * ( lenLayer (bound1.getLayer() ) ) - 3;
		
		if ( pivot.getNumber() == target.getNumber() )
			found = true;
		
		while ( lengthLayer > ( lenLayer (bound1.getLayer() ) ) - 2 && found == false)
		{
			pivot.goSouth();
			pivot.addNumber();
			
			if ( pivot.getNumber() == target.getNumber() )
				found = true;
			
			lengthLayer--;
		}
		
		while ( lengthLayer > 0 && found == false )
		{
			pivot.goEast();
			pivot.addNumber();
			
			if ( pivot.getNumber() == target.getNumber() )
				found = true;
			
			lengthLayer--;
		}
	}
	else if ( found == false ) // bound1.getEven() is false
	{
		pivot.goEast();
		pivot.addNumber();
		pivot.addLayer();
		
		if ( pivot.getNumber() == target.getNumber() )
			found = true;
		
		lengthLayer = 2 * ( lenLayer (pivot.getLayer() ) )- 5 ;
		
		while ( lengthLayer > ( lenLayer (pivot.getLayer() ) - 3 ) && found == false )
		{
			pivot.goNorth();
			pivot.addNumber();
			
			if ( pivot.getNumber() == target.getNumber() )
				found = true;
			
			lengthLayer--;
		}
		
		while ( lengthLayer > 0 && found == false )
		{
			pivot.goWest();
			pivot.addNumber();
			
			if ( pivot.getNumber() == target.getNumber() )
				found = true;
				
			lengthLayer--;
		}
	}
	
	if ( found == true )
	cout << "(" << pivot.getXpos() << "," << pivot.getYpos() << ")" << endl;
	//cout << endl << bound1.getNumber() << " r:"<< bound1.getSqroot() <<"(" << bound1.getXpos() << "," << bound1.getYpos() << ")" << endl;
	//cout << endl << center.getNumber() << "(" << center.getXpos() << "," << center.getYpos() << ")" << endl;

	return 0;
}
