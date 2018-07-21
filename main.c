#include<GL/glut.h>
#include<stdlib.h>

GLfloat vertices[][3]={{-40,-40.0,40.0},{-40.0,40.0,40.0},{40.0,40.0,40.0},{40.0,-40.0,40.0},{-40.0,-40.0,-40.0},{-40.0,40.0,-40.0},{40.0,40.0,-40.0},{40.0,-40.0,-40.0},{0.0,80,0.0}};
GLfloat normal[][3]={{-40,-40.0,40.0},{-40.0,40.0,40.0},{40.0,40.0,40.0},{40.0,-40.0,40.0},{-40.0,-40.0,-40.0},{-40.0,40.0,-40.0},{40.0,40.0,-40.0},{40.0,-40.0,-40.0}};

GLfloat colors[][3]={{1,1,0.8},{0.2,0.2,0.8},{0.8,0,0},{1,0.8,0},{1,1,1},{0,0.4,0},{1,0.2,0},{0,0,0},{0.2,0.2,0.2}};

GLfloat line[][3]={{-13.33,-40.05,40.05},//0
					{-13.33,40.05,40.05},//1
					{13.33,40.05,40.05},//2
					{13.33,-40.05,40.05},//3
					{-40.05,-13.33,40.05},//4
					{40.05,-13.33,40.05},//5
					{-40.05,13.33,40.05},//6
					{40.05,13.33,40.05},//7
					{-40.05,13.33,-40.05},//8
					{-40.05,-13.33,-40.05},//9
					{-40.05,40.05,13.33},//10
					{-40.05,40.05,-13.33},//11
					{-40.05,-40.05,13.33},//12
					{-40.05,-40.05,-13.33},//13
					{-13.33,40.05,-40.05},//14
					{13.33,40.05,-40.05},//15
					{-13.33,-40.05,-40.05},//16
					{13.33,-40.05,-40.05},//17
					{40.05,13.33,-40.05},//18
					{40.05,-13.33,-40.05},//19
					{40.05,40.05,-13.33},//20
					{40.05,40.05,13.33},//21
					{40.05,-40.05,13.33,},//22
					{40.05,-40.05,-13.33,}};//23
GLfloat fogColor[][4] = {{0.5,0.5,0.5,0},{0.6901960784313725, 0.7686274509803922, 0.8705882352941176, 0.0},{1, 0.7529411764705882, 0.796078431372549, 0.0},{0.1333333333333333, 0.5019607843137255, 0.1333333333333333, 0.0},{0.5450980392156863, 0.2705882352941176, 0.0745098039215686,0},{0.5,0.5,0.5,0.0},{1,0.8, 0.2, 0.0},{0,0,0,0}};
GLfloat density = 0.03;
GLUquadricObj *sphere,*cone,*base;
enum {Sphere = 1,Cone,House,Table,Chair,Cube,Teapot,Lamp,Fan,WIRE,FILL,BACKFACE,FRONTLINES};
int back=0,menuIdback=0,menuIdMain=0,menuIdRot=0,menuIdObj=0,menIdtran=0,menuIdraster=0,rastermode = FILL,x=0,y=0,j,k;
static GLfloat cone_mat[] = {0.f, .5f, .5f, 1.f};
static GLfloat lamp_mat[] = {1.f, .5f, 1.f, 1.f};
static GLfloat teapot_mat[]={0.4,0.2,0.2,1};
static GLfloat wood_mat[]={0.4,0.2,0,1};
static GLfloat cube_mat[]={0.74902,0.847059,0.847059};
static GLfloat torus_mat[]={0.6,0.6,0};
static GLfloat theta[]={0.0,0.0,0.0};
static GLint axis=0;
static int object = House, trans=0,val=0,a=1,b=0,r=1,l=1,foga=0,face,view=0;
void objMenu(int);
void rotMenu(int);
void rotate(void);
void ChangeObj(int);
void fog(int,int);
void light(int);
void lamp(void);
void cone_func( int);
void ball(int,int,int);
double spin = 0.0;                           
double center = 0.0; 
double rotation_angle = 0.0; 
double translation_distance = 0.0; 
char text1[]={"3D Objects Transformation,Lighting,"};
char text2[]={"***Press Enter to Start***"};
char texta[]={"Computer Graphics and Visualization"};
char textb[]={"Bangalore Institute of Technology"};
char textc[]={"Department of Computer Science & Engineering"};
char textd[]={"(USN:1BI15CS193)"};
char textg[]={"Graphics Package"};
char texth[]={"Fog,Viewing and Rasterization"};
char texti[]={"-Submitted by-"};
char textj[]={"Ankit Akash"};

