#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define N 10
#define H 6
#define D 10
int PASSWORD=114514;

//订单结构体
typedef struct Order{
    int Table_ID;//记录餐桌号
    int Dish_ID[N];//记录菜的编号
    struct Order *next;
}ORDER;

//餐桌结构体
typedef struct Table{
    int Table_ID;//餐桌编号
    int Capacity;//餐桌最多能容纳的人数
    int Table_State;//1 有人在用，0 没人用
}TABLE;

//菜结构体
typedef struct Dish{
    int Dish_ID;//菜的编号
    int Dish_Name[15];//菜名
    float Dish_Price;//价格
}DISH;

TABLE tb[H];//声明餐桌结构体数组
DISH dish[D];//声明菜的结构体数组

void Table_Init(void);//餐桌信息初始化
void Load_Dish(void);//从文件中读取菜谱
void Dish_Menu(void);//打印菜单
void Display(int);//打印菜的信息
int search(void);//查找匹配类型的餐桌
ORDER*CreateOne(int);//创建一个客户节点
ORDER*Dish_Order(ORDER*,ORDER*);//点菜
void Save_Inform(ORDER*,int);//消费历史记录
void saveInList(float);//将客户消费金额存入账目
ORDER*Payment(ORDER*);//客户结账
int Pass_Word(void);//密码验证
void ModifyPW();//修改账目密码
void List_Management(void);//账本管理
void Observe(void);//查看账目
void ListMenu(void);//账目管理菜单
void Main_Menu(void);//显示系统菜单
void Menu_select(void);//完成系统各项功能
void Get_Rank(void);//对菜进行排名


int main()
{
    Table_Init();
    Menu_select();
}

void Table_Init(void){
    tb[0].Table_ID=1;
    tb[0].Capacity=2;
    tb[1].Table_ID=2;
    tb[1].Capacity=2;
    tb[2].Table_ID=3;
    tb[2].Capacity=4;
    tb[3].Table_ID=4;
    tb[3].Capacity=4;
    tb[4].Table_ID=5;
    tb[4].Capacity=6;
    tb[5].Table_ID=6;
    tb[5].Capacity=6;
}

Load_Dish(void){
    int i;
    FILE *d;
    d=fopen("dishes.txt","r");
    for(i=0;i<D;i++){
        fscanf(d,"%d\t%s\t%.2f\n",&dish[i].Dish_ID,dish[i].Dish_Name,&dish[i].Dish_Price);
    }
}

void Dish_Menu(void){
    printf("********欢迎选购本店菜********\n"
           "菜编号\t菜名\t\t菜单价\n");
    int i;
    for(i=0;i<D;i++){
        printf("%d\t%s\t%.2f\n",dish[i].Dish_ID,dish[i].Dish_Name,dish[i].Dish_Price);
    }
}

void Display(int id){
    int i=0;
    for(i=0;i<D;i++){
        if(dish[i].Dish_ID==id){
            printf("%d\t%s\t%.2f\n",dish[i].Dish_ID,dish[i].Dish_Name,dish[i].Dish_Price);
            break;
        }
    }
}

int search(void){
    int number,i;
    printf("请输入来客数量：\n");
    scanf("%d",&number);
    if(6<number){
        printf("对不起，本店现无可供多于六人同时用餐的餐桌\n");
        return -1;
    }
    while(number<=6){
        for(i=0;i<H;i++){
            if(tb[i].Table_State==0){
                if(tb[i].Capacity<=number){
                    return (tb[i].Table_ID);
                }
            }
        }
    }
    printf("现无空闲餐桌，还请耐心等待");
    return -1;
}

