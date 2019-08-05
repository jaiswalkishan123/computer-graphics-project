#include<windows.h>
#include<stdio.h>
#include<GL/glut.h>
#include<math.h>
#define PI 3.1415
float r;
float rotate=0;
float X=2000,X1=400,X2=300,X3=300;
int snow=1000;
int whichScene = 0,whichInfo = 0;
int selected = 0,colorSelection = 0;
int i,i1,i2,m,m1,m2,m3,m4,m5,m6;

void print(char *string,float r,float g,float b,int x,int y)
{
    glPushMatrix();
    glColor3f(1, 0, 0);
    glRasterPos2f(x, y);
    while(*string)
     glutBitmapCharacter( GLUT_BITMAP_TIMES_ROMAN_24, *string++);
    glPopMatrix();
}
void circle(int x,int y,int r,float red,float green,float blue)
{
    glColor3f(red,green,blue);
    glBegin(GL_POLYGON);
    for(float i=0;i<360;i=i+5)
        glVertex2f(r*sin(i*PI/180)+x,r*cos(i*PI/180)+y);
    glEnd();
}
void background()
{
    int    yx=600,yy=200;
  glClear(GL_COLOR_BUFFER_BIT);
  glBegin(GL_POLYGON);
  glColor3f(0.4,0.2,0.1);
  glPointSize(5.0);
  glVertex2f(yx+450,200+yy);
  glVertex2f(yx+450,600+yy);
  glVertex2f(yx+450,200+yy);
  glVertex2f(yx+1050,200+yy);
  glVertex2f(yx+1050,200+yy);
  glVertex2f(yx+1050,600+yy);
  glVertex2f(yx+450,600+yy);
  glVertex2f(yx+450,600+yy);
  glVertex2f(yx+750,750+yy);
  glVertex2f(yx+750,750+yy);
  glVertex2f(yx+1050,600+yy);
  glEnd();
//arch
  glBegin(GL_LINES);
  glColor3f(1,1,1);
  glVertex2f(yx+450,600+yy);
  glVertex2f(yx+750,750+yy);
  glVertex2f(yx+750,750+yy);
  glVertex2f(yx+1050,600+yy);
  glEnd();
  //door1
  glBegin(GL_POLYGON);
  glColor3f(0.25,0,0);
  glVertex2f(yx+700,200+yy);
  glVertex2f(yx+700,400+yy);
  glVertex2f(yx+700,400+yy);
  glVertex2f(yx+750,420+yy);
  glVertex2f(yx+750,420+yy);
  glVertex2f(yx+800,400+yy);
  glVertex2f(yx+800,400+yy);
  glVertex2f(yx+800,200+yy);
  glVertex2f(yx+750,200+yy);
  glVertex2f(yx+750,420+yy);
  glEnd();
  //1st window
  glBegin(GL_LINES);
  glColor3f(0.56,0.9,0.99);
  glVertex2f(yx+550,300+yy);
  glVertex2f(yx+550,400+yy);
  glVertex2f(yx+550,400+yy);
  glVertex2f(yx+650,400+yy);
  glVertex2f(yx+650,400+yy);
  glVertex2f(yx+650,300+yy);
  glVertex2f(yx+650,300+yy);
  glVertex2f(yx+550,300+yy);
  glVertex2f(yx+600,300+yy);
  glVertex2f(yx+600,400+yy);
  glVertex2f(yx+550,350+yy);
  glVertex2f(yx+650,350+yy);
  glEnd();
  //2nd window
  glBegin(GL_LINES);
  glColor3f(0.56,0.9,0.99);
  glVertex2f(yx+850,300+yy);
  glVertex2f(yx+850,400+yy);
  glVertex2f(yx+850,400+yy);
  glVertex2f(yx+950,400+yy);
  glVertex2f(yx+950,400+yy);
  glVertex2f(yx+950,300+yy);
  glVertex2f(yx+950,300+yy);
  glVertex2f(yx+850,300+yy);
  glVertex2f(yx+900,300+yy);
  glVertex2f(yx+900,400+yy);
  glVertex2f(yx+850,350+yy);
  glVertex2f(yx+950,350+yy);
  glEnd();
  //doom
  glBegin(GL_POLYGON);
  glColor3f(0.4,0.2,0.1);
  glVertex2f(yx+600,650+yy);
  glVertex2f(yx+600,850+yy);
  glVertex2f(yx+600,1150+yy);
  glVertex2f(yx+900,1150+yy);
  glVertex2f(yx+900,1150+yy);
  glVertex2f(yx+900,650+yy);
  glVertex2f(yx+600,1150+yy);
  glVertex2f(yx+750,1300+yy);
  glVertex2f(yx+750,1300+yy);
  glVertex2f(yx+900,1150+yy);
  glEnd();
  //cross
  glBegin(GL_LINES);
  glColor3f(1,1,1);
  glVertex2f(yx+750,1300+yy);
  glVertex2f(yx+750,1450+yy);
  glVertex2f(yx+700,1375+yy);
  glVertex2f(yx+800,1375+yy);
  glEnd();
  //3rd window
  glBegin(GL_LINES);
  glColor3f(0.56,0.9,0.99);
  glVertex2f(yx+700,950+yy);
  glVertex2f(yx+800,950+yy);
  glVertex2f(yx+800,950+yy);
  glVertex2f(yx+800,1050+yy);
  glVertex2f(yx+800,1050+yy);
  glVertex2f(yx+700,1050+yy);
  glVertex2f(yx+700,1050+yy);
  glVertex2f(yx+700,950+yy);
  glVertex2f(yx+750,950+yy);
  glVertex2f(yx+750,1050+yy);
  glVertex2f(yx+700,1000+yy);
  glVertex2f(yx+800,1000+yy);
  glEnd();

  glBegin(GL_LINES);
  glColor3f(1,1,1);
  glVertex2f(yx+600,850+yy);
  glVertex2f(yx+900,850+yy);
  glVertex2f(yx+600,1150+yy);
  glVertex2f(yx+900,1150+yy);
  glEnd();

 //christ tree
  glBegin(GL_POLYGON);
  int x=1800;
  int y=300;
  glColor3f(0,0.5,0);
  glVertex2f(x+300,700+y); 
  glVertex2f(x+370,500+y);
  glVertex2f(x+370,500+y);
  glVertex2f(x+330,500+y);
  glVertex2f(x+330,500+y);
  glVertex2f(x+380,400+y);
  glVertex2f(x+380,400+y);
  glVertex2f(x+340,400+y);
  glVertex2f(x+340,400+y);
  glVertex2f(x+390,300+y);
  glVertex2f(x+390,300+y);
  glVertex2f(x+350,300+y);
  glVertex2f(x+350,300+y);
  glVertex2f(x+400,200+y);
  glVertex2f(x+200,200+y);
  glVertex2f(x+400,200+y);
  glVertex2f(x+200,200+y);
  glVertex2f(x+250,300+y);
  glVertex2f(x+250,300+y);
  glVertex2f(x+210,300+y);
  glVertex2f(x+210,300+y);
  glVertex2f(x+260,400+y);
  glVertex2f(x+260,400+y);
  glVertex2f(x+220,400+y);
  glVertex2f(x+220,400+y);
  glVertex2f(x+270,500+y);
  glVertex2f(x+270,500+y);
  glVertex2f(x+230,500+y);
  glVertex2f(x+230,500+y);
  glVertex2f(x+300,700+y); // might change this to 600
  glEnd();

  circle(x+250,y+300,10,1,0.85,0);
  circle(x+350,y+400,10,1,0,0);
  circle(x+275,y+500,10,1,0,0);
  circle(x+325,y+550,10,1,0.85,0);
//pot
  glBegin(GL_POLYGON);
  glColor3f(0.36,0,0.0);
  glVertex2f(x+250,200+y);
  glVertex2f(x+250,100+y);
  glVertex2f(x+250,100+y);
  glVertex2f(x+350,100+y);
  glVertex2f(x+350,100+y);
  glVertex2f(x+350,200+y);
  glEnd();
  //stick
  glBegin(GL_LINES);
  glColor3f(1,1,0);
  glVertex2f(x+300,700+y);
  glVertex2f(x+300,800+y);
  glEnd();
  //star
  glBegin(GL_POLYGON);
  glColor3f(0.7,0.7,0.7);
  glVertex2f(x+300,y+800);
  glVertex2f(x+320,y+780);
  glVertex2f(x+320,y+780);
  glVertex2f(x+310,y+820);
  glVertex2f(x+310,y+820);
  glVertex2f(x+330,y+840);
  glVertex2f(x+330,y+840);
  glVertex2f(x+305,y+840);
  glVertex2f(x+305,y+840);
  glVertex2f(x+300,y+880); 
  glVertex2f(x+300,y+880); 
  glVertex2f(x+295,y+840);
  glVertex2f(x+295,y+840);
  glVertex2f(x+270,y+840);
  glVertex2f(x+270,y+840);
  glVertex2f(x+290,y+820);
  glVertex2f(x+290,y+820);
  glVertex2f(x+280,y+780);
  glVertex2f(x+280,y+780);
  glVertex2f(x+300,y+800);
  glEnd();
  //tree2
  glBegin(GL_POLYGON);
  int x6=200;
  int y6=300;
  glColor3f(0,0.5,0);
  glVertex2f(x6+300,700+y6); 
  glVertex2f(x6+370,500+y6);
  glVertex2f(x6+370,500+y6);
  glVertex2f(x6+330,500+y6);
  glVertex2f(x6+330,500+y6);
  glVertex2f(x6+380,400+y6);
  glVertex2f(x6+380,400+y6);
  glVertex2f(x6+340,400+y6);
  glVertex2f(x6+340,400+y6);
  glVertex2f(x6+390,300+y6);
  glVertex2f(x6+390,300+y6);
  glVertex2f(x6+350,300+y6);
  glVertex2f(x6+350,300+y6);
  glVertex2f(x6+400,200+y6);
  glVertex2f(x6+200,200+y6);
  glVertex2f(x6+400,200+y6);
  glVertex2f(x6+200,200+y6);
  glVertex2f(x6+250,300+y6);
  glVertex2f(x6+250,300+y6);
  glVertex2f(x6+210,300+y6);
  glVertex2f(x6+210,300+y6);
  glVertex2f(x6+260,400+y6);
  glVertex2f(x6+260,400+y6);
  glVertex2f(x6+220,400+y6);
  glVertex2f(x6+220,400+y6);
  glVertex2f(x6+270,500+y6);
  glVertex2f(x6+270,500+y6);
  glVertex2f(x6+230,500+y6);
  glVertex2f(x6+230,500+y6);
  glVertex2f(x6+300,700+y6); 
  glEnd();
  circle(x6+250,y6+300,10,1,0.85,0);
  circle(x6+350,y6+400,10,1,0,0);
  circle(x6+275,y6+500,10,1,0,0);
  circle(x6+325,y6+550,10,1,0.85,0);
//pot
  glBegin(GL_POLYGON);
  glColor3f(0.36,0,0.0);
  glVertex2f(x6+250,200+y6);
  glVertex2f(x6+250,100+y6);
  glVertex2f(x6+250,100+y6);
  glVertex2f(x6+350,100+y6);
  glVertex2f(x6+350,100+y6);
  glVertex2f(x6+350,200+y6);
  glEnd();
  //stick
  glBegin(GL_LINES);
  glColor3f(1,1,0);
  glVertex2f(x6+300,700+y6);
  glVertex2f(x6+300,800+y6);
  glEnd();
  //star
  glBegin(GL_POLYGON);
  glColor3f(0.7,0.7,0.7);
  glVertex2f(x6+300,y6+800);
  glVertex2f(x6+320,y6+780);
  glVertex2f(x6+320,y6+780);
  glVertex2f(x6+310,y6+820);
  glVertex2f(x6+310,y6+820);
  glVertex2f(x6+330,y6+840);
  glVertex2f(x6+330,y6+840);
  glVertex2f(x6+305,y6+840);
  glVertex2f(x6+305,y6+840);
  glVertex2f(x6+300,y6+880); // maybe 850
  glVertex2f(x6+300,y6+880); // maybe 850
  glVertex2f(x6+295,y6+840);
  glVertex2f(x6+295,y6+840);
  glVertex2f(x6+270,y6+840);
  glVertex2f(x6+270,y6+840);
  glVertex2f(x6+290,y6+820);
  glVertex2f(x6+290,y6+820);
  glVertex2f(x6+280,y6+780);
  glVertex2f(x6+280,y6+780);
  glVertex2f(x6+300,y6+800);
  glEnd();
 //cloud
  glBegin(GL_POLYGON);
   glColor3f(1,1,1);
  for(m=0;m<=360;m++)
  {
     float deg2rad=m*PI/180;
     r=100;
     glVertex2f(cos(deg2rad)*r+1200,sin(deg2rad)*r+2220);
  }
 glEnd();

  glBegin(GL_POLYGON);
  for(m1=0;m1<=360;m1++)
  {
     float deg2rad=m1*PI/180;
     r=100;
     glVertex2f(cos(deg2rad)*r+1300,sin(deg2rad)*r+2220);
  }
 glEnd();

  glBegin(GL_POLYGON);
  for(m2=0;m2<=360;m2++)
  {
     float deg2rad=m2*PI/180;
     r=100;
     glVertex2f(cos(deg2rad)*r+1400,sin(deg2rad)*r+2220);
  }
 glEnd();

  glBegin(GL_POLYGON);
  for(m4=0;m4<=360;m4++)
  {
     float deg2rad=m4*PI/180;
     r=100;
     glVertex2f(cos(deg2rad)*r+1250,sin(deg2rad)*r+2275);
  }
 glEnd();

  glBegin(GL_POLYGON);
  for(m5=0;m5<=360;m5++)
  {
     float deg2rad=m5*PI/180;
     r=100;
     glVertex2f(cos(deg2rad)*r+1350,sin(deg2rad)*r+2275);
  }
 glEnd();

//cloud2
 glBegin(GL_POLYGON);
  for(int s=0;s<=360;s++)
  {
     float deg2rad=s*PI/180;
     r=100;
     glVertex2f(cos(deg2rad)*r+2000,sin(deg2rad)*r+1900);
  }
 glEnd();

 glBegin(GL_POLYGON);
  for(int s1=0;s1<=360;s1++)
  {
     float deg2rad=s1*PI/180;
     r=200;
     glVertex2f(cos(deg2rad)*r+2100,sin(deg2rad)*r+1900);
  }
 glEnd();

 glBegin(GL_POLYGON);
  for(int s2=0;s2<=360;s2++)
  {
     float deg2rad=s2*PI/180;
     r=200;
     glVertex2f(cos(deg2rad)*r+2200,sin(deg2rad)*r+1900);
  }
 glEnd();

 glBegin(GL_POLYGON);
  for(int s3=0;s3<=360;s3++)
  {
     float deg2rad=s3*PI/180;
     r=200;
     glVertex2f(cos(deg2rad)*r+2300,sin(deg2rad)*r+1900);
  }
 glEnd();

 //house
    /*glBegin(GL_POLYGON);
    glColor3f(1,0.7529,0.7960);
    glVertex2f(200,400);
    glVertex2f(200,800);
    glVertex2f(410,800);
    glVertex2f(410,450);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,0.4117,0);
    glVertex2f(200,400);
    glVertex2f(200,800);
    glVertex2f(50,800);
    glVertex2f(50,450);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.55,0.40,0.291);
    glVertex2f(200,800);
    glVertex2f(300,1000);
    glVertex2f(410,800);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5555,0.444,0.2999);
    glVertex2f(200,800);
    glVertex2f(300,1000);
    glVertex2f(150,1000);
    glVertex2f(50,800);
    glEnd();
    //door1
    glBegin(GL_POLYGON);
    glColor3f(0.7,0.66,0.4);
    glVertex2f(275,425);
    glVertex2f(275,550);
    glVertex2f(325,550);
    glVertex2f(325,425);
    glEnd();

    //house2
    int z=2200;
    glBegin(GL_POLYGON);
    glColor3f(1,0.7529,0.7960);
    glVertex2f(z+200,400);
    glVertex2f(z+200,800);
    glVertex2f(z+410,800);
    glVertex2f(z+410,450);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(1,0.4117,0);
    glVertex2f(z+200,400);
    glVertex2f(z+200,800);
    glVertex2f(z+50,800);
    glVertex2f(z+50,450);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.55,0.40,0.291);
    glVertex2f(z+200,800);
    glVertex2f(z+300,1000);
    glVertex2f(z+410,800);
    glEnd();

    glBegin(GL_POLYGON);
    glColor3f(0.5555,0.444,0.2999);
    glVertex2f(z+200,800);
    glVertex2f(z+300,1000);
    glVertex2f(z+150,1000);
    glVertex2f(z+50,800);
    glEnd();
    //door
    glBegin(GL_POLYGON);
    glColor3f(0.7,0.66,0.4);
    glVertex2f(z+275,425);
    glVertex2f(z+275,550);
    glVertex2f(z+325,550);
    glVertex2f(z+325,425);
    glEnd();*/
}
void snow_draw(void)
{
    glTranslatef(snow-2000,snow,0);
            circle(2000,snow,20,1,1,1);
            circle(2100,snow,20,1,1,1);
            circle(2200,snow,20,1,1,1);
            circle(2300,snow,20,1,1,1);
            circle(3000,snow,20,1,1,1);
            circle(3100,snow,20,1,1,1);
            circle(3200,snow,20,1,1,1);
            circle(3300,snow,20,1,1,1);
            if(snow<700){

                circle(2100+snow-500,snow+700,20,1,1,1);
                circle(2200+snow-500,snow+700,20,1,1,1);
                circle(2300+snow-500,snow+700,20,1,1,1);
                circle(3100+snow-500,snow+700,20,1,1,1);
                circle(3200+snow-500,snow+700,20,1,1,1);
                circle(3300+snow-500,snow+700,20,1,1,1);
            }
            if(snow<400){
                circle(2000+snow,snow+1200,20,1,1,1);
                circle(2100+snow,snow+1200,20,1,1,1);
                circle(2200+snow,snow+1200,20,1,1,1);
                circle(2300+snow,snow+1200,20,1,1,1);
                circle(3000+snow,snow+1200,20,1,1,1);
                circle(3100+snow,snow+1200,20,1,1,1);
                circle(3200+snow,snow+1200,20,1,1,1);
                circle(3300+snow,snow+1200,20,1,1,1);
            }
}
void colorBox(int x,float r,float g,float b)
{
    glColor3f(r,g,b);
    glBegin(GL_POLYGON);
    for(i=90;i<270;i++)
        glVertex2f(x+50*sin(i*PI/180)+1400,20*cos(i*PI/180)+400);
    glEnd();
    glBegin(GL_POLYGON);
    glVertex2f(x+1350,400);
    glVertex2f(x+1350,600);
    glVertex2f(x+1350,600);
    glVertex2f(x+1450,600);
    glVertex2f(x+1450,600);
    glVertex2f(x+1450,400);
    glVertex2f(x+1450,400);
    glVertex2f(x+1350,400);
    glEnd();
        glColor3f(0,0,0);
    glBegin(GL_POLYGON);
    for(i=0;i<360;i++)
        glVertex2f(x+50*sin(i*PI/180)+1400,20*cos(i*PI/180)+600);
    glEnd();
}
//diwali functions
void sparkles(int x,int y)
{
  glColor3f(0,1,0);
  glBegin(GL_LINES);
  glVertex2f(x+15*sin(22*PI/180)+250,y+15*cos(22*PI/180)+2750);
  glVertex2f(x+100*sin(22*PI/180)+250,y+100*cos(22*PI/180)+2750);
  glEnd();

  glColor3f(0,1,0);
  glBegin(GL_LINES);
  glVertex2f(x+10*sin(45*PI/180)+250,y+15*cos(45*PI/180)+2750);
  glVertex2f(x+135*sin(45*PI/180)+250,y+135*cos(45*PI/180)+2750);
  glEnd();

  glColor3f(1,0,0);
  glBegin(GL_LINES);
  glVertex2f(x+15*sin(75*PI/180)+250,y+15*cos(75*PI/180)+2750);
  glVertex2f(x+100*sin(75*PI/180)+250,y+100*cos(75*PI/180)+2750);
  glEnd();

  glColor3f(1,0,0);
  glBegin(GL_LINES);
  glVertex2f(x+15*sin(110*PI/180)+250,y+15*cos(110*PI/180)+2750);
  glVertex2f(x+100*sin(110*PI/180)+250,y+100*cos(110*PI/180)+2750);
  glEnd();

  glColor3f(0,0,1);
  glBegin(GL_LINES);
  glVertex2f(x+15*sin(135*PI/180)+250,y+15*cos(135*PI/180)+2750);
  glVertex2f(x+135*sin(135*PI/180)+250,y+135*cos(135*PI/180)+2750);
  glEnd();

  glColor3f(1,0,0);
  glBegin(GL_LINES);
  glVertex2f(x+15*sin(150*PI/180)+250,y+15*cos(150*PI/180)+2750);
  glVertex2f(x+65*sin(150*PI/180)+250,y+65*cos(150*PI/180)+2750);
  glEnd();

  glColor3f(1,0,0);
  glBegin(GL_LINES);
  glVertex2f(x+15*sin(200*PI/180)+250,y+15*cos(200*PI/180)+2750);
  glVertex2f(x+100*sin(200*PI/180)+250,y+100*cos(200*PI/180)+2750);
  glEnd();

  glColor3f(1,0,1);
  glBegin(GL_LINES);
  glVertex2f(x+15*sin(225*PI/180)+250,y+15*cos(225*PI/180)+2750);
  glVertex2f(x+135*sin(225*PI/180)+250,y+135*cos(225*PI/180)+2750);
  glEnd();

  glColor3f(1,0,0);
  glBegin(GL_LINES);
  glVertex2f(x+15*sin(250*PI/180)+250,y+15*cos(250*PI/180)+2750);
  glVertex2f(x+100*sin(250*PI/180)+250,y+100*cos(250*PI/180)+2750);
  glEnd();
}

