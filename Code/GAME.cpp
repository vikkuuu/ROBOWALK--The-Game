#include <iostream>
#include <GL/glut.h>
#include <math.h>
using namespace std;
GLfloat C[3]={0};
GLfloat X=0,Y=200,Z=-375,rot=0,rot_left_arm=0,rot_left_hand=0,left_hand=1;
GLfloat rot_right_arm=0,rot_right_hand=0;
GLfloat rot_left_leg=0,rot_left_foot=0,a=0,b=0;
GLfloat rot_right_leg=0,rot_right_foot=0,rightfoot=0,leftfoot=0;
GLfloat rot_robo=0,rx=0,rz=0,mov_x=0,mov_z=0,fix_x=0,fix_z=0;
GLfloat cam_x=0,cam_z=0,rot_cam=0,cam_pos_x=0,cam_pos_z=0;
GLfloat jugad_x=0,jugad_z=0,mov=0,no=0,bridge=0,key_main_get=0;
GLint grid=0,var1=10,var2=10,rou=0,sur=1,use_cam=3,jugad=0,Edit=1,yes=0,start=1;
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


void Cuboid(float b,float l,float h)
{
		
		if(Edit==1)
			glColor3fv(C);
		
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
	Cube(100,20,160);
	
	glLineWidth(10);
	
	for(int i=20;i<=160;i=i+20)
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

	}
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
	
	if(key_dl!=0&&key_dr!=0)
	{
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
	glRotatef(bridge,-1,0,0);
	Cube(2,100,100);
	glPopMatrix();
	
	
	DRAW_WALLS();
	
}

void GRID()
{
	glColor3f(0,0,0);
	glLineWidth(5);
	for(int i=-2000;i<=2000;i=i+100)
	{
		glBegin(GL_LINES);
		glVertex3f(i,0.5,-2000);
		glVertex3f(i,0.5,2000);
		glVertex3f(-2000,0.5,i);
		glVertex3f(2000,0.5,i);
		glEnd();
	}
}
	

void makebase()
{
	glBegin(GL_POLYGON);
	glColor3f(0,1,0.0);
	glVertex3f(-1000,0,1000);
	glVertex3f(-1000,0,-1000);
	glVertex3f(1000,0,-1000);
	glVertex3f(1000,0,1000);
	glEnd();
}

