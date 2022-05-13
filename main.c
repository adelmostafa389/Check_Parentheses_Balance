#include <stdio.h>
#include <stdlib.h>

#include "TYPES.H"

#define expressionLength 30

uint8_t stack_arr[10];
uint8_t user_expression[expressionLength];
uint8_t stack_top = -1;

void push(uint8_t u8_data);
uint8_t pull();
void printStack();

uint8_t* balancedParentheses(uint8_t* expression);

int main()
{
    uint8_t* check_result;
    printf("Please enter an expression: ");
    scanf("%s", user_expression);
    check_result = balancedParentheses(user_expression);
    printf("%s", check_result);

    return 0;
}

uint8_t* balancedParentheses(uint8_t* expression)
{
    uint8_t* ret_value;
    uint8_t counter = 0;
    for(counter = 0; counter < expressionLength; counter++)
    {
        /* Check if there is an open parenthes */
        if(expression[counter] == '{' || expression[counter] == '(')
        {
            push(expression[counter]);
            printf("pushed\n");
            printStack();
        }
        else if(expression[counter] == '}')
        {
            if(stack_arr[stack_top] == '{')
            {
                ret_value = "Balanced";
                pull();
                printf("pulled 1 \n");
                printStack();
            }
            else
            {
                ret_value = "Not Balanced";
                pull();
                printf("pulled 2 \n");
                printStack();
                break;
            }
        }
        else if(expression[counter] == ')')
        {
            if(stack_arr[stack_top] == '(')
            {
                ret_value = "Balanced";
                pull();
                printf("pulled 1 \n");
                printStack();
            }
            else
            {
                ret_value = "Not Balanced";
                pull();
                printf("pulled 2 \n");
                printStack();
                break;
            }
        }
        else; /* Nothing */
    }
    printStack();
    return ret_value;
}

void push(uint8_t u8_data)
{
    stack_top++;
    stack_arr[stack_top] = u8_data;
}

uint8_t pull()
{
    uint8_t ret_value = 0;
    ret_value = stack_arr[stack_top];
    stack_arr[stack_top] = ' ';
    stack_top--;
    return ret_value;
}

void printStack()
{
    uint8_t counter = 0;
    for(counter = 0; counter < 10; counter ++)
    {
        printf("%c\t", stack_arr[counter]);
    }
    printf("\n");
}

/* 5*8(6+2)+(53-8*(11+8)) */
/* (2*3+{(5/2+(4*3))}) */