void drawGirl(int x,int y)
{
      // shoes curve
  glColor3f(0,0,0);
  glBegin(GL_POINTS);
  for(i=0;i<180;i++)
      glVertex2f(x+5*sin(i*PI/180)+1060,y+15*cos(i*PI/180)+585);

  for(i=180;i<360;i++)
      glVertex2f(x+5*sin(i*PI/180)+930,y+15*cos(i*PI/180)+585);
  glEnd();
  //girl
  glColor3f(0,0,0);
  glBegin(GL_LINES);
  //right leg
  glVertex2f(x+1020,y+570);
  glVertex2f(x+1020,y+700);
  glVertex2f(x+1040,y+600);
  glVertex2f(x+1040,y+700);

  glVertex2f(x+1020,y+570);
  glVertex2f(x+1060,y+570);
  glVertex2f(x+1040,y+600);
  glVertex2f(x+1060,y+600);

  //left leg
  glVertex2f(x+970,y+570);
  glVertex2f(x+970,y+700);
  glVertex2f(x+950,y+600);
  glVertex2f(x+950,y+700);
  glVertex2f(x+970,y+570);
  glVertex2f(x+930,y+570);
  glVertex2f(x+950,y+600);
  glVertex2f(x+930,y+600);
  glEnd();

  glColor3f(1,0,0);
  glBegin(GL_POLYGON);

  glVertex2f(x+995,y+1020);
  glVertex2f(x+1010,y+1060);
  glVertex2f(x+1040,y+1060);
  glVertex2f(x+1010,y+1060);

  for(i=180;i<360;i++)
     glVertex2f(x+15*sin(i*PI/180)+1040,y+80*cos(i*PI/180)+980);
  glVertex2f(x+950,y+900);
  glVertex2f(x+1040,y+900);

  for(i=180;i>0;i--)
     glVertex2f(x+15*sin(i*PI/180)+950,y+80*cos(i*PI/180)+980);
  glVertex2f(x+950,y+1060);
  glVertex2f(x+980,y+1060);
  glVertex2f(x+980,y+1060);
  glVertex2f(x+995,y+1020);
  glEnd();
  glColor3f(0,0,0);
  //shoulder
  glBegin(GL_LINES);
    //hand left
  glVertex2f(x+950,y+1060);
  glVertex2f(x+935,y+1020);
  glVertex2f(x+935,y+1020);
  glVertex2f(x+910,y+1040);
  glVertex2f(x+960,y+1050);
  glVertex2f(x+935,y+1000);
  glVertex2f(x+935,y+1000);
  glVertex2f(x+910,y+1020);
  glVertex2f(x+910,y+1020);
  glVertex2f(x+910,y+1040);
  //hand right
  glVertex2f(x+1040,y+1060);
  glVertex2f(x+1050,y+850);
  glVertex2f(x+1030,y+1050);
  glVertex2f(x+1040,y+850);
  glVertex2f(x+1040,y+850);
  glVertex2f(x+1050,y+850);
 //neck
  glVertex2f(x+980,y+1060);
  glVertex2f(x+985,y+1100);
  glVertex2f(x+1010,y+1060);
  glVertex2f(x+1005,y+1100);
  glVertex2f(x+910,y+1040);
  glVertex2f(x+910,y+1060);
  glEnd();
  glLineWidth(3.0);
  glColor3f(0.7,0.7,0.7);
  glBegin(GL_LINES);
    //sursurbatti in left hand
  glVertex2f(x+910,y+1060);
  glVertex2f(x+910,y+1150);
  glEnd();
  glLineWidth(1.0);

  glColor3f(0,1,0);
  glBegin(GL_LINES);
  glVertex2f(x+15*sin(22*PI/180)+910,y+15*cos(22*PI/180)+1150);
  glVertex2f(x+35*sin(22*PI/180)+910,y+35*cos(22*PI/180)+1150);
  glEnd();

  glColor3f(0,1,0);
  glBegin(GL_LINES);
  glVertex2f(x+10*sin(45*PI/180)+910,y+15*cos(45*PI/180)+1150);
  glVertex2f(x+60*sin(45*PI/180)+910,y+60*cos(45*PI/180)+1150);
  glEnd();

  glColor3f(1,0,0);
  glBegin(GL_LINES);
  glVertex2f(x+15*sin(75*PI/180)+910,y+15*cos(75*PI/180)+1150);
  glVertex2f(x+35*sin(75*PI/180)+910,y+35*cos(75*PI/180)+1150);
  glEnd();

  glColor3f(0.5,0.25,1);
  glBegin(GL_LINES);
  glVertex2f(x+15*sin(325*PI/180)+910,y+15*cos(325*PI/180)+1150);
  glVertex2f(x+60*sin(325*PI/180)+910,y+60*cos(325*PI/180)+1150);
  glEnd();

  glColor3f(1,0,0);
  glBegin(GL_LINES);
  glVertex2f(x+15*sin(345*PI/180)+910,y+15*cos(345*PI/180)+1150);
  glVertex2f(x+35*sin(345*PI/180)+910,y+35*cos(345*PI/180)+1150);
  glEnd();
  //face
  glColor3f(0,0,0);
  glBegin(GL_POINTS);
  for(i=0;i<360;i++)
     glVertex2f(x+30*sin(i*PI/180)+995,y+50*cos(i*PI/180)+1140);
  glEnd();
  //eyes
  glBegin(GL_POLYGON);
  for(i=0;i<360;i++)
     glVertex2f(x+5*sin(i*PI/180)+980,y+5*cos(i*PI/180)+1150);
  glEnd();
  glBegin(GL_POLYGON);
  for(i=0;i<360;i++)
    glVertex2f(x+5*sin(i*PI/180)+1010,y+5*cos(i*PI/180)+1150);
  glEnd();
  //smile
  glBegin(GL_POINTS);
  for(i=90;i<270;i++)
    glVertex2f(x+15*sin(i*PI/180)+995,y+15*cos(i*PI/180)+1130);
  glEnd();
  //hair
  glPointSize(3.0);
  glBegin(GL_POINTS);
  for(i=270;i<360;i++)
     glVertex2f(x+35*sin(i*PI/180)+995,y+60*cos(i*PI/180)+1140);
  glEnd();
  glBegin(GL_POINTS);
  for(i=0;i<90;i++)
     glVertex2f(x+35*sin(i*PI/180)+995,y+60*cos(i*PI/180)+1140);
  glEnd();
  //pony
  glLineWidth(3.0);
  glBegin(GL_LINES);
  glVertex2f(x+1030,y+1140);
  glVertex2f(x+1030,y+1060);
  glVertex2f(x+960,y+1140);
  glVertex2f(x+960,y+1060);
  glEnd();
  glLineWidth(1.0);
  glPointSize(1.0);
  //skirt
 glColor3f(1.0,0.5,0);
  glBegin(GL_POLYGON);
  glVertex2f(x+1070,y+700);
  glVertex2f(x+920,y+700);
  glVertex2f(x+920,y+700);
  glVertex2f(x+950,y+900);
  glVertex2f(x+1070,y+700);
  glVertex2f(x+1040,y+900);
  glVertex2f(x+950,y+900);
  glVertex2f(x+1040,y+900);
  glEnd();
}
void chakkar()
{
    glTranslatef(1200,600,0);
    glRotatef(rotate,0,0,2);

  glColor3f(1,0.5,0.25);
  glBegin(GL_POLYGON);
  for(i=0;i<360;i++)
      glVertex2f(60*sin(i*PI/180)+0,60*cos(i*PI/180)+0);
  glEnd();
  glColor3f(1,0.5,1);
  glBegin(GL_POLYGON);
  for(i=0;i<360;i++)
      glVertex2f(40*sin(i*PI/180)+0,40*cos(i*PI/180)+0);
  glEnd();
  glColor3f(0,1,1);
  glBegin(GL_POLYGON);
  for(i=0;i<360;i++)
      glVertex2f(20*sin(i*PI/180)+0,20*cos(i*PI/180)+0);
  glEnd();
  glColor3f(1,0.5,0);
  glBegin(GL_POLYGON);
  glVertex2f(0,60);
  glVertex2f(100,60);
  glVertex2f(60,0);
  glVertex2f(100,0);
  glVertex2f(100,0);
  glVertex2f(100,60);
  glEnd();
  glBegin(GL_POINTS);
  for(i=0;i<30;i++)
      glVertex2f(100*sin(i*PI/180)+100,100*cos(i*PI/180)-100);
  glEnd();

  glColor3f(0,0.2,0);
  glBegin(GL_LINES);
  glVertex2f(105,20);
  glVertex2f(140,20);
  glEnd();

  glColor3f(0,0,1);
  glBegin(GL_LINES);
  glVertex2f(105,40);
  glVertex2f(160,40);
  glEnd();

  glColor3f(1,0.5,0.5);
  glBegin(GL_LINES);
  glVertex2f(105,50);
  glVertex2f(150,50);
  glEnd();

  glColor3f(1,0,0);
  glBegin(GL_LINES);
  glVertex2f(100,59);
  glVertex2f(150,59);
  glEnd();
}

