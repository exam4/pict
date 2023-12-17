//display end, delete end
//dry run for same

#include <iostream>
using namespace std;

struct Employee
{
    string name;
    int empId;
    int salary;
};

class Emp
{
private:
    Employee E[20];
    int size, f, r;

public:
    Emp();
    void EnQueue();
    void DeQueue();
    void IsEmpty();
    void IsFull();
    void Display();
};

Emp::Emp()
{
    f = -1;
    r = -1;
    cout << "Enter the size of the queue: ";
    cin >> size;

    for (int i = 0; i < size; i++)
    {
        E[i].name = "";
        E[i].empId = 0;
        E[i].salary = 0;
    }
}

void Emp::EnQueue()
{
    if ((r + 1) % size == f)
    {
        cout << "\nThe queue is full. Cannot add more elements.";
    }
    else
    {
        if (f == -1)
        {
            f = 0;
        }
        r = (r + 1) % size;
        cout << "\nEnter name: ";
        cin >> E[r].name;
        cout << "Enter employee id: ";
        cin >> E[r].empId;
        cout << "Enter salary: ";
        cin >> E[r].salary;
    }
}

void Emp::DeQueue()
{
    if (f == -1)
    {
        cout << "\nThe queue is empty. Nothing to remove.";
    }
    else
    {
        cout << "\nRemoved entry details:\n";
        cout << "Name: " << E[f].name << endl;
        cout << "Employee ID: " << E[f].empId << endl;
        cout << "Salary: " << E[f].salary << endl;

        if (f == r)
        {
            f = -1;
            r = -1;
        }
        else
        {
            f = (f + 1) % size;
        }
    }
}

void Emp::IsFull()
{
    if ((r + 1) % size == f)
    {
        cout << "\nThe queue is full.";
    }
    else
    {
        cout << "\nThe queue is not full.";
    }
}

void Emp::IsEmpty()
{
    if (f == -1)
    {
        cout << "\nThe queue is empty.";
    }
    else
    {
        cout << "\nThe queue is not empty.";
    }
}

void Emp::Display()
{
    if (f == -1)
    {
        cout << "\nThe queue is empty.";
    }
    else
    {
        int i = f;
        cout << "\nEmployee Queue:\n";
        while (true)
        {
            cout << "\nName: " << E[i].name << endl;
            cout << "Employee ID: " << E[i].empId << endl;
            cout << "Salary: " << E[i].salary << endl;

            if (i == r)
                break;

            i = (i + 1) % size;
        }
    }
}

int main()
{
    Emp E1;
    int choice;
    int yes = 1;
    while (yes == 1)
    {
        cout << "\nWhat do you want to do? \n1. Add an element\n2. Remove an Element\n3. Check if empty\n4. Check if full\n5. Display the queue\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            E1.EnQueue();
            break;
        case 2:
            E1.DeQueue();
            break;
        case 3:
            E1.IsEmpty();
            break;
        case 4:
            E1.IsFull();
            break;
        case 5:
            E1.Display();
            break;
        default:
            cout << "\nWrong choice!";
        }
        cout << "\nDo you want to Continue again? 1.Yes  2.No : ";
        cin >> yes;
    }
    return 0;
}
