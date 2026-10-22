#include <iostream>
#include <string>
using namespace std;

class BigNumber {
    struct Node {
        int digit;
        Node* next;

        Node(int d) {
            digit = d;
            next = NULL;
        }
    };

    Node* head;
    bool negative;

public:
    BigNumber(string s) {
        head = NULL;
        negative = false;

        if (s[0] == '-') {
            negative = true;
            s = s.substr(1);
        }

        // Store digits in reverse order
        for (int i = s.size() - 1; i >= 0; i--) {
            Node* temp = new Node(s[i] - '0');
            temp->next = head;
            head = temp;
        }
    }

    BigNumber add(BigNumber b) {
        Node* p = head;
        Node* q = b.head;

        BigNumber result("0");
        result.head = NULL;

        int carry = 0;

        // Addition
        while (p || q || carry) {
            int sum = carry;

            if (p) {
                sum += p->digit;
                p = p->next;
            }

            if (q) {
                sum += q->digit;
                q = q->next;
            }

            Node* temp = new Node(sum % 10);
            temp->next = result.head;
            result.head = temp;

            carry = sum / 10;
        }

        return result;
    }

    void print() {
        Node* temp = head;

        if (negative)
            cout << "-";

        while (temp) {
            cout << temp->digit;
            temp = temp->next;
        }

        cout << endl;
    }
};

int main() {

    BigNumber a("999999999999999999");
    BigNumber b("123456789");

    BigNumber c = a.add(b);

    cout << "Answer = ";
    c.print();

    return 0;
}