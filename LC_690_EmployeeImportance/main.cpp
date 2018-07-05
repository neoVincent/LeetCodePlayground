#include <QCoreApplication>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;

    Employee(int id, int importance, vector<int> subordinates)
    {
        this->id = id;
        this->importance = importance;
        this->subordinates = subordinates;

    }
};

Employee* locate(vector<Employee*>& employees, int id)
{
    auto iter = find_if(employees.begin(),employees.end(),[id](const Employee* e){
        return e->id == id;
    });

    if (iter == employees.end()) return nullptr;
    return *iter;
}



int getImportance(vector<Employee*> employees, int id)
{
    //locate the employee
    int res = 0;
    Employee* head = locate(employees,id);
    cout<< "id: "<<id<<endl;

    if (!head) return 0;

    cout<<"subordinates size: "<<head->subordinates.size() << endl;
    for(int id : head->subordinates)
    {
        auto importance = getImportance(employees,id);
        cout<<"Importance from sub: "<<importance<<endl;
        res += importance;
    }

    cout<<"Importance from self: "<<head->id << "  "<< head->importance<<endl;
    res += head->importance;
    return res;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Employee* e1 = new Employee(1,5,{2,3});
    Employee* e2 = new Employee(2,3,{});
    Employee* e3 = new Employee(3,3,{});
    vector<Employee*> employees {e1,e2,e3};
    cout<<"Result: " << getImportance(employees,1)<<endl;
    return a.exec();
}
