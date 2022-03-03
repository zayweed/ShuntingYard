/*
Zayeed Saffat
3/2/2022
This project uses stacks and queues to convert infix equations to postfix using the Shunting-yard algorithm, and then utilizes a binary tree to recursively translate the postfix equation into prefix, postfix, and infix form.
Credits to Nihal Parthasarathy for helping me with the Shunting-yard algorithm.
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
void operatorTree(Stack* &shead2, BNode* &thead, char c);
void infix(BNode* thead);
void postfix(BNode* thead);
void prefix(BNode* thead);

int main() {

    Stack* shead = NULL;
    Queue* qhead = NULL;
    Queue* tail = NULL;

    cout << "Welcome to the Shunting-yard algorithm!" << endl;
    cout << "Enter your equation:" << endl;

    char input[100];
    cin.getline(input, 100);
    //cout << input << endl;

    //Shunting-yard algorithm
    for (int i = 0; i < strlen(input); i++) {

        if (isdigit(input[i])) { // if operation is a number, enqueues into queue
            char a = input[i];
            enqueue(qhead, tail, a);
        }

        if (input[i] == '+' || input[i] == '-' || input[i] == '*' || input[i] == '/' || input[i] == '^' || input[i] == '(') { //if operation is a math symbol or left parenthesis, pushes into stack
            
            char a = input[i];
            push(shead, a);
            
        }

        if (input[i] == ')') { //if operation is a right parenthesis,
            char a;
            while (shead->c != '(') { //adds all operations in the stack into the queue and removes the left parenthesis
                a = peek(shead);
                pop(shead);
                enqueue(qhead, tail, a);
            }
            pop(shead);
        }

    }

    fillEnqueue(shead, qhead, tail); //adds all the remaining operations in the stack to the queue

    printQueue(qhead); //prints queue(postfix form)

    //making the binary expression tree
    Stack* shead2 = NULL;
    BNode* thead = NULL;
    
    while (qhead != NULL) {
        char a = qhead->c;

        if (isdigit(a)) {
            push(shead2, a);
        }

        else {
            operatorTree(shead2, thead, a);
            push(shead2, a);
        }

        qhead = qhead->next;
    }

    cout << "Infix(w/tree):" << endl;
    infix(thead);
    cout << endl;

    cout << "Postfix(w/tree):" << endl;
    postfix(thead);
    cout << endl;

    cout << "Prefix(w/tree):" << endl;
    prefix(thead);
    cout << endl;

}

void push(Stack* &head, char c) { //adds node to the stack that become the new head
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
    if (head == tail) {
        free(head);
        head = NULL;
        tail = NULL;
    }
    else if (head != NULL) {
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
    cout << "Postfix:" << endl;
    while (head != NULL) {
        cout << head->c << " ";
        head = head->next;
    }
    cout << endl;
}

void operatorTree(Stack* &shead2, BNode* &thead, char c) {
    BNode* node = new BNode(c);

    if (thead == NULL) {
        char a = peek(shead2);
        char b = peek(shead2->next);
        BNode* right = new BNode(a);
        BNode* left = new BNode(b);
        node->setRight(right);
        node->setLeft(left);
        pop(shead2);
        pop(shead2);
        thead = node;
    }

    else {
        char a = thead->getChar();
        char b = peek(shead2);
        BNode* right = new BNode(b);
        node->setRight(right);
        node->setLeft(thead);
        pop(shead2);
        thead = node;
    }
}

void infix(BNode* thead){
    if (thead->getLeft() != NULL){
        infix(thead->getLeft());
    }

    cout << thead->getChar() << " ";

    if (thead->getRight() != NULL){
        infix(thead->getRight());
    }
}

void postfix(BNode* thead){
    if (thead->getLeft() != NULL) {
        postfix(thead->getLeft());
    }

    if (thead->getRight() != NULL) {
        postfix(thead->getRight());   
    }

    cout << thead->getChar() << " ";
}

void prefix(BNode* thead){
    cout << thead->getChar() << " ";

    if (thead->getLeft() != NULL) {
        prefix(thead->getLeft());
    }
    
    if (thead->getRight() != NULL) {
        prefix(thead->getRight());
    }
}