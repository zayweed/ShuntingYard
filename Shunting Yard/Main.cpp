#include <bits/stdc++.h>

#include "Stack.h"
#include "Queue.h"
#include "BNode.h"

using namespace std;

void push(Stack* &head, char c);
void pop(Stack* &head);
char peek(Stack* head);
void enqueue(Queue* &head, Queue* &tail, char c);
void dequeue(Queue* &head, Queue* &tail);
void printQueue(Queue* head);


int main() {

    Stack* shead = NULL;
    Queue* qhead = NULL;
    Queue* tail = NULL;

    cout << "Welcome to the Shunting Yard Algorithm!" << endl;

    char input[100];
    cin.getline(input, 100);
    cout << input << endl;

    for (int i = 0; i < strlen(input); i++) {

        if (input[i] == '1' || input[i] == '2' || input[i] == '3' || input[i] == '4' || input[i] == '5' ||
            input[i] == '6' || input[i] == '7' || input[i] == '8' || input[i] == '9') {
            char a = input[i];
            enqueue(qhead, tail, a);
            printQueue(qhead);
        }

        if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i] == '^' || input[i] == '(') {
            
            char a = input[i];
            push(shead, a);
            cout << peek(shead) << endl;
            
        }

        if (input[i] == ')') {
            char a;
            while (shead->c != '(') {
                a = peek(shead);
                pop(shead);
                cout << a << endl;
                enqueue(qhead, tail, a);
            }
            pop(shead);
        }

    }

    while (shead != NULL) {
        char a;
        a = peek(shead);
        pop(shead);
        enqueue(qhead, tail, a);
    }

    printQueue(qhead);

}

void push(Stack* &head, char c) {
    Stack* temp = new Stack();
    temp->c = c;
    temp->next = head;
    head = temp;
}

void pop(Stack* &head) {
    if (head != NULL) {
        Stack* temp = head;
        head = temp->next;
        free(temp);
    }
}

char peek(Stack* head) {//Returns the charector at the top of the stack
    return head->c;
}

void enqueue(Queue* &head, Queue* &tail, char c) {
    Queue* temp = new Queue();
    temp->c = c;
    temp->next = NULL;

    if (head == NULL) {
        head = temp;
        tail = head;
    }
    else {
        tail->next = temp;
        tail = temp;
    }
}

void dequeue(Queue* &head, Queue* &tail) {
    if (head == NULL) {
        return;
    }
    else if (head == tail) {
        free(head);
        head = NULL;
        tail = NULL;
    }
    else {
        Queue* temp = head;
        head = head->next;
        free(temp);
    }
}

void printQueue(Queue* head) {//Prints out the queue
    while (head != NULL) {
        cout << head->c << " ";
        head = head->next;
    }
    cout << endl;
}