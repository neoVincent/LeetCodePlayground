#include <QCoreApplication>
#include <vector>
#include <QDebug>
#include <stack>
using namespace std;

class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        min = INT_MAX;
    }

    void push(int x) {
        if ( x < min)
        {
            min = x;
        }
        vec.push_back(x);
    }

    void pop() {
        int pVal = vec.back();
        vec.pop_back();
        if (pVal == min)
        {
            auto iter = min_element(vec.begin(),vec.end());
            if (iter != vec.end())
            {
                min = *iter;
            }
            else
            {
                min = INT_MAX;
            }
        }
    }

    int top() {
        return vec.back();
    }

    int getMin() {
        if (vec.empty()) return INT_MAX;
        return min;
    }

    vector<int> vec;
    int min;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    qDebug() << minStack.getMin();
    minStack.pop();
    qDebug() << minStack.top();
    qDebug() << minStack.getMin();

    return a.exec();
}
