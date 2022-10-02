#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <strings.h>
#include <time.h>
#include <windows.h>
const int M[12]={31,28,31,30,31,30,31,31,30,31,30,31}; //���������� ���� � �������
struct product { // ��������� ��� ���������
       char name[32]; // ������������
       float cost; // ����
       float amt; // ���������
       SYSTEMTIME shelf; // ���� ��������
};
struct list { // ������ ���������
       product p; // �������
       list *next; // ������ �� ����. �������
};
void readProduct(list *&head) { // �������� ������ � ��������� �� ���������
       FILE *f;
       list *p;
       f=fopen("base.txt","rb"); // ��������� ���� ��� ��������� ������
       while (!feof(f)) { // ���� �� ����� �����
             p=new(list);
             fread(&p->p, sizeof(p->p), 1, f); // ��������� ������ � ����
             p->next=head;
             head=p;
       }
       head=p->next;
       free(p);
       fclose(f);
}
void printList(list *p) {// ����� ������ � ���������
     int num=1;
     printf("#            ������������           ����������    ����    ����� ��\n");
     while (p) { // ���� ���� �������
           printf("%3d %32s  %8.2f   %4.2f  %2d.%2d.%2d\n",num,p->p.name,p->p.amt,p->p.cost,p->p.shelf.wDay,p->p.shelf.wMonth,p->p.shelf.wYear); // ����� ��������������� ������
           p=p->next;
           num++;
     }
}
bool find(list *p, char s[32]) {// ����� ��������
     while (p) { // ���� ���� ��������
           if (strcmp(p->p.name,s)==0) return true; // ���� ������� ������� � ������������� ����� �� ��� � s, �� ���������� ������
           p=p->next;
     }
     return false; // ����� ����
}
void addProduct(list *&head) { // ���������� ��������
     FILE *f;
     list *p=new(list); // ����� ������
     char name[32],shelf[12];
     float amt,cost;
     printf("������� ������������ ������(32�): ");
     scanf("%s",name); // �������� ������
     printf("������� ���������� ������(��,��): ");
     scanf("%f",&amt);
     printf("������� ���� ������ �� ��,��(���): ");
     scanf("%f",&cost);          
     printf("������� ���� �������� ������(��.��.��): ");
     scanf("%s",shelf);
     strcpy(p->p.name,name); // ���������� ������ � ������
     p->p.amt=amt;
     p->p.cost=cost;
     GetSystemTime(&p->p.shelf); // ���������� ���� ��������, �������� ���������� ����, ����� � ���
        char s[3];
        strncpy(s,shelf,2);
        p->p.shelf.wDay+=atoi(s);
        strncpy(s,shelf+3,2);
        p->p.shelf.wMonth+=atoi(s);
        strncpy(s,shelf+6,4);
        p->p.shelf.wYear+=atoi(s);
     while (p->p.shelf.wMonth>12) { // � ���� �� ������� ����� �� ���� ������ (����� ������ 12)
           p->p.shelf.wMonth-=12;
           p->p.shelf.wYear++;
     }
     while (p->p.shelf.wDay>M[p->p.shelf.wMonth]) { // ����� �� ���� ������ ���� � ����
           p->p.shelf.wDay-=M[p->p.shelf.wMonth];
           p->p.shelf.wMonth++;           
           while (p->p.shelf.wMonth>12) {
                 p->p.shelf.wMonth-=12;
                 p->p.shelf.wYear++;
           }          
     }
     if (find(head,p->p.name)) { // ���� ������� � ����� ������ ��� ����������
        printf("product exists!\n"); // ������� ��� ��� ���� ����� �������
        free(p); // ������ ������
        return; // �����
     }
     p->next=head; // ��������� � ���� ������
     head=p; // �������� ������
     f=fopen("base.txt","ab"); // �������� ���� ��� ��������
     fwrite(&p->p, sizeof(p->p), 1, f); // ������������ ���� ����� ������
     fclose(f); // ��������� ����
}
void checkShelf(list *p) { // �������� ����� ��������
     SYSTEMTIME t;
     GetSystemTime(&t); // �������� ������� ����
     while (p) { // ��������� �� ���� ���������
           if (p->p.shelf.wYear<t.wYear) { // ���� ������� ��� ������ ��� � ����� �������� ��
              printf("%32s - %2d.%2d.%2d\n",p->p.name,p->p.shelf.wDay,p->p.shelf.wMonth,p->p.shelf.wYear); // ������ ���� ������� �� �����
           } else  // �����
           if (p->p.shelf.wYear==t.wYear) { // ���� ���� ���������
              if (p->p.shelf.wMonth<t.wMonth) { // � ����� ������
                 printf("%32s - %2d.%2d.%2d\n",p->p.name,p->p.shelf.wDay,p->p.shelf.wMonth,p->p.shelf.wYear); // �������
              } else
              if (p->p.shelf.wMonth==t.wMonth) { // � ������ ��������� � ���� ������
                 if (p->p.shelf.wDay<=t.wDay) {
                    printf("%32s - %2d.%2d.%2d\n",p->p.name,p->p.shelf.wDay,p->p.shelf.wMonth,p->p.shelf.wYear); // �������
                 }
              }
           }
           p=p->next; // ������� � ����. ������
     }
}
void deleteProduct(list *p) { // �������� ��������
     int num;
     FILE *f;
     printList(p); // ������� ������ ���������
     printf("����� ����� �������? ");
     scanf("%d",&num); // ���������� ����� ���������� ������
     f=fopen("base.txt","wb"); // ��������� ���� ��� �������� ������ (������ � �� ��������, ������, ��� ���� �������� ����� �������)
     while (num>1) { // ���� ����� �������� ������ ������ ���������� ��������
           if (!p) { // ���� ��� ��������
              printf("not found!\n"); // ������ �� ������
              fclose(f);
              return;
           }
           fwrite(&p->p, sizeof(p->p), 1, f); // ����� ������� ������ � ��������
           list *q=p;
           p=p->next;
           free(q);
           num--;
     }
     if (!p) { // ���� � ������ �� ����� ������� - ����
        printf("not found!\n");
        fclose(f);
        return; // �����
     }
     p=p->next; // ��������� � ����. ��������, ��������� �������, ����� ������ �� ���������� � ���� ��������� �������
     while (p) { // ������� ��� ��������� ������ � ����
           fwrite(&p->p, sizeof(p->p), 1, f);
           list *q=p;
           p=p->next;
           free(q);
     }
     fclose(f);
}
void correctCost(list *p) { // ����������� ����
     int num;
     FILE *f;
     printList(p);
     printf("����� ����� ��������? ");
     scanf("%d",&num);
     f=fopen("base.txt","wb");
     while (num>1) { // ����� �������� ����������
           if (!p) {
              printf("not found!\n");
              fclose(f);
              return;
           }
           fwrite(&p->p, sizeof(p->p), 1, f);
           p=p->next;        
           num--;
     }
     if (!p) {
        printf("not found!\n");
        fclose(f);
        return;
     }
     printf("������� ����: "); // ��� ������ ����� ������ ������
     scanf("%d",&num);
     p->p.cost=num; // ��������� ����� ����
     while (p) { // ���������� � ��� �������
           fwrite(&p->p, sizeof(p->p), 1, f);
           p=p->next;
     }
     fclose(f);
}
int main() {
    list *head=NULL;
    setlocale(LC_ALL,"rus"); // ���������� ������� ���� � �������
    int key=1;
    readProduct(head); // ��������� ��� ��������
    while (key!=0) { // ���� �� ������ �����
          system("CLS"); // ������� ������
          printf(" 0) �����\n"); // ������ ����
          printf(" 1) ������ �������\n");
          printf(" 2) �������� �����\n");
          printf(" 3) ��������� ���� ��������\n");
          printf(" 4) ������� �����\n");
          printf(" 5) �������� ���� ������\n");
          scanf("%d",&key); // ��������� ��������� ����� ����
          switch (key) { // ��������� ��� �� �����
                 case 0: break; // ���� ������� - �����
                 case 1: printList(head); system("pause"); break; // ���� ������ - �������� ������� ������ ������
                 case 2: addProduct(head); system("pause"); break; // ������ - ���������� ��������
                 case 3: checkShelf(head); system("pause"); break; // �������� ����� ��������
                 case 4: deleteProduct(head); head=NULL; readProduct(head); system("pause"); break;  // �������� �������� � ������ ���������� �� �����
                 case 5: correctCost(head); system("pause"); break; // ��������� ����
          }
    }
    return 0;
}
