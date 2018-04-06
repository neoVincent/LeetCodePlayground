#include <QCoreApplication>
#include <QDebug>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
    ListNode* head = nullptr;
    if(!l1) return l2;
    if(!l2) return l1;
    if(l1->val < l2->val)
    {
        head = l1;
        l1 = l1->next;
    }
    else
    {
        head = l2;
        l2 = l2->next;
    }

    ListNode* p = head;
    while(l1 && l2)
    {
        if(l1->val < l2->val)
        {
            p->next = l1;
            p = p->next;
            l1 = l1->next;
        }
        else
        {
            p->next = l2;
            p = p->next;
            l2 = l2->next;
        }
    }
    if (l1) p->next = l1;
    if (l2) p->next = l2;

    return head;
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
    b2->next = b3;
    ListNode* list = mergeTwoLists(a1,b1);

    return app.exec();
}
