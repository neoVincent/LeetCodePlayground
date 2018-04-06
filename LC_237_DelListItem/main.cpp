#include <QCoreApplication>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr){}
};

void deleteNode(ListNode* node)
{
    node->val = node->next->val;
    node->next = node->next->next;
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
