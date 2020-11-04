// Template1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include "include\GL\GL.H"
#include "include\GL\GLU.H"
#include "include\GL\glut.h"

//clors//
//glColor4f(1.0f, 0.0f, 0.0f, 1.0f);//Red;
//glColor4f(0.0f, 1.0f, 0.0f, 1.0f);//Green
//glColor4f(0.0f, 0.0f, 1.0f, 1.0f);//Blue;
//glColor4f(1.0f, 0.5f, 0.0f, 1.0f);//Orange
//glColor4f(1.0f, 0.0f, 1.0f, 1.0f);//Magenta
//glColor4f(1.0f, 1.0f, 0.0f, 1.0f);//Yellow


const double lengthOfTriangle = 100.0f;
double angle = 0;
double spread = 50;
double spreadStep = 2;
const double SPREAD_LIMIT = 60.00;
bool SHOULD_INCRESE = true;

void Timer(int) {

	angle += 180 / SPREAD_LIMIT * 2;
	if (spread >= SPREAD_LIMIT || spread <= 0)
	{
		spreadStep *= -1;
	}
	spread += spreadStep;

	glutPostRedisplay();
	//glutTimerFunc(1000, timer, 0);
}

void CenterOfMassRotation() {
	glTranslated(lengthOfTriangle / 3, lengthOfTriangle / 3, 0);
	glRotated(angle, 0, 0, 1); 
	glTranslated(-lengthOfTriangle / 3, -lengthOfTriangle / 3, 0);
}

void SpreadOut(float xRate, float yRate) {
	glTranslated(spread * xRate, spread * yRate, 0);
}

void QuarterMovment(void) {
	glRotated(angle, 0, 0, 1);
	//DrawQuarter();

}

void DrawTriangle(GLfloat red, GLfloat green, GLfloat blue, GLfloat alpha) {
	glBegin(GL_POLYGON);// OpenGLa state
	glColor4f(red, green, blue, alpha);//blue
	glVertex2f(0.0f, 100.0f);
	glColor4f(red, green, blue, alpha);//blue
	glVertex2f(0.0f, 0.0f);
	glColor4f(red, green, blue, alpha);//blue
	glVertex2f(100.0f, 0.0f);
	glEnd();

}

void DrawQuarter(bool shouldRotate, bool shouldSpread) {
	// blue
	glPushMatrix();
	glTranslated(0, 0, 0);
	if (shouldRotate) CenterOfMassRotation();
	if (shouldSpread) SpreadOut(1.0, 1.0);
	DrawTriangle(0.0f, 0.0f, 1.0f, 1.0f);
	glPopMatrix();

	// green
	glTranslated(0, 100, 0);
	glPushMatrix();
	if (shouldRotate) CenterOfMassRotation();
	if (shouldSpread) SpreadOut(1.0, 4.0);
	DrawTriangle(0.0f, 1.0f, 0.0f, 1.0f);
	glPopMatrix();

	// red
	glTranslated(0, 100, 0);
	glPushMatrix();
	if (shouldRotate) CenterOfMassRotation();
	if (shouldSpread) SpreadOut(1.0, 7.0);
	DrawTriangle(1.0f, 0.0f, 0.0f, 1.0f);
	glPopMatrix();

	// yellow
	glTranslated(100, -100, 0);
	glPushMatrix();
	if (shouldRotate) CenterOfMassRotation();
	if (shouldSpread) SpreadOut(4.0, 4.0);
	DrawTriangle(1.0f, 1.0f, 0.0f, 1.0f);
	glPopMatrix();

	// orange
	glTranslated(0, -100, 0);
	glPushMatrix();
	if (shouldRotate) CenterOfMassRotation();
	if (shouldSpread) SpreadOut(4.0, 1.0);
	DrawTriangle(1.0f, 0.5f, 0.0f, 1.0f);
	glPopMatrix();

	// magenta
	glTranslated(100, 0, 0);
	glPushMatrix();
	if (shouldRotate) CenterOfMassRotation();
	if (shouldSpread) SpreadOut(7.0, 1.0);
	DrawTriangle(1.0f, 0.0f, 1.0f, 1.0f);
	glPopMatrix();
}

void MyDisplay(void) {
	// The new scene
	glLoadIdentity();
	glClear(GL_COLOR_BUFFER_BIT);
	glShadeModel(GL_SMOOTH);
	glTranslated(0, 0, 0);

	for (int i = 0; i < 4; i++) {
		glRotated(i * 90, 0, 0, 100);
		QuarterMovment();
		DrawQuarter(true, true); //cener of mass //spread
		glLoadIdentity();
	}

	// The end of scene
	glFlush();//start processing buffered OpenGL routines
	glutTimerFunc(20, Timer, 0);
}

void MyInit(void) {
	glClearColor(0.0, 0.0, 0.0, 0.0);//select clearing (background) color
									 /* initialize viewing values */
	glViewport(0, 0, 400, 400);//window origin and size
	glMatrixMode(GL_PROJECTION);//
	glLoadIdentity();//=1
	gluOrtho2D(-500.0, 500.0, -500.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();//=1
}

int main(int argc, char** argv) { //<- for normal API
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);//single buffer and RGBA
	glutInitWindowSize(600, 600);//initial window size
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Triangles");//create widnow, hello title bar
	MyInit();
	glutDisplayFunc(MyDisplay);

	glutMainLoop();//enter main loop and process events
	return 0;
}