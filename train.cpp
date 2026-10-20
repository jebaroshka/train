#include <iostream>
using namespace std;

struct Coach
{
    int coachNo;
    Coach* next;
};

// Add coach at beginning
void addBeginning(Coach*& head, int no)
{
    Coach* newCoach = new Coach;
    newCoach->coachNo = no;
    newCoach->next = head;
    head = newCoach;
}

// Add coach at end
void addEnd(Coach*& head, int no)
{
    Coach* newCoach = new Coach;
    newCoach->coachNo = no;
    newCoach->next = NULL;

    if (head == NULL)
    {
        head = newCoach;
        return;
    }

    Coach* temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newCoach;
}

// Remove a coach
void removeCoach(Coach*& head, int no)
{
    if (head == NULL)
    {
        cout << "Train is empty.\n";
        return;
    }

    if (head->coachNo == no)
    {
        Coach* temp = head;
        head = head->next;
        delete temp;
        cout << "Coach " << no << " removed.\n";
        return;
    }

    Coach* temp = head;

    while (temp->next != NULL && temp->next->coachNo != no)
    {
        temp = temp->next;
    }

    if (temp->next == NULL)
    {
        cout << "Coach " << no << " not found.\n";
        return;
    }

    Coach* deleteCoach = temp->next;
    temp->next = deleteCoach->next;
    delete deleteCoach;

    cout << "Coach " << no << " removed.\n";
}

// Display all coaches
void display(Coach* head)
{
    if (head == NULL)
    {
        cout << "Train is empty.\n";
        return;
    }

    Coach* temp = head;

    cout << "Train: ";

    while (temp != NULL)
    {
        cout << "Coach" << temp->coachNo << " -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

int main()
{
    Coach* head = NULL;
    int choice, no;

    do
    {
        cout << "\n===== TRAIN COACH MANAGEMENT =====\n";
        cout << "1. Add coach at beginning\n";
        cout << "2. Add coach at end\n";
        cout << "3. Remove a coach\n";
        cout << "4. Display all coaches\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter coach number: ";
                cin >> no;
                addBeginning(head, no);
                cout << "Coach added at beginning.\n";
                break;

            case 2:
                cout << "Enter coach number: ";
                cin >> no;
                addEnd(head, no);
                cout << "Coach added at end.\n";
                break;

            case 3:
                cout << "Enter coach number to remove: ";
                cin >> no;
                removeCoach(head, no);
                break;

            case 4:
                display(head);
                break;

            case 5:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}