void flowerpot()
{
      //flowerpot
  glColor3f(0.25,0.0,0.25);
  glBegin(GL_POLYGON);
  glVertex2f(2100,500);
  glVertex2f(2200,500);
  glVertex2f(2150,700);
  glEnd();

  glPointSize(2.0);

  if(rotate>180&&rotate<210){
    glColor3f(1,0,0);
    glBegin(GL_POINTS);
    for(i=30;i<90;i++)
      glVertex2f(200*sin(i*PI/180)+1930,250*cos(i*PI/180)+720);
    glEnd();
    glColor3f(1,0,0);
    glBegin(GL_POINTS);
    for(i=270;i<330;i++)
      glVertex2f(200*sin(i*PI/180)+2360,250*cos(i*PI/180)+720);
    glEnd();
    glColor3f(0,1,0);
    glBegin(GL_POINTS);
    for(i=20;i<90;i++)
      glVertex2f(200*sin(i*PI/180)+1935,250*cos(i*PI/180)+780);
    glEnd();
    glColor3f(0,1,0);
    glBegin(GL_POINTS);
    for(i=270;i<340;i++)
      glVertex2f(200*sin(i*PI/180)+2355,250*cos(i*PI/180)+780);
    glEnd();
    glColor3f(0,0,1);
    glBegin(GL_POINTS);
    for(i=10;i<90;i++)
      glVertex2f(200*sin(i*PI/180)+1940,250*cos(i*PI/180)+840);
    glEnd();
    glColor3f(0,0,1);
    glBegin(GL_POINTS);
    for(i=270;i<350;i++)
      glVertex2f(200*sin(i*PI/180)+2350,250*cos(i*PI/180)+840);
    glEnd();
  }
    glPointSize(1.0);
}

