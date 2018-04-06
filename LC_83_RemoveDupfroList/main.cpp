#include <QCoreApplication>
#include <QDebug>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr){}
};

ListNode* deleteDuplicates(ListNode* head)
{
    ListNode* p1 = head;
    ListNode* p2 = nullptr;
    while(p1)
    {
        if(p2 && p2->val == p1->val)
        {
            ListNode* t = p1;
            p2->next = p1->next;
            p1 = p1->next;
            delete t;
            continue;
        }
        p2 = p1;
        p1 = p1->next;
    }
    return head;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
