#include <iostream>
#include <math.h>
#include <GL/glut.h>
using namespace std;
GLfloat X=0,Y=200,Z=-375,rot=0,mov_x=0,mov_z,rot_obj=0,no=0,key_main_get=0;
GLfloat bridge=0;
GLint key_d1=0,key_dl=0,key_dr=0,key_d2l=200,key_d2r=200;


void Cube(float b,float l,float h)
{
   

   glBegin(GL_POLYGON);                 //front
   glVertex3f(l/2,h,-b/2);
   glVertex3f(l/2,0,-b/2);
   glVertex3f(-l/2,0,-b/2);
   glVertex3f(-l/2,h,-b/2);
   glEnd();

   
   glBegin(GL_POLYGON);                //back
   glVertex3f(-l/2,h,b/2);
   glVertex3f(l/2,h,b/2);
   glVertex3f(l/2,0,b/2);
   glVertex3f(-l/2,0,b/2);
   glEnd();
   
   //glColor3f(0.1,0.2,0.1);
    glBegin(GL_POLYGON);                  //left
   glVertex3f(-l/2,h,-b/2);
   glVertex3f(-l/2,h,b/2);
   glVertex3f(-l/2,0,b/2);
   glVertex3f(-l/2,0,-b/2);
   glEnd();

   
   glBegin(GL_POLYGON);             //right
   glVertex3f(l/2,h,b/2);
   glVertex3f(l/2,0,b/2);
   glVertex3f(l/2,0,-b/2);
   glVertex3f(l/2,h,-b/2);
   glEnd();
   
   glColor3f(0.1,0.2,0.3);

   glBegin(GL_POLYGON);         //top
   glVertex3f(l/2,h,b/2);
   glVertex3f(l/2,h,-b/2);
   glVertex3f(-l/2,h,-b/2);
   glVertex3f(-l/2,h,b/2);
   glEnd();

	glBegin(GL_POLYGON);            //bottom
   glVertex3f(l/2,0,b/2);
   glVertex3f(l/2,0,-b/2);
   glVertex3f(-l/2,0,-b/2);
   glVertex3f(-l/2,0,+b/2);
   glEnd();

}



void SAMPLE_WALL()
{
	glColor3f(1,0.2,0.2);
	Cube(100,20,40);
	
	/*glLineWidth(10);
	
	for(int i=20;i<=100;i=i+20)
	{
		glColor3f(0,0,0);
		glBegin(GL_LINES);
		glVertex3f(-10.05,i,50);
		glVertex3f(-10.5,i,-50);
		glVertex3f(10.05,i,50);
		glVertex3f(10.5,i,-50);
		glEnd();
		if(i%40==0)
		{
			for(int j=-37.5;j<37.5;j=j+25)
			{
				glBegin(GL_LINES);
				glVertex3f(-10.05,i-20,j);
				glVertex3f(-10.5,i,j);
		
				glVertex3f(10.05,i-20,j);
				glVertex3f(10.5,i,j);
				glEnd();
			}
		}
		
		else
		{
			for(int j=-50;j<=50;j=j+25)
			{
				glBegin(GL_LINES);
				glVertex3f(-10.05,i-20,j);
				glVertex3f(-10.5,i,j);
		
				glVertex3f(10.05,i-20,j);
				glVertex3f(10.5,i,j);
				glEnd();
			}
		}

	}*/
}

void WALLS()
{
//------------------presentation
	glPushMatrix();
	glTranslatef(490,0,-550);
	for(int i=-450;i<=450;i=i+100)
	{
		glTranslatef(0,0,100);
		SAMPLE_WALL();
	}
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(-490,0,-550);
	for(int i=-450;i<=450;i=i+100)
	{
		glTranslatef(0,0,100);
		SAMPLE_WALL();
	}
	glPopMatrix();
	
	glPushMatrix();
	glRotatef(90,0,1,0);
	glTranslatef(-490,0,-550);
	for(int i=-450;i<=450;i=i+100)
	{
		glTranslatef(0,0,100);
		SAMPLE_WALL();
	}
	glPopMatrix();
	
	glPushMatrix();
	glRotatef(90,0,1,0);
	glTranslatef(490,0,-550);
	for(int i=-450;i<=450;i=i+100)
	{
			if(i==50||i==-50)
			{
				glTranslatef(0,0,100);
				continue;
			}
		glTranslatef(0,0,100);
		SAMPLE_WALL();
	}
	glPopMatrix();
	
	
	
}

