/*
-----ROAD FIGHTER------
BY-PRAKHAR SRIVASTAVA
*/
#include <graphics.h>
#include <dos.h>
#include <conio.h>
#include<stdlib.h>
#include<time.h>
#include<iostream>
#include<windows.h>
int arr[100];
int start()
{
	int i=0;
	for(i=1;i<=5;i=i+1)
	{
		settextstyle(10,HORIZ_DIR,i);
		setcolor(i);
		outtextxy(getmaxx()/2-120,getmaxy()/2,"ROAD FIGHTER");
		delay(250);
	}
	delay(2000);
	cleardevice();
	outtextxy(getmaxx()/2-280,getmaxy()/2,"GAME BEGAINS IN 3 SEC");
	delay(3000);
	cleardevice();
}

int display(int flag)
{
	int i;
	delay(1000);
	cleardevice();
	settextstyle(10,HORIZ_DIR,5);
	if(flag==4)
	{
		for(i=6;i<=10;i=i+1)
		{
			settextstyle(10,HORIZ_DIR,i-5);
			setcolor(i);
			outtextxy(getmaxx()/2-120,getmaxy()/2,"U R A WINNER");
			delay(250);
		}
	}	
	if(flag==2)
	{
		outtextxy(getmaxx()/2-190,getmaxy()/2,"2 LIVES REMANING");	
		delay(2000);
		cleardevice();
		return 0;
	}
	if(flag==1)
	{
		outtextxy(getmaxx()/2-110,getmaxy()/2,"LAST LIFE");
		delay(2000);
		cleardevice();
		return 0;
	}
	if(flag==0)
	{
		for(i=6;i<=10;i=i+1)
		{
		settextstyle(10,HORIZ_DIR,i-5);
		setcolor(i);
		outtextxy(getmaxx()/2-120,getmaxy()/2,"GAME OVER");
		delay(250);
		}
	}
		delay(2000);
		cleardevice();
		outtextxy(getmaxx()/2-320,getmaxy()/2,"PRESS ANY KEY FOR RE GAME");
}

int check(int u,int xcord,int ycord,int i)
{
	int xboxl=xcord-15,xboxrt=xcord+15;
	int yboxstart=getmaxy()-105,yboxend=getmaxy()-75;
	int xlpos=xcord-25,xrpos=xcord+25;
	int topy=getmaxy()-ycord+u,boty=getmaxy()-(ycord-75)+u;
	if((arr[i]<xlpos&&xlpos<arr[i]+50)&&(topy<getmaxy()-75&&getmaxy()-75<boty))
		return 1;
	if((arr[i]<xrpos&&xrpos<arr[i]+50)&&(topy<getmaxy()-75&&getmaxy()-75<boty))
		return 1;
	if((arr[i]<xlpos&&xlpos<arr[i]+50)&&(topy<getmaxy()&&getmaxy()<boty))
		return 1;
	if((arr[i]<xrpos&&xlpos<arr[i]+50)&&(topy<getmaxy()&&getmaxy()<boty))
		return 1;
	if((arr[i]+10<xboxl&&xboxl<arr[i]+40)&&(boty<yboxstart&&yboxstart<boty+30))
		return 1;
	if((arr[i]+10<xboxrt&&xboxrt<arr[i]+40)&&(boty<yboxstart&&yboxstart<boty+30))
		return 1;
	if((arr[i]<xboxl&&xboxl<arr[i]+50)&&(topy<yboxstart&&yboxstart<boty))
		return 1;
	if((arr[i]<xboxrt&&xboxrt<arr[i]+50)&&(topy<yboxstart&&yboxstart<boty))
		return 1;
	else
		return 0;
}

int createx()
{
	int i;
	srand(time(NULL));
	for(i=0;i<100;i++)
	{
		while(1)
		{
			arr[i]=(rand()%(getmaxx()/3))+getmaxx()/3;
			if(arr[i]+50<2*getmaxx()/3)
				break;
			continue;
		}
	}
}