void HEAD()
{
	glColor3f(0.070,0.130,0.180);
	glBegin(GL_POLYGON);
	glVertex3f(5,0,0);
	glVertex3f(-5,0,0);
	glVertex3f(-5,25,0);
	glVertex3f(5,25,0);
	glEnd();
	
	
	//-----eye----------------
	
	glColor3f(0,0,0);
	glBegin(GL_POLYGON);
	glVertex3f(5+0.71,21,0.71);
	glVertex3f(6.4+5,21,6.2);
	glVertex3f(6.4+5,17,6.2);
	glVertex3f(5+0.71,17,0.71);
	glEnd();
	
	glColor3f(0.6,0.9,0.7);
	glBegin(GL_POLYGON);
	glVertex3f(5+0.35+0.71,20.5,0.6);
	glVertex3f(6.011+5,20.5,5.8);
	glVertex3f(6.011+5,17.5,5.8);
	glVertex3f(5+0.35+0.71,17.5,0.6);
	glEnd();
	
	glColor3f(0,0,0);
	glBegin(GL_POLYGON);
	glVertex3f(-5-0.71,21,0.71);
	glVertex3f(-6.4-5,21,6.2);
	glVertex3f(-6.4-5,17,6.2);
	glVertex3f(-5-0.71,17,0.71);
	glEnd();
	
	glColor3f(0.6,0.9,0.7);
	glBegin(GL_POLYGON);
	glVertex3f(-5-0.35-0.71,20.5,0.6);
	glVertex3f(-6.011-5,20.5,5.8);
	glVertex3f(-6.011-5,17.5,5.8);
	glVertex3f(-5-0.35-0.71,17.5,0.6);
	glEnd();
	
//-----------------------------------------	
	glColor3f(0.176,0.196,0.222);
	glBegin(GL_POLYGON);
	glVertex3f(5,0,0);
	glVertex3f(7.072+5,0,7.072);
	glVertex3f(7.072+5,25,7.072);
	glVertex3f(5,25,0);
	glEnd();
	
	glColor3f(0.047,0.079,0.079);
	glBegin(GL_POLYGON);
	glVertex3f(7.072+5,0,7.072);
	glVertex3f(7.072+5,25,7.072);
	glVertex3f(7.072+5,25,7.072+10);
	glVertex3f(7.072+5,0,7.072+10);
	glEnd();
	
	glColor3f(0.1,0.2,0.3);
	glBegin(GL_POLYGON);
	glVertex3f(7.072+5,0,7.072+10);
	glVertex3f(7.072+5,25,7.072+10);
	glVertex3f(5,25,7.072+7.072+10);
	glVertex3f(5,0,7.072+7.072+10);
	glEnd();
	
	glColor3f(0.1,0.2,0.3);
	glBegin(GL_POLYGON);
	glVertex3f(5,0,14.144+10);
	glVertex3f(-5,0,14.144+10);
	glVertex3f(-5,25,14.144+10);
	glVertex3f(5,25,14.144+10);
	glEnd();
	
	glColor3f(0.1,0.2,0.3);
	glBegin(GL_POLYGON);
	glVertex3f(-7.072-5,0,7.072+10);
	glVertex3f(-7.072-5,25,7.072+10);
	glVertex3f(-5,25,7.072+7.072+10);
	glVertex3f(-5,0,7.072+7.072+10);
	glEnd();
	
	glColor3f(0.047,0.079,0.079);
	glBegin(GL_POLYGON);
	glVertex3f(-7.072-5,0,7.072);
	glVertex3f(-7.072-5,25,7.072);
	glVertex3f(-7.072-5,25,7.072+10);
	glVertex3f(-7.072-5,0,7.072+10);
	glEnd();
	
	glColor3f(0.176,0.196,0.222);
	glBegin(GL_POLYGON);
	glVertex3f(-5,0,0);
	glVertex3f(-7.072-5,0,7.072);
	glVertex3f(-7.072-5,25,7.072);
	glVertex3f(-5,25,0);
	glEnd();
	
	
	//-------------------nose-------
	
	glColor3f(0,0,0);
	glBegin(GL_POLYGON);
	glVertex3f(0,17,-0.1);
	glVertex3f(4,12,-0.1);
	glVertex3f(-4,12,-0.1);
	glEnd();
	
	glColor3f(0.6,0.9,0.7);
	glBegin(GL_POLYGON);
	glVertex3f(0,16.8,-0.2);
	glVertex3f(3.8,12.2,-0.2);
	glVertex3f(-3.8,12.2,-0.2);
	glEnd();
	
	//----------------mouth-------
	
	glColor3f(0.6,0.9,0.7);
	glBegin(GL_POLYGON);
	glVertex3f(5,0,-0.1);
	glVertex3f(2,8,-0.1);
	glVertex3f(2,3,-0.1);
	glVertex3f(4,0,-0.1);
	glEnd();
	
	glBegin(GL_POLYGON);
	glVertex3f(-2,8,-0.1);
	glVertex3f(2,8,-0.1);
	glVertex3f(2,3,-0.1);
	glVertex3f(-2,3,-0.1);
	glEnd();
	
	glBegin(GL_POLYGON);
	glVertex3f(-2,8,-0.1);
	glVertex3f(-5,0,-0.1);
	glVertex3f(-4,0,-0.1);
	glVertex3f(-2,3,-0.1);
	glEnd();
	
	//----------ears---------------
	glPushMatrix();
	glTranslatef(12.072+1,17-2,12.072);
	glColor3f(0.240,0.230,0.140);
	Cuboid(4,2,4);
	glTranslatef(1.5,0.5,0);
	glColor3f(0.250,0.250,0.210);
	Cuboid(3,1,3);
	glPopMatrix();
	
	
	glColor3f(0.240,0.230,0.140);
	glPushMatrix();
	glTranslatef(-12.072-1,17-2,12.072);
	Cuboid(4,2,4);
	glTranslatef(-1.5,0.5,0);
	glColor3f(0.250,0.250,0.210);
	Cuboid(3,1,3);
	glPopMatrix();
	
	//-----------------------plates----------
	
	glColor3f(0,0,0);
	
	glBegin(GL_POLYGON);
	glVertex3f(5,0,0);
	glVertex3f(5+7.072,0,7.072);
	glVertex3f(5+7.072,0,17.072);
	glVertex3f(5,0,2*7.072+10);
	glVertex3f(-5,0,2*7.072+10);
	glVertex3f(-5-7.072,0,17.072);
	glVertex3f(-5-7.072,0,7.072);
	glVertex3f(-5,0,0);
	glEnd();
	
	glBegin(GL_POLYGON);
	glVertex3f(5,25,0);
	glVertex3f(5+7.072,25,7.072);
	glVertex3f(5+7.072,25,17.072);
	glVertex3f(5,25,2*7.072+10);
	glVertex3f(-5,25,2*7.072+10);
	glVertex3f(-5-7.072,25,17.072);
	glVertex3f(-5-7.072,25,7.072);
	glVertex3f(-5,25,0);
	glEnd();
	
	//---------------------NECK-------------
	
	glPushMatrix();
	glColor3f(0,0.255,0.127);
	glTranslatef(0,-1,12.072);
	Cuboid(15,15,1);
	for(int i=0;i<6;i++)
	{
		glTranslatef(0,-1,0);
		glColor3f(0,0.255,0.127);
		Cuboid(15-i/3,15-i/3,1);
	}	
	glPopMatrix();
	
}

