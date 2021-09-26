#include <stdio.h>
//var1 is defined (and declared implicitly) globally
int var1;

//Here var is declared only. Notice var is never used so no problems arise.
extern int var2;

//error!!! declared but not defined anywhere
extern int var3;

void foo(){
    //int var3;
    //var3=3;
    printf("foo-Var3 = %d\n",var3);


}

int main(void){
    var1 = 10;

    int var3 = 30;
    printf("Var3 = %d\n",var3);
    foo();

    return 0;
}