void diwali()
{
      glClear(GL_COLOR_BUFFER_BIT);
  //left part of house
  glColor3f(1,0.5,0.5);
  glBegin(GL_POLYGON);
  glVertex2f(500,1000);
  glVertex2f(1000,1000);
  glVertex2f(1000,2050);
  glVertex2f(500,2050);
  glEnd();
  //left house top
  glColor3f(0.5,0,0);
  glBegin(GL_POLYGON);
  glVertex2f(500,2050);
  glVertex2f(550,2300);
  glVertex2f(1000,2300);
  glVertex2f(1000,2050);
  glEnd();
  //right part of house
  glColor3f(1,0.5,0.5);
  glBegin(GL_POLYGON);
  glVertex2f(2500,1000);
  glVertex2f(2000,1000);
  glVertex2f(2000,2050);
  glVertex2f(2500,2050);
  glEnd();
  //right house top
  glColor3f(0.5,0,0);
  glBegin(GL_POLYGON);
  glVertex2f(2500,2050);
  glVertex2f(2450,2300);
  glVertex2f(2000,2300);
  glVertex2f(2000,2050);
  glEnd();
   //centre house top
  glColor3f(0.7,0,0);
  glBegin(GL_POLYGON);
  glVertex2f(900,2200);
  glVertex2f(1200,2700);
  glVertex2f(1800,2700);
  glVertex2f(2100,2200);
  glEnd();
  //centre house
  glColor3f(1,0.7,0.5);
  glBegin(GL_POLYGON);
  glVertex2f(1000,1000);
  glVertex2f(1000,2200);
  glVertex2f(2000,2200);
  glVertex2f(2000,1000);
  glEnd();

  //lines for house
  glColor3f(1.0,1.0,1.0);
  glBegin(GL_LINES);
  // left house
  glVertex2f(500,2000);
  glVertex2f(1000,2000);
  glVertex2f(500,2050);
  glVertex2f(1000,2050);
  //right house
  glVertex2f(2000,2000);
  glVertex2f(2500,2000);
  glVertex2f(2000,2050);
  glVertex2f(2500,2050);
  //centre house
  glVertex2f(1000,1000);
  glVertex2f(1000,2200);
  glVertex2f(2000,1000);
  glVertex2f(2000,2200);
  glEnd();
  //windows
  glColor3f(1.0,1.0,1.0);
  glBegin(GL_LINE_LOOP);
  glVertex2f(650,1400);
  glVertex2f(850,1400);
  glVertex2f(850,1600);
  glVertex2f(650,1600);
  glEnd();

  glColor3f(1.0,1.0,1.0);
  glBegin(GL_LINE_LOOP);
  glVertex2f(2150,1400);
  glVertex2f(2350,1400);
  glVertex2f(2350,1600);
  glVertex2f(2150,1600);
  glEnd();

  //door
  glColor3f(1.0,1.0,1.0);
  glBegin(GL_LINES);
  glVertex2f(1400,1000);
  glVertex2f(1400,1500);
  glVertex2f(1600,1000);
  glVertex2f(1600,1500);
  glEnd();

  glColor3f(1,1,1);
  glBegin(GL_POINTS);
  for(i=0;i<90;i++)
     glVertex2f(100*sin(i*PI/180)+1500,100*cos(i*PI/180)+1500);
  glEnd();
  glColor3f(1,1,1);
  glBegin(GL_POINTS);
  for(i=270;i<360;i++)
     glVertex2f(100*sin(i*PI/180)+1500,100*cos(i*PI/180)+1500);
  glEnd();

  //compound
  glColor3f(0.5,0.6,0.4);
  glBegin(GL_POLYGON);
  glVertex2f(500,1000);
  glVertex2f(300,300);
  glVertex2f(2800,300);
  glVertex2f(2500,1000);
  glEnd();

  //deepa 1
  glColor3f(1,0,0);
  glBegin(GL_POLYGON);
  for(i=90;i<270;i++)
      glVertex2f(50*sin(i*PI/180)+400,50*cos(i*PI/180)+400);
  glEnd();

  //flame for deepa1
  glColor3f(1,0.5,0);
  glBegin(GL_POLYGON);
  for(i=0;i<360;i++)
      glVertex2f(5*sin(i*PI/180)+450,50*cos(i*PI/180)+450);
  glEnd();

  //deepa 2
  glColor3f(1,0,0);
  glBegin(GL_POLYGON);
  for(i=90;i<270;i++)
      glVertex2f(50*sin(i*PI/180)+2650,50*cos(i*PI/180)+400);
  glEnd();

  //flame for deepa 2
  glColor3f(1,0.5,0);
  glBegin(GL_POLYGON);
  for(i=0;i<360;i++)
      glVertex2f(5*sin(i*PI/180)+2600,50*cos(i*PI/180)+450);
  glEnd();

  //edge of compound
  glColor3f(0.3,0,0);
  glBegin(GL_POLYGON);
  glVertex2f(300,250);
  glVertex2f(300,300);
  glVertex2f(2800,300);
  glVertex2f(2800,250);
  glEnd();

  drawGirl(-100,0);
  drawGirl(800,100);
  flowerpot();
  sparkles(0,0);
  sparkles(500,0);
  sparkles(2100,0);
  glPushMatrix();
  chakkar();
  glPopMatrix();
}
void mosque()
{
      glBegin(GL_LINES);
        glColor3f(0,0,0);
        glVertex2f(500,500);
        glVertex2f(2500,500);
        glEnd();
        //pillar1
        glColor3f(0.7,0,0);
        glBegin(GL_POLYGON);
        glVertex2f(500,500);
        glVertex2f(500,2500);
        glVertex2f(550,2500);
        glVertex2f(550,500);
        glEnd();

            //pillar2
        glBegin(GL_POLYGON);
        glVertex2f(2500,500);
        glVertex2f(2500,2500);
        glVertex2f(2450,2500);
        glVertex2f(2450,500);
        glEnd();
        glColor3f(0,0.5,0);

        glBegin(GL_POLYGON);
            glVertex2f(2440,2000);
        glVertex2f(2510,2000);
        glVertex2f(2440,2050);
        glVertex2f(2510,2050);
        glVertex2f(2510,2050);
        glVertex2f(2510,2000);
        glVertex2f(2440,2050);
        glVertex2f(2440,2000);
        glEnd();

        glBegin(GL_POLYGON);
            glVertex2f(490,2000);
        glVertex2f(560,2000);
        glVertex2f(490,2050);
        glVertex2f(560,2050);
        glVertex2f(560,2050);
        glVertex2f(560,2000);
        glVertex2f(490,2050);
        glVertex2f(490,2000);
        glEnd();

        //rectangle in pillar 1
        
        glColor3f(0.5,0,0);
        glBegin(GL_POLYGON);
        glVertex2f(1200,500);
        glVertex2f(1200,1200);
        glVertex2f(1800,500);
        glVertex2f(1800,1200);
        glVertex2f(1200,1200);
        glVertex2f(1800,1200);
        glEnd();
        glColor3f(0.4,0,0);
        glBegin(GL_POLYGON);
        glVertex2f(550,1250);
        glVertex2f(2450,1250);
        glVertex2f(2450,1200);
        glVertex2f(550,1200);
        glEnd();
        glColor3f(0.4,0,0);
        glBegin(GL_POLYGON);
        glVertex2f(1800,1200);
        glVertex2f(1800,1250);
        glVertex2f(1200,1250);
        glVertex2f(1200,1200);
        glEnd();
    //top
        glColor3f(0.5,0.5,0.5);
        glBegin(GL_POLYGON);
        glVertex2f(1000,1250);
        glVertex2f(1000,1750);
        glVertex2f(1000,1750);
        glVertex2f(2000,1750);
        glVertex2f(2000,1750);
        glVertex2f(2000,1250);
        glEnd();

        glColor3f(0.7,0,0);
        glBegin(GL_POLYGON);
        glVertex2f(950,1800);
        glVertex2f(2050,1800);
        glVertex2f(950,1750);
        glVertex2f(1000,1750);
        glVertex2f(2050,1750);
        glVertex2f(2000,1750);
        glVertex2f(950,1750);
        glVertex2f(950,1800);
        glVertex2f(2050,1750);
        glVertex2f(2050,1800);
        glEnd();

        //top2
        glColor3f(0.5,0,0);
        glBegin(GL_POLYGON);
        glVertex2f(1200,1800);
        glVertex2f(1200,1900);
        glVertex2f(1200,1900);
        glVertex2f(1800,1900);
        glVertex2f(1800,1900);
        glVertex2f(1800,1800);
        glEnd();

        glColor3f(0.5,0.5,0.5);
        glBegin(GL_POLYGON);
        glVertex2f(1300,1900);
        glVertex2f(1300,2100);
        glVertex2f(1700,2100);
        glVertex2f(1700,1900);
        glEnd();

        glColor3f(0.5,0,0);
        glBegin(GL_POLYGON);
        glVertex2f(1200,2100);
        glVertex2f(1800,2100);
        glVertex2f(1200,2100);
        glVertex2f(1200,2150);
        glVertex2f(1200,2150);
        glVertex2f(1800,2150);
        glVertex2f(1800,2150);
        glVertex2f(1800,2100);
        glEnd();

        //triangle
        glColor3f(0,0.5,0);
        glBegin(GL_LINES);
        glVertex2f(490,2500);
        glVertex2f(560,2500);
        glVertex2f(490,2500);
        glVertex2f(490,2550);
        glVertex2f(490,2550);
        glVertex2f(560,2550);
        glVertex2f(560,2550);
        glVertex2f(560,2500);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0,0.5,0);
        glVertex2f(490,2550);
        glVertex2f(525,2750);
        glVertex2f(525,2750);
        glVertex2f(560,2550);
        glEnd();

        //triangle2
        glBegin(GL_LINES);
        glVertex2f(2440,2500);
        glVertex2f(2510,2500);
        glVertex2f(2510,2500);
        glVertex2f(2510,2550);
        glVertex2f(2510,2550);
        glVertex2f(2440,2550);
        glVertex2f(2440,2550);
        glVertex2f(2440,2500);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0,0.5,0);
        glVertex2f(2440,2550);
        glVertex2f(2475,2750);
        glVertex2f(2475,2750);
        glVertex2f(2510,2550);
        glEnd();

        glColor3f(0.5,0.5,0.5);
        glBegin(GL_POLYGON);
        glVertex2f(550,500);
        glVertex2f(1200,500);
        glVertex2f(1200,1200);
        glVertex2f(550,1200);
        glEnd();

        glColor3f(0.5,0.5,0.5);
        glBegin(GL_POLYGON);
        glVertex2f(1800,500);
        glVertex2f(2450,500);
        glVertex2f(2450,1200);
        glVertex2f(1800,1200);
        glEnd();
    //doom
    glBegin(GL_POLYGON);
    glColor3f(0,0.5,0);
    for(i=270;i<451;i++)
        glVertex2f(200*sin(i*PI/180)+1500,400*cos(i*PI/180)+2150);
    glEnd();
    //door
    glColor3f(0.2,0.2,0.2);
    glBegin(GL_POLYGON);
    for(i=270;i<=450;i++)
        glVertex2f(100*sin(i*PI/180)+1500,400*cos(i*PI/180)+500);
    glEnd();
    //windows

   glBegin(GL_POLYGON);
   glColor3f(0,0.5,0);
    for(i=270;i<=450;i++)
        glVertex2f(50*sin(i*PI/180)+1100,200*cos(i*PI/180)+1250);
    glEnd();

    glColor3f(0,0.5,0);
    glBegin(GL_POLYGON);
    for(i=270;i<=450;i++)
        glVertex2f(50*sin(i*PI/180)+1350,200*cos(i*PI/180)+1250);
    glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0,0.5,0);
    for(i=270;i<=450;i++)
        glVertex2f(50*sin(i*PI/180)+1650,200*cos(i*PI/180)+1250);
    glEnd();

        glBegin(GL_POLYGON);
        glColor3f(0,0.5,0);
    for(i=270;i<=450;i++)
        glVertex2f(50*sin(i*PI/180)+1900,200*cos(i*PI/180)+1250);
    glEnd();
    //moon
    glColor3f(1,1,1);
    glPointSize(5.0);
    glBegin(GL_POINTS);
    for(i=130;i<330;i++)
        glVertex2f(80*sin(i*PI/180)+1700,80*cos(i*PI/180)+2700);
    glEnd();
    //left inside window
        glColor3f(0,0.2,0);
        glBegin(GL_POLYGON);
    for(i=270;i<=450;i++)
        glVertex2f(50*sin(i*PI/180)+1300,200*cos(i*PI/180)+800);
    glEnd();
    glColor3f(0,0.2,0);
    glBegin(GL_POLYGON);
    glVertex2f(1250,800);
    glVertex2f(1250,700);
    glVertex2f(1250,700);
    glVertex2f(1350,700);
    glVertex2f(1350,700);
    glVertex2f(1350,800);
    glEnd();

    //right
    glBegin(GL_POLYGON);
    glColor3f(0,0.2,0);
    for(i=270;i<=450;i++)
        glVertex2f(50*sin(i*PI/180)+1700,200*cos(i*PI/180)+800);
    glEnd();
    glColor3f(0,0.2,0);
    glBegin(GL_POLYGON);
    glVertex2f(1650,800);
    glVertex2f(1650,700);
    glVertex2f(1650,700);
    glVertex2f(1750,700);
    glVertex2f(1750,700);
    glVertex2f(1750,800);
    glEnd();
    //star
    int x=1400,y=1900;
  glBegin(GL_POLYGON);
  glColor3f(1,1,1);
  glPointSize(10.0);
  glVertex2f(x+300,y+800);
  glVertex2f(x+320,y+780);
  glVertex2f(x+320,y+780);
  glVertex2f(x+310,y+820);
  glVertex2f(x+310,y+820);
  glVertex2f(x+330,y+840);
  glVertex2f(x+330,y+840);
  glVertex2f(x+305,y+840);
  glVertex2f(x+305,y+840);
  glVertex2f(x+300,y+880); 
  glVertex2f(x+300,y+880); 
  glVertex2f(x+295,y+840);
  glVertex2f(x+295,y+840);
  glVertex2f(x+270,y+840);
  glVertex2f(x+270,y+840);
  glVertex2f(x+290,y+820);
  glVertex2f(x+290,y+820);
  glVertex2f(x+280,y+780);
  glVertex2f(x+280,y+780);
  glVertex2f(x+300,y+800);
  glEnd();
}
void muslim()
{
    //leg
    glColor3f(0.2,0.2,0.2);
    glBegin(GL_POLYGON);
    glVertex2f(500,200);
    glVertex2f(1100,200);
    glVertex2f(1100,200);
    glVertex2f(1000,300);
    glVertex2f(1000,300);
    glVertex2f(500,300);
    glVertex2f(500,300);
    glVertex2f(500,200);
    glEnd();
    //leg
    glBegin(GL_POLYGON);
    glColor3f(1,0.5,0.25);
    glVertex2f(500,200);
    glVertex2f(500,300);
    glVertex2f(500,300);
    glVertex2f(400,200);
    glVertex2f(400,200);
    glVertex2f(500,200);
    glEnd();
    //body
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    for(i=180;i<270;i++)
        glVertex2f(100*sin(i*PI/180)+545,100*cos(i*PI/180)+400);
    //front
    glVertex2f(1000,300);
    glVertex2f(850,800);
    glVertex2f(850,1100);
    glVertex2f(450,1100);
    glVertex2f(450,380);
    glEnd();
    //hand
    glColor3f(1,1,1);
    glBegin(GL_POLYGON);
    glVertex2f(850,800);
    glVertex2f(950,800);
    glVertex2f(950,800);
    glVertex2f(1100,1050);
    glVertex2f(1100,1050);
    glVertex2f(1050,1200);
    glVertex2f(1050,1200);
    glVertex2f(950,1000);
    glVertex2f(950,1000);
    glVertex2f(850,1100);
    glVertex2f(850,1100);
    glVertex2f(850,800);
    glEnd();
    //palm
    glColor3f(1,0.5,0.25);
    glLineWidth(3.0);
    glBegin(GL_LINES);
    glVertex2f(1090,1200);
    glVertex2f(1110,1320);
    glVertex2f(1110,1320);
    glVertex2f(1090,1070);
    glVertex2f(1060,1190);
    glVertex2f(1080,1250);
    glVertex2f(1080,1250);
    glVertex2f(1090,1200);
    glEnd();
    glLineWidth(1.0);
    //shoulder
    glBegin(GL_POLYGON);
    glColor3f(1,1,1);
    for(i=260;i<460;i++)
        glVertex2f(200*sin(i*PI/180)+640,100*cos(i*PI/180)+1110);
    glEnd();
    //face
    glColor3f(1,0.5,0.25);
    glBegin(GL_POLYGON);

    for(i1=140;i1<420;i1++)
        glVertex2f(200*sin(i1*PI/180)+620,150*cos(i1*PI/180)+1360);
    glEnd();
    int x=320,y=370;
    glColor3f(1,0.5,0.25);
    glBegin(GL_POLYGON);
    glVertex2f(x+460,1000+y);
    glVertex2f(x+485,960+y);
    glVertex2f(x+485,960+y);
    glVertex2f(x+450,960+y);
    glVertex2f(x+450,960+y);
    glVertex2f(x+460,1000+y);
    glEnd();
    //hat
    glColor3f(1,1,1);
    glPointSize(3.0);
    glBegin(GL_POLYGON);
    glVertex2f(730,1500);
    glVertex2f(730,1600);
    glVertex2f(730,1600);
    glVertex2f(500,1600);
    glVertex2f(500,1600);
    glVertex2f(500,1500);
    glEnd();
}
void ramzan()
{
        glClear(GL_COLOR_BUFFER_BIT);

        glPushMatrix();
        glScalef(0.9,1,1);
        glTranslatef(500,0,0);
        mosque();
        glPopMatrix();

        glPushMatrix();
        glScalef(0.8,1,1);
        glTranslatef(-100,0,0);
        muslim();
        glPopMatrix();
}
void intro()
{
    glClearColor(0,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,0.0,0.0);
	print("BNM INSTITUTE OF TECHNOLOGY",1,0,0,1000,2700);
	print("MINI PROJECT",5,5,5,1250,2000);
	print("ON",5,5,5,1400,1850);
    print("FESTIVALS OF INDIA",2,2,2,1200,1600);
    print("By",1,1,1,200,550);
    print("PRADYUMNA G",1,1,1,200,300);
    print("1BG15CS069",1,1,1,200,200);
    print("Press",1,1,1,2500,600);
    print("1-Ramzan",1,1,1,2500,400);
    print("2-Diwali",1,1,1,2500,300);
    print("3-Christmas",1,1,1,2500,200);
    print("Q-Exit Terminal",1,1,1,2500,100);
}
void christmas()
{
    glClear(GL_COLOR_BUFFER_BIT);
     background();
    glPushMatrix();
    snow_draw();
    glPopMatrix();
}
void display()
{
    switch(whichScene)
    {
    case 0: intro();break;
    case 1:ramzan();break;
    case 2:diwali();break;
    case 3:christmas();break;
    }
    glFlush();
}
void idle()
{
    if(whichScene==3)
    {
        snow--;
        if(snow<100) snow = 1000;
        glutPostRedisplay();
    }
    if(whichScene==2)
    {
        rotate += 0.5;
        if(rotate>360) rotate -= 360;
        glutPostRedisplay();
    }
}
void keyboard(unsigned char key,int x,int y)
{
    if(key=='1'){
        glClearColor(0.3,0.2,0.2,0);
        whichScene = 1;
        whichInfo = 1;
    }
    if(key=='2'){
        glClearColor(0,0,0.1,0);
        whichScene = 2;
        whichInfo = 2;
    }
    if(key=='3'){
        glClearColor(0,0,0.1,0);
        whichScene = 3;
        whichInfo = 3;
    }
    if(key=='q')
        exit(0);
   glutPostRedisplay();
}
void init()
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,3000,0,3000);
}

int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowSize(1750,650);
    glutCreateWindow("Festivals");
    glutInitWindowPosition(0,0);
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutKeyboardFunc(keyboard);
    init();
    glutMainLoop();
}