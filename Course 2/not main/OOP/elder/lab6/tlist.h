//--------------------------------------���������� �������--------------------------
class tList { // ����� ����� - ������
      protected: // ������ ������ ��� ������ � �������� �������
       struct List { // ��������� ������
        int Data; // ������
        List *Next;  // ������ �� ����. �������
       };   
      public: // ������ ��� ����
       tList(); // �����������
       virtual void PrintList(){}; // ����� ������
       virtual void DeleteElement(){}; // �������� ��������
       virtual void AddElement(){}; // ���������� ��������
};
class tStack: public tList {  // ����� ����� �������� �� ������ ������
      protected: // ��������� ���� ������
       List *Head;   
      public:
       tStack(); // �����������
       virtual void PrintList(); // ������ �����
       virtual void DeleteElement(int NumElement); // �������� �������� �� ������
       virtual void AddElement(int Element); // ���������� �������� �� ������
};
class tQueue: public tStack {  // ������� - ����������� �� �����
      protected:
       List *Tail;   // ����������� ���� �����
      public:
       tQueue(); // �����������
       virtual void PrintList(); // ����� �������
       virtual void DeleteElement(int NumElement); // ��������
       virtual void AddElement(int Element); // ����������
};
//--------------------------�������� �������������----------------------------------
tList::tList() { // ����������� ��� ������ ������
}
tStack::tStack():tList() { // ��� ����� ���������������� ������
     Head=NULL;
}
tQueue::tQueue():tStack() { // ��� ������� ���������������� �����
     Tail=NULL;    
}
//------------------------�������� ��������---------------------------------------

void tStack::DeleteElement(int NumElement) { // �������� �������� �� �����
     NumElement--; // ��������� ����� �������� �� 1 (����� ��� ������� ������� ��������� �������� �� ������ ��������)
     if (NumElement<0) { // ���� �������� ������������� ���������� ���������, �� ������ �������� ���
        printf("Not found!\n"); // ����� � ��� ��� ������ �� �������
        return; // � �����
     }
     List *pHead,*sHead,*Temp; // ��������� ���������
     Temp=Head; // ��������� �� ������
     sHead=new List; // ������� ���������, ����� �������
     sHead->Next=Head; // ����� ������
     pHead=sHead; // � ������� � ��������, ������� ��������� �� ������, ��������� ���
     while (NumElement>0) { // ���� ����� ��������� ����
           NumElement--; // ��������� ���
           pHead=Temp; // �������� ���������
           Temp=Temp->Next;
           if (Temp==NULL) { // ���� �������� ��� ������, ������ �������� �����������
              printf("Not found!\n"); // ������� �� ���� ������
              return; // �����
           }
     }
     pHead->Next=Temp->Next; // ����� ������������ ������ � �������� �� ���������� �� ������� ����� ����������
     free(Temp); // � ������� ��� �������
     Head=sHead->Next; // ���������� ����� ������ (������� �� ����������� ������ ����������)
     free(sHead); // � ������� ��������� �� ������������(�� ��� �� ������)
}
void tStack::AddElement(int Element) { // ���������� �������� � ����
     List *NewElement = new List; // ������� ����� �������
     NewElement->Data=Element; // ��������� �������
     NewElement->Next=Head; // ������ ����� �������
     Head=NewElement; // ��������� ������
}
void tStack::PrintList() { // ����� �����
     List *Temp=Head; // ������ � ������
     while (Temp) { // ���� ���� ��������
           printf("%d ",Temp->Data);     // ������� ������ 
           Temp=Temp->Next; // � ��������� � ��������� ��������
     }
     printf("\n");
}
void tQueue::AddElement(int Element) { // ���������� �������� � �������
     List *NewElement = new List; // ��������� ������
     NewElement->Data=Element; // ��������� �������
     NewElement->Next=NULL; // ����� �������� ������ ���
     if (Tail==NULL) { // ���� ������ ���
        Head=NewElement; // ������� ����� ������� � ������
        Tail=Head; // ����������� �����
     } else {
        Tail->Next=NewElement; // ����� ������� ����� ������� ����� ������
        Tail=NewElement; // ������� �����
     }
}
void tQueue::PrintList() { // ����� ������� ���������� ������ �����
     List *Temp=Head;
     while (Temp) {
           printf("%d ",Temp->Data);     
           Temp=Temp->Next;
     }
     printf("\n");
}
void tQueue::DeleteElement(int NumElement) { // �������� �������� �� ������� ���������� �����
     NumElement--;
     if (NumElement<0) {
        printf("Not found!\n");
        return;
     }
     List *pHead,*sHead,*Temp;
     Temp=Head;
     sHead=new List;
     sHead->Next=Head;
     pHead=sHead;
     while (NumElement>0) {
           NumElement--;
           pHead=Temp;     
           Temp=Temp->Next;
           if (Temp==NULL) {
              printf("Not found!\n");
              return;
           }
     }
     pHead->Next=Temp->Next;
     free(Temp);
     Head=sHead->Next;
     free(sHead);
}
