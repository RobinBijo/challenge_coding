#include <stdio.h>
#include <ctype.h>
#include <string.h>
//Global Variable Declaration
void displayPostfix(char postfix[],int size){
    for (int i = 0;i<size;i++){
        printf("%c",postfix[i]);
    }
}
void displaystack(char postfix[],int size){
    for (int i = 0;i<size;i++){
        printf("%c",postfix[i]);
    }
}
int find_precedence(char k){
    char precedence[] = "-+*/^";
    int plen = strlen(precedence);
    for (int i =0;i<plen;i++){
        if (k==precedence[i]){
            return i;
        }
    }
}

int main() {
    int stop =-1;
    int ptop = -1;
    char infix[] = "(a+(b-c)*d)";
    
    int infix_size = strlen(infix);//Referenced from Google
    char postfix[100];
    char stack[100];
    
    //SCANNING EACH CHARACTER
    for (int i = 0;i<infix_size;i++){
        char c = infix[i];
        if (c == '('){
            //Direct push to Stack
            stop+=1;
            stack[stop] = c;
        }
        else if (isalpha(c)){
            //Direct push to output
            ptop +=1;
            postfix[ptop] = c;
            
        }
        else if (c==')'){
            //Pop out elements until '(' is reached
            int flag = 1;
            while (flag != 0){
                ptop+= 1;
                postfix[ptop] = stack[stop];
                stop-=1;
                if (stack[stop]=='('){
                    stop-=1;
                    flag = 0;
                }
                
            }
        }
        else{
            //Detected Operator
            /*if (stop == -1){
                //Stack Empty push to stack
                stop += 1;
                stack[stop] = c;
            }*/
            if (stack[stop] == '('){
                //Direct push to stack no precendence checks
                stop+= 1;
                stack[stop] = c;
            }
            else{
                //Precedence checks begin
                if (c== '^'){
                    //Highest Precedence no major
                    //IF stack top is not ^ then push 
                    if (stack[stop] != c){
                        stop += 1;
                        stack[stop] = c;
                    }
                    else{
                        //Stack top is also ^ remove one and add
                        ptop += 1;
                        postfix[ptop] = stack[stop];
                        stack[stop] = c;
                    }
                }
                else if(c=='/'){
                    //If stack top is either / or * or ^ pop and then add
                    if ((stack[stop] == '/') || (stack[stop] == '*')||(stack[stop] == '^')){
                            ptop += 1;
                            postfix[ptop] = stack[stop];
                            stack[stop] = c;

                    }
                    else{
                        stop += 1;
                        stack[stop] = c;
                    }
                }
                else if (c=='*'){
                    //If stack top is either / or * or ^ pop and then add
                    if ((stack[stop] == '/') || (stack[stop] == '*')||(stack[stop] == '^')){
                            ptop += 1;
                            postfix[ptop] = stack[stop];
                            stack[stop] = c;

                    }
                    else{
                        stop += 1;
                        stack[stop] = c;
                    } 
                }
                else if (c=='+'){
                    //If stack top contains /*^-+ pop and then add  
                    if ((stack[stop] == '/') || (stack[stop] == '*')||(stack[stop] == '^')||(stack[stop]=='-')||(stack[stop]=='+')){
                        int flag = 1;
                        while (flag){
                            ptop += 1;
                            postfix[ptop] = stack[stop];
                            stop -= 1;
                            if ((stack[stop] =='(') || (stop == -1)){
                                flag = 0;
                                break;
                            }
                        }
                    stop += 1;
                    stack[stop] = c;
                }
                else{
                    stop += 1;
                    stack[stop] = c;
                    }
                }
                else if (c=='-'){
                    if ((stack[stop] == '/') || (stack[stop] == '*')||(stack[stop] == '^')||(stack[stop]=='-')||(stack[stop]=='+')){
                        int flag = 1;
                        while (flag){
                            ptop += 1;
                            postfix[ptop] = stack[stop];
                            stack[stop] = c;
                            stop -=1;
                            if ((stack[stop] == '(') || (stop == -1) ){
                                flag = 0;
                                break;
                            }
                        }
                        stop += 1;
                        stack[stop] = c;

                    }
                    else{
                        stop += 1;
                        stack[stop] = c;
                    }

                }
            }
            
        }
        printf("----Iteration #%d----\n",i);
        printf("Current Scanned Operator: %c\n",c);
        printf("Stack Top: %d\nStack: ",stop);
        for (int k = 0;k<=stop;k++){
            printf("%c",stack[k]);
        }
        printf("\n");
        printf("Postfix Top: %d\nOutput: ",ptop);
        for (int j = 0;j<=ptop;j++){
            printf("%c",postfix[j]);
        }
        printf("\n");
    }
    if (stop != -1){
        //Stack is not empty throw all elements into output
        while (stop!=-1){
            ptop += 1;
            postfix[ptop] = stack[stop];
            stop -= 1;
        }

    }
    printf("\n FINAL RESULT: \n");
        printf("Postfix Top: %d\nOutput: ",ptop);
        for (int j = 0;j<=ptop;j++){
            printf("%c",postfix[j]);
        }
        printf("\n");
    return 0;
}
