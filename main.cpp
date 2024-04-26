#include <iostream>
#include <iostream>
#include <SDL2/SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL2/SDL2_gfx.h>
#include <string>
#include <SDL_mixer.h>
#include <fstream>

// by Dr Arasteh
// by Dr Vosoghi Vahdat
// by MohammadAmin Alamalhoda  ma.alamalhoda@gmail.com


using namespace std;
int pause();
void window_color(SDL_Renderer *Renderer, int R, int G, int B);
void rect(SDL_Renderer *Renderer, int x,int y,int w,int h,int R, int G, int B, int fill_boolian );
void ellipse(SDL_Renderer *Renderer, int x, int y, int Radius1, int Radius2, int R, int G, int B, int fill_boolian);
void my_line(SDL_Renderer *Renderer, int x_1, int y_1, int L,double theta,int widht, int R, int G, int B );
void texture(SDL_Renderer *m_renderer,int xp,int yp,string addressOfImage,int width,int height);
void textColor(SDL_Renderer *renderer,int x,int y,const char * text,const char * font,int font_size,SDL_Color textColor,double angle,short flip_num);
void textColor(SDL_Renderer *renderer,int x,int y,const char * text,const char * font,int font_size,SDL_Color textColor,double angle,short flip_num);

int main( int argc, char * argv[] )
{
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    Mix_OpenAudio(MIX_DEFAULT_FREQUENCY,MIX_DEFAULT_FORMAT,2,2048);
    string sound = "background2.mp3";
    Mix_Music *GameSound = Mix_LoadMUS(sound.c_str());
    Mix_PlayMusic(GameSound,-1);

    Mix_Chunk *gol = Mix_LoadWAV("gol.wav");
    Mix_Chunk *winner = Mix_LoadWAV("winner.wav");
    Mix_Chunk *kick = Mix_LoadWAV("kick.wav");
    Mix_Chunk *topoli = Mix_LoadWAV("topoli.wav");
    Mix_Chunk *avazi = Mix_LoadWAV("avazi.wav");
    Mix_Chunk *ab = Mix_LoadWAV("ab.wav");
    Mix_Chunk *helicopter = Mix_LoadWAV("helicopter.wav");
    Mix_Chunk *hello1 = Mix_LoadWAV("hello1.wav");
    Mix_Chunk *hello2 = Mix_LoadWAV("hello2.wav");
    Mix_Chunk *whistle = Mix_LoadWAV("whistle.wav");
    int W = 800;//ertefa safhe
    int L = 1280;//tool safhe
      // be ina kari nadashte bashid
    Uint32 SDL_flags = SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_AUDIO;
    Uint32 WND_flags = SDL_WINDOW_SHOWN;//| SDL_WINDOW_FULLSCREEN_DESKTOP;//SDL_WINDOW_BORDERLESS ;
    SDL_Window *m_window;
    SDL_Renderer *m_renderer;
    SDL_Init( SDL_flags );
    SDL_CreateWindowAndRenderer( L, W, WND_flags, &m_window, &m_renderer );
    //Pass the focus to the drawing window
    SDL_RaiseWindow(m_window);
    //Get screen res olution
    SDL_DisplayMode DM;
    SDL_GetCurrentDisplayMode(0, &DM);
    TTF_Init();
    // be ina kari nadashte bashid
    int RNX = 200, RNY = 200;
    SDL_Event *event = new SDL_Event();
    SDL_Event *f = new SDL_Event();

int A=1,X=0;
bool general=true,menu=true,choose=true,table2=true,game=true,leader=true,setting=true,about=true;

///main
string situation_Y="off.png",situation_L="off.png",situation_S="off.png",situation_U="off.png";
///main

///choose characters
string player1="messi.png",player2="messi.png",logo1="barca.png",logo2="barca.png";
///choose characters

///table2
int O=0xFF0AAFFF;
///table2

///game
string ball="ball3.png",team1,team2,fan1,fan2,score1,score2,shoe1,shoe2;
int xh1=1070,yh1=580;/// x and y for head1
int xh2=160,yh2=580;/// x and y for head2
int xb=625,yb=215;/// x and y for ball
int xhel=-400,xsh=xhel+210;/// x helicopter and Mr.Shapoori
double yhel=20,ysh=yhel+115;/// y helicopter and Mr.Shapoori
int score_1=0,score_2=0,counter1=0,counter2=0,counter_Time=-10,counter_Time_Goal=1000,counter_Time_Goall=1000,counter_ab=0,counter_Time_referee,counter_Time_shoot1,counter_Time_shoot2,counter_Time_punch1=1000,counter_Time_punch2=1000,counter_Time_invisible1=1000,counter_Time_invisible2=1000,counter_Time_obstacle1=1000,counter_Time_obstacle2=1000;

///picture of background****************************************************************************************
int img_w1,img_h1,x1=0,y1=0;
SDL_Texture* m_texture;
const char * IMG1_address="background_game.png";
m_texture = IMG_LoadTexture(m_renderer, IMG1_address);
SDL_QueryTexture(m_texture, NULL, NULL, &img_w1, &img_h1);
SDL_Rect img_rect1;
img_rect1.x = x1;
img_rect1.y = y1;
img_rect1.w = 1280;
img_rect1.h = 800;
SDL_RenderCopy(m_renderer, m_texture, NULL, &img_rect1);
///picture of background****************************************************************************************

double zarib=1,a=3,v=-200,y0=350,t=0;
double dx=0,dy=10;
bool power1=false,power2=false;
bool kick1=false,punch1=false,invisible1=false,obstacle1=false,thief1=false;
bool kick2=false,punch2=false,invisible2=false,obstacle2=false,thief2=false;
///game

///setting
int xb1=300,yb1=300,dx1=55,dy1=55;
int xb2=1100,yb2=100,dx2=15,dy2=15;
int xb3=100,yb3=700,dx3=15,dy3=35;
///setting

///about
int y11=-10,y2=-200,y3=-450,y4=-650,y5=-1050,y6=-950,y7=-850,y8=-1800,y9=-2300,dyy=3;
///about

string name1,name2;
cin>>name1>>name2;

while (general)
{
if(A==1)
{
            while (menu)
            {

texture(m_renderer,0,0,"background_menu.png",1280,800);///picture of background
texture(m_renderer,300,20,"headfootball.png",700,200);///picture of headfootball
texture(m_renderer,0,0,"javad.png",300,200);///picture of khiabani
texture(m_renderer,-20,30,"text.png",340,350);///picture of

///picture of wooden buttons______________________________________________________
texture(m_renderer,240,230,situation_Y,400,150);
texture(m_renderer,220,360,situation_L,690,130);
texture(m_renderer,250,485,situation_S,400,130);
texture(m_renderer,240,620,situation_U,650,160);
///picture of wooden buttons______________________________________________________

///text============================================================
texture(m_renderer,300,250,"play.png",300,150);
texture(m_renderer,300,370,"leaderboard.png",550,100);
texture(m_renderer,300,400,"setting.png",300,200);
texture(m_renderer,300,600,"about us and game.png",550,170);
///text============================================================

///press..........................................
texture(m_renderer,650,270,"Y.png",150,75);
texture(m_renderer,880,390,"L.png",150,75);
texture(m_renderer,650,525,"S.png",150,75);
texture(m_renderer,870,655,"U.png",150,75);
///press..........................................

SDL_RenderPresent(m_renderer);
SDL_Delay(5);
SDL_RenderClear(m_renderer);

const Uint8 *keyboard_state_array = SDL_GetKeyboardState(NULL);
SDL_PollEvent(f);
        if(f->type == SDL_KEYDOWN || f->type == SDL_KEYUP)
        {
                if(keyboard_state_array[SDL_SCANCODE_Y])
                {
                  situation_Y="on.png";
                  A=2;
                  menu=false;
                  choose=true;
                }
            else if(keyboard_state_array[SDL_SCANCODE_L])
                    {
                  situation_L="on.png";
                  A=5;
                  menu=false;
                  leader=true;
                    }
            else if(keyboard_state_array[SDL_SCANCODE_S])
                    {
                  situation_S="on.png";
                  A=6;
                  menu=false;
                  setting=true;
                    }
            else if(keyboard_state_array[SDL_SCANCODE_U])
                    {
                  situation_U="on.png";
                  A=7;
                  menu=false;
                  about=true;
                  y11=-10,y2=-200,y3=-450,y4=-650,y5=-1050,y6=-950,y7=-850,y8=-1800,y9=-2300,dyy=3;
                    }
            else if(keyboard_state_array[SDL_SCANCODE_ESCAPE])
                    {
                  general=false;
                  menu=false;
                    }
            }

}
}

if(A==2)
{
while (choose)
{
if(player1=="messi.png") logo1="barca.png";
if(player2=="messi.png") logo2="barca.png";
if(player1=="karim.png") logo1="real.png";
if(player2=="karim.png") logo2="real.png";
if(player1=="ronaldo.png") logo1="juve.png";
if(player2=="ronaldo.png") logo2="juve.png";
if(player1=="bruno.png") logo1="manu.png";
if(player2=="bruno.png") logo2="manu.png";
if(player1=="hoseini.png") logo1="persepolis.png";
if(player2=="hoseini.png") logo2="persepolis.png";

texture(m_renderer,0,0,"background_choose.png",1280,800);///picture of background

ellipse(m_renderer,1037,380,140,140,150,200,100,1);///daiere sabz posht bazikon1
ellipse(m_renderer,243,380,140,130,150,200,100,1);///daiere sabz posht bazikon2
rect(m_renderer,630,130,30,28,255,245,255,1);///white square
rect(m_renderer,575,182,35,36,150,200,100,1);///not important thing
rect(m_renderer,675,183,35,35,150,200,100,1);///not important thing
rect(m_renderer,414,380,102,65,150,200,50,1);///not important thing
rect(m_renderer,766,380,102,65,150,200,50,1);///not important thing
rect(m_renderer,756,323,120,26,190,50,50,1);///red rectangle
rect(m_renderer,405,320,130,30,90,50,250,1);///blue rectangle
texture(m_renderer,756,305,"player1.png",120,70);
texture(m_renderer,405,305,"player2.png",120,70);

texture(m_renderer,880,240,player1,300,300);///picture of player1
texture(m_renderer,90,230,player2,300,300);///picture of player2

texture(m_renderer,766,380,logo1,100,70);///picture of logo1
texture(m_renderer,414,380,logo2,100,70);///picture of logo2

texture(m_renderer,455,200,"left.png",80,80);///picture of left button
texture(m_renderer,550,170,ball,150,150);///picture of ball
texture(m_renderer,710,200,"right.png",90,90);///picture of right button

SDL_RenderPresent(m_renderer);
SDL_Delay(15);
SDL_RenderClear(m_renderer);

const Uint8 *keyboard_state_array = SDL_GetKeyboardState(NULL);
SDL_PollEvent(f);
        if(f->type == SDL_KEYDOWN || f->type == SDL_KEYUP)
        {

                  if(keyboard_state_array[SDL_SCANCODE_UP])
                    {
                        if(player1=="messi.png") player1="karim.png";
                   else if(player1=="karim.png") player1="ronaldo.png";
                   else if(player1=="ronaldo.png") player1="bruno.png";
                   else if(player1=="bruno.png") player1="hoseini.png";
                   else if(player1=="hoseini.png") player1="messi.png";
                    }
                  if(keyboard_state_array[SDL_SCANCODE_DOWN])
                    {
                        if(player1=="messi.png") player1="hoseini.png";
                   else if(player1=="hoseini.png") player1="bruno.png";
                   else if(player1=="bruno.png") player1="ronaldo.png";
                   else if(player1=="ronaldo.png") player1="karim.png";
                   else if(player1=="karim.png") player1="messi.png";
                    }
                  if(keyboard_state_array[SDL_SCANCODE_W])
                    {
                        if(player2=="messi.png") player2="karim.png";
                   else if(player2=="karim.png") player2="ronaldo.png";
                   else if(player2=="ronaldo.png") player2="bruno.png";
                   else if(player2=="bruno.png") player2="hoseini.png";
                   else if(player2=="hoseini.png") player2="messi.png";
                    }
                  if(keyboard_state_array[SDL_SCANCODE_S])
                    {
                        if(player2=="messi.png") player2="hoseini.png";
                   else if(player2=="hoseini.png") player2="bruno.png";
                   else if(player2=="bruno.png") player2="ronaldo.png";
                   else if(player2=="ronaldo.png") player2="karim.png";
                   else if(player2=="karim.png") player2="messi.png";
                    }
                 if(keyboard_state_array[SDL_SCANCODE_LEFT])
                    {
                          if(ball=="ball1.png") ball="ball3.png";
                          else if(ball=="ball2.png") ball="ball3.png";
                          else if(ball=="ball3.png") ball="ball1.png";
                          else if(ball=="ball4.png") ball="ball1.png";
                    }
                  if(keyboard_state_array[SDL_SCANCODE_RIGHT])
                    {
                          if(ball=="ball1.png") ball="ball3.png";
                          else if(ball=="ball2.png") ball="ball3.png";
                          else if(ball=="ball3.png") ball="ball1.png";
                          else if(ball=="ball4.png") ball="ball1.png";
                    }
                  if(keyboard_state_array[SDL_SCANCODE_P])
                    {
                        A=3;
                        choose=false;
                        table2=true;
                    }

        }
}
}

if(A==3)
{
while (table2)
        {
int n=2,goalsd1=score_1-score_2,goalsd2=score_2-score_1,drawn1=0,drawn2=0,won1=0,won2=0;
if(score_1>score_2) won1+=1;
if(score_1<score_2) won2+=1;
if(score_1==score_2 && X!=0) {drawn1+=1;drawn2+=1;}
int points1=3*won1+drawn1,points2=3*won2+drawn2;

texture(m_renderer,0,0,"background_table2.png",1280,800);///picture of background
rect(m_renderer,930,50,300,70,0,0,0,1);///not important thing
rect(m_renderer,280,200,720,400,100,100,100,1);///table

///vertical lines-------------------------------------------------
my_line(m_renderer,360,200,400,4.71248898,4,250,120,0);
my_line(m_renderer,440,200,400,4.71248898,4,250,120,0);
my_line(m_renderer,520,200,400,4.71248898,4,250,120,0);
my_line(m_renderer,600,200,400,4.71248898,4,250,120,0);
my_line(m_renderer,680,200,400,4.71248898,4,250,120,0);
my_line(m_renderer,760,200,400,4.71248898,4,250,120,0);
my_line(m_renderer,840,200,400,4.71248898,4,250,120,0);
my_line(m_renderer,920,200,400,4.71248898,4,250,120,0);
///vertical lines---------------------------------------------------

stringColor(m_renderer,855,232,"PLAYED",O);
stringColor(m_renderer,785,232,"WON",O);
stringColor(m_renderer,695,232,"DRAWN",O);
stringColor(m_renderer,625,232,"LOST",O);
stringColor(m_renderer,535,232,"GOALS F",O);
stringColor(m_renderer,455,232,"GOALS A",O);
stringColor(m_renderer,375,232,"GOALS D",O);
stringColor(m_renderer,295,232,"POINTS",O);

if(X==0)texture(m_renderer,855,500,"noll.png",50,50); else texture(m_renderer,855,500,"one.png",50,50);
if(X==0)texture(m_renderer,855,350,"noll.png",50,50); else texture(m_renderer,855,350,"one.png",50,50);
if(score_2>score_1) texture(m_renderer,780,500,"one.png",50,50); else texture(m_renderer,780,500,"noll.png",50,50);
if(score_1>score_2) texture(m_renderer,780,350,"one.png",50,50); else texture(m_renderer,780,350,"noll.png",50,50);
if(score_1==score_2 && X!=0) texture(m_renderer,695,500,"one.png",50,50); else texture(m_renderer,695,500,"noll.png",50,50);
if(score_1==score_2 && X!=0) texture(m_renderer,695,350,"one.png",50,50); else texture(m_renderer,695,350,"noll.png",50,50);
if(score_1>score_2) texture(m_renderer,620,500,"one.png",50,50); else texture(m_renderer,620,500,"noll.png",50,50);
if(score_2>score_1) texture(m_renderer,620,350,"one.png",50,50); else texture(m_renderer,620,350,"noll.png",50,50);
if(score_1==1)texture(m_renderer,535,350,"one.png",50,50); else if(score_1==2)texture(m_renderer,535,350,"two.png",50,50); else if(score_1==3)texture(m_renderer,535,350,"three.png",50,50); else if(score_1==1)texture(m_renderer,535,350,"four.png",50,50); else if(score_1==5)texture(m_renderer,535,350,"five.png",50,50); else if(score_1==6)texture(m_renderer,535,350,"six.png",50,50);  else texture(m_renderer,535,350,"noll.png",50,50);///goals f1
if(score_2==1)texture(m_renderer,535,500,"one.png",50,50); else if(score_2==2)texture(m_renderer,535,500,"two.png",50,50); else if(score_2==3)texture(m_renderer,535,500,"three.png",50,50); else if(score_2==1)texture(m_renderer,535,500,"four.png",50,50); else if(score_2==5)texture(m_renderer,535,500,"five.png",50,50); else if(score_2==6)texture(m_renderer,535,500,"six.png",50,50);  else texture(m_renderer,535,500,"noll.png",50,50);///goals f2
if(score_2==1)texture(m_renderer,455,350,"one.png",50,50); else if(score_2==2)texture(m_renderer,455,350,"two.png",50,50); else if(score_2==3)texture(m_renderer,455,350,"three.png",50,50); else if(score_2==1)texture(m_renderer,455,350,"four.png",50,50); else if(score_2==5)texture(m_renderer,455,350,"five.png",50,50); else if(score_2==6)texture(m_renderer,455,350,"six.png",50,50);  else texture(m_renderer,455,350,"noll.png",50,50);///goals a1
if(score_1==1)texture(m_renderer,455,500,"one.png",50,50); else if(score_1==2)texture(m_renderer,455,500,"two.png",50,50); else if(score_1==3)texture(m_renderer,455,500,"three.png",50,50); else if(score_1==1)texture(m_renderer,455,500,"four.png",50,50); else if(score_1==5)texture(m_renderer,455,500,"five.png",50,50); else if(score_1==6)texture(m_renderer,455,500,"six.png",50,50);  else texture(m_renderer,455,500,"noll.png",50,50);///goals a2
if(goalsd1==-6){stringRGBA(m_renderer,365,380,"-",255,0,0,255);texture(m_renderer,375,350,"six.png",50,50);} else if(goalsd1==-5){stringRGBA(m_renderer,365,380,"-",255,0,0,255);texture(m_renderer,375,350,"five.png",50,50);} else if(goalsd1==-4){stringRGBA(m_renderer,365,380,"-",255,0,0,255);texture(m_renderer,375,350,"four.png",50,50);} else if(goalsd1==-3){stringRGBA(m_renderer,365,380,"-",255,0,0,255);texture(m_renderer,375,350,"three.png",50,50);} else if(goalsd1==-2){stringRGBA(m_renderer,365,380,"-",255,0,0,255);texture(m_renderer,375,350,"two.png",50,50);} else if(goalsd1==-1){stringRGBA(m_renderer,365,380,"-",255,0,0,255);texture(m_renderer,375,350,"one.png",50,50);} else if(goalsd1==0)texture(m_renderer,375,350,"noll.png",50,50); else if(goalsd1==1)texture(m_renderer,375,350,"one.png",50,50); else if(goalsd1==2)texture(m_renderer,375,350,"two.png",50,50); else if(goalsd1==3)texture(m_renderer,375,350,"three.png",50,50); else if(goalsd1==4)texture(m_renderer,375,350,"four.png",50,50); else if(goalsd1==5)texture(m_renderer,375,350,"five.png",50,50); else if(goalsd1==6)texture(m_renderer,375,350,"six.png",50,50);
if(goalsd2==-6){stringRGBA(m_renderer,365,530,"-",255,0,0,255);texture(m_renderer,375,500,"six.png",50,50);} else if(goalsd2==-5){stringRGBA(m_renderer,365,530,"-",255,0,0,255);texture(m_renderer,375,500,"five.png",50,50);} else if(goalsd2==-4){stringRGBA(m_renderer,365,530,"-",255,0,0,255);texture(m_renderer,375,500,"four.png",50,50);} else if(goalsd2==-3){stringRGBA(m_renderer,365,530,"-",255,0,0,255);texture(m_renderer,375,500,"three.png",50,50);} else if(goalsd2==-2){stringRGBA(m_renderer,365,530,"-",255,0,0,255);texture(m_renderer,375,500,"two.png",50,50);} else if(goalsd2==-1){stringRGBA(m_renderer,365,530,"-",255,0,0,255);texture(m_renderer,375,500,"one.png",50,50);} else if(goalsd2==0)texture(m_renderer,375,500,"noll.png",50,50); else if(goalsd2==1)texture(m_renderer,375,500,"one.png",50,50); else if(goalsd2==2)texture(m_renderer,375,500,"two.png",50,50); else if(goalsd2==3)texture(m_renderer,375,500,"three.png",50,50); else if(goalsd2==4)texture(m_renderer,375,500,"four.png",50,50); else if(goalsd2==5)texture(m_renderer,375,500,"five.png",50,50); else if(goalsd2==6)texture(m_renderer,375,500,"six.png",50,50);
if(points1==0)texture(m_renderer,295,350,"noll.png",50,50); else if(points1==1)texture(m_renderer,295,350,"one.png",50,50); else if(points1==2)texture(m_renderer,295,350,"two.png",50,50); else if(points1==3)texture(m_renderer,295,350,"three.png",50,50); else if(points1==4)texture(m_renderer,295,350,"four.png",50,50); else if(points1==6)texture(m_renderer,295,350,"six.png",50,50);
if(points2==0)texture(m_renderer,295,500,"noll.png",50,50); else if(points2==1)texture(m_renderer,295,500,"one.png",50,50); else if(points2==2)texture(m_renderer,295,500,"two.png",50,50); else if(points2==3)texture(m_renderer,295,500,"three.png",50,50); else if(points2==4)texture(m_renderer,295,500,"four.png",50,50); else if(points2==6)texture(m_renderer,295,500,"six.png",50,50);

const char * font_address_00="arial.ttf";
SDL_Color text_color={255,0,255};
textColor(m_renderer,935,500,name2.c_str(),font_address_00,23,text_color,0.0,0);///show name1
textColor(m_renderer,935,350,name1.c_str(),font_address_00,23,text_color,0.0,0);///show name2

my_line(m_renderer,280,280,720,0,5,250,120,0);///the first horizontal line
rect(m_renderer,920,200,81,80,250,120,0,1);///mostatil narenji bala raste jadval
my_line(m_renderer,280,440,720,0,2,128,0,128);///the other horizontal lines

SDL_RenderPresent(m_renderer);
SDL_Delay(5);
SDL_RenderClear(m_renderer);
const Uint8 *keyboard_state_array = SDL_GetKeyboardState(NULL);
SDL_PollEvent(f);
        if(f->type == SDL_KEYDOWN || f->type == SDL_KEYUP)
        {

                  if(keyboard_state_array[SDL_SCANCODE_P])
                    {
                        table2=false;
                        A=4;
                        game=true;
xh1=1070,yh1=580;/// x and y for head1
xh2=160,yh2=580;/// x and y for head2
xb=625,yb=215;/// x and y for ball
xhel=-400,xsh=xhel+210;/// x helicopter and Mr.Shapoori
yhel=20,ysh=yhel+115;/// y helicopter and Mr.Shapoori
score_1=0,score_2=0,counter1=0,counter2=0,counter_Time=-10,counter_Time_Goal=1000,counter_Time_Goall=1000,counter_ab=0,counter_Time_referee,counter_Time_shoot1,counter_Time_shoot2,counter_Time_punch1=1000,counter_Time_punch2=1000,counter_Time_invisible1=1000,counter_Time_invisible2=1000,counter_Time_obstacle1=1000,counter_Time_obstacle2=1000;
sound="background.mp3";Mix_Music *GameSound = Mix_LoadMUS(sound.c_str());Mix_PlayMusic(GameSound,-1);
                    }
        }

}



SDL_RenderPresent(m_renderer);
SDL_Delay(5);
SDL_RenderClear(m_renderer);

}

if(player1=="messi.png") player1="messi1.png";
if(player1=="karim.png") player1="karim1.png";
if(player1=="ronaldo.png") player1="ronaldo1.png";
if(player1=="bruno.png") player1="bruno1.png";
if(player1=="hoseini.png") player1="hoseini1.png";
if(player2=="messi.png") player2="messi2.png";
if(player2=="karim.png") player2="karim2.png";
if(player2=="ronaldo.png") player2="ronaldo2.png";
if(player2=="bruno.png") player2="bruno2.png";
if(player2=="hoseini.png") player2="hoseini2.png";

if(player1=="karim1.png") {logo1="real logo.png";fan1="real fan.png";}
if(player2=="karim2.png") {logo2="real logo.png";fan2="real fan.png";}
if(player1=="ronaldo1.png") {logo1="juve logo.png";fan1="juve fan.png";}
if(player2=="ronaldo2.png") {logo2="juve logo.png";fan2="juve fan.png";}
if(player1=="messi1.png") {logo1="barca logo.png";fan1="barca fan.png";}
if(player2=="messi2.png") {logo2="barca logo.png";fan2="barca fan.png";}
if(player1=="bruno1.png") {logo1="manu logo.png";fan1="manu fan.png";}
if(player2=="bruno2.png") {logo2="manu logo.png";fan2="manu fan.png";}
if(player1=="hoseini1.png") {logo1="persepolis logo.png";fan1="persepolis fan.png";}
if(player2=="hoseini2.png") {logo2="persepolis logo.png";fan2="persepolis fan.png";}

if(A==4)
{
   X+=1;
   while (game)
{
bool freeze1=false,freeze2=false;
if (power1==true)
            {
                if (player1=="messi1.png") kick1=true;
                if (player1=="ronaldo1.png") punch1=true;
                if (player1=="bruno1.png") invisible1=true;
                if (player1=="karim1.png") obstacle1=true;
                if (player1=="hoseini1.png") thief1=true;
                power1=false;
            }
if (power2==true)
            {
                if (player2=="messi2.png") kick2=true;
                if (player2=="ronaldo2.png") punch2=true;
                if (player2=="bruno2.png") invisible2=true;
                if (player2=="karim2.png") obstacle2=true;
                if (player2=="hoseini2.png") thief2=true;
                power2=false;
            }

///thief100000000000000000000000000000000000000000000000000000000000000000000000000000000000
if(thief1==true)
{
      //if(counter_Time%4==0) punch1=true;
      //if(counter_Time%4==1) invisible1=true;
      obstacle1=true;
      //if(counter_Time%4==3) kick1=true;
      thief1=false;
}
///thief100000000000000000000000000000000000000000000000000000000000000000000000000000000000

///thief200000000000000000000000000000000000000000000000000000000000000000000000000000000000
if(thief2==true)
{
      if(counter_Time%4==0) punch2=true;
      if(counter_Time%4==1) invisible2=true;
      if(counter_Time%4==2) obstacle2=true;
      if(counter_Time%4==3) kick2=true;
      thief2=false;
}
///thief200000000000000000000000000000000000000000000000000000000000000000000000000000000000

///punch1=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
if(punch1==true && xh1+40>xh2+80 && xh1-30<xh2+80)
{
      counter_Time_punch1=counter_Time;
      punch1=false;
}
if(counter_Time_punch1+1==counter_Time || counter_Time_punch1+2==counter_Time || counter_Time_punch1+3==counter_Time || counter_Time_punch1+4==counter_Time || counter_Time_punch1+5==counter_Time || counter_Time_punch1+6==counter_Time || counter_Time_punch1+7==counter_Time || counter_Time_punch1+8==counter_Time || counter_Time_punch1+9==counter_Time || counter_Time_punch1+10==counter_Time || counter_Time_punch1+11==counter_Time || counter_Time_punch1+12==counter_Time || counter_Time_punch1+13==counter_Time || counter_Time_punch1+14==counter_Time || counter_Time_punch1+15==counter_Time || counter_Time_punch1+16==counter_Time || counter_Time_punch1+17==counter_Time || counter_Time_punch1+18==counter_Time || counter_Time_punch1+19==counter_Time || counter_Time_punch1+20==counter_Time || counter_Time_punch1+21==counter_Time || counter_Time_punch1+22==counter_Time || counter_Time_punch1+23==counter_Time || counter_Time_punch1+24==counter_Time || counter_Time_punch1+25==counter_Time || counter_Time_punch1+26==counter_Time || counter_Time_punch1+27==counter_Time || counter_Time_punch1+28==counter_Time || counter_Time_punch1+29==counter_Time || counter_Time_punch1+30==counter_Time) freeze2=true;
///punch1=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=

///punch2/-\/-\/-\/-\/-\/-\/-\/-\/-\/-\/-\/-\/-\/-\/-\/-\/-\/-\/-\/-\/-\/-\/-\/-\/-\/-\/-\-
if(punch2==true && xh2+80>xh1-40 && xh2+80<xh1+10)
{
      counter_Time_punch2=counter_Time;
      punch2=false;
}
if(counter_Time_punch2+1==counter_Time || counter_Time_punch2+2==counter_Time || counter_Time_punch2+3==counter_Time || counter_Time_punch2+4==counter_Time || counter_Time_punch2+5==counter_Time || counter_Time_punch2+6==counter_Time || counter_Time_punch2+7==counter_Time || counter_Time_punch2+8==counter_Time || counter_Time_punch2+9==counter_Time || counter_Time_punch2+10==counter_Time || counter_Time_punch2+11==counter_Time || counter_Time_punch2+12==counter_Time || counter_Time_punch2+13==counter_Time || counter_Time_punch2+14==counter_Time || counter_Time_punch2+15==counter_Time || counter_Time_punch2+16==counter_Time || counter_Time_punch2+17==counter_Time || counter_Time_punch2+18==counter_Time || counter_Time_punch2+19==counter_Time || counter_Time_punch2+20==counter_Time || counter_Time_punch2+21==counter_Time || counter_Time_punch2+22==counter_Time || counter_Time_punch2+23==counter_Time || counter_Time_punch2+24==counter_Time || counter_Time_punch2+25==counter_Time || counter_Time_punch2+26==counter_Time || counter_Time_punch2+27==counter_Time || counter_Time_punch2+28==counter_Time || counter_Time_punch2+29==counter_Time || counter_Time_punch2+30==counter_Time) freeze1=true;
///punch2/-\/-\/-\/-\/-\/-\/-\/-\/-\/-\/-\/-\/-\/-\/-\/-\/-\/-\/-\/-\/-\/-\/-\/-\/-\/-\/-\-

///invisible1<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>
if(invisible1==true)
{
      counter_Time_invisible1=counter_Time;
      dy=-20;
      dx=-3;
      invisible1=false;
}
///invisible1<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>

///invisible2><-><-><-><-><-><-><-><-><-><-><-><-><-><-><-><-><-><-><-><-><-><-><-><-><-><
if(invisible2==true)
{
      counter_Time_invisible2=counter_Time;
      dy=-20;
      dx=50;
      invisible2=false;
}
///invisible2><-><-><-><-><-><-><-><-><-><-><-><-><-><-><-><-><-><-><-><-><-><-><-><-><-><

///obstacle1|^:^|^:^|^:^|^:^|^:^|^:^|^:^|^:^|^:^|^:^|^:^|^:^|^:^|^:^|^:^|^:^|^:^|^:^|^:^|^:^|
if(obstacle1==true)
{
      counter_Time_obstacle1=counter_Time;
      obstacle1=false;
}
///obstacle1|^:^|^:^|^:^|^:^|^:^|^:^|^:^|^:^|^:^|^:^|^:^|^:^|^:^|^:^|^:^|^:^|^:^|^:^|^:^|^:^|

///obstacle2################################################################################
if(obstacle2==true)
{
      counter_Time_obstacle2=counter_Time;
      obstacle2=false;
}
///obstacle2################################################################################

///kick1$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$
if(kick1==true)
{
      if(xh1-30>xb+40 && xh1-30<xb+150)
      {
      dx-=60;
      counter_Time_punch1=counter_Time;
      }
      kick1=false;
}
if(xb-20<xh2+45 && (counter_Time_punch1+1==counter_Time || counter_Time_punch1+3==counter_Time || counter_Time_punch1+5==counter_Time || counter_Time_punch1+7==counter_Time || counter_Time_punch1+9==counter_Time || counter_Time_punch1+11==counter_Time || counter_Time_punch1+13==counter_Time || counter_Time_punch1+15==counter_Time || counter_Time_punch1+17==counter_Time || counter_Time_punch1+19==counter_Time || counter_Time_punch1+21==counter_Time || counter_Time_punch1+23==counter_Time || counter_Time_punch1+25==counter_Time || counter_Time_punch1+27==counter_Time || counter_Time_punch1+29==counter_Time) ) {xh2-=80;dx+=45;dx=-dx;}
if(xb-20<xh2+45 && (counter_Time_punch1+2==counter_Time || counter_Time_punch1+4==counter_Time || counter_Time_punch1+6==counter_Time || counter_Time_punch1+8==counter_Time || counter_Time_punch1+10==counter_Time || counter_Time_punch1+12==counter_Time || counter_Time_punch1+14==counter_Time || counter_Time_punch1+16==counter_Time || counter_Time_punch1+18==counter_Time || counter_Time_punch1+20==counter_Time || counter_Time_punch1+22==counter_Time || counter_Time_punch1+24==counter_Time || counter_Time_punch1+26==counter_Time || counter_Time_punch1+28==counter_Time || counter_Time_punch1+30==counter_Time) ) {xh2-=80;dx+=45;dx=-dx;}
///kick1$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$

///kick2.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,
if(kick2==true)
{
      if(xh2+80<xb-10 && xh2+80>xb-120)
      {
      dx+=60;
      counter_Time_punch2=counter_Time;
      }
      kick2=false;
}
if(xb+45>xh1-20 && (counter_Time_punch2+1==counter_Time || counter_Time_punch2+3==counter_Time || counter_Time_punch2+5==counter_Time || counter_Time_punch2+7==counter_Time || counter_Time_punch2+9==counter_Time || counter_Time_punch2+11==counter_Time || counter_Time_punch2+13==counter_Time || counter_Time_punch2+15==counter_Time || counter_Time_punch2+17==counter_Time || counter_Time_punch2+19==counter_Time || counter_Time_punch2+21==counter_Time || counter_Time_punch2+23==counter_Time || counter_Time_punch2+25==counter_Time || counter_Time_punch2+27==counter_Time || counter_Time_punch2+29==counter_Time) ) {xh1+=80;dx-=57;dx=-dx;}
if(xb+45>xh1-20 && (counter_Time_punch2+2==counter_Time || counter_Time_punch2+4==counter_Time || counter_Time_punch2+6==counter_Time || counter_Time_punch2+8==counter_Time || counter_Time_punch2+10==counter_Time || counter_Time_punch2+12==counter_Time || counter_Time_punch2+14==counter_Time || counter_Time_punch2+16==counter_Time || counter_Time_punch2+18==counter_Time || counter_Time_punch2+20==counter_Time || counter_Time_punch2+22==counter_Time || counter_Time_punch2+24==counter_Time || counter_Time_punch2+26==counter_Time || counter_Time_punch2+28==counter_Time || counter_Time_punch2+30==counter_Time) ) {xh1+=80;dx-=57;dx=-dx;}
///kick2.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,.,

counter_Time++,counter1++;counter2++;
int xf1=xh1,yf1=yh1+50; ///x and y for shoe1
int xf2=xh2,yf2=yh2+50; ///x and y for shoe2
int xreferee=xb-50;///x referee
img_rect1.x = x1;///x picture of background
img_rect1.y = y1;///y picture of background
SDL_RenderCopy(m_renderer, m_texture, NULL, &img_rect1); ///picture of background
///texture(m_renderer,0,0,"background_game.png",1280,800); ///picture of background
texture(m_renderer,650,260,fan1,630,220); ///team1 fan
texture(m_renderer,0,260,fan2,650,220); ///team2 fan
my_line(m_renderer,1130,615,130,5.7,4,245,255,255); ///get line1
my_line(m_renderer,150,620,130,3.7,4,250,250,250); ///get line2

///picture of referee!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
if(xb>=1020) xreferee=975;///movement
if(xb<=200) xreferee=155;///movement
if(counter_Time==608 ||counter_Time==609 ||counter_Time==610 ||counter_Time==611 ||counter_Time==612 ||counter_Time==613 || counter_Time==614 || counter_Time==-2 ||counter_Time==-1 ||counter_Time==0 || counter_Time==1 || counter_Time==2 || counter_Time==3 || counter_Time==4 ||counter_Time==5 ||counter_Time==6 ||counter_Time_referee+1==counter_Time || counter_Time_referee+2==counter_Time || counter_Time_referee+3==counter_Time || counter_Time_referee+4==counter_Time || counter_Time_referee+5==counter_Time || counter_Time_referee+6==counter_Time || counter_Time_referee+7==counter_Time || counter_Time_referee+8==counter_Time ) texture(m_renderer,575,350,"referee2.png",150,150);
else texture(m_renderer,xreferee,350,"referee1.png",150,150);
texture(m_renderer,xreferee-100,320,"referee flag.png",120,120);
///picture of referee!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

texture(m_renderer,1127,370,"tir1.png",152,115); ///Part of the gate post1
texture(m_renderer,0,370,"tir2.png",152,115); ///Part of the gate post2
rect(m_renderer,xb,yb,20,20,0,155,25,0); ///ball
if(counter_Time_invisible1+1!=counter_Time && counter_Time_invisible1+2!=counter_Time && counter_Time_invisible1+3!=counter_Time && counter_Time_invisible1+4!=counter_Time && counter_Time_invisible1+5!=counter_Time && counter_Time_invisible1+6!=counter_Time && counter_Time_invisible1+7!=counter_Time && counter_Time_invisible1+8!=counter_Time && counter_Time_invisible1+9!=counter_Time && counter_Time_invisible1+10!=counter_Time && counter_Time_invisible1+11!=counter_Time && counter_Time_invisible1+12!=counter_Time && counter_Time_invisible1+13!=counter_Time && counter_Time_invisible1+14!=counter_Time && counter_Time_invisible1+15!=counter_Time && counter_Time_invisible1+16!=counter_Time && counter_Time_invisible1+17!=counter_Time && counter_Time_invisible1+18!=counter_Time && counter_Time_invisible1+19!=counter_Time && counter_Time_invisible1+20!=counter_Time && counter_Time_invisible1+21!=counter_Time && counter_Time_invisible1+22!=counter_Time && counter_Time_invisible1+23!=counter_Time && counter_Time_invisible1+24!=counter_Time && counter_Time_invisible1+25!=counter_Time && counter_Time_invisible1+26!=counter_Time && counter_Time_invisible1+27!=counter_Time && counter_Time_invisible1+28!=counter_Time && counter_Time_invisible1+29!=counter_Time && counter_Time_invisible1+30!=counter_Time   &&   counter_Time_invisible2+1!=counter_Time && counter_Time_invisible2+2!=counter_Time && counter_Time_invisible2+3!=counter_Time && counter_Time_invisible2+4!=counter_Time && counter_Time_invisible2+5!=counter_Time && counter_Time_invisible2+6!=counter_Time && counter_Time_invisible2+7!=counter_Time && counter_Time_invisible2+8!=counter_Time && counter_Time_invisible2+9!=counter_Time && counter_Time_invisible2+10!=counter_Time && counter_Time_invisible2+11!=counter_Time && counter_Time_invisible2+12!=counter_Time && counter_Time_invisible2+13!=counter_Time && counter_Time_invisible2+14!=counter_Time && counter_Time_invisible2+15!=counter_Time && counter_Time_invisible2+16!=counter_Time && counter_Time_invisible2+17!=counter_Time && counter_Time_invisible2+18!=counter_Time && counter_Time_invisible2+19!=counter_Time && counter_Time_invisible2+20!=counter_Time && counter_Time_invisible2+21!=counter_Time && counter_Time_invisible2+22!=counter_Time && counter_Time_invisible2+23!=counter_Time && counter_Time_invisible2+24!=counter_Time && counter_Time_invisible2+25!=counter_Time && counter_Time_invisible2+26!=counter_Time && counter_Time_invisible2+27!=counter_Time && counter_Time_invisible2+28!=counter_Time && counter_Time_invisible2+29!=counter_Time && counter_Time_invisible2+30!=counter_Time) texture(m_renderer,xb-20,yb-20,ball,70,70); ///picture of ball

///head1__________________________________________________________________________________
rect(m_renderer,xh1,yh1,40,50,0,155,25,0); ///head1
if(counter_Time<0) texture(m_renderer,xh1-10,yh1-45,player1,55,90); ///picture of head1
if(counter_Time%2==0 && counter_Time>=0)texture(m_renderer,xh1-10,yh1-45,player1,55,90); ///picture of head1
if(counter_Time%2==1 && counter_Time>=0)texture(m_renderer,xh1-10,yh1-43,player1,55,90); ///picture of head1
///head1__________________________________________________________________________________

///shoe1>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
rect(m_renderer,xf1,yf1,40,24,111,111,111,0); ///shoe1
if(counter_Time<0) texture(m_renderer,xf1-35,yf1-20,"shoe1.png",80,60); ///picture of shoe1
else if(counter_Time_shoot1+1==counter_Time || counter_Time_shoot1+2==counter_Time || counter_Time_shoot1+3==counter_Time || counter_Time_shoot1+4==counter_Time || counter_Time_shoot1+5==counter_Time || counter_Time_shoot1+6==counter_Time || counter_Time_shoot1+7==counter_Time) texture(m_renderer,xf1-50,yf1-50,"shoe1_shooting.png",100,100); ///picture of shoe1
else texture(m_renderer,xf1-35,yf1-20,"shoe1.png",80,60); ///picture of shoe1
///shoe1>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

///head2@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
rect(m_renderer,xh2,yh2,40,50,0,154,23,0); ///head2
if(counter_Time<0) texture(m_renderer,xh2-10,yh2-45,player2,55,90); ///picture of head2
if(counter_Time%2==0 && counter_Time>=0)texture(m_renderer,xh2-10,yh2-45,player2,55,90); ///picture of head2
if(counter_Time%2==1 && counter_Time>=0)texture(m_renderer,xh2-10,yh2-42,player2,55,90); ///picture of head2
///head2@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

///shoe2=============================================================================================================================================================================================================================================================================================================================================================
rect(m_renderer,xf2,yf2,40,24,111,111,111,0); ///shoe2
if(counter_Time_shoot2+1==counter_Time || counter_Time_shoot2+2==counter_Time || counter_Time_shoot2+3==counter_Time || counter_Time_shoot2+4==counter_Time || counter_Time_shoot2+5==counter_Time || counter_Time_shoot2+6==counter_Time || counter_Time_shoot2+7==counter_Time) texture(m_renderer,xf2-10,yf2-50,"shoe2_shooting.png",100,100); ///picture of shoe2
else texture(m_renderer,xf2-2,yf2-20,"shoe2.png",80,60); ///picture of shoe2
///shoe2=============================================================================================================================================================================================================================================================================================================================================================

texture(m_renderer,800,30,logo1,100,100); ///picture of team1 logo
texture(m_renderer,400,30,logo2,100,100); ///picture of team2 logo

if(xb<=40 && yb>=460)   {counter_Time_Goal=counter_Time;counter_Time_Goall=counter_Time;counter_Time_referee=counter_Time;score_1++;counter2+=100;xh1=1070;yh1=580;xh2=160;yh2=580;xb=625;yb=215;dy=10;dx=0;} ///score1
if(xb>=1200 && yb>=460) {counter_Time_Goal=counter_Time;counter_ab=counter_Time;counter_Time_referee=counter_Time;score_2++;counter1+=100;xh1=1070;yh1=580;xh2=160;yh2=580;xb=625;yb=215;dy=10;dx=0;} ///score2

/// picture of the score+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
if(score_1==0) score1="noll.png";
if(score_1==1) score1="one.png";
if(score_1==2) score1="two.png";
if(score_1==3) score1="three.png";
if(score_1==4) score1="four.png";
if(score_1==5) score1="five.png";
if(score_1==6) score1="six.png";
if(score_1==7) score1="seven.png";
texture(m_renderer,800,150,score1,60,50);
if(score_2==0) score2="noll.png";
if(score_2==1) score2="one.png";
if(score_2==2) score2="two.png";
if(score_2==3) score2="three.png";
if(score_2==4) score2="four.png";
if(score_2==5) score2="five.png";
if(score_2==6) score2="six.png";
if(score_2==7) score2="seven.png";
texture(m_renderer,400,150,score2,60,50);
/// picture of the score+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

texture(m_renderer,1180,10,"orange3.png",80,80);
texture(m_renderer,1050,25,"white3.png",350,300);

///movement of the ball------------------------------------------------------------------------------------------------------------------------------------
if(xh1>=xb+65 && xh1<=xb+75 && (xb-15>xh2+80||xb<xh2) && yh1<yb-25 && yh1>yb-85 && ball=="ball1.png") {Mix_PlayChannel(-1,kick,0);xb-=15;ball="ball2.png";}
if(xh1>=xb+65 && xh1<=xb+75 && (xb-15>xh2+80||xb<xh2) && yh1<yb-25 && yh1>yb-85 && ball=="ball2.png") {Mix_PlayChannel(-1,kick,0);xb-=15;ball="ball1.png";}
if(xh1>=xb+65 && xh1<=xb+75 && (xb-15>xh2+80||xb<xh2) && yh1<yb-25 && yh1>yb-85 && ball=="ball3.png") {Mix_PlayChannel(-1,kick,0);xb-=15;ball="ball4.png";}
if(xh1>=xb+65 && xh1<=xb+75 && (xb-15>xh2+80||xb<xh2) && yh1<yb-25 && yh1>yb-85 && ball=="ball4.png") {Mix_PlayChannel(-1,kick,0);xb-=15;ball="ball3.png";}

if(xh1<=xb-55 && xh1>=xb-65 && (xb+15<xh2-50||xb>xh2) && yh1<yb-25 && yh1>yb-85 && ball=="ball1.png" && xb!=1210) {Mix_PlayChannel(-1,kick,0);xb+=15;ball="ball2.png";}
if(xh1<=xb-55 && xh1>=xb-65 && (xb+15<xh2-50||xb>xh2) && yh1<yb-25 && yh1>yb-85 && ball=="ball2.png" && xb!=1210) {Mix_PlayChannel(-1,kick,0);xb+=15;ball="ball1.png";}
if(xh1<=xb-55 && xh1>=xb-65 && (xb+15<xh2-50||xb>xh2) && yh1<yb-25 && yh1>yb-85 && ball=="ball3.png" && xb!=1210) {Mix_PlayChannel(-1,kick,0);xb+=15;ball="ball4.png";}
if(xh1<=xb-55 && xh1>=xb-65 && (xb+15<xh2-50||xb>xh2) && yh1<yb-25 && yh1>yb-85 && ball=="ball4.png" && xb!=1210) {Mix_PlayChannel(-1,kick,0);xb+=15;ball="ball3.png";}

if(xh2>=xb+45 && xh2<=xb+55 && (xb-15>xh1+60||xb<xh1) && yh2<yb-25 && yh2>yb-85 && ball=="ball1.png" && xb!=40) {Mix_PlayChannel(-1,kick,0);xb-=15; ball="ball2.png";}
if(xh2>=xb+45 && xh2<=xb+55 && (xb-15>xh1+60||xb<xh1) && yh2<yb-25 && yh2>yb-85 && ball=="ball2.png" && xb!=40) {Mix_PlayChannel(-1,kick,0);xb-=15; ball="ball1.png";}
if(xh2>=xb+45 && xh2<=xb+55 && (xb-15>xh1+60||xb<xh1) && yh2<yb-25 && yh2>yb-85 && ball=="ball3.png" && xb!=40) {Mix_PlayChannel(-1,kick,0);xb-=15; ball="ball4.png";}
if(xh2>=xb+45 && xh2<=xb+55 && (xb-15>xh1+60||xb<xh1) && yh2<yb-25 && yh2>yb-85 && ball=="ball4.png" && xb!=40) {Mix_PlayChannel(-1,kick,0);xb-=15; ball="ball3.png";}

if(xh2<=xb-80 && xh2>=xb-90 && (xb+15<xh1-70||xb>xh1) && yh2<yb-25 && yh2>yb-85 && ball=="ball1.png") {Mix_PlayChannel(-1,kick,0);xb+=15;ball="ball2.png";}
if(xh2<=xb-80 && xh2>=xb-90 && (xb+15<xh1-70||xb>xh1) && yh2<yb-25 && yh2>yb-85 && ball=="ball2.png") {Mix_PlayChannel(-1,kick,0);xb+=15;ball="ball1.png";}
if(xh2<=xb-80 && xh2>=xb-90 && (xb+15<xh1-70||xb>xh1) && yh2<yb-25 && yh2>yb-85 && ball=="ball3.png") {Mix_PlayChannel(-1,kick,0);xb+=15;ball="ball4.png";}
if(xh2<=xb-80 && xh2>=xb-90 && (xb+15<xh1-70||xb>xh1) && yh2<yb-25 && yh2>yb-85 && ball=="ball4.png") {Mix_PlayChannel(-1,kick,0);xb+=15;ball="ball3.png";}
///movement of the ball------------------------------------------------------------------------------------------------------------------------------------------------


if(xb>55 && xb<170 && yb<400 && yb>340 && dx<0) dx=-dx;///when The ball hits the left post
if(xb>1140 && xb<1255 && yb<400 && yb>340 && dx>0) dx=-dx;///when The ball hits the right post
if(xb<=20 || xb>=1230) dx=-dx;///when The ball hits the left or right wall
if(yb<=100) dy=-dy; ///when The ball hits the sky

///ball's hight and dx - dy***************************************************************************
yb+=dy;
dy+=1.5;
if (yb>608 && dy!=0)
{
    if (dy<=3 && dy>0)
    {
        dy=0;
    }
    else dy=(-0.6)*dy;
}
if (yb>608 && dy==0) yb=615;

xb+=dx;
dx-=1.5;
if ( (dx<=3 && dx>0) || (dx>=-3 && dx<0) ) dx=0;
if( (xb<=40 || xb>=1200) && yb>=460) dx=0;
if(counter_Time>=611) {dx=0;dy=0;}///the ball doesn't move after the game
///ball's hight and dx - dy***************************************************************************

if(xb+50>xh1-10 && xb+50<xh1+20 && yb-45<yh1-10 && yb-45>yh1-120) {dx-=5;dx=-dx;}///barkhord toop ba harif
if(xb-20<xh2+40 && xb-20>xh2+10 && yb-45<yh2-10 && yb-45>yh2-120) {dx+=5;dx=-dx;}///barkhord toop ba harif

if(counter_Time_shoot1+1==counter_Time && xh1-30<xb+70 && xh1-30>xb+20 && yb>600){dy=-22;dx=-3;}///shoot1 noke pa
else if(counter_Time_shoot1+1==counter_Time && xh1-30<xb+70 && xh1-30>xb+20 && yb<600){dy=-22;dx=-2;}///shoot1 rooye pa
if(counter_Time_shoot2+1==counter_Time && xh2+80>xb-30 && xh2+80<xb && yb>600){dy=-20;dx=50;}///shoot2 noke pa
else if(counter_Time_shoot2+1==counter_Time && xh2+80>xb-30 && xh2+80<xb && yb<600){dy=-20;dx=15;}///shoot2 rooye pa

///picture of stars'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'
if(counter_Time_punch1+1==counter_Time || counter_Time_punch1+3==counter_Time || counter_Time_punch1+5==counter_Time || counter_Time_punch1+7==counter_Time || counter_Time_punch1+9==counter_Time || counter_Time_punch1+11==counter_Time || counter_Time_punch1+13==counter_Time || counter_Time_punch1+15==counter_Time || counter_Time_punch1+17==counter_Time || counter_Time_punch1+19==counter_Time || counter_Time_punch1+21==counter_Time || counter_Time_punch1+23==counter_Time || counter_Time_punch1+25==counter_Time || counter_Time_punch1+27==counter_Time || counter_Time_punch1+29==counter_Time) texture(m_renderer,xh2-10,yh2-85,"star1.png",100,70);
if(counter_Time_punch1+2==counter_Time || counter_Time_punch1+4==counter_Time || counter_Time_punch1+6==counter_Time || counter_Time_punch1+8==counter_Time || counter_Time_punch1+10==counter_Time || counter_Time_punch1+12==counter_Time || counter_Time_punch1+14==counter_Time || counter_Time_punch1+16==counter_Time || counter_Time_punch1+18==counter_Time || counter_Time_punch1+20==counter_Time || counter_Time_punch1+22==counter_Time || counter_Time_punch1+24==counter_Time || counter_Time_punch1+26==counter_Time || counter_Time_punch1+28==counter_Time || counter_Time_punch1+30==counter_Time) texture(m_renderer,xh2-30,yh2-85,"star2.png",100,70);

if(counter_Time_punch2+1==counter_Time || counter_Time_punch2+3==counter_Time || counter_Time_punch2+5==counter_Time || counter_Time_punch2+7==counter_Time || counter_Time_punch2+9==counter_Time || counter_Time_punch2+11==counter_Time || counter_Time_punch2+13==counter_Time || counter_Time_punch2+15==counter_Time || counter_Time_punch2+17==counter_Time || counter_Time_punch2+19==counter_Time || counter_Time_punch2+21==counter_Time || counter_Time_punch2+23==counter_Time || counter_Time_punch2+25==counter_Time || counter_Time_punch2+27==counter_Time || counter_Time_punch2+29==counter_Time) texture(m_renderer,xh1-15,yh1-85,"star1.png",100,70);
if(counter_Time_punch2+2==counter_Time || counter_Time_punch2+4==counter_Time || counter_Time_punch2+6==counter_Time || counter_Time_punch2+8==counter_Time || counter_Time_punch2+10==counter_Time || counter_Time_punch2+12==counter_Time || counter_Time_punch2+14==counter_Time || counter_Time_punch2+16==counter_Time || counter_Time_punch2+18==counter_Time || counter_Time_punch2+20==counter_Time || counter_Time_punch2+22==counter_Time || counter_Time_punch2+24==counter_Time || counter_Time_punch2+26==counter_Time || counter_Time_punch2+28==counter_Time || counter_Time_punch2+30==counter_Time) texture(m_renderer,xh1-15,yh1-85,"star2.png",100,70);
///picture of stars'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'"'

///picture of rock-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
if(counter_Time_obstacle1+1==counter_Time || counter_Time_obstacle1+2==counter_Time || counter_Time_obstacle1+3==counter_Time || counter_Time_obstacle1+4==counter_Time || counter_Time_obstacle1+5==counter_Time || counter_Time_obstacle1+6==counter_Time || counter_Time_obstacle1+7==counter_Time || counter_Time_obstacle1+8==counter_Time || counter_Time_obstacle1+9==counter_Time || counter_Time_obstacle1+10==counter_Time || counter_Time_obstacle1+11==counter_Time || counter_Time_obstacle1+12==counter_Time || counter_Time_obstacle1+13==counter_Time || counter_Time_obstacle1+14==counter_Time || counter_Time_obstacle1+15==counter_Time || counter_Time_obstacle1+16==counter_Time || counter_Time_obstacle1+17==counter_Time || counter_Time_obstacle1+18==counter_Time || counter_Time_obstacle1+19==counter_Time || counter_Time_obstacle1+20==counter_Time || counter_Time_obstacle1+21==counter_Time || counter_Time_obstacle1+22==counter_Time || counter_Time_obstacle1+23==counter_Time || counter_Time_obstacle1+24==counter_Time || counter_Time_obstacle1+25==counter_Time || counter_Time_obstacle1+26==counter_Time || counter_Time_obstacle1+27==counter_Time || counter_Time_obstacle1+28==counter_Time || counter_Time_obstacle1+29==counter_Time || counter_Time_obstacle1+30==counter_Time)
{
texture(m_renderer,1135,385,"rock.png",100,270);
if(xb+40>=1135) dx=-dx;
}

if(counter_Time_obstacle2+1==counter_Time || counter_Time_obstacle2+2==counter_Time || counter_Time_obstacle2+3==counter_Time || counter_Time_obstacle2+4==counter_Time || counter_Time_obstacle2+5==counter_Time || counter_Time_obstacle2+6==counter_Time || counter_Time_obstacle2+7==counter_Time || counter_Time_obstacle2+8==counter_Time || counter_Time_obstacle2+9==counter_Time || counter_Time_obstacle2+10==counter_Time || counter_Time_obstacle2+11==counter_Time || counter_Time_obstacle2+12==counter_Time || counter_Time_obstacle2+13==counter_Time || counter_Time_obstacle2+14==counter_Time || counter_Time_obstacle2+15==counter_Time || counter_Time_obstacle2+16==counter_Time || counter_Time_obstacle2+17==counter_Time || counter_Time_obstacle2+18==counter_Time || counter_Time_obstacle2+19==counter_Time || counter_Time_obstacle2+20==counter_Time || counter_Time_obstacle2+21==counter_Time || counter_Time_obstacle2+22==counter_Time || counter_Time_obstacle2+23==counter_Time || counter_Time_obstacle2+24==counter_Time || counter_Time_obstacle2+25==counter_Time || counter_Time_obstacle2+26==counter_Time || counter_Time_obstacle2+27==counter_Time || counter_Time_obstacle2+28==counter_Time || counter_Time_obstacle2+29==counter_Time || counter_Time_obstacle2+30==counter_Time)
{
texture(m_renderer,40,390,"rock.png",105,270);
if(xb-10<=145) dx=-dx;
}
///picture of rock-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+


///power1..................................................................................
my_line(m_renderer,960,80,70,0.2,5,0,255,0);
my_line(m_renderer,1025,67,85,0.2,6,255,235,0);
my_line(m_renderer,1160,40,60,3.34,8,255,135,0);
my_line(m_renderer,960,80,200,-0.2,5,0,255,0);
my_line(m_renderer,1025,94,85,-0.2,6,255,235,0);
my_line(m_renderer,1160,121,60,-3.34,8,255,135,0);
my_line(m_renderer,1158,40,80,4.7124,5,255,0,0);

if(counter1>=15)my_line(m_renderer,975,77,6,4.7124,25,40,255,0);
if(counter1>=30)my_line(m_renderer,990,74,12,4.7124,15,40,255,0);
if(counter1>=45)my_line(m_renderer,1004,71,18,4.7124,15,130,255,0);
if(counter1>=60)my_line(m_renderer,1017,68,24,4.7124,15,170,255,0);
if(counter1>=75)my_line(m_renderer,1032,66,30,4.7124,15,200,255,0);
if(counter1>=90)my_line(m_renderer,1047,63,36,4.7124,15,235,255,0);
if(counter1>=105)my_line(m_renderer,1062,60,43,4.7124,15,255,235,0);
if(counter1>=120)my_line(m_renderer,1077,57,50,4.7124,15,255,215,0);
if(counter1>=135)my_line(m_renderer,1092,54,56,4.7124,15,255,190,0);
if(counter1>=150)my_line(m_renderer,1105,51,62,4.7124,15,255,160,0);
if(counter1>=175)my_line(m_renderer,1120,48,66,4.7124,15,255,125,0);
if(counter1>=190)my_line(m_renderer,1135,45,70,4.7124,15,255,80,0);
if(counter1>=205)my_line(m_renderer,1148,42,74,4.7124,20,255,0,0);
///power1..................................................................................

///power2----------------------------------------------------------------------------------
my_line(m_renderer,100,40,200,-0.2,5,0,255,0);
my_line(m_renderer,100,40,130,-0.2,6,255,235,0);
my_line(m_renderer,100,40,60,-0.2,8,255,135,0);
my_line(m_renderer,100,120,200,0.2,5,0,255,0);
my_line(m_renderer,100,120,130,0.2,6,255,235,0);
my_line(m_renderer,100,120,60,0.2,8,255,135,0);
my_line(m_renderer,100,40,80,4.7124,5,255,0,0);

if(counter2>=15)my_line(m_renderer,280,77,5,4.7124,17,0,255,0);
if(counter2>=30)my_line(m_renderer,262,73,13,4.7124,25,40,255,0);
if(counter2>=45)my_line(m_renderer,245,70,19,4.7124,20,130,255,0);
if(counter2>=60)my_line(m_renderer,230,67,25,4.7124,20,170,255,0);
if(counter2>=75)my_line(m_renderer,217,64,31,4.7124,15,200,255,0);
if(counter2>=90)my_line(m_renderer,205,61,37,4.7124,15,235,255,0);
if(counter2>=105)my_line(m_renderer,195,60,40,4.7124,15,255,235,0);
if(counter2>=120)my_line(m_renderer,180,57,46,4.7124,15,255,215,0);
if(counter2>=135)my_line(m_renderer,165,54,53,4.7124,15,255,190,0);
if(counter2>=150)my_line(m_renderer,150,51,58,4.7124,15,255,160,0);
if(counter2>=175)my_line(m_renderer,135,47,65,4.7124,15,255,125,0);
if(counter2>=190)my_line(m_renderer,123,45,70,4.7124,15,255,80,0);
if(counter2>=205)my_line(m_renderer,108,42,75,4.7124,15,255,0,0);
///power2----------------------------------------------------------------------------------

///helicopter>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
if(counter_Time>=370 && counter_Time<=530)
{
xhel+=10;
yhel-=0.5;
}

if(counter_Time>=370 && counter_Time<=530)
{
texture(m_renderer,xhel,yhel,"helicopter.png",400,300);///picture of helicopter
texture(m_renderer,xhel+210,yhel+115,"shapoori.png",100,100);///picture of Mr.Shapoori
}
///helicopter>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>

if(yh1-24==yb-115 && xb-75<xh1-30 && xh1-30<xb+35) yh1=519;///Standing on the ball
else {
///jump1=========================================================================================================================================================================================================================
if(yh1==575 || yh1==570 || yh1==565 || yh1==560 || yh1==555 || yh1==550 || yh1==545 || yh1==540 || yh1==535 || yh1==530 || yh1==525 || yh1==520 || yh1==515 || yh1==510 || yh1==505 || yh1==500 || yh1==495) yh1-=5;
if(yh1==490) yh1-=6;
if(yh1==484 || yh1==489 || yh1==494 || yh1==499 || yh1==504 || yh1==509 || yh1==514 || yh1==519 || yh1==524 || yh1==529 || yh1==534 || yh1==539 || yh1==544 || yh1==549 || yh1==554 || yh1==559 || yh1==564 || yh1==569) yh1+=5;
if(yh1==574) yh1+=6;
///jump1=========================================================================================================================================================================================================================
}

if(yh2-24==yb-115 && xb-85<xh2 && xh2<xb+35) yh2=519;///Standing on the ball
else {
///jump2/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
if(yh2==575 || yh2==570 || yh2==565 || yh2==560 || yh2==555 || yh2==550 || yh2==545 || yh2==540 || yh2==535 || yh2==530 || yh2==525 || yh2==520 || yh2==515 || yh2==510 || yh2==505 || yh2==500 || yh2==495) yh2-=5;
if(yh2==490) yh2-=6;
if(yh2==484 || yh2==489 || yh2==494 || yh2==499 || yh2==504 || yh2==509 || yh2==514 || yh2==519 || yh2==524 || yh2==529 || yh2==534 || yh2==539 || yh2==544 || yh2==549 || yh2==554 || yh2==559 || yh2==564 || yh2==569) yh2+=5;
if(yh2==574) yh2+=6;
///jump1////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
}

ellipse(m_renderer,646,69,9,9,200,200,200,1);/// Not important thing
ellipse(m_renderer,636,102,9,9,200,200,200,1);/// Not important thing

const char * font_address_00="arial.ttf";
const char * font_address_01="IranNastaliq.ttf";
const char * font_address_02="HARLOWSI.ttf";
const char * font_address_03="MAGNETOB.ttf";

///Celebration after the game_____________________________________________________________________________________________________________________________________________________________________________________________________________________________
if(score_1>score_2)
{
if(counter_Time==611 || counter_Time==612) {texture(m_renderer,0,-320,"celebration.png",1200,800);SDL_Color text_color = {50,55,255};const char * text ="Team 1 is winner";textColor(m_renderer,270,320,text,font_address_00 ,120,text_color,0.0,0);}
if(counter_Time==613 || counter_Time==614) {texture(m_renderer,0,-280,"celebration.png",1200,800);SDL_Color text_color = {255,0,0};const char * text ="Team 1 is winner";textColor(m_renderer,270,380,text,font_address_00 ,120,text_color,0.0,0);}
if(counter_Time==615 || counter_Time==616) {texture(m_renderer,0,-240,"celebration.png",1200,800);SDL_Color text_color = {0,255,0};const char * text ="Team 1 is winner";textColor(m_renderer,270,320,text,font_address_00 ,120,text_color,0.0,0);}
if(counter_Time==617 || counter_Time==618) {texture(m_renderer,0,-200,"celebration.png",1200,800);SDL_Color text_color = {255,255,0};const char * text ="Team 1 is winner";textColor(m_renderer,270,380,text,font_address_00 ,120,text_color,0.0,0);}
if(counter_Time==619 || counter_Time==620) {texture(m_renderer,0,-160,"celebration.png",1200,800);SDL_Color text_color = {255,155,0};const char * text ="Team 1 is winner";textColor(m_renderer,270,320,text,font_address_00 ,120,text_color,0.0,0);}
if(counter_Time==621 || counter_Time==622) {texture(m_renderer,0,-120,"celebration.png",1200,800);SDL_Color text_color = {100,100,100};const char * text ="Team 1 is winner";textColor(m_renderer,270,380,text,font_address_00 ,120,text_color,0.0,0);}
if(counter_Time==623 || counter_Time==624) {texture(m_renderer,0,-80,"celebration.png",1200,800);SDL_Color text_color = {100,0,100};const char * text ="Team 1 is winner";textColor(m_renderer,270,320,text,font_address_00 ,120,text_color,0.0,0);}
if(counter_Time==625 || counter_Time==626) {texture(m_renderer,0,-40,"celebration.png",1200,800);SDL_Color text_color = {0,0,0};const char * text ="Team 1 is winner";textColor(m_renderer,270,380,text,font_address_00 ,120,text_color,0.0,0);}
if(counter_Time==627 || counter_Time==628) {texture(m_renderer,0,0,"celebration.png",1200,800);SDL_Color text_color = {160,82,45};const char * text ="Team 1 is winner";textColor(m_renderer,270,320,text,font_address_00 ,120,text_color,0.0,0);}
if(counter_Time==629 || counter_Time==630) {texture(m_renderer,0,40,"celebration.png",1200,800);SDL_Color text_color = {70,130,180};const char * text ="Team 1 is winner";textColor(m_renderer,270,380,text,font_address_00 ,120,text_color,0.0,0);}
if(counter_Time==631 || counter_Time==632) {texture(m_renderer,0,80,"celebration.png",1200,800);SDL_Color text_color = {255,0,0};const char * text ="Team 1 is winner";textColor(m_renderer,270,320,text,font_address_00 ,120,text_color,0.0,0);}
if(counter_Time==633 || counter_Time==634) {texture(m_renderer,0,120,"celebration.png",1200,800);SDL_Color text_color = {155,255,};const char * text ="Team 1 is winner";textColor(m_renderer,270,380,text,font_address_00 ,120,text_color,0.0,0);}
if(counter_Time==635 || counter_Time==636) {texture(m_renderer,0,160,"celebration.png",1200,800);SDL_Color text_color = {255,255,255};const char * text ="Team 1 is winner";textColor(m_renderer,270,320,text,font_address_00 ,120,text_color,0.0,0);}
}
if(score_2>score_1)
{
if(counter_Time==611 || counter_Time==612) {texture(m_renderer,0,-320,"celebration.png",1200,800);SDL_Color text_color = {50,55,255};const char * text ="Team 2 is winner";textColor(m_renderer,270,320,text,font_address_00 ,120,text_color,0.0,0);}
if(counter_Time==613 || counter_Time==614) {texture(m_renderer,0,-280,"celebration.png",1200,800);SDL_Color text_color = {255,0,0};const char * text ="Team 2 is winner";textColor(m_renderer,270,380,text,font_address_00 ,120,text_color,0.0,0);}
if(counter_Time==615 || counter_Time==616) {texture(m_renderer,0,-240,"celebration.png",1200,800);SDL_Color text_color = {0,255,0};const char * text ="Team 2 is winner";textColor(m_renderer,270,320,text,font_address_00 ,120,text_color,0.0,0);}
if(counter_Time==617 || counter_Time==618) {texture(m_renderer,0,-200,"celebration.png",1200,800);SDL_Color text_color = {255,255,0};const char * text ="Team 2 is winner";textColor(m_renderer,270,380,text,font_address_00 ,120,text_color,0.0,0);}
if(counter_Time==619 || counter_Time==620) {texture(m_renderer,0,-160,"celebration.png",1200,800);SDL_Color text_color = {255,155,0};const char * text ="Team 2 is winner";textColor(m_renderer,270,320,text,font_address_00 ,120,text_color,0.0,0);}
if(counter_Time==621 || counter_Time==622) {texture(m_renderer,0,-120,"celebration.png",1200,800);SDL_Color text_color = {100,100,100};const char * text ="Team 2 is winner";textColor(m_renderer,270,380,text,font_address_00 ,120,text_color,0.0,0);}
if(counter_Time==623 || counter_Time==624) {texture(m_renderer,0,-80,"celebration.png",1200,800);SDL_Color text_color = {100,0,100};const char * text ="Team 2 is winner";textColor(m_renderer,270,320,text,font_address_00 ,120,text_color,0.0,0);}
if(counter_Time==625 || counter_Time==626) {texture(m_renderer,0,-40,"celebration.png",1200,800);SDL_Color text_color = {0,0,0};const char * text ="Team 2 is winner";textColor(m_renderer,270,380,text,font_address_00 ,120,text_color,0.0,0);}
if(counter_Time==627 || counter_Time==628) {texture(m_renderer,0,0,"celebration.png",1200,800);SDL_Color text_color = {160,82,45};const char * text ="Team 2 is winner";textColor(m_renderer,270,320,text,font_address_00 ,120,text_color,0.0,0);}
if(counter_Time==629 || counter_Time==630) {texture(m_renderer,0,40,"celebration.png",1200,800);SDL_Color text_color = {70,130,180};const char * text ="Team 2 is winner";textColor(m_renderer,270,380,text,font_address_00 ,120,text_color,0.0,0);}
if(counter_Time==631 || counter_Time==632) {texture(m_renderer,0,80,"celebration.png",1200,800);SDL_Color text_color = {255,0,0};const char * text ="Team 2 is winner";textColor(m_renderer,270,320,text,font_address_00 ,120,text_color,0.0,0);}
if(counter_Time==633 || counter_Time==634) {texture(m_renderer,0,120,"celebration.png",1200,800);SDL_Color text_color = {155,255,};const char * text ="Team 2 is winner";textColor(m_renderer,270,380,text,font_address_00 ,120,text_color,0.0,0);}
if(counter_Time==635 || counter_Time==636) {texture(m_renderer,0,160,"celebration.png",1200,800);SDL_Color text_color = {255,255,255};const char * text ="Team 2 is winner";textColor(m_renderer,270,320,text,font_address_00 ,120,text_color,0.0,0);}
}
if(score_1==score_2)
{
if(counter_Time==611 || counter_Time==612) {SDL_Color text_color = {50,55,255};const char * text ="Draw";textColor(m_renderer,470,300,text,font_address_00 ,180,text_color,0.0,0);}
if(counter_Time==613 || counter_Time==614) {SDL_Color text_color = {255,0,0};const char * text ="Draw";textColor(m_renderer,470,360,text,font_address_00 ,180,text_color,0.0,0);}
if(counter_Time==615 || counter_Time==616) {SDL_Color text_color = {0,255,0};const char * text ="Draw";textColor(m_renderer,470,300,text,font_address_00 ,180,text_color,0.0,0);}
if(counter_Time==617 || counter_Time==618) {SDL_Color text_color = {255,255,0};const char * text ="Draw";textColor(m_renderer,470,360,text,font_address_00 ,180,text_color,0.0,0);}
if(counter_Time==619 || counter_Time==620) {SDL_Color text_color = {255,155,0};const char * text ="Draw";textColor(m_renderer,470,300,text,font_address_00 ,180,text_color,0.0,0);}
if(counter_Time==621 || counter_Time==622) {SDL_Color text_color = {100,250,100};const char * text ="Draw";textColor(m_renderer,470,360,text,font_address_00 ,180,text_color,0.0,0);}
if(counter_Time==623 || counter_Time==624) {SDL_Color text_color = {100,0,100};const char * text ="Draw";textColor(m_renderer,470,300,text,font_address_00 ,180,text_color,0.0,0);}
if(counter_Time==625 || counter_Time==626) {SDL_Color text_color = {0,255,0};const char * text ="Draw";textColor(m_renderer,470,360,text,font_address_00 ,180,text_color,0.0,0);}
if(counter_Time==627 || counter_Time==628) {SDL_Color text_color = {160,82,45};const char * text ="Draw";textColor(m_renderer,470,300,text,font_address_00 ,180,text_color,0.0,0);}
if(counter_Time==629 || counter_Time==630) {SDL_Color text_color = {150,135,235};const char * text ="Draw";textColor(m_renderer,470,360,text,font_address_00 ,180,text_color,0.0,0);}
if(counter_Time==631 || counter_Time==632) {SDL_Color text_color = {255,0,0};const char * text ="Draw";textColor(m_renderer,470,300,text,font_address_00 ,180,text_color,0.0,0);}
if(counter_Time==633 || counter_Time==634) {SDL_Color text_color = {155,255,0};const char * text ="Draw";textColor(m_renderer,470,360,text,font_address_00 ,180,text_color,0.0,0);}
if(counter_Time==635 || counter_Time==636) {SDL_Color text_color = {50,55,255};const char * text ="Draw";textColor(m_renderer,470,300,text,font_address_00 ,180,text_color,0.0,0);}
}
///Celebration after the game_____________________________________________________________________________________________________________________________________________________________________________________________________________________________

///show time on score board::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
if(counter_Time>=1 && counter_Time<=10) {SDL_Color text_color = {0,225,0};const char * text ="60";textColor(m_renderer,600,50,text,font_address_03 ,85,text_color,0.0,0);}
if(counter_Time>=11 && counter_Time<=20) {SDL_Color text_color = {0,225,0};const char * text ="59";textColor(m_renderer,600,50,text,font_address_03 ,85,text_color,0.0,0);}
if(counter_Time>=21 && counter_Time<=30) {SDL_Color text_color = {0,225,0};const char * text ="58";textColor(m_renderer,600,50,text,font_address_03 ,85,text_color,0.0,0);}
if(counter_Time>=31 && counter_Time<=40) {SDL_Color text_color = {0,225,0};const char * text ="57";textColor(m_renderer,600,50,text,font_address_03 ,85,text_color,0.0,0);}
if(counter_Time>=41 && counter_Time<=50) {SDL_Color text_color = {0,225,0};const char * text ="56";textColor(m_renderer,600,50,text,font_address_03 ,85,text_color,0.0,0);}
if(counter_Time>=51 && counter_Time<=60) {SDL_Color text_color = {0,225,0};const char * text ="55";textColor(m_renderer,600,50,text,font_address_03 ,85,text_color,0.0,0);}
if(counter_Time>=61 && counter_Time<=70) {SDL_Color text_color = {0,225,0};const char * text ="54";textColor(m_renderer,600,50,text,font_address_03 ,85,text_color,0.0,0);}
if(counter_Time>=71 && counter_Time<=80) {SDL_Color text_color = {0,225,0};const char * text ="53";textColor(m_renderer,600,50,text,font_address_03 ,85,text_color,0.0,0);}
if(counter_Time>=81 && counter_Time<=90) {SDL_Color text_color = {0,225,0};const char * text ="52";textColor(m_renderer,600,50,text,font_address_03 ,85,text_color,0.0,0);}
if(counter_Time>=91 && counter_Time<=100) {SDL_Color text_color = {0,225,0};const char * text ="51";textColor(m_renderer,600,50,text,font_address_03 ,85,text_color,0.0,0);}
if(counter_Time>=101 && counter_Time<=110) {SDL_Color text_color = {0,225,0};const char * text ="50";textColor(m_renderer,600,50,text,font_address_03 ,85,text_color,0.0,0);}
if(counter_Time>=111 && counter_Time<=120) {SDL_Color text_color = {0,225,0};const char * text ="49";textColor(m_renderer,600,50,text,font_address_03 ,85,text_color,0.0,0);}
if(counter_Time>=121 && counter_Time<=130) {SDL_Color text_color = {0,225,0};const char * text ="48";textColor(m_renderer,600,50,text,font_address_03 ,85,text_color,0.0,0);}
if(counter_Time>=131 && counter_Time<=140) {SDL_Color text_color = {0,225,0};const char * text ="47";textColor(m_renderer,600,50,text,font_address_03 ,85,text_color,0.0,0);}
if(counter_Time>=141 && counter_Time<=150) {SDL_Color text_color = {0,225,0};const char * text ="46";textColor(m_renderer,600,50,text,font_address_03 ,85,text_color,0.0,0);}
if(counter_Time>=151 && counter_Time<=160) {SDL_Color text_color = {0,225,0};const char * text ="45";textColor(m_renderer,600,50,text,font_address_03 ,85,text_color,0.0,0);}
if(counter_Time>=161 && counter_Time<=170) {SDL_Color text_color = {0,225,0};const char * text ="44";textColor(m_renderer,600,50,text,font_address_03 ,85,text_color,0.0,0);}
if(counter_Time>=171 && counter_Time<=180) {SDL_Color text_color = {0,225,0};const char * text ="43";textColor(m_renderer,600,50,text,font_address_03 ,85,text_color,0.0,0);}
if(counter_Time>=181 && counter_Time<=190) {SDL_Color text_color = {0,225,0};const char * text ="42";textColor(m_renderer,600,50,text,font_address_03 ,85,text_color,0.0,0);}
if(counter_Time>=191 && counter_Time<=200) {SDL_Color text_color = {0,225,0};const char * text ="41";textColor(m_renderer,600,50,text,font_address_03 ,85,text_color,0.0,0);}
if(counter_Time>=201 && counter_Time<=210) {SDL_Color text_color = {0,225,0};const char * text ="40";textColor(m_renderer,600,50,text,font_address_03 ,85,text_color,0.0,0);}
if(counter_Time>=211 && counter_Time<=220) {SDL_Color text_color = {0,225,0};const char * text ="39";textColor(m_renderer,600,50,text,font_address_03 ,85,text_color,0.0,0);}
if(counter_Time>=221 && counter_Time<=230) {SDL_Color text_color = {0,225,0};const char * text ="38";textColor(m_renderer,600,50,text,font_address_03 ,85,text_color,0.0,0);}
if(counter_Time>=231 && counter_Time<=240) {SDL_Color text_color = {0,225,0};const char * text ="37";textColor(m_renderer,600,50,text,font_address_03 ,85,text_color,0.0,0);}
if(counter_Time>=241 && counter_Time<=250) {SDL_Color text_color = {0,225,0};const char * text ="36";textColor(m_renderer,600,50,text,font_address_03 ,85,text_color,0.0,0);}
if(counter_Time>=251 && counter_Time<=260) {SDL_Color text_color = {0,225,0};const char * text ="35";textColor(m_renderer,600,50,text,font_address_03 ,85,text_color,0.0,0);}
if(counter_Time>=261 && counter_Time<=270) {SDL_Color text_color = {0,225,0};const char * text ="34";textColor(m_renderer,600,50,text,font_address_03 ,85,text_color,0.0,0);}
if(counter_Time>=271 && counter_Time<=280) {SDL_Color text_color = {0,225,0};const char * text ="33";textColor(m_renderer,600,50,text,font_address_03 ,85,text_color,0.0,0);}
if(counter_Time>=281 && counter_Time<=290) {SDL_Color text_color = {0,225,0};const char * text ="32";textColor(m_renderer,600,50,text,font_address_03 ,85,text_color,0.0,0);}
if(counter_Time>=291 && counter_Time<=300) {SDL_Color text_color = {0,225,0};const char * text ="31";textColor(m_renderer,600,50,text,font_address_03 ,85,text_color,0.0,0);}
if(counter_Time>=301 && counter_Time<=310) {SDL_Color text_color = {255,255,0};const char * text ="30";textColor(m_renderer,600,50,text,font_address_03 ,85,text_color,0.0,0);}
if(counter_Time>=311 && counter_Time<=320) {SDL_Color text_color = {255,255,0};const char * text ="29";textColor(m_renderer,600,50,text,font_address_03 ,85,text_color,0.0,0);}
if(counter_Time>=321 && counter_Time<=330) {SDL_Color text_color = {255,255,0};const char * text ="28";textColor(m_renderer,600,50,text,font_address_03 ,85,text_color,0.0,0);}
if(counter_Time>=331 && counter_Time<=340) {SDL_Color text_color = {255,255,0};const char * text ="27";textColor(m_renderer,600,50,text,font_address_03 ,85,text_color,0.0,0);}
if(counter_Time>=341 && counter_Time<=350) {SDL_Color text_color = {255,255,0};const char * text ="26";textColor(m_renderer,600,50,text,font_address_03 ,85,text_color,0.0,0);}
if(counter_Time>=351 && counter_Time<=360) {SDL_Color text_color = {255,255,0};const char * text ="25";textColor(m_renderer,600,50,text,font_address_03 ,85,text_color,0.0,0);}
if(counter_Time>=361 && counter_Time<=370) {SDL_Color text_color = {255,255,0};const char * text ="24";textColor(m_renderer,600,50,text,font_address_03 ,85,text_color,0.0,0);}
if(counter_Time>=371 && counter_Time<=380) {SDL_Color text_color = {255,255,0};const char * text ="23";textColor(m_renderer,600,50,text,font_address_03 ,85,text_color,0.0,0);}
if(counter_Time>=381 && counter_Time<=390) {SDL_Color text_color = {255,255,0};const char * text ="22";textColor(m_renderer,600,50,text,font_address_03 ,85,text_color,0.0,0);}
if(counter_Time>=391 && counter_Time<=400) {SDL_Color text_color = {255,255,0};const char * text ="21";textColor(m_renderer,600,50,text,font_address_03 ,85,text_color,0.0,0);}
if(counter_Time>=401 && counter_Time<=410) {SDL_Color text_color = {255,165,0};const char * text ="20";textColor(m_renderer,600,50,text,font_address_03 ,85,text_color,0.0,0);}
if(counter_Time>=411 && counter_Time<=420) {SDL_Color text_color = {255,165,0};const char * text ="19";textColor(m_renderer,600,50,text,font_address_03 ,85,text_color,0.0,0);}
if(counter_Time>=421 && counter_Time<=430) {SDL_Color text_color = {255,165,0};const char * text ="18";textColor(m_renderer,600,50,text,font_address_03 ,85,text_color,0.0,0);}
if(counter_Time>=431 && counter_Time<=440) {SDL_Color text_color = {255,165,0};const char * text ="17";textColor(m_renderer,600,50,text,font_address_03 ,85,text_color,0.0,0);}
if(counter_Time>=441 && counter_Time<=450) {SDL_Color text_color = {255,165,0};const char * text ="16";textColor(m_renderer,600,50,text,font_address_03 ,85,text_color,0.0,0);}
if(counter_Time>=451 && counter_Time<=460) {SDL_Color text_color = {255,165,0};const char * text ="15";textColor(m_renderer,600,50,text,font_address_03 ,85,text_color,0.0,0);}
if(counter_Time>=461 && counter_Time<=470) {SDL_Color text_color = {255,165,0};const char * text ="14";textColor(m_renderer,600,50,text,font_address_03 ,85,text_color,0.0,0);}
if(counter_Time>=471 && counter_Time<=480) {SDL_Color text_color = {255,165,0};const char * text ="13";textColor(m_renderer,600,50,text,font_address_03 ,85,text_color,0.0,0);}
if(counter_Time>=481 && counter_Time<=490) {SDL_Color text_color = {255,165,0};const char * text ="12";textColor(m_renderer,600,50,text,font_address_03 ,85,text_color,0.0,0);}
if(counter_Time>=491 && counter_Time<=500) {SDL_Color text_color = {255,165,0};const char * text ="11";textColor(m_renderer,600,50,text,font_address_03 ,85,text_color,0.0,0);}
SDL_Color text_color = {255,0,0}; ///red
if(counter_Time>=501 && counter_Time<=507) {const char * text ="10";textColor(m_renderer,600,50,text,font_address_03 ,85,text_color,0.0,0);}
if(counter_Time>=508 && counter_Time<=510) {const char * text ="10";textColor(m_renderer,570,30,text,font_address_03 ,135,text_color,0.0,0);}
if(counter_Time>=511 && counter_Time<=517) {const char * text ="9";textColor(m_renderer,600,50,text,font_address_03 ,85,text_color,0.0,0);}
if(counter_Time>=518 && counter_Time<=520) {const char * text ="9";textColor(m_renderer,570,30,text,font_address_03 ,135,text_color,0.0,0);}
if(counter_Time>=521 && counter_Time<=527) {const char * text ="8";textColor(m_renderer,600,50,text,font_address_03 ,85,text_color,0.0,0);}
if(counter_Time>=528 && counter_Time<=530) {const char * text ="8";textColor(m_renderer,570,30,text,font_address_03 ,135,text_color,0.0,0);}
if(counter_Time>=531 && counter_Time<=537) {const char * text ="7";textColor(m_renderer,600,50,text,font_address_03 ,85,text_color,0.0,0);}
if(counter_Time>=538 && counter_Time<=540) {const char * text ="7";textColor(m_renderer,570,30,text,font_address_03 ,135,text_color,0.0,0);}
if(counter_Time>=541 && counter_Time<=547) {const char * text ="6";textColor(m_renderer,600,50,text,font_address_03 ,85,text_color,0.0,0);}
if(counter_Time>=548 && counter_Time<=550) {const char * text ="6";textColor(m_renderer,570,30,text,font_address_03 ,135,text_color,0.0,0);}
if(counter_Time>=551 && counter_Time<=557) {const char * text ="5";textColor(m_renderer,600,50,text,font_address_03 ,85,text_color,0.0,0);}
if(counter_Time>=558 && counter_Time<=560) {const char * text ="5";textColor(m_renderer,570,30,text,font_address_03 ,135,text_color,0.0,0);}
if(counter_Time>=561 && counter_Time<=567) {const char * text ="4";textColor(m_renderer,600,50,text,font_address_03 ,85,text_color,0.0,0);}
if(counter_Time>=568 && counter_Time<=570) {const char * text ="4";textColor(m_renderer,570,30,text,font_address_03 ,135,text_color,0.0,0);}
if(counter_Time>=571 && counter_Time<=577) {const char * text ="3";textColor(m_renderer,600,50,text,font_address_03 ,85,text_color,0.0,0);}
if(counter_Time>=578 && counter_Time<=580) {const char * text ="3";textColor(m_renderer,570,30,text,font_address_03 ,135,text_color,0.0,0);}
if(counter_Time>=581 && counter_Time<=587) {const char * text ="2";textColor(m_renderer,600,50,text,font_address_03 ,85,text_color,0.0,0);}
if(counter_Time>=588 && counter_Time<=590) {const char * text ="2";textColor(m_renderer,570,30,text,font_address_03 ,135,text_color,0.0,0);}
if(counter_Time>=591 && counter_Time<=597) {const char * text ="1";textColor(m_renderer,600,50,text,font_address_03 ,85,text_color,0.0,0);}
if(counter_Time>=598 && counter_Time<=600) {const char * text ="1";textColor(m_renderer,570,30,text,font_address_03 ,135,text_color,0.0,0);}
if(counter_Time>=601 && counter_Time<=607) {const char * text ="0";textColor(m_renderer,600,50,text,font_address_03 ,85,text_color,0.0,0);}
if(counter_Time>=608 && counter_Time<=610) {const char * text ="0";textColor(m_renderer,570,30,text,font_address_03 ,135,text_color,0.0,0);}
///show time on score board:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

textColor(m_renderer,130,130,name2.c_str(),font_address_00,30,text_color,0.0,0);///show name1
textColor(m_renderer,970,130,name1.c_str(),font_address_00,30,text_color,0.0,0);///show name2

if(counter_Time==637) {game=false;A=1;menu=true;situation_Y="off.png";sound="background2.mp3";Mix_Music *GameSound = Mix_LoadMUS(sound.c_str());Mix_PlayMusic(GameSound,-1);}

///texture for start(Go)""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
if(counter_Time==-10) {const char * text ="Goooooo";textColor(m_renderer,250,340,text,font_address_00,165,text_color,0.0,0);}
if(counter_Time==-9) {const char * text ="Goooooo";textColor(m_renderer,250,300,text,font_address_00,165,text_color,0.0,0);}
if(counter_Time==-8) {const char * text ="Goooooo";textColor(m_renderer,250,340,text,font_address_00,165,text_color,0.0,0);}
if(counter_Time==-7) {const char * text ="Goooooo";textColor(m_renderer,250,300,text,font_address_00,165,text_color,0.0,0);}
if(counter_Time==-6) {const char * text ="Goooooo";textColor(m_renderer,250,340,text,font_address_00,165,text_color,0.0,0);}
if(counter_Time==-5) {const char * text ="Goooooo";textColor(m_renderer,250,300,text,font_address_00,165,text_color,0.0,0);}
if(counter_Time==-4) {const char * text ="Goooooo";textColor(m_renderer,250,340,text,font_address_00,165,text_color,0.0,0);}
if(counter_Time==-3) {const char * text ="Goooooo";textColor(m_renderer,250,300,text,font_address_00,165,text_color,0.0,0);}
if(counter_Time==-2) {const char * text ="Goooooo";textColor(m_renderer,250,340,text,font_address_00,165,text_color,0.0,0);}
if(counter_Time==-1) {const char * text ="Goooooo";textColor(m_renderer,250,300,text,font_address_00,165,text_color,0.0,0);}
if(counter_Time==0) {const char * text ="Goooooo";textColor(m_renderer,250,340,text,font_address_00,165,text_color,0.0,0);}
///texture for start(Go)""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

///texture for goal<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<
if(counter_Time_Goal==counter_Time) {const char * text ="Goal!!";textColor(m_renderer,250,340,text,font_address_00,195,text_color,0.0,0);}
if(counter_Time_Goal+1==counter_Time) {SDL_Color text_color = {255,250,0};const char * text ="Goooal!!";textColor(m_renderer,50,40,text,font_address_00,165,text_color,0.0,0);}
if(counter_Time_Goal+2==counter_Time) {SDL_Color text_color = {255,150,0};const char * text ="Gooooooal!!";textColor(m_renderer,650,640,text,font_address_00,165,text_color,0.0,0);}
if(counter_Time_Goal+3==counter_Time) {SDL_Color text_color = {0,250,0};const char * text ="Goooooooooooooal!!";textColor(m_renderer,150,340,text,font_address_00,165,text_color,0.0,0);}
if(counter_Time_Goal+4==counter_Time) {SDL_Color text_color = {0,00,250};const char * text ="Gooooal!!";textColor(m_renderer,850,40,text,font_address_00,165,text_color,0.0,0);}
if(counter_Time_Goal+5==counter_Time) {SDL_Color text_color = {120,0,120};const char * text ="Gooooooooal!!";textColor(m_renderer,50,640,text,font_address_00,165,text_color,0.0,0);}
if(counter_Time_Goal+6==counter_Time) {const char * text ="Gooooooooooal";textColor(m_renderer,20,300,text,font_address_00,165,text_color,0.0,0);}
if(counter_Time_Goal+7==counter_Time) {const char * text ="Gooooooooooal";textColor(m_renderer,20,340,text,font_address_00,165,text_color,0.0,0);}
if(counter_Time_Goal+8==counter_Time) {const char * text ="Gooooooooooal";textColor(m_renderer,20,300,text,font_address_00,165,text_color,0.0,0);}
if(counter_Time_Goal+9==counter_Time) {const char * text ="Gooooooooooal";textColor(m_renderer,20,340,text,font_address_00,165,text_color,0.0,0);}
if(counter_Time_Goal+10==counter_Time) {const char * text ="Gooooooooooal";textColor(m_renderer,20,300,text,font_address_00,165,text_color,0.0,0);}
if(counter_Time_Goal+11==counter_Time) {const char * text ="Gooooooooooal";textColor(m_renderer,20,340,text,font_address_00,165,text_color,0.0,0);}
if(counter_Time_Goal+12==counter_Time) {const char * text ="Gooooooooooal";textColor(m_renderer,20,300,text,font_address_00,165,text_color,0.0,0);}
///texture for goal<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

///sound^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
if(score_1!=score_2 && counter_Time==611) Mix_PlayChannel(-1,winner,0);
if(counter_Time==300) Mix_PlayChannel(-1,topoli,0);
///if(counter_Time==30) Mix_PlayChannel(-1,avazi,0);
if(counter_Time_Goall==counter_Time && (counter_Time<=290 || counter_Time>=380)) Mix_PlayChannel(-1,gol,0);
if(counter_Time==counter_ab && ( (counter_Time>=150 && counter_Time<=240) || (counter_Time>=370 && counter_Time<=540) )) Mix_PlayChannel(-1,ab,0);
if(counter_Time==370) Mix_PlayChannel(-1,helicopter,0);
if(counter_Time==-8) Mix_PlayChannel(-1,hello1,0);
if(counter_Time==30) Mix_PlayChannel(-1,hello2,0);
if((counter_Time==0) || (counter_Time==609) || (counter_Time_referee==counter_Time) ) Mix_PlayChannel(-1,whistle,0);
///sound^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

if(xh1-30>=xh2+30 && xh1-30<=xh2+60) yh1=yh2-21;///Standing 1 on 2's shoe
if(yh2!=580 && xh2+80>=xh1-25 && xh2+80<=xh1) yh2=yh1-16;///Standing 2 on 1's shoe

SDL_RenderPresent(m_renderer);
SDL_Delay(5);
SDL_RenderClear(m_renderer);

if(counter_Time<=610)
                                {

const Uint8 *keyboard_state_array = SDL_GetKeyboardState(NULL);
SDL_PollEvent(f);
        if(f->type == SDL_KEYDOWN || f->type == SDL_KEYUP)
        {
                if(keyboard_state_array[SDL_SCANCODE_UP] && freeze1==false)
                    {
                          yh1-=5;
                    }
                 if(keyboard_state_array[SDL_SCANCODE_DOWN] && freeze1==false)
                    {
                             counter_Time_shoot1=counter_Time;
                    }
                 if(keyboard_state_array[SDL_SCANCODE_RIGHT] && freeze1==false)
                    {
                              if(yh1!=580 && xh1+50!=xh2) xh1+=5;
                              else if(xh1>=xb && xb>=xh2 && xh1!=1195) xh1+=5;
                              else if(xb<=xh2 && xh2<=xh1 && xh1!=1150) xh1+=5;
                              else if(xb<=xh1 && xh1<=xh2 && xh1+50!=xh2) xh1+=5;
                              else if(xh1<=xb && xb<=xh2 && xh1+70+50+5!=xh2) xh1+=5;
                              else if(xh2<=xh1 && xh1<=xb) xh1+=5;
                              else if(xh1<=xh2 && xh2<=xb && xh1+50!=xh2) xh1+=5;
                    }
                 if(keyboard_state_array[SDL_SCANCODE_LEFT] && freeze1==false)
                    {
                          if(!((xh1-30==xh2+40) || (xh2+80==xh1-15 && yh2==yh1-21)) ){
                              if(yh1!=580) xh1-=5;
                              else if(xh1>=xb && xb>=xh2 && xh1-175!=xh2) xh1-=5;
                              else if(xb<=xh2 && xh2<=xh1 && xh1-105!=xh2) xh1-=5;
                              else if(xb<=xh1 && xh1<=xh2) xh1-=5;
                              else if(xh1<=xb && xb<=xh2 && xh1!=75) xh1-=5;
                              else if(xh2<=xh1 && xh1<=xb && xh1-105!=xh2) xh1-=5;
                              else if(xh1<=xh2 && xh2<=xb && xh1!=75) xh1-=5;
                                            }
                    }

                 if(keyboard_state_array[SDL_SCANCODE_W] && freeze2==false)
                    {
                          yh2-=5;
                    }
                 if(keyboard_state_array[SDL_SCANCODE_D] && freeze2==false)
                    {
                          if(!((xh2+80==xh1-15) || (xh1-30==xh2+40&&yh1==yh2-21)) ){
                              if(yh2!=580) xh2+=5;
                              else if(xh1>=xb && xb>=xh2 && xh2+175!=xh1) xh2+=5;
                              else if(xb<=xh2 && xh2<=xh1 && xh1-105!=xh2) xh2+=5;
                              else if(xb<=xh1 && xh1<=xh2 && xh2!=1160) xh2+=5;
                              else if(xh1<=xb && xb<=xh2 && xh2!=1160) xh2+=5;
                              else if(xh2<=xh1 && xh1<=xb && xh1-105!=xh2) xh2+=5;
                              else if(xh1<=xh2 && xh2<=xb) xh2+=5;
                                            }
                    }
                 if(keyboard_state_array[SDL_SCANCODE_A] && freeze2==false)
                    {
                              if(yh2!=580 && xh1+50!=xh2) xh2-=5;
                              else if(xh2<=xb && xb<=xh1 && xh2!=50) xh2-=5;
                              else if(xb<=xh2 && xh2<=xh1) xh2-=5;
                              else if(xb<=xh1 && xh1<=xh2 && xh1+50!=xh2) xh2-=5;
                              else if(xh1<=xb && xb<=xh2 && xh1+70+50+5!=xh2) xh2-=5;
                              else if(xh2<=xh1 && xh1<=xb && xh2!=50) xh2-=5;
                              else if(xh1<=xh2 && xh2<=xb && xh1+50!=xh2) xh2-=5;
                    }
                 if(keyboard_state_array[SDL_SCANCODE_X] && freeze2==false)
                    {
                             counter_Time_shoot2=counter_Time;
                    }
                 if(keyboard_state_array[SDL_SCANCODE_P] && freeze1==false)
                    {
                              if(counter1>=205)
                              {
                              power1=true;
                              counter1=0;
                              }
                    }
                 if(keyboard_state_array[SDL_SCANCODE_Q] && freeze2==false)
                    {
                              if(counter2>=205)
                              {
                              power2=true;
                              counter2=0;
                              }
                    }
                 if(keyboard_state_array[SDL_SCANCODE_ESCAPE])
                    {
                              int chose = pause();
                              if(chose == 0)
                              {
                              game = false;
                              A=1;
                              menu=true;
                              situation_Y="off.png";
                              sound="background2.mp3";Mix_Music *GameSound = Mix_LoadMUS(sound.c_str());Mix_PlayMusic(GameSound,-1);
                              }
                              else if(chose == 1)
                              game = true;
                    }
                 if(keyboard_state_array[SDL_SCANCODE_TAB])
                    {
                          game=false;
                          A=1;
                          menu=true;
                          situation_Y="off.png";
                    }
        }
                                    }
}
}

if(A==5)
{
      while (leader)
{

ofstream fout("D:\\information",ios::out);
fout<<score_2<<"\t"<<score_1;
ifstream fin("D:\\information",ios::in);

int n=2,goalsd1=score_1-score_2,goalsd2=score_2-score_1,drawn1=0,drawn2=0,won1=0,won2=0;
if(score_1>score_2) won1+=1;
if(score_1<score_2) won2+=1;
if(score_1==score_2 && X!=0) {drawn1+=1;drawn2+=1;}
int points1=3*won1+drawn1,points2=3*won2+drawn2;

texture(m_renderer,0,0,"background_table2.png",1280,800);///picture of background
rect(m_renderer,930,50,300,70,0,0,0,1);///not important thing
rect(m_renderer,280,200,720,400,100,100,100,1);///table

///Vertical lines----------------------------------------------------------
my_line(m_renderer,360,200,400,4.71248898,4,250,120,0);
my_line(m_renderer,440,200,400,4.71248898,4,250,120,0);
my_line(m_renderer,520,200,400,4.71248898,4,250,120,0);
my_line(m_renderer,600,200,400,4.71248898,4,250,120,0);
my_line(m_renderer,680,200,400,4.71248898,4,250,120,0);
my_line(m_renderer,760,200,400,4.71248898,4,250,120,0);
my_line(m_renderer,840,200,400,4.71248898,4,250,120,0);
my_line(m_renderer,920,200,400,4.71248898,4,250,120,0);
///Vertical lines----------------------------------------------------------

stringColor(m_renderer,855,232,"PLAYED",O);
stringColor(m_renderer,785,232,"WON",O);
stringColor(m_renderer,695,232,"DRAWN",O);
stringColor(m_renderer,625,232,"LOST",O);
stringColor(m_renderer,535,232,"GOALS F",O);
stringColor(m_renderer,455,232,"GOALS A",O);
stringColor(m_renderer,375,232,"GOALS D",O);
stringColor(m_renderer,295,232,"POINTS",O);

if(X==0)texture(m_renderer,855,500,"noll.png",50,50); else texture(m_renderer,855,500,"one.png",50,50);
if(X==0)texture(m_renderer,855,350,"noll.png",50,50); else texture(m_renderer,855,350,"one.png",50,50);
if(score_2>score_1) texture(m_renderer,780,500,"one.png",50,50); else texture(m_renderer,780,500,"noll.png",50,50);
if(score_1>score_2) texture(m_renderer,780,350,"one.png",50,50); else texture(m_renderer,780,350,"noll.png",50,50);
if(score_1==score_2 && X!=0) texture(m_renderer,695,500,"one.png",50,50); else texture(m_renderer,695,500,"noll.png",50,50);
if(score_1==score_2 && X!=0) texture(m_renderer,695,350,"one.png",50,50); else texture(m_renderer,695,350,"noll.png",50,50);
if(score_1>score_2) texture(m_renderer,620,500,"one.png",50,50); else texture(m_renderer,620,500,"noll.png",50,50);
if(score_2>score_1) texture(m_renderer,620,350,"one.png",50,50); else texture(m_renderer,620,350,"noll.png",50,50);
if(score_1==1)texture(m_renderer,535,350,"one.png",50,50); else if(score_1==2)texture(m_renderer,535,350,"two.png",50,50); else if(score_1==3)texture(m_renderer,535,350,"three.png",50,50); else if(score_1==4)texture(m_renderer,535,350,"four.png",50,50); else if(score_1==5)texture(m_renderer,535,350,"five.png",50,50); else if(score_1==6)texture(m_renderer,535,350,"six.png",50,50);  else texture(m_renderer,535,350,"noll.png",50,50);///goals f1
if(score_2==1)texture(m_renderer,535,500,"one.png",50,50); else if(score_2==2)texture(m_renderer,535,500,"two.png",50,50); else if(score_2==3)texture(m_renderer,535,500,"three.png",50,50); else if(score_2==4)texture(m_renderer,535,500,"four.png",50,50); else if(score_2==5)texture(m_renderer,535,500,"five.png",50,50); else if(score_2==6)texture(m_renderer,535,500,"six.png",50,50);  else texture(m_renderer,535,500,"noll.png",50,50);///goals f2
if(score_2==1)texture(m_renderer,455,350,"one.png",50,50); else if(score_2==2)texture(m_renderer,455,350,"two.png",50,50); else if(score_2==3)texture(m_renderer,455,350,"three.png",50,50); else if(score_2==4)texture(m_renderer,455,350,"four.png",50,50); else if(score_2==5)texture(m_renderer,455,350,"five.png",50,50); else if(score_2==6)texture(m_renderer,455,350,"six.png",50,50);  else texture(m_renderer,455,350,"noll.png",50,50);///goals a1
if(score_1==1)texture(m_renderer,455,500,"one.png",50,50); else if(score_1==2)texture(m_renderer,455,500,"two.png",50,50); else if(score_1==3)texture(m_renderer,455,500,"three.png",50,50); else if(score_1==4)texture(m_renderer,455,500,"four.png",50,50); else if(score_1==5)texture(m_renderer,455,500,"five.png",50,50); else if(score_1==6)texture(m_renderer,455,500,"six.png",50,50);  else texture(m_renderer,455,500,"noll.png",50,50);///goals a2
if(goalsd1==-6){texture(m_renderer,325,365,"negetive.png",200,200);texture(m_renderer,375,350,"six.png",50,50);} else if(goalsd1==-5){texture(m_renderer,325,365,"negetive.png",200,200);texture(m_renderer,375,350,"five.png",50,50);} else if(goalsd1==-4){texture(m_renderer,325,365,"negetive.png",200,200);texture(m_renderer,375,350,"four.png",50,50);} else if(goalsd1==-3){texture(m_renderer,325,365,"negetive.png",200,200);texture(m_renderer,375,350,"three.png",50,50);} else if(goalsd1==-2){texture(m_renderer,325,365,"negetive.png",200,200);texture(m_renderer,375,350,"two.png",50,50);} else if(goalsd1==-1){texture(m_renderer,325,365,"negetive.png",200,200);texture(m_renderer,375,350,"one.png",50,50);} else if(goalsd1==0)texture(m_renderer,375,350,"noll.png",50,50); else if(goalsd1==1)texture(m_renderer,375,350,"one.png",50,50); else if(goalsd1==2)texture(m_renderer,375,350,"two.png",50,50); else if(goalsd1==3)texture(m_renderer,375,350,"three.png",50,50); else if(goalsd1==4)texture(m_renderer,375,350,"four.png",50,50); else if(goalsd1==5)texture(m_renderer,375,350,"five.png",50,50); else if(goalsd1==6)texture(m_renderer,375,350,"six.png",50,50);
if(goalsd2==-6){texture(m_renderer,325,515,"negetive.png",200,200);texture(m_renderer,375,500,"six.png",50,50);} else if(goalsd2==-5){texture(m_renderer,325,515,"negetive.png",200,200);texture(m_renderer,375,500,"five.png",50,50);} else if(goalsd2==-4){texture(m_renderer,325,515,"negetive.png",200,200);texture(m_renderer,375,500,"four.png",50,50);} else if(goalsd2==-3){texture(m_renderer,325,515,"negetive.png",200,200);texture(m_renderer,375,500,"three.png",50,50);} else if(goalsd2==-2){texture(m_renderer,325,515,"negetive.png",200,200);texture(m_renderer,375,500,"two.png",50,50);} else if(goalsd2==-1){texture(m_renderer,325,515,"negetive.png",200,200);texture(m_renderer,375,500,"one.png",50,50);} else if(goalsd2==0)texture(m_renderer,375,500,"noll.png",50,50); else if(goalsd2==1)texture(m_renderer,375,500,"one.png",50,50); else if(goalsd2==2)texture(m_renderer,375,500,"two.png",50,50); else if(goalsd2==3)texture(m_renderer,375,500,"three.png",50,50); else if(goalsd2==4)texture(m_renderer,375,500,"four.png",50,50); else if(goalsd2==5)texture(m_renderer,375,500,"five.png",50,50); else if(goalsd2==6)texture(m_renderer,375,500,"six.png",50,50);
if(points1==0)texture(m_renderer,295,350,"noll.png",50,50); else if(points1==1)texture(m_renderer,295,350,"one.png",50,50); else if(points1==2)texture(m_renderer,295,350,"two.png",50,50); else if(points1==3)texture(m_renderer,295,350,"three.png",50,50); else if(points1==4)texture(m_renderer,295,350,"four.png",50,50); else if(points1==6)texture(m_renderer,295,350,"six.png",50,50);
if(points2==0)texture(m_renderer,295,500,"noll.png",50,50); else if(points2==1)texture(m_renderer,295,500,"one.png",50,50); else if(points2==2)texture(m_renderer,295,500,"two.png",50,50); else if(points2==3)texture(m_renderer,295,500,"three.png",50,50); else if(points2==4)texture(m_renderer,295,500,"four.png",50,50); else if(points2==6)texture(m_renderer,295,500,"six.png",50,50);

const char * font_address_00="arial.ttf";
SDL_Color text_color={255,0,255};
textColor(m_renderer,935,500,name2.c_str(),font_address_00,23,text_color,0.0,0);///show name1
textColor(m_renderer,935,350,name1.c_str(),font_address_00,23,text_color,0.0,0);///show name2


my_line(m_renderer,280,280,720,0,5,250,120,0);///The first horizontal line
rect(m_renderer,920,200,81,80,250,120,0,1);///mostatil narenji bala raste jadval
for(int i=1;i<n;i++) my_line(m_renderer,280,280+i*320/n,720,0,2,120,0,120);///The other horizontal lines

SDL_RenderPresent(m_renderer);
SDL_Delay(5);
SDL_RenderClear(m_renderer);

const Uint8 *keyboard_state_array = SDL_GetKeyboardState(NULL);
SDL_PollEvent(f);
        if(f->type == SDL_KEYDOWN || f->type == SDL_KEYUP)
        {

                  if(keyboard_state_array[SDL_SCANCODE_ESCAPE])
                    {
                        leader=false;
                        A=1;
                        menu=true;
                        situation_L="off.png";
                    }
        }

}
}

if(A==6)
{
      while (setting)
{
texture(m_renderer,0,0,"background_setting.png",1280,800);///picture of background
texture(m_renderer,450,20,"setting_text.png",400,200);///picture of setting

///ball 1-----------------------------------------------------------------------------------
rect(m_renderer,xb1+30,yb1+30,30,30,0,0,0,0);
xb1+=dx1;yb1+=dy1;
if(yb1>=720 || yb1<=0) dy1=-dy1;
if(xb1>=1200 || xb1<=0) dx1=-dx1;
texture(m_renderer,xb1,yb1,"ball1.png",80,80);
///ball 1-----------------------------------------------------------------------------------

///ball 20***********************************************************************************
rect(m_renderer,xb2+30,yb2+30,30,30,0,0,0,0);
xb2+=dx2;yb2+=dy2;
if(yb2>=720 || yb2<=0) dy2=-dy2;
if(xb2>=1200 || xb2<=0) dx2=-dx2;
texture(m_renderer,xb2,yb2,"ball20.png",80,110);
///ball 20***********************************************************************************

///ball 3------------------------------------------------------------------------------------
rect(m_renderer,xb3+30,yb3+30,30,30,0,0,0,0);
xb3+=dx3;yb3+=dy3;
if(yb3>=720 || yb3<=0) dy3=-dy3;
if(xb3>=1200 || xb3<=0) dx3=-dx3;
texture(m_renderer,xb3,yb3,"ball3.png",80,80);
///ball 3-----------------------------------------------------------------------------------

texture(m_renderer,455,330,"left.png",80,80);///picture of left button
texture(m_renderer,550,300,ball,150,150);///picture of ball
texture(m_renderer,710,330,"right.png",90,90);///picture of right button

texture(m_renderer,455,630,"left.png",80,80);///picture of left button
texture(m_renderer,550,600,"sound.png",150,150);///picture of sound
texture(m_renderer,710,630,"right.png",90,90);///picture of right button

SDL_RenderPresent(m_renderer);
SDL_Delay(15);
SDL_RenderClear(m_renderer);

const Uint8 *keyboard_state_array = SDL_GetKeyboardState(NULL);
SDL_PollEvent(f);
        if(f->type == SDL_KEYDOWN || f->type == SDL_KEYUP)
        {
                 if(keyboard_state_array[SDL_SCANCODE_LEFT])
                    {
                          if(ball=="ball1.png") ball="ball3.png";
                          else if(ball=="ball2.png") ball="ball3.png";
                          else if(ball=="ball3.png") ball="ball1.png";
                          else if(ball=="ball4.png") ball="ball1.png";
                    }
                  if(keyboard_state_array[SDL_SCANCODE_RIGHT])
                    {
                          if(ball=="ball1.png") ball="ball3.png";
                          else if(ball=="ball2.png") ball="ball3.png";
                          else if(ball=="ball3.png") ball="ball1.png";
                          else if(ball=="ball4.png") ball="ball1.png";
                    }
                 if(keyboard_state_array[SDL_SCANCODE_A])
                    {
                          if(sound=="background1.mp3") {sound="background2.mp3";Mix_Music *GameSound = Mix_LoadMUS(sound.c_str());Mix_PlayMusic(GameSound,-1);}
                          else if(sound=="background2.mp3") {sound="background1.mp3";Mix_Music *GameSound = Mix_LoadMUS(sound.c_str());Mix_PlayMusic(GameSound,-1);}
                    }
                  if(keyboard_state_array[SDL_SCANCODE_D])
                    {
                          if(sound=="background1.mp3") {sound="background2.mp3";Mix_Music *GameSound = Mix_LoadMUS(sound.c_str());Mix_PlayMusic(GameSound,-1);}
                          else if(sound=="background2.mp3") {sound="background1.mp3";Mix_Music *GameSound = Mix_LoadMUS(sound.c_str());Mix_PlayMusic(GameSound,-1);}
                    }
                  if(keyboard_state_array[SDL_SCANCODE_ESCAPE])
                    {
                        setting=false;
                        A=1;
                        menu=true;
                        situation_S="off.png";
                    }
        }
}

}

if(A==7)
{
while (about)
{
texture(m_renderer,0,0,"background_about.png",1280,800);///picture of background
y11+=3;y2+=3;y3+=3;y4+=3;y5+=3;y6+=3;y7+=3;y8+=3;y9+=dyy;
texture(m_renderer,200,y11,"1.png",850,150);
texture(m_renderer,200,y2,"2.png",850,150);
texture(m_renderer,260,y3-180,"3.png",700,600);
texture(m_renderer,200,y4,"4.png",850,100);
texture(m_renderer,380,y5,"5.png",500,100);
texture(m_renderer,200,y6,"6.png",850,100);
texture(m_renderer,400,y7,"7.png",500,100);
texture(m_renderer,400,y8,"8.png",500,800);
texture(m_renderer,450,y9,"9.png",400,70);
if(y9==400 || y9==401 || y9==402) dyy=0;

SDL_RenderPresent(m_renderer);
SDL_Delay(15);
SDL_RenderClear(m_renderer);

const Uint8 *keyboard_state_array = SDL_GetKeyboardState(NULL);
SDL_PollEvent(f);
        if(f->type == SDL_KEYDOWN || f->type == SDL_KEYUP)
        {
                 if(keyboard_state_array[SDL_SCANCODE_ESCAPE])
                    {
                        about=false;
                        A=1;
                        menu=true;
                        situation_U="off.png";
                    }

        }
}
}

if(player1=="messi1.png") player1="messi.png";
if(player1=="karim1.png") player1="karim.png";
if(player1=="ronaldo1.png") player1="ronaldo.png";
if(player1=="bruno1.png") player1="bruno.png";
if(player1=="hoseini1.png") player1="hoseini.png";
if(player2=="messi2.png") player2="messi.png";
if(player2=="karim2.png") player2="karim.png";
if(player2=="ronaldo2.png") player2="ronaldo.png";
if(player2=="bruno2.png") player2="bruno.png";
if(player2=="hoseini2.png") player2="hoseini.png";

}
SDL_DestroyTexture(m_texture);
}



