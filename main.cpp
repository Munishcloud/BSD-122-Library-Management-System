#include <iostream>
#include <string>
using namespace std;

class Book {
public:
    int id;
    string title;
    string author;
    bool isBorrowed;

    void displayBook() {
        cout << "Book ID: " << id << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Status: " << (isBorrowed ? "Borrowed" : "Available") << endl;
    }
};

class Library {
private:
    Book books[50];
    int bookCount;

public:
    Library() {
        bookCount = 0;
    }

    void addBook() {
        Book b;
        cout << "Enter Book ID: ";
        cin >> b.id;
        cin.ignore();

        cout << "Enter Book Title: ";
        getline(cin, b.title);

        cout << "Enter Author Name: ";
        getline(cin, b.author);

        b.isBorrowed = false;
        books[bookCount] = b;
        bookCount++;

        cout << "Book added successfully!" << endl;
    }

    void displayBooks() {
        if (bookCount == 0) {
            cout << "No books available." << endl;
            return;
        }

        for (int i = 0; i < bookCount; i++) {
            cout << "\nBook " << i + 1 << endl;
            books[i].displayBook();
        }
    }

    void borrowBook() {
        int id;
        cout << "Enter Book ID to borrow: ";
        cin >> id;

        for (int i = 0; i < bookCount; i++) {
            if (books[i].id == id && !books[i].isBorrowed) {
                books[i].isBorrowed = true;
                cout << "Book borrowed successfully!" << endl;
                return;
            }
        }
        cout << "Book not available." << endl;
    }

    void returnBook() {
        int id;
        cout << "Enter Book ID to return: ";
        cin >> id;

        for (int i = 0; i < bookCount; i++) {
            if (books[i].id == id && books[i].isBorrowed) {
                books[i].isBorrowed = false;
                cout << "Book returned successfully!" << endl;
                return;
            }
        }
        cout << "Invalid book ID." << endl;
    }
};

int main() {
    Library library;
    int choice;

    do {
        cout << "\n--- Online Library Management System ---\n";
        cout << "1. Add Book\n";
        cout << "2. Display Books\n";
        cout << "3. Borrow Book\n";
        cout << "4. Return Book\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                library.addBook();
                break;
            case 2:
                library.displayBooks();
                break;
            case 3:
                library.borrowBook();
                break;
            case 4:
                library.returnBook();
                break;
            case 0:
                cout << "Exiting system..." << endl;
                break;
            default:
                cout << "Invalid choice. Try again." << endl;
        }
    } while (choice != 0);

    return 0;
}