int traffic(int u,int xcord)
{
	int i,rl,ycord=30500;
	for(i=0;i<100;i++)
	{
		setfillstyle(SOLID_FILL,BROWN);
		setcolor(BROWN);
		rectangle(arr[i],getmaxy()-ycord+u,arr[i]+50,getmaxy()-(ycord-75)+u);
		floodfill(arr[i]+5,getmaxy()-(ycord-25)+u,BROWN);
		setfillstyle(SOLID_FILL,BLUE);
		setcolor(BLUE);
		rectangle(arr[i]+10,getmaxy()-(ycord-75)+u,arr[i]+40,getmaxy()-(ycord-105)+u);
		floodfill(arr[i]+20,getmaxy()-(ycord-85)+u,BLUE);
		rl=check(u,xcord,ycord,i);
		if(rl==1)
			return rl;
		ycord=ycord-300;
	}
}

int terrain(int u)
{
	setcolor(GREEN);
	setfillstyle(SOLID_FILL,GREEN);
	rectangle(0,0,getmaxx()/3,getmaxy());
	floodfill(50,50,GREEN);
	rectangle(2*getmaxx()/3,0,getmaxx()-1,getmaxy());
	floodfill(2*getmaxx()/3+5,50,GREEN);
}

int car()
{
	static int xcord=(2*getmaxx()/3+getmaxx()/3)/2;
	char ch=NULL;
	DWORD stime=GetTickCount();
	DWORD etime=stime+1;
	while(etime>stime)
	{
		if(kbhit())
		{
			ch=getch();
			break;
		}
	stime=GetTickCount();
	}
	if(ch=='d'&& xcord+50<=2*getmaxx()/3)
	{
		xcord=xcord+25;
		setfillstyle(SOLID_FILL,RED);
		setcolor(RED);
		rectangle(xcord-25,getmaxy()-75,xcord+25,getmaxy());
		floodfill(xcord+10,getmaxy()-70,RED);
		setfillstyle(SOLID_FILL,BLUE);
		setcolor(BLUE);
		rectangle(xcord-15,getmaxy()-105,xcord+15,getmaxy()-75);
		floodfill(xcord-10,getmaxy()-90,BLUE);
	}
	if(ch=='a' && xcord-50>=getmaxx()/3)
	{
		xcord=xcord-25;
		setfillstyle(SOLID_FILL,RED);
		setcolor(RED);
		rectangle(xcord-25,getmaxy()-75,xcord+25,getmaxy());
		floodfill(xcord+10,getmaxy()-70,RED);
		setfillstyle(SOLID_FILL,BLUE);
		setcolor(BLUE);
		rectangle(xcord-15,getmaxy()-105,xcord+15,getmaxy()-75);
		floodfill(xcord-10,getmaxy()-90,BLUE);
	}
	if((ch!='a' && ch!='d')||(xcord+50>2*getmaxx()/3||xcord-50<getmaxx()/3))
	{
		setfillstyle(SOLID_FILL,RED);
		setcolor(RED);
		rectangle(xcord-25,getmaxy()-75,xcord+25,getmaxy());
		floodfill(xcord+10,getmaxy()-70,RED);
		setfillstyle(SOLID_FILL,BLUE);
		setcolor(BLUE);
		rectangle(xcord-15,getmaxy()-105,xcord+15,getmaxy()-75);
		floodfill(xcord-10,getmaxy()-90,BLUE);
	}
	if(ch=='h')
		Beep(400,100);
	return xcord;
}
int main()
{
	char ch=NULL;
	int u=0,life=3,rl,xcord, gd = DETECT, gm,oldpage,newpage;
	initgraph(&gd,&gm,"C:\\TC\\BGI");
	setbkcolor(BLACK);
	int speed=50;
	start();
	createx();
	while(1)
	{
		oldpage = getvisualpage( );
		newpage = abs(oldpage-1);
		setactivepage(newpage);
		cleardevice();
		if(30600==u)
		{
			display(4);
			ch=getch();
			if(ch!=NULL)
				life=3;
			cleardevice();
			u=0;
			speed=50;
			createx();
			continue;
		}
		xcord=car();
		terrain(u);
		rl=traffic(u,xcord);
		if(rl==1)
		{
			setvisualpage(newpage);
			--life;
			if(life==2)
				display(2);
			if(life==1)
				display(1);
			if(life==0)
			{
				display(0);
				ch=getch();
				if(ch!=NULL)
					life=3;
			}
			cleardevice();
			u=0;
			speed=50;
			createx();
			continue;
		}
		if(u%6100==0 && speed>5)
			speed=speed-10;
		setvisualpage(newpage);
		delay(speed);
		u=u+10;
	}
	getch();
	closegraph();
	return 0;
}
