#include <GL/glut.h>
void display(void)
{
    glEnable(GL_DEPTH_TEST);
glShadeModel(GL_FLAT);
glClearColor(0.0, 0.0, 0.0, 0.0);
   glClear(GL_COLOR_BUFFER_BIT);
   glColor3f(1.0, 1.0, 1.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity ();
 gluLookAt(2.0,0.0, 5.0, 0.0, 0.0, 0.0, 0.0, 3.0, 0.0);
   glTranslatef(2.0,0.0,0.0);
   glColor3f(0.0,0.0,1.0);
      glutSolidTeapot(1);
       glTranslatef(-3.5,0.0,0.0);
      glColor3f(0.0,1.0,0.0);
      glutSolidTeapot(1);
      
   glFlush();
}

void init()
{
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();
   glOrtho(-3.5,3.5,-3.5,3.5,10,-10);
        glMatrixMode(GL_MODELVIEW);
}
int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
   glutInitWindowSize (500, 500);
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init();
   glutDisplayFunc(display);
   glutMainLoop();
   return 0;
}