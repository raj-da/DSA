// Node based Doubly linked list implimentation
/*
operations:

*/

#include <bits/stdc++.h>
using namespace std;

class MyList{
    private:
        class Node {
            public:
                string title;
                string author;
                int edition;
                int year;
                bool status; // borrowed state availability
                Node *prev;
                Node *next;

            Node(string title, string author, int edition, int year){
                this->title = title;
                this->author = author;
                this->edition = edition;
                this->year = year;
                this->status = false;
                prev = next = nullptr;
            }
        };

        Node *head, *tail = nullptr;

    public:
        // For traversing from head to tail
        void forwardTraversal(){
            Node *start = this->head;

            if(start == nullptr){
                cout << "The library is Empty!" << endl;
                return;
            }

            cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
            while(start != nullptr){
                cout << "Title: " << start->title << endl;
                cout << "Author: " << start->author << endl;
                cout << "Edition: " << start->edition << endl;
                cout << "Year: " << start->year << endl;
                start = start->next;
            }
            cout << "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
            cout << endl;

        }

        // // For traversing from tail to head
        // void backwardTraversal(){
        //     Node *end = this->tail;

        //     if(end == nullptr){
        //         cout << "Empty linked list!" << endl;
        //         return;
        //     }
            
        //     while(end != nullptr){
        //         cout << end->data << " ";
        //         end = end->prev;
        //     }

        //     cout << endl;
        // }

        // counting the elment in the list
        int findLength(){
            int count(0);
            Node *start = this->head;
            while(start != nullptr){
                count++;
                start = start->next;
            }

            return count;
        }

        // searching an element in the list by title
        bool findBookBytitle(string title){
            int count(0);
            bool found = false;
            Node *start = this->head;
            
            // cheack if the linkedlist is empty before searching
            if(start == nullptr){
                cout << "The Library is Empty!";
                return false;
            }

            while(start != nullptr){
                count++;
                if(start->title == title){
                    cout << title << " found at position: " << count << endl;
                    return true;
                }

                start = start->next;
            }

            cout << title << " not found in the Library" << endl;
            return false;
        }


        // searching an element in the list by author
        bool findBookBytitle(string author){
            int count(0);
            bool found = false;
            Node *start = this->head;
            
            // cheack if the linkedlist is empty before searching
            if(start == nullptr){
                cout << "The Library is Empty!";
                return false;
            }

            while(start != nullptr){
                count++;
                if(start->author == author){
                    cout << author << " found at position: " << count << endl;
                    return true;
                }

                start = start->next;
            }

            cout << author << " is not an author to any book in the library" << endl;
            return false;
        }


         // searching an element in the list by year
        bool findBookBytitle(int year){
            int count(0);
            bool found = false;
            Node *start = this->head;
            
            // cheack if the linkedlist is empty before searching
            if(start == nullptr){
                cout << "The Library is Empty!";
                return false;
            }

            while(start != nullptr){
                count++;
                if(start->year == year){
                    cout << year << " found at position: " << count << endl;
                    return true;
                }

                start = start->next;
            }

            cout << " no book found in the Library with the year " << year << endl;
            return false;
        }

        // // insert value at the beggining
        // void insertAtBegining(int value){
        //     Node *new_node = new Node(value);

        //     // if the linked list is empty
        //     if(this->head == nullptr){
        //         this->head = this->tail = new_node;
        //         cout << "Enterd at the biggining" << endl;
        //         return;
        //     }

        //     new_node->next = head;
        //     head->prev = new_node;
        //     head = new_node;
        //     cout << "Enterd at the biggining" << endl;
        //     return;
        // }

        // // insert value at the end
        // void insertAtEnd(int value){
        //     Node *new_node = new Node(value);

        //     // if the linked list is empty
        //     if(tail == nullptr){
        //         head = tail = new_node;
        //         cout << "Enterd at the end" << endl;
        //         return;
        //     }

        //     tail->next = new_node;
        //     new_node->prev = tail;
        //     tail = new_node;
        // }

        // insert a value at position pos
        /* 
            to be improved later:
                1.choosing from which end to go to the position
                2.handling when pos is last + 1
        */
        void insertBook(string title, string author, int edition, int year){
            Node *new_node = new Node(title, author, edition, year);
            int length = this->findLength();

            if(length == 0){
                head = new_node;
                return;
            }

            Node *previous_node = this->head; //node before the pos
            while(previous_node->next != nullptr){
                int comparision = new_node->title.compare(previous_node->title);
                if(comparision == 0){
                    break;
                }else if(comparision == -1){
                    if(head = previous_node){
                        new_node->next = head;
                        head->prev = new_node;
                        head = new_node;
                        return;
                    }

                    previous_node = previous_node->prev;
                    break;
                }else{
                    previous_node = previous_node->next;
                    if(previous_node->next == nullptr){
                        previous_node->next = new_node;
                        new_node->prev = previous_node;
                        return;
                    }
                }
            }

            Node *temp = previous_node->next;
            previous_node->next = new_node;
            new_node->prev = previous_node;
            new_node->next = temp;
            temp->prev = new_node;
        }

