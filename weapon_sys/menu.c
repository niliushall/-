#include "myhead.h"

void menu_main (void)
{
    int choice;
    firearms *pHead;

    do{
        system("cls");

        printf("\n\t\t\t----------***    ��ӭʹ��ǹе��Ϣ����ϵͳ    ***--------\n\n\n");
        printf("\t\t\t====================     ������     ==================\n\n");
        printf("\t\t\t------- 1.�½�ǹе��Ϣ        2.���ǹе��Ϣ -------\n\n");
        printf("\t\t\t------- 3.���ǹе��Ϣ        4.�޸�ǹе��Ϣ -------\n\n");
        printf("\t\t\t------- 5.��ѯǹе��Ϣ        6.ɾ��ǹе��Ϣ -------\n\n");
        printf("\t\t\t------- 7.�����¼����        8.��Ϣ����     -------\n\n");
        printf("\t\t\t------- 0.�˳�                               -------\n\n");
        printf("\t\t\t======================================================\n\n\n");
        printf("����0~7��ѡ���Իس�������\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 0:exit(0);
            case 1:pHead = Create();break;
            case 2:Print_all();break;
            case 3:pHead = Add();break;
            case 4:Modify();break;
            case 5:Search();break;
            case 6:Delete();break;
            case 7:menu_log();break;
            case 8:menu_BubbleSort();break;
            default:printf("���ֳ�����Χ�������������...");
                    fflush(stdin);
                    getchar();
        }
    }while(choice);
}

/*ע���¼����*/
void menu_log (void)
{
    int choice;

    do
    {
        system("cls");
        printf("\t\t\t===================================\n");
        printf("\t\t\t===  ��ӭ����ǹе��Ϣ����ϵͳ   ===\n");
        printf("\t\t\t===                             ===\n");
        printf("\t\t\t===          1.ע��             ===\n");
        printf("\t\t\t===          2.��½             ===\n");
        printf("\t\t\t===          0.�˳�             ===\n");
        printf("\t\t\t===                             ===\n");
        printf("\t\t\t===================================\n");

        printf("\t\t\t������Ҫ���в���ǰ������: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 0:return;
            case 1:Register();break;
            case 2:logIn();break;
            default:printf("���ֳ�����Χ�������������...\n");
                getchar();
                getchar();
                menu_log();
        }
    }while(choice);
}

int menu_modify(void)
{
    int choice;

    do
    {
        system("cls");
        printf("\t\t\t===================================\n");
        printf("\t\t\t===     ��ѡ��Ҫ�޸ĵ���Ŀ      ===\n");
        printf("\t\t\t===                             ===\n");
        printf("\t\t\t===          1.ǹе����         ===\n");
        printf("\t\t\t===          2.ǹе����         ===\n");
        printf("\t\t\t===          3.ǹе�����       ===\n");
        printf("\t\t\t===          4.ǹе����         ===\n");
        printf("\t\t\t===          5.ǹе��Я         ===\n");
        printf("\t\t\t===          6.ǹе��׼         ===\n");
        printf("\t\t\t===          7.ǹе�ȶ���       ===\n");
        printf("\t\t\t===          8.ǹе����         ===\n");

        printf("\t\t\t===          9.ȫ����Ϣ         ===\n");
        printf("\t\t\t===          0.�˳�             ===\n");
        printf("\t\t\t===                             ===\n");
        printf("\t\t\t===================================\n");

        printf("\t\t\t������Ҫ���в���ǰ������: ");
        scanf("%d", &choice);

        if(choice>=0 &&choice<10)
            return choice;

        //���ֳ���
        printf("���ֳ�����Χ, �����������...\n");
        getchar();
        getchar();
    }while(choice);
}
