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
	printf("请选择您想要查看的房屋\n");
	printf("1.house1\n");
	printf("2.house2\n");
	printf("3.house3\n");
	printf("4.house4\n");
	printf("5.house5\n");
	printf("6.退出系统\n");

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
            printf("已退出程序\n");
            break;

	}
}



void checkin(){
int arr[5]={123,234,345,456,567};
printf("请输入您的ID\n");
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
        printf("您已拥有big house\n");
        printf("1.入住 2.出租 3.空置\n");
        scanf("%d",&q);
        if(q==1)
            printf("入住成功\n");
        else if(q==2)
            printf("出租成功\n");
         else if(q==3)
            printf("空置成功\n");
        }
        else if(k==1){
        printf("您已拥有medium house\n");
        printf("1.入住 2.出租 3.空置\n");
        scanf("%d",&q);
        if(q==1)
            printf("入住成功\n");
        else if(q==2)
            printf("出租成功\n");
         else if(q==3)
            printf("空置成功\n");
        }
        else if(k==2){
        printf("您已拥有small house\n");
        printf("1.入住 2.出租 3.空置\n");
        scanf("%d",&q);
        if(q==1)
            printf("入住成功\n");
        else if(q==2)
            printf("出租成功\n");
         else if(q==3)
            printf("空置成功\n");
        }
        else if(k==3){
        printf("您没有房子\n");
        printf("1.现在购买2.暂不购买\n");
        scanf("%d",&q);
        if(q==1)
            printf("余额不足\n");
        else if(q==2)
            printf("已退出程序\n");
        }
        else if(k==4){
        printf("您没有房子\n");
        printf("1.现在购买2.暂不购买\n");
        scanf("%d",&q);
        if(q==1)
            printf("余额不足\n");
        else if(q==2)
            printf("已退出程序\n");
        }
}
typedef struct vip_{
    int vip_id;//会员编号
    char name[20];//会员名称
    char gender;//会员性别
    int age;//会员的年龄
    char house[10];
    struct vip *next;
}VIP;

//定义用户管理结构体
typedef struct manage_{
    int stuff_id;//工号
    char name[20];//员工名称
    char gender;//员工性别
    int serve;//员工服务对象
    struct manage *next;
}MANAGE;

VIP vips;//会员结构体
MANAGE stuffs;//员工结构体

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
    puts("查找会员，请输入会员编号：");
    scanf("%d",&n);
    VIP *p = (h1->next);
    while(p!=NULL){
        if((p->next)==n){
            puts("该会员存在");
        }
        else{
            puts("该会员不存在！");
        }
    }
}

void delete_vip(){
    int n;
    puts("删除会员，请输入会员编号：");
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
        puts("该会员不存在！");
    }
}

void insert_vip(){
    int n;
    puts("插入会员，请输入会员编号：");
    scanf("%d",&n);
    n=n-1001;
    VIP *p = h1,*ptr;
    ptr = (VIP *)malloc(sizeof(VIP));
    puts("请输入会员数据");
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
        puts("该会员不存在！");
    }
}

void change_vip(){
    int n;
    puts("修改会员数据，请输入会员编号：");
    scanf("%d",&n);
    n=n-1001;
    VIP *p = h1;
    int i=0;
    while(i<n&&p!=NULL){
        p = (p->next);
        i++;
    }
    if(p!=NULL){
        puts("请输入修改之后的数据");
        scanf("%d %s %c %d %s",&p->vip_id,&p->name,&p->gender,&p->age,&p->house);
    }
    else{
        puts("该会员不存在！");
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
    puts("查找员工，请输入员工编号：");
    scanf("%d",&n);
    MANAGE *p = (h2->next);
    while(p!=NULL){
        if((p->next)==n){
            puts("该员工存在");
        }
        else{
            puts("该员工不存在！");
        }
    }
}

void delete_manage(){
    int n;
    puts("删除员工，请输入员工编号：");
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
        puts("该员工不存在！");
    }
}