        // delete the first element
        // void deleteFirst(){
        //     Node *temp = this->head; //for deleting the node

        //     // if there is no element
        //     if(head == nullptr){
        //         cout << "Error! The linked list is empty" << endl;
        //         return;
        //     }
        //     // if there is only one element
        //     if(head == tail){
        //         head = tail = nullptr;
        //         delete temp;
        //         cout << "Deleted First Element" << endl;
        //         return;
        //     }

        //     head = head->next;
        //     head->prev = nullptr;
        //     delete temp;
        //     cout << "Deleted First Element" << endl;
        // }

        // delete the last element
        // void deleteEnd(){
        //     Node *temp = this->tail; //for deleting the node

        //     // if there is no element
        //     if(tail == nullptr){
        //         cout << "Error! The linked list is empty" << endl;
        //         return;
        //     }
        //     // if there is only one element
        //     if(head == tail){
        //         head = tail = nullptr;
        //         delete temp;
        //         cout << "Deleted Last Element" << endl;
        //         return;
        //     }

        //     tail = tail->prev;
        //     tail->next = nullptr;
        //     delete temp;
        //     cout << "Deleted Last Element" << endl;
        // }

        // delete at position
        void deleteAtPos(int pos){
            Node *temp = head; //to holds the node to be deleted
            int length = this->findLength();

            if(length == 0){
                cout << "Empty Library!" << endl;
                return;
            }
            // if the list contains one element
            if(pos == 1 && length == 1){
                head = nullptr;
                delete temp;
                cout << "Deleted at position: "<< pos << endl;
                return;
            }else if(pos == 1){ 
                head = head->next;
                head->prev = nullptr;
                delete temp;
                cout << "Deleted at position: "<< pos << endl;
                return;
            }

            // deleting the last element
            if(pos == length){
                temp = tail;
                tail = tail->prev;
                tail->next = nullptr;
                delete temp;
                cout << "Deleted at position: "<< pos << endl;
                return;
            }

            for(int i = 1; i < pos; i++){
                temp = temp->next;
            }

            Node *right = temp->next;
            Node *left = temp->prev;
            right->prev = temp->prev;
            left->next = temp->next;
            delete temp;

            cout << "Deleted at position: "<< pos << endl;
        }

        // delete by title
        void deleteByTitle(string title){
            Node *temp = head; //to holds the node to be deleted
            int length = this->findLength();

            if(length == 0){
                cout << "Empty Library!" << endl;
                return;
            }
            // if the list contains one element
            // if(pos == 1 && length == 1){
            //     head = nullptr;
            //     delete temp;
            //     cout << "Deleted at position: "<< pos << endl;
            //     return;
            // }else if(pos == 1){ 
            //     head = head->next;
            //     head->prev = nullptr;
            //     delete temp;
            //     cout << "Deleted at position: "<< pos << endl;
            //     return;
            // }

            // // deleting the last element
            // if(pos == length){
            //     temp = tail;
            //     tail = tail->prev;
            //     tail->next = nullptr;
            //     delete temp;
            //     cout << "Deleted at position: "<< pos << endl;
            //     return;
            // }

            // for(int i = 1; i < pos; i++){
            //     temp = temp->next;
            // }

            while(temp->next != nullptr){
                if(temp->title == title && head == temp){ //book is the first element
                    head = head->next;
                    temp->next->prev = nullptr;
                    temp->next = nullptr;
                    delete temp;

                }else if(temp->title == title){
                    Node *right = temp->next;
                    Node *left = temp->prev;
                    right->prev = left;
                    left->next = right;
                    temp->next = temp->prev = nullptr;
                    delete temp;
                }

                temp = temp->next;
            }
            if(temp->title == title && head == temp){ // book is the only element
                    head = head->next;
                    temp->next->prev = nullptr;
                    temp->next = nullptr;
                    delete temp;
            }else if(temp->title == title) { // book is the last element
                    temp->prev->next = nullptr;
                    temp->prev = nullptr;
                    delete temp;
            }
        }

