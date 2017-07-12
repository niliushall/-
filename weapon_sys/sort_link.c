#include "myhead.h"

int menu_BubbleSort(void)
{
    int choice;
    do
    {
        system("cls");
        printf("\t\t\t===================================\n");
        printf("\t\t\t===       ��ѡ����������      ===\n");
        printf("\t\t\t===                             ===\n");
        printf("\t\t\t===          1.ǹе����         ===\n");
        printf("\t\t\t===          2.ǹе����         ===\n");
        printf("\t\t\t===          3.ǹе��׼         ===\n");
        printf("\t\t\t===          0.�˳�             ===\n");
        printf("\t\t\t===                             ===\n");
        printf("\t\t\t===================================\n");

        printf("\t\t\t����������0~6: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 0:return;
            case 1:sort_name();Print_all();break;
            case 2:sort_wei();Print_all();break;
            case 3:sort_jing();Print_all();break;
            default:printf("����Խ�磬�����������...\n");
                    fflush(stdin);//���������ַ�������
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
    //�ж��Ƿ�ֻ��һ��Ԫ�ػ���û��Ԫ��
    if(pHead -> next == NULL || pHead -> next -> next == NULL)
    {
        return;
    }
    while(f != pHead->next->next)
    {
        //�����N - 1��ѭ��,����
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
        printf("�ļ��򿪴���, �����������...\n");
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
    //�ж��Ƿ�ֻ��һ��Ԫ�ػ���û��Ԫ��
    if(pHead -> next == NULL || pHead -> next -> next == NULL)
    {
        return;
    }
    while(f != pHead->next->next)
    {
        //�����N - 1��ѭ��,����
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
        printf("�ļ��򿪴���, �����������...\n");
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
    //�ж��Ƿ�ֻ��һ��Ԫ�ػ���û��Ԫ��
    if(pHead -> next == NULL || pHead -> next -> next == NULL)
    {
        return;
    }
    while(f != pHead->next->next)
    {
        //�����N - 1��ѭ��,����
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
        printf("�ļ��򿪴���, �����������...\n");
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
