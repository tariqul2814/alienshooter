#include <iostream>
#include <stdio.h>
#include<GL/gl.h>
#include <GL/glut.h>
#include <conio.h>
#include <windows.h>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <process.h>
#include <time.h>
#include<cmath>
#include "EnemyObject.h"

void display();
///prototypes
void CheckDeadEnemy();
void DrawPlayer();
void DrawEnemies();
void DrawEnvironmentObjects();
void DrawStarTool();
void CheckBossBattle();
void DrawLifeLine();
void CheckLifeLineHit();
void ResetGame();
///declarations objects

EnemyObject *enemy1=new EnemyObject;
EnemyObject *enemy2=new EnemyObject;
EnemyObject *enemy3=new EnemyObject;
//Boss *b1 = new Boss;
//Boss *b2 = new Boss;
//TextElements text;
///declarations booleans
bool createEnemy1=true;
bool createEnemy2=true;
bool createEnemy3=true;
bool loadBoss=false;
bool isPaused=true;
bool createNewLifeLine=false;
bool isMainMenu=true;
bool loadLevel1=false;
bool loadLevel2=false;
bool isControlScreen=false;
bool lost=false;
bool win=false;
///declarations floats
float randomEnemy1StartPos=0.0f;
float randomEnemy2StartPos=0.0f;
float randomEnemy3StartPos=0.0f;
///declarations integers
int lifeCount=5;
int bossLifeCount=5;
int enemyCounter=0;
int mainMenuSelector=1;
int score=0;
int enemyLimit=15;

///Player Object
float move_player=0.0f;
bool isLaser=false;
float laser1PositionX=-1.3f;//-0.7f,-0.4f
float laser1PositionY=15.4f;
float laser2PositionX=1.3f;//0.7f,0.4f
float laser2PositionY=15.4f;

/// End;
int timetracker = 0;
int timecounter = 0;



char sco[10]="Score: ";
void renderbitmap(float x, float y, void *font, char *str);
void init()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glOrtho(-90.0,100.0,-15.0,100.0,0.0,1.0);
}

void introscreen()
{
	glColor3f(1.0f,1.0f,1.0f);
	//int i = 151;
	char buf[1000];
	snprintf(buf, sizeof(buf), "%d", score);
	renderbitmap(-80,40,GLUT_BITMAP_TIMES_ROMAN_24,sco);
	renderbitmap(-30,40,GLUT_BITMAP_TIMES_ROMAN_24,buf);

}


void display1()
{
    introscreen();
    glFlush();
    glutPostRedisplay();
}

void renderbitmap(float x, float y, void *font, char *str)
{
	char *c;
	glRasterPos2f(x,y);
	for(c = str; *c!='\0'; c++)
	{
		glutBitmapCharacter(font,*c);
	}
}

void DrawScore(int score)
{
    char scoreText[20]="Score: ";
    char buf[1000];
	snprintf(buf, sizeof(buf), "%d", score);
    strcat(scoreText,buf);
   // int i;
    glColor3ub(0,255,0);
    //glRasterPos2f(-0.05f,0.95f);
    renderbitmap(-0.05f,0.95,GLUT_BITMAP_TIMES_ROMAN_24,scoreText);

}



///enemy death checker///
void CheckDeadEnemy()
{
    if(move_player>=enemy1->randomXpos-0.2f && move_player<=enemy1->randomXpos+0.2f && enemy1->move_enemy<=1.3f)
    {
        enemy1->isHit=true;
        enemyCounter++;
        score+=10;
    }
    if(move_player>=enemy2->randomXpos-0.2f && move_player<=enemy2->randomXpos+0.2f && enemy1->move_enemy<=1.3f)
    {
        enemy2->isHit=true;
        enemyCounter++;
        score+=10;
    }
    if(move_player>=enemy3->randomXpos-0.2f && move_player<=enemy3->randomXpos+0.2f && enemy1->move_enemy<=1.3f)
    {
        enemy3->isHit=true;
        enemyCounter++;
        score+=10;
    }

    if(!loadBoss)
    {
        if(enemy1->isHit==true)
        {
            createEnemy1=true;
        }
        if(enemy2->isHit==true)
        {
            createEnemy2=true;
        }
        if(enemy3->isHit==true)
        {
            createEnemy3=true;
        }
    }

    if(enemyCounter>enemyLimit)///number of enemies in the level
    {
        loadBoss=true;
    }
}

