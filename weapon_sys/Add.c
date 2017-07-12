#include "myhead.h"

firearms *Add (void)//尾插法
{
    int n, i=0;
    FILE *fp;
    firearms *pHead, *pNew = NULL, *pEnd, *p;
    pHead = read_from_file();
    pEnd = pHead->next;

    fp = fopen("information.txt", "at+");
    if(fp == NULL)
    {
        printf("文件打开错误, 按任意键继续...\n");
        getch();
        exit(0);
    }

    while(pEnd->next != NULL)//指向链表尾结点
        pEnd = pEnd->next;
    p = pEnd;

    system("cls");
    printf("请输入要添加信息的枪械个数:\n");
    scanf("%d" ,&n);

    do
    {
        system("cls");
        pNew = (firearms *)malloc(sizeof(firearms));
        printf("请输入第%d个添加信息:\n\n", ++i);

        printf("名称: ");
        scanf("%s", pNew->name);
        printf("产地: ");
        scanf("%s", pNew->addr);
        printf("设计者: ");
        scanf("%s", pNew->designer);
        printf("威力: ");
        scanf("%d", &pNew->wei);
        printf("便携: ");
        scanf("%d", &pNew->bian);
        printf("精准: ");
        scanf("%d", &pNew->jing);
        printf("稳定: ");
        scanf("%d", &pNew->wen);
        printf("射速: ");
        scanf("%d", &pNew->she);

        pEnd->next = pNew;
        pEnd = pNew;

    }while(i<n);
    pEnd->next = NULL;

    for(p = p->next; p != NULL; p = p->next)//写入文件
    {
        fprintf(fp, "%s %s %s %d %d %d %d %d\n",  p->name, p->addr, p->designer, p->wei, p->bian, p->jing, p->wen, p->she);
    }

    fclose(fp);
    return pHead;
}
