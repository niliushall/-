#include "myhead.h"

void Print_all(void){
    FILE *fp;
    firearms *pHead, *p;

    fp = fopen("information.txt", "rt");
    if(fp == NULL){
        printf("打开文件出错， 按任意键继续...\n");
        getchar();
        getchar();
        exit(0);
    }

    system("clear");
    /*输出信息*/
    printf("%-15s %-12s %-18s %-15s %-15s %-15s %-15s %-15s\n\n", "name", "address", "designer", "power", "portability", "precision", "stability", "rate");
    pHead = read_from_file();  //读取文件信息
    p = pHead->next;
    while(p != NULL){
        printf("%-15s %-12s %-18s %-15d %-15d %-15d %-15d %-15d\n",  p->name, p->addr, p->designer, p->wei, p->bian, p->jing, p->wen, p->she);
        p = p->next;
    }

    fclose(fp);

    printf("\n\n\n文件内容已全部输出， 按任意键继续...\n");
    getchar();
    getchar();
}
