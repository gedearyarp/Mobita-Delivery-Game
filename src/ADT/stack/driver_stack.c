#include "stack.h"
#include <stdio.h>

int main(){
    Stack s;
    ElType val;
    CreateStack(&s);
    push(&s, 2);
    printf("%d\n", isFull(s));
    pop(&s, &val);
    printf("%d\n", isEmpty(s));
}