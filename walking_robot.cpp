#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define GLUT_DISABLE_ATEXIT_HACK
#include <gl/glut.h>

int curw;
int curh;
int swingLeft = 0;
int swingRight = 0;
bool isSwingForward = false;
bool isLighting = false;
int curTurn=180 ;//current facing angle
int maxAngel = 0;//maximum swing angle
int stepDis = 0;//thigh swing speed
float speed = 0;//forward speed
bool isStand = true;
float curDistanceX=0 , curDistanceZ=0;//current distance
float legDis = 0 ;


void display(void)
{
	glClear (GL_COLOR_BUFFER_BIT);
	glShadeModel(GL_SMOOTH);
	glBegin(GL_QUADS);
	glColor3ub(33,33,33);//BACKGROUND COLOR
	glVertex3f(-20.0f, -23.0f, -4.0f);
	glVertex3f(28.0f, -3.0f, -4.0f);
	glColor3ub(100,66,220);//BACKGROUND COLOR
	glVertex3f(28.0f, 8.0f, -4.0f);
	glVertex3f(-28.0f, 8.0f, -4.0f);
	glEnd();

	//Push the stack, draw the lower right half of the body
	glPushMatrix();

	//Translate and rotate the coordinate system
	glTranslatef (curDistanceX,0.0,curDistanceZ); //go ahead
	glRotatef ((GLfloat) curTurn, 0.0, 1.0, 0.0);//turn

	//Adjust the coordinate system to the right to locate the center of rotation
	glTranslatef (0.375,0.0, 0.0);
	//whether to lift the right thigh
	glRotatef ((GLfloat) swingRight, 1.0, 0.0, 0.0);
	//Lower the coordinate system and prepare to draw the right thigh
	glTranslatef (0.0, -0.5, 0.0);
	glColor3f(0.5,0.8,0.3);//RIGHT THIGH COLOR
	//draw right thigh
	glPushMatrix();
	glScalef (0.4, 1.0, 0.4);
	glutSolidCube(1.0);
	glPopMatrix();

	//Lower the coordinate system and locate the center of rotation
	glTranslatef (0.0, -0.5, 0.0);
	//Whether to lift the right calf
	glRotatef ((GLfloat) legDis, 1.0, 0.0, 0.0);
	//Lower the coordinate system and prepare to draw the right calf
	glTranslatef (0.0, -0.5, 0.0);
	glColor3f(0.1,0.5,0.5);//RIGHT CALF COLOR
	//draw right calf
	glPushMatrix();
	glScalef (0.3, 1.0, 0.3);
	glutSolidCube(1.0);
	glPopMatrix();

	//Lower the coordinate system, ready to draw the right foot
	glTranslatef (0.0, -0.5, -0.1);
	glColor3f(0.8,0.8,0.2);//RIGHT FOOT COLOR
	//draw the right foot
	glPushMatrix();
	glScalef (0.5, 0.1, 0.7);
	glutSolidCube(1.0);
	glPopMatrix();

	glPopMatrix ();
	//pop

	//Push into the stack, draw the lower left body
	glPushMatrix();
	//Translate and rotate the coordinate system
	glTranslatef (curDistanceX,0.0,curDistanceZ);//go ahead
	glRotatef ((GLfloat) curTurn, 0.0, 1.0, 0.0);//turn

	//Do the same for the left thigh
	glTranslatef (-0.375, 0.0, 0.0);
	glRotatef ((GLfloat) swingLeft, 1.0, 0.0, 0.0);
	glTranslatef (0.0, -0.5, 0.0);
	glColor3f(0.5,0.8,0.3);//LEFT THIGH COLOR
	glPushMatrix();
	glScalef (0.4, 1.0, 0.4);
	glutSolidCube(1.0);
	glPopMatrix();
	//Do the same for the left calf
	glTranslatef (0.0, -0.5, 0.0);
	glRotatef ((GLfloat) legDis, 1.0, 0.0, 0.0);
	glTranslatef (0.0, -0.5, 0.0);
	glColor3f(0.1,0.5,0.5);//LEFT CALF COLOR
	glPushMatrix();
	glScalef (0.3, 1.0, 0.3);
	glutSolidCube(1.0);
	glPopMatrix();
	//Do the same with the left foot
	glTranslatef (0.0, -0.5, -0.1);
	glColor3f(0.8,0.8,0.2);//LEFT FOOT COLOR
	glPushMatrix();
	glScalef (0.5, 0.1, 0.7);
	glutSolidCube(1.0);
	glPopMatrix();
	glPopMatrix();
	//pop

	//Push the stack, draw the chest and head
	glPushMatrix();
	glTranslatef (curDistanceX,0.0,curDistanceZ);
	glRotatef ((GLfloat) curTurn, 0.0, 1.0, 0.0);
	//Chest
	glTranslatef (0.0, 1.0,  0.0);
	glColor3f(1.0,0.7,0.1);//CHEST COLOR
	glPushMatrix();
	glScalef (1.4, 2.0, 0.5);
	glutSolidCube(1.0);
	glPopMatrix();
	//head
	glTranslatef (0.0, 1.25, 0.0);
	glColor3f(0.9,0.9,0.9);//HEAD COLOR
	glPushMatrix();
	glScalef (0.5, 0.5, 0.5);
	glutSolidCube(1.0);
	glPopMatrix();

	glPopMatrix();
	//pop
	//Push the stack, draw the right arm part
	glPushMatrix();
	glTranslatef (curDistanceX,0.0,curDistanceZ);
	glRotatef ((GLfloat) curTurn, 0.0, 1.0, 0.0);
	//right arm
	glTranslatef (0.85, 1.75, 0.0);
	glRotatef ((GLfloat) swingLeft, 1.0, 0.0, 0.0);
	glTranslatef (0.0, -0.5, 0.0);
	glColor3f(0.8,0.4,0.5);//RIGHT HAND COLOR
	glPushMatrix();
	glScalef (0.3, 1.6, 0.4);
	glutSolidCube(1.0);
	glPopMatrix();
	glPopMatrix();
	//pop

	//Push the stack, draw the left arm part
	glPushMatrix();
	glTranslatef (curDistanceX,0.0,curDistanceZ);
	glRotatef ((GLfloat) curTurn, 0.0, 1.0, 0.0);
	//left arm
	glTranslatef (-0.85, 1.75, 0.0);
	glRotatef ((GLfloat) swingRight, 1.0, 0.0, 0.0);
	glTranslatef (0.0, -0.5, 0.0);
	glColor3f(0.8,0.4,0.5);//LEFT HAND COLOR
	glPushMatrix();
	glScalef (0.3, 1.6, 0.4);
	glutSolidCube(1.0);
	glPopMatrix();
	glPopMatrix();
	//pop

	glutSwapBuffers();
}


 /**
	when the window size changes
 **/
