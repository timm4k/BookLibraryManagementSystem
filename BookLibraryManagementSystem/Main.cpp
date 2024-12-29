#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <limits>
#include <string>
using namespace std;

struct Book {
    string title;
    string author;
    string publisher;
    string genre;

    void display() const {
        cout << "Title: " << title << "\n"
            << "Author: " << author << "\n"
            << "Publisher: " << publisher << "\n"
            << "Genre: " << genre << "\n\n";
    }
};

void displayBooks(const vector<Book>& books) {
    if (books.empty()) {
        cout << "No books to display o_0\n";
        return;
    }
    for (const auto& book : books) {
        book.display();
    }
}

void editBook(vector<Book>& books) {
    int index;
    cout << "Enter the index of the book to edit (0 to " << books.size() - 1 << "): ";
    while (!(cin >> index) || index < 0 || index >= books.size()) {
        cout << "Invalid index!(\n"
            << "Try again: " << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Editing book at index " << index << ":\n";

    cout << "Current data:\n";
    books[index].display();

    cout << "Enter new title (leave empty to keep current): ";
    cin.ignore();
    string newTitle;
    getline(cin, newTitle);
    if (!newTitle.empty()) {
        books[index].title = newTitle;
    }

    cout << "Enter new author (leave empty to keep current): ";
    string newAuthor;
    getline(cin, newAuthor);
    if (!newAuthor.empty()) {
        books[index].author = newAuthor;
    }

    cout << "Enter new publisher (leave empty to keep current): ";
    string newPublisher;
    getline(cin, newPublisher);
    if (!newPublisher.empty()) {
        books[index].publisher = newPublisher;
    }

    cout << "Enter new genre (leave empty to keep current): ";
    string newGenre;
    getline(cin, newGenre);
    if (!newGenre.empty()) {
        books[index].genre = newGenre;
    }

    cout << "Book updated successfully ^^\n";
}

void searchByAuthor(const vector<Book>& books) {
    string author;
    cout << "Enter the author to search for: ";
    cin.ignore();
    getline(cin, author);

    bool found = false;
    for (const auto& book : books) {
        if (book.author == author) {
            book.display();
            found = true;
        }
    }
    if (!found) {
        cout << "No books found by that author ;(\n";
    }
}

void searchByTitle(const vector<Book>& books) {
    string title;
    cout << "Enter the title to search for: ";
    cin.ignore();
    getline(cin, title);

    bool found = false;
    for (const auto& book : books) {
        if (book.title == title) {
            book.display();
            found = true;
        }
    }
    if (!found) {
        cout << "No books found with that title ;(\n";
    }
}

void sortByTitle(vector<Book>& books) {
    sort(books.begin(), books.end(), [](const Book& a, const Book& b) {
        return a.title < b.title;
        });
    cout << "Books sorted by title successfully ^^\n";
}

void sortByAuthor(vector<Book>& books) {
    sort(books.begin(), books.end(), [](const Book& a, const Book& b) {
        return a.author < b.author;
        });
    cout << "Books sorted by author successfully ^^\n";
}

void sortByPublisher(vector<Book>& books) {
    sort(books.begin(), books.end(), [](const Book& a, const Book& b) {
        return a.publisher < b.publisher;
        });
    cout << "Books sorted by publisher successfully ^^\n";
}

void saveBooksToFile(const vector<Book>& books, const string& filename) {
    ofstream file(filename);
    if (!file) {
        cerr << "Error opening file for writing o_0" << endl;
        return;
    }
    for (const auto& book : books) {
        file << book.title << '\n' << book.author << '\n' << book.publisher << '\n' << book.genre << '\n';
    }
    cout << "Books saved to " << filename << " successfully ^^\n";
}

void loadBooksFromFile(vector<Book>& books, const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file for reading o_0" << endl;
        return;
    }
    books.clear();
    Book book;
    while (getline(file, book.title) && getline(file, book.author) && getline(file, book.publisher) && getline(file, book.genre)) {
        books.push_back(book);
    }
    cout << "Books loaded from " << filename << " successfully ^^\n";
}

int main() {
    vector<Book> books = {
        {"Default Title", "Default Author", "Default Publisher", "Default Genre"},
        {"Book1", "Author1", "Publisher1", "Genre1"},
        {"Book2", "Author2", "Publisher2", "Genre2"},
        {"Book3", "Author3", "Publisher3", "Genre3"},
        {"Book4", "Author4", "Publisher4", "Genre4"},
        {"Book5", "Author5", "Publisher5", "Genre5"},
        {"Book6", "Author6", "Publisher6", "Genre6"},
        {"Book7", "Author7", "Publisher7", "Genre7"},
        {"Book8", "Author8", "Publisher8", "Genre8"},
        {"Book9", "Author9", "Publisher9", "Genre9"}
    };
    string filename = "library.txt";

    while (true) {
        cout << "Library Menu:\n"
            << "1. Display all books\n"
            << "2. Save books to file\n"
            << "3. Load books from file\n"
            << "4. Edit a book\n"
            << "5. Search by author\n"
            << "6. Search by title\n"
            << "7. Sort by title\n"
            << "8. Sort by author\n"
            << "9. Sort by publisher\n"
            << "10. Exit ;p\n"
            << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1:
            displayBooks(books);
            break;
        case 2:
            saveBooksToFile(books, filename);
            break;
        case 3:
            loadBooksFromFile(books, filename);
            break;
        case 4:
            editBook(books);
            break;
        case 5:
            searchByAuthor(books);
            break;
        case 6:
            searchByTitle(books);
            break;
        case 7:
            sortByTitle(books);
            break;
        case 8:
            sortByAuthor(books);
            break;
        case 9:
            sortByPublisher(books);
            break;
        case 10:
            cout << "Arigatou gozaimashita! Sayounara ;3\n";
            return 0;
        }
    }
}
