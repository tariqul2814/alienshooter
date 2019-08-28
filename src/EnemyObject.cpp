#include <iostream>
#include <stdio.h>
#include<GL/gl.h>
#include <GL/glut.h>
#include <conio.h>
#include<cmath>
#include <windows.h>
#include "EnemyObject.h"
#include <cstdlib>

EnemyObject::EnemyObject()
{
    GetRandomEnemyPos();
}
void EnemyObject::DrawEnemyObject()
{
    if(isHit==true)
    {EnemyObject();
    GetRandomEnemyPos();
    enemyLeftXpos=-0.2f;
    enemyRightXpos=0.2f;
    move_enemy=1.4f;
    isHit=false;
    playerLife=5;
    randomXpos=0.0f;
    DrawEnemyObject();
    DrawEnemyObject2();
    DrawEnemyObject3();
    DrawLevel2EnemyObject();
    void DrawLevel2EnemyObject2();
    void DrawLevel2EnemyObject3();
        return;
    }
    glPushMatrix();
    glTranslatef(randomXpos, move_enemy, 0.0f);
    glPushMatrix();
    glScalef(0.05,0.15,0.0);
    ///head
	glColor3d(105, 107, 99);
	glBegin(GL_POLYGON);
	glVertex2f(0.0f,-1.5f);
	glVertex2f(-0.2f,-0.9f);
	glVertex2f(0.2f,-0.9f);
	glEnd();

	///helmet
	glColor3d(105, 107, 99);
	glBegin(GL_POLYGON);
	glVertex2f(0.0f,-2.0f);
	glVertex2f(-0.4f,-0.9f);
	glVertex2f(0.4f,-0.9f);
	glEnd();





	glColor3ub(105, 107, 99);
	glBegin(GL_POLYGON);
	glVertex2f(-0.3f,-0.9f);
	glVertex2f(-0.5f,-0.5f);
	glVertex2f(0.5f,-0.5f);
	glVertex2f(0.3f,-0.9f);
	glEnd();

	///wingleft
	glColor3ub(242, 9, 32);
	glBegin(GL_POLYGON);
	glVertex2f(-0.3f,-0.9f);
	glVertex2f(-0.5f,-0.5f);
	glVertex2f(-1.5f,-0.3f);
	glVertex2f(-1.2f,-0.9f);
	glEnd();

	///wingright
	glColor3ub(242, 9, 32);
	glBegin(GL_POLYGON);
	glVertex2f(0.3f,-0.9f);
	glVertex2f(0.5f,-0.5f);
	glVertex2f(1.5f,-0.3f);
	glVertex2f(1.2f,-0.9f);
	glEnd();

	///tailbody
	glColor3ub(242, 9, 32);
	glBegin(GL_POLYGON);
	glVertex2f(-0.5f,-0.5f);
	glVertex2f(-0.2f,-0.2f);
	glVertex2f(0.2f,-0.2f);
	glVertex2f(0.5f,-0.5f);
	glEnd();

	///lefttail
	glColor3ub(77, 30, 232);
	glBegin(GL_POLYGON);
	glVertex2f(-0.2f,-0.2f);
	glVertex2f(-0.4f,0.0f);
	glVertex2f(-0.5f,-0.3f);
	glVertex2f(-0.4f,-0.4f);
	glVertex2f(-0.3f,-0.3f);

	glEnd();

	///righttail
	glColor3ub(77, 30, 232);
	glBegin(GL_POLYGON);
	glVertex2f(0.2f,-0.2f);
	glVertex2f(0.4f,0.0f);
	glVertex2f(0.5f,-0.3f);
	glVertex2f(0.4f,-0.4f);
	glVertex2f(0.3f,-0.3f);

	glEnd();

	///leftGun
	glColor3ub(255,255,255);
	glBegin(GL_POLYGON);
	glVertex2f(-1.2f,-0.9f);


	glVertex2f(-0.9f,-1.4f);
	glVertex2f(-0.9f,-1.0f);
	glVertex2f(-0.6f,-0.9f);

	glEnd();

		///rightGun
	glColor3ub(255,255,255);
	glBegin(GL_POLYGON);
	glVertex2f(1.2f,-0.9f);


	glVertex2f(0.9f,-1.4f);
	glVertex2f(0.9f,-1.0f);
	glVertex2f(0.6f,-0.9f);

	glEnd();
    glFlush();

    glPopMatrix();
    glPopMatrix();
}
void EnemyObject::DrawEnemyObject2()
{
    if(isHit==true)
    {
        return;
    }
    glPushMatrix();
    glTranslatef(randomXpos, move_enemy, 0.0f);
    glPushMatrix();
    glScalef(0.045,0.1,0.0);
    ///body
	glColor3ub(46, 17, 122);
	glBegin(GL_POLYGON);
	glVertex2f(0.0f,-1.5f);
	glVertex2f(-0.6f,-1.0f);
	glVertex2f(0.0f,-0.5f);

	glVertex2f(0.6f,-1.0f);



	glEnd();

	glColor3ub(46, 17, 122);
	glBegin(GL_POLYGON);

	glVertex2f(-0.6f,-1.0f);
	glVertex2f(-1.2f,-1.5f);
	glVertex2f(0.0f,-0.5f);



	glVertex2f(0.6f,-1.0f);



	glEnd();

	///leftHorn

	glColor3ub(255,255,255);
	glBegin(GL_POLYGON);

	glVertex2f(-0.6f,-1.0f);
	glVertex2f(-1.5f,0.0f);

	glVertex2f(0.0f,-0.5f);



	//glVertex2f(0.6f,-1.0f);



	glEnd();

	///rightHorn

	glColor3ub(255,255,255);
	glBegin(GL_POLYGON);

	glVertex2f(0.6f,-1.0f);
	glVertex2f(1.5f,0.0f);

	glVertex2f(0.0f,-0.5f);



	//glVertex2f(0.6f,-1.0f);



	glEnd();

	///leftElbow

	glColor3ub(255,255,255);
	glBegin(GL_POLYGON);

	glVertex2f(-0.6f,-1.0f);
	glVertex2f(-1.7f,-0.6f);
	glVertex2f(-1.1f,-1.2f);

	glVertex2f(0.0f,-1.5f);
	glEnd();

	///rightElbow

	glColor3ub(255,255,255);
	glBegin(GL_POLYGON);

	glVertex2f(0.6f,-1.0f);
	glVertex2f(1.7f,-0.6f);
	glVertex2f(1.1f,-1.2f);

	glVertex2f(0.0f,-1.5f);
	glEnd();

	///upperBoxLeft

	glColor3ub(122, 119, 124);
	glBegin(GL_POLYGON);

	glVertex2f(-0.6f,-0.3f);
	glVertex2f(0.0f,-0.5f);





	glVertex2f(0.0f,0.5f);

	glVertex2f(-0.6f,-0.3f);
	glEnd();

	///upperPartLeft

	glColor3ub(54, 50, 255);
	glBegin(GL_POLYGON);





    glVertex2f(-0.6f,-0.3f);

	glVertex2f(0.0f,0.5f);
	glVertex2f(-0.4f,0.8f);
	glVertex2f(-0.8f,-0.25f);



	glEnd();



	///upperBoxRight

	glColor3ub(122, 119, 124);
	glBegin(GL_POLYGON);

	glVertex2f(0.6f,-0.3f);
	glVertex2f(0.0f,-0.5f);





	glVertex2f(0.0f,0.5f);

	glVertex2f(0.6f,-0.3f);
	glEnd();

	///upperPartRight


	glColor3ub(54, 50, 255);
	glBegin(GL_POLYGON);





    glVertex2f(0.6f,-0.3f);

	glVertex2f(0.0f,0.5f);
	glVertex2f(0.4f,0.8f);
	glVertex2f(0.8f,-0.25f);



	glEnd();

	///leftBooster
	glColor3ub(255,255,255);
	glBegin(GL_POLYGON);

	glVertex2f(-1.5f,0.0f);
	glVertex2f(-0.4f,0.8f);
	glVertex2f(-0.6f,0.8f);
	glVertex2f(-1.7f,0.2f);
	glEnd();

	glColor3ub(255, 7, 7);
	glBegin(GL_POLYGON);


	glVertex2f(-0.4f,0.8f);
	glVertex2f(-0.6f,0.8f);
	glVertex2f(-1.6f,0.2f);
	glVertex2f(-1.6f,0.1f);


	glEnd();




	///rightBooster
		glColor3ub(255,255,255);
	glBegin(GL_POLYGON);

	glVertex2f(1.5f,0.0f);
	glVertex2f(0.4f,0.8f);
	glVertex2f(0.6f,0.8f);
	glVertex2f(1.7f,0.2f);
	glEnd();

	glColor3ub(255, 7, 7);
	glBegin(GL_POLYGON);


	glVertex2f(0.4f,0.8f);
	glVertex2f(0.6f,0.8f);
	glVertex2f(1.6f,0.2f);
	glVertex2f(1.6f,0.1f);


	glEnd();

	///leftMaxilla

	glColor3ub(255, 7, 7);
	glBegin(GL_POLYGON);


	glVertex2f(-0.6f,-1.0f);
	glVertex2f(-1.0f,-1.5f);
	glVertex2f(-0.6f,-1.4f);
	glVertex2f(-0.1f,-2.1f);
	glVertex2f(-0.1f,-2.0f);


	glEnd();

	///rightMaxilla

	glColor3ub(255, 7, 7);
	glBegin(GL_POLYGON);


	glVertex2f(0.6f,-1.0f);
	glVertex2f(1.0f,-1.5f);
	glVertex2f(0.6f,-1.4f);
	glVertex2f(0.1f,-2.1f);
	glVertex2f(0.1f,-2.0f);
	glEnd();
    glFlush();
	glPopMatrix();
	glPopMatrix();

}
void EnemyObject::DrawEnemyObject3()
{
    if(isHit==true)
    {
        return;
    }
    glPushMatrix();
    glTranslatef(randomXpos, move_enemy, 0.0f);
    glPushMatrix();
    glScalef(0.05,0.1,0.0);

    ///HeadBumper

	glColor3ub(89, 55, 42);
	glBegin(GL_POLYGON);

	glVertex2f(-1.0f,-0.4f);
	glVertex2f(0.0f,-1.8f);
	glVertex2f(1.0f,-0.4f);

	glEnd();

	///MainBody

	glColor3ub(175, 59, 17);
	glBegin(GL_POLYGON);

	glVertex2f(-1.0f,0.4f);
	glVertex2f(-1.5f,0.1f);
	glVertex2f(-0.15f,-1.0f);
	glVertex2f(0.15f,-1.0f);
	glVertex2f(1.5f,0.1f);
	glVertex2f(1.0f,0.4f);

	glEnd();

	///LeftGun

	glColor3ub(255,255,255);
	glBegin(GL_POLYGON);

	glVertex2f(-1.5f,0.1f);
	glVertex2f(-1.2f,-1.0f);
	glVertex2f(-0.9f,-1.5f);
	glVertex2f(-1.0f,-0.4f);
	glEnd();


	///RightGun

	glColor3ub(255,255,255);
	glBegin(GL_POLYGON);

	glVertex2f(1.5f,0.1f);
	glVertex2f(1.2f,-1.0f);
	glVertex2f(0.9f,-1.5f);
	glVertex2f(1.0f,-0.4f);
	glEnd();

	///window
	glColor3ub(41, 32, 114);
	glBegin(GL_POLYGON);

	glVertex2f(-0.5f,0.0f);
	glVertex2f(-0.1f,-0.8f);
	glVertex2f(0.1f,-0.8f);
	glVertex2f(0.5f,0.0f);
	glEnd();

	///rearBody

	glColor3ub(175, 59, 17);
	glBegin(GL_POLYGON);
	glVertex2f(-1.0f,0.4f);
	glVertex2f(0.0f,1.8f);
	glVertex2f(1.0f,0.4f);
	glEnd();
	glColor3ub(89, 55, 42);
	glBegin(GL_POLYGON);
	glVertex2f(-0.8f,0.4f);
	glVertex2f(-0.09f,1.3f);
	glVertex2f(0.09f,1.3f);
	glVertex2f(0.8f,0.4f);
	glEnd();
	glColor3ub(41, 32, 114);
	glBegin(GL_POLYGON);

	glVertex2f(-0.5f,0.1f);
	glVertex2f(-0.7f,0.3f);
	glVertex2f(-0.07f,1.0f);
	glVertex2f(0.07f,1.0f);
	glVertex2f(0.7f,0.3f);


	glVertex2f(0.5f,0.1f);
	glEnd();
    glFlush();
    glPopMatrix();
    glPopMatrix();
}
void EnemyObject::DrawLevel2EnemyObject()
{
    if(isHit==true)
    {
        return;
    }
    glPushMatrix();
    glTranslatef(randomXpos, move_enemy, 0.0f);
    glPushMatrix();
    glScalef(0.045,0.1,0.0);

	///HeadBumper

	glColor3ub(66, 143, 244);
	glBegin(GL_POLYGON);

	glVertex2f(-1.0f,-0.4f);
	glVertex2f(0.0f,-1.8f);
	glVertex2f(1.0f,-0.4f);

	glEnd();

	///MainBody

	glColor3ub(174, 174, 175);
	glBegin(GL_POLYGON);

	glVertex2f(-1.0f,0.4f);
	glVertex2f(-1.5f,0.1f);
	glVertex2f(-0.15f,-1.0f);
	glVertex2f(0.15f,-1.0f);
	glVertex2f(1.5f,0.1f);
	glVertex2f(1.0f,0.4f);



	glEnd();

	///LeftGun

	glColor3ub(198, 7, 30);
	glBegin(GL_POLYGON);

	glVertex2f(-1.5f,0.1f);
	glVertex2f(-1.2f,-1.0f);
	glVertex2f(-0.9f,-1.5f);
	glVertex2f(-1.0f,-0.4f);
	glEnd();


	///RightGun



	glColor3ub(198, 7, 30);
	glBegin(GL_POLYGON);

	glVertex2f(1.5f,0.1f);
	glVertex2f(1.2f,-1.0f);
	glVertex2f(0.9f,-1.5f);
	glVertex2f(1.0f,-0.4f);
	glEnd();


	///window
	glColor3ub(198, 7, 30);
	glBegin(GL_POLYGON);

	glVertex2f(-0.5f,0.0f);
	glVertex2f(-0.1f,-0.8f);
	glVertex2f(0.1f,-0.8f);


	glVertex2f(0.5f,0.0f);
	glEnd();

	///rearBody

	glColor3ub(7, 117, 196);
	glBegin(GL_POLYGON);

	glVertex2f(-1.0f,0.4f);
	glVertex2f(0.0f,1.8f);
	glVertex2f(1.0f,0.4f);

	glEnd();

	glColor3ub(174, 174, 175);
	glBegin(GL_POLYGON);

	glVertex2f(-0.8f,0.4f);
	glVertex2f(-0.09f,1.3f);
	glVertex2f(0.09f,1.3f);
	glVertex2f(0.8f,0.4f);

	glEnd();

	glColor3ub(41, 32, 114);
	glBegin(GL_POLYGON);

	glVertex2f(-0.5f,0.1f);
	glVertex2f(-0.7f,0.3f);
	glVertex2f(-0.07f,1.0f);
	glVertex2f(0.07f,1.0f);
	glVertex2f(0.7f,0.3f);


	glVertex2f(0.5f,0.1f);
	glEnd();

	glColor3ub(198, 7, 30);
	glBegin(GL_POLYGON);

	glVertex2f(-1.5f,0.1f);
	glVertex2f(-1.2f,1.0f);
	glVertex2f(-0.9f,1.5f);
	glVertex2f(-1.0f,0.4f);
	glEnd();

	glColor3ub(198, 7, 30);
	glBegin(GL_POLYGON);

	glVertex2f(1.5f,0.1f);
	glVertex2f(1.2f,1.0f);
	glVertex2f(0.9f,1.5f);
	glVertex2f(1.0f,0.4f);
	glEnd();
    glFlush();
    glPopMatrix();
}
void EnemyObject::DrawLevel2EnemyObject2()
{
    if(isHit==true)
    {
        return;
    }
    glPushMatrix();
    glTranslatef(randomXpos, move_enemy, 0.0f);
    glPushMatrix();
    glScalef(0.045,0.1,0.0);

	///head
	glColor3ub(224, 184, 8);
	glBegin(GL_POLYGON);
	glVertex2f(0.0f,-1.5f);
	glVertex2f(-0.2f,-0.9f);
	glVertex2f(0.2f,-0.9f);
	glEnd();

	///helmet
	glColor3ub(89, 84, 61);
	glBegin(GL_POLYGON);
	glVertex2f(0.0f,-2.0f);
	glVertex2f(-0.4f,-0.9f);
	glVertex2f(0.4f,-0.9f);
	glEnd();





	glColor3ub(142, 125, 45);
	glBegin(GL_POLYGON);
	glVertex2f(-0.3f,-0.9f);
	glVertex2f(-0.5f,-0.5f);
	glVertex2f(0.5f,-0.5f);
	glVertex2f(0.3f,-0.9f);
	glEnd();

	///wingleft
	glColor3ub(173, 167, 140);
	glBegin(GL_POLYGON);
	glVertex2f(-0.3f,-0.9f);
	glVertex2f(-0.5f,-0.5f);
	glVertex2f(-1.8f,-0.3f);
	glVertex2f(-1.2f,-0.9f);
	glEnd();

	///wingright
	glColor3ub(173, 167, 140);
	glBegin(GL_POLYGON);
	glVertex2f(0.3f,-0.9f);
	glVertex2f(0.5f,-0.5f);
	glVertex2f(1.8f,-0.3f);
	glVertex2f(1.2f,-0.9f);
	glEnd();

	///tailbody
	glColor3ub(173, 167, 140);
	glBegin(GL_POLYGON);
	glVertex2f(-0.5f,-0.5f);
	glVertex2f(-0.2f,-0.2f);
	glVertex2f(0.2f,-0.2f);
	glVertex2f(0.5f,-0.5f);
	glEnd();

	///lefttail
	glColor3ub(89, 84, 61);
	glBegin(GL_POLYGON);
	glVertex2f(-0.2f,-0.2f);
	glVertex2f(-0.4f,0.4f);
	glVertex2f(-0.7f,-0.3f);
	glVertex2f(-0.4f,-0.4f);
	glVertex2f(-0.3f,-0.3f);

	glEnd();

	///righttail
	glColor3ub(89, 84, 61);
	glBegin(GL_POLYGON);
	glVertex2f(0.2f,-0.2f);
	glVertex2f(0.4f,0.4f);
	glVertex2f(0.7f,-0.3f);
	glVertex2f(0.4f,-0.4f);
	glVertex2f(0.3f,-0.3f);

	glEnd();

	///leftGun
	glColor3ub(224, 184, 8);
	glBegin(GL_POLYGON);
	glVertex2f(-1.2f,-0.9f);


	glVertex2f(-0.6f,-1.9f);
	glVertex2f(-0.8f,-1.0f);
	glVertex2f(-0.6f,-0.9f);

	glEnd();

		///rightGun
	glColor3ub(224, 184, 8);
	glBegin(GL_POLYGON);
	glVertex2f(1.2f,-0.9f);


	glVertex2f(0.6f,-1.9f);
	glVertex2f(0.8f,-1.0f);
	glVertex2f(0.6f,-0.9f);

	glEnd();
    glFlush();
    glPopMatrix();
}
void EnemyObject::DrawLevel2EnemyObject3()
{
     if(isHit==true)
    {
        return;
    }
    glPushMatrix();
    glTranslatef(randomXpos, move_enemy, 0.0f);
    glPushMatrix();
    glScalef(0.045,0.1,0.0);

	///body



	glColor3ub(45, 119, 105);
	glBegin(GL_POLYGON);
	glVertex2f(0.0f,-1.5f);
	glVertex2f(-0.6f,-1.0f);
	glVertex2f(0.0f,-0.5f);



	glVertex2f(0.6f,-1.0f);



	glEnd();

	glColor3ub(45, 119, 105);
	glBegin(GL_POLYGON);

	glVertex2f(-0.6f,-1.0f);
	glVertex2f(-1.2f,-1.5f);
	glVertex2f(0.0f,-0.5f);



	glVertex2f(0.6f,-1.0f);



	glEnd();

	///leftHorn

	glColor3ub(68, 221, 192);
	glBegin(GL_POLYGON);

	glVertex2f(-0.6f,-1.0f);
	glVertex2f(-1.5f,0.0f);

	glVertex2f(0.0f,-0.5f);



	glEnd();

	///rightHorn

	glColor3ub(68, 221, 192);
	glBegin(GL_POLYGON);

	glVertex2f(0.6f,-1.0f);
	glVertex2f(1.5f,0.0f);

	glVertex2f(0.0f,-0.5f);



	glEnd();

	///leftElbow

	glColor3ub(68, 221, 192);
	glBegin(GL_POLYGON);

	glVertex2f(-0.6f,-1.0f);
	glVertex2f(-1.7f,-0.6f);
	glVertex2f(-1.1f,-1.2f);

	glVertex2f(0.0f,-1.5f);
	glEnd();

	///rightElbow

	glColor3ub(68, 221, 192);
	glBegin(GL_POLYGON);

	glVertex2f(0.6f,-1.0f);
	glVertex2f(1.7f,-0.6f);
	glVertex2f(1.1f,-1.2f);

	glVertex2f(0.0f,-1.5f);
	glEnd();

	///upperBoxLeft

	glColor3ub(122, 119, 124);
	glBegin(GL_POLYGON);

	glVertex2f(-0.6f,-0.3f);
	glVertex2f(0.0f,-0.5f);

	glVertex2f(0.0f,0.5f);

	glVertex2f(-0.6f,-0.3f);
	glEnd();

	///upperPartLeft

	glColor3ub(45, 119, 105);
	glBegin(GL_POLYGON);


    glVertex2f(-0.6f,-0.3f);

	glVertex2f(0.0f,0.5f);
	glVertex2f(-0.4f,0.8f);
	glVertex2f(-0.8f,-0.25f);



	glEnd();



	///upperBoxRight

	glColor3ub(122, 119, 124);
	glBegin(GL_POLYGON);

	glVertex2f(0.6f,-0.3f);
	glVertex2f(0.0f,-0.5f);

	glVertex2f(0.0f,0.5f);

	glVertex2f(0.6f,-0.3f);
	glEnd();

	///upperPartRight


	glColor3ub(45, 119, 105);
	glBegin(GL_POLYGON);

    glVertex2f(0.6f,-0.3f);

	glVertex2f(0.0f,0.5f);
	glVertex2f(0.4f,0.8f);
	glVertex2f(0.8f,-0.25f);

	glEnd();

	///leftBooster
	glColor3ub(68, 221, 192);
	glBegin(GL_POLYGON);

	glVertex2f(-1.5f,0.0f);
	glVertex2f(-0.4f,0.8f);
	glVertex2f(-0.6f,0.8f);
	glVertex2f(-1.7f,0.2f);
	glEnd();

	glColor3ub(247, 98, 12);
	glBegin(GL_POLYGON);


	glVertex2f(-0.4f,0.8f);
	glVertex2f(-0.6f,0.8f);
	glVertex2f(-1.6f,0.2f);
	glVertex2f(-1.6f,0.1f);


	glEnd();


	///rightBooster
		glColor3ub(68, 221, 192);
	glBegin(GL_POLYGON);

	glVertex2f(1.5f,0.0f);
	glVertex2f(0.4f,0.8f);
	glVertex2f(0.6f,0.8f);
	glVertex2f(1.7f,0.2f);
	glEnd();

	glColor3ub(247, 98, 12);
	glBegin(GL_POLYGON);


	glVertex2f(0.4f,0.8f);
	glVertex2f(0.6f,0.8f);
	glVertex2f(1.6f,0.2f);
	glVertex2f(1.6f,0.1f);


	glEnd();

	///leftMaxilla

	glColor3ub(247, 98, 12);
	glBegin(GL_POLYGON);


	glVertex2f(-0.6f,-1.0f);
	glVertex2f(-1.3f,-1.5f);
	glVertex2f(-0.7f,-1.4f);
	glVertex2f(-0.3f,-2.1f);
	glVertex2f(-0.3f,-2.0f);

	glEnd();

	///rightMaxilla

	glColor3ub(247, 98, 12);
	glBegin(GL_POLYGON);


	glVertex2f(0.6f,-1.0f);
	glVertex2f(1.3f,-1.5f);
	glVertex2f(0.7f,-1.4f);
	glVertex2f(0.3f,-2.1f);
	glVertex2f(0.3f,-2.0f);


	glEnd();

    glFlush();
    glPopMatrix();
}
float EnemyObject::GetRandomEnemyPos()
{
    randomXpos= -1.0 + static_cast <float> (rand()) /( static_cast <float> (RAND_MAX/(1.0-(-1.0))));
    if(randomXpos+0.3f>1.0f || randomXpos-0.3<-1.0f )
    {
        GetRandomEnemyPos();
    }
    return randomXpos;
}

