#include <stdlib.h>
#include <stdio.h>

int main() {
    tQueue *myQueue;// �������� �������
    tStack *myStack;    // � ����
    myStack=new tStack; // ������� ������, ������� ������������
    myQueue=new tQueue;    
    for (int i=0;i<10;i++) { // ������� 10 ����. ����� � ����
        myStack->AddElement(rand()%100); // �� 0 �� 99
        myStack->PrintList(); // ����� �����
    }
    myStack->DeleteElement(rand()%10+1); // ������ ��������� ������� �����
    myStack->PrintList(); // �������
    for (int i=0;i<10;i++) { // ���� ����� ��� �������
        myQueue->AddElement(rand()%100);
        myQueue->PrintList();
    }
    myQueue->DeleteElement(rand()%10+1);
    myQueue->PrintList();     
    system("pause");
}
