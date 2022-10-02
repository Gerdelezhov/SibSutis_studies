#include <stdlib.h>
#include <stdio.h>
#include <graphics.h>
#include <math.h>
struct stack {
       int data; // ������ 
       stack *next; // ������ �� ����. �������
}; // ����� ��� �����
struct queue {
       int data;
       queue *next;
}; // ����� ��� �������
void printS(stack *p) { // ����� �����
     while (p) { // ���� ������� ����������
           printf("%3d -> ",p->data);//������� ���
           p=p->next; // ��������� � ����������
     }
     printf("NULL\n"); // ����� ����� �����
}
void printQ(queue *p) {
     while (p) { // ���� ���� ��� ������ �������
           printf("%3d -> ",p->data);
           p=p->next;
     }
     printf("TAIL\n");
}
stack *addS(stack *head, int n, int pos) { // �������� ������� � ���� head-������ ����� n-������ ������ �������� pos-�� ����� ������� ��������
      stack *p=new(stack); // �������� ����� �� ������� ��������
      p->data=n; // ��������� ������
      if (pos==0) { // ���� ������� �������, �����
         p->next=head; // ���������� ������� ����� ������� �
         return p; // ���������� ����� ������ �����
      } // ���� ����� �� ���������
      stack *q=head; // ������� ����� ��������� �� ������ �����
      pos--; // ��������� ��� ������������ �� ���� �������
      while (pos>0) { // ���� �� ����������� �� ������ �������
            pos--; // ������ ������� �������
            if (!q) { // ���� ��������, ����� �������� ����� �������� �������, ���
               free(p); // ����������� ������
               printf("\nERROR!\n"); // ������� ��������� �� ������
               return head; // ���������� ������ ������
            }
            q=q->next; // ��������� � ����. ��������
      }
      p->next=q->next;// ����� ���������� �������� ��������� ���
      q->next=p; // � ����� ������ �������
      return head; // ���������� ������ ������
}
queue *addQ(queue *tail, int n) { // ���������� �������� � �������
     queue *p=new(queue); // ���� ����� ���������
     p->data=n; // ������ ������� �������� �����
     tail->next=p; // ��������� � ������� ����� ������,
     tail=p; // ����� ���� ������������ ����� ������
     tail->next=NULL;
     return p;
}
stack *delS(stack *head, int pos) { // ������� ������� �� �����
      stack *p=head;
      if (pos==1) { // ���� ����� ������� ������ �������
         head=head->next; // ����������� ������ �� ���� ������� ������
         free(p); // ������� ������ ������
         return head; // ���������� �����
      } // ���� �� ���������
      stack *q=head; // ������� � ������
      p=head->next; // ���������� ������� ����� ������
      pos-=2; // ��������� ������� �� 2
      while (pos>0) { // ���� �� ����� ������ �������
            pos--;
            if (!p) { // ���� ��� ������ �������
               printf("\nERROR!\n"); // ������
               return head;
            }
            q=p; // ������� ������ ��� ���������
            p=p->next;
      }
      // p - ��������� �������
      q->next=p->next; // ������ � ����������� �������� ��������� �� ������� ����� ���������
      free(p); // �������
      return head;     
}
queue *delQ(queue *head, int pos) { // �������� �� ������� (����������)
      queue *p=head;
      if (pos==1) {
         head=head->next;
         free(p);
         return head;
      }
      queue *q=head;
      p=head->next;
      pos-=2;
      while (pos>0) {
            pos--;
            if (!p) {
               printf("\nERROR!\n");
               return head;
            }
            q=p;
            p=p->next;
      }
      q->next=p->next;
      free(p); 
      return head;     
}
int number(stack *p) { // ������� ���������� ��������� � �����
    if (!p) return 0; else // ���� ��� �������� ���������� 0
       return 1+number(p->next); // ����� ���������� 1 + �������� ������� (���� ����������� � ������� ��������)
}
int number1(queue *p) { // ���� ����� ��� �������
    if (!p) return 0; else
       return 1+number1(p->next);
}
stack *swapS(int n1,int n2, stack *head) { // ������ �������� ������� � ����� � ������� head � ��������� n1 � n2
      int num=1;
      stack *head0,*p1,*p2;
      head0=new(stack); // ����� ���������
      head0->next=head; // ������� �������� �� ������ (�� ���� �� �������� ��������� �� ������)
      p1=head0;
      while (num<n1) {p1=p1->next; num++;} // ������� ������� � ������� n1
      p2=p1;
      while (num<n2) {p2=p2->next; num++;} // � ������� n2
      if (n2-n1>1) {// ���� �������� ����� �� ����� (����� ���������� ���������� ����� ������ ������� ������, ��� ���������, ��� ������ � ���������)
          stack *q=p1->next->next; // ����� ������������ ������ ��������� � �������� ������������ ��������� ����� �������
          p1->next->next=p2->next->next; // ��� ����� ���� �������� ��������� � ��������, ������� ��� �� ������� �� ������������, ���� ��������� �� ������
          p2->next->next=q; // � ������� �������� �� ������ ���� ��������� �� ������, � ��������������, ������� ����� ����� �������
          q=p1->next; // ���� ����� ����� ������� � ��������
          p1->next=p2->next;
          p2->next=q;
      } else { // ���� �������� ����� �����
          stack *q=p2->next->next; // ����� ��� �� ����� �����, �������, �������� ����� ������� �������� ������ ����� ����� �������, � ������ ������� ����� �������.
          p1->next=p2->next; // � ������ ������ ����� �� ����� �������, �� ���� �� ���� ����� ��� �������, ������� ���� �� �������
          p2->next->next=p2;
          p2->next=q;
      }
      return head0->next; // ���������� ����� ������
}
queue *swapQ(int n1,int n2, queue *head) { // ����� ��������� � �������
      int num=1; // ��� ����������
      queue *head0,*p1,*p2;
      head0=new(queue);
      head0->next=head;
      p1=head0;
      while (num<n1) {p1=p1->next; num++;}
      p2=p1;
      while (num<n2) {p2=p2->next; num++;}
      if (n2-n1>1) {
          queue *q=p1->next->next;
          p1->next->next=p2->next->next;
          p2->next->next=q;
          q=p1->next;
          p1->next=p2->next;
          p2->next=q;
      } else {
          queue *q=p2->next->next;
          p1->next=p2->next;
          p2->next->next=p2;
          p2->next=q;
      }
      return head0->next;
}
int main() {
    stack *head; // ����
    queue *head1, *tail; // �������
 //   srand(time(NULL));
    int a[100]; // ������ ��� �����
    bool b[256];
    head=NULL; // ��������� ����������
    tail=head1=NULL;
    for (int i=0;i<100;i++) a[i]=rand()%256; // ��������� ������ ���������� ������� �� 0 �� 255
    for (int i=0;i<100;i++) {
        if (sqrt(a[i])*sqrt(a[i])==a[i]) { // ���� ����������� ���������� ������ �� ��������
           head=addS(head,a[i],0); // ������� ��� � ���� � ������
           b[a[i]]=false; // ��������, ��� ������ ������� ��� ������� � ������
           printS(head); // ������� ����
        }
    }
    stack *p=head;
    int num=1;
    b[head->data]=true; // �������� ������ ������� ������ ������, ��� �� ���������� �������
    while (p->next) { // ���� ���� �������� (��� ����� ���������� �� ������������� ���������)
          if (!b[p->next->data]) { // ���� ������� ��� �� ����������
             b[p->next->data]=true; // �������� ��� ���������
             num++;
             p=p->next; // ��������� � ����������
          } else { // �����
             delS(head,num+1);            // ������� ���
             printS(head); // �������
          }
    }
    head=swapS(2,3,head); // ������ ��� ������� 2 � 3 �������� �����
    printf("after swap 2 and 3\n");
    printS(head); // �������
    printf("number of elements: %d\n",number(head));   // ������� ���������� ��������� � �����  
    for (int i=0;i<100;i++) { // ����� ���� ����� ��� �������
        if (sqrt(a[i])*sqrt(a[i])==a[i]) {
           head=addS(head,a[i],0);
           if (tail==NULL) { // ���� ��������� ��� ��� (������ �� ����������)
              tail=new (queue); // �������� ������
              tail->data=a[i]; // ���������� ������
              tail->next=NULL; // ��������� ��� ����� ������ ���� �� ����� ���������
              head1=tail; // ���������� ������ (��� �������� ��� � ������� ��� ��� ����� 1 �������)
           } else tail=addQ(tail,a[i]);
           b[a[i]]=false;
           printQ(head1);
        }
    } 
    queue *p1=head1;
    num=1;
    b[head1->data]=true;
    while (p1->next) {
          if (!b[p1->next->data]) {
             b[p1->next->data]=true;
             num++;
             p1=p1->next;
          } else {
             delQ(head1,num+1);           
             printQ(head1);
          }
    } 
    head1=swapQ(2,3,head1);
    printf("after swap 2 and 3\n");
    printQ(head1);    
    printf("number of elements: %d\n",number1(head1));         
    system("pause");
}
