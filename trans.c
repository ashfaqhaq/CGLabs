#include<GL/glut.h>
void display()
{
glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_POLYGON);
glVertex2f(1.0,1.0);
glVertex2f(3.0,1.0);
glVertex2f(3.0,4.0);
glVertex2f(1.0,4.0);
glEnd();
glFlush();
}
void init()
{
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,12,0.0,12 );
}
void timer(int n)
{
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glTranslatef(0.0,5.0,0.0);
glutPostRedisplay();
glutTimerFunc(1000,timer,n); // to have some delay
}
int main(int argc,char** argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE);
glutInitWindowPosition(200,200);
glutInitWindowSize(300,300);
glutCreateWindow("Translation");
init();
glutDisplayFunc(display);
glutTimerFunc(1000,timer,10); // callback to timer function
glutMainLoop();
}