void polygon (int a,int b,int c,int d,int e)
{
	glBegin(GL_POLYGON);
	glColor3fv(colors[e]);
	glNormal3fv(vertices[a]);
	glVertex3fv(vertices[a]);
	glVertex3fv(vertices[b]);
	glNormal3fv(normal[b]);
	glVertex3fv(vertices[c]);
	glNormal3fv(normal[c]);
	glVertex3fv(vertices[d]);
	glNormal3fv(normal[d]);
	glEnd();
}
void linecube (int a,int b)
{
	glBegin(GL_LINES);
	glColor3f(0,0,0);
	glVertex3fv(line[a]);
	glVertex3fv(line[b]);
	glEnd();
}
void window(void)
{

	base = gluNewQuadric();
	glPushMatrix();
	glColor3f(.8,.8,.8);
	glRotated(45,0,0,1);
	gluDisk(base, 0, 14, 4, 1);
	glPopMatrix();
	glPushMatrix();
	glColor3fv(wood_mat);
	glTranslated(0,0,.5);
	glScaled(10,1,1);
	glutSolidCube(2);
	glTranslated(0,10,0);
	glutSolidCube(2);
	glTranslated(0,-20,0);
	glutSolidCube(2);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0,0,.5);
	glScaled(1,10,1);
	glutSolidCube(2);
	glTranslated(-9,0,0);
	glutSolidCube(2);
	glTranslated(18,0,0);
	glutSolidCube(2);
	glPopMatrix();
	glEnable(GL_COLOR_MATERIAL);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 0.6*128.0);
}
void house(void)
{
	glLineWidth(1);
	glPushMatrix();
	glColor3fv(colors[0]);
	glutSolidCube(80);
    glEnable(GL_COLOR_MATERIAL);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 0.6*128.0);
	glColor3fv(colors[8]);
	glTranslated(0,37,0);
	glRotated(-90,1,0,0);
	glRotated(45,0,0,1);
	glScaled(2.1,2.1,.6);
	cone_func(4);
	glPopMatrix();
	glPushMatrix();
	glTranslated(26,56,0);
	glScaled(3,5,3);
	glutSolidCube(5);
	glTranslated(0,2.5,0);
	glRotated(-90,1,0,0);
	glRotated(45,0,0,1);
	glScaled(.13,.13,.03);
	cone_func(4);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-25,10,41);
	window();
	glTranslated(50,0,0);
	window();
	glTranslated(-25,-25,0);
	glScaled(2.5,3.2,.2);
	glutSolidCube(10);
	glColor3fv(colors[8]);
	glTranslated(0,-6,20);
	glScaled(1.5,.37,5);
	glutSolidCube(10);
	glTranslated(0,-2,5);
	glScaled(1,.6,2);
	glutSolidCube(10);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-10,-15,42);
	glScaled(0.05,0.05,.05);
	ball(30,30,30);
	glPopMatrix();
}
void rubix_outline(void)
{	
	linecube(0,1);
	linecube(2,3);
	linecube(4,5);
	linecube(6,7);
	linecube(6,8);
	linecube(4,9);
	linecube(10,12);
	linecube(11,13);
	linecube(1,14);
	linecube(2,15);
	linecube(7,18);
	linecube(5,19);
	linecube(8,18);
	linecube(9,19);
	linecube(14,16);
	linecube(15,17);
	linecube(0,16);
	linecube(3,17);
	linecube(10,21);
	linecube(11,20);
	linecube(20,23);
	linecube(21,22);
	linecube(13,23);
	linecube(12,22);
}
void rubix(void)
{	
	glShadeModel (GL_SMOOTH);
	glLineWidth(2);
	polygon(0,3,2,1,1);
	polygon(2,3,7,6,2);
	polygon(0,4,7,3,3);
	polygon(1,2,6,5,4);
	polygon(4,5,6,7,5);
	polygon(0,1,5,4,6);
	rubix_outline();
	glEnable(GL_COLOR_MATERIAL);
	glColorMaterial(GL_FRONT_AND_BACK, GL_AMBIENT_AND_DIFFUSE);
}
void teapot(void)
{	
	glPushMatrix();
	glLineWidth(1);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 0.8*128.0);
	glColor3fv(teapot_mat);
	glutSolidTeapot(30);
	glColor3f(.6,.6,.4);
	glTranslated(0,-25.5,0);
	glScaled(1.5,.1,1.5);
	ball(30,30,30);
	glTranslated(0,10,0);
	glRotated(90,1,0,0);
	glutSolidTorus(5, 30, 10, 40);
	glPopMatrix();
}
void Leg(double thick,double len)
{
	glPushMatrix();
	glColor3f(0.5450980392156863, 0.2705882352941176, 0.0745098039215686);
	glTranslated(0,len/2,0);
	glScaled(thick,len,thick);
	glutSolidCube(1.0);
	glPopMatrix();
}
void bar(double thick,double len)
{
	glPushMatrix();
	glColor3f(0.5450980392156863, 0.2705882352941176, 0.0745098039215686);
	glTranslated(0,len/2,0);
	glScaled(len,thick,thick);
	glutSolidCube(1.0);
	glPopMatrix();
}
void table(double topWid,double topThick,double legThick,double legLen)
{
	glLineWidth(1);
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, wood_mat);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 0.6*128.0);
	glPushMatrix();	
	glTranslated(0,legLen,0);
	glScaled(topWid,topThick,topWid);
	glutSolidCube(1.0);
	
	glPopMatrix();

	double dist=0.95 * topWid/2.0 - legThick/2.0;
	glPushMatrix();

	glTranslated(dist,0,dist);
	Leg(legThick,legLen);

	glTranslated(0.0,0.0,-2 * dist);
	Leg(legThick,legLen);

	glTranslated(-2*dist,0,2* dist);
	Leg(legThick,legLen);

	glTranslated(0,0,-2*dist);
	Leg(legThick,legLen);

	glPopMatrix();

}
void ball(int radius,int slice,int stack)
{	
	sphere = gluNewQuadric();
  	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 0.6*128.0);
	gluSphere(sphere, radius, slice, stack);
    gluDeleteQuadric(sphere);

}
void cone_func(int slice)
{
	cone = gluNewQuadric();
    base = gluNewQuadric();
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 0.6*128.0);
    gluDisk(base, 0., 30, slice, 1);
    gluCylinder(cone, 30, 0, 80, slice,30);
    gluDeleteQuadric(cone);
    gluDeleteQuadric(base);
}
void icecream(void)
{
	glLineWidth(1);
	glPushMatrix();
	glColor3f(0.8,0.4,0);
	glRotated(90,1,0,0);
	cone_func(30);
	glPopMatrix();
	glPushMatrix();
	glColor3f(1,1,1);
	glTranslated(0,8,0);
	ball(30,30,30);
	glColor3f(1,1,1);
	glScaled(0.9,0.9,0.9);
	glTranslated(0,25,0);
	ball(30,30,30);
	glColor3f(0.8,0,0);
	glScaled(0.3,0.3,0.3);
	glTranslated(0,90,0);
	ball(30,30,30);
	glColor3fv(wood_mat);
	glScaled(0.2,0.2,0.2);
	glTranslated(50,130,50);
	ball(30,30,30);
	glPopMatrix();
}
void torus(int sr,int br)
{
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 0.6*128.0);
	glutSolidTorus(sr, br, 20, 10);	  
}
void lamp(void)
{
	glLineWidth(1);
	cone = gluNewQuadric();
    base = gluNewQuadric();
    glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 0.6*128.0);
	glPushMatrix();
	glColor3fv(lamp_mat);
	glTranslated(0,0,-50);
	glPushMatrix();
	glRotated(180,0,1,0);
	gluDisk(base, 0, 15, 8, 1);
	glPopMatrix();
    gluCylinder(cone, 15, 30, 40, 8,30);
	glTranslated(0,0,40);
	gluDisk(base, 25, 30, 8, 1);
    glPopMatrix();
	glPushMatrix();
	glTranslated(0,0,-25);
	glScaled(0.2,0.2,0.25);
	glColor3fv(colors[0]);
	ball(30,5,10);
	glTranslated(0,0,25);
	glScaled(1,1,1);
	glColor3f(0,0,0);
	torus(15,20);
	glPopMatrix();
	glPushMatrix();
	glColor3fv(colors[8]);
	glTranslated(0,0,-20);
	gluCylinder(cone, 3, 3, 80, 3,30);
	glTranslated(0,0,75);
	glutSolidTorus(6, 6, 4, 20);
	glColor3f(0.4,0.4,0.4);
	glTranslated(15,0,-2);
	ball(5,3,10);
	glColor3fv(colors[8]);
	glTranslated(-15,0,3);
	glScaled(0.9,0.9,0.1);
	ball(30,30,30);
	glPopMatrix();
	gluDeleteQuadric(cone);
    gluDeleteQuadric(base);
}
void chair(double topWid,double topThick,double legThick,double legLen)
{
	glLineWidth(1);
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, wood_mat);
	glMaterialf(GL_FRONT_AND_BACK, GL_SHININESS, 0.6*128.0);
	glPushMatrix();
	glTranslated(0,legLen,0);
	glScaled(topWid,topThick,topWid);
	glutSolidCube(1.0);
	glPopMatrix();
	double dist=0.95 * topWid/2.0 - legThick/2.0;
	glPushMatrix();
	glColor3fv(wood_mat);
	glTranslated(dist,0,dist);
	Leg(legThick,legLen);
	glTranslated(0.0,0.0,-2 *dist);
	Leg(legThick,legLen);
	glTranslated(-2*dist,0,2* dist);
	Leg(legThick,legLen);
	glTranslated(0,0,-2*dist);
	Leg(legThick,legLen);
	glTranslated(0.0,8+dist,0.0);
	Leg(legThick,legLen*1.5);	
	glTranslated(2*dist,0.0,0.0);
	Leg(legThick,legLen*1.5);
	glTranslated(4-dist,0.0,0.0);
	Leg(legThick/2,legLen*1.5);	
	glTranslated(8-dist,0.0,0.0);
	Leg(legThick/2,legLen*1.5);
	glPopMatrix();
	glPushMatrix();
	glTranslated(0,2.5*dist,-dist);
	bar(legThick,topWid);
	glPopMatrix();
	//left arm
	glPushMatrix();
	glTranslated(-dist,1.5*dist,dist);
	Leg(legThick,legLen/1.5);
	glPopMatrix();
	glPushMatrix();
	glTranslated(-dist,2.5*dist,0.15*dist);
	glScaled(legThick,legThick,topWid);
	glutSolidCube(1.0);
	glPopMatrix();
	//right arm			
	glPushMatrix();
	glTranslated(dist,2.5*dist,0.15*dist);
	glScaled(legThick,legThick,topWid);
	glutSolidCube(1.0);
	glPopMatrix();
	glPushMatrix();
	glTranslated(dist,1.5*dist,dist);
	Leg(legThick,legLen/1.5);
	glPopMatrix();
}

