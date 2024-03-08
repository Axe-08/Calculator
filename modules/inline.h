// change calculation base to float to accomodate decimals (done)
// figure out modulus operation on float (done)
// idea: try mathmetical manipulation like conting most decimal places of them and use some shenegans(done)

// decimal handling fix it!!!(done)

// debug for long expressions

// fix extra handelling!!!
#ifndef INLINE_H
#define INLINE_H
#include <iostream>
#include <vector>
#include <cmath>
#include <stack>

using namespace std;

namespace custom
{

    struct Extra
    {
        int id = -1;
        int start = -1;
        int brac_start = -1;
        int brac_close = -1;
        float inside;
    };

}
string convert(const string &xline);

float evaluate(const string &postfix);

bool isNum(char c)
{
    return c >= '0' && c <= '9';
}

bool isOperator(char c)
{
    return c == '+' || c == '^' || c == '-' || c == '*' || c == '/' || c == '%' || c == '~' || c == '.';
}

bool isOpenBracket(char c)
{
    return c == '(' || c == '[' || c == '{';
}

bool isClosingBracket(char c)
{
    return c == ')' || c == ']' || c == '}';
}

int findMatchingClosingBracket(string line, int openBracketIndex)
{
    int level = 0; // initialize the nesting level to 0
    for (int i = openBracketIndex + 1; i <= line.size(); i++)
    {
        if (isOpenBracket(line[i]))
        {
            level++; // increment the nesting level for opening brackets
        }
        else if (isClosingBracket(line[i]))
        {
            level--; // decrement the nesting level for closing brackets
            if (level == 0)
            {
                return i; // return the index of the matching closing bracket
            }
        }
    }
    return -1; // return -1 if no matching closing bracket is found
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

string floatToString_mod(float float_num)
{
    stack<char> stringStack;
    string signValue = "";

    // if long number is negative store the negative sign to
    // the signValue variable
    if (float_num < 0)
    {
        signValue = "-";
        float_num = -float_num;
    }

    string float_to_string = to_string(float_num);

    // while number is greater than 0, get last digit from it
    // and convert it to character by adding '0' to it, and
    // push to the stack.

    // while stack is not empty pop the character one by one
    // and append to the resultant string.
    // return the resulatant string value by appending
    // singValue to it
    return signValue + float_to_string + "~";
}

custom::Extra *findExtra(string line)
{
    custom::Extra *extra = new custom::Extra;
    int pos;

    if (-1 < (pos = line.find("exp"))) {
        cout << "Found exp at position " << pos << endl;
        extra->id = 0;
        extra->start = pos;
        extra->brac_start = pos + 3;
    }
    else if (-1 < (pos = line.find("log"))) {
        cout << "Found log at position " << pos << endl;
        extra->id = 1;
        extra->start = pos;
        extra->brac_start = pos + 3;
    }
    else if (-1 < (pos = line.find("ln"))) {
        cout << "Found ln at position " << pos << endl;
        extra->id = 2;
        extra->start = pos;
        extra->brac_start = pos + 2;
    }
    else if (-1 < (pos = line.find("sin"))) {
        cout << "Found sin at position " << pos << endl;
        extra->id = 3;
        extra->start = pos;
        extra->brac_start = pos + 3;
    }
    else if (-1 < (pos = line.find("cos"))) {
        cout << "Found cos at position " << pos << endl;
        extra->id = 4;
        extra->start = pos;
        extra->brac_start = pos + 3;
    }
    else if (-1 < (pos = line.find("tan"))) {
        cout << "Found tan at position " << pos << endl;
        extra->id = 5;
        extra->start = pos;
        extra->brac_start = pos + 3;
    }
    else if (-1 < (pos = line.find("cosec"))) {
        cout << "Found cosec at position " << pos << endl;
        extra->id = 6;
        extra->start = pos;
        extra->brac_start = pos + 5;
    }
    else if (-1 < (pos = line.find("sec"))) {
        cout << "Found sec at position " << pos << endl;
        extra->id = 7;
        extra->start = pos;
        extra->brac_start = pos + 3;
    }
    else if (-1 < (pos = line.find("cot"))) {
        cout << "Found cot at position " << pos << endl;
        extra->id = 8;
        extra->start = pos;
        extra->brac_start = pos + 3;
    }
    else if (-1 < (pos = line.find("asin"))) {
        cout << "Found asin at position " << pos << endl;
        extra->id = 9;
        extra->start = pos;
        extra->brac_start = pos + 4;
    }
    else if (-1 < (pos = line.find("acos"))) {
        cout << "Found acos at position " << pos << endl;
        extra->id = 10;
        extra->start = pos;
        extra->brac_start = pos + 4;
    }
    else if (-1 < (pos = line.find("atan"))) {
        cout << "Found atan at position " << pos << endl;
        extra->id = 11;
        extra->start = pos;
        extra->brac_start = pos + 4;
    }
    else if (-1 < (pos = line.find("acosec"))) {
        cout << "Found acosec at position " << pos << endl;
        extra->id = 12;
        extra->start = pos;
        extra->brac_start = pos + 6;
    }
    else if (-1 < (pos = line.find("asec"))) {
        cout << "Found asec at position " << pos << endl;
        extra->id = 13;
        extra->start = pos;
        extra->brac_start = pos + 4;
    }
    else if (-1 < (pos = line.find("acot"))) {
        cout << "Found acot at position " << pos << endl;
        extra->id = 14;
        extra->start = pos;
        extra->brac_start = pos + 4;
    }
    else {
        cout << "No mathematical function found" << endl;
        extra->id = -1;
    }

    if (extra->id != -1) {
        if (line[extra->brac_start] != '(') {
            extra->id = -1;
        }
    }
    return extra;
}

float exSolve(custom::Extra *extra)
{
    switch (extra->id)
    {
    case 0: // exp
        return exp(extra->inside);
    case 1: // log
        return log10(extra->inside);
    case 2: // ln
        return log(extra->inside);
    case 3: // sin
        return sin(extra->inside);
    case 4: // cos
        return cos(extra->inside);
    case 5: // tan
        return tan(extra->inside);
    case 6: // cosec
        return 1 / sin(extra->inside);
    case 7: // sec
        return 1 / cos(extra->inside);
    case 8: // cot
        return cos(extra->inside) / sin(extra->inside);
    case 9: // asin
        return asin(extra->inside);
    case 10: // acos
        return acos(extra->inside);
    case 11: // atan
        return atan(extra->inside);
    case 12: // acosec
        return asin(1 / extra->inside);
    case 13: // asec
        return acos(1 / extra->inside);
    case 14: // acot
        return atan(1 / extra->inside);
    default:
        // Handle error case where the extra is not supported
        return nanf(NULL);
    }
}

float extraSolving(string line)
{
    custom::Extra *ex = findExtra(line);
    if (ex->id > -1)
    {
        cout << "found extra\n";
        ex->brac_close = findMatchingClosingBracket(line, ex->brac_start);
        if (ex->brac_close != -1 && ex->brac_start != -1)
            ex->inside = extraSolving(line.substr(ex->brac_start + 1, ex->brac_close - ex->brac_start - 1));
        float value = exSolve(ex);
        string val_string = floatToString_mod(value);
        line.replace(ex->start, ex->brac_close - ex->start + 1, val_string);
        return extraSolving(line);
    }
    else if (ex->id == -1)
    {
        cout << "no extra";
        return evaluate(convert(line));
    }
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
            if (i + 1 == line.size() || (!isNum(line[i + 1]) && line[i + 1] != '.'))
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
            string s2 = floatToString_mod(x);

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
        return 6;
    case '^':
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
        if (isNum(c) || c == '_' || c == '.')
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
            case '^':
                x.push(pow(op2, op1));
                break;
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
    cout << "Result: " << endl;
    cout << extraSolving(line) << endl;
    /* string postfix = convert(line);
     if (!postfix.empty())
     {
         cout << "Result:" << endl;
         cout << evaluate(postfix) << endl;
     }
     */
}

#endif