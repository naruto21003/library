#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct link
{
char number[100];
char bookname[100];
char author[100];
char publish[100];
char time[100];
float price;
char status[100];
struct link *next;

}link;

//函数声明 

void mainmenu();
void menu1();
void glmenu();
void cxmenu();
void jhmenu();
void print(link *head);
void  hold(link *head);
void holdcx(link *t);
link *Cbook();
link *findnumber(link *head);
link *findboookname(link *head);
link *findauthor(link *head);
link *add(link *head);
link *sortnumber(link *head);
link *delbook(link *head);
link *revamp(link *head);
link *borrowbook(link *head);
 link *returnbook(link *head);
 
 //主函数 
main()
{
int a,b,c,d,e;
link *h,*t;

L:system("cls");
mainmenu();
while(1) 
{
scanf("%d",&a);
switch(a)
{
case 1:
   {
   B: system("cls"); 
   menu1();
   while(1)
   {
   	scanf("%d",&b);
   	switch(b)
   	{
    case 1: 
	   {
   	     h=Cbook();
	   }break;
   	case 2:
	   {
	   system("cls");
	   glmenu();
	   while(1)
	   {
	   	scanf("%d",&c);
	   	switch(c)
	   	{
		   case 1:
		   {
		   print(h);
		   }break;
		   case 2: 
		   {
		   h=add(h);
		   h=sortnumber(h);
		   print(h);
		   
		   
		   }break;
		   case 3:
		   {
   			revamp(h);
   		   }
		   break;
           case 4:
		     {
   			h=delbook(h);
   			print(h);
   		   
			  }break;
		   case 5: 
		   {
		   hold(h); 
		   }break;
		   case 6:
		   	{
		   		goto B;
		    }break;
	   		
	   	}
   		
   	   }
	   
	   }break;
   	case 3:
	   {
	    system("cls");
	    cxmenu();
	    while(1)
	    {
    		scanf("%d",&d);
    		switch(d)
    		{
   	           case 1: 
				  {
				   print(h);
				  }break;
               case 2:
			   {
			   t=findnumber(h);
			   if(t==NULL)
			   printf("没有要查询的图书！！！");
			   if(t!=NULL)
			   {
			   	printf("查询的图书为：");
   				printf("\n");
                printf("\n**************************************************\n");
            	printf("\n编号\t\t书名\t\t作者\t\t出版社\t\t出版时间\t\t价格\t\t状态\n"); 
            	
	            printf("\n");
	        	printf("%s\t%s\t%s\t%s\t%s",t->number,t->bookname,t->author,t->publish,t->time);
	        	printf("\t\t%.2f",t->price);
	        	printf("\t\t%s",t->status);
				printf("\n");
        	
	           }
   			   
				  }break;
		       case 3: 
			   {
			   t=findboookname(h);
			   if(t==NULL)
			   printf("没有要查询的图书！！！");
			   if(t!=NULL)
			   {
			   	printf("查询的图书为：");
   				printf("\n");
                printf("\n**************************************************\n");
            	printf("\n编号\t\t书名\t\t作者\t\t出版社\t\t出版时间\t\t价格\t\t状态\n"); 
            	
	            printf("\n");
	        	printf("%s\t%s\t%s\t%s\t%s",t->number,t->bookname,t->author,t->publish,t->time);
	        	printf("\t\t%.2f",t->price);
	        	printf("\t\t%s",t->status);
	        	printf("\n");
        	
	           }
   			   }break;
		       case 4:
			   	{
			   	t=findauthor(h);
			   if(t==NULL)
			   printf("没有要查询的图书！！！");
			   if(t!=NULL)
			   {
			   	printf("查询的图书为：");
   				printf("\n");
                printf("\n**************************************************\n");
            	printf("\n编号\t\t书名\t\t作者\t\t出版社\t\t出版时间\t\t价格\t\t状态\n"); 
            	
	            printf("\n");
	        	printf("%s\t%s\t%s\t%s\t%s",t->number,t->bookname,t->author,t->publish,t->time);
	        	printf("\t\t%.2f",t->price);
	        	printf("\t\t%s",t->status);
				printf("\n");
        	
	           }
			  
   			   }
			    
				break;
		       case 5: 
			   	{
			   
			   holdcx(t);
			   
			   
			   }break;
		       case 6:
			   	{
		   		   goto B;
		        }break;
		    }
    	}
	   
	   }break;
    case 4:
	{
	system("cls");
	jhmenu();
	while(1)
	{
	scanf("%d",&e);
	switch(e)
	{
		case 1: 
		{
		borrowbook(h);
		}break;
		case 2: 
		{
		returnbook(h); 
		}break;
		case 3:
		{
		goto B;
		}break;
	}
		
	} 
	}break;
   	case 5:
	   {
	    hold(h); 
	   }break;
   	case 6:
	   {
	   system("cls");
	   menu1();
	   
	   }break;
   	case 7:
	   {
	   goto L; 
	   }break;	
    }
   
   }
   }break;
case 0: 
{
printf("\t\t\t感谢使用，再见！！！");
exit(0);
}
}
}
}
link *Cbook()
{
int n=0;
link *p,*q,*head;
FILE *fp;
fp=fopen("图书信息.txt","r+");
if(fp==NULL)
printf("没有找到文件，请检查……");
p=(link *)malloc(sizeof(link));
if(p==NULL)
printf("申请内存出错！！！\n");

fscanf(fp,"%s%s%s%s%s",p->number,p->bookname,p->author,p->publish,p->time);
fscanf(fp,"%f",&p->price);
fscanf(fp,"%s",p->status);
while(feof(fp)==0)
{
n++;
if(n==1)
{
	head=p;
}
else
{
q=p;
p=(link *)malloc(sizeof(link));
if(p==NULL)
printf("申请内存出错！！！\n");

fscanf(fp,"%s%s%s%s%s",p->number,p->bookname,p->author,p->publish,p->time);
fscanf(fp,"%f",&p->price);
fscanf(fp,"%s",p->status);
q->next=p;

}
}
p->next=NULL;
fclose(fp);
printf("信息已录入！！！");
return head;
}