void myReshape(int w,int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(view==0)
	{
		if(w<=h)
			glOrtho(-100.0,100.0,-100.0*(GLfloat)h/(GLfloat)w,100.0*(GLfloat)h/(GLfloat)w,-500.0,500.0);
		else
			glOrtho(-100.0*(GLfloat)w/(GLfloat)h,100.0*(GLfloat)w/(GLfloat)h,-100.0,100.0,-500.0,500.0);
		gluLookAt(50,50,100,0.0,0,0.0,0.0,100.0,0.0);
	}
	else
	if(view==1)
	{
		if(w<=h)
			glFrustum(-35.0,35.0,-35.0*(GLfloat)h/(GLfloat)w,35.0*(GLfloat)h/(GLfloat)w,10.0,500.0);
		else
			glFrustum(-35.0*(GLfloat)w/(GLfloat)h,35.0*(GLfloat)w/(GLfloat)h,-35.0,25.0,10.0,500.0);
	//	gluPerspective(90,1.3, 20.0, 500.0);
		gluLookAt(10,15,100,0.0,0,0.0,0.0,100.0,0.0);
	}
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void display(void)
{ 	
	if(k==0)
	{
		float position[] = {-5.0, 5.0, 3.0, 0.0};
	    float local_view[] = {0.0};
		float specular[] = {0.727811, 0.626959, 0.626959};
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LESS);
		glLightfv(GL_LIGHT0, GL_POSITION, position);
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);
		glEnable(GL_AUTO_NORMAL);
		glEnable(GL_NORMALIZE);
		glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular);
		glClearColor(0,0.2,0.2,1); 
		glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		glColor3f(1,1,1);
		glRasterPos3f(-45,70,0);
		for(j=0;texta[j]!='\0';j++)
			glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, texta[j]); 
    	glRasterPos3f(-50,30,0);
		for(j=0;text1[j]!='\0';j++)
			glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, text1[j]);
		glRasterPos3f(-40,25,0);
		for(j=0;texth[j]!='\0';j++)
			glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, texth[j]); 
       	glColor3f(0.4,0.8,0.8);		    
		glRasterPos3f(-23,-70,0);
		for(j=0;text2[j]!='\0';j++)
			glutBitmapCharacter( GLUT_BITMAP_HELVETICA_18, text2[j]); 
        glColor3f(1,1,1);
		glRasterPos3f(-45,0,0);
		for(j=0;textb[j]!='\0';j++)
			glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, textb[j]); 
        glRasterPos3f(-55,-10,0);
		for(j=0;textc[j]!='\0';j++)
			glutBitmapCharacter( GLUT_BITMAP_HELVETICA_18, textc[j]); 
		glRasterPos3f(-15,50,0);
		for(j=0;textg[j]!='\0';j++)
			glutBitmapCharacter( GLUT_BITMAP_HELVETICA_18, textg[j]); 
		glRasterPos3f(-23,-47,0);
		for(j=0;textd[j]!='\0';j++)
			glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, textd[j]); 
		glRasterPos3f(-16,-30,0);
		for(j=0;texti[j]!='\0';j++)
			glutBitmapCharacter( GLUT_BITMAP_HELVETICA_18, texti[j]); 
		glRasterPos3f(-18,-38,0);
		for(j=0;textj[j]!='\0';j++)
			glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, textj[j]); 
		glFlush();
    }
	else
	{
		glClearColor(0.5,0.5,0.5,0);
		switch(back)
		{
		case 1:
			glClearColor (0.6901960784313725, 0.7686274509803922, 0.8705882352941176, 0.0);//Light Blue
			break;				
		case 2:
			glClearColor (1, 0.7529411764705882, 0.796078431372549, 0.0);//Pink
            break;
		case 3:
			glClearColor (0.1333333333333333, 0.5019607843137255, 0.1333333333333333, 0.0);//Green
            break;			
		case 4:
			glClearColor (0.5450980392156863, 0.2705882352941176, 0.0745098039215686,0);//Brown
            break;
		case 5:
			glClearColor (0.5,0.5,0.5,0.0);//Gray
            break;
		case 6:
			glClearColor (1,0.8, 0.2, 0.0);//Yellow
            break;			
		case 7:
			glClearColor (0.0,0.0, 0.0, 0.0);//Black
            break;
		}  
		switch(trans)
		{
		case 0: glutIdleFunc(NULL);
			break;
		case 1:	glTranslated(0.05,0,0);
			break;
		case 2: glTranslated(-0.05,0,0);
			break;
		case 3: glTranslated(0,0.05,0);
			break;
		case 4: glTranslated(0,-0.05,0);
			break;
		case 5: glTranslated(0,0,0.05);
			break;
			case 6: glTranslated(0,0,-0.05);
			break;
		}
		glutPostRedisplay();
		glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		//glutSwapBuffers();
		glRotatef(theta[0],1.0,0.0,0.0);
		glRotatef(theta[1],0.0,1.0,0.0);
		glRotatef(theta[2],0.0,0.0,1.0);
		
	  	switch(rastermode)
		{
		case FILL:glCallList(object);
			break;
		case WIRE: /* basic wireframe mode */
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
		glCallList(object);
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			break;
		case BACKFACE: /* use backface culling to clean things up */
			glEnable(GL_CULL_FACE);
			glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			glCallList(object);
			glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			glDisable(GL_CULL_FACE);
			break;
		case FRONTLINES: /* use polygon mode line on front, fill on back */
			if(object==Teapot)
			{
				glPolygonMode(GL_BACK, GL_LINE);
				glCallList(object);
				glPolygonMode(GL_BACK, GL_FILL);
			 }
			else
			{
				glPolygonMode(GL_FRONT, GL_LINE);
				glCallList(object);
				glPolygonMode(GL_FRONT, GL_FILL);
			}
			break;
		}		

		glFlush();
	}
}
/*Menu Functions*/
void mainMenu(int value)
{	
  switch(value)
  {
  case 1:
	  if(foga==0)
	  {
		fog(++foga,back);
		glutChangeToMenuEntry(6, "Fog Off [f]", 1);
	  }
	  else
		  if(foga==1)
		  {
			  fog(++foga,back);
			  glutChangeToMenuEntry(6, "Fog On [f]", 1);
		  }
		  break;
  case 2:
	  if(l==0)
	  {
		light(++l);
		glutChangeToMenuEntry(7, "Lighting Off [l]", 2);
	  }
	  else
		  if(l==1)
		  {
			 light(++l);
			 glutChangeToMenuEntry(7, "Lighting On [l]", 2);
		  }
		  break;
  case 3:glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	  view = abs(view-1);
	  break;
  case 4: exit(0);
	  break;
  }
}
void transMenu(int value)
{
	static int is_translation = 0;
	switch(value)
	{
	case 1:
		if(is_translation)
		{
			rotMenu(32);
			trans=1;			
	        is_translation = 0;
			glutChangeToMenuEntry(1, "X - axis Translation -", 1);
			glutChangeToMenuEntry(2, "Y - axis Translation On", 2);
			glutChangeToMenuEntry(3, "Z - axis Translation On", 3);
		}
		else
		{
			rotMenu(32);
			trans=2;		
			is_translation = 1;
			glutChangeToMenuEntry(1, "X - axis Translation +", 1);
			glutChangeToMenuEntry(2, "Y - axis Translation On", 2);
			glutChangeToMenuEntry(3, "Z - axis Translation On", 3);
		}
		break;
	case 2:
		if(is_translation)
		{
			rotMenu(32);
			trans=3;
			is_translation = 0;
			glutChangeToMenuEntry(2, "Y - axis Translation -", 2);
		    glutChangeToMenuEntry(1, "X - axis Translation On", 1);
			glutChangeToMenuEntry(3, "Z - axis Translation On", 3);
		}
		else
		{
			rotMenu(32);
			trans=4;
			is_translation = 1;
		    glutChangeToMenuEntry(2, "Y - axis Translation +", 2);
			glutChangeToMenuEntry(1, "X - axis Translation On", 1);
			glutChangeToMenuEntry(3, "Z - axis Translation On", 3);
		}
		break;
	case 3:
		if(is_translation)
		{
			rotMenu(32);
			trans=5;			
			is_translation = 0;
			glutChangeToMenuEntry(3, "Z - axis Translation -", 3);
			glutChangeToMenuEntry(1, "X - axis Translation On", 1);
		    glutChangeToMenuEntry(2, "Y - axis Translation On", 2);
		}
		else
		{
			rotMenu(32);
			trans=6;			
			is_translation = 1;
		    glutChangeToMenuEntry(3, "Z - axis Translation +", 3);
			glutChangeToMenuEntry(1, "X - axis Translation On", 1);
			glutChangeToMenuEntry(2, "Y - axis Translation On", 2);
		}
		break;
	case 4:trans=0;
		break;
	}
}
void rotMenu(int val)
{ 
	switch (val) 
    { 
    case 1:
	case 'X':
    case 'x':axis=0;		
		rotate();
		glutPostRedisplay();
		break;
    case 2:
	case 'Y':
    case 'y': axis=1;
		rotate();
		glutPostRedisplay();
		break;
	case 3:
	case 'z':
	case 'Z':axis=2;
		rotate();
		glutPostRedisplay();
		break;
	case 32:theta[0]=0;	
		theta[1]=0;		
		theta[2]=0;
		glutPostRedisplay();
		trans=0;
		break;
	case 'o':
	case 'O':
	case 4:trans=0;	
		theta[0]=0;	
		theta[1]=0;		
		theta[2]=0;			
		theta[axis]-=0.1;
		glutPostRedisplay();
		break;
	}
}
void objMenu(int obj)
{
  switch(obj)
  {

  case 1:object=House;
	 a=obj;
	 break;
  case 2: object=Lamp;
	 a=obj;
	 break;
  case 3:object =Table;
	 a=obj;
	 break;
  case 4:object=Chair;
	 a=obj;
	 break;
  case 5:object=Teapot;
     a=obj;
	 break;
  case 6:
	 object=Sphere;
	 a=obj;
	 break;
  case 7:
	 object=Cube;
	 a=0;
	 break;
  }
}
void backMenu(int value)
{
  switch(value)
  {
  case 1: back = 1;
	b=value;
	fog(foga,back);
    break;
  case 2: back=2;
	b=value;
	fog(foga,back);
    break;
  case 3: back=3;
	b=value;
	fog(foga,back);
    break;
  case 4: back=4;
	b=value;
	fog(foga,back);
    break;
  case 5: back=5;
	b=value;
	fog(foga,back);
    break;
 case 6:  back=6;
	b=value;
	fog(foga,back);
    break;
 case 7:  back=7;
	b=0;
	fog(foga,back);
    break;
  }
}
void rasterMenu(int ren)
{
	switch(ren)
	{
	case 1:rastermode=FILL;
		r=ren;
		break;
	case 2: rastermode=WIRE;
		r=ren;
		break;
	case 3:rastermode=BACKFACE;
		r=ren;
		break;
	case 4:rastermode=FRONTLINES;
		r=0;
		break;
	default:
		break;
	}
}
/*Key Fucntions*/
void keyboard (unsigned char key, int x, int y) 
{  
	switch(key)
	{ 
	case 13: k=1;
		glutPostRedisplay();
		break;
	case 'f':
	case 'F':
		fog(++foga,back);
		break;
	case 'N':
	case 'n':objMenu(++a);
		break;
	case 'b':
	case 'B':backMenu(++b);
		break;
	case 'r':
	case 'R':rasterMenu(++r);
		break;
	case 'l':
	case 'L':light(++l);
		break;
	case 'q':
	case 'Q':exit(0);
		break;
	case 'v':
	case 'V':glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
		     view=abs(view-1);
		break;
	case 61:rotMenu(32);
		trans=5;
		break;
	case 45:rotMenu(32);
		trans=6;		
		break;
	default:rotMenu(key);
		break;
	}
}
void special(int key,int x,int y)
{
	switch(key)
	{
		case GLUT_KEY_RIGHT:rotMenu(32);
			trans=1;;
			break;
		case GLUT_KEY_LEFT:rotMenu(32);
			trans=2;			
			break;
		case GLUT_KEY_UP:rotMenu(32);
			trans=3;			
			break;
		case GLUT_KEY_DOWN:rotMenu(32);
			trans=4;
			
			break;
	}
}
/*Effect Functions*/
void fog(int a,int fc)
{
	switch(a)
	{
	case 1:glFogfv (GL_FOG_COLOR, fogColor[fc]);
	    glFogf (GL_FOG_DENSITY, density);
	    glHint (GL_FOG_HINT, GL_NICEST);
	    glEnable(GL_FOG);
		break;
	case 2:glDisable(GL_FOG);
		foga=0;
		break;
	}
}
void light(int ll)
{
	switch(ll)
	{
	case 1: glEnable(GL_LIGHTING);			
	   break;
	case 2:glDisable(GL_LIGHTING);
		l=0;
		break;
	}
}

