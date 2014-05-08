

#include "Point.h"

class Triangle
{

public:

    Triangle()
    {
    }

    Triangle(  const Point& p0, const Point& p1,const Point& p2 )
    {
        this->set( p0, p1, p2 );
    }

public:

    void set(
        const Point& p0,
        const Point& p1,
        const Point& p2 )
    {
        points[0] = p0;
        points[1] = p1;
        points[2] = p2;
    }

    const Point& operator [] ( const unsigned int index ) const
    {
        assert( index < 3 );
        return points[ index ];
    }

    

    const bool isEqual( const Triangle& tri ) const
    {
        return ( ( points[0].isEqual( tri[0] ) && points[1].isEqual( tri[1] ) && points[2].isEqual( tri[2] ) ) ||  ( points[0].isEqual( tri[1] ) && points[1].isEqual( tri[2] ) && points[2].isEqual( tri[0] ) ) ||
                 ( points[0].isEqual( tri[2] ) && points[1].isEqual( tri[0] ) && points[2].isEqual( tri[1] ) ) ||  ( points[0].isEqual( tri[2] ) && points[1].isEqual( tri[1] ) && points[2].isEqual( tri[0] ) ) ||
                 ( points[0].isEqual( tri[1] ) && points[1].isEqual( tri[0] ) && points[2].isEqual( tri[2] ) ) ||( points[0].isEqual( tri[0] ) && points[1].isEqual( tri[2] ) && points[2].isEqual( tri[1] ) ) );
    }

    const bool boundaryPoints( const Triangle& tri ) const
    {
        return ( points[0].isEqual( tri[0] ) || points[0].isEqual( tri[1] ) || points[0].isEqual( tri[2] ) ||
                 points[1].isEqual( tri[0] ) || points[1].isEqual( tri[1] ) || points[1].isEqual( tri[2] ) ||
                 points[2].isEqual( tri[0] ) || points[2].isEqual( tri[1] ) || points[2].isEqual( tri[2] ) );
    }

private:

    Point points[3];

};


