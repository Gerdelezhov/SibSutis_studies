#include <stdlib.h>
#include <stdio.h>
#include <graphics.h>
#include "point.h" 
main() {
    initwindow(800,600); // �������������� ����������� ����
    tpoint *pt[200]; // ������ ��� 200 �����
    for (int i=0;i<200;i++) {
        pt[i]=new tpoint(800,600); // �������������� ����� ����� (�������� ��� ������ �����������)
    }
    while (1) { // ����������� ����
          for (int i=0;i<200;i++)
              pt[i]->move(); // ������� ������ �����
    }
    closegraph(); // ��������� ����������� ����
}
