#include <stdio.h>
#include <string.h>

int main() {
    char com[30];
    int i=2,a=0;
    printf("\n enter comment:");
    gets(com);
    if(com[0]=='/') {
        if(com[1]=='/') printf("\n valid single-line comment.");
        else if(com[1]=='*') {
            for(i=2;i<=30;i++) {
                if(com[i]=='*'&&com[i+1]=='/') {
                    printf("\n valid comment");
                    a=1;
                    break;
                }
            }
            if(a==0) printf("\n not a comment");
        } else printf("\n not a comment");
    } else printf("\n not a comment");
    return 0;
}