#include "myhead.h"

/*登陆*/
void logIn(void)
{
    int i = 0, flag = 0;;
    char ch, name[NAME_MAX], *password, tname[NAME_MAX], tpasswd[PASSWD_MAX];
    FILE *fp;
    fp = fopen("User.txt", "rt");
    if(fp == NULL)
    {
        printf("\n文件打开错误....\n");
        exit(0);
    }

    printf("请输入用户名:");
    scanf("%s", name);

    while(fscanf(fp, "%s%s", tname, tpasswd) != EOF)
    {
        if(!strcmp(tname, name))//存在该用户
        {
            flag = 1;
            do
            {
                i++;
                password = getpass("请输入密码:\n");
                if(!strcmp(password, tpasswd))//登陆成功
                    menu_main();
                else if(i<3)
                {
                    printf("\n密码错误!继续(y/n)？");
                    getchar();
                    scanf("%c", &ch);

                    if(ch == 'n' || ch == 'N')
                        return;
                    else if(ch == 'y' || ch =='Y')
                        ;
                    else
                    {
                        printf("\n输入错误,按任意键返回...\n");
                        getchar();
                        getchar();
                        i--;//输入判断条件出错，此处不计数
                    }
                }

                if(i > 2)
                {
                    printf("\n输入次数过多，按任意键返回...\n");
                    getchar();
                    getchar();
                    return;
                }
            }while(i<3);
        }
    }

    if(!flag)
    {
        printf("\n查无此人，按任意键继续...\n");
        getchar();
        getchar();
        return;
    }

    fclose(fp);
}

/*注册信息*/
void Register(void)
{
    FILE *fp;
    char t[PASSWD_MAX];
    char name[NAME_MAX], *passwd, tname[NAME_MAX], *tpasswd;
    fp = fopen("User.txt", "at+");

    if(fp == NULL)
    {
        printf("文件打开错误,按任意键继续...\n");
        getchar();
        getchar();
        exit(0);
    }

    printf("用户名: ");
    scanf("%s", name);

    /*判断用户名是否存在*/
    while(fscanf(fp, "%s%s", tname, t) != EOF)
    {
        if(!strcmp(tname, name))
        {
            printf("该用户名已存在，按任意键继续...\n");
            getchar();
            getchar();
            return;
        }
    }
    while(1)
    {
        passwd = getpass("请输入密码:\n");
        tpasswd = getpass("请确认密码:\n");
        if(!strcmp(passwd, tpasswd))//注册成功
        {
            fprintf(fp, "%s %s\n", name, passwd);
            printf("\n注册成功!    按任意键继续...\n");
            getchar();
            getchar();
            fclose(fp);
            return;
        }
        else
        {
            printf("\n两次密码不同,  按任意键继续...\n");
            getchar();
            getchar();
        }
    }
}

/*隐藏输入密码*/
/*
 *  windows下 

void passwd_input(char passwd[])
{
    int i;

    for(i = 0; (passwd[i] = getch()) && (i < PASSWD_MAX) && passwd[i] != '\r'; i++)//隐藏密码
    {
        if(passwd[i] == 8)    //删除前一位密码
        {
            i -= 2;
            printf("\b \b");  //删除前一位 '*'
        }
        else
            printf("*");

        if(i >= PASSWD_MAX)
        {
            system("cls");
            printf("密码长度过长，（%d位以内）。 按任意键继续...\n", PASSWD_MAX);
            Register();
        }
    }
    passwd[i]  = 0;     //一定要有添加结束符
}
*/

void passwd_input(char *passwd)
{
    passwd = getpass("");
}
