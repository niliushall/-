#include "myhead.h"

void Print_all(void){
    FILE *fp;
    firearms *pHead, *p;

    fp = fopen("information.txt", "rt");
    if(fp == NULL){
        printf("���ļ����� �����������...\n");
        getchar();
        getchar();
        exit(0);
    }

    system("cls");
    /*�����Ϣ*/
    printf("%-15s%-12s%-18s%-6s%-6s%-6s%-6s%-6s\n\n", "ǹе����", "ǹе����", "�����", "����", "��Я", "��׼", "�ȶ�", "����");
    pHead = read_from_file();  //��ȡ�ļ���Ϣ
    p = pHead->next;

    while(p != NULL){
        printf("%-15s%-12s%-18s%-6d%-6d%-6d%-6d%-6d\n",  p->name, p->addr, p->designer, p->wei, p->bian, p->jing, p->wen, p->she);
        p = p->next;
    }

    fclose(fp);

    printf("\n\n\n�ļ�������ȫ������� �����������...\n");
    getch();
}