void PresenTation_Base()
{

//-----------------------_SEA---------------
	glBegin(GL_POLYGON);
	glColor3f(0,0,1);
	glVertex3f(-5000,-5,5000);
	glVertex3f(-5000,-5,-2000);
	glVertex3f(5000,-5,-2000);
	glVertex3f(5000,-5,5000);
	glEnd();
	
	//--------------------Presentation_Base---------------

	glBegin(GL_POLYGON);
	glColor3f(0,1,0);
	glVertex3f(-500,0,500);
	glVertex3f(-500,0,-500);
	glVertex3f(500,0,-500);
	glVertex3f(500,0,500);
	glEnd();
	
	//-------------WALLS----------
	
	glPushMatrix();
	glTranslatef(0,0,0);
	WALLS();
	glPopMatrix();
	
	
	//------------Bridge_____key
	glPushMatrix();
	glTranslatef(0,0,-250);
	glBegin(GL_POLYGON);
	if(bridge==0)
		glColor3f(1,0,0);
	else glColor3f(0,1,0);
	glVertex3f(-50,0.1,50);
	glVertex3f(-50,0.1,-50);
	glVertex3f(50,0.1,-50);
	glVertex3f(50,0.1,50);
	glEnd();
	glPopMatrix();
	
	
	//------------DOOR   1  GATE KEY
	
	glPushMatrix();
	glTranslatef(-0300,0,-1300);
	glBegin(GL_POLYGON);
	if(bridge==0)
		glColor3f(1,0,0);
	else 
		glColor3f(0,1,0);
	glVertex3f(-50,0.05,50);
	glVertex3f(-50,0.05,-50);
	glVertex3f(50,0.05,-50);
	glVertex3f(50,0.05,50);
	glEnd();
	glPopMatrix();
	
	//------------DOOR1 KEY
	
	glPushMatrix();
	glTranslatef(-300,0,-1300);
	glBegin(GL_POLYGON);
	if(key_d1==0)
		glColor3f(1,0,0);
	else glColor3f(0,1,0);
	glVertex3f(-50,0.1,50);
	glVertex3f(-50,0.1,-50);
	glVertex3f(50,0.1,-50);
	glVertex3f(50,0.1,50);
	glEnd();
	glPopMatrix();
	
	//-----------------DOOR3-----LEFT--
	
	glPushMatrix();
	glTranslatef(-1300,0,-2800);
	glBegin(GL_POLYGON);
	if(key_dr==0)
		glColor3f(1,0,0);
	else glColor3f(0,1,0);
	glVertex3f(-50,0.1,50);
	glVertex3f(-50,0.1,-50);
	glVertex3f(50,0.1,-50);
	glVertex3f(50,0.1,50);
	glEnd();
	glPopMatrix();
	
	//------------------------door----------right
	
	glPushMatrix();
	glTranslatef(1300,0,-2800);
	glBegin(GL_POLYGON);
	if(key_dl==0)
		glColor3f(1,0,0);
	else glColor3f(0,1,0);
	glVertex3f(-50,0.1,50);
	glVertex3f(-50,0.1,-50);
	glVertex3f(50,0.1,-50);
	glVertex3f(50,0.1,50);
	glEnd();
	glPopMatrix();
	
	
	//-------------KEY MAIN GET
	
	glPushMatrix();
	glTranslatef(0,0,-2300);
	glBegin(GL_POLYGON);
	if(key_main_get==0)
		glColor3f(1,0,0);
	else 
		glColor3f(0,1,0);
	glVertex3f(-100,0.1,100);
	glVertex3f(-100,0.1,-100);
	glVertex3f(100,0.1,-100);
	glVertex3f(100,0.1,100);
	glEnd();
	glPopMatrix();
	
	
}