void LOGO()
{
	glColor3f(1,1,0);
    glBegin(GL_POLYGON);
        glVertex3f(0,0,0);
        glVertex3f(-5,-2,0);
        glVertex3f(12,-15,0);
       glEnd();
		glBegin(GL_POLYGON);
        glVertex3f(-2,-4,0);
        glVertex3f(4,0,0);
        glVertex3f(0,8,0);
        glVertex3f(-6,8,0);
        glEnd();
		glBegin(GL_POLYGON);
        glVertex3f(-1,8,0);
        glVertex3f(4,8,0);
        glVertex3f(0,20,0);
        glVertex3f(-7.5,21,0);
       glEnd();
 }

 void Symbol()
{
    
   
   GLUquadric *q;
    q=gluNewQuadric();
    glColor3f(0.6,0.9,0.7);
    gluDisk( q, 4.8, 6.5, 50, 50);
    glTranslatef(0,0,0);
    glColor3f(1,1,0);
    glBegin(GL_POLYGON);
    glVertex3f(0,0,0);
    glVertex3f(2,2,0);
    glVertex3f(-2,-6,0);
    glVertex3f(3,4,0);


        

    glEnd(); 
    glColor3f(1,1,0);
    glBegin(GL_POLYGON);
    glVertex3f(0,0,0);
    glVertex3f(-2,2,0);
    glVertex3f(2,-6,0);
    glVertex3f(-3,4,0);

        
    glEnd();  
glRotatef(180,1,0,0);


    GLUquadric *q1;
    q1=gluNewQuadric();
    glColor3f(0.6,0.9,0.7);
    gluDisk( q1, 4.8, 6.5, 50, 50);
    glTranslatef(0,0,0);
    glColor3f(1,1,0);
    glBegin(GL_POLYGON);
    glVertex3f(0,0,0);
    glVertex3f(2,2,0);
    glVertex3f(-2,-6,0);
    glVertex3f(3,4,0);


        

    glEnd(); 
    glColor3f(1,1,0);
    glBegin(GL_POLYGON);
    glVertex3f(0,0,0);
    glVertex3f(-2,2,0);
    glVertex3f(2,-6,0);
    glVertex3f(-3,4,0);

        
    glEnd();
}

 
void Bullet()
{
	glPushMatrix();
	glColor3f(1,0,0);
	Cuboid(5,5,5);
	glTranslatef(0,2.5,2.5);
	
	glColor3f(1,1,0);
	glBegin(GL_POLYGON);
	glVertex3f(-2.5,2.5,0);
	glVertex3f(2.5,2.5,0);
	glVertex3f(0,0,5);
	glEnd();
	
	glBegin(GL_POLYGON);
	glVertex3f(-2.5,2.5,0);
	glVertex3f(-2.5,-2.5,0);
	glVertex3f(0,0,5);
	glEnd();
	
	glBegin(GL_POLYGON);
	glVertex3f(2.5,-2.5,0);
	glVertex3f(-2.5,-2.5,0);
	glVertex3f(0,0,5);
	glEnd();
	
	glBegin(GL_POLYGON);
	glVertex3f(2.5,2.5,0);
	glVertex3f(2.5,-2.5,0);
	glVertex3f(0,0,5);
	glEnd();
	glPopMatrix();
}
void BAZOOKA()
{
	glColor3f(0,1,1);
	Cuboid(25,10,10);
	
	glTranslatef(0,5,12.5);
	
	
	glColor3f(0,0,0);
	GLUquadric *d1;
	d1=gluNewQuadric();
	gluDisk(d1,0,7.075,25,25);
	
	GLUquadric *q;
	glColor3f(0,0,1);
	q=gluNewQuadric();
	gluCylinder(q,7.075,9,35,25,25);
	
	glTranslatef(0,0,10);
	glColor3f(0,0,0);
	Cuboid(10,20,3);
	glPushMatrix();
	if(yes==0||yes==1)
		glTranslatef(0,0,3);
	else 
		glTranslatef(0,0,-3);
	Cuboid(3,65,2.5);
	glPopMatrix();
	glTranslatef(0,0,22);
	glColor3f(0,0,0);
	GLUquadric *d3;
	d3=gluNewQuadric();
	gluDisk(d3,0,11,25,25);
	
	GLUquadric *q1;
	q1=gluNewQuadric();
	gluCylinder(q1,11,11,3,25,25);
	
	glTranslatef(0,0,3);
	glColor3f(0,0,0);
	GLUquadric *d2;
	d2=gluNewQuadric();
	gluDisk(d2,0,11,25,25);
	
}