ORDER*CreateOne(int table){
    ORDER *ptr;
    int i;
    ptr=(ORDER*)malloc(sizeof(ORDER));
    if(table!=-1){
        ptr->Table_ID=table;
        for(i=0;i<D;i++){
            printf("请输入菜的编号，按0结束输入：");
            scanf("%d",&ptr->Dish_ID[i]);
            if(ptr->Dish_ID[i]<0||ptr->Dish_ID>10){
                printf("输入的编号无效，请重新输入\n");
                i--;
            }
            else if(ptr->Dish_ID==0){
                break;
            }
        }
        tb[table-1].Table_State=1;
    }
    ptr->next=NULL;
    return ptr;
}

ORDER*Dish_Order(ORDER *head,ORDER *ptr){
    ORDER *p;
    p=head;
    if(p!=NULL){
        if(ptr!=NULL){
            while(p->next!=NULL){
                p=p->next;
                printf("成功创建账单\n");
            }
        }
        else{printf("创建订单失败\n");}
    }
    else{
        if(head==NULL&&ptr!=NULL){
            head=ptr;
            }
        }
    return head;
}

void Save_Inform(ORDER *ptr,int n){
    int i;
    time_t t;
    t=time(NULL);
    FILE *h;
    if((h=fopen("logs.txt","a"))==NULL){
        printf("保存失败\n");
    }
    else{
        fprintf(h,"%d\n",n);
        while(ptr->Dish_ID[i]>0){
            fprintf(h,"%d\t%s\t%.2f\n",dish[ptr->Dish_ID[i]-1].Dish_ID,dish[ptr->Dish_ID[i]-1].Dish_Name,dish[ptr->Dish_ID[i]-1].Dish_Price);
            i++;
        }
        fprintf(h,"%s",ctime(&time));
        printf("保存成功\n");
    }
    fclose(h);
}

void saveInList(float check){
    time_t t;
    t=time(NULL);
    FILE *m;
    if((m=fopen("账本.txt","a"))==NULL){
        printf("操作失败");
    }
    else{
        fprintf(m,"%.2f\t%s\n",check,ctime(&time));
        printf("保存成功\n");
    }
    fclose(m);
}

ORDER*Payment(ORDER *head){
    int i=0,count=0,ID;
    float check=0.0,pay;
    ORDER *ptr,*p;
    p=NULL;
    ptr=head;
    printf("请输入您的餐桌号\n");
    scanf("%d",&ID);
    while(ptr!=NULL){
        if(ptr->Table_ID==ID){
            printf("您点菜的情况如下:\n"
                   "编号\t菜名\t\t价格\n");
            while(ptr->Dish_ID[i]!=0){
                Display(ptr->Dish_ID[i]);
                check=check+dish[ptr->Dish_ID[i]-1].Dish_Price;
                i++;
                count++;
            }
            printf("您一共点了%d道菜\n",count,
			"您本次的消费额为%.2f元\n",check,
            "您实际的付款:\n");
			scanf("%f",&pay);
			if(pay>check){
                printf("找您%.2f\n",pay-check);
			}
			printf("谢谢您的惠顾,欢迎下次光临\n");
			if(count>0){
				saveInList(check);
				Save_Inform(ptr,count);
			}
			tb[ptr->Table_ID-1].Table_State=0;
			break;
        }
        else{
            p=ptr;
            ptr=ptr->next;
        }
    }
    if(ptr==NULL){
        printf("\n此餐桌还未点菜!\n");
    }
    else if(ptr==head){
        free(ptr);
        ptr==NULL;
    }
    else{
        p->next=ptr->next;
        free(ptr);
        ptr=NULL;
    }
    return head;
}

int Pass_Word(void){
    int password;
	do{
		printf("请输入密码\n");
		scanf("%d",&password);
		if(PASSWORD==password){
			printf("**********************************\n"
			"     欢迎进入账目管理系统\n"
			"**********************************\n");
			return 1;
		}
		else{
			printf("密码有误,可选择重新输入\n");
			printf("是否重新输入？\n");
		}
	}while(getchar()=='y'||getchar()=='Y');
	return 0;
}