void my_line(SDL_Renderer *Renderer, int x_1, int y_1, int L, double theta,int widht, int R, int G, int B )
{

    int x_2 = x_1 + L*cos(theta);

    int y_2 = y_1 - L*sin(theta);


    thickLineRGBA(Renderer,x_1,y_1,x_2,y_2,widht,R,G,B,255);

    //SDL_RenderPresent(Renderer);

}

void rect(SDL_Renderer *Renderer, int x,int y,int w,int h,int R, int G, int B, int fill_boolian )
{

    SDL_Rect rectangle ;

    rectangle.x = x;

    rectangle.y = y;

    rectangle.w = w;

    rectangle.h = h;

    SDL_SetRenderDrawColor(Renderer, R, G, B, 255);

    if (fill_boolian==1)

        SDL_RenderFillRect(Renderer, &rectangle);

    SDL_RenderDrawRect(Renderer, &rectangle);

   // SDL_RenderPresent(Renderer);

}

void ellipse(SDL_Renderer *Renderer, int x, int y, int Radius1, int Radius2, int R, int G, int B, int fill_boolian)
{

    if(fill_boolian==1)
        filledEllipseRGBA(Renderer,x,y,Radius1,Radius2,R,G,B,255);

    if(fill_boolian==0)

        ellipseRGBA(Renderer,x,y,Radius1,Radius2,R,G,B,255);

   // SDL_RenderPresent(Renderer);

}