void MID()
{
	glColor3f(1,0,1);
	Cuboid(26.4,40.5,12);
	glColor3f(0.6,0.9,0.7);
	glTranslatef(0,12,0);
	Cuboid(23.1,33.75,22);
	glColor3f(1,0,0);
	glTranslatef(0,22,0);
	Cuboid(28.05,47.25,25);

	//--------------Symbol---------

	glPushMatrix();
	glScalef(2.4,2.4,1);
    glTranslatef(0,3,14.5);
    Symbol();
    glPopMatrix();
	
	//----------------LOGO----
	glPushMatrix();
	glScalef(1.25,1,1);
	glTranslatef(-2,0,-14.2);
	LOGO();
	glPopMatrix();
	
	//---------------Bazooka-----------
	glPushMatrix();
	if(yes==0){
	glRotatef(30,0,0,-1);
	glTranslatef(0,-17,27);
	glRotatef(90,-1,0,0);
	}
	if(yes==1)
	{
		glTranslatef(0,0,-10);
		glRotatef(180,1,0,0);
	}
	if(yes==2)
	{
		glTranslatef(0,-8,-10);
		glRotatef(180,1,0,0);
	}
	BAZOOKA();
	glPopMatrix();
	
	//--------------Bullet--------------
	
	glPushMatrix();
	if(yes==0){
	glRotatef(30,0,0,-1);
	glTranslatef(0,-17,27);
	glRotatef(90,-1,0,0);
	glTranslatef(0,0,50);
	}
	if(yes==1)
	{
		glTranslatef(0,0,-20);
		glRotatef(180,1,0,0);
		glTranslatef(0,0,40);
	}
	if(yes==2){
	glRotatef(180,-1,0,0);
		glTranslatef(0,0,40+mov);
		}
	Bullet();
	glPopMatrix();


	
}




void RIGHTHAND()
{
	glPushMatrix();
	glRotatef(rot_right_arm,-1,0,0);
	glTranslatef(0,6,0);
	glColor3f(0,0,0);
	
	glBegin(GL_POLYGON);
	glVertex3f(0,0,-9.9);
	glVertex3f(0,12,-9.9);
	glVertex3f(0,12,9.9);
	glVertex3f(0,0,9.9);
	glEnd();
	
	glBegin(GL_POLYGON);
	glVertex3f(0,0,-9.9);
	glVertex3f(-20,0,-9.9);
	glVertex3f(0,12,-9.9);
	glEnd();
	
	glBegin(GL_POLYGON);
	glVertex3f(0,0,9.9);
	glVertex3f(-20,0,9.9);
	glVertex3f(0,12,9.9);
	glEnd();
	
	glBegin(GL_POLYGON);
	glVertex3f(-20,0,-9.9);
	glVertex3f(-20,0,9.9);
	glVertex3f(0,12,9.9);
	glVertex3f(0,12,-9.9);
	glEnd();
	
	glPopMatrix();
	

	glPushMatrix();
	glColor3f(1,0.2,0.2);
	glTranslatef(-9.45,-6,0);
	Cuboid(19.8,18.9,12);
	glColor3f(0.6,0.9,0.7);
	glTranslatef(-0.675,-11,0);
	Cuboid(16.5,13.5,11);
	glPopMatrix();
	
	glTranslatef(-10.125,-24,0);
	glColor3f(1,0.2,0.2);
	Cuboid(18.15,14.85,8);
	
	glPushMatrix();
	glRotatef(rot_right_hand,1,0,0);
	glTranslatef(-0.5,-18,0);
	glColor3f(1,0,0);
	Cuboid(20.625,19.575,18);
	glTranslatef(0,-12,0);
	glColor3f(0,0,1);
	Cuboid(18.15,14.85,12);
	glPopMatrix();
	
	
}

void LEFTHAND()
{

	glPushMatrix();
	glRotatef(rot_left_arm,-1,0,0);
	glTranslatef(0,6,0);
	glColor3f(0,0,0);
	
	glBegin(GL_POLYGON);
	glVertex3f(0,0,-9.9);
	glVertex3f(0,12,-9.9);
	glVertex3f(0,12,9.9);
	glVertex3f(0,0,9.9);
	glEnd();
	
	glBegin(GL_POLYGON);
	glVertex3f(0,0,-9.9);
	glVertex3f(20,0,-9.9);
	glVertex3f(0,12,-9.9);
	glEnd();
	
	glBegin(GL_POLYGON);
	glVertex3f(0,0,9.9);
	glVertex3f(20,0,9.9);
	glVertex3f(0,12,9.9);
	glEnd();
	
	glBegin(GL_POLYGON);
	glVertex3f(20,0,-9.9);
	glVertex3f(20,0,9.9);
	glVertex3f(0,12,9.9);
	glVertex3f(0,12,-9.9);
	glEnd();
	
	glPopMatrix();
	
	glPushMatrix();
	glColor3f(1,0.2,0.2);
	glTranslatef(9.45,-6,0);
	Cuboid(19.8,18.9,12);
	glColor3f(0.6,0.9,0.7);
	glTranslatef(0.675,-11,0);
	Cuboid(16.5,13.5,11);
	glPopMatrix();
	
	glTranslatef(10.125,-24,0);
	glColor3f(1,0.2,0.2);
	Cuboid(18.15,14.85,8);
	
	glPushMatrix();
	glRotatef(rot_left_hand,1,0,0);
	glTranslatef(0.5,-18,0);
	glColor3f(1,0,0);
	Cuboid(20.625,19.575,18);
	glTranslatef(0,-12,0);
	glColor3f(0,0,1);
	Cuboid(18.15,14.85,12);
	glPopMatrix();
	
	
}

