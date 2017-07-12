#include "myhead.h"

/*��������*/
firearms *Create (void)
{
    FILE *fp;
    int i = 0, n;
    char choice;
    firearms *pHead = NULL, *pEnd = NULL, *pNew = NULL;

    system("cls");//����
    getchar();//ȥ���ϴ������'\n'

    /*������Ϣ*/
    printf("��֮ǰ�Ѵ洢��Ϣ���ò�����ɾ��֮ǰ�洢����Ϣ������(y/n)?\n");
    scanf("%c", &choice);

    if(choice == 'n' || choice == 'N')
        return 0;
    else if(choice == 'y' || choice == 'Y')
        ;
    else{
        printf("�������,�����������...\n");
        getchar();
        getchar();
        exit(0);
    }

    fp = fopen("information.txt", "wt");
    if(fp == NULL)
    {
        printf("�ļ��򿪳��� �����������...\n");
        getchar();
        getchar();
        exit(0);
    }

    system("cls");//����

    printf("������Ҫ¼��ǹе������: ");
    scanf("%d", &n);

    do{
        i++;
        pNew = (firearms *)malloc(sizeof(firearms));

        printf("\n�������%d��ǹе����Ϣ:", i);

        /*¼����Ϣ*/
        printf("\n\n����: ");
        scanf("%s", pNew->name);
        printf("����: ");
        scanf("%s", pNew->addr);
        printf("�����: ");
        scanf("%s", pNew->designer);
        printf("����: ");
        scanf("%d", &pNew->wei);
        printf("��Я: ");
        scanf("%d", &pNew->bian);
        printf("��׼: ");
        scanf("%d", &pNew->jing);
        printf("�ȶ�: ");
        scanf("%d", &pNew->wen);
        printf("����: ");
        scanf("%d", &pNew->she);

        /*д���ļ�*/
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

    printf("�ļ������ɹ�!   �����������...\n");
    getchar();
    getchar();
    system("cls");
    fclose(fp);//�ر��ļ�

    return pHead;
}

/*���ļ���ȡ����������*/
firearms *read_from_file(void){
    FILE *fp;
    firearms *pHead, *pNew, *pEnd;
    pHead = (firearms *)malloc(sizeof(firearms));
    if(pHead == NULL){
        printf("�ڴ�ռ�����ʧ��, �����������...\n");
        getchar();
        getchar();
        exit(0);
    }

    pHead->next = NULL;
    pEnd = pHead;

    fp = fopen("information.txt", "r");

    if(fp == NULL)
    {
        printf("�ļ��򿪳��� �����������...\n");
        getchar();
        getchar();
        exit(0);
    }
int i=0;
    while(!feof(fp)){
        pNew = (firearms *)malloc(sizeof(firearms));

        if(pNew == NULL){
            printf("�����ڴ�ռ�ʧ��, �����������...\n");
            getchar();
            getchar();
            exit(0);
        }

        /*��ȡ��Ϣ,��fscanf����*/
        if(fscanf(fp, "%s%s%s%d%d%d%d%d", pNew->name, pNew->addr, pNew->designer, &pNew->wei, &pNew->bian, &pNew->jing, &pNew->wen, &pNew->she) != EOF)
        {
            pEnd->next = pNew;
            pEnd = pNew;
        }
    }

    fclose(fp);//�ر��ļ�
    return pHead;
}


