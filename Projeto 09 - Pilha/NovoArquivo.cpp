#include <iostream>

using namespace std;

// Defini��o do n� da lista encadeada
struct Node {
    int data;
    Node* next;
};

// Classe para a pilha implementada como lista encadeada
class LinkedStack {
private:
    Node* top;

public:
    LinkedStack() {
        top = nullptr;
    }

    void push(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (isEmpty()) {
            cout << "A pilha est� vazia." << endl;
            return -1;
        }

        int value = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;

        return value;
    }

    bool isEmpty() {
        return (top == nullptr);
    }
};

// Classe para a pilha implementada como vetor
class ArrayStack {
private:
    static const int MAX_SIZE = 30;
    int arr[MAX_SIZE];
    int top;

public:
    ArrayStack() {
        top = -1;
    }

    void push(int value) {
        if (top >= MAX_SIZE - 1) {
            cout << "A pilha est� cheia." << endl;
            return;
        }

        arr[++top] = value;
    }

    int pop() {
        if (isEmpty()) {
            cout << "A pilha est� vazia." << endl;
            return -1;
        }

        return arr[top--];
    }

    bool isEmpty() {
        return (top == -1);
    }
};

int main() {
    LinkedStack evenStack; // Pilha para n�meros pares
    LinkedStack oddStack;  // Pilha para n�meros �mpares

    // Digitar e empilhar os n�meros
    cout << "Digite 30 n�meros inteiros em ordem crescente:" << endl;
    int previous = 0;
    for (int i = 0; i < 30; i++) {
        int num;
        cin >> num;

        if (num <= previous) {
            cout << "O n�mero digitado n�o � maior que o anterior. Tente novamente." << endl;
            i--;
            continue;
        }

        if (num % 2 == 0) {
            evenStack.push(num);
        } else {
            oddStack.push(num);
        }

        previous = num;
    }

    // Desempilhar e exibir os n�meros em ordem decrescente
    cout << "N�meros pares em ordem decrescente:" << endl;
    while (!evenStack.isEmpty()) {
        cout << evenStack.pop() << " ";
    }
    cout << endl;

    cout << "N�meros �mpares em ordem decrescente:" << endl;
    while (!oddStack.isEmpty()) {
        cout << oddStack.pop() << " ";
    }
    cout << endl;

    return 0;
}