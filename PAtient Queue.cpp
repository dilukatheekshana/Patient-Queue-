#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

class Patient {
public:
    string name;
    int age;
    Patient() : name(""), age(-1) {}

    Patient(const string& n, int a) : name(n), age(a) {}
};

class Queuex {
private:
    Patient *queueArray;
    int maxSize;
    int front;
    int rear;
    int count;

public:
    Queuex(int s);
    ~Queuex();
    void enqueue(const Patient& p);
    Patient dequeue();
    Patient peekFront();
    bool isFull();
    bool isEmpty();
    void viewQueue();
    int Qsize();
};

Queuex::Queuex(int s) {
    queueArray = new Patient[s];
    maxSize = s;
    count = 0;
    front = 0;
    rear = -1;
}

Queuex::~Queuex() {
    delete[] queueArray;
}

int Queuex::Qsize()
{
    return count;
}

bool Queuex::isFull() {
    return (count == maxSize);
}

bool Queuex::isEmpty() {
    return (count == 0);
}

void Queuex::enqueue(const Patient& p) {
    if (isFull()) {
        cout << "Queue is full. Can't insert" << endl;
    } else {
        rear = (rear + 1) % maxSize;
        queueArray[rear] = p;
        count++;
    }
}

Patient Queuex::dequeue() {
    if (isEmpty()) {
        cout << "Queue is Empty" << endl;
        return Patient("", -1);
    } else {
        Patient result = queueArray[front];
        front = (front + 1) % maxSize;
        count--;
        return result;
    }
}

Patient Queuex::peekFront() {
    if (isEmpty()) {
        cout << "Queue is empty" << endl;
        return Patient("", -1);
    } else {
        return queueArray[front];
    }
}

void Queuex::viewQueue() {
    if (!isEmpty()) {
        cout << "Current Queue:" << endl;
        int index = front;
        for (int i = 0; i < count; i++) {
            Patient patient = queueArray[index];
            cout << i + 1 << ". " << patient.name << " (Age: " << patient.age << ")" << endl;
            index = (index + 1) % maxSize;
        }
    } else {
        cout << "Queue is empty" << endl;
    }
}

int main() {
    int size;
    cout << "Enter the size of the queue: ";
    cin >> size;

    Queuex patientQueue(size);

    while (true) {
        system("cls");
        cout << "\nOptions:" << endl;
        cout << "1. Add a patient to the queue" << endl;
        cout << "2. Remove the next patient from the queue" << endl;
        cout << "3. View the current queue" << endl;
        cout << "4. View Count" << endl;
        cout << "5. Quit" << endl;

        int choice;
        cout << "Enter your choice (1/2/3/4/5): ";
        cin >> choice;

        switch (choice) {
            case 1: {
                system("cls");
                string patientName;
                int patientAge;
                cout << "Enter the patient's name: ";
                cin.ignore();
                getline(cin, patientName);
                cout << "Enter the patient's age: ";
                cin >> patientAge;
                Patient patient(patientName, patientAge);
                patientQueue.enqueue(patient);
                break;
            }
            case 2: {
                system("cls");
                Patient removedPatient = patientQueue.dequeue();
                if (removedPatient.age != -1) {
                    cout << removedPatient.name << " (Age: " << removedPatient.age << ") has been removed from the queue." << endl;
                }
                break;
            }
            case 3: {
                system("cls");
                patientQueue.viewQueue();
                break;
            }
            case 4: {
                system("cls");
                cout << "Queue size: " << patientQueue.Qsize() << endl;
                break;
            }
            case 5: {
                cout << "Exiting the application." << endl;
                return 0;
            }
            default: {
                cout << "Invalid choice. Please select a valid option." << endl;
                break;
            }
        }
        getch();
    }

    return 0;
}
