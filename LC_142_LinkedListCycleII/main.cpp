#include <QCoreApplication>
#include <math.h>
#include <QDebug>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

ListNode *detectCycle(ListNode *head) {
        // detect whether is has cycle
        ListNode* faster = head;
        ListNode* slower = head;

        while(faster != nullptr && faster->next != nullptr)
        {
            faster = faster->next->next;
            slower = slower->next;

            if (faster == slower) break;
        }

        if (faster == nullptr || faster->next == nullptr) return nullptr;

        // find the start point
        ListNode* p = head;
        while(p != slower)
        {
            p = p->next;
            slower = slower->next;
        }

        return p;

    }

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
