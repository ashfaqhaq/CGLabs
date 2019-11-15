#include<GL/glut.h>
GLuint BOX=1;
void init()
{
glNewList(BOX,GL_COMPILE);
	glBegin(GL_POLYGON);
		glColor3f(0.0,0.0,1.0);                
		glVertex2f(-1.0,-1.0);
		glVertex2f(1.0,-1.0);
		glVertex2f(0.5,0.5);
	glEnd();

	glTranslatef(2.0,0.0,0.0);

	glEndList();

}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0,1.0,0.0);
	//glClearColor(0.0,0.0,0.0,1.0);
for(int i=1;i<10;i++)
	glCallList(BOX);

glFlush();
}
void reshape(int w,int h)
{
glViewport(0,0,w,h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(-10,30,-10,30);
glMatrixMode(GL_MODELVIEW);
}
int main(int argc,char **argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_RGB );
glutInitWindowPosition(50,50);
glutInitWindowSize(300,300);
glutCreateWindow("DISPLAY LIST");
init();
glutDisplayFunc(display);
glutReshapeFunc(reshape);
glutMainLoop();
return 1;
}
