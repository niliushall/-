#include "myhead.h"

void Delete(void)
{
    int choice;

    do
    {
        system("clear");
        printf("\t\t\t=========================================\n");
        printf("\t\t\t===                                   ===\n");
        printf("\t\t\t===          1.按名称删除             ===\n");
        printf("\t\t\t===          2.按产地删除             ===\n");
        printf("\t\t\t===          3.按设计者删除           ===\n");
        printf("\t\t\t===          0.退出                   ===\n");
        printf("\t\t\t===                                   ===\n");
        printf("\t\t\t=========================================\n\n\n");

        printf("请在0~3中选择，以回车键结束\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 0:return;
            case 1:delete_name();break;
            case 2:delete_addr();break;
            case 3:delete_designer();break;
            default:
                printf("超出范围, 按任意键继续...\n");
                fflush(stdin);
                getchar();
        }
    }while(choice);
}

/*按名称删除*/
void delete_name(void)
{
    int flag = 0;   //判断是否存在所查信息
    char name[12];
    firearms *pHead = NULL, *p = NULL, *pEnd = NULL;
    FILE *fp;

    pHead = read_from_file();

    printf("请输入要删除的枪械名称:\n");
    fflush(stdin);
    scanf("%s", name);
    system("clear");

    p = pHead->next;
    pEnd = pHead;
    while(p != NULL)
    {
        if(!strcmp(p->name, name))
        {
            flag = 1;
            pEnd->next = p->next;
        }
        pEnd = p;
        p = p->next;
    }

    if(!flag)
    {
        printf("\n\n文件内没有该枪械信息, 按任意键继续...\n");
        getchar();
        return;
    }

    fp = fopen("information.txt", "wt");
    if(fp == NULL)
    {
        printf("文件打开错误, 按任意键继续...\n");
        getchar();
        getchar();
        exit(0);
    }
    p = pHead->next;
    while(p != NULL)
    {
        fprintf(fp, "%s %s %s %d %d %d %d %d\n",  p->name, p->addr, p->designer, p->wei, p->bian, p->jing, p->wen, p->she);
        p = p->next;
    }
    fclose(fp);

    printf("\n\n已删除, 按任意键继续...\n");
    getchar();
    getchar();
    return;
}

/*按产地删除*/
void delete_addr(void)
{
    int flag = 0;   //判断是否存在所查信息
    char addr[10];
    firearms *pHead = NULL, *p = NULL, *pEnd = NULL;
    FILE *fp;

    pHead = read_from_file();

    printf("请输入要删除的枪械产地:\n");
    fflush(stdin);
    scanf("%s", addr);
    system("clear");

    p = pHead->next;
    pEnd = pHead;
    while(p != NULL)
    {
        if(!strcmp(p->addr, addr))
        {
            flag = 1;
            pEnd->next = p->next;
        }
        pEnd = p;
        p = p->next;
    }

    if(!flag)
    {
        printf("\n\n文件内没有该枪械信息, 按任意键继续...\n");
        getchar();
        return;
    }

    fp = fopen("information.txt", "wt");
    if(fp == NULL)
    {
        printf("文件打开错误, 按任意键继续...\n");
        getchar();
        getchar();
        exit(0);
    }
    p = pHead->next;
    while(p != NULL)
    {
        fprintf(fp, "%s %s %s %d %d %d %d %d\n",  p->name, p->addr, p->designer, p->wei, p->bian, p->jing, p->wen, p->she);
        p = p->next;
    }
    fclose(fp);

    printf("\n\n已删除, 按任意键继续...\n");
    getchar();
    getchar();
    return;
}

/*按设计者删除*/
void delete_designer(void)
{
    int flag = 0;   //判断是否存在所查信息
    char designer[15];
    firearms *pHead = NULL, *p = NULL, *pEnd = NULL;
    FILE *fp;

    pHead = read_from_file();

    printf("请输入要删除的枪械设计者:\n");
    fflush(stdin);
    scanf("%s", designer);
    system("clear");

    p = pHead->next;
    pEnd = pHead;
    while(p != NULL)
    {
        if(!strcmp(p->designer, designer))
        {
            flag = 1;
            pEnd->next = p->next;
        }
        pEnd = p;
        p = p->next;
    }

    if(!flag)
    {
        printf("\n\n文件内没有该枪械信息, 按任意键继续...\n");
        getchar();
        getchar();
        return;
    }

    fp = fopen("information.txt", "wt");
    if(fp == NULL)
    {
        printf("文件打开错误, 按任意键继续...\n");
        getchar();
        getchar();
        exit(0);
    }
    p = pHead->next;
    while(p != NULL)
    {
        fprintf(fp, "%s %s %s %d %d %d %d %d\n",  p->name, p->addr, p->designer, p->wei, p->bian, p->jing, p->wen, p->she);
        p = p->next;
    }
    fclose(fp);

    printf("\n\n已删除, 按任意键继续...\n");
    getchar();
    getchar();
    return;
}