void LEFTFOOT()
{
	if(leftfoot>0)
	{
		
		glPushMatrix();
	glTranslatef(mov_x+fix_x,0,mov_z+fix_z);
		glRotatef(rot_robo,0,1,0);
	glColor3f(0.6,0.9,0.7);
	glTranslatef(12,-2,0);
	
	glRotatef(leftfoot/5,-1,0,0);
	for(int i=0;i<10;i++)
	{
		Cuboid(16.5,18.9,3);
		glTranslatef(0.3,-3,0);
	}
	glTranslatef(-0.3,-2,0);
	glColor3f(1,0,0);
	Cuboid(16.5,18.9,5);
	glPopMatrix();
	
	glPushMatrix();
	glColor3f(0,0,1);
	glTranslatef(mov_x+fix_x,0,mov_z+fix_z);
		glRotatef(rot_robo,0,1,0);
	glTranslatef(14.7,-30,0);
	glRotatef(leftfoot,-1,0,0);
	glTranslatef(0,-4,0);
	for(int i=0;i<12;i++)
	{
		glTranslatef(0.2,-4,0);
		Cuboid(18.15,20.35,4);
	}
	glColor3f(0,0,0);
	glTranslatef(-0.2,0,-9.075);
	Cuboid(9.075,20.25,8);
	glPopMatrix();
}
	
	
	
else{	
	glPushMatrix();
	if(var1>0)
	{
		glRotatef(rot_robo,0,1,0);
		glRotatef(rot_left_leg,1,0,0);
		glColor3f(0.6,0.9,0.7);
		glTranslatef(12,-2,0);
		for(int i=0;i<10;i++)
		{
			Cuboid(16.5,18.9,3);
			glTranslatef(0.3,-3,0);
		}
		glTranslatef(-0.3,-2,0);
		glColor3f(1,0,0);
		Cuboid(16.5,18.9,5);
	}
	if(var1<0)
	{
		rx=mov_x+fix_x;
		rz=mov_z+fix_z;
		//glTranslatef(-rx,0,-rz);
		glRotatef(rot_robo,0,1,0);
		//glTranslatef(rx,0,rz);
		glTranslatef(14.7,-27,-21.5);
		glRotatef(rot_left_leg,1,0,0);
		glTranslatef(0,-6+rot_left_leg/36,0);
		glColor3f(1,0,0);
		Cuboid(16.5,18.9,5);
		glTranslatef(0,5,0);
		for(int i=0;i<11;i++)
		{
			Cuboid(16.5,18.9,3);
			if(i==8)
				glColor3f(0.6,0.9,0.7);
			if(i==9)
				glColor3f(1,0,1);
			glTranslatef(-0.3,3,0);
		}
	}
	glPopMatrix();
	
	glPushMatrix();
	if(var1>0)
		glRotatef(rot_robo,0,1,0);
	else
	{
		//glTranslatef(rx,0,rz);
		glRotatef(rot_robo,0,1,0);
		//glTranslatef(-rx,0,-rz);
		}
	if(var1>0)
		glRotatef(rot_left_leg,1,0,0);
	else
		glRotatef(40,1,0,0);
	glColor3f(0,0,1);
	glTranslatef(14.7,-38,0);
	
	if(var1>0)
	{
		a=0;
		glRotatef(rot_left_foot,-1,0,0);
		glTranslatef(0,rot_left_foot/10,(rot_left_foot/12.0));
	}
	else 
	{
		glRotatef(40,-1,0,0);
		if(a<8.19)
		{
			glTranslatef(0,rot_left_foot/10-a,3.33);
			a=a+0.819;
		}
		else {
				glTranslatef(0,-8.19,3.33);
				}
	}
	
	
	
	for(int i=0;i<12;i++)
	{
		Cuboid(18.15,20.25,4);
		glTranslatef(0.2,-4,0);
	}
	glColor3f(0,0,0);
	glTranslatef(-0.2,4,-9.075);
	Cuboid(9.075,20.25,8);
	glPopMatrix();
	
	}
}

