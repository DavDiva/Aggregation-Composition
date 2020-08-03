#include <iostream> 
#include <string>
#include <vector>
using namespace std;

class Worker
{
private:
    string m_name;

public:
    Worker(string name)
        : m_name(name)
    {
    }

    string getName() { return m_name; }
};

class Department
{
private:
    Worker* m_worker; 
    vector<Worker*>vect;
public:
    
    Department(Worker* worker = nullptr)
        : m_worker(worker)
    {
    }
    void add(Worker *worker)
    {
        vect.push_back(worker);
    }
    friend ostream& operator<< (ostream& out, const Department& department);

};

ostream& operator<< (ostream& out, const Department& department)
{
    for (int i = 0; i < department.vect.size(); i++)
    {
        out << department.vect[i]->getName() << endl;
    }
    return out;
}

int main()
{
    
    Worker* w1 = new Worker("Anton");
    Worker* w2 = new Worker("Ivan");
    Worker* w3 = new Worker("Max");

    {
        
        Department department; 
        department.add(w1);
        department.add(w2);
        department.add(w3);

        cout<< department;

    } 

    cout << w1->getName() << " still exists!\n";
    cout << w2->getName() << " still exists!\n";
    cout << w3->getName() << " still exists!\n";

    delete w1;
    delete w2;
    delete w3;

    return 0;
}