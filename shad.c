#include <GL/glut.h>
/* GL_SMOOTH is actually the default shading model. In smooth shading every vertex will have its
color. /*In flat shading, for GL_POLYGON first vertex color, for GL_TRIANGLES third vertex color, for
GL_QUADS fourth vertex color. */
void myinit (void)
{
//glShadeModel(GL_FLAT);
	glShadeModel(GL_SMOOTH); 
}
void primitive(void)
{
	glBegin(GL_QUADS);
	//glColor3f(1.0, 0.0, 0.0);
	glVertex2f(5.0, 5.0);
	glColor3f(0.0, 1.0, 0.0);
	glVertex2f(25.0, 5.0);
	glColor3f(0.0, 0.0, 1.0);
	glVertex2f(25.0, 25.0);
	glColor3f(1.0,1.0,0.0);
	glVertex2f(5.0,25.0);
	glEnd();
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	primitive();
	glFlush();
}
void reshape(int w, int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-80,80,-80,80);
	//glOrtho(-40.0,40.0,-40.0,40.0,1.5,0.0);
}
int main(int argc, char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(		GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("shade");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}