void DRAW_WALLS()
{

//---------------1
	glPushMatrix();
	glRotatef(90,0,1,0);
	glTranslatef(0,0,-550);
	for(int i=-450;i<=450;i=i+100)
	{
			if(i==50||i==-50)
			{
				glTranslatef(0,0,100);
				continue;
			}
		glTranslatef(0,0,100);
		SAMPLE_WALL();
	}
	glPopMatrix();
	
//-----------------2

	glPushMatrix();
	glTranslatef(500,0,-50);
	for(int i=-450;i<=450;i=i+100)
	{
		glTranslatef(0,0,100);
		SAMPLE_WALL();
	}
	glPopMatrix();
	
//----------------3

		glPushMatrix();
	glTranslatef(-500,0,-50);
	for(int i=-450;i<=450;i=i+100)
	{
		glTranslatef(0,0,100);
		SAMPLE_WALL();
	}
	glPopMatrix();
	
//----------------4

	glPushMatrix();
	glRotatef(90,0,1,0);
	glTranslatef(-1000,0,-550);
	for(int i=-450;i<=450;i=i+100)
	{
			if(i==50||i==-50)
			{
				glTranslatef(0,0,100);
				continue;
			}
		glTranslatef(0,0,100);
		SAMPLE_WALL();
			}
		glPopMatrix();
		
		
//----------------5------------

	glPushMatrix();
	glTranslatef(500,0,1200);
	for(int i=-450;i<=450;i=i+100)
	{
		glTranslatef(0,0,100);
		SAMPLE_WALL();
	}
	glPopMatrix();
	
	
	//----------------6
	
	glPushMatrix();
	glRotatef(90,0,1,0);
	glTranslatef(-1000,0,450);
	for(int i=-450;i<=450;i=i+100)
	{
		glTranslatef(0,0,100);
		SAMPLE_WALL();
	}
	glPopMatrix();
	
	//-------------7
	
	glPushMatrix();
	glTranslatef(1500,0,950);
	for(int i=-450;i<=1900;i=i+100)
	{
		glTranslatef(0,0,100);
		SAMPLE_WALL();
	}
	glPopMatrix();
	
	//------------------8
	
	glPushMatrix();
	glRotatef(90,0,1,0);
	glTranslatef(-2500,0,150);
	for(int i=-450;i<=750;i=i+100)
	{
		glTranslatef(0,0,100);
		SAMPLE_WALL();
	}
	glPopMatrix();
	
	
	//--------------------9
	
	
	glPushMatrix();
	glRotatef(90,0,1,0);
	glTranslatef(-2500,0,-1550);
	for(int i=-450;i<=750;i=i+100)
	{
		glTranslatef(0,0,100);
		SAMPLE_WALL();
	}
	glPopMatrix();
	
	//--------------10
	
	glPushMatrix();
	glTranslatef(-500,0,1200);
	for(int i=-450;i<=450;i=i+100)
	{
		glTranslatef(0,0,100);
		SAMPLE_WALL();
	}
	glPopMatrix();
	
	//-----------------11
	
	glPushMatrix();
	glTranslatef(-1500,0,950);
	for(int i=-450;i<=1900;i=i+100)
	{
		glTranslatef(0,0,100);
		SAMPLE_WALL();
	}
	glPopMatrix();
	
	//--------------12
	
	glPushMatrix();
	glRotatef(90,0,1,0);
	glTranslatef(-1000,0,-1550);
	for(int i=-450;i<=450;i=i+100)
	{
		glTranslatef(0,0,100);
		SAMPLE_WALL();
	}
	glPopMatrix();
	
	//------------------16
	
		glPushMatrix();
	glRotatef(90,0,1,0);
	glTranslatef(-3400,0,-1550);
	for(int i=-450;i<=2500;i=i+100)
	{
		glTranslatef(0,0,100);
		SAMPLE_WALL();
	}
	glPopMatrix();
	
	
	//------------------DOOR1
	
	glPushMatrix();
	glTranslatef(-50-key_d1,0,1000);
	glColor3f(0,0,0);
	Cube(10,100,160);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(50+key_d1,0,1000);
	glColor3f(0,0,0);
	Cube(10,100,160);
	glPopMatrix();
	
	//----------DOOR2---LEFT------
	
	glPushMatrix();
	glRotatef(90,0,1,0);
	glTranslatef(-1075-key_d2l,0,500);
	glColor3f(0.5,0.105,0.30);
	Cube(10,100,160);
	glPopMatrix();
	
	glPushMatrix();
	glRotatef(90,0,1,0);
	glTranslatef(-1175-key_d2l,0,500);
	glColor3f(0.5,0.105,0.30);
	Cube(10,100,160);
	glPopMatrix();
	
	//--------------DOOR2    RIGHT------


	glPushMatrix();
	glRotatef(90,0,1,0);
	glTranslatef(-1075-key_d2r,0,-500);
	glColor3f(0.5,0.105,0.30);
	Cube(10,100,160);
	glPopMatrix();
	
	glPushMatrix();
	glRotatef(90,0,1,0);
	glTranslatef(-1175-key_d2r,0,-500);
	glColor3f(0.5,0.105,0.30);
	Cube(10,100,160);
	glPopMatrix();
	
	
	//---------------DOOR3   LEFT
	
	glPushMatrix();
	glRotatef(90,0,1,0);
	glTranslatef(-2300+key_dl,0,-500);
	
	glColor3f(0.070,0.13,0.5);
	Cube(10,100,160);
	glPopMatrix();
	
	glPushMatrix();
	glRotatef(90,0,1,0);
	glTranslatef(-2400+key_dl,0,-500);
	
	glColor3f(0.070,0.13,0.5);
	Cube(10,100,160);
	glPopMatrix();
	
	
	//--------------DOOR3    RIGHT------


	glPushMatrix();
	glRotatef(90,0,1,0);
	glTranslatef(-2300+key_dr,0,500);
	glColor3f(0.5,0.105,0.30);
	Cube(10,100,160);
	glPopMatrix();
	
	glPushMatrix();
	glRotatef(90,0,1,0);
	glTranslatef(-2400+key_dr,0,500);
	glColor3f(0.5,0.105,0.30);
	Cube(10,100,160);
	glPopMatrix();
	
	//---------------Dooorr4
	
	glPushMatrix();
	glTranslatef(-210,0,2490);
	glRotatef(key_main_get,0,1,0);
	glTranslatef(210,0,-2490);
	glPushMatrix();
	glTranslatef(-160,0,2490);
	glColor3f(0.240,0.230,0.140);
	Cube(10,100,160);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(-55,0,2490);
	glColor3f(0.240,0.230,0.140);
	Cube(10,100,160);
	glPopMatrix();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(210,0,2490);
	glRotatef(key_main_get,0,-1,0);
	glTranslatef(-210,0,-2490);
	glPushMatrix();
	glTranslatef(55,0,2490);
	glColor3f(0.240,0.230,0.140);
	Cube(10,100,160);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(160,0,2490);
	glColor3f(0.240,0.230,0.140);
	Cube(10,100,160);
	glPopMatrix();
	glPopMatrix();
	
}

