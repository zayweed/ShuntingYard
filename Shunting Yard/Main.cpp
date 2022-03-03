/*
Zayeed Saffat
3/2/2022
This project uses stacks and queues to convert infix equations to postfix using the Shunting-yard algorithm, and then utilizes a binary tree to recursively translate the postfix equation into prefix, postfix, and infix form.
*/

#include <bits/stdc++.h>

#include "Stack.h"
#include "Queue.h"
#include "BNode.h"

using namespace std;

//function prototypes
void push(Stack* &head, char c);
void pop(Stack* &head);
char peek(Stack* head);
void enqueue(Queue* &head, Queue* &tail, char c);
void dequeue(Queue* &head, Queue* &tail);
void fillEnqueue(Stack* &shead, Queue* &qhead, Queue* &tail);
void printQueue(Queue* head);

int main() {

    Stack* shead = NULL;
    Queue* qhead = NULL;
    Queue* tail = NULL;

    cout << "Welcome to the Shunting Yard Algorithm!" << endl;

    char input[100];
    cin.getline(input, 100);
    //cout << input << endl;

    for (int i = 0; i < strlen(input); i++) {

        if (input[i] == '1' || input[i] == '2' || input[i] == '3' || input[i] == '4' || input[i] == '5' ||
            input[i] == '6' || input[i] == '7' || input[i] == '8' || input[i] == '9') { // if operation is a number, enqueues into queue
            char a = input[i];
            enqueue(qhead, tail, a);
            //printQueue(qhead);
        }

        if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i] == '^' || input[i] == '(') { //if operation is a math symbol or left parenthesis, pushes into stack
            
            char a = input[i];
            push(shead, a);
            //cout << peek(shead) << endl;
            
        }

        if (input[i] == ')') { //if operation is a right parenthesis,
            char a;
            while (shead->c != '(') { //adds all operations in the stack into the queue and removes the left parenthesis
                a = peek(shead);
                pop(shead);
                //cout << a << endl;
                enqueue(qhead, tail, a);
            }
            pop(shead);
        }

    }

    fillEnqueue(shead, qhead, tail); //adds all the remaining operations in the stack to the queue

    printQueue(qhead); //prints queue(postfix form)

}

void push(Stack* &head, char c) { //addes node to the stack that become the new head
    Stack* temp = new Stack();
    temp->c = c;
    temp->next = head;
    head = temp;
}

void pop(Stack* &head) { //removes the head node of the stack
    if (head != NULL) {
        Stack* temp = head;
        head = temp->next;
        free(temp);
    }
}

char peek(Stack* head) { //returns the character value of the head node
    return head->c;
}

void enqueue(Queue* &head, Queue* &tail, char c) { //adds node to the end of the queue
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

void dequeue(Queue* &head, Queue* &tail) { //removes node from the front of the queue
    if (head == NULL) {

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

void fillEnqueue(Stack* &shead, Queue* &qhead, Queue* &tail) { //fills queue with all remaining nodes in the stack in order
    while (shead != NULL) {
        char a = peek(shead);
        pop(shead);
        enqueue(qhead, tail, a);
    }
}

void printQueue(Queue* head) { //prints the operations in the queue seperated by spaces
    while (head != NULL) {
        cout << head->c << " ";
        head = head->next;
    }
    cout << endl;
}