void rotate(void)
{
	trans=0;
	theta[0]=0;	
	theta[1]=0;		
	theta[2]=0;
	theta[axis]+=1.0;
	if(theta[axis]>360.0) theta[axis]-=360.0;
	glutPostRedisplay();
}

int main(int argc,char** argv)
{
	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(900,700);
	glutInitWindowPosition(200.0,0.0); 
    glutCreateWindow ("3D Objects"); 
	glutReshapeFunc(myReshape);
	glClearColor(1,1,1,1);
	glutKeyboardFunc(keyboard);
	glutSpecialFunc(special);
	//glEnable(GL_DEPTH_TEST);

	menuIdRot=glutCreateMenu(rotMenu);
	glutAddMenuEntry("Rotate on X axis (x)",1);
	glutAddMenuEntry("Rotate on Y axis (y)",2);
	glutAddMenuEntry("Rotate on Z axis (z) ",3);
	glutAddMenuEntry("Rotation Opposite Direction(o)",4);
	glutAddMenuEntry("Stop Rotation (Spacebar)",32);
	
	menIdtran = glutCreateMenu(transMenu);
	glutAddMenuEntry("X - axis Translation On ", 1);
	glutAddMenuEntry("Y - axis Translation On ", 2);
	glutAddMenuEntry("Z - axis Translation On ", 3);
	glutAddMenuEntry("Translation Off (Spacebar) ", 4);
	
	menuIdObj = glutCreateMenu(objMenu);
	glutAddMenuEntry("House", 1);
	glutAddMenuEntry("Lamp",2);
	glutAddMenuEntry("Table", 3);
	glutAddMenuEntry("Chair ", 4);
	glutAddMenuEntry("Teapot on Plate",5);
	glutAddMenuEntry("IceCream",6);	
	glutAddMenuEntry("Rubik's Cube", 7);

	menuIdback = glutCreateMenu(backMenu);
	glutAddMenuEntry("Light Blue ", 1);
	glutAddMenuEntry("Pink", 2);
	glutAddMenuEntry("Green ", 3);
	glutAddMenuEntry("Brown ", 4);
	glutAddMenuEntry("Gray", 5);
	glutAddMenuEntry("Yellow ", 6);
	glutAddMenuEntry("Black ", 7);

	menuIdraster = glutCreateMenu(rasterMenu);
	glutAddMenuEntry("FillSolid",1);
	glutAddMenuEntry("Wireframe",2);
	glutAddMenuEntry("Backface",3);
	glutAddMenuEntry("FrontLines",4);

	menuIdMain = glutCreateMenu(mainMenu);
	glutAddSubMenu("Translation ", menIdtran);
	glutAddSubMenu("Rotation",menuIdRot);
	glutAddSubMenu("Next Object [n]",menuIdObj);
	glutAddSubMenu("Change Background [b]", menuIdback);	
	glutAddSubMenu("Rasterization Mode [r]",menuIdraster);
	glutAddMenuEntry("Fog On [f]",1);
	glutAddMenuEntry("Lighting Off[l]",2);
	glutAddMenuEntry("Press [v] and resize screen to toggle view",3);
	glutAddMenuEntry("Quit [q]", 4);
	glutAttachMenu(GLUT_RIGHT_BUTTON);

	
	glNewList(House,GL_COMPILE);
	house();
	glEndList();

	glNewList(Teapot,GL_COMPILE);
	teapot();
	glEndList();

	glNewList(Table,GL_COMPILE);
	table(70,8,6,50);
	glEndList();

	glNewList(Chair,GL_COMPILE);
	chair(40,6,6,25);
	glEndList();


	glNewList(Sphere, GL_COMPILE);
    icecream();
    glEndList();
	
	glNewList(Lamp, GL_COMPILE);
	glPushMatrix();
	glRotated(90,1,0,0);
    lamp();
	glPopMatrix();
    glEndList();

	glNewList(Cube,GL_COMPILE);
	rubix();
	glEndList();

	
	glutDisplayFunc(display);
	glEnable(GL_DEPTH_TEST);
	glutMainLoop();
	return 0;
}