void ModifyPW(){
    int password;
	printf("请输入新密码\n");
	scanf("%d",&password);
	PASSWORD=password;
	printf("修改成功\n");
}

void List_Management(void){
    FILE *m;
	if((m=fopen("账本.txt","r"))==NULL){
		printf("操作失败\n");
	}
	if(Pass_Word()){
		ListMenu();
	}
}

void Observe(void){
    int i=0,j=0;
    float pay;
    char string[25];
    FILE *o;
	if((o=fopen("账本.txt","r"))==NULL){
		printf("操作失败\n");
	}
	printf("消费金额\t消费时间\n");
	while(!feof(o)){
		i=0,j=0;
		fscanf(o,"%f\t",&pay);
		while(i<=5&&j<25){
			fscanf(o,"%c",&string[j]);
			j++;
			if(string[j]==' '){
				i++;
			}
		}
		fscanf(o,"\n\n");
		i=0,j=0;
		printf("%f\t",pay);
		while(i<=5&&j<25){
			printf("%c",string[j]);
			j++;
			if(string[j]==' '){
				i++;
			}
		}
		printf("\n");
	}
	fclose(o);
}

void ListMenu(void){
    int selection;
	printf("1.修改密码\n"
        "2.查看账本\n"
        "3.返回\n");
	do{
		printf("请选择:\n");
		scanf("%d",&selection);
		switch(selection){
		case 1:
		    ModifyPW();
            break;
		case 2:
		    Observe();
            break;
		case 3:
            Menu_select();
            break;
		default:
		    printf("没有该功能项\n");
		}
	}while(1);
}

void Main_Menu(void){
    printf("*********************\n"
           "餐厅服务系统"
           "*********************\n"
           "1.点菜\n"
           "2.客户结账\n"
           "3.账目管理\n"
           "4.餐馆统计\n"
           "5.退出\n"
           "请选择：");
}

void Menu_select(void){
    ORDER *head;
    int selection,table;
    head = NULL;

    Load_Dish();
    Main_Menu();
    scanf("%d",&selection);
    switch (selection)
    {
    case 1:
        table=search();
        if(table!=-1)
        {printf("您和您的朋友可以到%d号餐桌就餐\n",table);}
        else
        {break;}
        Dish_Menu();
        head = Dish_Order(head,CreateOne(table));
        break;
    case 2:
        head = Payment(head);
        break;
    case 3:
        List_Management();
        break;
    case 4:
        Get_Rank();
        break;
    case 5:
        return 0;
    }
}

void Get_Rank(void){
    FILE *r;
    int n,i,j,x=0,t=0,count[10]={0};
    char s[15]="",a[10];
    r=fopen("logs.txt","r");
    while(!feof(r))
    {
        fscanf(r,"%d\n",&n);
        i=0;
        while(i!=n)
        {
            for(j=0;j<10;j++)
            {
                if(x==dish[j].Dish_ID)
                {
                    count[j]++;
                    break;
                }
            }
            i++;
            if(i==n)
            {
                fscanf(r,"%*s%*s%*s%*s%*s",s,s,s,s,s);
            }
        }
    }
    printf("菜的受欢迎程度如下：\n");
    for(i=0;i<10;i++){
        printf("\n%d 菜：",i+1);
        for(j=0;j<count[i];j++){
            printf(" * ");
        }
    }
    for(i=0;i<9;i++){
        for(j=0;j<9-i;j++){
            if(count[j]<count[j+1]){
                t=count[j];
                strcpy(a,dish[j].Dish_Name);
                count[j]=count[j+1];
                strcpy(dish[j].Dish_Name,dish[j+1].Dish_Name);
                count[j+1]=t;
                strcpy(dish[j+1].Dish_Name,a);
            }
        }
    }
    printf("\n比较受顾客欢迎的四个菜是：\n");
    for(i=0;i<4;i++){
        printf("%s\n",dish[i].Dish_Name);
    }
    fclose(r);
}
