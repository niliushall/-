#include "myhead.h"
/*
void Modify(void)
{
    int choice;

    do
    {
        system("cls");
        printf("\t\t\t=========================================\n");
        printf("\t\t\t===                                   ===\n");
        printf("\t\t\t===          1.按名称修改             ===\n");
        printf("\t\t\t===          2.按产地修改             ===\n");
        printf("\t\t\t===          3.按设计者修改           ===\n");
        printf("\t\t\t===          0.退出                   ===\n");
        printf("\t\t\t===                                   ===\n");
        printf("\t\t\t=========================================\n\n\n");

        printf("请在0~3中选择，以回车键结束\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 0:return 0;
            case 1:Modify_name();break;
            //case 2:Modify_addr();break;
            //case 3:Modify_designer();break;
            default:
                printf("超出范围, 按任意键继续...\n");
                fflush(stdin);
                getchar();
        }
    }while(choice);
}
*/
void Modify(void)
{
    FILE *fp;
    firearms *pHead = NULL, *p = NULL;
    char name[NAME];
    int choice;
    printf("请输入要修改的枪械名称: ");
    fflush(stdin);
    gets(name);

    pHead = read_from_file();
    p = pHead->next;

    while(p != NULL && strcmp(p->name, name))//找到相应结点
        p = p->next;;
    if(p == NULL)
    {
        printf("没有该枪械信息...\n");
        getch();
        return;
    }
    choice = menu_modify();//调用函数，返回所选项目

    fflush(stdin);
    switch(choice)
    {
        case 0: return;
        case 1: printf("请输入修改后的名称:\n");
                gets(p->name);
                break;
        case 2: printf("请输入修改后的产地:\n");
                gets(p->addr);
                break;
        case 3: printf("请输入修改后的设计者姓名:\n");
                gets(p->designer);
                break;
        case 4: printf("请输入修改后的威力:\n");
                scanf("%d", &p->wei);
                break;
        case 5: printf("请输入修改后的便携度:\n");
                scanf("%d", &p->bian);
                break;
        case 6: printf("请输入修改后的精准度:\n");
                scanf("%d", &p->jing);
                break;
        case 7: printf("请输入修改后的稳定性:\n");
                scanf("%d", &p->wen);
                break;
        case 8: printf("请输入修改后的射速:\n");
                scanf("%d", &p->she);
                break;
        case 9: printf("请输入修改后的全部信息:");
                printf("\n\n名称: ");
                scanf("%s", p->name);
                printf("产地: ");
                scanf("%s", p->addr);
                printf("设计者: ");
                scanf("%s", p->designer);
                printf("威力: ");
                scanf("%d", &p->wei);
                printf("便携: ");
                scanf("%d", &p->bian);
                printf("精准: ");
                scanf("%d", &p->jing);
                printf("稳定: ");
                scanf("%d", &p->wen);
                printf("射速: ");
                scanf("%d", &p->she);
                break;
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
    printf("修改成功， 按任意键继续...\n");
    getchar();
}