void RIGHTFOOT()
{

	if(rightfoot>0)
	{
	glPushMatrix();
	glColor3f(0.6,0.9,0.7);
	glTranslatef(mov_x+fix_x,0,mov_z+fix_z);
		glRotatef(rot_robo,0,1,0);
	glTranslatef(-12,-2,0);
	glRotatef(rightfoot/5,-1,0,0);
	for(int i=0;i<10;i++)
	{
		Cuboid(16.5,18.9,3);
		glTranslatef(-0.3,-3,0);
	}
	glTranslatef(0.3,-2,0);
	glColor3f(1,0,0);
	Cuboid(16.5,18.9,5);
	glPopMatrix();
	
	glPushMatrix();
	glColor3f(0,0,1);
	glTranslatef(mov_x+fix_x,0,mov_z+fix_z);
		glRotatef(rot_robo,0,1,0);
	glTranslatef(-14.7,-30,0);
	glRotatef(rightfoot,-1,0,0);
	glTranslatef(0,-4,0);
	for(int i=0;i<12;i++)
	{
		glTranslatef(-0.2,-4,0);
		Cuboid(18.15,20.25,4);
		
	}
	glColor3f(0,0,0);
	glTranslatef(0.2,0,-9.075);
	Cuboid(9.075,20.25,8);
	glPopMatrix();
	
	}
	else {
	glPushMatrix();
	if(var2>0)
	{
		glRotatef(rot_robo,0,1,0);
		glRotatef(rot_right_leg,1,0,0);
		glColor3f(0.6,0.9,0.7);
		glTranslatef(-12,-2,0);
		for(int i=0;i<10;i++)
		{
			Cuboid(16.5,18.9,3);
			glTranslatef(-0.3,-3,0);
		}
		glTranslatef(0.3,-2,0);
		glColor3f(1,0,0);
		Cuboid(16.5,18.9,5);
	}
	if(var2<0)
	{
		rx=mov_x+fix_x;
		rz=mov_z+fix_z;
		//glTranslatef(rx,0,rz);
		glRotatef(rot_robo,0,1,0);
		//glTranslatef(-rx,0,-rz);
		glTranslatef(-14.7,-27,-21.5);
		glRotatef(rot_right_leg,1,0,0);
		glTranslatef(0,-6+rot_right_leg/36,0);
		glColor3f(1,0,0);
		Cuboid(16.5,18.9,5);
		glTranslatef(0,5,0);
		for(int i=0;i<11;i++)
		{
			Cuboid(16.5,18.9,3);
			if(i==8)
				glColor3f(0.6,0.9,0.7);
			if(i==9)
				glColor3f(1,0,1);
			glTranslatef(0.3,3,0);
		}
	}
	glPopMatrix();
	
	glPushMatrix();
	
	if(var2>0)
		glRotatef(rot_robo,0,1,0);
	else
	{
		//glTranslatef(rx,0,rz);
		glRotatef(rot_robo,0,1,0);
		//glTranslatef(-rx,0,-rz);
		}
	
	if(var2>0)
		glRotatef(rot_right_leg,1,0,0);
	else
		glRotatef(40,1,0,0);
	
	glColor3f(0,0,1);
	glTranslatef(-14.7,-38,0);
	
	if(var2>0)
	{
		b=0;
		glRotatef(rot_right_foot,-1,0,0);
		glTranslatef(0,rot_right_foot/10,rot_right_foot/12.0);
	}
	else 
	{
		glRotatef(40,-1,0,0);
		if(b<8.19)
		{
			glTranslatef(0,rot_right_foot/10-b,3.33);
			b=b+0.819;
		}
		else {
				glTranslatef(0,-8.19,3.33);
				}
	}
	
	for(int i=0;i<12;i++)
	{
		Cuboid(18.15,20.25,4);
		glTranslatef(-0.2,-4,0);
	}
	glColor3f(0,0,0);
	glTranslatef(0.2,4,-9.075);
	Cuboid(9.75,20.25,8);
	glPopMatrix();
	
	}
}


void ROBOT()
{
	glPushMatrix();
	glTranslatef(mov_x,148,0+mov_z);
	glRotatef(rot_robo,0,1,0);
	glTranslatef(0,0,-12.0721);
	HEAD();
	glPopMatrix();
	
	
	
	
	glPushMatrix();
	//glScalef(1.35,1,1.65);
	
	glPushMatrix();
	glTranslatef(mov_x,82,mov_z);
	glRotatef(rot_robo,0,1,0);
	MID();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(mov_x,0,mov_z);
	glRotatef(rot_robo,0,1,0);
	glTranslatef(-23.5,135,0);
	glRotatef(rot_right_arm,1,0,0);
	glTranslatef(0,-1,0);
	RIGHTHAND();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(mov_x,0,mov_z);
	glRotatef(rot_robo,0,1,0);
	glTranslatef(23.5,135,0);
	glRotatef(rot_left_arm,1,0,0);
	glTranslatef(0,-1,0);
	LEFTHAND();
	glPopMatrix();
	
	glPushMatrix();
	
	glTranslatef(-fix_x,82,-fix_z);
	
	LEFTFOOT();
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(-fix_x,82,-fix_z);
	RIGHTFOOT();
	glPopMatrix();
	
	glPopMatrix();

}


