#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool oper(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

string postfixtoinfix(string postfix) {
    stack<string> st;

    for (char c : postfix) {
        if (isalnum(c)) {
            st.push(string(1, c));
        } 
        else if (oper(c)) {
            if (st.size() < 2) {
                cout << "Invalid postfix expression!" << endl;
                return "";
            }
            string operand2 = st.top(); st.pop();
            string operand1 = st.top(); st.pop();
            string infix = "(" + operand1 + c + operand2 + ")";
            st.push(infix);
        }
    }

    if (st.size() != 1) {
        cout << "Invalid exp." << endl;
        return "";
    }

    return st.top();
}

int main() {
    string postfix;
    cout << "Enter postfix expression: ";
    cin >> postfix;

    string infix = postfixToInfix(postfix);

    if (!infix.empty()) {
        cout << "The infix expression is: " << infix << endl;
    }

    return 0;
}
