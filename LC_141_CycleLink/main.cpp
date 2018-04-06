#include <QCoreApplication>
#include <map>
#include <QDebug>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr){}
};

bool hasCycle(ListNode *head)
{
    map<ListNode*,bool> valMap;
    while(head)
    {
        if(valMap[head]) return true;
        valMap[head] = true;
        head = head->next;
    }
    return false;

//    if (head == NULL) {
//                return false;
//            }
//            ListNode *singleJump = head;
//            ListNode *doubleJump = head;
//            while(doubleJump->next != NULL && doubleJump->next->next != NULL) {
//                singleJump = singleJump->next;
//                doubleJump = doubleJump->next->next;
//                if (singleJump == doubleJump) {
//                    return true;
//                }
//            }
//            return false;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    ListNode *p = new ListNode(1);
    qDebug() << hasCycle(p);
    return a.exec();
}
