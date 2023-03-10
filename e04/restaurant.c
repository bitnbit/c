#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define N 10
#define H 6
#define D 10
int PASSWORD=114514;

//�����ṹ��
typedef struct Order{
    int Table_ID;//��¼������
    int Dish_ID[N];//��¼�˵ı��
    struct Order *next;
}ORDER;

//�����ṹ��
typedef struct Table{
    int Table_ID;//�������
    int Capacity;//������������ɵ�����
    int Table_State;//1 �������ã�0 û����
}TABLE;

//�˽ṹ��
typedef struct Dish{
    int Dish_ID;//�˵ı��
    int Dish_Name[15];//����
    float Dish_Price;//�۸�
}DISH;

TABLE tb[H];//���������ṹ������
DISH dish[D];//�����˵Ľṹ������

void Table_Init(void);//������Ϣ��ʼ��
void Load_Dish(void);//���ļ��ж�ȡ����
void Dish_Menu(void);//��ӡ�˵�
void Display(int);//��ӡ�˵���Ϣ
int search(void);//����ƥ�����͵Ĳ���
ORDER*CreateOne(int);//����һ���ͻ��ڵ�
ORDER*Dish_Order(ORDER*,ORDER*);//���
void Save_Inform(ORDER*,int);//������ʷ��¼
void saveInList(float);//���ͻ����ѽ�������Ŀ
ORDER*Payment(ORDER*);//�ͻ�����
int Pass_Word(void);//������֤
void ModifyPW();//�޸���Ŀ����
void List_Management(void);//�˱�����
void Observe(void);//�鿴��Ŀ
void ListMenu(void);//��Ŀ����˵�
void Main_Menu(void);//��ʾϵͳ�˵�
void Menu_select(void);//���ϵͳ�����
void Get_Rank(void);//�Բ˽�������


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
    printf("********��ӭѡ�������********\n"
           "�˱��\t����\t\t�˵���\n");
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
    printf("����������������\n");
    scanf("%d",&number);
    if(6<number){
        printf("�Բ��𣬱������޿ɹ���������ͬʱ�ò͵Ĳ���\n");
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
    printf("���޿��в������������ĵȴ�");
    return -1;
}

ORDER*CreateOne(int table){
    ORDER *ptr;
    int i;
    ptr=(ORDER*)malloc(sizeof(ORDER));
    if(table!=-1){
        ptr->Table_ID=table;
        for(i=0;i<D;i++){
            printf("������˵ı�ţ���0�������룺");
            scanf("%d",&ptr->Dish_ID[i]);
            if(ptr->Dish_ID[i]<0||ptr->Dish_ID>10){
                printf("����ı����Ч������������\n");
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
                printf("�ɹ������˵�\n");
            }
        }
        else{printf("��������ʧ��\n");}
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
        printf("����ʧ��\n");
    }
    else{
        fprintf(h,"%d\n",n);
        while(ptr->Dish_ID[i]>0){
            fprintf(h,"%d\t%s\t%.2f\n",dish[ptr->Dish_ID[i]-1].Dish_ID,dish[ptr->Dish_ID[i]-1].Dish_Name,dish[ptr->Dish_ID[i]-1].Dish_Price);
            i++;
        }
        fprintf(h,"%s",ctime(&time));
        printf("����ɹ�\n");
    }
    fclose(h);
}

void saveInList(float check){
    time_t t;
    t=time(NULL);
    FILE *m;
    if((m=fopen("�˱�.txt","a"))==NULL){
        printf("����ʧ��");
    }
    else{
        fprintf(m,"%.2f\t%s\n",check,ctime(&time));
        printf("����ɹ�\n");
    }
    fclose(m);
}

ORDER*Payment(ORDER *head){
    int i=0,count=0,ID;
    float check=0.0,pay;
    ORDER *ptr,*p;
    p=NULL;
    ptr=head;
    printf("���������Ĳ�����\n");
    scanf("%d",&ID);
    while(ptr!=NULL){
        if(ptr->Table_ID==ID){
            printf("����˵��������:\n"
                   "���\t����\t\t�۸�\n");
            while(ptr->Dish_ID[i]!=0){
                Display(ptr->Dish_ID[i]);
                check=check+dish[ptr->Dish_ID[i]-1].Dish_Price;
                i++;
                count++;
            }
            printf("��һ������%d����\n",count,
			"�����ε����Ѷ�Ϊ%.2fԪ\n",check,
            "��ʵ�ʵĸ���:\n");
			scanf("%f",&pay);
			if(pay>check){
                printf("����%.2f\n",pay-check);
			}
			printf("лл���Ļݹ�,��ӭ�´ι���\n");
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
        printf("\n�˲�����δ���!\n");
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
		printf("����������\n");
		scanf("%d",&password);
		if(PASSWORD==password){
			printf("**********************************\n"
			"     ��ӭ������Ŀ����ϵͳ\n"
			"**********************************\n");
			return 1;
		}
		else{
			printf("��������,��ѡ����������\n");
			printf("�Ƿ��������룿\n");
		}
	}while(getchar()=='y'||getchar()=='Y');
	return 0;
}

void ModifyPW(){
    int password;
	printf("������������\n");
	scanf("%d",&password);
	PASSWORD=password;
	printf("�޸ĳɹ�\n");
}

void List_Management(void){
    FILE *m;
	if((m=fopen("�˱�.txt","r"))==NULL){
		printf("����ʧ��\n");
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
	if((o=fopen("�˱�.txt","r"))==NULL){
		printf("����ʧ��\n");
	}
	printf("���ѽ��\t����ʱ��\n");
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
	printf("1.�޸�����\n"
        "2.�鿴�˱�\n"
        "3.����\n");
	do{
		printf("��ѡ��:\n");
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
		    printf("û�иù�����\n");
		}
	}while(1);
}

void Main_Menu(void){
    printf("*********************\n"
           "��������ϵͳ"
           "*********************\n"
           "1.���\n"
           "2.�ͻ�����\n"
           "3.��Ŀ����\n"
           "4.�͹�ͳ��\n"
           "5.�˳�\n"
           "��ѡ��");
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
        {printf("�����������ѿ��Ե�%d�Ų����Ͳ�\n",table);}
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
    printf("�˵��ܻ�ӭ�̶����£�\n");
    for(i=0;i<10;i++){
        printf("\n%d �ˣ�",i+1);
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
    printf("\n�Ƚ��ܹ˿ͻ�ӭ���ĸ����ǣ�\n");
    for(i=0;i<4;i++){
        printf("%s\n",dish[i].Dish_Name);
    }
    fclose(r);
}
