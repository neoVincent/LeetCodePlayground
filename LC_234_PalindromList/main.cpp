#include <QCoreApplication>
#include <stack>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr){}
};

bool isPalindrome(ListNode* head)
{
    if(!head) return true;

    stack<ListNode*> st;
    queue<ListNode*> qu;
    while(head)
    {
        st.push(head);
        qu.push(head);
        head = head->next;
    }
    while(!st.empty())
    {
        if(st.top()->val != qu.front()->val) return false;
        st.pop();
        qu.pop();
    }
    return true;

//    int cnt=0;
//           if(head==NULL||head->next==NULL) return true;
//           ListNode *p=head;
//           while(p!=NULL)
//           {
//               ++cnt;
//               p=p->next;
//           }
//          // cout<<"cnt="<<cnt<<endl;
//           int n=cnt/2;
//           for(p=head;n>1;--n)
//           {
//               ListNode *tmp=p->next;
//               //head=p->next;
//               p->next=tmp->next;
//               tmp->next=head;
//               head=tmp;
//           }
//           p=p->next;
//           if(cnt%2==1)
//               p=p->next;
//           //cout<<"p="<<p->val<<" head="<<head->val<<endl;
//           //cout<<"cnt/="<<n-1<<endl;
//           for(int i=0;i<cnt/2;++i)
//           {
//              // cout<<"p="<<p->val<<" head="<<head->val<<endl;
//               if(p->val!=head->val)
//                   return false;

//               p=p->next;
//               head=head->next;
//           }
//           return true;
}



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
