#include <iostream>
#include <string>
using namespace std;

struct Order {
    int orderId;
    string studentName;
    string foodItem;
    Order* next;
};

Order* head = NULL;

void insertAtBeginning() {
    Order* newOrder = new Order;

    cout << "Enter Order ID: ";
    cin >> newOrder->orderId;
    cin.ignore(1000, '\n');

    cout << "Enter Student Name: ";
    getline(cin, newOrder->studentName);

    cout << "Enter Food Item: ";
    getline(cin, newOrder->foodItem);

    newOrder->next = head;
    head = newOrder;

    cout << "Order added successfully.\n";
}

void insertAtEnd() {
    Order* newOrder = new Order;

    cout << "Enter Order ID: ";
    cin >> newOrder->orderId;
    cin.ignore(1000, '\n');

    cout << "Enter Student Name: ";
    getline(cin, newOrder->studentName);

    cout << "Enter Food Item: ";
    getline(cin, newOrder->foodItem);

    newOrder->next = NULL;

    if (head == NULL) {
        head = newOrder;
    } else {
        Order* temp = head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newOrder;
    }

    cout << "Order added successfully.\n";
}

void displayOrders() {
    if (head == NULL) {
        cout << "No pending orders.\n";
        return;
    }

    Order* temp = head;

    cout << "\n--- Pending Canteen Orders ---\n";

    while (temp != NULL) {
        cout << "Order ID: " << temp->orderId << endl;
        cout << "Student Name: " << temp->studentName << endl;
        cout << "Food Item: " << temp->foodItem << endl;
        cout << "-----------------------------\n";

        temp = temp->next;
    }
}

void searchOrder() {
    int id;

    cout << "Enter Order ID to search: ";
    cin >> id;

    Order* temp = head;

    while (temp != NULL) {
        if (temp->orderId == id) {
            cout << "Order found!\n";
            cout << "Student Name: " << temp->studentName << endl;
            cout << "Food Item: " << temp->foodItem << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "Order not found.\n";
}

void deleteCompletedOrder() {
    if (head == NULL) {
        cout << "No orders available to delete.\n";
        return;
    }

    int id;

    cout << "Enter completed Order ID to delete: ";
    cin >> id;

    if (head->orderId == id) {
        Order* temp = head;
        head = head->next;
        delete temp;

        cout << "Completed order deleted successfully.\n";
        return;
    }

    Order* current = head;

    while (current->next != NULL &&
           current->next->orderId != id) {
        current = current->next;
    }

    if (current->next == NULL) {
        cout << "Order ID not found.\n";
    } else {
        Order* temp = current->next;
        current->next = temp->next;
        delete temp;

        cout << "Completed order deleted successfully.\n";
    }
}

void freeMemory() {
    while (head != NULL) {
        Order* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    int choice;

    do {
        cout << "\n===== Smart Canteen Order Management System =====\n";
        cout << "1. Insert Order at Beginning\n";
        cout << "2. Insert Order at End\n";
        cout << "3. Display Pending Orders\n";
        cout << "4. Search Order by ID\n";
        cout << "5. Delete Completed Order\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";

        cin >> choice;

        switch (choice) {
            case 1:
                insertAtBeginning();
                break;

            case 2:
                insertAtEnd();
                break;

            case 3:
                displayOrders();
                break;

            case 4:
                searchOrder();
                break;

            case 5:
                deleteCompletedOrder();
                break;

            case 6:
                cout << "Program ended.\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 6);

    freeMemory();

    return 0;
}
