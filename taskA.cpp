#include <iostream>

using namespace std;

class Patient {
public:
    string name;
    int age;
    string condition;
    int priority;
    Patient* next;

    Patient(string name, int age, string condition, int priority) {
        this->name = name;
        this->age = age;
        this->condition = condition;
        this->priority = priority;
    }
};

class PatientPriority {
private:
    Patient* front;
    int length;

public:
    PatientPriority() {
        front = NULL;
        length = 0;
    }

    bool isEmpty() {
        if (front == NULL) return true;
        else return false;
    }

    void add_patient(string name, int age, string condition, int priority) {
        Patient* newpatient = new Patient(name, age, condition, priority);
        if (isEmpty() || priority > front->priority) {
            newpatient->next = front;
            front = newpatient;
        } else {
            Patient* curr = front;
            while (curr->next != NULL && curr->next->priority >= priority) {
                curr = curr->next;
            }
            newpatient->next = curr->next;
            curr->next = newpatient;
        }
        length++;
    }

    void process_patient() {
        if (isEmpty()) {
            cout << "No patients to process." << endl;
        } else {
            Patient* temp = front;
            cout <<  temp->name << ", Age: " << temp->age
                 << ", Condition: " << temp->condition << ", Priority: " << temp->priority << endl;
            front = front->next;
            delete temp;
            length--;
        }
    }



    void display() {
        if (isEmpty()) {
            cout << " there is no patients" << "\n";
        } else {
            Patient* current = front;
            while (current != NULL) {
                cout << "Name: " << current->name << ", Age: " << current->age
                     << ", Condition: " << current->condition << ", Priority: " << current->priority << endl;
                current = current->next;
            }
            cout << "\n";
        }
    }



    int queue_size() {
        return length;
    }
    string FrontName()
    {
        if (isEmpty())
        {
            cout<<"there is no patients"<<"\n";
            return "";
        }
        return front->name;
    }



};

int main() {
    PatientPriority p1;
    string name, condition;
    int age, priority;

    int numPatients;

    cout << "Enter the number of patients: ";
    cin >> numPatients;

    for (int i = 0; i < numPatients; ++i) {
        cout << "Enter patient " << i + 1 << " details:" << endl;
        cout << "Name: ";
        cin>>name;
        cout << "Age: ";
        cin >> age;
        cout << "Condition (critical, urgent, normal): ";
        cin >> condition;

        if (condition == "critical") {
            priority = 3;
        } else if (condition == "urgent") {
            priority = 2;
        } else if (condition == "normal") {
            priority = 1;
        } else {
            cout << "Invalid condition. Setting priority to 1 (normal)." << endl;
            priority = 1;
        }
        cout<<"patient "<< name<<" added to the queue"<<"\n";

        p1.add_patient(name, age, condition, priority);
    }

    cout << "\n";
    cout<<"front patient name :"<<p1.FrontName()<<"\n";

    cout<<"current patients in the queue:  "<<"\n";
    p1.display();
    cout<<"processing patient... "<<"\n";
    cout<<"processing patient:   "; p1.process_patient();

    cout<<"current patients in the queue:  "<<"\n";
    p1.display();



    return 0;
}