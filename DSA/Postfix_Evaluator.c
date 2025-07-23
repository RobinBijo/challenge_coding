#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
//Global Variable Declaration
int main() {
    int stop =-1;
    int ptop = -1;
    char postfix[] = "53+62/*35*+";
    
    int postfix_size = strlen(postfix);//Referenced from Google
    int output;
    int stack[postfix_size];
    
    //SCANNING EACH CHARACTER
    for (int i = 0;i<postfix_size;i++){
        char c = postfix[i];
        if (isdigit(c)){
            //C is a number attempt to convert into integer
            char number[1];
            number[0] = c;
            int num = atoi(number);
            //Once converted put into stack
            stop+=1;
            stack[stop] = num;
        }
        else if (c=='+'){
            //Addition Operator
            int op2 = stack[stop];
            stop-=1;
            int op1 = stack[stop];
            stack[stop] = op1+op2;
            
        }
        else if (c=='-'){
            //Subtraction Operator
            int op2 = stack[stop];
            stop-=1;
            int op1 = stack[stop];
            stack[stop] = op1-op2;
            
        }
        else if (c=='*'){
            //Multiplication Operator
            int op2 = stack[stop];
            stop-=1;
            int op1 = stack[stop];
            stack[stop] = op1*op2;
            
        }
        else if (c=='/'){
            //Division Operator
            int op2 = stack[stop];
            stop-=1;
            int op1 = stack[stop];
            stack[stop] = op1/op2;
            
        }
    }
    printf("%d",stack[stop]);
    return 0;
}
