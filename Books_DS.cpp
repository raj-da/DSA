#include <bits/stdc++.h>
using namespace std;

class MyList {
private:
    class Node {
    public:
        string title;
        string author;
        int edition;
        int year;
        bool status; // borrowed state availability
        Node* prev;
        Node* next;

        Node(string title, string author, int edition, int year)
            : title(title), author(author), edition(edition), year(year),
              status(false), prev(nullptr), next(nullptr) {}
    };

    Node* head;
    Node* tail;

public:
    MyList() : head(nullptr), tail(nullptr) {}

    // Forward traversal
    void forwardTraversal() {
        Node* current = head;
        if (!current) {
            cout << "The library is empty!" << endl;
            return;
        }

        cout << "-------------------------------------------------------------------\n";
        while (current) {
            cout << "Title: " << current->title << endl;
            cout << "Author: " << current->author << endl;
            cout << "Edition: " << current->edition << endl;
            cout << "Year: " << current->year << endl;
            current = current->next;
        }
        cout << "-------------------------------------------------------------------\n";
    }

    // Count elements in the list
    int findLength() {
        int count = 0;
        Node* current = head;
        while (current) {
            count++;
            current = current->next;
        }
        return count;
    }

    // Search by title
    bool findBookBytitle(const string& title) {
        Node* current = head;
        int position = 1;

        while (current) {
            if (current->title == title) {
                cout << "Book '" << title << "' found at position: " << position << endl;
                return true;
            }
            current = current->next;
            position++;
        }

        cout << "Book '" << title << "' not found in the library." << endl;
        return false;
    }

    // Search by author
    bool findBookByauthor(const string& author) {
        Node* current = head;
        int position = 1;

        while (current) {
            if (current->author == author) {
                cout << "Books by '" << author << "' found starting at position: " << position << endl;
                return true;
            }
            current = current->next;
            position++;
        }

        cout << "No books by '" << author << "' found in the library." << endl;
        return false;
    }

    // Search by year
    bool findBookByyear(int year) {
        Node* current = head;
        int position = 1;

        while (current) {
            if (current->year == year) {
                cout << "Book(s) from year " << year << " found starting at position: " << position << endl;
                return true;
            }
            current = current->next;
            position++;
        }

        cout << "No books from year " << year << " found in the library." << endl;
        return false;
    }

    // Insert a book in sorted order by title
    void insertBook(string title, string author, int edition, int year) {
        Node* new_node = new Node(title, author, edition, year);

        if (!head) {
            head = tail = new_node;
            return;
        }

        Node* current = head;
        while (current && current->title < title) {
            current = current->next;
        }

        if (!current) {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        } else if (current == head) {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        } else {
            Node* prev = current->prev;
            prev->next = new_node;
            new_node->prev = prev;
            new_node->next = current;
            current->prev = new_node;
        }
    }

    // Delete by position
    void deleteAtPos(int pos) {
        if (!head) {
            cout << "The library is empty!" << endl;
            return;
        }

        if (pos <= 0 || pos > findLength()) {
            cout << "Invalid position!" << endl;
            return;
        }

        Node* current = head;

        for (int i = 1; i < pos; i++) {
            current = current->next;
        }

        if (current == head) {
            head = head->next;
            if (head) head->prev = nullptr;
        } else if (current == tail) {
            tail = tail->prev;
            if (tail) tail->next = nullptr;
        } else {
            Node* prev = current->prev;
            Node* next = current->next;
            prev->next = next;
            next->prev = prev;
        }

        delete current;
        cout << "Deleted book at position " << pos << "." << endl;
    }

    // Delete by title
    void deleteByTitle(const string& title) {
        if (!head) {
            cout << "The library is empty!" << endl;
            return;
        }

        Node* current = head;
        while (current) {
            if (current->title == title) {
                if (current == head) {
                    head = head->next;
                    if (head) head->prev = nullptr;
                } else if (current == tail) {
                    tail = tail->prev;
                    if (tail) tail->next = nullptr;
                } else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                delete current;
                cout << "Book with title '" << title << "' deleted." << endl;
                return;
            }
            current = current->next;
        }

        cout << "Book with title '" << title << "' not found." << endl;
    }

