/* CODE FOR THE GAME BALLOON BURST */
/* USE OF ONLY C++ LANGUAGE AND GRAPHICS FUNCTIONS */
/* START OF CODE */
#include<graphics.h>
#include<stdio.h>
#include<conio.h>
#include<iostream.h>
using namespace std;
bool red_clicked = false;
int c;
int count1=0,count2=0,count3=0;

/* FUNCTION TO INCREMENT AND UPDATE THE COUNTER FOR SHOTS */
void increase_shots()
{
     string Result;
     char c[100];
     int l;
     ostringstream convert;
     convert << count2;      
     Result = convert.str(); 
     l=Result.size();
     for (int a=0;a<=l;a++)
     {
            c[a]=Result[a];
     }
     settextjustify(1,1);
     settextstyle(10, HORIZ_DIR,4);
     setcolor(12);
     outtextxy(175,630,c);
}

/* FUNCTION TO INCREMENT AND UPDATE THE COUNTER FOR BURST */

void increase_burst()
{
     string Result;
     char c[100];
     int l;
     ostringstream convert;
     convert << count1;      
     Result = convert.str(); 
     l=Result.size();
     for (int a=0;a<=l;a++)
     {
            c[a]=Result[a];
     }
     settextjustify(1,1);
     settextstyle(10, HORIZ_DIR,4);
     setcolor(12);
     outtextxy(849,630,c);
}


/* FUNCTION TO INCREMENT AND UPDATE THE COUNTER FOR MISSES */
void increase_misses()
{
     string Result;
     char c[100];
     int l;
     count3=count2-count1;
     ostringstream convert;   
     convert << count3;      
     Result = convert.str(); 
     l=Result.size();
     for (int a=0;a<=l;a++)
     {
            c[a]=Result[a];
     }
     settextjustify(1,1);
     settextstyle(10, HORIZ_DIR,4);
     setcolor(12);
     outtextxy(525,630,c);
    
     
}

/* FUNCTION TO CREATE THE GUI FOR BACKGROUND OF MAIN GAME SCREEN */

void background()
{    
     line(0,0,32,30);
     line(32,30,992,30);
     line(1024,0,992,30);
     line(32,30,32,90);
     line(992,30,992,90);
     arc(32,30,180,270,60);
     arc(992,30,270,360,60);
     arc(32+60,30,225,315,86);
     arc(92+60*2,30,225,315,86);
     arc(92+60*4,30,225,315,86);
     arc(92+60*6,30,225,315,86);
     arc(92+60*8,30,225,315,86);
     arc(92+60*10,30,225,315,86);
     arc(92+60*12,30,225,315,86);
     arc(92+60*14,30,225,315,86);
     setfillstyle(SOLID_FILL,4);
     floodfill(10,2,15);
     floodfill(1,10,15);
     floodfill(1023,10,15);
     floodfill(55,40,15);
     line(0,520,1024,520);
     line(0,520,92,560);
     line(1024,520,932,560);
     line(92,560,932,560);
     line(92,560,92,680);
     line(932,560,932,680);
     line(70,550,70,680);
     line(954,550,954,680);
     arc(0,520,270,337,76);
     arc(1024,520,205,270,76);
     setfillstyle(SOLID_FILL,7);
     floodfill(10,521,15);
     arc(152,500,225,315,86);
     arc(152+60*2,500,225,315,86);
     arc(152+60*4,500,225,315,86);
     arc(152+60*6,500,225,315,86);
     arc(152+60*8,500,225,315,86);
     arc(152+60*10,500,225,315,86);
     arc(152+60*12,500,225,315,86);
     rectangle(130,600,220,650);
     rectangle(490-10,600,580-10,650);
     rectangle(804,600,894,650);
     setfillstyle(SOLID_FILL,4);
     floodfill(1,521,15);
     setfillstyle(SOLID_FILL,4);
     floodfill(1023,521,15);
     setfillstyle(SOLID_FILL,4);
     for(int i=152;i<1024;i+=120)floodfill(i,562,15);
     setfillstyle(XHATCH_FILL,8);
     floodfill(91,570,15);
     floodfill(933,570,15);
     setfillstyle(CLOSE_DOT_FILL,9);
     floodfill(200,200,15);      
     setfillstyle(BKSLASH_FILL,14);
     floodfill(2,610,15);
     setfillstyle(BKSLASH_FILL,14);
     floodfill(1023,610,15);
     setfillstyle(INTERLEAVE_FILL,10);
     floodfill(120,610,15);
     settextjustify(1,1);
     settextstyle(10, HORIZ_DIR,3);
     setcolor(12);
     outtextxy(175,670,"SHOTS");
     outtextxy(525,670,"MISSES");
     outtextxy(849,670,"BURST");
}  


void click_handler(int x, int y)

{
     count2++;
     if (getpixel(x,y) == 4)
     {   
         red_clicked = true;
     }

}

void upperpart(int a,int b,int x,int y) //lower part according to the screen
{
     setcolor(4);
     putpixel(a+x,b+y,4);     
     putpixel(a-x,b+y,4);
     putpixel(a+y,b+x,4);
     putpixel(a-y,b+x,4);
}

void lowerpart(int a,int b,int x,int y) //upper part according to the screen
{
     
     putpixel(a+x,b-y,4);
     putpixel(a-x,b-y,4);
     putpixel(a+y,b-x,4);
     putpixel(a-y,b-x,4);
}

