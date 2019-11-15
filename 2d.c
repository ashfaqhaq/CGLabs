#include<GL/glut.h>

void display()
{
//glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0.9,0.9,0.9);
  glBegin(GL_QUADS);
        glVertex2f(20.0,20.0);
        glVertex2f(30.0,20.0);
        glVertex2f(30.0,30.0);
        glVertex2f(20.0,30.0);
  glEnd();
  

  glBegin(GL_LINES);
     glVertex2f(-20.0,2.0);
     glVertex2f(-5,20);
  glEnd();
  

glBegin(GL_TRIANGLES);
        glVertex2f(-30.0,-20.0);
        glVertex2f(-10.0,-20.0);
        glVertex2f(-20.0,-10.0);
glEnd();
  
glBegin(GL_POLYGON);
      glVertex2f(40.0,-5.0);
        glVertex2f(30.0,-20.0);
        glVertex2f(50.0,-20.0);
        glVertex2f(45.0,-10.0);
     
        glVertex2f(30.0,-10.0);
glEnd();

glFlush();
}
void init()
{
gluOrtho2D(-50,50,-50,50);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glMatrixMode(GL_MODELVIEW);

}


int main(int argc,char **argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE|GLUT_DEPTH);
glutInitWindowPosition(50,50);
glutInitWindowSize(300,300);
glutCreateWindow("quads");
init();
glutDisplayFunc(display);
glutMainLoop();
return 0;
}

