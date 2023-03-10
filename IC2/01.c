#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void house(){
struct House{
	char Size[50];
	char Price[50];
	char Purchase[50];
  	char Usage[50];
};

struct House house1;
strcpy(house1.Size,"very big house");
strcpy(house1.Price,"1000w");
strcpy(house1.Purchase,"unsold");
strcpy(house1.Usage,"nobody use");

struct House house2;
strcpy(house2.Size,"big house");
strcpy(house2.Price,"500w");
strcpy(house2.Purchase,"sold");
strcpy(house2.Usage,"in use");

struct House house3;
strcpy(house3.Size,"medium house");
strcpy(house3.Price,"200w");
strcpy(house3.Purchase,"sold");
strcpy(house3.Usage,"in use");

struct House house4;
strcpy(house4.Size,"little house");
strcpy(house4.Price,"100w");
strcpy(house4.Purchase,"unsold");
strcpy(house4.Usage,"nobody use");

struct House house5;
strcpy(house5.Size,"very little house");
strcpy(house5.Price,"50w");
strcpy(house5.Purchase,"sold");
strcpy(house5.Usage,"nobody use");

    printf("\n*********************\n");
	printf("Welcome to the housing management system.\n");
	printf("*********************\n");
	printf("��ѡ������Ҫ�鿴�ķ���\n");
	printf("1.house1\n");
	printf("2.house2\n");
	printf("3.house3\n");
	printf("4.house4\n");
	printf("5.house5\n");
	printf("6.�˳�ϵͳ\n");

	int option;
	scanf("%d",&option);
	switch(option){
	    case 1:
	        printf("size:%s\nprice:%s\n%s\n%s\n",house1.Size,house1.Price,house1.Purchase,house1.Usage);
	        break;
	    case 2:
	        printf("size:%s\nprice:%s\n%s\n%s\n",house2.Size,house2.Price,house2.Purchase,house2.Usage);
	        break;
	    case 3:
	        printf("size:%s\nprice:%s\n%s\n%s\n",house3.Size,house3.Price,house3.Purchase,house3.Usage);
	        break;
	    case 4:
	        printf("size:%s\nprice:%s\n%s\n%s\n",house4.Size,house4.Price,house4.Purchase,house4.Usage);
	        break;
	    case 5:
	        printf("size:%s\nprice:%s\n%s\n%s\n",house5.Size,house5.Price,house5.Purchase,house5.Usage);
	        break;
        case 6:
            printf("���˳�����\n");
            break;

	}
}



void checkin(){
int arr[5]={123,234,345,456,567};
printf("����������ID\n");
int ID;
scanf("%d",&ID);
int k;
int i;
for(i=0;i<5;i++){
        if(arr[i]==ID)
        {
           k=i;
        break;
        }

    }
    int q;
    if(k==0){
        printf("����ӵ��big house\n");
        printf("1.��ס 2.���� 3.����\n");
        scanf("%d",&q);
        if(q==1)
            printf("��ס�ɹ�\n");
        else if(q==2)
            printf("����ɹ�\n");
         else if(q==3)
            printf("���óɹ�\n");
        }
        else if(k==1){
        printf("����ӵ��medium house\n");
        printf("1.��ס 2.���� 3.����\n");
        scanf("%d",&q);
        if(q==1)
            printf("��ס�ɹ�\n");
        else if(q==2)
            printf("����ɹ�\n");
         else if(q==3)
            printf("���óɹ�\n");
        }
        else if(k==2){
        printf("����ӵ��small house\n");
        printf("1.��ס 2.���� 3.����\n");
        scanf("%d",&q);
        if(q==1)
            printf("��ס�ɹ�\n");
        else if(q==2)
            printf("����ɹ�\n");
         else if(q==3)
            printf("���óɹ�\n");
        }
        else if(k==3){
        printf("��û�з���\n");
        printf("1.���ڹ���2.�ݲ�����\n");
        scanf("%d",&q);
        if(q==1)
            printf("����\n");
        else if(q==2)
            printf("���˳�����\n");
        }
        else if(k==4){
        printf("��û�з���\n");
        printf("1.���ڹ���2.�ݲ�����\n");
        scanf("%d",&q);
        if(q==1)
            printf("����\n");
        else if(q==2)
            printf("���˳�����\n");
        }
}
typedef struct vip_{
    int vip_id;//��Ա���
    char name[20];//��Ա����
    char gender;//��Ա�Ա�
    int age;//��Ա������
    char house[10];
    struct vip *next;
}VIP;

//�����û�����ṹ��
typedef struct manage_{
    int stuff_id;//����
    char name[20];//Ա������
    char gender;//Ա���Ա�
    int serve;//Ա���������
    struct manage *next;
}MANAGE;

VIP vips;//��Ա�ṹ��
MANAGE stuffs;//Ա���ṹ��

VIP *h1 = NULL;
VIP *head1,*node1,*end1;


MANAGE *h2 = NULL;
MANAGE *head2,*node2,*end2;

