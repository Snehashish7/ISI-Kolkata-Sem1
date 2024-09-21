#include <stdio.h>
int main(){
    int r,c;
    scanf("%d", r);
    scanf("%d", c);
    int ma[r][c];
    for(int i=0; i<r; i++){
        for(int j = 0; j<c; j++){
            scanf("%d", &ma[i][j]);
        }
    }
    int r1,c1;
    scanf("%d", r1);
    scanf("%d", c1);
    int mb[r1][c1];
    for(int i=0; i<r1; i++){
        for(int j = 0; j<c1; j++){
            scanf("%d", &mb[i][j]);
        }
    }
    if(c != r1){
        printf("Hoba na");
        return 0;
    }
    
}