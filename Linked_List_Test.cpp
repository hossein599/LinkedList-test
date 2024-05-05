#include <iostream>
#include <string>
using namespace std;

struct Node 
{
public:
    int id;
    string name;
    float gpa;
    Node* next;

    Node(int id, string name , float gpa) 
    {
        this->id = id;
        this->name = name;
        this->gpa = gpa;
        next = NULL;
    }
};

struct LinkedList 
{
public:
    Node* head;

    LinkedList() 
    {
        head = NULL;
    }

    void addStudent(int id, string name, float gpa) 
    {
        Node* newStudent = new Node(id, name, gpa);

        if (head == NULL) 
        {
            head = newStudent;
        }
        else if (gpa > head->gpa) 
        {
            newStudent->next = head;
            head = newStudent;
        }
        else {
            Node* s1 = head;
            Node* s2 = s1->next;
            while (s2 != NULL && gpa < s2->gpa) 
            {
                s1 = s2;
                s2 = s2->next;
            }
            s1->next = newStudent;
            newStudent->next = s2;
        }
    }

    void display() 
    {
        Node* curr = head;
        while (curr != NULL) 
        {
            cout << curr->id << " " << curr->name << " " << curr->gpa << endl;
            curr = curr->next;
        }
    }

    void deleteStudent(int id) 
    {
        Node* curr = head;
        Node* prev = NULL;
        while (curr != NULL && curr->id != id) 
        {
            prev = curr;
            curr = curr->next;
        }
        if (curr == NULL) 
        {
            cout << "Student with ID " << id << " not found." << endl;
        } 
        else 
        {
            if (prev == NULL) 
            {
                head = curr->next;
            } 
            else 
            {
                prev->next = curr->next;
            }
            delete curr;
            cout << "Student with ID " << id << " deleted." << endl;
        }
    }
};


int main() 
{
    int id, delnum;
    string name;
    float gpa;
    bool exit = false;
    char per;
    LinkedList list;
    
    while(!exit)
    {
        cout << " please enter student ID: ";
        cin >> id;
        cout << " please enter student Name: ";
        cin >> name;
        cout << " please enter student GPA: ";
        cin >> gpa;
        list.addStudent(id, name, gpa);
        cout << "Exit?(Y/N): ";
        cin >> per;
        if(per == 'y' || per == 'Y')
        {
            exit = true;
        }
    }

    cout << "Initial list:" << endl;
    list.display();

    cout << " please enter id for delete student: ";
    cin >> delnum;
    cout << endl << "Deleting student with ID "<< delnum << " ..." << endl;
    list.deleteStudent(delnum);

    cout << endl << "Updated list:" << endl;
    list.display();

    string x;
    cin >> x;

    return 0;
}