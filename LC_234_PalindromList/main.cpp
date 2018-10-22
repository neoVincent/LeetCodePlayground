#include <QCoreApplication>
#include <stack>
#include <queue>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr){}
};

struct ResultNode
{
    bool isPalindrome;
    ListNode* node;
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
}

//Iterate
bool isPalindrome2(ListNode* head)
{

    //use runner pointer
    if (!head) return true;
    ListNode* iter = head;
    ListNode* p1 = head;
    stack<ListNode*> firstHalf;
    while(iter && iter->next)
    {
        firstHalf.push(p1);
        p1 = p1->next;
        iter = iter->next->next;
    }

    //different case: if the length is odd, p1 go to next
    if (iter)
    {
        p1 = p1->next;
    }

    while(!firstHalf.empty())
    {
        auto p = firstHalf.top();
        firstHalf.pop();
        if (p->val != p1->val) return false;
        p1 = p1->next;
    }
    return true;
}

ResultNode recurse(ListNode* head, int length)
{
    //arrive at the middle
    //even number
    if (head == nullptr || length <= 0)
    {
        return {true,head};
    }
    else if (length == 1)
    {
        return {true,head->next};
    }

    ResultNode result = recurse(head->next,length-2);
    if (!result.isPalindrome || !result.node)
    {
        return result;
    }

    result.isPalindrome = (result.node->val == head->val);
    result.node = result.node->next;

    return result;
}

int listSize(ListNode* head)
{
    ListNode* p = head;
    int size = 0;
    while(p)
    {
        size++;
        p = p->next;
    }
    return size;
}

//Recurse
bool isPalindrome3(ListNode* head)
{
    int size = listSize(head);
    return recurse(head,size).isPalindrome;
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    ListNode* l3 = new ListNode(1);
    ListNode* l2 = new ListNode(0);
    ListNode* l1 = new ListNode(1);
    l1->next = l2;
    l2->next = l3;
    cout << isPalindrome3(l1)<< endl;
    return a.exec();
}
