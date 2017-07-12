#include "myhead.h"

int menu_BubbleSort(void)
{
    int choice;
    do
    {
        system("cls");
        printf("\t\t\t===================================\n");
        printf("\t\t\t===       请选择按哪项排序      ===\n");
        printf("\t\t\t===                             ===\n");
        printf("\t\t\t===          1.枪械名称         ===\n");
        printf("\t\t\t===          2.枪械威力         ===\n");
        printf("\t\t\t===          3.枪械精准         ===\n");
        printf("\t\t\t===          0.退出             ===\n");
        printf("\t\t\t===                             ===\n");
        printf("\t\t\t===================================\n");

        printf("\t\t\t请输入数字0~6: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 0:return;
            case 1:sort_name();Print_all();break;
            case 2:sort_wei();Print_all();break;
            case 3:sort_jing();Print_all();break;
            default:printf("数字越界，按任意键继续...\n");
                    fflush(stdin);//避免输入字符型数据
                    getchar();
        }
    }while(choice);
}

void sort_name(void)
{
    FILE *fp;
    firearms *f, *p, *x, *y ,*pHead;
    f = NULL;
    pHead = read_from_file();
    //判断是否只有一个元素或者没有元素
    if(pHead -> next == NULL || pHead -> next -> next == NULL)
    {
        return;
    }
    while(f != pHead->next->next)
    {
        //外层是N - 1次循环,升序
        for(p = pHead; p -> next -> next != f; p = p -> next)
        {
            if(strcmp(p -> next -> name, p -> next -> next -> name) > 0)
            {
                x = p -> next;
                y = p -> next -> next;
                p -> next = y;
                x -> next = y -> next;
                y -> next = x;
            }
        }
        f = p -> next;
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
        int i=0;
        fprintf(fp, "%s %s %s %d %d %d %d %d\n", p->name, p->addr, p->designer, p->wei, p->bian, p->jing, p->wen, p->she);
        p = p->next;
    }
    fclose(fp);
}

void sort_wei(void)
{
    FILE *fp;
    firearms *f, *p, *x, *y ,*pHead;
    f = NULL;
    pHead = read_from_file();
    //判断是否只有一个元素或者没有元素
    if(pHead -> next == NULL || pHead -> next -> next == NULL)
    {
        return;
    }
    while(f != pHead->next->next)
    {
        //外层是N - 1次循环,升序
        for(p = pHead; p -> next -> next != f; p = p -> next)
        {
            if(p -> next -> wei > p -> next -> next -> wei)
            {
                x = p -> next;
                y = p -> next -> next;
                p -> next = y;
                x -> next = y -> next;
                y -> next = x;
            }
        }
        f = p -> next;
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
        int i=0;
        fprintf(fp, "%s %s %s %d %d %d %d %d\n", p->name, p->addr, p->designer, p->wei, p->bian, p->jing, p->wen, p->she);
        p = p->next;
    }
    fclose(fp);
}

void sort_jing(void)
{
    FILE *fp;
    firearms *f, *p, *x, *y ,*pHead;
    f = NULL;
    pHead = read_from_file();
    //判断是否只有一个元素或者没有元素
    if(pHead -> next == NULL || pHead -> next -> next == NULL)
    {
        return;
    }
    while(f != pHead->next->next)
    {
        //外层是N - 1次循环,升序
        for(p = pHead; p -> next -> next != f; p = p -> next)
        {
            if(p -> next -> jing > p -> next -> next -> jing)
            {
                x = p -> next;
                y = p -> next -> next;
                p -> next = y;
                x -> next = y -> next;
                y -> next = x;
            }
        }
        f = p -> next;
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
        int i=0;
        fprintf(fp, "%s %s %s %d %d %d %d %d\n", p->name, p->addr, p->designer, p->wei, p->bian, p->jing, p->wen, p->she);
        p = p->next;
    }
    fclose(fp);
}
