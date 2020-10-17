// Template1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include "include\GL\GL.H"
#include "include\GL\GLU.H"
#include "include\GL\glut.h"

	//glColor4f(1.0f, 0.0f, 0.0f, 1.0f);//Red;
	//glColor4f(0.0f, 1.0f, 0.0f, 1.0f);//Green
	//glColor4f(0.0f, 0.0f, 1.0f, 1.0f);//Blue;
	//glColor4f(1.0f, 0.5f, 0.0f, 1.0f);//orange
	//glColor4f(1.0f, 0.0f, 1.0f, 1.0f);//magenta
	//glColor4f(1.0f, 1.0f, 0.0f, 1.0f);//yellow


void DrawTriangleBlue(void) {
	glBegin(GL_POLYGON);// OpenGL’a state
	glColor4f(0.0f, 0.0f, 1.0f, 1.0f);//blue
	glVertex2f(0.0f, 100.0f);
	glColor4f(0.0f, 0.0f, 1.0f, 1.0f);//blue
	glVertex2f(0.0f, 0.0f);
	glColor4f(0.0f, 0.0f, 1.0f, 1.0f);//Blue
	glVertex2f(100.0f, 0.0f);
	glEnd();
}

void DrawTriangleGreen(void) {
	glBegin(GL_POLYGON);// OpenGL’a state
	glColor4f(0.0f, 1.0f, 0.0f, 1.0f);//Green
	glVertex2f(0.0f, 100.0f);
	glColor4f(0.0f, 1.0f, 0.0f, 1.0f);//Green
	glVertex2f(0.0f, 0.0f);
	glColor4f(0.0f, 1.0f, 0.0f, 1.0f);//Green
	glVertex2f(100.0f, 0.0f);
	glEnd();
}

void DrawTriangleOrange(void) {
	glBegin(GL_POLYGON);// OpenGL’a state
	glColor4f(1.0f, 0.5f, 0.0f, 1.0f);//orange
	glVertex2f(0.0f, 100.0f);
	glColor4f(1.0f, 0.5f, 0.0f, 1.0f);//orange
	glVertex2f(0.0f, 0.0f);
	glColor4f(1.0f, 0.5f, 0.0f, 1.0f);//orange
	glVertex2f(-100.0f, 0.0f);
	glEnd();
}

void DrawTriangleRed(void) {
	glBegin(GL_POLYGON);// OpenGL’a state
	glColor4f(1.0f, 0.0f, 0.0f, 1.0f);//Red;
	glVertex2f(0.0f, 100.0f);
	glColor4f(1.0f, 0.0f, 0.0f, 1.0f);//Red;
	glVertex2f(0.0f, 0.0f);
	glColor4f(1.0f, 0.0f, 0.0f, 1.0f);//Red;
	glVertex2f(100.0f, 0.0f);
	glEnd();
}

void DrawTriangleMagenta(void) {
	glBegin(GL_POLYGON);// OpenGL’a state
	glColor4f(1.0f, 0.0f, 1.0f, 1.0f);//magenta
	glVertex2f(0.0f, 100.0f);
	glColor4f(1.0f, 0.0f, 1.0f, 1.0f);//magenta
	glVertex2f(0.0f, 0.0f);
	glColor4f(1.0f, 0.0f, 1.0f, 1.0f);//magenta
	glVertex2f(-100.0f, 0.0f);
	glEnd();
}

void DrawTriangleYellow(void) {
	glBegin(GL_POLYGON);// OpenGL’a state
	glColor4f(1.0f, 1.0f, 0.0f, 1.0f);//yellow
	glVertex2f(0.0f, 100.0f);
	glColor4f(1.0f, 1.0f, 0.0f, 1.0f);//yellow
	glVertex2f(0.0f, 0.0f);
	glColor4f(1.0f, 1.0f, 0.0f, 1.0f);//yellow
	glVertex2f(100.0f, 0.0f);
	glEnd();
}



void MyDisplay(void) {
	// The new scene
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT);
	glShadeModel(GL_SMOOTH);
	glTranslated(0, 0, 0);
//--------------blue triangle----------//
	DrawTriangleBlue();
	glRotated(90, 0, 0, 100);
	DrawTriangleBlue();
	glRotated(180, 0, 0, 100);
	DrawTriangleBlue();
	glRotated(270, 0, 0, 100);
	DrawTriangleBlue();

	//--------------green triangle----------//
	glTranslated(0, 100, 0);
	DrawTriangleGreen();
	glRotated(90, 0, 0, 100);
	glTranslated(-100, 100, 0);
	DrawTriangleGreen();
	glRotated(180, 0, 0, 100);
	glTranslated(0, 200, 0);
	DrawTriangleGreen();
	glRotated(270, 0, 0, 100);
	glTranslated(100, 100, 0);
	DrawTriangleGreen();
	//--------------orange triangle----------//
	glTranslated(0,0, 0);
	DrawTriangleOrange();
	glRotated(90, 0, 0, 100);
	glTranslated(-100, 100, 0);
	DrawTriangleOrange();
	glRotated(180, 0, 0, 100);
	glTranslated(0, 200, 0);
	DrawTriangleOrange();
	glRotated(270, 0, 0, 100);
	glTranslated(100, 100, 0);
	DrawTriangleOrange();

	//--------------red triangle----------//
	glTranslated(0, 100, 0);
	DrawTriangleRed();
	glRotated(90, 0, 0, 100);
	glTranslated(-200, 200, 0);
	DrawTriangleRed();
	glRotated(180, 0, 0, 100);
	glTranslated(0, 400, 0);
	DrawTriangleRed();
	glRotated(270, 0, 0, 100);
	glTranslated( 200, 200, 0);
	DrawTriangleRed();

	//--------------magenta triangle----------//
	glTranslated( 0, 0, 0);
	DrawTriangleMagenta();
	glRotated(90, 0, 0, 100);
	glTranslated(-200, 200, 0);
	DrawTriangleMagenta();
	glRotated(180, 0, 0, 100);
	glTranslated(0, 400, 0);
	DrawTriangleMagenta();
	glRotated(270, 0, 0, 100);
	glTranslated(200, 200, 0);
	DrawTriangleMagenta();

	//--------------yellow triangle----------//
	glTranslated(100, -100, 0);
	DrawTriangleYellow();
	glRotated(90, 0, 0, 100);
	glTranslated(0, 200, 0);
	DrawTriangleYellow();
	glRotated(180, 0, 0, 100);
	glTranslated(200, 200, 0);
	DrawTriangleYellow();
	glRotated(270, 0, 0, 100);
	glTranslated(200, 0, 0);
	DrawTriangleYellow();


	// The end of scene
	glFlush();//start processing buffered OpenGL routines
}


void MyInit(void) {
	glClearColor(0.0, 0.0, 0.0, 0.0);//select clearing (background) color
									 /* initialize viewing values */
	glViewport(0, 0, 400, 400);//window origin and size
	glMatrixMode(GL_PROJECTION);//
	glLoadIdentity();//=1
	gluOrtho2D(-500.0, 500.0,-500.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();//=1
}

int main(int argc, char** argv) { //<- for normal API
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);//single buffer and RGBA
	glutInitWindowSize(800, 800);//initial window size
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Triangles");//create widnow, hello title bar
	MyInit();
	glutDisplayFunc(MyDisplay);

	glutMainLoop();//enter main loop and process events
	return 0;
}