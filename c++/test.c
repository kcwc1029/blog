// TODO: 
// �M����3�ؼҦ� A B C
// ���]��n�ӽL�l�A
// �Nn-1�ӽL�l�A�Q��C��buffer�A�NA�h��B
// �N1�ӽL�l��A�h��C
// �Nn-1�ӽL�l�A�Q��A��buffer�A�NB�h��C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void hanoi(int n, char src, char buffer, char dst){
    if(n==1){
        printf("from %c to %c\n", src, dst);
    }else{
        hanoi(n-1, src, dst, buffer);
        printf("from %c to %c\n", src, dst);
        hanoi(n-1, buffer, src, dst);
    }
}

int main(){
    int n=4;
    hanoi(n, 'A', 'B', 'C');
    return 0;
}
// ��X
// name is John
// grade is 4.000000
// birthDay day is 29

void printArray(int a[], int size) {
    for (int i = 0; i < size; i++) {
        printf("a[%d] = %d (Address: %p)\n", i, a[i], (void*)&a[i]);
    }
    printf("\n");
}
