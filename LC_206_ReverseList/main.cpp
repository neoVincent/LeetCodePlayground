#include <QCoreApplication>
#include <QDebug>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr){}
};

ListNode* reverseList(ListNode* head)
{
    if(!head || !head->next) return head;

    ListNode* p1 = head;
    ListNode* p2 = head->next;
    head->next = nullptr;
    while(p2)
    {
        ListNode* t = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = t;
    }

    return p1;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
