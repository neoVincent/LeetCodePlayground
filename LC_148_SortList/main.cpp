#include <QCoreApplication>
#include <QDebug>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

void switchNode(ListNode* head, ListNode* &p1, ListNode* &p2)
{
    if (p1 == p2) return;

    ListNode* preP1 = nullptr;
    ListNode* preP2 = nullptr;
    for(ListNode* cur = head; cur != nullptr; cur = cur->next)
    {
        if (cur->next == p1) preP1 = cur;
        if (cur->next == p2) preP2 = cur;
        if (preP1 && preP2 ) break;
    }


    if (preP1 == p2 || preP2 == p1)
    {
        if (p1->next == p2)
        {
            preP1->next = p2;
            p1->next = p2->next;
            p2->next = p1;

            p1 = preP1->next;
            p2 = p1->next;
        }
        else
        {
            preP2->next = p1;
            p2->next = p1->next;
            p1->next = p2;

            p2 = preP2->next;
            p1 = p2->next;
        }
    }
    else
    {
        ListNode* t = p1->next;
        p1->next = p2->next;
        preP2->next = p1;
        preP1->next = p2;
        p2->next = t;

        p1 = preP1->next;
        p2 = preP2->next;
    }

}

//exclude head, exclude tail (head,tail)
void partition(ListNode* head, ListNode* tail)
{
    if (head->next == tail) return;

    ListNode* pivot = head->next;
    ListNode* cur = pivot->next;
    ListNode* pNode = pivot;
    while(cur != tail)
    {
        if (cur->val > pivot->val)
        {
            cur = cur->next;
        }
        else
        {
            pNode = pNode->next;
            switchNode(head,pNode,cur);
            cur = cur->next;
        }
    }
    switchNode(head,pivot,pNode);
    partition(head,pNode);
    partition(pNode,tail);
}

ListNode* sortList(ListNode* head)
{
    if (!head || !head->next) return head;

    ListNode* dummyHead = new ListNode(-1);
    dummyHead->next = head;
    ListNode* pivot = head;
    ListNode* cur = head->next;
    ListNode* pNode = head;

    while(cur)
    {
        if (cur->val > pivot->val)
        {
            cur = cur->next;
        }
        else
        {
            pNode = pNode->next;
            switchNode(dummyHead,pNode,cur);
            cur = cur->next;
        }
    }
    switchNode(dummyHead,pivot,pNode);
    partition(dummyHead,pNode);
    partition(pNode,nullptr);

    return dummyHead->next;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    ListNode* head = new ListNode(4);
    ListNode* n2 = new ListNode(19);
    ListNode* n3 = new ListNode(14);
    ListNode* n4 = new ListNode(5);
    ListNode* n5 = new ListNode(-3);
    ListNode* n6 = new ListNode(1);
    ListNode* n7 = new ListNode(8);
    ListNode* n8 = new ListNode(5);
    ListNode* n9 = new ListNode(11);
    ListNode* n10 = new ListNode(15);
    head->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;
    n7->next = n8;
    n8->next = n9;
    n9->next = n10;
    sortList(head);
    return a.exec();
}
