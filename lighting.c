#include <GL/gl.h>
#include <GL/glu.h>
#include <stdlib.h>
#include <GL/glut.h>
void myinit(void)
{
GLfloat mat_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
/* mat_specular and mat_shininess are NOT default values */
GLfloat mat_diffuse[] = { 0.4, 0.4, 0.4, 1.0 };
GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat mat_shininess[] = { 15.0 };
GLfloat light_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat lmodel_ambient[] = { 0.2, 0.2, 0.2, 1.0 };
glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
glLightModelfv(GL_LIGHT_MODEL_AMBIENT, lmodel_ambient);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glDepthFunc(GL_LESS);
glEnable(GL_DEPTH_TEST);
}
void drawPlane(void)
{
glBegin (GL_QUADS);
glNormal3f (0.0, 0.0, 1.0);
glVertex3f (-1.0, -1.0, 0.0);
glVertex3f (0.0, -1.0, 0.0);
glVertex3f (0.0, 0.0, 0.0);
glVertex3f (-1.0, 0.0, 0.0);
glNormal3f (0.0, 0.0, 1.0);
glVertex3f (0.0, -1.0, 0.0);
glVertex3f (1.0, -1.0, 0.0);
glVertex3f (1.0, 0.0, 0.0);
glVertex3f (0.0, 0.0, 0.0);
glNormal3f (0.0, 0.0, 1.0);
glVertex3f (0.0, 0.0, 0.0);

glVertex3f (1.0, 0.0, 0.0);
glVertex3f (1.0, 1.0, 0.0);
glVertex3f (0.0, 1.0, 0.0);
glNormal3f (0.0, 0.0, 1.0);
glVertex3f (0.0, 0.0, 0.0);
glVertex3f (0.0, 1.0, 0.0);
glVertex3f (-1.0, 1.0, 0.0);
glVertex3f (-1.0, 0.0, 0.0);
glEnd();
}
void display (void)
{
GLfloat infinite_light[] = { 1.0, 1.0, 1.0, 0.0 };
GLfloat local_light[] = { 1.0, 1.0, 1.0, 1.0 };
glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glPushMatrix ();
glTranslatef (-1.5, 0.0, 0.0);
glLightfv (GL_LIGHT0, GL_POSITION, infinite_light);
drawPlane ();
glPopMatrix ();
glPushMatrix ();
glTranslatef (1.5, 0.0, 0.0);
glLightfv (GL_LIGHT0, GL_POSITION, local_light);
drawPlane ();
glPopMatrix ();
glFlush ();
}
void myReshape(int w, int h)
{
glViewport (0, 0, w, h);
glMatrixMode (GL_PROJECTION);
glLoadIdentity ();
if (w <= h)
glOrtho (-1.5, 1.5, -1.5*(GLdouble)h/(GLdouble)w,
1.5*(GLdouble)h/(GLdouble)w, -10.0, 10.0);
else
glOrtho (-1.5*(GLdouble)w/(GLdouble)h,
1.5*(GLdouble)w/(GLdouble)h, -1.5, 1.5, -10.0, 10.0);
glMatrixMode (GL_MODELVIEW);
}
int main(int argc, char** argv)
{
glutInit(&argc,argv);
glutInitWindowSize(300,300);
glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);

//glutInitPosition (0, 0, 500, 500);
glutCreateWindow("lightning");
myinit();
glutReshapeFunc (myReshape);
glutDisplayFunc(display);
glutMainLoop();
}