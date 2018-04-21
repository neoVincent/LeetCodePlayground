#include <QCoreApplication>
#include <QDebug>

using namespace std;

class MyCalendarTwo
{
public:

    MyCalendarTwo()
    {

    }

    MyCalendarTwo(int start, int end)
    {
        this->start = start;
        this->end = end;
        isOverlap = false;
        this->left = nullptr;
        this->right = nullptr;
    }

    bool book(int start, int end)
    {

        return insert(calendarTree,new MyCalendarTwo(start,end));
    }

    bool insert(MyCalendarTwo* tree, MyCalendarTwo* node)
    {
        if (tree == nullptr)
        {
            calendarTree = node;
            return true;
        }
        if (node->start >= tree->end)
        {
            if (tree->right) insert(tree->right,node);
            else tree->right = node;
        }
        else if (node->end <= tree->start)
        {
            if (tree->left) insert(tree->left,node);
            else tree->left = node;
        }
        else if (node->start >= tree->start && node->end <= tree->end)
        {
            if (tree->isOverlap) return false;
            else tree->isOverlap = true;
        }
        else
        {
            if (tree->isOverlap) return false;
            else tree->isOverlap = true;

            int minStart = min(tree->start,node->start);
            int maxEnd = max(tree->end,node->end);

            if (minStart != tree->start)
            {
                return insert(tree,new MyCalendarTwo(minStart,tree->start));
            }

            if (maxEnd != tree->end)
            {
                return insert(tree, new MyCalendarTwo(tree->end,maxEnd));
            }
        }
        return true;
    }

    int start,end;
    MyCalendarTwo* left;
    MyCalendarTwo* right;
    bool isOverlap;

    static MyCalendarTwo* calendarTree;
};

MyCalendarTwo* MyCalendarTwo::calendarTree = nullptr;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    MyCalendarTwo calendar;
    qDebug() << calendar.book(26,35) << endl;
    qDebug() << calendar.book(26,32) << endl;
    qDebug() << calendar.book(25,32) << endl;
    qDebug() << calendar.book(18,26) << endl;
    qDebug() << calendar.book(40,45) << endl;
    qDebug() << calendar.book(19,26) << endl;
    qDebug() << calendar.book(48,50) << endl;
    qDebug() << calendar.book(1,6) << endl;
    qDebug() << calendar.book(46,50) << endl;
    qDebug() << calendar.book(11,18) << endl;
    return a.exec();
}
