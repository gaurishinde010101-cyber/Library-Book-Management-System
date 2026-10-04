#include <iostream>
#include <string>
using namespace std;

struct Node
{
    int bookID;
    string bookName;
    Node* next;
};

Node* head = NULL;

// Insert a book
void insertBook()
{
    Node* newNode = new Node;

    cout << "Enter Book ID: ";
    cin >> newNode->bookID;

    cout << "Enter Book Name: ";
    cin.ignore();
    getline(cin, newNode->bookName);

    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node* temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    cout << "Book inserted successfully!\n";
}

// Delete a book
void deleteBook()
{
    int id;
    cout << "Enter Book ID to delete: ";
    cin >> id;

    Node* temp = head;
    Node* prev = NULL;

    while (temp != NULL && temp->bookID != id)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        cout << "Book not found!\n";
        return;
    }

    if (prev == NULL)
    {
        head = temp->next;
    }
    else
    {
        prev->next = temp->next;
    }

    delete temp;
    cout << "Book deleted successfully!\n";
}

// Search a book
void searchBook()
{
    int id;
    cout << "Enter Book ID to search: ";
    cin >> id;

    Node* temp = head;

    while (temp != NULL)
    {
        if (temp->bookID == id)
        {
            cout << "Book Found!\n";
            cout << "Book ID   : " << temp->bookID << endl;
            cout << "Book Name : " << temp->bookName << endl;
            return;
        }

        temp = temp->next;
    }

    cout << "Book not found!\n";
}

// Display all books
void displayBooks()
{
    if (head == NULL)
    {
        cout << "Library is empty!\n";
        return;
    }

    Node* temp = head;

    cout << "\n--- Library Books ---\n";

    while (temp != NULL)
    {
        cout << "Book ID   : " << temp->bookID << endl;
        cout << "Book Name : " << temp->bookName << endl;
        cout << "---------------------\n";

        temp = temp->next;
    }
}

int main()
{
    int choice;

    do
    {
        cout << "\n===== LIBRARY BOOK MANAGEMENT =====\n";
        cout << "1. Insert Book\n";
        cout << "2. Delete Book\n";
        cout << "3. Search Book\n";
        cout << "4. Display Books\n";
        cout << "5. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                insertBook();
                break;

            case 2:
                deleteBook();
                break;

            case 3:
                searchBook();
                break;

            case 4:
                displayBooks();
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