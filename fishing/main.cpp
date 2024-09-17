#include <windows.h>
#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#define dx 15
#define dy 10
#define maxX 120
#define maxY 21

float fishangle=0;
float fishFlip=0;
void display();
void display11();
void display4();
void display1();
void display2();
void display3();
void drawm();
void drawr();
void sky();
void water();
void circle1(float x,float y,float r);
void circle2(float x,float y,float r);
void spincube();
GLfloat house[3][10]={{150.0,150.0,175,275,300.0,300.0,200.0,200.0,250.0,250.0},{150.0,350.0,400,400,350.0,150.0,150.0,250.0,250.0,150.0},{1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0,1.0}};
GLint a=90,b=0,c=0,w=0,g=0,d=290,e,i,j,k=0;
GLfloat s[maxX]={0,0},h[maxY]={0,0};
GLfloat s0=-170.0,h0=50.0;


GLfloat theta[3]={0.0,0.0,0.0};
GLint axis=0;


int flag1=0,flag=0,flag2=0,flag3=0;//set when a key is pressed
//To draw the sun
void sun()
{
	sky();
	glColor3ub(225,225,51);
	glPushMatrix();
	glTranslatef(950,700,0.0);
	glutSolidTorus(1,30,100,200);
	glPopMatrix();
}
//to color the display screen
void sky()
{
	glColor3f(0.0,1.0,0.0);//sky
	glBegin(GL_POLYGON);
	glColor3f(0.7,0.9,1.0);
    glVertex2f(0,1500);
	glColor3f(0.7,0.9,1.0);
	glVertex2f(1500,1500);
	glColor3f(1.0,1.0,0.0);
	glVertex2f(1500,0);
	glColor3f(0.7,0.9,1.0);
	glVertex2f(0,0);
	glEnd();

}
void clockWise()
{
	//sunAngle -= 1%360;
   fishangle -= 1%360;
   fishFlip = 180.0;
   glutPostRedisplay();
}
//keyboard function
void mykeys(unsigned char key,int x,int y)
{
	if(key=='f' || key=='F')
		display();
	if(c>290 && key=='r' ||key=='R')
		flag1=1;
	if(key=='q'||key=='Q')
		exit(0);
	if(key=='s'||key=='S')
		flag=0;
	if(key=='t'||key=='T')
	{
		    axis=0;
		flag=1;
	}
	if(key == 'c' || key == 'C')
        glutIdleFunc(clockWise);
    if( key=='n'||key=='N')
		flag2=1;
	glFlush();
}
//mouse function
void mouse(int state,int btn,int x,int y)
{
	//if(btn==GLUT_LEFT_BUTTON&&state==GLUT_DOWN)
	//exit(0);
	//if(btn==GLUT_MIDDLE_BUTTON&&state==GLUT_DOWN)
	//flag=1;
	//if(btn==GLUT_RIGHT_BUTTON&&state==GLUT_DOWN)
	//flag2=1;
	glFlush();
}
//to draw a polygon
void box(int a,int b,int c,int d,int e,int f,int g,int h)
{
	glColor3f(0.0,0.9,0.5);
	glBegin(GL_POLYGON);
	glVertex2f(a,b);
	glVertex2f(c,d);
	glVertex2f(e,f);
	glVertex2f(g,h);
	glEnd();
}
//to draw board in display3
void board()
{
	box(180,390,180,405,190,405,190,400);
	box(240,400,240,405,250,405,250,400);
    box(165,405,165,500,265,500,265,405);
	glColor3f(0.0,0.0,0.0);
	glRasterPos2i(180,450);
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,'F');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,'I');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,'S');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,'H');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,' ');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,'M');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,'A');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,'R');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,'K');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,'E');
	glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,'T');
}
//to draw a school
void drawschool()
{
   glColor3f(0.5,0.0,0.8);
	glBegin(GL_POLYGON);
	glVertex2f(house[0][0],house[1][0]);
    glVertex2f(house[0][1],house[1][1]);
	glVertex2f(house[0][4],house[1][4]);
	glVertex2f(house[0][5],house[1][5]);
	glEnd();
   glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
	glVertex2f(house[0][6],house[1][6]);
    glVertex2f(house[0][7],house[1][7]);
	glVertex2f(house[0][8],house[1][8]);
	glVertex2f(house[0][9],house[1][9]);
	glEnd();
   glColor3f(0.7,0.9,1.0);
	glBegin(GL_POLYGON);
	glVertex2f(house[0][1],house[1][1]);
    glVertex2f(house[0][2],house[1][2]);
	glVertex2f(house[0][3],house[1][3]);
	glVertex2f(house[0][4],house[1][4]);
	glEnd();
	glFlush();
}
//to draw a man
void man()
{
	glColor3ub(0,0,0);
	glPushMatrix();
	glTranslatef(370,208,0);
	glutSolidTorus(1,15,100,90);
	glPopMatrix();
//fill face
	glColor3ub(255,191,128);
	glPushMatrix();
	glTranslatef(370,208,0);
	glutSolidTorus(7,7,100,90);
	glPopMatrix();
//draw nose  eyebrow
	glColor3ub(0,0,0);
	glBegin(GL_LINES);
		glVertex2i(370,207);
		glVertex2i(370,200);
 		glVertex2i(361,213);
		glVertex2i(367,213);
 		glVertex2i(373,213);
		glVertex2i(379,213);
	glEnd();
 // eyes
	glBegin(GL_POLYGON);
		glVertex2i(363,211);
		glVertex2i(365,211);
		glVertex2i(365,209);
		glVertex2i(363,209);
	glEnd();

	glBegin(GL_POLYGON);
		glVertex2i(375,211);
		glVertex2i(377,211);
		glVertex2i(377,209);
		glVertex2i(375,209);
	glEnd();
 // mouth
	glBegin(GL_POLYGON);
		glVertex2i(366,197);
		glVertex2i(370,195);
		glVertex2i(374,197);
		glVertex2i(370,195);
	glEnd();
//shirt
	 glBegin(GL_POLYGON);
		glColor3ub(55,50,70);
		glVertex2i(359,190);
		glVertex2i(381,190);
		glVertex2i(396,179);
		glVertex2i(391,171);
		glVertex2i(386,175);
		glVertex2i(386,155);
		glVertex2i(354,155);
		glVertex2i(354,175);
		glVertex2i(349,170);
		glVertex2i(344,179);
	glEnd();
//hands
	glBegin(GL_POLYGON);
		glColor3ub(255,191,128);
		glVertex2i(395,178);
		glVertex2i(405,163);
		glVertex2i(397,164);
		glVertex2i(392,172);
	glEnd();
	glBegin(GL_POLYGON);
		 glVertex2i(405,163);
		glVertex2i(386,148);
		 glVertex2i(386,155);
		 glVertex2i(397,164);
	glEnd();
	glBegin(GL_LINES);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(386,155);
		glVertex2i(440,155);
	glEnd();
	glBegin(GL_POINTS);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(440,155);
	glEnd();
	glBegin(GL_LINES);
		glVertex2i(440,155);
		glVertex2i(440,100);
		glVertex2i(440,100);
		glVertex2i(433,100);
		glVertex2i(433,100);
		glVertex2i(433,8);
		glVertex2i(433,8);
		glVertex2i(440,8);
		glVertex2i(440,8);
		glVertex2i(440,4);
		glVertex2i(440,4);
		glVertex2i(437,4);
	glEnd();
//hands2
	glBegin(GL_POLYGON);
glColor3ub(255,191,128);
		glVertex2i(345,178);
		glVertex2i(335,163);
		glVertex2i(343,164);
		glVertex2i(348,172);
	glEnd();
	glBegin(GL_POLYGON);
		glVertex2i(335,163);
		glVertex2i(354,148);
		glVertex2i(354,155);
		glVertex2i(343,164);
	glEnd();
 // belt
	glBegin(GL_POLYGON);
		glColor3ub(100,120,130);
		glVertex2i(386,155);
		glVertex2i(354,155);
		glVertex2i(354,150);
		glVertex2i(386,150);
	glEnd();
// collar
	glBegin(GL_POLYGON);
		glColor3ub(200,140,110);
		glVertex2i(359,190);
		glVertex2i(381,190);
		glVertex2i(376,180);
		glVertex2i(364,180);
	glEnd();
	glBegin(GL_TRIANGLES);
		glColor3ub(20,140,110);
		glVertex2i(370,187);
		glVertex2i(375,180);
		glVertex2i(365,180);
	glEnd();
// pant
	glBegin(GL_POLYGON);
		glColor3ub(10,10,10);
		glVertex2i(385,150);
		glVertex2i(354,150);
		glVertex2i(350,115);
		glVertex2i(360,115);
		glVertex2i(363,148);
		glVertex2i(380,115);
		glVertex2i(390,115);
	glEnd();
}
void scaleman()
{
	glPushMatrix();
		glTranslated(550,550,0);
		glScaled(1.25,0.87,0.0);
		glTranslated(-550,-550,0);
		man();
	glPopMatrix();
}
//to draw water
void water()
{
		glPushMatrix();
		glTranslated(w,0.0,0.0);
		glColor3f(0.3,0.4,1.0);
		glBegin(GL_POLYGON);
		glVertex2f(0,0);
		glVertex2f(0,200);
		glVertex2f(100,196);
		glVertex2f(125,198);
		glVertex2f(139,194);
		glVertex2f(150,192);
		glVertex2f(170,198);
		glVertex2f(185,195);
		glVertex2f(195,196);
		glVertex2f(210,199);
		glVertex2f(228,197);
		glVertex2f(139,195);
		glVertex2f(245,197);
		glVertex2f(255,199);
		glVertex2f(272,195);
		glVertex2f(295,196);
		glVertex2f(312,195);
		glVertex2f(354,192);
		glVertex2f(384,196);
		glVertex2f(444,198);
		glVertex2f(460,193);
		glVertex2f(490,194);
		glVertex2f(510,199);
		glVertex2f(550,194);
		glVertex2f(585,200);
		glVertex2f(602,192);
		glVertex2f(652,192);
		glVertex2f(692,196);
		glVertex2f(730,205);
		glVertex2f(780,193);
		glVertex2f(820,197);
		glVertex2f(850,193);
		glVertex2f(900,195);
		glVertex2f(950,197);
		glVertex2f(980,208);
		glVertex2f(1000,196);
		glVertex2f(1020,193);
		glVertex2f(1050,199);
		glVertex2f(1080,192);
		glVertex2f(1100,199);
		glVertex2f(1100,0);
		glVertex2f(1700,110);
		glVertex2f(3100,380);
		glEnd();
		glPopMatrix();
}
//to draw a boat
void boat()
{
	glColor3f(0.2,0.2,0.2);




	glBegin(GL_POLYGON);
		glVertex2f(85,270.375);
		glVertex2f(125,270.375);
		glVertex2f(125,300);
		glVertex2f(85,300);
		glEnd();




		circle1(105,350,50);



glColor3f(0.0,0.0,0.0);

	glBegin(GL_POLYGON);
		glVertex2f(70,156.625);
		glVertex2f(70,270.375);
		glVertex2f(140,270.375);
		glVertex2f(140,156.625);
	glEnd();
	glBegin(GL_POLYGON);
        glVertex2f(140,226.625);
		glVertex2f(140,244.125);
		glVertex2f(175,244.125);
		glVertex2f(150,226.625);
	glEnd();
	glScaled(20,25,0);
	//boat
	glColor3f(0.6,0.2,0.6);
	glBegin(GL_POLYGON);
		glVertex2f(7,8.875);
		glColor3f(1.0,1.0,1.0);
		glVertex2f(7,1.75);
		glColor3f(0.6,0.2,0.6);
		glVertex2f(23.25,1.75);
		glColor3f(1.0,1.0,1.0);
		glVertex2f(27.625,8.875);
	glEnd();
}
//to draw reverse of the boat
void boat1()
{

	glColor3f(0.2,0.2,0.2);




	glBegin(GL_POLYGON);
		glVertex2f(680.5,270.375);
		glVertex2f(720.5,270.375);
		glVertex2f(720.5,300);
		glVertex2f(680.5,300);
		glEnd();




		circle2(700.5,350,50);

	glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON);
        glVertex2f(665,156.625);
		glVertex2f(665,270.375);
		glVertex2f(736,270.375);
		glVertex2f(736,156.625);
	glEnd();
	glBegin(GL_POLYGON);
        glVertex2f(630,226.625);
		glVertex2f(630,244.125);
		glVertex2f(682.5,244.125);
		glVertex2f(682.5,226.625);
	glEnd();
	glScaled(20,25,0);
	//boat
	glColor3f(0.6,0.2,0.6);
	glBegin(GL_POLYGON);
		glVertex2f(11.75,8.875);
		glColor3f(1.0,1.0,1.0);
		glVertex2f(16.75,1.75);
		glColor3f(0.6,0.2,0.6);
     	glVertex2f(33.25,1.75);
		glColor3f(1.0,1.0,1.0);
		glVertex2f(33.25,8.875);
	glEnd();
}
//timer function for the movement of water
void update(int value)
{
	w-=80;
	if(w<=-90)
		w=0;
		if(a==100||a==120||a==200||a==400||b==100||b==150||b==600||b==620||c==120||c==150||c==170)
			{

				glColor3f(1.0,1.0,1.0);
				glBegin(GL_POLYGON);
				glVertex2f(300.0,700.0);
				glVertex2f(220.0,700.0);
				glVertex2f(420.0,550.0);
				glVertex2f(600.0,500.0);
	        glEnd();
			glFlush();
		}
		glutPostRedisplay();
		glutTimerFunc(150,update,0);
}
//left bank