void Display()
{
	if(sur>0)
		glClearColor(1,1,1,1);
	else
		glClearColor(0,0,0,1);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	if(rou==1){
		gluLookAt(cam_x,Y,cam_z,mov_x,100,mov_z,0,1,0);
		rou=0;
	}
	else if(use_cam==0||use_cam==1)
	{
		gluLookAt(X+mov_x,Y,Z+mov_z,+mov_x,100,mov_z,0,1,0);
		rot_cam=0;
		}
	else if(use_cam==2||yes==0)
	{
		if(jugad==0)
		{
			gluLookAt(cam_pos_x,Y,cam_pos_z,mov_x,100,mov_z,0,1,0);
			jugad_x=mov_x;
			jugad_z=mov_z;
			jugad=1;
		}
		else
		{
			gluLookAt(mov_x-jugad_x+cam_pos_x,Y,mov_z-jugad_z+cam_pos_z,mov_x,100,mov_z,0,1,0);
		}
	}
	else if(use_cam==3)
	{
		gluLookAt(0,200,600,0,0,-1000,0,1,0);
	}
	else if(use_cam==4)
	{
		if(jugad==0)
		{
			gluLookAt(cam_pos_x+200,Y+300,cam_pos_z,mov_x,0,mov_z+300,0,1,0);
			jugad_x=mov_x;
			jugad_z=mov_z;
			jugad=1;
		}
		else
		{
			gluLookAt(mov_x-jugad_x+cam_pos_x+200,Y+300,mov_z-jugad_z+cam_pos_z,mov_x,0,mov_z+300,0,1,0);
		}
	}
	cout<<mov_x<<" "<<mov_z<<" "<<endl;
	
	if(no==1)
	{
		
	rot_left_arm=0;
	rot_left_hand=0;
	left_hand=1;
	rot_right_arm=0;
	rot_right_hand=0;
	rot_left_leg=0;
	rot_left_foot=0;
	rot_right_leg=0;
	rot_right_foot=0;
	rightfoot=0;
	leftfoot=0;
	var1=10;
	var2=10;
	no=0;
	fix_x-=21.5*sin(rot_robo*3.141/180);
	fix_z-=21.5*cos(rot_robo*3.141/180);
	mov_x=-fix_x;
	mov_z=-fix_z;
	
}
	cout<<rot_left_leg<<" "<<rot_left_foot<<" "<<rot_left_hand<<" "<<rot_left_arm<<endl;
	

	
	
//------------------GRID--------------------

	if(grid==1)
	{
		glPushMatrix();
		glTranslatef(0,0,0);
		GRID();
		glPopMatrix();
	}
	
//----------------BASE----------------------
	/*glPushMatrix();
	glTranslatef(0,0,0);
	makebase();
	glPopMatrix();*/
	
//--------------ROBOT-------------------------

	glPushMatrix();
	glTranslatef(0,0,0);
	ROBOT();
	glPopMatrix();

//-----------SURROUNDING
glPushMatrix();
glTranslatef(0,0,0);
glRotatef(180,0,1,0);
glPushMatrix();
	glTranslatef(0,0,0);
	PresenTation_Base();
	glPopMatrix();
	
	glPushMatrix();
	glRotatef(180,0,1,0);
	glTranslatef(0,0,600);
	TARGETBASE();
	glPopMatrix();	
glPopMatrix();
	glutSwapBuffers();
}

void Normal()
{
	rot_left_arm=0;
	rot_left_hand=0;
	left_hand=1;
	rot_right_arm=0;
	rot_right_hand=0;
	rot_left_leg=0;
	rot_left_foot=0;
	rot_right_leg=0;
	rot_right_foot=0;
	rightfoot=0;
	leftfoot=0;
	var1=10;
	var2=10;
	fix_x+=21.5*sin(rot_robo*3.141/180);
	fix_z+=21.5*cos(rot_robo*3.141/180);
	mov_x=-fix_x;
	mov_z=-fix_z;
}	