void window_color(SDL_Renderer *Renderer, int R, int G, int B)
{

    SDL_SetRenderDrawColor( Renderer, R, G, B, 255 );

    SDL_RenderClear( Renderer );



    // Show the window

  //SDL_RenderPresent( Renderer );



}

void texture(SDL_Renderer *m_renderer,int xp,int yp,string addressOfImage,int width,int height)
{
        int n = addressOfImage.length();
        char char_array[n+1];

        strcpy(char_array, addressOfImage.c_str());
        SDL_Texture *myTexture;
        myTexture = IMG_LoadTexture( m_renderer, char_array);
        int w1, h1;
        SDL_QueryTexture(myTexture, NULL, NULL, &w1, &h1);
        SDL_Rect texr1;
        texr1.x = xp;
        texr1.y = yp;
        texr1.w = width;
        texr1.h = height;
        SDL_RenderCopy( m_renderer, myTexture, NULL, &texr1);
            SDL_DestroyTexture(myTexture);
}

int pause()
{
    int Choose;

    const SDL_MessageBoxButtonData buttons[] = {
        {0, 0, "Yes" },
        { SDL_MESSAGEBOX_BUTTON_ESCAPEKEY_DEFAULT, 2, "No" },
    };
    const SDL_MessageBoxColorScheme colorScheme = {
    };
    const SDL_MessageBoxData messageboxdata = {
        SDL_MESSAGEBOX_INFORMATION,
        NULL,
        "Pause",
        "Would you like to quit?",
        SDL_arraysize(buttons),
        buttons,
        &colorScheme
    };
    int buttonid;

    if (SDL_ShowMessageBox(&messageboxdata, &buttonid) < 0) {
        return 1;
    }else {
        if(buttons[buttonid].text=="Yes")
            Choose=0;
        else if(buttons[buttonid].text=="No")
            Choose=1;
        else
            Choose=-1;
    }

    return Choose;
}

