

#ifndef Delaunay_Point_h
#define Delaunay_Point_h

#include <cmath>
#include <assert.h>



class Point
{

public:

	Point()
	{
		points[0] = 0.0;
		points[1] = 0.0;
	}

	Point( const float& x, const float& y )
	{
		points[0] = x;
		points[1] = y;
	}
	Point( double x, double y )
	{
		points[0] = x;
		points[1] = y;
	}

public:

	void set( const float& x, const float& y )
	{
		points[0] = x;
		points[1] = y;
	}

	const float& operator [] ( const unsigned int index ) const
	{

		return points[ index ];
	}



	const float& x() const { return points[0]; }
	const float& y() const { return points[1]; }



public:

	const double length() const
	{
		return sqrt( points[0] * points[0] + points[1] * points[1] );
	}

	const double length( const Point& point ) const
	{
		Point p( point.x() - points[0], point.y() - points[1] );
		return p.length();
	}

	const bool isEqual( const Point& p ) const
	{
		return ( points[0] == p[0] && points[1] == p[1] );
	}

private:

	float points[2];

};

#endif
