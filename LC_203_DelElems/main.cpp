#include <QCoreApplication>
#include <QDebug>


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr){}
};

ListNode* removeElements(ListNode* head, int val) {

    while(head && head->val == val) head = head->next;
    if(!head) return head;
    ListNode* p1 = head;
    ListNode* p2 = head->next;
    while(p2)
    {
        if(p2->val == val)
        {
            p1->next = p2->next;
        }
        else
        {
            p1 = p1->next;
        }
        p2 = p2->next;
    }
    return head;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    ListNode* myList = new ListNode(1);
    auto res = removeElements(myList,1);
    if(res) qDebug() << "not null";
    else qDebug() << "Nullptr";
    return a.exec();
}
