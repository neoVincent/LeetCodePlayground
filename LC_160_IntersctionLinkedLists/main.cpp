#include <QCoreApplication>
#include <math.h>
#include <QDebug>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(NULL) {}
};

pair<ListNode*, int> listLen(ListNode* head)
{
    ListNode* p = head;
    int len = 1;
    while(p->next)
    {
        len++;
        p = p->next;
    }
    return {p,len};
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
{
   auto lenA = listLen(headA);
   auto lenB = listLen(headB);

   if (lenA.first != lenB.first) return nullptr;

   ListNode* shorter = lenA.second > lenB.second ? lenB.first : lenA.first;
   ListNode* longer = lenA.second > lenB.second ? lenA.first : lenB.first;

   int k = abs(lenA.second - lenB.second);

   while(longer && k > 0)
   {
       longer = longer->next;
   }

   while(longer && shorter)
   {
      if (longer == shorter) return longer;
      longer = longer->next;
      shorter = shorter->next;
   }

   return nullptr;

}

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);
    ListNode* a1 = new ListNode(1);
    ListNode* a2 = new ListNode(2);
    ListNode* a3 = new ListNode(3);
    ListNode* a4 = new ListNode(4);
    ListNode* a5 = new ListNode(5);
    ListNode* b1 = new ListNode(6);
    ListNode* b2 = new ListNode(7);
    ListNode* b3 = new ListNode(8);
    a1->next = a2;
    a2->next = a3;
    a3->next = a4;
    a4->next = a5;
    b1->next = b2;
    b2->next = a3;
//    b3->next = a3;

    ListNode* p = getIntersectionNode(a1,b1);
    if(p) qDebug()<<"no null";
    else qDebug() <<"Nullptr";
    return app.exec();
}
