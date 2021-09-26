#include <stdio.h>
#include <stdlib.h>

struct twod
{   
    int x;
    int y;
    /* data */
};


int main(){
    
    struct twod element;
    struct twod *arr;
    int *count;
    
    arr=malloc(5*sizeof(element));
    count=malloc(5*sizeof(int));

    for(int i=0; i<5;i++){
        count[i]=i+1;
        element.x=i;
        element.y=i;
        arr[i]=element;
    }
    
    for(int i=0; i<5;i++){
        printf("%d. x=%d y=%d\n",i,arr[i].x,arr[i].y);
    }

return 0;
}