/*
 * LUtil.cpp
 *
 *  Created on: 24 lis 2013
 *      Author: piot
 */

#include "LUtil.h"

bool initGL()
{
	/*projection and modelview matrices is that they're two matrices that geometry data
	is multiplied against before rendering. By setting them both to the identity matrix,
	whatever geometry you send is what you will get rendered since the identity matrix
	just gives you the same vector back when you multiply against it.*/

    //Initialize Projection Matrix
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();

    //Initialize Modelview Matrix
    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    //Initialize clear color
    glClearColor( 0.f, 0.f, 0.f, 1.f );


    //Check for error
    GLenum error = glGetError();
    if( error != GL_NO_ERROR ) {
    	printf( "Error initializing OpenGL! %s\n", gluErrorString( error ) );
        	return false;
	}
    return true;
}

void update()
{

}

void render()
{
    //Clear color buffer
    glClear( GL_COLOR_BUFFER_BIT );
    //Render quad
    glBegin( GL_QUADS );
    	glVertex2f( -0.5f, -0.5f );
        glVertex2f(  0.5f, -0.5f );
        glVertex2f(  0.5f,  0.5f );
        glVertex2f( -0.5f,  0.5f );
    glEnd();
    //Update screen
    glutSwapBuffers();
}

void runMainLoop( int val )
{
    //Frame logic
    update();
    render();

    //Run frame one more time
    glutTimerFunc( 1000 / SCREEN_FPS, runMainLoop, val );
}
