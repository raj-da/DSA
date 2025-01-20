#include <iostream>
using namespace std;

class UserQueue {
    private:
        class UserNode {
            public:
                string name;
                string bookTitle;
                time_t dueDate;
                UserNode *next;

                UserNode(string name, string bookTitle, time_t dueDate):
                    name(name), bookTitle(bookTitle), dueDate(dueDate), next(nullptr) {}
        };

        UserNode *head = nullptr;
        UserNode *tail = nullptr;

    public:

        // Add a user to the queue
        void enqueue(string name, string bookTitle, time_t dueDate){
            UserNode *newUser = new UserNode(name, bookTitle, dueDate);
            if(!tail)
                head = tail = newUser;
            else{
                tail->next = newUser;
                tail = newUser;
            }
            cout << "User \"" << name << "\" added to the queue for book \"" << bookTitle << "\".\n";
        }

        // Remove a user from the queue
        void dequeue() {
            if(!head){
                cout << "The queue is empty." << endl;
                return;
            }

            UserNode *temp = head;
            head = head->next;
            if(!head)
                tail = nullptr;

            cout << "User \"" << temp->name << "\" removed from the queue for book \"" << temp->bookTitle << "\".\n";
            delete temp;
        }

        // get next user in the queue
        UserNode* peek(){
            return head;
        }

        // display the queue
        void displayQueue() {
            if(!head) {
                cout << "The queue is empty." << endl;
                return;
            }

            UserNode *current = head;
            cout << "Queue:\n";
            while(current){
                cout << "Name: " << current->name << ", Book: " << current->bookTitle
                << ", Due Date: " << ctime(&current->dueDate);
                current = current->next;
            }
        }
};