#include "myhead.h"

void Search(void)
{
    int choice;

    do
    {
        system("cls");
        printf("\t\t\t=========================================\n");
        printf("\t\t\t===     ��ӭ����ǹе��Ϣ����ϵͳ      ===\n");
        printf("\t\t\t===                                   ===\n");
        printf("\t\t\t===          1.�����Ʋ�ѯ             ===\n");
        printf("\t\t\t===          2.�����ز�ѯ             ===\n");
        printf("\t\t\t===          3.������߲�ѯ           ===\n");
        printf("\t\t\t===          0.�˳�                   ===\n");
        printf("\t\t\t===                                   ===\n");
        printf("\t\t\t=========================================\n\n\n");

        printf("����0~3��ѡ���Իس�������\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 0:return 0;
            case 1:search_name();break;
            case 2:search_addr();break;
            case 3:search_designer();break;
            default:
                printf("������Χ, �����������...\n");
                getch();
        }
    }while(choice);
}

/*�����Ʋ�ѯ*/
void search_name(void)
{
    int flag = 0;   //�ж��Ƿ����������Ϣ
    char name[NAME_MAX];
    firearms *pHead = NULL, *p = NULL;
    pHead = read_from_file();

    printf("������Ҫ��ѯ��ǹе����:\n");
    fflush(stdin);
    gets(name);
    system("cls");

    printf("%-15s%-12s%-18s%-6s%-6s%-6s%-6s%-6s\n", "ǹе����", "ǹе����", "�����", "����", "��Я", "��׼", "�ȶ�", "����");

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
        printf("\n\n�ļ���û�и�ǹе��Ϣ, �����������...\n");
        getch();
        return;
    }
    printf("\n\n���ݲ�ѯ���, �����������...\n");
    getch();
    return;
}

/*����ַ��ѯ*/
void search_addr(void)
{
    int flag = 0;   //�ж��Ƿ����������Ϣ
    char addr[12];
    firearms *pHead = NULL, *p = NULL;
    pHead = read_from_file();

    printf("������Ҫ��ѯ��ǹе����:\n");
    fflush(stdin);  //������뻺����
    gets(addr);
    system("cls");

    printf("%-15s%-12s%-18s%-6s%-6s%-6s%-6s%-6s\n", "ǹе����", "ǹе����", "�����", "����", "��Я", "��׼", "�ȶ�", "����");

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
        printf("\n\n�ļ���û�и�ǹе��Ϣ, �����������...\n");
        getch();
        return;
    }
    printf("\n\n���ݲ�ѯ���, �����������...\n");
    getch();
    return;
}

/*������߲�ѯ*/
void search_designer(void)
{
    int flag = 0;   //�ж��Ƿ����������Ϣ
    char designer[12];
    firearms *pHead = NULL, *p = NULL;
    pHead = read_from_file();

    printf("������Ҫ��ѯ��ǹе�����:\n");
    fflush(stdin);  //������뻺����
    gets(designer);
    system("cls");

    printf("%-15s%-12s%-18s%-6s%-6s%-6s%-6s%-6s\n", "ǹе����", "ǹе����", "�����", "����", "��Я", "��׼", "�ȶ�", "����");

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
        printf("\n\n�ļ���û�и�ǹе��Ϣ, �����������...\n");
        getch();
        return;
    }
    printf("\n\n���ݲ�ѯ���, �����������...\n");
    getch();
    return;
}
