#include "List.h"
#include <iostream>
using namespace std;

void List::insert_at_head(int value) 
{
    Node* temp = new Node(value);
    if (head == NULL) 
    {
        head = temp;
        tail = temp;
    }
    else 
    {
        temp->setNext(head);
        head->setPrev(temp);
        head = temp;
    }
}

void List::insert_at_tail(int value) 
{
    Node* temp = new Node(value);
    if (head == NULL) 
    {
        head = temp;
        tail = temp;
    }
    else 
    {
        tail->setNext(temp);
        temp->setPrev(tail);
        tail = temp;
    }
}

void List::insert_at_target(int value, int target) 
{
    Node* temp = head;
    while (temp != NULL && temp->getData() != target) 
    {
        temp = temp->getNext();
    }

    if (temp != NULL) 
    {
        Node* newNode = new Node(value);
        newNode->setNext(temp->getNext());
        newNode->setPrev(temp);

        if (temp->getNext() != NULL) 
        {
            temp->getNext()->setPrev(newNode);
        }
        else 
        {
            tail = newNode;
        }

        temp->setNext(newNode);
    }
    else 
    {
        cout << "Target value not found!" << endl;
    }
}

void List::search_target(int target)
{
    Node* temp = head;
    while (temp != NULL)
    {
        if (temp->getData() == target) 
        {
            cout << "Found" << endl;
            return;
        }
        temp = temp->getNext();
    }
    cout << "Not Found" << endl;
}

void List::print() 
{
    Node* temp = head;
    while (temp != NULL) 
    {
        cout << temp->getData() << " ";
        temp = temp->getNext();
    }
    cout << endl;
}

void List::prev_print() 
{
    Node* temp = tail;
    while (temp != NULL) 
    {
        cout << temp->getData() << " ";
        temp = temp->getPrev();
    }
    cout << endl;
}

void List::remove(int target) 
{
    Node* temp = head;
    while (temp != NULL && temp->getData() != target) 
    {
        temp = temp->getNext();
    }

    if (temp == NULL) 
    {
        cout << "Value not found!" << endl;
        return;
    }

    if (temp == head) 
    {
        head = temp->getNext();
        if (head != NULL) 
        {
            head->setPrev(NULL);
        }
        else 
        {
            tail = NULL; 
        }
    }
    else if (temp == tail) 
    {
        tail = temp->getPrev();
        if (tail != NULL) 
        {
            tail->setNext(NULL);
        }
        else 
        {
            head = NULL;
        }
    }
    else 
    {
        temp->getPrev()->setNext(temp->getNext());
        temp->getNext()->setPrev(temp->getPrev());
    }

    delete temp;
}
