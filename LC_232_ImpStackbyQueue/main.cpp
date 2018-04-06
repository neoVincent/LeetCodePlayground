

#include <QCoreApplication>
#include <queue>
#include <QDebug>

using namespace std;
class MyStack {
public:
    /** Initialize your data structure here. */
    MyStack() {

    }

    /** Push element x onto stack. */
    void push(int x) {
        qu.push(x);
    }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int val = qu.back();
        qDebug()<<"size "<<qu.size();
        for(int i = qu.size() - 1  ; i > 0 ; i--)
        {
            qu.push(qu.front());
            qu.pop();
        }
        qu.pop();
        return val;
    }

    /** Get the top element. */
    int top() {
        return qu.back();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
        return qu.empty();
    }

    queue<int> qu;
};

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    MyStack stack;
    stack.push(2);

    qDebug() << stack.pop()<<endl;
    qDebug() << stack.top();
    return a.exec();
}