void TARGETBASE()
{
	glBegin(GL_POLYGON);
	glColor3f(0,1,0);
	glVertex3f(5000,0,0);
	glVertex3f(5000,0,5000);
	glVertex3f(-5000,0,5000);
	glVertex3f(-5000,0,0);
	glEnd();
	
	//---------------WALL-------------------

	glPushMatrix();
	glColor3f(0.6,0.9,0.7);
	glRotatef(90,-1,0,0);
	Cube(2,100,100);
	glPopMatrix();
	
	
	DRAW_WALLS();
	
}

void Display()
{
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(X+mov_x,Y,Z+mov_z,mov_x,0,Z+500+mov_z,0,1,0);

	glRotatef(rot,0,1,0);
	
	glPushMatrix();
	//cout<<fall<<endl;
	glTranslatef(-mov_x,0,-mov_z);
	glRotatef(rot_obj,0,1,0);
	glColor3f(0,0,0);
	Cube(28,65.25,28);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(0,0,0);
	PresenTation_Base();
	glPopMatrix();
	
	glPushMatrix();
	glRotatef(180,0,1,0);
	glTranslatef(0,0,600);
	TARGETBASE();
	glPopMatrix();
	
	
	
	glutSwapBuffers();
}

void Keypress(unsigned char key,int x,int y)
{
	switch(key)
	{
		case 'W':
			Z=Z+5;
			break;
		case 'S':
			Z=Z-5;
			break;
		case 'A':
			X=X-5;
			break;
		case 'D':
			X=X+5;
			break;
		case 'K':
			Y=Y+25;
			break;
		case 'L':
			Y=Y-25;
			break;
		case 'G':
			rot+=5;
			break;
		case 'H':
			rot-=5;
			break;
	}
	glutPostRedisplay();
}

