#include <iostream>
#include <vector>
#include <cmath>
#include <stack>

using namespace std;

bool isNum(char c)
{
    return c >= '0' && c <= '9';
}

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '~';
}

bool isOpenBracket(char c)
{
    return c == '(' || c == '[' || c == '{';
}

bool isClosingBracket(char c)
{
    return c == ')' || c == ']' || c == '}';
}

int isValidBracketPlacement(const string &line)
{
    int open = 0, close = 0;
    for (char c : line)
    {
        if (isOpenBracket(c))
            open++;
        if (isClosingBracket(c))
            close++;
    }
    if (open == close)
        return open;
    else
        return -1;
}

string LongToString_mod(long long_num)
{
    stack<char> stringStack;
    string signValue = "";

    // if long number is negative store the negative sign to
    // the signValue variable
    if (long_num < 0)
    {
        signValue = "-";
        long_num = -long_num;
    }

    // while number is greater than 0, get last digit from it
    // and convert it to character by adding '0' to it, and
    // push to the stack.
    while (long_num > 0)
    {
        char convertedDigit = long_num % 10 + '0';
        stringStack.push(convertedDigit);
        long_num /= 10;
    }

    string long_to_string = "";

    // while stack is not empty pop the character one by one
    // and append to the resultant string.
    while (!stringStack.empty())
    {
        long_to_string += stringStack.top();
        stringStack.pop();
    }

    // return the resulatant string value by appending
    // singValue to it
    return signValue + long_to_string;
}

void pseudoLine(const string &line, string &newline)
{
    for (size_t i = 0; i < line.size(); ++i)
    {
        if (line[i] == '-')
        {
            if (i == 0 || isOperator(line[i - 1]) || isOpenBracket(line[i - 1]))
            {
                // If '-' is at the beginning of the expression or after an operator or an opening bracket,
                // mark it as negation by adding '_' to the output
                newline.push_back('_');
            }
            else
            {
                // Otherwise, treat it as a regular minus sign
                newline.push_back(line[i]);
            }
        }
        else if (isNum(line[i]))
        {
            newline.push_back(line[i]);
            // Add '~' to represent the end of a number if the next character is not a digit
            if (i + 1 == line.size() || !isNum(line[i + 1]))
            {
                newline.push_back('~');
            }
        }
        else if (isOperator(line[i]))
        {
            newline.push_back(line[i]);
        }
    }
}

long long int evaluate(const string &postfix);

void bracketSolver(string &brackline)
{
    if (isValidBracketPlacement(brackline) != -1)
    {
        while (isValidBracketPlacement(brackline) != 0)
        {
            int end_brack = brackline.find_first_of(")]}");
            int start_brack = brackline.find_last_of("([}", end_brack);

            if (start_brack == string::npos || end_brack == string::npos)
            {
                cout << "ERROR: Invalid Bracket Placement!" << endl;
                return;
            }

            string s1 = brackline.substr(start_brack, end_brack - start_brack + 1);
            long long int x = evaluate(s1);
            string s2 = LongToString_mod(x);

            string s3;
            pseudoLine(s2, s3);
            brackline.replace(start_brack, end_brack - start_brack + 1, s3);
        }
    }
    else
    {
        cout << "Invalid Bracket Placement!\n";
    }
}

int precedence(char c)
{
    switch (c)
    {
    case '~':
        return 5;
    case '*':
    case '/':
    case '%':
        return 4;
    case '+':
    case '-':
        return 3;
    case '#':
        return 2;
    default:
        return 0;
    }
}

string convert(const string &xline)
{
    string line, postfix;
    pseudoLine(xline, line);

    if (isValidBracketPlacement(line) == -1)
    {
        cout << "Invalid bracket placement" << endl;
        exit(0);
    }

    bracketSolver(line);

    stack<char> s1;
    s1.push('#');
    int i = 0;
    while (line[i] != '\0')
    {
        char c = line[i];
        if (isNum(c) || c == '_')
        {
            postfix.push_back(c);
        }
        else if (isOperator(c))
        {

            while (precedence(c) <= precedence(s1.top()))
            {
                postfix.push_back(s1.top());
                s1.pop();
            }
            s1.push(c);
        }
        else
        {
            cout << "ERROR: Invalid Input" << endl;
            return "";
        }
        i++;
    }

    while (s1.top() != '#')
    {
        postfix.push_back(s1.top());
        s1.pop();
    }
    return postfix;
}

long long int evaluate(const string &postfix)
{
    stack<long long int> x;
    int i = 0;
    while (postfix[i] != '\0')
    {
        char op = postfix[i];
        if (op == '_')
        {
            i++;
            int v = i;
            while (postfix[v] != '~')
            {
                v++;
            }
            x.push(-1 * stoi(postfix.substr(i, v - i)));
            i = v;
        }
        else if (isNum(op))
        {
            int v = i;
            while (postfix[v] != '~')
            {
                v++;
            }
            x.push(stoi(postfix.substr(i, v - i)));
            i = v;
        }
        else
        {
            long long int op1 = x.top();
            x.pop();
            long long int op2 = x.top();
            x.pop();
            switch (op)
            {
            case '*':
                x.push(op1 * op2);
                break;
            case '/':
                x.push(op2 / op1);
                break;
            case '%':
                x.push(op2 % op1);
                break;
            case '+':
                x.push(op1 + op2);
                break;
            case '-':
                x.push(op2 - op1);
                break;
            default:
                break;
            }
        }
        i++;
    }
    return x.top();
}

int main()
{
    string line;
    cout << "Enter Expression" << endl;
    cin >> line;
    string postfix = convert(line);
    if (!postfix.empty())
    {
        cout << "Result:" << endl;
        cout << evaluate(postfix) << endl;
    }
    return 0;
}
