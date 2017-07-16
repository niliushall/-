#include "myhead.h"

/*创建链表*/
firearms *Create (void)
{
    FILE *fp;
    int i = 0, n;
    char choice;
    firearms *pHead = NULL, *pEnd = NULL, *pNew = NULL;

    system("clear");//清屏
    getchar();//去掉上次输入的'\n'

    /*警告信息*/
    printf("若之前已存储信息，该操作将删除之前存储的信息。继续(y/n)?\n");
    scanf("%c", &choice);

    if(choice == 'n' || choice == 'N')
        return 0;
    else if(choice == 'y' || choice == 'Y')
        ;
    else{
        printf("输入错误,按任意键继续...\n");
        getchar();
        getchar();
        exit(0);
    }

    fp = fopen("information.txt", "wt");
    if(fp == NULL)
    {
        printf("文件打开出错， 按任意键继续...\n");
        getchar();
        getchar();
        exit(0);
    }

    system("clear");//清屏

    printf("请输入要录入枪械的种数: ");
    scanf("%d", &n);

    do{
        i++;
        pNew = (firearms *)malloc(sizeof(firearms));

        printf("\n请输入第%d种枪械的信息:", i);

        /*录入信息*/
        printf("\n\n名称: ");
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

        /*写入文件*/
        fprintf(fp, "%s %s %s %d %d %d %d %d\n",  pNew->name, pNew->addr, pNew->designer, pNew->wei, pNew->bian, pNew->jing, pNew->wen, pNew->she);
        if(i == 1){
            pHead = pNew;
            pEnd = pNew;
        }
        else{
            pEnd->next = pNew;
            pEnd = pNew;
        }
    }while(i < n);

    pNew->next = NULL;

    printf("文件创建成功!   按任意键继续...\n");
    getchar();
    getchar();
    system("clear");
    fclose(fp);//关闭文件

    return pHead;
}

/*从文件读取并创建链表*/
firearms *read_from_file(void){
    FILE *fp;
    firearms *pHead, *pNew, *pEnd;
    pHead = (firearms *)malloc(sizeof(firearms));
    if(pHead == NULL){
        printf("内存空间申请失败, 按任意键继续...\n");
        getchar();
        getchar();
        exit(0);
    }

    pHead->next = NULL;
    pEnd = pHead;

    fp = fopen("information.txt", "r");

    if(fp == NULL)
    {
        printf("文件打开出错， 按任意键继续...\n");
        getchar();
        getchar();
        exit(0);
    }
    int i=0;
    while(!feof(fp)){
        pNew = (firearms *)malloc(sizeof(firearms));
        if(pNew == NULL){
            printf("申请内存空间失败, 按任意键继续...\n");
            getchar();
            getchar();
            exit(0);
        }

    fscanf(fp, "%s %s %s %d %d %d %d %d\n",  pNew->name, pNew->addr, pNew->designer, &pNew->wei, &pNew->bian, &pNew->jing, &pNew->wen, &pNew->she);
    pEnd->next = pNew;
    pEnd = pNew;
    }
    pNew->next = NULL;
    fclose(fp);//关闭文件
    return pHead;
}