void Time(int value)
{	
	if(bridge>0&&bridge<=90)
	{
		bridge+=1;
		glutPostRedisplay();
	glutTimerFunc(1,Time,0);
	}
	
	if(key_d1>0&&key_d1<=100)
	{
		key_d1+=1;
		glutPostRedisplay();
	glutTimerFunc(1,Time,0);
}

if(key_d2l<200&&key_d2l>0)
	{
		key_d2l-=1;
		glutPostRedisplay();
	glutTimerFunc(1,Time,0);
}

if(key_d2r<200&&key_d2r>0)
	{
		key_d2r-=1;
		glutPostRedisplay();
	glutTimerFunc(1,Time,0);
}

if(key_dl<200&&key_dl>0)
	{
		key_dl+=1;
		glutPostRedisplay();
	glutTimerFunc(1,Time,0);
}
	
	if(key_dr<200&&key_dr>0)
	{
		key_dr+=1;
		glutPostRedisplay();
	glutTimerFunc(1,Time,0);
}
		
if(key_main_get>0&&key_main_get<90)
	{
		key_main_get+=0.5;
		glutPostRedisplay();
		glutTimerFunc(100,Time,0);
	}

}

void Check()
{
//---------------presentation----------
	if(mov_z>-500&&mov_z<500)
	{
		if(mov_x<-470||mov_x>470)
			no=1;
		else if(mov_z>470&&mov_z<530)
		{
			if((mov_x>=80||mov_x<=-80))
			no=1;
		}
		else if(mov_z<-470)
		no=1;
	}
	
	
		
	//------------------------WALL1
	
	
	
//----------------Bridge-----------

	if(mov_z<300&&mov_z>200&&mov_x<50&&mov_x>-50&&bridge==0)
	{
		bridge=1;
		glutTimerFunc(1,Time,0);
	}
	
	
	if(mov_z<600&&mov_z>500)
	{
		if(mov_x<-25||mov_x>25)
			no=1;
	}
	
	//-------------------3--------4-------5
	
	if(mov_z>600&&mov_z<1600)
	{
		if(mov_x<-470||mov_x>470)
			no=1;
		else if(mov_z>1570&&mov_z<1630)
		{
			if((mov_x>=80||mov_x<=-80))
			no=1;
			else if(key_d1==0)
				no=1;
		}
	}
	
	
	//-----------16-----8-------9
	
	if(mov_z>3000&&mov_z<4000)
	{
		if(mov_x<-1500||mov_x>1500)
			no=1;
		else if(mov_z>3060&&mov_z<3130)
		{
			if((mov_x>=170||mov_x<=-170))
			no=1;
			else if(key_main_get==0)
				no=1;
		}
		
	}
	if(mov_z>4000)
		no=1;
		
	//-----------7,11
	
	if(mov_z>1600&&mov_z<3000)
	
	{
		if(mov_x<-1470||mov_x>1470)
			no=1;
	}
	//--------5  10
	if(mov_z>1850&&mov_z<2850)
	{
		if((mov_x<-470&&mov_x>-530)||(mov_x>470&&mov_x<530))
		no=1;
		
	}
	
	if(mov_z>1600&&mov_z<1850)
	{
		if((mov_x>470&&mov_x<530))
			if(key_d2l==0)
				no=1;
				
		if((mov_x<-470&&mov_x>-530))
			if(key_d2r==0)
				no=1;
		
	}
	
	if(mov_z>2850&&mov_z<3050)
	{
		if((mov_x>470&&mov_x<530))
			if(key_dr==0)
				no=1;
				
		if((mov_x<-470&&mov_x>-530))
			if(key_dl==0)
				no=1;
	}
	
	//---------------open door1
	
	if(mov_z>1250&&mov_z<1350&&mov_x>300&&mov_x<400&&key_d1==0)
	{
		key_d1=1;
		glutTimerFunc(1,Time,0);
	}
	
	//-----------------door__2  left
	
	if(mov_x>600&&key_d2l==200)
	{
		key_d2l=199;
		glutTimerFunc(1,Time,0);
	}
		
	//----------door  2 right
	
	if(mov_x<-600&&key_d2r==200)
	{
		key_d2r=199;
		glutTimerFunc(1,Time,0);
	}
	
	//////------------door 3  left
	
	if(mov_z>2750&&mov_z<2850&&mov_x>1250&&mov_x<1350&&key_dr==0)
	{
		key_dr=1;
		glutTimerFunc(1,Time,0);
	}
	//////------------door 3  right
	
	if(mov_z>2750&&mov_z<2850&&mov_x>-1350&&mov_x<-1250&&key_dl==0)
	{
		key_dl=1;
		glutTimerFunc(1,Time,0);
	}

//--------------main get
	if(mov_z>2250&&mov_z<2350&&mov_x>-100&&mov_x<100&&key_main_get==0&&key_dr!=0&&key_dl!=0)
	{
		key_main_get=1;
		glutTimerFunc(1,Time,0);
	}
	
}
			