///movement///
void UpdateEnemy(int value)
{
    timetracker+=20;
    /*if(timetracker>=20)
    {
        isPaused = false;
        return;
    }*/
    enemy1->move_enemy-=0.01f;
    enemy2->move_enemy-=0.01f;
    enemy3->move_enemy-=0.02f;
    if(enemy1->move_enemy<-1.0f)
    {
        createEnemy1=true;

    }
    if(enemy1->move_enemy<=-0.4f && move_player>=enemy1->randomXpos-0.2f && move_player<=enemy1->randomXpos+0.2f)
    {
        enemy1->isHit=true;
        createEnemy1=true;
    }
    if(enemy2->move_enemy<-1.0f)
    {
        createEnemy2=true;
    }
    if(enemy2->move_enemy<=-0.45f && move_player>=enemy2->randomXpos-0.2f && move_player<=enemy2->randomXpos+0.2f)
    {
        enemy2->isHit=true;
        createEnemy2=true;
    }
    if(enemy3->move_enemy<-1.0f)
    {
        createEnemy3=true;
    }
    if(enemy3->move_enemy<=-0.45f && move_player>=enemy3->randomXpos-0.2f && move_player<=enemy3->randomXpos+0.2f)
    {
        enemy3->isHit=true;
        createEnemy3=true;
    }


    glutPostRedisplay();
    if(timetracker<=30000)
    glutTimerFunc(20, UpdateEnemy, 0);
    else
    {
        isPaused=false;
    }
}

///Draw Enemy Object///
void DrawEnemies()
{

    if(createEnemy1)
    {
        enemy1=new EnemyObject;
        createEnemy1=false;
    }
    if(createEnemy2)
    {
        enemy2=new EnemyObject;
        createEnemy2=false;
    }
    if(createEnemy3)
    {
        enemy3=new EnemyObject;
        createEnemy3=false;
    }
    glPushMatrix();
    enemy1->DrawEnemyObject();
    glPopMatrix();

    glPushMatrix();
    enemy2->DrawEnemyObject2();
    glPopMatrix();

    glPushMatrix();
    enemy3->DrawEnemyObject3();
    glPopMatrix();


}

///end;
void laseroff(int i)
{
    if(i==0)
    {
        isLaser=false;
    }
    glutPostRedisplay();
}

///keyboard general
static void KeyboardActions(unsigned char key, int x, int y)
{
    int track = 0;
    track = (int) key;
    if(key=='a')
    {
        move_player-=0.03;
        if(move_player<-1.0)
        {
            move_player=1.0;
        }
    }
    else if(key=='d')
    {
        move_player+=0.03;
        if(move_player>1.0)
        {
            move_player=-1.0;
        }
    }
    else if(key=='f')
    {
        isLaser=true;
        CheckDeadEnemy();
        glutTimerFunc(40, laseroff, 0);

    }
    else if(key=='F')
    {
        isLaser=true;
        glutTimerFunc(40, laseroff, 0);
    }
    else if(track==27)
    {
        exit(0);
    }
    glutPostRedisplay();
}