        // delete by author
        void deleteByAuthor(string author){
            Node *temp = head; //to holds the node to be deleted
            int length = this->findLength();

            if(length == 0){
                cout << "Empty Library!" << endl;
                return;
            }
            // if the list contains one element
            // if(pos == 1 && length == 1){
            //     head = nullptr;
            //     delete temp;
            //     cout << "Deleted at position: "<< pos << endl;
            //     return;
            // }else if(pos == 1){ 
            //     head = head->next;
            //     head->prev = nullptr;
            //     delete temp;
            //     cout << "Deleted at position: "<< pos << endl;
            //     return;
            // }

            // // deleting the last element
            // if(pos == length){
            //     temp = tail;
            //     tail = tail->prev;
            //     tail->next = nullptr;
            //     delete temp;
            //     cout << "Deleted at position: "<< pos << endl;
            //     return;
            // }

            // for(int i = 1; i < pos; i++){
            //     temp = temp->next;
            // }

            while(temp->next != nullptr){
                if(temp->author == author && head == temp){ //book is the first element
                    head = head->next;
                    temp->next->prev = nullptr;
                    temp->next = nullptr;
                    delete temp;

                }else if(temp->author == author){
                    Node *right = temp->next;
                    Node *left = temp->prev;
                    right->prev = left;
                    left->next = right;
                    temp->next = temp->prev = nullptr;
                    delete temp;
                }

                temp = temp->next;
            }
            if(temp->author == author && head == temp){ // book is the only element
                    head = head->next;
                    temp->next->prev = nullptr;
                    temp->next = nullptr;
                    delete temp;
            }else if(temp->author == author) { // book is the last element
                    temp->prev->next = nullptr;
                    temp->prev = nullptr;
                    delete temp;
            }
        }

        // delete by year
        void deleteAtPos(int year){
            Node *temp = head; //to holds the node to be deleted
            int length = this->findLength();

            if(length == 0){
                cout << "Empty Library!" << endl;
                return;
            }
            // if the list contains one element
            // if(pos == 1 && length == 1){
            //     head = nullptr;
            //     delete temp;
            //     cout << "Deleted at position: "<< pos << endl;
            //     return;
            // }else if(pos == 1){ 
            //     head = head->next;
            //     head->prev = nullptr;
            //     delete temp;
            //     cout << "Deleted at position: "<< pos << endl;
            //     return;
            // }

            // // deleting the last element
            // if(pos == length){
            //     temp = tail;
            //     tail = tail->prev;
            //     tail->next = nullptr;
            //     delete temp;
            //     cout << "Deleted at position: "<< pos << endl;
            //     return;
            // }

            // for(int i = 1; i < pos; i++){
            //     temp = temp->next;
            // }

            while(temp->next != nullptr){
                if(temp->year == year && head == temp){ //book is the first element
                    head = head->next;
                    temp->next->prev = nullptr;
                    temp->next = nullptr;
                    delete temp;

                }else if(temp->year == year){
                    Node *right = temp->next;
                    Node *left = temp->prev;
                    right->prev = left;
                    left->next = right;
                    temp->next = temp->prev = nullptr;
                    delete temp;
                }

                temp = temp->next;
            }
            if(temp->year == year && head == temp){ // book is the only element
                    head = head->next;
                    temp->next->prev = nullptr;
                    temp->next = nullptr;
                    delete temp;
            }else if(temp->year == year) { // book is the last element
                    temp->prev->next = nullptr;
                    temp->prev = nullptr;
                    delete temp;
            }
        }

        bool comps(Node a, Node b){
            return !(a.author.compare(b.author) == 1);
        }

        bool compi(Node a, Node b){
            return a.year > b.year;
        }

        void sortByAuthor(){
            vector<Node> books;
            Node* start = head;
            while(start != nullptr){
                books.push_back(*start);
                start = start->next;
            }

            sort(books.begin(), books.end(), comps);
            for(Node book: books){
                cout << "Title: " << book.title << endl;
                cout << "Author: " << book.author << endl;
                cout << "Edition: " << book.edition << endl;
                cout << "Year: " << book.year << endl;
            }
        }

        void sortByYear(){
            vector<Node> books;
            Node* start = head;
            while(start != nullptr){
                books.push_back(*start);
                start = start->next;
            }

            sort(books.begin(), books.end(), compi);
            for(Node book: books){
                cout << "Title: " << book.title << endl;
                cout << "Author: " << book.author << endl;
                cout << "Edition: " << book.edition << endl;
                cout << "Year: " << book.year << endl;
            }
        }
};

int main(){
    int choice;
    bool stop = false;
    MyList list = MyList();
    do{
        cout << "Enter your choice:\n";
        cout << "1.Insert at the beginning" << endl;
        cout << "2.Insert at the end" << endl;
        cout << "3.Insert at position" << endl;
        cout << "4.Delete at the beginning" << endl;
        cout << "5.Delete at the end" << endl;
        cout << "6.Delete at position" << endl;
        cout << "7.Forward traversal" << endl;
        cout << "8.Backward traversal" << endl;
        cout << "9.Find length" << endl;
        cout << "10.Search element" << endl;
        cout << "11.exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;
        
    }while (!stop);
    
}