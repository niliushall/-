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
        printf("\t\t\t===          1.�������޸�             ===\n");
        printf("\t\t\t===          2.�������޸�             ===\n");
        printf("\t\t\t===          3.��������޸�           ===\n");
        printf("\t\t\t===          0.�˳�                   ===\n");
        printf("\t\t\t===                                   ===\n");
        printf("\t\t\t=========================================\n\n\n");

        printf("����0~3��ѡ���Իس�������\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 0:return 0;
            case 1:Modify_name();break;
            //case 2:Modify_addr();break;
            //case 3:Modify_designer();break;
            default:
                printf("������Χ, �����������...\n");
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
    printf("������Ҫ�޸ĵ�ǹе����: ");
    fflush(stdin);
    gets(name);

    pHead = read_from_file();
    p = pHead->next;

    while(p != NULL && strcmp(p->name, name))//�ҵ���Ӧ���
        p = p->next;;
    if(p == NULL)
    {
        printf("û�и�ǹе��Ϣ...\n");
        getch();
        return;
    }
    choice = menu_modify();//���ú�����������ѡ��Ŀ

    fflush(stdin);
    switch(choice)
    {
        case 0: return;
        case 1: printf("�������޸ĺ������:\n");
                gets(p->name);
                break;
        case 2: printf("�������޸ĺ�Ĳ���:\n");
                gets(p->addr);
                break;
        case 3: printf("�������޸ĺ�����������:\n");
                gets(p->designer);
                break;
        case 4: printf("�������޸ĺ������:\n");
                scanf("%d", &p->wei);
                break;
        case 5: printf("�������޸ĺ�ı�Я��:\n");
                scanf("%d", &p->bian);
                break;
        case 6: printf("�������޸ĺ�ľ�׼��:\n");
                scanf("%d", &p->jing);
                break;
        case 7: printf("�������޸ĺ���ȶ���:\n");
                scanf("%d", &p->wen);
                break;
        case 8: printf("�������޸ĺ������:\n");
                scanf("%d", &p->she);
                break;
        case 9: printf("�������޸ĺ��ȫ����Ϣ:");
                printf("\n\n����: ");
                scanf("%s", p->name);
                printf("����: ");
                scanf("%s", p->addr);
                printf("�����: ");
                scanf("%s", p->designer);
                printf("����: ");
                scanf("%d", &p->wei);
                printf("��Я: ");
                scanf("%d", &p->bian);
                printf("��׼: ");
                scanf("%d", &p->jing);
                printf("�ȶ�: ");
                scanf("%d", &p->wen);
                printf("����: ");
                scanf("%d", &p->she);
                break;
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
        fprintf(fp, "%s %s %s %d %d %d %d %d\n",  p->name, p->addr, p->designer, p->wei, p->bian, p->jing, p->wen, p->she);
        p = p->next;
    }
    fclose(fp);
    printf("�޸ĳɹ��� �����������...\n");
    getchar();
}
