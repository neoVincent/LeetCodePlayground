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
    int pivot;

    while(p1)
    {
        pivot = p1->val;
        if(p1->next && p1->next->val == pivot)
        {
            while(p1 && p1->val == pivot)
            {
                ListNode* t = p1;
                p1 = p1->next;
                delete t;
            }
        }

        if(p1 && p1->next && p1->val == p1->next->val) continue;

        if(p2)
        {
            p2->next = p1;
            p2 = p2->next;
        }
        else if(!p1)
        {
            head = nullptr;
        }
        else
        {
            p2 = p1;
            head = p2;
        }
        if(p1) p1 = p1->next;
    }
    return head;

//    if(!head) return nullptr;

//           ListNode *dummyHead = new ListNode(0); //Create a temp node to build distinct list while curr skips elements duplicate elements.

//           dummyHead->next = head;

//           ListNode *pre = dummyHead;


//           ListNode *curr = head;

//           while(curr && curr->next)
//           {
//               ListNode *temp = curr->next;

//               //Found duplicate, move temp node until we find a distinct element
//               if(temp && curr->val == temp->val){
//                   while(temp && curr->val == temp->val) temp = temp->next;

//                   //Move curr to next distinct element
//                   curr = temp;

//                   //Set next distinct element
//                   pre->next = curr;
//               } else {

//                   //Element is distinct, traverse normally.
//                   pre->next = curr;

//                   pre = pre->next;
//                   curr = curr->next;
//               }
//           }

//           return dummyHead->next;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    ListNode* n2 = new ListNode(1);
    ListNode* n1 = new ListNode(1);
    n1->next = n2;

    deleteDuplicates(n2);
    return a.exec();
}