VIP *create_vip(){
    head1=(VIP *)malloc(sizeof(VIP));
    end1 = head1;
    node1 = (VIP *)malloc(sizeof(VIP));
    scanf("%d %s %c %d %s",&node1->vip_id,&node1->name,&node1->gender,&node1->age,&node1->house);
    (end1->next) = node1;
    end1 = node1;
    end1->next = NULL;
    return head1;
}

void search_vip(){
    int n;
    puts("���һ�Ա���������Ա��ţ�");
    scanf("%d",&n);
    VIP *p = (h1->next);
    while(p!=NULL){
        if((p->next)==n){
            puts("�û�Ա����");
        }
        else{
            puts("�û�Ա�����ڣ�");
        }
    }
}

void delete_vip(){
    int n;
    puts("ɾ����Ա���������Ա��ţ�");
    scanf("%d",&n);
    n=n-1001;
    VIP *p = h1,*ptr = h1;
    int i=0;
    while (i<n&&p!=NULL){
        ptr = p;
        p = p->next;
        i++;
    }
    if(p!=NULL){
        ptr->next = p->next;
        free(p);
    }
    else{
        puts("�û�Ա�����ڣ�");
    }
}

void insert_vip(){
    int n;
    puts("�����Ա���������Ա��ţ�");
    scanf("%d",&n);
    n=n-1001;
    VIP *p = h1,*ptr;
    ptr = (VIP *)malloc(sizeof(VIP));
    puts("�������Ա����");
    scanf("%d %s %c %d %s",&ptr->vip_id,&ptr->name,&ptr->gender,&ptr->age,&ptr->house);
    int i=0;

    while(i<n&&p!=NULL){
        p = (p->next);
        i++;
    }
    if(p!=NULL){
        ptr->next = p->next;
        (p->next) = ptr;
    }
    else{
        puts("�û�Ա�����ڣ�");
    }
}

void change_vip(){
    int n;
    puts("�޸Ļ�Ա���ݣ��������Ա��ţ�");
    scanf("%d",&n);
    n=n-1001;
    VIP *p = h1;
    int i=0;
    while(i<n&&p!=NULL){
        p = (p->next);
        i++;
    }
    if(p!=NULL){
        puts("�������޸�֮�������");
        scanf("%d %s %c %d %s",&p->vip_id,&p->name,&p->gender,&p->age,&p->house);
    }
    else{
        puts("�û�Ա�����ڣ�");
    }
}

MANAGE *create_manage(){
    head2=(MANAGE *)malloc(sizeof(MANAGE));
    end2 = head2;
    node2 = (MANAGE *)malloc(sizeof(MANAGE));
    scanf("%d %s %c %d",&node2->stuff_id,&node2->name,&node2->gender,&node2->serve);
    (end2->next) = node2;
    end2 = node2;
    end2->next = NULL;
    return head2;
}

void search_manage(){
    int n;
    puts("����Ա����������Ա����ţ�");
    scanf("%d",&n);
    MANAGE *p = (h2->next);
    while(p!=NULL){
        if((p->next)==n){
            puts("��Ա������");
        }
        else{
            puts("��Ա�������ڣ�");
        }
    }
}

void delete_manage(){
    int n;
    puts("ɾ��Ա����������Ա����ţ�");
    scanf("%d",&n);
    n=n-1001;
    MANAGE *p = h2,*ptr = h2;
    int i=0;
    while (i<n&&p!=NULL){
        ptr = p;
        p = (p->next);
        i++;
    }
    if(p!=NULL){
        ptr->next = p->next;
        free(p);
    }
    else{
        puts("��Ա�������ڣ�");
    }
}

void insert_manage(){
    int n;
    puts("����Ա�����������Ա��ţ�");
    scanf("%d",&n);
    n=n-1001;
    MANAGE *p = h2,*ptr;
    ptr = (MANAGE *)malloc(sizeof(MANAGE));
    puts("������Ա������");
    scanf("%d %s %c %d",&ptr->stuff_id,&ptr->name,&ptr->gender,&ptr->serve);
    int i=0;

    while(i<n&&p!=NULL){
        p = (p->next);
        i++;
    }
    if(p!=NULL){
        ptr->next = p->next;
        (p->next) = ptr;
    }
    else{
        puts("��Ա�������ڣ�");
    }
}

void change_manage(){
    int n;
    puts("�޸�Ա�������ݣ�������Ա����ţ�");
    scanf("%d",&n);
    n=n-1001;
    MANAGE *p = h2;
    int i=0;
    while(i<n&&p!=NULL){
        p = p->next;
        i++;
    }
    if(p!=NULL){
        puts("�������޸�֮�������");
        scanf("%d %s %c %d",&p->stuff_id,&p->name,&p->gender,&p->serve);
    }
    else{
        puts("��Ա�������ڣ�");
    }
}

