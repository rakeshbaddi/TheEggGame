#include<stdio.h>
#include<GL/glut.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int eggs_caught=0, missed_eggs=0, level_count=1, points=0;
int p=0;    // for incrementing the points based on color
int d=0;    // for color selection
int egg_xc,egg_yc;  // for coordinates of egg
int basket_x,basket_y;  // for coordinates of basket
int a=500,b=500;    // for default size of the screen
int s=0;    // for menu option
int dropped_eggs=0;
int speed_1=1, speed_2=2, speed_3=3, speed_4=4;
int orange_egg=0, white_egg=0, pink_egg=0, yellow_egg=0, gray_egg=0, green_egg=0;
int w=48, h=48, t=10, e=9, g=12;


void myinit();
void start_screen(int,int);
void egg();
void basket(int,int);
void duck(int,int);
void print_score();
void egg_start();
void color();
void score();
void display(void);
void basket_set(int,int);
void myReshape(int,int);
void keys(unsigned char,int,int);
void menu(int);


void myinit()
{
    glViewport(0,0,a,b);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,(GLdouble)a,0,(GLdouble)b);
    glMatrixMode(GL_MODELVIEW);
    glutPostRedisplay();
}

void start_screen(int i,int j)
{
    int k;
    char cat[7]="-CATCH", or[3]="OR", hatch[7]="HATCH";
    glColor3f(0,1,0);
    glRasterPos2i(250,180);

    for(k=0;k<7;k++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,cat[k]);

    glColor3f(1,1,1);
    glRasterPos2i(345,180);

    for(k=0;k<3;k++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,or[k]);

    glColor3f(1,0,0);
    glRasterPos2i(390,180);

    for(k=0;k<7;k++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,hatch[k]);

    glColor3f(1,1,0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(i,j);
    glVertex2f(i+w,j);
    glVertex2f(i+w,j+t);
    glVertex2f(i+t,j+t);
    glVertex2f(i+t,j+t+e);
    glVertex2f(i+t+2*e,j+t+e);
    glVertex2f(i+t+2*e,j+2*t+e);
    glVertex2f(i+t,j+2*t+e);
    glVertex2f(i+t,j+2*t+2*e);
    glVertex2f(i+w,j+2*t+2*e);
    glVertex2f(i+w,j+h);
    glVertex2f(i,j+h);
    glEnd();
    glFlush();
    i+=g+w;

    glBegin(GL_LINE_LOOP);
    glVertex2f(i,j);
    glVertex2f(i+w,j);
    glVertex2f(i+w,j+h/2);
    glVertex2f(i+w/2-t/2,j+h/2);
    glVertex2f(i+w/2-t/2,j+h/2-3*t/4);
    glVertex2f(i+w-t,j+h/2-3*t/4);
    glVertex2f(i+w-t,j+t);
    glVertex2f(i+t,j+t);
    glVertex2f(i+t,j+h-t);
    glVertex2f(i+w,j+h-t);
    glVertex2f(i+w,j+h);
    glVertex2f(i,j+h);
    glEnd();
    glFlush();
    i+=g+w;

    glBegin(GL_LINE_LOOP);
    glVertex2f(i,j);
    glVertex2f(i+w,j);
    glVertex2f(i+w,j+h/2);
    glVertex2f(i+w/2-t/2,j+h/2);
    glVertex2f(i+w/2-t/2,j+h/2-3*t/4);
    glVertex2f(i+w-t,j+h/2-3*t/4);
    glVertex2f(i+w-t,j+t);
    glVertex2f(i+t,j+t);
    glVertex2f(i+t,j+h-t);
    glVertex2f(i+w,j+h-t);
    glVertex2f(i+w,j+h);
    glVertex2f(i,j+h);
    glEnd();
    glFlush();
    i+=g+w;
    j-=g+h;

    glBegin(GL_LINE_LOOP);
    glVertex2f(i,j);
    glVertex2f(i+w,j);
    glVertex2f(i+w,j+h/2);
    glVertex2f(i+w/2-t/2,j+h/2);
    glVertex2f(i+w/2-t/2,j+h/2-3*t/4);
    glVertex2f(i+w-t,j+h/2-3*t/4);
    glVertex2f(i+w-t,j+t);
    glVertex2f(i+t,j+t);
    glVertex2f(i+t,j+h-t);
    glVertex2f(i+w,j+h-t);
    glVertex2f(i+w,j+h);
    glVertex2f(i,j+h);
    glEnd();
    glFlush();
    i+=g+w;

    glBegin(GL_LINE_LOOP);
    glVertex2f(i,j);
    glVertex2f(i+t,j);
    glVertex2f(i+w/2-3*t/4,j+h/2-t);
    glVertex2f(i+w/2+3*t/4,j+h/2-t);
    glVertex2f(i+w-t,j);
    glVertex2f(i+w,j);
    glVertex2f(i+w/2+t/2,j+h);
    glVertex2f(i+w/2-t/2,j+h);
    glEnd();
    glBegin(GL_LINE_LOOP);
    glVertex2f(i+w/2,j+h-t);
    glVertex2f(i+w/2-t/2,j+h/2);
    glVertex2f(i+w/2+t/2,j+h/2);
    glEnd();
    i+=g+w;

    glBegin(GL_LINE_LOOP);
    glVertex2f(i,j);
    glVertex2f(i+t,j);
    glVertex2f(i+t,j+h-2*t);
    glVertex2f(i+w/2,j+t/2);
    glVertex2f(i+w-t,j+h-2*t);
    glVertex2f(i+w-t,j);
    glVertex2f(i+w,j);
    glVertex2f(i+w,j+h);
    glVertex2f(i+w-t,j+h);
    glVertex2f(i+w/2,j+h/2);
    glVertex2f(i+t,j+h);
    glVertex2f(i,j+h);
    glEnd();
    i+=g+w;

    glBegin(GL_LINE_LOOP);
    glVertex2f(i,j);
    glVertex2f(i+w,j);
    glVertex2f(i+w,j+t);
    glVertex2f(i+t,j+t);
    glVertex2f(i+t,j+t+e);
    glVertex2f(i+t+2*e,j+t+e);
    glVertex2f(i+t+2*e,j+2*t+e);
    glVertex2f(i+t,j+2*t+e);
    glVertex2f(i+t,j+2*t+2*e);
    glVertex2f(i+w,j+2*t+2*e);
    glVertex2f(i+w,j+h);
    glVertex2f(i,j+h);
    glEnd();
    glFlush();

    glColor3f(1,1,1);
    egg_xc=375;
    egg_yc=370;
    egg();
    duck(70,330);
    basket(330,0);
}

void egg()
{
    float x,y,z;
    int t;
    glBegin(GL_POLYGON);

    for(t=0;t<=360;t+=1)
    {
        x = egg_xc+8*(cos(t));
        y = egg_yc+16*(sin(t));
        z = 0;
        glVertex3f(x,y,z);
    }

    glEnd();
}

void basket(int i,int j)
{
    j=10;

    if(i>=a-60)i=a-60;
        glColor3f(1.0,0.0,0.0);

    glBegin(GL_QUADS);
    glVertex2f(0.0+i,30.0+j);
    glVertex2f(10.0+i,10.0+j);
    glVertex2f(50.0+i,10.0+j);
    glVertex2f(60.0+i,30.0+j);
    glEnd();
}

void duck(int i,int j)
{
    int h;
    glColor3f(1.0,1.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(45+i,45+j);
    glVertex2f(70+i,20+j);
    glVertex2f(95+i,20+j);
    glVertex2f(120+i,45+j);
    glVertex2f(95+i,70+j);
    glVertex2f(70+i,70+j);
    glVertex2f(95+i,95+j);
    glVertex2f(82.5+i,107.5+j);
    glVertex2f(32.5+i,57.5+j);
    glEnd();
    glFlush();
    for(h=0;h<13;h+=4)
    {
        glBegin(GL_LINES);
        glColor3f(0.7,0.4,0);
        glVertex2f(57.5+h+i,52.5+h+j);
        glVertex2f(100+h+i,30+h+j);
        glEnd();
        glFlush();
    }

    glColor3f(0.0,1.0,0.0);
    glBegin(GL_POLYGON);
    glVertex2f(82.5+i,107.5+j);
    glVertex2f(65+i,107.5+j);
    glVertex2f(50+i,95+j);
    glVertex2f(70+i,95+j);
    glEnd();
    glFlush();

    glColor3f(0.0,0.0,0.0);
    glPointSize(5);
    glBegin(GL_POINTS);
    glVertex2f(76+i,101+j);
    glEnd();

    glColor3f(0.0,1.0,0.0);
    glBegin(GL_LINE_LOOP);
    glVertex2f(72.5+i,107.5+j);
    glVertex2f(67.5+i,112.5+j);
    glVertex2f(72.5+i,110+j);
    glVertex2f(77.5+i,112.5+j);
    glEnd();
    glFlush();
}

void print_score()
{
    printf("\nLevel reached: %d\n\n",level_count);
    printf("\nNo. of eggs dropped= %d \n",dropped_eggs+gray_egg);
    printf("\nNo. of eggs caught = %d\n",eggs_caught+gray_egg);
    printf("\nNo. of eggs missed = %d\n",missed_eggs);
    printf("\nwhite eggs = %d\tpoints gained = %d\n",white_egg,white_egg);
    printf("\norange eggs = %d\tpoints gained = %d\n",orange_egg,orange_egg*5);
    printf("\ngreen eggs = %d\tpoints gained = %d\n",green_egg,green_egg*10);
    printf("\npink eggs= %d\tpoints gained = %d\n",pink_egg,pink_egg*15);
    printf("\nYellow eggs = %d\tpoints gained = %d\n\n",yellow_egg,yellow_egg*100);
    printf("\ngray eggs= %d\tpoints deducted = %d\n",gray_egg,gray_egg*50);
    printf("\n\n\nyour score=%d\n\n",points);
    getchar();
    exit(0);
}

void egg_start()
{
    egg_yc=375;
    if(missed_eggs>=10)
    {
        printf("\n\n\t\t\t\tGAME OVER\n\n");
        print_score();
    }

    dropped_eggs++;
    if(d==4)
        dropped_eggs--;

    switch(rand()%9)
    {
    case 0:egg_xc=105;d=rand()%6; break;
    case 1:egg_xc=245;d=rand()%6; break;
    case 2:egg_xc=380;d=rand()%6; break;
    case 5:egg_xc=105;d=rand()%6; break;
    case 3:egg_xc=245;d=rand()%6; break;
    case 4:egg_xc=380;d=rand()%6; break;
    case 7:egg_xc=105;d=rand()%6; break;
    case 6:egg_xc=245;d=rand()%6; break;
    case 8:egg_xc=380;d=rand()%6; break;
    }
}

void color()
{
    switch(d)
    {
        case 3:glColor3f(1,0.4,0);p=5;break; //orange
        case 2:glColor3f(0,1,0);p=10;break; //green
        case 4:glColor3f(0.2,0.2,0.2);p=-50;break; //gray
        case 5:glColor3f(1,1,1);p=1;break; //white
        case 0:glColor3f(1,0,1);p=15;break; //pink
        case 1:glColor3f(1,1,0);p=100;break; //yellow
    }
}

void score()
{
    if(egg_yc<=50 && (egg_xc>=basket_x&&egg_xc<=basket_x+60))
    {
        printf("\a");
        eggs_caught++;
        switch(d)
        {
            case 0: pink_egg++;break;
            case 1: yellow_egg++;break;
            case 2: green_egg++;break;
            case 3: orange_egg++;break;
            case 4: gray_egg++;eggs_caught--;break;
            case 5: white_egg++;break;
        }
        points+=p;
        egg_yc=-10;
    }
    missed_eggs=dropped_eggs-eggs_caught;
}

void display(void)
{
    int i;
    char level1[12]="LEVEL 1";
    char level2[12]="LEVEL 2";
    char level3[12]="LEVEL 3";
    char level4[12]="LEVEL 4";

    glClear(GL_COLOR_BUFFER_BIT);
    if(s>=1)
    {
        if(level_count==1)
        {
            glColor3f(1,1,1);
            glRasterPos2i(400,300);
            for(i=0;i<12;i++)
                glutBitmapCharacter(GLUT_BITMAP_8_BY_13,level1[i]);
        }
        else if(level_count==2)
        {
            glColor3f(1,1,1);
            glRasterPos2i(400,300);
            for(i=0;i<12;i++)
                glutBitmapCharacter(GLUT_BITMAP_8_BY_13,level2[i]);
        }
        else if(level_count==3)
        {
            glColor3f(1,1,1);
            glRasterPos2i(400,300);
            for(i=0;i<12;i++)
                glutBitmapCharacter(GLUT_BITMAP_8_BY_13,level3[i]);
        }
        if(level_count==4)
        {
            glColor3f(1,1,1);
            glRasterPos2i(400,300);
            for(i=0;i<12;i++)
                glutBitmapCharacter(GLUT_BITMAP_8_BY_13,level4[i]);
        }
        duck(20,375);
        duck(160,375);
        duck(300,375);
        if(egg_yc<=10)
        egg_start();
        color();
        egg();
        basket(basket_x,basket_y);
        if(eggs_caught>=10)
        {
        egg_yc-=speed_2;
        level_count=2;
        }
        if(eggs_caught>=20)
        {
        egg_yc-=speed_3;
        level_count=3;
        }
        if(eggs_caught>=30)
        {
        egg_yc-=speed_4;
        level_count=4;
        }
        else
        egg_yc-=speed_1;
        score();
        }
        else
        start_screen(40,300);
        glFlush();
        glutSwapBuffers();
}

void basket_set(int a,int b)
{
    basket_x=a;
    basket_y=b;
    glutPostRedisplay();
}

void myReshape(int w,int h)
{
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,(GLdouble)w,0.0,(GLdouble)h);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glViewport(0,0,w,h);
    a=w;
    b=h;
}
void keys(unsigned char key,int x,int y)
{
    if(key=='q'||key=='Q')
    {
        printf("\n\n\n\t\tQUIT BY PLAYER\n\n");
        print_score();
    }

    if(key=='s'||key=='S')
        s+=1;

    if(key=='a'||key=='A')
    {
        egg_xc-=10;
        if(egg_xc<=0)
            egg_xc=10;
    }

    if(key=='d'||key=='D')
    {
        egg_xc+=10;
        if(egg_xc>=500)
        egg_xc=490;
    }
}

void menu(int id)
{
    switch(id)
    {
        case 1: s+=1;
        break;
        case 2:print_score();
        break;
        case 3: printf("\n\n\n\t\tQUIT BY PLAYER\n");
        break;
        default:exit(0);
    }
    glutPostRedisplay();
}

int main(int argc,char **argv)
{
        printf("\n\t\t\t\t EGG GAME\n\n");
        printf("******************************************************************");
        printf("\n\tHow to Play..?\n\n <1>The objective of the game is to catch the eggs in the basket.\n\t To move Basket use mouse.\n");
        printf("\n <2> To Start, press key 's' or 'S' or \n\tClick Right mouse button then click 'Start Game'.\n");
        printf("\n <3> To Quit manually, press key 'q' or 'Q' or\n\t Click Right mouse button then click 'Quit'.\n");
        printf("\n\n RULES : If the player misses 10 eggs,then 'Game Over'.\n");
        printf("\n\n\n SCORE : ->White Egg = 01 point\n\t ->Green Egg = 10 points\n\t ->Orange Egg= 05 points\n\t ->Pink Egg = 15 points\n\t ->Gray Egg = -50 points\n");
        printf("\n BONUS : ->Yellow egg = 100 points\n");
        printf("\nFor each level, speed is doubled\n\n");
        printf("\n\nBEST OF LUCK\n");
        printf("\nFrom BLACK HAWKS\n");
        glutInit(&argc,argv);
        glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);
        glutInitWindowSize(a,b);
        glutCreateWindow("EGG GAME");
        myinit();
        glutCreateMenu(menu);
        glutAddMenuEntry("Start game",1);
        glutAddMenuEntry("score",2);
        glutAddMenuEntry("Quit",3);
        glutAttachMenu(GLUT_RIGHT_BUTTON);
        glutDisplayFunc(display);
        glutKeyboardFunc(keys);
        glutPassiveMotionFunc(basket_set);
        glutIdleFunc(display);
        glutReshapeFunc(myReshape);
        glutMainLoop();
}

