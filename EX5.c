/**
@author Saheb Singh Arora
Student id 3742233
*/
#include <stdio.h>

int main() {
    int a = 0;
    int b =1;
    int c = 1;
    int num=0;

    printf("Every second value in the Tribonacci sequence are as follows:\n");
    printf("%d\n%d\n", a,b);

    for(int i = 0 ; i < 16 ; i++){
   num=a+b+c;
    a=b;
    
    b=c;
    c=num;
    
    if(i%2 == 0){
    printf("%d\n",num);
    	}
    
    }
}