void insert_manage(){
    int n;
    puts("插入员工，请输入会员编号：");
    scanf("%d",&n);
    n=n-1001;
    MANAGE *p = h2,*ptr;
    ptr = (MANAGE *)malloc(sizeof(MANAGE));
    puts("请输入员工数据");
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
        puts("该员工不存在！");
    }
}

void change_manage(){
    int n;
    puts("修改员工的数据，请输入员工编号：");
    scanf("%d",&n);
    n=n-1001;
    MANAGE *p = h2;
    int i=0;
    while(i<n&&p!=NULL){
        p = p->next;
        i++;
    }
    if(p!=NULL){
        puts("请输入修改之后的数据");
        scanf("%d %s %c %d",&p->stuff_id,&p->name,&p->gender,&p->serve);
    }
    else{
        puts("该员工不存在！");
    }
}

void set_manage(){
    int n;
    puts("设置员工的服务对象，请输入员工编号：");
    scanf("%d",&n);
    n=n-1001;
    MANAGE *p = h2;
    int i=0;
    while(i<n&&p!=NULL){
        p = p->next;
        i++;
    }
    if(p!=NULL){
        puts("请输入修改之后的数据");
        scanf("%d",&p->serve);
    }
    else{
        puts("该员工不存在！");
    }
}

void check_manage(){
    int n;
    puts("查看员工的服务对象，请输入员工编号：");
    scanf("%d",&n);
    MANAGE *p = h2->next;
    while(p!=NULL){
        if(p->next==n){
            printf("该员工存在，其服务对象为%d",&p->serve);
        }
        else{
            puts("该员工不存在！");
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
        puts("错误！");
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
        puts("错误！");
        break;
}
}

void select(){
    int x,b;
    printf("1.会员相关\n2.员工相关\n");
    printf("请输入操作：");
    scanf("%d",&x);
    create_vip();
    create_manage();
    switch(x)
    {
        case 1:
            puts("1.新建\n2.查询\n3.修改\n4.删除");
            scanf("%d",&b);
            choose1(b);
            break;
        case 2:
            puts("1.新增\n2.修改\n3.删除\n4.设置服务对象\n5.查看服务对象");
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
      printf("请输入娱乐场所名称:\n");
      scanf("%s",node1->name);
      printf("\n请输入娱乐场所号码:\n");
      scanf("%d",&node1->number);
      end->ptr=node1;
      end=node1;
  }
end->ptr=NULL;
return head;
}//建立链表
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
        puts("不存在");
    }
}//删除娱乐场所
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
        puts("请输入插入名称:\n");
        scanf("%s",in->name);
        puts("请输入插入号码:\n");
        scanf("%d",&in->number);
        in->ptr=t->ptr;
        t->ptr=in;
    }
    else{
        puts("不存在");
    }
}//增加娱乐场所
void print(Equ *startptr)
{
    while(startptr->ptr!=NULL)
    {
        startptr=startptr->ptr;
        printf("%s          %d\n",startptr->name,startptr->number);
    }
}//打印
void place_manage(){
Equ *startptr;
if(a==0)
{
    printf("欢迎来到娱乐场所管理系统\n");
    int n;
    printf("请输入娱乐场所数目:\n");//初始化
    scanf("%d",&n);
    startptr=node(&n);
    a++;
}
int m;
printf("\n请选择功能\n1.添加娱乐场所\n2.删除娱乐场所\n3.打印娱乐场所\n");
scanf("%d",&m);
int tem;
switch(m)
{   case 1:
    printf("\n请输入增加第几个娱乐场所:\n");
    scanf("%d",&tem);
    equ_add(head,tem);
    startptr=head;
    break;
    case 2:
    printf("\n请输入删除第几个娱乐场所:\n");
    scanf("%d",&tem);
    equ_del(head,tem);
    startptr=head;
    break;
    case 3:
    printf(head);
    startptr=head;
    case 4:
    printf("\n退出\n");
    system("pause");
    break;
}
}

int main()
{
    int x;
    printf("1.人员管理\n2.房屋相关\n3.场馆设施\n4.人员入住\n");
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
        puts("错误!");
    }
    return 0;
}
