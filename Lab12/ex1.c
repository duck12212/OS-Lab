#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct process{
        char pagetext[2];
};
struct pagetable{
        int frame;
};
struct process a[8]={"ab","ef","cd","gh","xa","ta","ab","cg"};
struct process b[8]={"rx","yy","zz","ww","mr","mk","fn","zx"};
struct process phy[16]={"ee","","","ww","","","gg","","","ff","","","","","",""};
struct pagetable ap[8];
struct pagetable bp[8];
int nowfree[12]={4,7,8,5,1,2,11,12,10,13,14,15};
int pageout[4]={0,3,6,9};
int main(int argc, char *argv[]) {
        int i,c=0,o=0;
        int input;
        int pagen;
        while(o!=4){
        printf("Please input which page of which process in:");
        scanf("%d%d",&input,&pagen);
                if(input==1){
                        if(c>11){
                                ap[pagen].frame=pageout[o];
                                phy[pageout[o]].pagetext[0]=a[pagen].pagetext[0];
                                phy[pageout[o]].pagetext[1]=a[pagen].pagetext[1];
                                o++;
                        }else{
                                ap[pagen].frame=nowfree[c];
                                phy[nowfree[c]].pagetext[0]=a[pagen].pagetext[0];
                                phy[nowfree[c]].pagetext[1]=a[pagen].pagetext[1];
                                c++;
                        }
                }
                if(input==2){
                        if(c>11){
                                bp[pagen].frame=pageout[o];
                                phy[pageout[o]].pagetext[0]=b[pagen].pagetext[0];
                                phy[pageout[o]].pagetext[1]=b[pagen].pagetext[1];
                                o++;
                        }else{
                                bp[pagen].frame=nowfree[c];
                                phy[nowfree[c]].pagetext[0]=b[pagen].pagetext[0];
                                phy[nowfree[c]].pagetext[1]=b[pagen].pagetext[1];
                                c++;
                        }
                }
        }
 printf("Process a pagetable:\n");
        for(i=0;i<8;i++){
                printf("%d\t%d\n",i,ap[i].frame);
        }
        printf("Process b pagetable:\n");
        for(i=0;i<8;i++){
                printf("%d\t%d\n",i,bp[i].frame);
        }
        printf("Physical memory list:\n");
        for(i=0;i<16;i++){
                printf("%d\t%c%c\n",i,phy[i].pagetext[0],phy[i].pagetext[1]);
        }
        return 0;
}
                                                                                                                                                                                           66,1         底端
