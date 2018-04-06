#include <QCoreApplication>
#include <stack>
using namespace std;

class MyQueue {
public:
    /** Initialize your data structure here. */
    MyQueue() {

    }

    /** Push element x to the back of queue. */
    void push(int x) {
        while(!mockQu.empty())
        {
            st.push(mockQu.top());
            mockQu.pop();
        }

        st.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        while(!st.empty())
        {
            mockQu.push(st.top());
            st.pop();
        }
        int val = mockQu.top();
        mockQu.pop();
        return val;
    }

    /** Get the front element. */
    int peek() {
        while(!st.empty())
        {
            mockQu.push(st.top());
            st.pop();
        }
        return mockQu.top();
    }

    /** Returns whether the queue is empty. */
    bool empty() {
        return (mockQu.empty() && st.empty());
    }

    stack<int> st;
    stack<int> mockQu;
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