void Time(int value)
{
	if(yes==2)
	{
		mov+=2;
		if(mov>500)
		{
			start=1;
			mov=0;
			yes=0;
		}
		else
			start=0;
	glutPostRedisplay();
	glutTimerFunc(1,Time,0);
	}
	
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
void Keypress(unsigned char key,int x,int y)
{
	switch(key)
	{
		case'B':
			Edit=1;
			C[0]=0;  C[1]=0;  C[2]=0;
			break;
		case 'D':
			Edit=0;
			break;
		case 9:
			if(mov_x!=-fix_x)
			Normal();
			if(grid==0)
				grid=1;
			else grid=0;
			break;
		case 'M':
			if(mov_x!=-fix_x)
			Normal();
			rot_cam+=5;
			if(rot_cam>=360)
				rot_cam=0;
			cam_x=mov_x-375*sin(rot_cam*3.141/180);
			cam_z=mov_z-375*cos(rot_cam*3.141/180);
			rou=1;
			break;
		case 'N':
			if(mov_x!=-fix_x)
			Normal();
			rot_cam-=5;
			if(rot_cam<=0)
				rot_cam=360;
			cam_x=mov_x-375*sin(rot_cam*3.141/180);
			cam_z=mov_z-375*cos(rot_cam*3.141/180);
			rou=1;
			break;
		case '1':
			use_cam=1;
			break;
		case '2':
			use_cam=2;
			break;
		case '3':
			use_cam=3;
		case 32:
			if(start==1)
				yes+=1;
			if(yes==1){
				use_cam=4;
				rot_left_arm=17.7188218;
				rot_left_hand=72.2811782;
				rot_right_arm=17.7188218;
				rot_right_hand=72.2811782;
				}
			if(yes==2){
				rot_left_arm=0;
				rot_right_arm=0;
	glutTimerFunc(1,Time,0);
				}
			break;
	}
	glutPostRedisplay();
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
		case GLUT_KEY_UP:
		
			yes=0;
			start=1;
			if(left_hand==1)
			{
				if(rot_right_arm<20&&rot_right_arm>=0)
				{
					rot_right_arm+=var1;
					rot_left_arm-=var1*0.67;
					rot_left_hand+=var1*0.67;
					if(var1>0)
					{
						rot_left_leg+=var1;
					}
					if(var1<0)
					{
						rot_right_arm-=4*var1/20.0;
						rot_left_foot+=2*var1;
						rot_left_leg+=2*var1;
						mov_x-=1.075*var2*sin(rot_robo*3.141/180);
						mov_z-=1.075*var2*cos(rot_robo*3.141/180);
						rightfoot-=2*var1;
					}
					
				}
				else if(rot_right_hand<70&&rot_right_hand>=0)
				{
					rot_right_hand+=var1;
					rot_left_hand+=0.19*var1;
					rot_left_arm-=0.19*var1;
					if(var1>0)
					{
						rot_left_leg+=0.285714*var1;
						rot_left_foot+=0.571428*var1;
					}
					if(var1<0)
					{
						rot_right_hand-=var1*4/70.0;
						rightfoot+=0.571428*var1;
						if(rightfoot<=0)
							rightfoot=0.01;
					}
				}
				else if(rot_right_arm>=0)
					{
						rot_right_arm-=var1;
						rot_right_hand-=var1;
						var1=-1*var1;
					}
				else 
				{
					left_hand=0;
					rot_right_hand=0;
					rot_right_arm=0;
					rot_left_hand=0;
					rot_left_arm=0;
					var1=var1*-1;
					fix_x+=21.5*sin(rot_robo*3.141/180);
					fix_z+=21.5*cos(rot_robo*3.141/180);
					rot_left_leg=0;
					rot_left_foot=0;
					rightfoot=0;
				}
			}
			else
			{
				if(rot_left_arm<20&&rot_left_arm>=0)
				{
					rot_left_arm+=var2;
					rot_right_arm-=var2*0.67;
					rot_right_hand+=var2*0.67;
					if(var2>0)
					{
						rot_right_leg+=var2;
					}
					if(var2<0)
					{
						rot_left_arm-=var2*4/20.0;
						rot_right_foot+=2*var2;
						rot_right_leg+=2*var2;
						mov_x+=1.075*var2*sin(rot_robo*3.141/180);
						mov_z+=1.075*var2*cos(rot_robo*3.141/180);
						leftfoot-=2*var2;
					}
				}
				else if(rot_left_hand<70&&rot_left_hand>=0)
				{
					rot_left_hand+=var2;
					rot_right_hand+=0.19*var2;
					rot_right_arm-=0.19*var2;
					if(var2>0)
					{
						rot_right_leg+=0.285714*var2;
						rot_right_foot+=0.571428*var2;
					}
					if(var2<0)
					{
						rot_left_hand-=var2*4/70.0;
						leftfoot+=0.571428*var2;
						if(leftfoot<=0)
							leftfoot=0.01;
					}
				}
				else if(rot_left_arm>=0)
					{
						rot_left_arm-=var2;
						rot_left_hand-=var2;
						var2=-1*var2;
					}
				else 
				{
					left_hand=1;
					rot_left_hand=0;
					rot_left_arm=0;
					rot_left_hand=0;
					rot_right_hand=0;
					var2=var2*-1;
					fix_x+=21.5*sin(rot_robo*3.141/180);
					fix_z+=21.5*cos(rot_robo*3.141/180);
					rot_right_leg=0;
					rot_right_foot=0;
					leftfoot=0;
				}
			}
			Check();
			
			break;
		case GLUT_KEY_RIGHT:
			no=0;
			if(yes!=0)
			{
				rot_left_arm=0;
				rot_left_hand=0;
				rot_right_arm=0;
				rot_right_hand=0;
				yes=0;
				start=1;
			}
			if(mov_x!=-fix_x)
			Normal();
			rot_robo+=3;
			if(rot_robo>=360)
				rot_robo=0;
			cam_pos_x=mov_x-375*sin(-rot_robo*3.141/180);
			cam_pos_z=mov_z+375*cos(-rot_robo*3.141/180);
			jugad=0;
			break;
		case GLUT_KEY_LEFT:
			no=0;
			if(yes!=0)
			{
				rot_left_arm=0;
				rot_left_hand=0;
				rot_right_arm=0;
				rot_right_hand=0;
				yes=0;
				start=1;
			}
			if(mov_x!=-fix_x)
			Normal();
			rot_robo-=3;
			if(rot_robo<=0)
				rot_robo=360;
			cam_pos_x=mov_x-375*sin(-rot_robo*3.141/180);
			cam_pos_z=mov_z+375*cos(-rot_robo*3.141/180);
			jugad=0;
			break;
		case GLUT_KEY_HOME:
			sur=sur*-1;	
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
