#include "myhead.h"

/*��½*/
void logIn(void)
{
    int i = 0, flag = 0;;
    char ch, name[NAME_MAX], password[PASSWD_MAX], tname[NAME_MAX], tpasswd[PASSWD_MAX];
    FILE *fp;
    fp = fopen("User.txt", "rt");
    if(fp == NULL)
    {
        printf("\n�ļ��򿪴���....\n");
        exit(0);
    }

    printf("�������û���:");
    scanf("%s", name);

    while(fscanf(fp, "%s%s", tname, tpasswd) != EOF)
    {
        if(!strcmp(tname, name))//���ڸ��û�
        {
            flag = 1;
            do
            {
                i++;
                printf("����������:");
                passwd_input(password);

                if(!strcmp(password, tpasswd))//��½�ɹ�
                    menu_main();
                else if(i<3)
                {
                    printf("\n�������!����(y/n)��");
                    getchar();
                    scanf("%c", &ch);

                    if(ch == 'n' || ch == 'N')
                        return;
                    else if(ch == 'y' || ch =='Y')
                        ;
                    else
                    {
                        printf("\n�������,�����������...\n");
                        getchar();
                        getchar();
                        i--;//�����ж����������˴�������
                    }
                }

                if(i > 2)
                {
                    printf("\n����������࣬�����������...\n");
                    getchar();
                    getchar();
                    return;
                }
            }while(i<3);
        }
    }

    if(!flag)
    {
        printf("\n���޴��ˣ������������...\n");
        getchar();
        getchar();
        return;
    }

    fclose(fp);
}

/*ע����Ϣ*/
void Register(void)
{
    FILE *fp;
    char name[NAME_MAX], passwd[PASSWD_MAX], tname[NAME_MAX], tpasswd[PASSWD_MAX];
    fp = fopen("User.txt", "at+");

    if(fp == NULL)
    {
        printf("�ļ��򿪴���,�����������...\n");
        getchar();
        getchar();
        exit(0);
    }

    printf("�û���: ");
    scanf("%s", name);

    /*�ж��û����Ƿ����*/
    while(fscanf(fp, "%s%s", tname, tpasswd) != EOF)
    {
        if(!strcmp(tname, name))
        {
            printf("���û����Ѵ��ڣ������������...\n");
            getch();
            return;
        }
    }
    while(1)
    {
        printf("\n����������: ");
        passwd_input(passwd);

        printf("\n��ȷ������: ");
        passwd_input(tpasswd);

        if(!strcmp(passwd, tpasswd))//ע��ɹ�
        {
            fprintf(fp, "%s %s\n", name, passwd);
            printf("\nע��ɹ�!    �����������...\n");
            getch();
            fclose(fp);
            return;
        }
        else
        {
            printf("\n�������벻ͬ,  �����������...\n");
            getch();
        }
    }
}

/*������������*/
void passwd_input(char passwd[])
{
    int i;

    for(i = 0; (passwd[i] = getch()) && (i < PASSWD_MAX) && passwd[i] != '\r'; i++)//��������
    {
        if(passwd[i] == 8)    //ɾ��ǰһλ����
        {
            i -= 2;
            printf("\b \b");  //ɾ��ǰһλ '*'
        }
        else
            printf("*");

        if(i >= PASSWD_MAX)
        {
            system("cls");
            printf("���볤�ȹ�������%dλ���ڣ��� �����������...\n", PASSWD_MAX);
            Register();
        }
    }
    passwd[i]  = 0;     //һ��Ҫ����ӽ�����
}

