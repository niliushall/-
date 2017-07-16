#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define NAME_MAX 10    //用户名最大长度
#define PASSWD_MAX 15  //密码最大长度
#define NAME 12        //枪械名称最大长度
#define ADDR 10        //地址最大长度
#define DESIGNER 15    //设计者姓名最大长度

typedef struct weapon
{
    char name[NAME];//名称
    char addr[ADDR];//产地
    char designer[DESIGNER];//设计者
    int wei;//威力
    int bian;//便携
    int jing;//精准
    int wen;//稳定
    int she;//射速
    struct weapon *next;//地址域
}firearms;

void menu_main();//主界面
void menu_log(void);//登录注册界面
int menu_modify(void);//修改选择界面
void Search();//查询界面
void logIn();//登陆
void Register();//注册

void Modify(void);
void Modify_name(void);//按名称修改
void Modify_addr(void);//按地址修改
void Modify_designer(void);//按设计者修改

void search_name(void);//名称查询
void search_addr(void);//产地查询
void search_designer(void);//设计者查询

firearms *Add(void);//添加信息
firearms *Create(void);//新建链表
firearms *read_from_file(void);//从文件读取并创建链表
void Print_all(void);//读取文件信息并输出
void passwd_input(char *);//输入密码并隐藏
int menu_BubbleSort(void);//链表排序菜单

void Delete(void);
void delete_name(void);
void delete_addr(void);
void delete_designer(void);

void sort_name(void);//按姓名排序
void sort_addr(void);//按地址排序
void sort_designer(void);//按设计者排序
void sort_wei(void);//按威力排序
void sort_jing(void);//按精准度排序
void sort_bian(void);//按便携度排序
void sort_wen(void);//按稳定性排序
void sort_she(void);//按射速排序