void reshape (int w, int h)
{
   curw=w;
   curh=h;
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   gluPerspective(65.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
   glTranslatef (0.0, 0.0, -8.0);
}


void arrowKeyPress(int key, int x, int y){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	switch(key){
	case GLUT_KEY_RIGHT:
		curTurn = (curTurn - 5) % 360;
         glutPostRedisplay();
	break;
	case GLUT_KEY_LEFT:
		curTurn = (curTurn + 5) % 360;
         glutPostRedisplay();
	break;

    }

    glutPostRedisplay();		// redraw the image now
}
//Reset function
void reset(){
swingLeft = 0;
swingRight = 0;

curTurn=180 ;//current facing angle
maxAngel = 0;//maximum swing angle
stepDis = 0;//thigh swing speed
speed = 0;//forward speed
isStand = true;
curDistanceX=0 , curDistanceZ=0;//current distance
 legDis = 0 ;
}


//time function, timed refresh
void timer(int value)
{
	int tempTurn=curTurn;
    curDistanceX = curDistanceX - speed*sin((GLfloat)tempTurn/360*3.14*2);
    curDistanceZ=curDistanceZ- speed*cos((GLfloat)tempTurn/360*3.14*2);
    if(!isSwingForward){
        swingLeft = (swingLeft + stepDis);
        swingRight = (swingRight - stepDis);
        if(swingLeft>0){legDis=legDis - stepDis*1.2;}
        else{legDis=legDis + stepDis*1.2;}
    }
    else
    {
        swingLeft = (swingLeft - stepDis);
        swingRight = (swingRight + stepDis);
        if(swingLeft<0){legDis=legDis - stepDis*1.2;}
        else{legDis=legDis + stepDis*1.2;}
    }
    if(swingLeft>maxAngel){
        isSwingForward = true;
    }
    if(swingLeft<maxAngel*-1){
        isSwingForward = false;
    }
	display();
	glutPostRedisplay();
	if(!isStand) glutTimerFunc(value ,timer, value);
}
//Stand function
void stand(){
	swingLeft = 0;
	swingRight = 0;
	isSwingForward = false;
	legDis = 0 ;
}



/*main menu*/
void MenuFunc(int data)
{
	switch(data){
	case 1:
		isStand = true;
		stand();
		break;
	case 2:
		stand();
		maxAngel = 20;
		stepDis = 1;
		speed = 0.02;
		if(isStand) glutTimerFunc(20 ,timer, 20);
		isStand = false;
		break;
	case 3:
	    //Run function
		stand();
		maxAngel = 55;
		stepDis = 5;
		speed = 0.04;
		if(isStand) glutTimerFunc(10 ,timer, 10);
		isStand = false;
		break;
    case 4: reset();
    break;
    case 5:
        exit(0);

	}
}

//Initialize parameter settings such as background
void init(void)
{


	/*Create a main menu and add menu items and submenus*/
	glutCreateMenu(MenuFunc);
	glutAddMenuEntry("Stand",1);
	glutAddMenuEntry("Walk",2);
	glutAddMenuEntry("Run",3);
		glutAddMenuEntry("Reset",4);
				glutAddMenuEntry("Exit",5);


	glutAttachMenu(GLUT_RIGHT_BUTTON);

	glEnable(GL_CULL_FACE); // Turn on cropping
	glCullFace(GL_BACK); // cut backx

}


//main function
int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
   glutInitWindowSize (800, 700);
   glutInitWindowPosition (100, 100);
   glutCreateWindow("Walking Robot");
   init();
   glutDisplayFunc(display);
   glutReshapeFunc(reshape);
   glutSpecialFunc(arrowKeyPress);

   glutMainLoop();
   return 0;
}