void mainmenu()
{
printf("\n**************************************************\n");
printf("\n**            欢迎使用图书管理系统              **\n");
printf("\n**           1.进入系统");
printf("\t0.退出系统              **\n");
printf("\n**************************************************\n");
printf("\n   请选择");
}

void menu1()
{

printf("\n**************************************************\n");
printf("\n**             1.录入所有书籍信息               **\n");
printf("\n**             2.进入图书管理系统               **\n");
printf("\n**             3.进入图书查询系统               **\n");
printf("\n**             4.进入图书借还系统               **\n");
printf("\n**             5.保存所有图书信息               **\n");
printf("\n**             6.显示菜单                       **\n");
printf("\n**             7.返回上级菜单                   **\n");
printf("\n**************************************************\n");
printf("\n请选择");
}

void glmenu()
{

 printf("\n**************************************************\n");
 printf("\n**             1.显示所有图书信息               **\n");
 printf("\n**             2.添加一本图书信息               **\n");
 printf("\n**             3.修改一本图书信息               **\n");
 printf("\n**             4.删除一本图书信息               **\n");
 printf("\n**             5.保存所有图书信息               **\n");
 printf("\n**             6.返回上级菜单                   **\n");
 printf("\n**************************************************\n");
 printf("\n请选择");

}

void cxmenu()
{
 printf("\n**************************************************\n");
 printf("\n**             1.显示所有图书信息               **\n");
 printf("\n**             2.按编号查询图书                 **\n");
 printf("\n**             3.按书名查询图书                 **\n");
 printf("\n**             4.按作者查询图书                 **\n");
 printf("\n**             5.保存所查询图书的信息           **\n");
 printf("\n**             6.返回上级菜单                   **\n");
 printf("\n**************************************************\n");
 printf("\n请选择");

}

void jhmenu()
{
printf("\n**************************************************\n");
printf("\n**             1.借书                           **\n");
printf("\n**             2.还书                           **\n");
printf("\n**             3.返回上级菜单                   **\n");
printf("\n**************************************************\n");
printf("\n请选择");	
} 
 
void print(link *head)
{
	link *p;
	p=head;
	if(p==NULL)
	{
	printf("文件中没有图书信息\n");
	}
	else{
		
	
	printf("\n");
	printf("\n**************************************************\n");
	printf("\n编号\t\t书名\t\t作者\t\t出版社\t\t出版时间\t\t价格\t\t状态\n"); 
	while(p!=NULL)
	{	
	    printf("\n");
		printf("%s\t%s\t%s\t%s\t%s",p->number,p->bookname,p->author,p->publish,p->time);
		printf("\t\t%.2f",p->price);
		printf("\t\t%s",p->status);
		printf("\n");
		p=p->next;
	}
}
}


void  hold(link *head)
{
link *p;
FILE *fp;
fp=fopen("图书信息.txt","w+");
if(fp==NULL)
{
printf("文件操作出错！！！");
exit(1);	
}
p=head;
	
for(;p!=NULL;p=p->next)
{   fprintf(fp,"\n");
	fprintf(fp,"%s\t%s\t%s\t%s\t%s",p->number,p->bookname,p->author,p->publish,p->time);
	fprintf(fp,"\t\t%.2f",p->price);
	fprintf(fp,"\t\t%s",p->status);
		
}
fclose(fp);
printf("信息已保存。");
}

void holdcx(link *t)
{
	link *p=NULL;
	FILE *fp;
	fp=fopen("查询.txt","a+");
	p=t;
	fprintf(fp,"查询到的信息为：\n");
	fprintf(fp,"\n");
	fprintf(fp,"\n**************************************************\n");
	fprintf(fp,"\n编号\t\t书名\t\t作者\t\t出版社\t\t出版时间\t\t价格\t\t状态\n");
	fprintf(fp,"\n");
	fprintf(fp,"%s\t%s\t%s\t%s\t%s",p->number,p->bookname,p->author,p->publish,p->time);
	fprintf(fp,"\t\t%.2f",p->price);
	fprintf(fp,"\t\t%s",p->status);
	fprintf(fp,"\n");
	fclose(fp);
	printf("信息已保存!!!");
}


link *findnumber(link *head)
{
char key[100];
link *h,*t1=NULL;

printf("请输入图书的编号：");
getchar();
gets(key);


for(h=head;h!=NULL;h=h->next)
{
   if(strcmp(key,h->number)==0)
   {
	   t1=h;
	   break;
   }
   
}
return t1;
} 
