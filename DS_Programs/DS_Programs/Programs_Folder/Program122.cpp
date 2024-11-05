// ENTER THE 2 POLYNOMIAL EQUATIONS DYNAMICALLY, ADD THEM AND DISPLAY THE ANSWER

#include <iostream>
using namespace std;

class Node {
public:
    int coefficient;
    int exponent;
    Node* next;

    Node(int coeff, int exp) {
        coefficient = coeff;
        exponent = exp;
        next = nullptr;
    }
};

class Polynomial {
private:
    Node* head;

public:
    Polynomial() {
        head = nullptr;
    }

    // Function to insert a term in the polynomial
    void insertTerm(int coefficient, int exponent) {
        Node* newNode = new Node(coefficient, exponent);
        if (head == nullptr || head->exponent < exponent) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr && current->next->exponent > exponent) {
                current = current->next;
            }
            if (current->exponent == exponent) {
                current->coefficient += coefficient;
                delete newNode;
            } else {
                newNode->next = current->next;
                current->next = newNode;
            }
        }
    }

    // Function to add two polynomials
    Polynomial add(Polynomial& poly) {
        Polynomial result;
        Node* p1 = head;
        Node* p2 = poly.head;

        while (p1 != nullptr && p2 != nullptr) {
            if (p1->exponent == p2->exponent) {
                result.insertTerm(p1->coefficient + p2->coefficient, p1->exponent);
                p1 = p1->next;
                p2 = p2->next;
            } else if (p1->exponent > p2->exponent) {
                result.insertTerm(p1->coefficient, p1->exponent);
                p1 = p1->next;
            } else {
                result.insertTerm(p2->coefficient, p2->exponent);
                p2 = p2->next;
            }
        }

        while (p1 != nullptr) {
            result.insertTerm(p1->coefficient, p1->exponent);
            p1 = p1->next;
        }

        while (p2 != nullptr) {
            result.insertTerm(p2->coefficient, p2->exponent);
            p2 = p2->next;
        }

        return result;
    }

    // Function to display the polynomial
    void display() {
        if (head == nullptr) {
            cout << "0" << endl;
            return;
        }

        Node* current = head;
        while (current != nullptr) {
            cout << current->coefficient << "x^" << current->exponent;
            current = current->next;
            if (current != nullptr) {
                cout << " + ";
            }
        }
        cout << endl;
    }
};

int main() {
    Polynomial poly1, poly2;

    int terms, coefficient, exponent;

    cout << "Enter the number of terms in the first polynomial: ";
    cin >> terms;
    for (int i = 0; i < terms; i++) {
        cout << "Enter coefficient and exponent: ";
        cin >> coefficient >> exponent;
        poly1.insertTerm(coefficient, exponent);
    }

    cout << "Enter the number of terms in the second polynomial: ";
    cin >> terms;
    for (int i = 0; i < terms; i++) {
        cout << "Enter coefficient and exponent: ";
        cin >> coefficient >> exponent;
        poly2.insertTerm(coefficient, exponent);
    }

    cout << "\nFirst Polynomial: ";
    poly1.display();

    cout << "Second Polynomial: ";
    poly2.display();

    Polynomial result = poly1.add(poly2);

    cout << "\nResult of Addition: ";
    result.display();

    return 0;
}
