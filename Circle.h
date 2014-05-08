#include "Point.h"

class Circle
{

public:



	Circle( const Point& center, const float& radius )      
	{
		ctr= center ;
		radii=radius ;
	}

public:

	const Point& center() const { return ctr; }
	const float& radius() const { return radii; }


	Point& center() { return ctr; }
	float& radius() { return radii; }

public:

	const bool isInside( const Point& point ) const
	{
		return ctr.length( point ) <= radii;
	}

private:

	Point  ctr;
	float   radii;

};


