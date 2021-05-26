/*
    Topic: the importance of the member
    Author: Sliverchen
    Create file date : 2021 / 5 / 1
    Explanation:
        利用深度优先搜索

*/

#include <iostream>
#include <vector>
using namespace std;

int importance;
//define the data structure of the employee
class Employee
{
public:
    int id;
    int importance;
    vector<int> subordinates;
    Employee(int i, int im, vector<int> sub) : id(i), importance(im), subordinates(sub) {}
};

void getCurimportance(const vector<Employee *> &employees, const int &id)
{
    for (int i = 0; i < employees.size(); i++)
    {
        if (employees[i]->id == id)
        {
            importance += employees[i]->importance;
            if (!employees[i]->subordinates.empty())
            {
                for (auto subid : employees[i]->subordinates)
                    getCurimportance(employees, subid);
            }
        }
        else
            continue;
    }
}

int getImportance(const vector<Employee *> &employees, int id)
{
    importance = 0;
    getCurimportance(employees, id);
    return importance;
}

int main()
{
    vector<Employee *> employees = {new Employee(1, 5, {2, 3}), new Employee(2, 3, {}), new Employee(3, 3, {})};
    cout << getImportance(employees, 1) << endl;
    system("pause");
    return 0;
}