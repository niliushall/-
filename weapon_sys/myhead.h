#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAME_MAX 10    //�û�����󳤶�
#define PASSWD_MAX 15  //������󳤶�
#define NAME 12        //ǹе������󳤶�
#define ADDR 10        //��ַ��󳤶�
#define DESIGNER 15    //�����������󳤶�

typedef struct weapon
{
    char name[NAME];//����
    char addr[ADDR];//����
    char designer[DESIGNER];//�����
    int wei;//����
    int bian;//��Я
    int jing;//��׼
    int wen;//�ȶ�
    int she;//����
    struct weapon *next;//��ַ��
}firearms;

void menu_main();//������
void menu_log();//��¼������
void Search();//��ѯ����
void logIn();//��½
void Register();//ע��

void search_name(void);//���Ʋ�ѯ
void search_addr(void);//���ز�ѯ
void search_designer(void);//����߲�ѯ

firearms *Add(void);//�����Ϣ
firearms *Create(void);//�½�����
firearms *read_from_file(void);//���ļ���ȡ����������
void Print_all(void);//��ȡ�ļ���Ϣ�����
void passwd_input(char *);//�������벢����
void Modify(void);//�޸�
int menu_BubbleSort(void);//��������˵�
void sort_name(void);//����������
void sort_wei(void);//����������
void sort_jing(void);//����׼������
