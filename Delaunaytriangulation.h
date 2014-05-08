
#ifndef Delaunay_Delaunay_h
#define Delaunay_Delaunay_h

#include <list>
#include <vector>

#include "Circle.h"
#include "Triangle.h"

typedef std::list<Point>    PointList;
typedef std::list<Triangle> TriangleList;

typedef std::vector<Triangle> TriangleVector;
typedef std::vector<bool>     BoolVector;
typedef std::vector<Circle>     circumCircles;

class Delaunaytriangulation
{

public:

    Delaunaytriangulation();

public:

    void initialize( const Point& minCoord, const Point& maxCoord );
    void addPoint( const Point& p );
    void output();

    void clear();
	void clearAll();

public:

    Point& minCoord() { return minCoordinate; }
     Point& maxCoord() { return maxCoordinate; }

     PointList& pointLisr() { return pointList; }
     TriangleList& triangleList() { return triangles; }
    circumCircles circles;

private:

    void checkDuplicate( TriangleVector& tri, BoolVector& boolList, Triangle t );
    Triangle getTriangle();
    Circle getCircumCenter( const Triangle& t );


private:

    Point minCoordinate;
    Point maxCoordinate;

    PointList    pointList;
    TriangleList  triangles;
	TriangleVector triangleVector;
	BoolVector  boolVector;
	

};

#endif