void set_manage(){
    int n;
    puts("����Ա���ķ������������Ա����ţ�");
    scanf("%d",&n);
    n=n-1001;
    MANAGE *p = h2;
    int i=0;
    while(i<n&&p!=NULL){
        p = p->next;
        i++;
    }
    if(p!=NULL){
        puts("�������޸�֮�������");
        scanf("%d",&p->serve);
    }
    else{
        puts("��Ա�������ڣ�");
    }
}

void check_manage(){
    int n;
    puts("�鿴Ա���ķ������������Ա����ţ�");
    scanf("%d",&n);
    MANAGE *p = h2->next;
    while(p!=NULL){
        if(p->next==n){
            printf("��Ա�����ڣ���������Ϊ%d",&p->serve);
        }
        else{
            puts("��Ա�������ڣ�");
        }
    }
}

void choose1(int b){
switch(b){
    case 1:
        insert_vip();
        break;
    case 2:
        search_vip();
        break;
    case 3:
        change_vip();
        break;
    case 4:
        delete_vip();
        break;
    default:
        puts("����");
        break;
}
}

void choose2(int b){
switch(b){
    case 1:
        insert_manage();
        break;
    case 2:
        change_manage();
        break;
    case 3:
        delete_manage();
        break;
    case 4:
        set_manage();
        break;
    case 5:
        check_manage();
        break;
    default:
        puts("����");
        break;
}
}

void select(){
    int x,b;
    printf("1.��Ա���\n2.Ա�����\n");
    printf("�����������");
    scanf("%d",&x);
    create_vip();
    create_manage();
    switch(x)
    {
        case 1:
            puts("1.�½�\n2.��ѯ\n3.�޸�\n4.ɾ��");
            scanf("%d",&b);
            choose1(b);
            break;
        case 2:
            puts("1.����\n2.�޸�\n3.ɾ��\n4.���÷������\n5.�鿴�������");
            scanf("%d",&b);
            choose2(b);
            break;
    }
}
int a=0;
typedef struct equ
{
    char name[20];
    int number;
    struct equ* ptr;
}Equ;

    Equ *const head;
Equ *node(int *n){
    Equ *const head=(Equ*)malloc(sizeof(Equ));
    Equ *node1,*end;
    end=head;
  for(int i=0;i<*n;i++)
  {
      node1=(Equ*)malloc(sizeof(Equ));
      printf("���������ֳ�������:\n");
      scanf("%s",node1->name);
      printf("\n���������ֳ�������:\n");
      scanf("%d",&node1->number);
      end->ptr=node1;
      end=node1;
  }
end->ptr=NULL;
return head;
}//��������
void equ_del(Equ *list,int n)
{
    Equ *t=list,*in;
    int i=0;
    while(i<n&&t!=NULL)
    {
        in=t;
        t=t->ptr;
        i++;
    }
    if(t!=NULL)
    {
        in->ptr=t->ptr;
        free(t);
    }
    else{
        puts("������");
    }
}//ɾ�����ֳ���
void equ_add(Equ *list,int n)
{
    Equ *t=list,*in;
    int i=0;
    while(i<n&&t!=NULL)
    {
        t=t->ptr;
        i++;
    }
    if(t!=NULL)
    {
        in=(Equ*)malloc(sizeof(Equ));
        puts("�������������:\n");
        scanf("%s",in->name);
        puts("������������:\n");
        scanf("%d",&in->number);
        in->ptr=t->ptr;
        t->ptr=in;
    }
    else{
        puts("������");
    }
}//�������ֳ���
void print(Equ *startptr)
{
    while(startptr->ptr!=NULL)
    {
        startptr=startptr->ptr;
        printf("%s          %d\n",startptr->name,startptr->number);
    }
}//��ӡ
void place_manage(){
Equ *startptr;
if(a==0)
{
    printf("��ӭ�������ֳ�������ϵͳ\n");
    int n;
    printf("���������ֳ�����Ŀ:\n");//��ʼ��
    scanf("%d",&n);
    startptr=node(&n);
    a++;
}
int m;
printf("\n��ѡ����\n1.������ֳ���\n2.ɾ�����ֳ���\n3.��ӡ���ֳ���\n");
scanf("%d",&m);
int tem;
switch(m)
{   case 1:
    printf("\n���������ӵڼ������ֳ���:\n");
    scanf("%d",&tem);
    equ_add(head,tem);
    startptr=head;
    break;
    case 2:
    printf("\n������ɾ���ڼ������ֳ���:\n");
    scanf("%d",&tem);
    equ_del(head,tem);
    startptr=head;
    break;
    case 3:
    printf(head);
    startptr=head;
    case 4:
    printf("\n�˳�\n");
    system("pause");
    break;
}
}

int main()
{
    int x;
    printf("1.��Ա����\n2.�������\n3.������ʩ\n4.��Ա��ס\n");
    scanf("%d",&x);
    switch(x)
    {
    case 1:
        select();
        break;
    case 2:
        house();
        break;
    case 3:
        place_manage();
        break;
    case 4:
        checkin();
        break;
    default:
        puts("����!");
    }
    return 0;
}
