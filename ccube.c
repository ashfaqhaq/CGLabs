#include<GL/glut.h>
GLfloat vertices[8][3]={{-1.0,-1.0,-1.0},{1.0,-1.0,-1.0},{1.0,1.0,-1.0},
{-1.0,1.0,-1.0},{-1.0,-1.0,1.0},{1.0,-1.0,1.0},{1.0,1.0,1.0},{-1.0,1.0,1.0}};
void polygon(int a,int b,int c,int d)
{
    glBegin(GL_QUADS);
    glVertex3fv(vertices[a]);
        glColor3fv(vertices[a]);
    glVertex3fv(vertices[b]);
        glColor3fv(vertices[b]);
    glVertex3fv(vertices[c]);
        glColor3fv(vertices[c]);
    glVertex3fv(vertices[d]);
        glColor3fv(vertices[d]);
    glEnd();
    
}
void colorcube()
{
    polygon(0,3,2,1);
    polygon(2,3,7,6);
    polygon(0,4,7,3);
    polygon(1,2,6,5);
    polygon(4,5,6,7);
    polygon(0,1,5,4);
}
void display()
{
    glClearColor(1.0,1.0,0.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glTranslatef(2.0f,2.0f,-10.0f);
    gluLookAt(0.0,-5.0, 0.0, 3.0, 0.0, 0.0, 0.0, 1.0, 0.0);
    colorcube();
    glFlush();
    glutSwapBuffers();
}
void timer(int n)
{
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glRotatef(45.0,0.0,1.0,0.0);
glutPostRedisplay();
glutTimerFunc(1000,timer,n);
}
void reshape(GLsizei width,GLsizei height)
{
    glViewport(0,0,width,height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f,(double)width/(double)height,0.1f,100.0f);
    //glMatrixMode(GL_MODELVIEW);
}
int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
    	glutInitWindowSize(800,600);
	glutInitWindowPosition(50,50);
	glutCreateWindow("Color Cube");
	glutDisplayFunc(display);
    glutTimerFunc(1000,timer,10);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}
