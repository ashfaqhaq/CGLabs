#include <GL/glut.h>
void init(void)
{
GLfloat specular0[] = {1.0, 1.0, 1.0, 1.0};
GLfloat ambient0[] = {1.0, 1.0, 1.0, 1.0};
GLfloat diffuse0[] = {1.0, 0.0, 0.0, 1.0};
glLightfv(GL_LIGHT0, GL_SPECULAR, specular0); //specular
glLightfv(GL_LIGHT0, GL_AMBIENT, ambient0); //ambient
glLightfv(GL_LIGHT0, GL_DIFFUSE, diffuse0); //diffuse
GLfloat mat_ambient[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat mat_diffuse[] = { 0.4, 0.4, 0.4, 1.0 };
GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat mat_shininess[] = { 15.0 };
glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient);
glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse);
glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
glEnable(GL_LIGHTING);
glEnable(GL_LIGHT0);
glEnable(GL_DEPTH_TEST); //do depth comparisons and update the depth buffer
}
void display(void)
{
glClearColor(0.0, 0.0, 0.0, 0.0);
glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
GLfloat finite_light[] = { 1.0, 1.0, 1.0, 1.0 }; //near light
glTranslatef(1.7, 0.0, 0.0);
glLightfv(GL_LIGHT0, GL_POSITION, finite_light);
glutSolidSphere(1.0, 30, 16); //(radius, no. of longitudes around z-axes, no. of latitudes about z-axes)
//glutSolidTeapot(1);
GLfloat distant_light[] = { 1.0, 1.0, 1.0, 0.0 }; //distant light
glTranslatef (-3.5, 0.0, 0.0);
glLightfv(GL_LIGHT0, GL_POSITION, distant_light);
glutSolidSphere(1.0, 30, 16);
//glutSolidTeapot(1);
glRasterPos3f(0.0,-2.0,0.0);
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 68); //D
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 76); //L
glRasterPos3f(3.5,-2.0,0.0);
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 78); //N
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, 76); //L
glFlush();
}
void reshape(int w, int h)
{
glViewport(0,0,w,h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(-6.0,6.0,-6.0,6.0,1.5,0.0);

}
int main(int argc, char** argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(500,500);
glutInitWindowPosition(100,100);
glutCreateWindow("light");
init();
glutDisplayFunc(display);
glutReshapeFunc(reshape);
glutMainLoop();
return 0;
}