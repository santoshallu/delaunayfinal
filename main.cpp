
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <GL/glut.h>
#include <math.h>
#define PI 3.1415


#include "Delaunaytriangulation.h"
using namespace std;

Delaunaytriangulation delaunay;
int main();



void displayFunction()
{
	glClearColor(1.0,1.0,1.0,0.0);   
	glClear( GL_COLOR_BUFFER_BIT );

	TriangleList triangleList = delaunay.triangleList();

	glLineWidth( 1.0 );
	for ( TriangleList::iterator itr = triangleList.begin(); itr != triangleList.end(); itr++ )
	{
		glBegin( GL_LINE_LOOP );
		glColor4f( 0.0, 1.0, 0.0, 0.0 );
		glVertex2f( (*itr)[0][0], (*itr)[0][1] );
		glVertex2f( (*itr)[1][0], (*itr)[1][1] );
		glVertex2f( (*itr)[2][0], (*itr)[2][1] );
		glEnd();
	}

	glutSwapBuffers();
}

void resizeFunction( int width, int height )
{
	glViewport( 0, 0, width, height );
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	glOrtho(0, 1,
		1, 0,
		- 1.0, 1.0 );
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();
}



void mouse(int btn, int state, int x, int y)
{
	if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)   
	{
		const double xPos = static_cast<double>(x / 1366.0);
		const double yPos = static_cast<double>( y/768.0);
		delaunay.addPoint( Point( xPos, yPos ) );
		delaunay.output();
		glutPostRedisplay();

	}



}

void process_Normal_Keys(int key, int x, int y) 
{
	if(key==GLUT_KEY_UP)
	{
	delaunay.addPoint( Point(  0.0,  0.0 ) );	
	delaunay.addPoint( Point(  0.0,1.0) );	
	delaunay.addPoint( Point( 1.0,  0.0 ) );	
	delaunay.addPoint( Point( 1.0, 1.0) );
	double x;
	double y;
	for ( unsigned int i = 0; i < 500; i++ )
	{
	  x = 0.5*cos(i*PI/180.0);
	  y =0.5*sin(i*PI/180.0);
	 delaunay.addPoint( Point( x, y ) );	
	} 
	glutPostRedisplay();
	}
	if(key==GLUT_KEY_DOWN)
	{		
	 for ( unsigned int i = 0; i <1000; i++ )
    {
        const double x = static_cast<double>( rand() ) / RAND_MAX;
        const double y = static_cast<double>( rand() ) / RAND_MAX;
        delaunay.addPoint( Point( x, y ) );
    }
	glutPostRedisplay();
	}
	if(key==GLUT_KEY_LEFT)
	{		
	delaunay.addPoint( Point(  0.0,  0.0 ) );	
	delaunay.addPoint( Point(  0.0, 1.0) );	
	delaunay.addPoint( Point( 1.0,  0.0 ) );	
	delaunay.addPoint( Point( 1.0, 1.0) );
	glutPostRedisplay();
	}	
}



int main()
{
	delaunay.initialize( Point( 0.0, 0.0 ), Point( 1.0, 1.0 ) );
	glutInitWindowPosition( 0, 0 );
	glutInitWindowSize( 1366, 768 );
	glutInitDisplayMode( GLUT_RGBA | GLUT_DOUBLE );
	glutCreateWindow( "Delaunay" );
	glutMouseFunc(mouse);
	glutDisplayFunc( displayFunction );
	glutReshapeFunc( resizeFunction );

    glutSpecialFunc( process_Normal_Keys );

	glutMainLoop();

	return 0;
}