void house1()
{
    glColor3f(0.0,0.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2f(0,270);
    glVertex2f(0,350);
    glVertex2f(70,350);
    glVertex2f(70,270);
    glEnd();
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);
    glVertex2f(25,270);
    glVertex2f(25,315);
    glVertex2f(45,315);
    glVertex2f(45,270);
    glEnd();
    glColor3f(1.0,0.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(0,350);
    glVertex2f(35,390);
    glVertex2f(70,350);;
    glEnd();

}
void bank1()
{
		glColor3f(0.2,0.6,0.0);
  glBegin(GL_POLYGON);
		glVertex2f(0,270);
		glVertex2f(190,270);
		glVertex2f(310,100);
		glVertex2f(0,0);
	glEnd();
	house1();
	glFlush();
}
//right bank
void bank()
{
		glColor3f(0.6,0.3,0.2);
	glBegin(GL_POLYGON);
		glVertex2f(834,270);
		glVertex2f(1124,270);
		glVertex2f(1124,0);
		glVertex2f(714,0);
	glEnd();
	glFlush();
}
//purpel fishes
void fish1()
{
    glPushMatrix();
		glColor3f(0.3,0.0,0.7);
		glRotatef(fishangle,0,1,0);
	glBegin(GL_POLYGON);//body
		glVertex2i(100,100);
		glVertex2i(125,125);
		glVertex2i(150,100);
		glVertex2i(125,75);
		glVertex2i(100,100);
    glEnd();
		glColor3f(1.0,0.0,0.9);
	glBegin(GL_LINES);//body
		glVertex2i(147,105);
		glVertex2i(147,95);
	glEnd();
		glColor3f(1.0,0.0,0.9);
	glBegin(GL_LINES);//body
		glVertex2i(135,115);
		glVertex2i(135,85);
	glEnd();
		glColor3f(1.0,0.0,0.9);
	glBegin(GL_LINES);//body
		glVertex2i(127,125);
		glVertex2i(127,75);
	glEnd();
	glBegin(GL_POLYGON);//fins1
		glColor3f(1.0,0.0,0.9);
		glVertex2i(125,125);
		glVertex2i(120,160);
		glVertex2i(125,140);
		glVertex2i(130,160);
		glVertex2i(125,125);
	 glEnd();
	glBegin(GL_POLYGON);//fin2
		glColor3f(1.0,0.0,0.9);
		glVertex2i(125,75);
		glVertex2i(120,45);
		glVertex2i(125,60);
		glVertex2i(130,45);
		glVertex2i(125,75);
	glEnd();
    glBegin(GL_POLYGON);//tail
		glColor3f(1.0,0.0,0.9);
		glVertex2i(150,100);
		glVertex2i(175,125);
		glVertex2i(175,75);
		glVertex2i(150,100);
	glEnd();
		glColor3f(0.2,0.0,0.6);
	glBegin(GL_LINES);//body
		glVertex2i(165,95);
		glVertex2i(172.5,102.5);
	glEnd();
		glColor3f(0.3,0.0,0.7);
	glBegin(GL_LINES);//body
		glVertex2i(162.5,100);
		glVertex2i(172.5,110);
	glEnd();
	glBegin(GL_POINTS);
		glColor3f(0.0,0.0,0.0);
		glVertex2i(115,105);
	glEnd();
	glPopMatrix();


}
//golden fishes
void fish2()
{
	//glTranslated(w,0.0,0.0);
	//glPushMatrix();
	glPushMatrix();
	glColor3f(0.9,0.8,0.2);
	glRotatef(fishangle,0,1,0);
	glBegin(GL_POLYGON);//body
	glVertex2i(75,225);
	glVertex2i(100,250);
	glVertex2i(125,225);
	glVertex2i(100,200);
	 glEnd();
glColor3f(0.9,0.0,0.0);
	glBegin(GL_LINES);//body
	glVertex2i(80,230);
	glVertex2i(80,220);
	glEnd();
glColor3f(0.9,0.0,0.0);
	glBegin(GL_LINES);//body
	glVertex2i(90,240);
	glVertex2i(90,210);
	glEnd();
glColor3f(0.9,0.0,0.0);
	glBegin(GL_LINES);//body
	glVertex2i(100,250);
	glVertex2i(100,200);
	glEnd();
	glBegin(GL_POLYGON);//fins1
	glColor3f(0.9,0.0,0.0);
	glVertex2i(100,200);
	glVertex2i(80,175);
	glVertex2i(90,210);
	 glEnd();
glBegin(GL_POLYGON);//tail
	glColor3f(0.9,0.0,0.0);
	glVertex2i(75,225);
	glVertex2i(50,250);
	glVertex2i(50,200);
	glVertex2i(75,225);
	glEnd();
    glBegin(GL_POLYGON);//fin2
	glColor3f(0.9,0.0,0.0);
    glVertex2i(100,250);
	glVertex2i(80,175);
	glVertex2i(90,240);
	glEnd();
glBegin(GL_POINTS);
	glColor3f(0.0,0.0,0.0);
	glVertex2i(110,230);
	glEnd();
	glPopMatrix();
	//glFlush();
//glPopMatrix();
}
//golden fishes without movement
void fish21()
{
	glColor3f(0.9,0.8,0.2);
	glBegin(GL_POLYGON);//body
	glVertex2i(75,225);
	glVertex2i(100,250);
	glVertex2i(125,225);
	glVertex2i(100,200);
	 glEnd();
glColor3f(0.9,0.0,0.0);
	glBegin(GL_LINES);//body
	glVertex2i(80,230);
	glVertex2i(80,220);
	glEnd();
glColor3f(0.9,0.0,0.0);
	glBegin(GL_LINES);//body
	glVertex2i(90,240);
	glVertex2i(90,210);
	glEnd();
glColor3f(0.9,0.0,0.0);
	glBegin(GL_LINES);//body
	glVertex2i(100,250);
	glVertex2i(100,200);
	glEnd();
	glBegin(GL_POLYGON);//fins1
	glColor3f(0.9,0.0,0.0);
	glVertex2i(100,200);
	glVertex2i(80,175);
	glVertex2i(90,210);
	 glEnd();
glBegin(GL_POLYGON);//tail
	glColor3f(0.9,0.0,0.0);
	glVertex2i(75,225);
	glVertex2i(50,250);
	glVertex2i(50,200);
	glVertex2i(75,225);
	glEnd();
    glBegin(GL_POLYGON);//fin2
	glColor3f(0.9,0.0,0.0);
    glVertex2i(100,250);
	glVertex2i(80,175);
	glVertex2i(90,240);
	glEnd();
glBegin(GL_POINTS);
	glColor3f(0.0,0.0,0.0);
	glVertex2i(110,230);
	glEnd();
}
// many purple fishes
void scalefish11()
{
	glPushMatrix();
glScaled(0.7,0.7,0.0);
	glTranslated(160,35,0);
	fish1();
		glTranslated(150,55,0);
	fish1();
	glPopMatrix();
}
//many golden yellow fishes
int floc=200;
void scalefish12()
{
    glPushMatrix();
glScaled(0.7,0.7,0.0);
if(floc<200)floc+=10;
if(floc>600)floc-=10;
	glTranslated(floc,30,0);
	fish2();
		glTranslated(floc,-20,0);
	fish2();
		glTranslated(floc,-100,0);
	fish2();
		glTranslated(floc,-180,0);
	fish2();
     	glTranslated(-800,300,0);
	fish2();
	glTranslated(300,-20,0);
	fish2();
	glTranslated(350,-20,0);
	fish21();
	glTranslated(500,-20,0);
	fish21();
	glPopMatrix();
}
//fishes on the bank with man in display4
void scalefish111()
{
    glPushMatrix();
glScaled(0.7,0.7,0.0);
	glTranslated(276,-50,0);
	fish1();
		glTranslated(195,35,0);
	fish1();
	glTranslated(110,25,0);
	fish21();
	glTranslated(-110,-0,0);
	fish21();
	glPopMatrix();
}

void circle1(float x,float y,float r)
{

	float angle;
	glColor3f(0,0,0);
	glPointSize(2);
	for(angle=0;angle<=360;angle+=0.01)
	{
		glBegin(GL_POINTS);
		glVertex2f(r*cos(angle)+x,r*sin(angle)+y);
		glEnd();
	}


	glBegin(GL_LINES);
	glVertex2f(105,350);
	glVertex2f(105,300);
	glVertex2f(105,350);
	glVertex2f(105,400);
	glVertex2f(105,350);
	glVertex2f(55,350);
	glVertex2f(105,350);
	glVertex2f(155,350);

	glVertex2f(105,350);
	glVertex2f(140.355,385.355);
	glVertex2f(105,350);
	glVertex2f(69.640,385.355);
	glVertex2f(105,350);
	glVertex2f(69.644,314.644);
	glVertex2f(105,350);
	glVertex2f(140.355,314.644);

	glEnd();




}













void circle2(float x,float y,float r)
{
	float angle;
	glColor3f(0,0,0);
	glPointSize(2);
	for(angle=0;angle<=360;angle+=0.01)
	{
		glBegin(GL_POINTS);
		glVertex2f(r*cos(angle)+x,r*sin(angle)+y);
		glEnd();
	}
	glBegin(GL_LINES);
	glVertex2f(700.5,350);
	glVertex2f(700.5,300);
	glVertex2f(700.5,350);
	glVertex2f(700.5,400);
	glVertex2f(700.5,350);
	glVertex2f(650.5,350);
	glVertex2f(700.5,350);
	glVertex2f(750.5,350);

	glVertex2f(700.5,350);
	glVertex2f(735.855,385.355);
glVertex2f(700.5,350);
	glVertex2f(665.144,385.355);
glVertex2f(700.5,350);
	glVertex2f(665.144,314.644);
glVertex2f(700.5,350);
	glVertex2f(735.855,314.644);

	glEnd();



}



//main display
void display()
{
	glClearColor(1.0,1.0,1.0,0.0);
	glClear(GL_COLOR_BUFFER_BIT);


	if(flag==1)
	{

    drawm();

	}
	else
	{
		if(a)
		display1();
		if(k)
			display11();
		if(b)
			display2();
		if(c)
			display3();
		if(d && flag1==1)
			drawr();
	}
	glutSwapBuffers();
	glFlush();
}



//to draw boat in reverse and its movement
void drawr()
{
	glClear(GL_COLOR_BUFFER_BIT);
	sun();
	glPushMatrix();
	glTranslated(d,60,0.0);
	scaleman();
	boat1();
	glPopMatrix();
	water();
    glPushMatrix();
    glTranslated(704,70,0.0);
	drawschool();
	board();
	glPopMatrix();
 	bank();
}
//to draw initial and corresponding displays
void drawm()
{
    glClear(GL_COLOR_BUFFER_BIT);

    	a+=20.0;//	Movement of ship(speed)
        display1();
	if(a>950)
	{
		k+=15;
		display11();
	}
	if(k>970)
	{
		b+=15;
		display2();
	}
	if(b>960)
	{
		if(c<=290)c+=15;
		display3();
	}
	if(c>=290)
		display4();
	if(flag1==1 && c>290)
	{
		d-=8;
		drawr();
	}
}
//throw net
void net()
{
	glTranslated(w,0.0,0.0);
	glPushMatrix();
glColor3f(0.0,0.0,0.0);
for(i=0;i<maxX;i++)
s[i]=s0+i*dx;
for(j=0;j<maxY;j++)
h[j]=h0+j*dy;
glColor3f(0.0,0.0,0.0);
for(i=0;i<maxX-1;i++)
for(j=0;j<maxY-1;j++)
{
glColor3f(0.0,0.0,0.0);
glBegin(GL_LINE_LOOP);
glVertex2f(s[i],h[j]);
glVertex2f(s[i],h[j+1]);
glVertex2f(s[i+1],h[j+1]);
glVertex2f(s[i+1],h[j]);
glEnd();
glFlush();
}
glFlush();
glPopMatrix();
}
//net on water
void snet()
{
glPushMatrix();
glScaled(0.7,0.7,0.0);
	glTranslated(230,15,0);
	net();
	glPopMatrix();
}
//inital display with movement of the boat
void display1()
{
    glClear(GL_COLOR_BUFFER_BIT);
	sun();
	glPushMatrix();
	glTranslated(a,60,0.0);

	scaleman();
	boat();

	glPopMatrix();


	water();
	bank1();
}
//to display part of the river without fishes
void display11()
{
    glClear(GL_COLOR_BUFFER_BIT);
    sun();
	glPushMatrix();
	glTranslated(k,60,0.0);
	scaleman();
	boat();
	glPopMatrix();
	water();
}
//display2 only movement of the boat
void display2()
{
    glClear(GL_COLOR_BUFFER_BIT);
    sun();
	glPushMatrix();
	glTranslated(b,60,0.0);
	scaleman();
	boat();
	glPopMatrix();
	water();
	if(flag2==1)
		snet();
	fish1();
	scalefish11();
	scalefish12();
}
//display3 man with fish near the right bank
void display3()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glutIdleFunc(clockWise);
	sun();
	glPushMatrix();;
	glTranslated(c,60,0.0);
	scaleman();
	boat();
	glPopMatrix();
	water();
    glPushMatrix();
    glTranslated(704,70,0.0);
	drawschool();
	board();
    glPopMatrix();
	snet();
	fish1();
	scalefish11();
	scalefish12();
 	bank();
}
//display4 with man and his fish on the bank
void display4()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glutIdleFunc(NULL);
    if(c>=290)
	{
		sun();
	glPushMatrix();
	glTranslated(290,60,0.0);
	boat();
	glPopMatrix();
	water();
    bank();
    glPushMatrix();
    glTranslated(704,70,0.0);
    drawschool();
	board();
	glPopMatrix();
    glPushMatrix();
    glTranslated(500,18,0.0);
	scaleman();
	glRotatef(0,0,0,0);
	scalefish111();
    glPopMatrix();
	}
}
void myinit()
{
	glClearColor(1.0,1.0,1.0,0.0);
	glPointSize(0.9);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,999.0,0.0,799.0);
}
//main
int main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE| GLUT_RGB);
	glutInitWindowSize(1500.0,1500.0);
	glutInitWindowPosition(0,0);
	printf("\t\tFISHING-OCCUPATION\t\n");
	printf("Project By Raghuveer K J , Sudeep J S , Renukaprasad K R , Shabaz Pasha\n");
	printf("Under the Guidence of :\n");
	printf("Dr. Nagaraj M. Lutimath, Associate Professor, Dept. of CSE\n");
	printf("Enter 't' to start the boat\n");
	printf("Enter 's' to stop the boat\n");
	printf("Enter 'f' to increase the speed of the boat\n");
	printf("Enter 'r' to reverse the boat\n");
	printf("Enter 'n' to throw net\n");
	printf("Enter 'q' or click left mouse button to quit\n");
	printf("Enter 'c/C' to move Fish \n");
	glutCreateWindow("FISHING OCCUPATION");
    glutDisplayFunc(display);

    glutIdleFunc(scalefish11);
	glutKeyboardFunc(mykeys);
	glutMouseFunc(mouse);
	myinit();
	glutTimerFunc(100,update,0);
	glutMainLoop();
}
