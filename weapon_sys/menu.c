#include "myhead.h"

void menu_main (void)
{
    int choice;
    firearms *pHead;

    do{
        system("clear");

        printf("\n\t\t\t----------***    欢迎使用枪械信息管理系统    ***--------\n\n\n");
        printf("\t\t\t====================     主界面     ==================\n\n");
        printf("\t\t\t------- 1.新建枪械信息        2.浏览枪械信息 -------\n\n");
        printf("\t\t\t------- 3.添加枪械信息        4.修改枪械信息 -------\n\n");
        printf("\t\t\t------- 5.查询枪械信息        6.删除枪械信息 -------\n\n");
        printf("\t\t\t------- 7.进入登录界面        8.信息排序     -------\n\n");
        printf("\t\t\t------- 0.退出                               -------\n\n");
        printf("\t\t\t======================================================\n\n\n");
        printf("请在0~7中选择，以回车键结束\n");
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
            default:printf("数字超出范围，按任意键返回...");
                    fflush(stdin);
                    getchar();
        }
    }while(choice);
}

/*注册登录界面*/
void menu_log (void)
{
    int choice;

    do
    {
        system("clear");
        printf("\t\t\t===================================\n");
        printf("\t\t\t===  欢迎来到枪械信息管理系统   ===\n");
        printf("\t\t\t===                             ===\n");
        printf("\t\t\t===          1.注册             ===\n");
        printf("\t\t\t===          2.登陆             ===\n");
        printf("\t\t\t===          0.退出             ===\n");
        printf("\t\t\t===                             ===\n");
        printf("\t\t\t===================================\n");

        printf("\t\t\t请输入要进行操作前的数字: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 0:return;
            case 1:Register();break;
            case 2:logIn();break;
            default:printf("数字超出范围，按任意键返回...\n");
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
        system("clear");
        printf("\t\t\t===================================\n");
        printf("\t\t\t===     请选择要修改的项目      ===\n");
        printf("\t\t\t===                             ===\n");
        printf("\t\t\t===          1.枪械名称         ===\n");
        printf("\t\t\t===          2.枪械产地         ===\n");
        printf("\t\t\t===          3.枪械设计者       ===\n");
        printf("\t\t\t===          4.枪械威力         ===\n");
        printf("\t\t\t===          5.枪械便携         ===\n");
        printf("\t\t\t===          6.枪械精准         ===\n");
        printf("\t\t\t===          7.枪械稳定性       ===\n");
        printf("\t\t\t===          8.枪械射速         ===\n");
        printf("\t\t\t===          9.全部信息         ===\n");
        printf("\t\t\t===          0.退出             ===\n");
        printf("\t\t\t===                             ===\n");
        printf("\t\t\t===================================\n");

        printf("\t\t\t请输入要进行操作前的数字: ");
        scanf("%d", &choice);

        if(choice>=0 &&choice<10)
            return choice;

        //数字超限
        printf("数字超出范围, 按任意键继续...\n");
        getchar();
        getchar();
    }while(choice);

    return 0;
}