    // Delete by author
    void deleteByAuthor(const string& author) {
        if (!head) {
            cout << "The library is empty!" << endl;
            return;
        }

        bool deleted = false;
        Node* current = head;

        while (current) {
            if (current->author == author) {
                Node* toDelete = current;
                if (current == head) {
                    head = head->next;
                    if(head) 
                        head->prev = nullptr;
                } else if (current == tail) {
                    tail = tail->prev;
                    if(tail) 
                        tail->next = nullptr;
                } else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                current = current->next;
                delete toDelete;
                deleted = true;
            } else {
                current = current->next;
            }
        }

        if (deleted) {
            cout << "All books by author '" << author << "' deleted." << endl;
        } else {
            cout << "No books by author '" << author << "' found." << endl;
        }
    }

    // Sort books by author
    void sortByAuthor() {
        if (!head || !head->next) return;

        for (Node* i = head; i->next; i = i->next) {
            for (Node* j = i->next; j; j = j->next) {
                if (i->author > j->author) {
                    swap(i->title, j->title);
                    swap(i->author, j->author);
                    swap(i->edition, j->edition);
                    swap(i->year, j->year);
                }
            }
        }

        cout << "Books sorted by author." << endl;
    }

    // Sort books by year
    void sortByYear() {
        if (!head || !head->next) return;

        for (Node* i = head; i->next; i = i->next) {
            for (Node* j = i->next; j; j = j->next) {
                if (i->year > j->year) {
                    swap(i->title, j->title);
                    swap(i->author, j->author);
                    swap(i->edition, j->edition);
                    swap(i->year, j->year);
                }
            }
        }

        cout << "Books sorted by year." << endl;
    }
};

int main() {
    MyList list;
    int choice;
    bool stop = false;

    do {
        cout << "\nLibrary Menu:\n";
        cout << "1. Forward traversal\n";
        cout << "2. Find book by title\n";
        cout << "3. Find book by author\n";
        cout << "4. Find book by year\n";
        cout << "5. Insert a book\n";
        cout << "6. Delete book at position\n";
        cout << "7. Delete book by title\n";
        cout << "8. Delete books by author\n";
        cout << "9. Sort books by author\n";
        cout << "10. Sort books by year\n";
        cout << "11. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                list.forwardTraversal();
                break;
            case 2: {
                string title;
                cin.ignore();
                cout << "Enter book title: ";
                getline(cin, title);
                list.findBookBytitle(title);
                break;
            }
            case 3: {
                string author;
                cin.ignore();
                cout << "Enter author name: ";
                getline(cin, author);
                list.findBookByauthor(author);
                break;
            }
            case 4: {
                int year;
                cout << "Enter year: ";
                cin >> year;
                list.findBookByyear(year);
                break;
            }
            case 5: {
                string title, author;
                int edition, year;
                cin.ignore();
                cout << "Enter book title: ";
                getline(cin, title);
                cout << "Enter author: ";
                getline(cin, author);
                cout << "Enter edition: ";
                cin >> edition;
                cout << "Enter year: ";
                cin >> year;
                list.insertBook(title, author, edition, year);
                break;
            }
            case 6: {
                int pos;
                cout << "Enter position to delete: ";
                cin >> pos;
                list.deleteAtPos(pos);
                break;
            }
            case 7: {
                string title;
                cin.ignore();
                cout << "Enter title to delete: ";
                getline(cin, title);
                list.deleteByTitle(title);
                break;
            }
            case 8: {
                string author;
                cin.ignore();
                cout << "Enter author to delete: ";
                getline(cin, author);
                list.deleteByAuthor(author);
                break;
            }
            case 9:
                list.sortByAuthor();
                break;
            case 10:
                list.sortByYear();
                break;
            case 11:
                stop = true;
                break;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
    } while (!stop);

    return 0;
}
