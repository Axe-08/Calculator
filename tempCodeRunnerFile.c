#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <string.h>
#define size 50

typedef struct stack_usingArrays_int
{
    long long int arr[size];
    int top;

} Stick;

void push_int(Stick *s, int val)
{
    if (s->top < size - 1) // Check if there's space in the stack
    {
        (s->top)++;
        s->arr[s->top] = val;
        // Indicate successful push
    }
    else
    {
        printf("Stack Overflow\n");
        // Indicate unsuccessful push
    }
}

int pop_int(Stick *s)
{
    if (s->top > -1)
        return s->arr[(s->top)--];
    else
    {
        printf("Stack Underflow\n");
    }
}

typedef struct stack_usingArrays
{
    char arr[size];
    int top;

} Stack;

void push(Stack *s, char val)
{
    if (s->top < size - 1) // Check if there's space in the stack
    {
        (s->top)++;
        s->arr[s->top] = val;
        // Indicate successful push
    }
    else
    {
        printf("Stack Overflow\n");
        // Indicate unsuccessful push
    }
}

char pop(Stack *s)
{
    if (s->top > -1)
        return s->arr[(s->top)--];
    else
    {
        printf("Stack Underflow\n");
    }
}

bool isNum(char c)
{
    if (c >= '0' && c <= '9')
        return true;
    else
        return false;
}

bool isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '~')
        return true;
    else
        return false;
}

char peep(Stack *s)
{
    // add error condition here
    return s->arr[s->top];
}

bool isEmpty(Stack *s)
{
    if (s->top == -1)
    {
        return true;
    }
    else
        return false;
}

void pseudoLine(char *line, char *newline)
{
    int i = 0;
    int j = 0;
    while (line[i] != '\0')
    {
        if (isNum(line[i]))
        {
            newline[j] = line[i];
            j++;
            if (isNum(line[i + 1]))
            {
                newline[j] = '~';
                j++;
            }
        }
        else if (isOperator(line[i]))
        {
            newline[j] = line[i];
            j++;
        }
        i++;
    }
}

int digit(int i)
{
    int count = 0;
    while (i / 10 > 0)
    {
        i = i / 10;
        count++;
    }
    return count;
}

int prec(char c)
{
    switch (c)
    {
    case '~':
        return 5;
        break;
    case '*':
        return 4;
        break;
    case '/':
        return 4;
        break;
    case '%':
        return 4;
        break;
    case '+':
        return 3;
        break;
    case '-':
        return 3;
        break;
    case '#':
        return 2;
        break;
    default:
        return 0;
        break;
    }
}

char *convert(char *xline)
{
    char line[100];
    char infix[101];
    pseudoLine(xline, line);
    int i = 0;
    Stack s1;
    Stack *m;
    m->top = -1;
    s1.top = -1;
    push(&s1, '#');
    while (line[i] != '\0')
    {
        if (isNum(line[i]))
        {
            push(m, line[i]);
        }
        else if (isOperator(line[i]))
        {
            if (prec(line[i]) > prec(peep(&s1)))
            {
                push(&s1, line[i]);
            }
            else
            {
                while (prec(line[i]) <= prec(peep(&s1)))
                {
                    push(m, pop(&s1));
                }
                push(&s1, line[i]);
            }
        }
        else
        {
            printf("ERROR: Invalid Input\n");
            return;
        }
        i++;
    }
    while (!isEmpty(&s1))
    {
        push(m, pop(&s1));
    }
    strcpy(infix, m->arr);
    return infix;
}

long long int evaluate(char *postfix)
{
    int op1, op2, op3;
    char op;
    Stick x;
    x.top = -1;
    op = *postfix;
    while (op != '#')
    {
        if (isNum(op))
        {
            int v;
            v = (int)(op - '0');
            push_int(&x, v);
        }
        else
        {
            op1 = pop(&x);
            op2 = pop(&x);
            switch (op)
            {
            case '~':
                op3 = (op2 * pow(10, digit(op1) + 1)) + op1;
                break;
            case '*':
                op3 = op1 * op2;
                break;
            case '/':
                op3 = op2 / op1;
                break;
            case '%':
                op3 = op2 % op1;
                break;
            case '+':
                op3 = op1 + op2;
                break;
            case '-':
                op3 = op2 - op1;
                break;

            default:
                break;
            }
            push(&x, op3);
        }
    }
    return pop(&x);
}

int main()
{
    char line[20];
    scanf("%s", line);
    Stack i;
    int j = 0;
    char postfix[101] = convert(line);
    printf("\n%lld",evaluate(postfix));
}

// inline calculator