#include <QCoreApplication>
#include <QDebug>

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* insertionSortList(ListNode* head)
{
    if (!head) return head;

    ListNode* dummyHead = new ListNode(-1);
    dummyHead->next = head;
    ListNode* p1 = head->next;
    ListNode* p2 = head;
    ListNode* p3 = dummyHead;
    while(p1)
    {
        while(p3 != p2)
        {
            if (p3->next->val < p1->val )
            {
                p3 = p3->next;
            }
            else
            {
                p2->next = p1->next;

                ListNode* t = p3->next;
                p3->next = p1;
                p1->next = t;
                break;
            }
        }

        //indicate the p1 has already been inserted, so p2 should not move
        if (p2->next == p1)
        {
            p2 = p2->next;
        }
        p1 = p2->next;
        p3 = dummyHead;
    }
    return dummyHead->next;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
