
#include "Delaunaytriangulation.h"

using namespace std;

Delaunaytriangulation::Delaunaytriangulation()
{
	this->clear();
}

void Delaunaytriangulation::initialize( const Point& minCoord, const Point& maxCoord )
{
	this->clear();
	minCoordinate = minCoord;
	maxCoordinate = maxCoord;

	const Triangle initialTriangle( this->getTriangle() );
	triangles.push_back( initialTriangle );
}

void Delaunaytriangulation::addPoint( const Point& p )
{
	TriangleVector tmpTri;
	BoolVector duplicates;
	int edges=3;
	for ( TriangleList::iterator itr = triangles.begin(); itr != triangles.end(); )
	{
		const Circle circle = this->getCircumCenter( *itr );
		if ( circle.isInside( p ) )
		{
		    this->checkDuplicate( tmpTri, duplicates, Triangle( p, (*itr)[0], (*itr)[1] ) ); 
			this->checkDuplicate( tmpTri, duplicates, Triangle( p, (*itr)[1], (*itr)[2] ) );
			this->checkDuplicate( tmpTri, duplicates, Triangle( p, (*itr)[0], (*itr)[2] ) );
			itr = triangles.erase( itr );
		}
		else
		{
			itr++;

		}
	}

	for ( unsigned int i = 0; i < tmpTri.size(); i++ )
	{
		if ( !duplicates[i] )
		{
			triangles.push_back( tmpTri[i] );	
		}
	}
}

void Delaunaytriangulation::output()
{
	const Triangle initialTriangle( this->getTriangle() );
	for ( TriangleList::iterator itr = triangles.begin(); itr != triangles.end(); )
	{
		if ( initialTriangle.boundaryPoints( *itr ) )
		{
			itr = triangles.erase( itr );
		}
		else
		{
			itr++;
		}
	}
}

void Delaunaytriangulation::clear()
{
	minCoordinate.set( 0.0, 0.0 );
	maxCoordinate.set( 1.0, 1.0 );
	pointList.clear();
	triangles.clear();
}
void Delaunaytriangulation::clearAll()
{


	triangleVector.clear();
	boolVector.clear();
}

void Delaunaytriangulation::checkDuplicate( TriangleVector& tmp, BoolVector& boolean, Triangle tri )
{
	bool hasDuplicate = false;
	for ( unsigned int i = 0; i < tmp.size(); i++ )
	{
		if ( tri.isEqual( tmp[i] ) )
		{
			hasDuplicate = true;
			boolean[i] = true;
			break;
		}
	}

	if ( !hasDuplicate )
	{
		tmp.push_back( tri);
		boolean.push_back( false );
	}
}

Triangle Delaunaytriangulation::getTriangle()
{

	Point p0( -1.5, -0.5 );
	Point p1( 2, -0.5 );
	Point p2( 0.5, 2);
	return Triangle( p0, p1, p2 );
}



Circle Delaunaytriangulation::getCircumCenter( const Triangle& t )
{
	const double D = 2.0 * ( t[0][0]*(t[1][1]-t[2][1])+ t[1][0]*(t[2][1]-t[0][1])+ t[2][0]*(t[0][1]-t[1][1]) );
	const double x = ( (t[0][0]*t[0][0]+t[0][1]*t[0][1]) *(t[1][1]-t[2][1]) +  (t[1][0]*t[1][0]+t[1][1]*t[1][1]) *(t[2][1]-t[0][1]) 
		+ (t[2][0]*t[2][0]+t[2][1]*t[2][1]) *(t[0][1]-t[1][1])  ) / D;

	const double y = ( (t[0][0]*t[0][0]+t[0][1]*t[0][1]) *(t[2][0]-t[1][0]) +  (t[1][0]*t[1][0]+t[1][1]*t[1][1]) *(t[0][0]-t[2][0]) 
		+ (t[2][0]*t[2][0]+t[2][1]*t[2][1]) *(t[1][0]-t[0][0])  ) / D;  
	const Point center( x, y );

	return Circle( center, center.length( t[0] ) );
}
