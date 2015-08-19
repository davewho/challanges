#ifndef POINT_H
#define POINT_H

class Point
{
	public:
		void setNumber ( double value );
		void setXpos ( double value );
		void setYpos ( double value );
		void setLayer ( double value );
		void setSqroot ( double value );
		void setEven ( bool value );
		
		double getNumber (void);
		double getXpos (void);
		double getYpos (void);
		double getLayer (void);
		double getSqroot (void);
		bool getEven (void);
		
		void findLayer ( void );
		void relPosition ( Point* ptr );
		
		void goNorth ( void );
		void goSouth ( void );
		void goWest ( void );
		void goEast ( void );
		
		void addNumber ( void );
		void addLayer ( void );
		
	private:
		double number;
		double xpos;
		double ypos;
		double layer;
		double sqroot;
		bool even;
};

#endif