void textColor(SDL_Renderer *renderer,int x,int y,const char * text,const char * font,int font_size,SDL_Color textColor,double angle,short flip_num)
{
      int mWidth = 0;
	int mHeight = 0;
    SDL_Rect* clip = NULL;
    TTF_Font *gFont = NULL;
    SDL_Point* center = NULL;

    SDL_RendererFlip flip;
    switch(flip_num){
        case 0:
            flip = SDL_FLIP_NONE;
            break;
        case 1:
            flip = SDL_FLIP_HORIZONTAL;
            break;
        case 2:
            flip = SDL_FLIP_VERTICAL;
            break;
        case 3:
            flip = (SDL_RendererFlip) (SDL_FLIP_HORIZONTAL | SDL_FLIP_VERTICAL);
            break;
        default:
            flip = SDL_FLIP_NONE;
    }

    SDL_Texture* mTexture = NULL;
    gFont = TTF_OpenFont(font, font_size);

    SDL_Surface* textSurface = TTF_RenderText_Solid(gFont, text, textColor);

    mWidth = textSurface->w;
    mHeight = textSurface->h;
    mTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_FreeSurface(textSurface);


    SDL_Rect renderQuad = {x , y, mWidth, mHeight};
    SDL_RenderCopyEx(renderer, mTexture, clip, &renderQuad, angle, center, flip);

    SDL_DestroyTexture(mTexture);
    SDL_RenderPresent(renderer);
}
