#include <stdlib.h>
#include <stdio.h>
#include <graphics.h>
#include <math.h>
#include "E:\������� ����\�����\���\lab4-5\figure.h" // ���� � ������ ������
const 
     int w=800, h=600;      // ��������� ��� ������ � ������ ����                          
main() {
    initwindow(w,h); // ������������� ������������ ����
    tfigure *fig[50]; // ������ ��� �����
    for (int i= 0;i<20;i++) fig[i]=new tpoint(w,h); // 20 �����
    for (int i=20;i<25;i++) fig[i]=new tline(w,h);  // 5 �����
    for (int i=25;i<30;i++) fig[i]=new tcircle(w,h); // 5 ������
    for (int i=30;i<35;i++) fig[i]=new trectangle(w,h);  // 5 ���������������
    for (int i=35;i<40;i++) fig[i]=new trhomb(w,h); // 5 ������
    for (int i=40;i<45;i++) fig[i]=new ttriangle(w,h);  // 5 �������������
    for (int i=45;i<50;i++) fig[i]=new tellipse(w,h); // 5 ��������

    while (1) {
          for (int i=0;i<50;i++) fig[i]->move(); // ������� ������
    }
    closegraph();
}
