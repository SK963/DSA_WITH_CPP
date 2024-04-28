#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Book {
    string title;
    int quantity;
    int restockPriority;

    // Custom comparison function for the priority queue
    bool operator<(const Book& other) const {
        // Higher priority books should have lower values
        return restockPriority > other.restockPriority;
    }
};

int main() {
    priority_queue<Book> inventory;

    while (true) {
        int choice;
        cin >> choice;

        if (choice == 1) {
            // Add book to inventory
            string title;
            int quantity, restockPriority;
            cin.ignore(); // Clear newline character
            getline(cin, title);
            cin >> quantity >> restockPriority;
            Book book = {title, quantity, restockPriority};
            inventory.push(book);
            cout << "Book added to the inventory." << endl;
        } else if (choice == 2) {
            // Restock book
            if (!inventory.empty()) {
                Book topBook = inventory.top();
                inventory.pop();
                cout << "Restocked book: " << topBook.title << endl;
            } else {
                cout << "No books in the inventory." << endl;
            }
        } else if (choice == 3) {
            // View next book to restock
            if (!inventory.empty()) {
                Book topBook = inventory.top();
                cout << "Next book to restock: " << topBook.title << endl;
            } else {
                cout << "No books in the inventory." << endl;
            }
        } else if (choice == 4) {
            // Exit the application
            cout << "Exiting the application." << endl;
            break;
        } else {
            // Invalid choice
            cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }

    return 0;
}
