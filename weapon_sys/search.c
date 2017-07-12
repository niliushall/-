#include "myhead.h"

void Search(void)
{
    int choice;

    do
    {
        system("cls");
        printf("\t\t\t=========================================\n");
        printf("\t\t\t===     欢迎来到枪械信息管理系统      ===\n");
        printf("\t\t\t===                                   ===\n");
        printf("\t\t\t===          1.按名称查询             ===\n");
        printf("\t\t\t===          2.按产地查询             ===\n");
        printf("\t\t\t===          3.按设计者查询           ===\n");
        printf("\t\t\t===          0.退出                   ===\n");
        printf("\t\t\t===                                   ===\n");
        printf("\t\t\t=========================================\n\n\n");

        printf("请在0~3中选择，以回车键结束\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 0:return 0;
            case 1:search_name();break;
            case 2:search_addr();break;
            case 3:search_designer();break;
            default:
                printf("超出范围, 按任意键继续...\n");
                getch();
        }
    }while(choice);
}

/*按名称查询*/
void search_name(void)
{
    int flag = 0;   //判断是否存在所查信息
    char name[NAME_MAX];
    firearms *pHead = NULL, *p = NULL;
    pHead = read_from_file();

    printf("请输入要查询的枪械名称:\n");
    fflush(stdin);
    gets(name);
    system("cls");

    printf("%-15s%-12s%-18s%-6s%-6s%-6s%-6s%-6s\n", "枪械名称", "枪械产地", "设计者", "威力", "便携", "精准", "稳定", "射速");

    for(p = pHead; p != NULL; p = p->next)
    {
        if(!strcmp(name, p->name))
        {
            flag = 1;
            printf("%-15s%-12s%-18s%-6d%-6d%-6d%-6d%-6d\n",  p->name, p->addr, p->designer, p->wei, p->bian, p->jing, p->wen, p->she);
        }
    }

    if(!flag)
    {
        printf("\n\n文件内没有该枪械信息, 按任意键继续...\n");
        getch();
        return;
    }
    printf("\n\n内容查询完毕, 按任意键继续...\n");
    getch();
    return;
}

/*按地址查询*/
void search_addr(void)
{
    int flag = 0;   //判断是否存在所查信息
    char addr[12];
    firearms *pHead = NULL, *p = NULL;
    pHead = read_from_file();

    printf("请输入要查询的枪械产地:\n");
    fflush(stdin);  //清空输入缓冲区
    gets(addr);
    system("cls");

    printf("%-15s%-12s%-18s%-6s%-6s%-6s%-6s%-6s\n", "枪械名称", "枪械产地", "设计者", "威力", "便携", "精准", "稳定", "射速");

    for(p = pHead; p != NULL; p = p->next)
    {
        if(!strcmp(addr, p->addr))
        {
            flag = 1;
            printf("%-15s%-12s%-18s%-6d%-6d%-6d%-6d%-6d\n",  p->name, p->addr, p->designer, p->wei, p->bian, p->jing, p->wen, p->she);
        }
    }

    if(!flag)
    {
        system("cls");
        printf("\n\n文件内没有该枪械信息, 按任意键继续...\n");
        getch();
        return;
    }
    printf("\n\n内容查询完毕, 按任意键继续...\n");
    getch();
    return;
}

/*按设计者查询*/
void search_designer(void)
{
    int flag = 0;   //判断是否存在所查信息
    char designer[12];
    firearms *pHead = NULL, *p = NULL;
    pHead = read_from_file();

    printf("请输入要查询的枪械设计者:\n");
    fflush(stdin);  //清空输入缓冲区
    gets(designer);
    system("cls");

    printf("%-15s%-12s%-18s%-6s%-6s%-6s%-6s%-6s\n", "枪械名称", "枪械产地", "设计者", "威力", "便携", "精准", "稳定", "射速");

    for(p = pHead; p != NULL; p = p->next)
    {
        if(!strcmp(designer, p->designer))
        {
            flag = 1;
            printf("%-15s%-12s%-18s%-6d%-6d%-6d%-6d%-6d\n",  p->name, p->addr, p->designer, p->wei, p->bian, p->jing, p->wen, p->she);
        }
    }

    if(!flag)
    {
        system("cls");
        printf("\n\n文件内没有该枪械信息, 按任意键继续...\n");
        getch();
        return;
    }
    printf("\n\n内容查询完毕, 按任意键继续...\n");
    getch();
    return;
}
