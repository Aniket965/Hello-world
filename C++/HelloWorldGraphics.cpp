#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <thread>
using namespace std;
    const int xShift = 90;
void animeLine(int x1,int y1,int x2, int y2){
    for(int i=1;i<=100;i++){
        line(x1,y1,(((x2*i)+x1*(100-i))/100),(((y2*i)+y1*(100-i))/100));
        Sleep(10);
    }
}
void drawOne(){
    animeLine(xShift+20,200,xShift+20,400);
    animeLine(xShift+40,200,xShift+40,400);
    animeLine(xShift+20,300,xShift+40,300);
}
void drawTwo(){
    animeLine(xShift+60,200,xShift+60,400);
    animeLine(xShift+120,200,xShift+60,200);
    animeLine(xShift+60,300,xShift+90,300);
    animeLine(xShift+60,400,xShift+120,400);
}
void drawThree(){
    animeLine(xShift+140,200,xShift+140,400);
    animeLine(xShift+140,400,xShift+190,400);

    animeLine(xShift+200,200,xShift+200,400);
    animeLine(xShift+200,400,xShift+240,400);
}
void drawFour(){
    animeLine(xShift+250,200,xShift+250,400);
    animeLine(xShift+280,200,xShift+280,400);
    animeLine(xShift+250,200,xShift+280,200);
    animeLine(xShift+250,400,xShift+280,400);
}
void drawFive(){
    animeLine(xShift+380,200,xShift+400,400);
    animeLine(xShift+400,400,xShift+420,200);
    animeLine(xShift+420,200,xShift+440,400);
    animeLine(xShift+440,400,xShift+460,200);
}
void drawSix(){
    animeLine(xShift+480,200,xShift+480,400);
    animeLine(xShift+510,200,xShift+510,400);
    animeLine(xShift+480,200,xShift+510,200);
    animeLine(xShift+480,400,xShift+510,400);
}
void drawSeven(){
    animeLine(xShift+530,200,xShift+530,400);
    animeLine(xShift+560,200,xShift+560,250);
    animeLine(xShift+530,200,xShift+560,200);
    animeLine(xShift+530,250,xShift+560,250);
    animeLine(xShift+530,250,xShift+560,400);
}
void drawEight(){
    animeLine(xShift+590,200,xShift+590,400);
    animeLine(xShift+590,400,xShift+620,400);
}
void drawNine(){
    animeLine(xShift+640,200,xShift+640,400);
    animeLine(xShift+640,200,xShift+660,300);
    animeLine(xShift+660,300,xShift+640,400);
}
void drawTen(){
    animeLine(xShift+680,200,xShift+680,380);
    animeLine(xShift+670,390,xShift+690,390);
    animeLine(xShift+670,390,xShift+670,400);
    animeLine(xShift+670,400,xShift+690,400);
    animeLine(xShift+690,400,xShift+690,390);
}

int main()
{
    initwindow(900,600,"Hello there!",100,100);
    std::thread t1(drawOne),t2(drawTwo),t3(drawThree),t4(drawFour),t5(drawFive),t6(drawSix);
    std::thread t7(drawSeven),t8(drawEight),t9(drawNine),t10(drawTen);
    t1.detach();
    t2.detach();
    t3.detach();
    t4.detach();
    t5.detach();
    t6.detach();
    t7.detach();
    t8.detach();
    t9.detach();
    t10.detach();


    _getch();
    return 0;
}
