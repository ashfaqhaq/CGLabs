#include<GL/glut.h>
void polygon()
{
glBegin(GL_POLYGON);
glColor3f(0.0,0.0,0.0);
glVertex2f(1.0,1.0);
glVertex2f(4.0,1.0);
glVertex2f(4.0,4.0);
glVertex2f(1.0,4.0);
glEnd();
}
void display()
{
glClearColor(1.0f,1.0f,1.0f,1.0f);
glClear(GL_COLOR_BUFFER_BIT);
polygon();
glFlush();
}
void timer(int n)
{
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
//glTranslatef(2.0,2.0,0.0);
glRotatef(45.0,0.0,0.0,1.0);
//glTranslatef(-2.0,-2.0,0.0);
polygon();
glutPostRedisplay();
glutTimerFunc(1000,timer,n);
}
void init()
{
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-6,6,-6,6);
}
int main(int argc, char **argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE);
glutInitWindowPosition(100,100);
glutInitWindowSize(300,300);
glutCreateWindow("Rotation");
init();
glutDisplayFunc(display);
glutTimerFunc(1000,timer,10);
glutMainLoop();
}