void FUNCTION(int key,int x,int y)
{
	switch(key)
	{
		case GLUT_KEY_RIGHT:
			rot_obj+=5;
			break;
		case GLUT_KEY_LEFT:
			rot_obj-=5;
			break;
		case GLUT_KEY_UP:
			mov_z=mov_z+25*cos(rot_obj*3.141/180);
			mov_x=mov_x+25*sin(rot_obj*3.141/180);
			Check();
			if(no==1)
			{
				mov_z=mov_z-25*cos(rot_obj*3.141/180);
				mov_x=mov_x-25*sin(rot_obj*3.141/180);
				no=0;
			}
			cout<<mov_x<<" "<<mov_z<<endl;
			break;
	}
	glutPostRedisplay();
}
			
		

void Enable()
{
	glEnable(GL_DEPTH_TEST);
}

void Resize(int w,int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45,w/h,1,5000);
}




int main(int argv,char **argc)
{
	glutInit(&argv,argc);
	glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE|GLUT_DEPTH);
	glutInitWindowSize(768,768);
	glutCreateWindow("PROJECT");
	Enable();
	glutReshapeFunc(Resize);
	glutDisplayFunc(Display);
	glutKeyboardFunc(Keypress);
	glutSpecialFunc(FUNCTION);
	glutMainLoop();
	return 0;
}
