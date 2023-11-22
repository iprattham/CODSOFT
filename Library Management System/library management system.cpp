#include <iostream>
#include <vector>
#include <string>
#include <ctime>

using namespace std;

struct Book {
    string title;
    string author;
    string isbn;
    bool available;
    time_t dueDate; // Due date for checked-out books
};

struct Transaction {
    string borrowerName;
    string bookTitle;
    time_t checkoutDate;
};

vector<Book> library;
vector<Transaction> transactions;

void addBook(const string& title, const string& author, const string& isbn) {
    Book newBook;
    newBook.title = title;
    newBook.author = author;
    newBook.isbn = isbn;
    newBook.available = true;
    library.push_back(newBook);
    cout << "Book added: " << title << endl;
}

void searchBooks(const string& keyword) {
    cout << "Search Results:" << endl;
    for (size_t i = 0; i < library.size(); ++i) {
        const Book& book = library[i];
        if (book.title.find(keyword) != string::npos || book.author.find(keyword) != string::npos || book.isbn.find(keyword) != string::npos) {
            cout << "Title: " << book.title << ", Author: " << book.author << ", ISBN: " << book.isbn << (book.available ? " (Available)" : " (Checked Out)") << endl;
        }
    }
}

void checkOutBook(const string& bookTitle, const string& borrowerName) {
    for (size_t i = 0; i < library.size(); ++i) {
        Book& book = library[i];
        if (book.title == bookTitle && book.available) {
            book.available = false;
            time_t now = time(0);
            book.dueDate = now + 7 * 24 * 60 * 60; // Due in 7 days
            Transaction transaction;
            transaction.borrowerName = borrowerName;
            transaction.bookTitle = bookTitle;
            transaction.checkoutDate = now;
            transactions.push_back(transaction);
            cout << "Checked out: " << bookTitle << " to " << borrowerName << endl;
            return;
        }
    }
    cout << "Book not found or is already checked out." << endl;
}

void returnBook(const string& bookTitle) {
    for (size_t i = 0; i < library.size(); ++i) {
        Book& book = library[i];
        if (book.title == bookTitle && !book.available) {
            book.available = true;
            time_t now = time(0);
            double overdueDays = difftime(now, book.dueDate) / (24 * 60 * 60);
            if (overdueDays > 0) {
                double fine = overdueDays * 2; // $2 per day fine
                cout << "Returned: " << bookTitle << " (Overdue by " << overdueDays << " days, Fine: $" << fine << ")" << endl;
            } else {
                cout << "Returned: " << bookTitle << " (On time)" << endl;
            }
            return;
        }
    }
    cout << "Book not found or is already returned." << endl;
}

int main() {
	
	cout << "Library Management System by: Pratham Aggarwal\n" << endl;
	
    // Sample data
    addBook("Book 1", "Author A", "123456");
    addBook("Book 2", "Author B", "789012");

    int choice;
    string keyword, title, author, isbn, borrowerName;

    do {
        cout << "Options:" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Search Books" << endl;
        cout << "3. Check Out Book" << endl;
        cout << "4. Return Book" << endl;
        cout << "5. Quit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cin.ignore(); // Clear the newline character from the previous input
                cout << "Title: ";
                getline(cin, title);
                cout << "Author: ";
                getline(cin, author);
                cout << "ISBN: ";
                getline(cin, isbn);
                addBook(title, author, isbn);
                break;
            case 2:
                cin.ignore(); // Clear the newline character from the previous input
                cout << "Search (Keyword): ";
                getline(cin, keyword);
                searchBooks(keyword);
                break;
            case 3:
                cin.ignore();
                cout << "Book Title: ";
                getline(cin, title);
                cout << "Borrower Name: ";
                getline(cin, borrowerName);
                checkOutBook(title, borrowerName);
                break;
            case 4:
                cin.ignore();
                cout << "Book Title: ";
                getline(cin, title);
                returnBook(title);
                break;
            case 5:
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
