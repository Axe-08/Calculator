// change calculation base to float to accomodate decimals (done)
// figure out modulus operation on float (done)
// idea: try mathmetical manipulation like conting most decimal places of them and use some shenegans(done)


//decimal handling fix it!!!(done)

//debug for long expressions

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
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '~' || c == '.';
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

string LongToString_mod(float long_num)
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


    string long_to_string = to_string(long_num);

    // while number is greater than 0, get last digit from it
    // and convert it to character by adding '0' to it, and
    // push to the stack.
    

    // while stack is not empty pop the character one by one
    // and append to the resultant string.
    // return the resulatant string value by appending
    // singValue to it
    return signValue + long_to_string + "~";

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
            if (i + 1 == line.size() || (!isNum(line[i + 1])&&line[i+1]!='.'))
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

float evaluate(const string &postfix);

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
            float x = evaluate(s1);
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
        if (isNum(c) || c == '_' ||c =='.')
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

float evaluate(const string &postfix)
{
    stack<float> x;
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
            x.push(-1 * stof(postfix.substr(i, v - i)));
            i = v;
        }
        else if (isNum(op))
        {
            int v = i;
            while (postfix[v] != '~')
            {
                v++;
            }
            x.push(stof(postfix.substr(i, v - i)));
            i = v;
        }
        else
        {
            float op1 = x.top();
            x.pop();
            float op2 = x.top();
            x.pop();
            switch (op)
            {
            case '*':
                x.push(op1 * op2);
                break;
            case '/':
                if (op1 != 0)
                    x.push(op2 / op1);
                else
                {
                    exit(EXIT_SUCCESS);
                }
                break;
            case '%':
                x.push(fmod(op2, op1));
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

void arith()
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
}