void playerobject()
{
    glTranslatef(move_player, -0.8f, 0.0f);
    glScalef(0.05f,0.12f,0.0f);
    ///body
    glColor3ub(226, 0, 0);
    glBegin(GL_POLYGON);
    glVertex2f(0.0f,1.5f);
    glVertex2f(-1.5f,-0.8f);
    glVertex2f(1.5f,-0.8f);

    glEnd();

    glColor3ub(48, 127, 48);
    glBegin(GL_POLYGON);

    glEnd();

    glColor3ub(48, 127, 48);
    glBegin(GL_POLYGON);

    glVertex2f(1.5f,-0.8f);
    glVertex2f(1.7f,0.0f);
    glVertex2f(0.0f,1.5f);

    glEnd();

    glColor3ub(48, 127, 48);
    glBegin(GL_POLYGON);

    glVertex2f(-1.5f,-0.8f);
    glVertex2f(-1.7f,0.0f);
    glVertex2f(0.0f,1.5f);

    glEnd();

    glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
    glVertex2f(0.0f,1.5f);
    glVertex2f(-0.6f,1.0f);
    glVertex2f(-0.1f,0.9f);
    glVertex2f(-0.1f,0.2f);
    glVertex2f(0.1f,0.2f);
    glVertex2f(0.1f,0.9f);


    glVertex2f(0.6f,1.0f);



    glEnd();
    ///head

    glColor3ub(255,255,255);
    glBegin(GL_POLYGON);
    glVertex2f(-0.1f,0.2f);
    glVertex2f(-0.6f,-0.8f);
    glVertex2f(0.6f,-0.8f);
    glVertex2f(0.1f,0.2f);




    glEnd();

    glColor3ub(255,255,255);
    glBegin(GL_POLYGON);

    glVertex2f(-0.6f,-0.8f);
    glVertex2f(-0.2f,-1.4f);
    glVertex2f(0.2f,-1.4f);
    glVertex2f(0.6f,-0.8f);





    glEnd();

    ///window
    glColor3ub(48, 42, 42);
    glBegin(GL_POLYGON);


    glVertex2f(-0.2f,-1.4f);
    glVertex2f(-0.2f,-0.8f);
    glVertex2f(0.0f,-0.9f);
    glVertex2f(0.2f,-0.8f);
    glVertex2f(0.2f,-1.4f);





    glEnd();

    glColor3ub(48, 42, 42);
    glBegin(GL_POLYGON);



    glVertex2f(-0.2f,-0.7f);
    glVertex2f(0.0f,-0.8f);
    glVertex2f(0.2f,-0.7f);

    glVertex2f(0.2f,-0.2f);
    glVertex2f(0.0f,-0.1f);
    glVertex2f(-0.2f,-0.2f);





    glEnd();

    ///leftWing

    glColor3ub(51, 20, 229);
    glBegin(GL_POLYGON);


    glVertex2f(-0.6f,1.0f);
    glVertex2f(-1.7f,0.0f);
    glVertex2f(-1.3f,0.0f);
    glEnd();

    glColor3ub(51, 20, 229);
    glBegin(GL_POLYGON);


    glVertex2f(-0.6f,1.0f);
    glVertex2f(-1.3f,0.5f);
    glVertex2f(-1.0f,0.5f);

    glVertex2f(-0.1f,0.2f);
    glVertex2f(-0.1f,0.9f);


    glEnd();

    glColor3ub(249, 221, 4);
    glBegin(GL_POLYGON);


    glVertex2f(-0.6f,-0.8f);
    glVertex2f(-0.8f,-0.8f);
    glVertex2f(-0.8f,0.0f);
    glVertex2f(-0.1f,0.9f);
    glEnd();

    ///leftGun

    glColor3ub(249, 221, 4);
    glBegin(GL_POLYGON);
    glVertex2f(-0.6f,1.0f);
    glVertex2f(-0.6f,1.4f);
    glVertex2f(-0.8f,1.1f);
    glVertex2f(-1.3f,0.5f);

    glEnd();

    glColor3ub(239, 222, 110);
    glBegin(GL_POLYGON);



    glVertex2f(-1.7f,0.0f);
    glVertex2f(-1.4f,0.9f);

    glVertex2f(-1.4f,0.25f);

    glEnd();






    ///rightWing

    glColor3ub(51, 20, 229);
    glBegin(GL_POLYGON);


    glVertex2f(0.6f,1.0f);
    glVertex2f(1.7f,0.0f);
    glVertex2f(1.3f,0.0f);
    glEnd();

    glColor3ub(51, 20, 229);
    glBegin(GL_POLYGON);


    glVertex2f(0.6f,1.0f);
    glVertex2f(1.3f,0.5f);
    glVertex2f(1.0f,0.5f);

    glVertex2f(0.1f,0.2f);
    glVertex2f(0.1f,0.9f);


    glEnd();

    glColor3ub(249, 221, 4);
    glBegin(GL_POLYGON);


    glVertex2f(0.6f,-0.8f);
    glVertex2f(0.8f,-0.8f);
    glVertex2f(0.8f,0.0f);
    glVertex2f(0.1f,0.9f);
    glEnd();

    ///rightGun

    glColor3ub(249, 221, 4);
    glBegin(GL_POLYGON);
    glVertex2f(0.6f,1.0f);
    glVertex2f(0.6f,1.4f);
    glVertex2f(0.8f,1.1f);
    glVertex2f(1.3f,0.5f);

    glEnd();

    glColor3ub(239, 222, 110);
    glBegin(GL_POLYGON);



    glVertex2f(1.7f,0.0f);
    glVertex2f(1.4f,0.9f);

    glVertex2f(1.4f,0.25f);

    glEnd();

    ///tailBody

    glColor3ub(249, 221, 4);
    glBegin(GL_POLYGON);


    glVertex2f(-0.6f,-0.8f);
    glVertex2f(-0.8f,-0.8f);
    glVertex2f(-0.9f,-1.0f);
    glVertex2f(-0.2f,-1.8f);


    glEnd();

    glColor3ub(249, 221, 4);
    glBegin(GL_POLYGON);


    glVertex2f(0.6f,-0.8f);
    glVertex2f(0.8f,-0.8f);
    glVertex2f(0.9f,-1.0f);
    glVertex2f(0.2f,-1.8f);


    glEnd();
    glFlush();

    if(isLaser==true)
    {
        glLineWidth(5);
        glColor3ub(255,0,0);
        glScalef(1.0f,1.0f,0.0f);
        glBegin(GL_LINES);
        glVertex2f(-1.3f,0.5f);
        glVertex2f(laser1PositionX,laser1PositionY);
        glVertex2f(1.3f,0.5f);
        glVertex2f(laser2PositionX,laser2PositionY);
        glEnd();
        glFlush();
    }
    glLineWidth(1);

}

void display ()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);


    if(isPaused)
    {
        glLoadIdentity();
        glPushMatrix();
        playerobject();
        glPopMatrix();
        DrawScore(score);
        DrawEnemies();
    }

    else
    {
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize(320,320);
        glutInitWindowPosition(30,30);
        glutCreateWindow("Display");

        init();


        glutDisplayFunc(display1);
    }



}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutCreateWindow("OpenGL Setup Test");
    glutInitWindowSize(320,320);
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(KeyboardActions);
    if(isPaused)
    UpdateEnemy(0);
    glutFullScreen();
    sndPlaySound("Stratosphere.wav",SND_ASYNC|SND_LOOP);
    glutMainLoop();
    return 0;

}
