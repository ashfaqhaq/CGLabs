#include<GL/glut.h>
#include<math.h>
GLfloat theta, thetar;
void display()
{
glClear(GL_COLOR_BUFFER_BIT);
glBegin(GL_POLYGON);
glDrawBuffer(GL_FRONT_AND_BACK);
glColor3f(0.0,0.0,1.0);
thetar = theta/(3.141/180.0);
glVertex2f(cos(thetar),sin(thetar));
glVertex2f(-sin(thetar),cos(thetar));
glVertex2f(-cos(thetar),-sin(thetar));
glVertex2f(sin(thetar),-cos(thetar));
glEnd();
//for Outer circle
glBegin(GL_POINTS);
GLfloat r=1.0;
for(int i=0;i<=360;i++)
glVertex2f(cos(i*(3.141/180))*r, sin(i*(3.141/180))*r);
glEnd();
glutSwapBuffers();
}
//perform background processing tasks or continuous animation when window system events are not being received. 
void idle(){
theta+=2;
if(theta>=360.0)
theta-=360.0;
glutPostRedisplay();
}
void myMouse(int btn, int state, int x, int y)
{
if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
glutIdleFunc(idle);
if(btn==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
glutIdleFunc(NULL);
}
void reshape(int w, int h)
{
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(-2,2,-2,2,2,-2);
glMatrixMode(GL_MODELVIEW);
glViewport(0,0,w,h);
}
int main(int argc, char **argv)
{
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
glutCreateWindow("rotate square");
glutDisplayFunc(display);
glutReshapeFunc(reshape);

glutMouseFunc(myMouse); glutMainLoop(); }