void mellipse(int a, int b, int x, int y)
{
     putpixel(a+x,b+y,4);     
     putpixel(a-x,b+y,4);  
}

/* FUNCTION FOR TRANSLATION OF BALLOON UPWARDS */

int balloon(int a,int b,int r,int e)
{
    for(int i=0;i<240;i+=3)
    { 
            if(red_clicked)
            {                        
                  cout<<"\a";
                  count1++;
                  return 0;
            }
                 
            int ac=a,bc=b-i,rc=r,pc,xc,yc;
            pc=1-rc;
            xc=0;
            yc=rc;
            lowerpart(ac,bc,xc,yc);
            while(xc<yc)
            {
                  xc++;
                  if(pc<0)
                      pc+=2*xc+1;
                  else
                  {
                      yc--;
                      pc+=2*(xc-yc)+1;
                  }
                  lowerpart(ac,bc,xc,yc);
            }     
            /*    ELLEPSE    */   
   
            int ae=e,be=rc,re,xe,ye,s=ac,t=bc,px,py;
            float pe;
            xe=0;
            ye=ae;
            px=0;
            py=2*be*be*ye;
            pe=(ae*ae)+(be*be*0.25)-(ae*be*be);
            mellipse(s,t,xe,ye);
            while(px<py)        
            {
                    xe++;
                    px+=2*ae*ae;
                    if(pe<0)
                            pe+=(ae*ae)+px;         
                    else
                    {
                            ye--;
                            py-=2*be*be;
                            pe+=(ae*ae)+px-py;  
                    }
                    mellipse(s,t,xe,ye);
            }
            pe=(ae*ae*(xe+0.5)*(xe+0.5)+ (be*be*(ye-1)*(ye-1))-(ae*ae*be*be));
            while(ye>0)
            {
                    ye--;
                    py-=2*be*be;
                    if(pe>0)
                            pe+=(be*be)-py;
                    else
                    {
                            xe++;
                            px+=2*ae*ae;
                            pe+=(be*be)-py+px;    
                    }          
                    mellipse(s,t,xe,ye);
            }     
            setcolor(4);
            line(ac,bc+ae,ac-10,bc+ae+5);
            line(ac,bc+ae,ac+10,bc+ae+5);
            line(ac-10,bc+ae+5,ac+10,bc+ae+5);
            arc(ac,bc+ae+15,90,270,15);
            arc(ac,bc+ae+15+30,270,90,15);
            setfillstyle(SOLID_FILL,4);
            floodfill(ac,bc,4);
            floodfill(ac,bc+ae+3,4);
            delay(30);
            setfillstyle(CLOSE_DOT_FILL,9);
            floodfill(ac-rc+1,bc,15);
            increase_shots();
            increase_burst();
            increase_misses();
     }
      
}

/* main function   */

int main()
{
    
    int maxx, maxy;   
    int x1=0, y1=0;    
    int z=50,k=10000000;
    int points=0;
    initwindow(1024,680,"test");
	char c[50];
	int l,i,j;
	registermousehandler(WM_LBUTTONDOWN, click_handler);
    maxx = getmaxx( );
    maxy = getmaxy( );
    /* BACKGROUND FOR START  GAME SCREEN */
    setfillstyle(SOLID_FILL, RED);
    setcolor(WHITE);
    rectangle(100,250,900,400);
    setfillstyle(SOLID_FILL, RED);
    floodfill(101,252,15);
    settextjustify(1,1);
    settextstyle(10, HORIZ_DIR,6);
    setcolor(12);
	outtextxy((maxx/2) ,(maxy/2) ,"click here to start game");
    setcolor(WHITE);
    setfillstyle(WIDE_DOT_FILL,GREEN);
    floodfill(99,252,15);
    int min=100,max=980,x;
   	while(!red_clicked);
   	red_clicked=false;
   	cleardevice();
   	/* CALL FOR BACKGROUND FOR MAIN GAME SCREEN */
   	background();
   	/* GENERATE RANDOM POSITIONS FOR BALLOONS */
    for(int i=0;i<50;i++)
    {
            min=100,max=980;
            x=(rand() % ( max + 1 - min ))+ min;
            printf("%d",x);
            balloon(x,400,40,60);
            red_clicked=false;
    }
    cleardevice();
    /* BACKGROUND FOR END GAME SCREEN */
    setfillstyle(SOLID_FILL, RED);
    setcolor(WHITE);
    rectangle(175,250,825,400);
    floodfill(176,252,15);
    string Result;
    char o[100],g[100];
    ostringstream convert;   
    convert << count1;      
    Result = convert.str(); 
    l=Result.size();
    strcpy(o,"POINTS EARNED : ");
    int b=strlen(o);
    for (int a=0;a<=l;a++)
    {
        g[a]=Result[a];
    }
    strcat(o,g);
    settextjustify(1,1);
    settextstyle(10, HORIZ_DIR,6);
    setcolor(12);
	outtextxy((maxx/2) ,(maxy/2) ,o);
    setcolor(WHITE);
    setfillstyle(WIDE_DOT_FILL,GREEN);
    floodfill(99,252,15);
    rectangle(290,490,725,570);
    setfillstyle(SOLID_FILL,RED);
    floodfill(301,501,15);
    settextjustify(1,1);
    settextstyle(10, HORIZ_DIR,5);
    setcolor(12);
	outtextxy((maxx/2) ,(maxy/2)+200 ,"PRESS TO EXIT");
	while(!red_clicked);
    return 0;
}
/* END OF CODE */
