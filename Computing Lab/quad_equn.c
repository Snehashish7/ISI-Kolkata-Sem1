#include <stdio.h>
#include <math.h>
int main(){
    
    float a,b,c;
    scanf("%f",&a);
    scanf("%f",&b);
    scanf("%f",&c);
    float root1,root2;
    float det = b*b -4*a*c;
    if((det) >= 0 && a > 0){
        root1 = (sqrt((det)) - b)/(2*a);
        root2 = (-sqrt((det)) - b)/(2*a);
        printf("%f\n", root1);
        printf("%f", root2);
    }
    else if((det) < 0 && a > 0){
        printf("%f + %fi \n", b/2,det/2);
        printf("%f %fi", b/2,det/2);
    }
    return 0;
}