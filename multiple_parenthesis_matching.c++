#include <iostream>
#include <stack>
using namespace std;

void check_expression(char str[]) {
    stack<char> s;
    int i = 0;
    bool isValid = true; 

    while (str[i] != '\0') {
        if (str[i] != '(' && str[i] != '[' && str[i] != '{' &&
            str[i] != ')' && str[i] != ']' && str[i] != '}') {
            i++;
            continue;
        }

        if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
            s.push(str[i]);
        } else {
            if (s.empty()) { // Check for unmatched closing brackets
                isValid = false;
                break;
            }
            char top = s.top();
            if ((str[i] == ')' && top == '(') ||
                (str[i] == ']' && top == '[') ||
                (str[i] == '}' && top == '{')) {
                s.pop();
            } else {
                isValid = false; // Mismatched brackets
                break;
            }
        }
        i++;
    }

// Final Check
    if (isValid && s.empty()) {
        cout << "Valid Expression\n";
    } else {
        cout << "Invalid Expression\n";
    }
}

int main() {
    char exp_1[40] = "a * ((b + c) - {a - [b]})";        // Valid
    char exp_2[40] = "{[a + b] * (c - a)} / [b + c]";    // Valid
    char exp_3[40] = "(a + [b * {c - a}])";              // Valid
    char exp_4[40] = "({a})]";                          // Invalid
    char exp_5[40] = "[(a + b) - {b * (c + a)}]";        // Valid
    char exp_6[40] = "a * ((b + c) - {a - [b]}";        // Invalid
    char exp_7[40] = "{[a + b] * (c - a) / [b + c]}";   // Valid
    char exp_8[40] = "(a + [b * {c - a})";              // Invalid
    char exp_9[40] = "({a})";                            // Valid
    char exp_10[40] = "[a + b)";                         // Invalid         

    check_expression(exp_1);
    check_expression(exp_2);
    check_expression(exp_3);
    check_expression(exp_4);
    check_expression(exp_5);
    check_expression(exp_6);
    check_expression(exp_7);
    check_expression(exp_8);
    check_expression(exp_9);
    check_expression(exp_10);

    return 0;
}