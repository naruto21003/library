# include <stdio.h>
# include <stdlib.h>
# include <string.h>

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

link *findboookname(link *head)
{
char key[100];
link *h,*t2=NULL;

printf("请输入图书的书名：");
getchar();
gets(key);

for(h=head;h!=NULL;h=h->next)
{
   if(strcmp(key,h->bookname)==0)
   {
	   t2=h;
	   break;
   }
   
}
return  t2;
}

link *findauthor(link *head)
{
char key[100];
link *h,*t3=NULL;

printf("请输入作者姓名：");
getchar();
gets(key);

for(h=head;h!=NULL;h=h->next)
{
   if(strcmp(key,h->author)==0)
   {
	   t3=h;
	   break;
   }
   
}
return  t3;
	
}

link *add(link *head)
{
	link *h,*h1;
	h1=head;
	h=(link *)malloc(sizeof(link));
	if(h==NULL)
	{
		printf("申请内存出错！！！");
		exit(1);
	}
	printf("请输入添加图书的信息");
	printf("\n");
	printf("\n**************************************************\n");
	printf("\n编号\t\t书名\t\t作者\t\t出版社\t\t出版时间\t\t价格\t\t状态\n");
	scanf("%s%s%s%s%s",h->number,h->bookname,h->author,h->publish,h->time);
	scanf("%f",&h->price);
	scanf("%s",h->status);
    h->next=h1;
    return h;
}

link *sortnumber(link *head)
{
	link *p,*q,*temp;
    temp=(link *)malloc(sizeof(link));
    if(temp==NULL)
    {
    	printf("申请内存出错！！！");
    	exit(1);
    }

	for(p=head;p!=NULL;p=p->next)
	  {
        for(q=p->next;q!=NULL;q=q->next)
		{
			if(strcmp(p->number,q->number)>0)
		  {
			 strcpy(temp->number,p->number);
			 strcpy(temp->bookname,p->bookname);
			 strcpy(temp->author,p->author);
			 strcpy(temp->publish,p->publish);
			 strcpy(temp->time,p->time);
			 temp->price=p->price;
			 strcpy(temp->status,p->status);
			 
			 strcpy(p->number,q->number);
			 strcpy(p->bookname,q->bookname);
			 strcpy(p->author,q->author);
			 strcpy(p->publish,q->publish);
			 strcpy(p->time,q->time);
			 p->price=q->price;
			 strcpy(p->status,temp->status); 
			  
		     strcpy(q->number,temp->number);
			 strcpy(q->bookname,temp->bookname);
			 strcpy(q->author,temp->author);
			 strcpy(q->publish,temp->publish);
			 strcpy(q->time,temp->time);
			 q->price=temp->price;
			 strcpy(q->status,temp->status);
		  }  
			 
		  }
	  
	  }

	
    
return head;
  
} 

link *delbook(link *head)
{
int k=0;
char str[10];
link *h,*t,*p;
h=t=p=head;

printf("请输入要删除图书的书名:");
getchar();
gets(str);
for(;p!=NULL;p=p->next)
{
	k++;
   if(k>2)
   {
   t=t->next;
   }

    if((strcmp(p->bookname,str)==0)&&(k==1))
   {
      h=p->next;
         
   }
	    else if(strcmp(p->bookname,str)==0&&k>1)
		{ 
	      t->next=p->next;
		 
		}
		 else  if(strcmp(p->bookname,str)==0&&p->next==NULL)
		   {
		     t=NULL;
		     
		   }

}

return h;
}

link *revamp(link *head)
{
	link *h,*t;
	h=head;
	
	t=findboookname(h);
	if(t==NULL)
	printf("没有找到……");
	else
	{
		        printf("修改前图书信息为：");
   				printf("\n");
                printf("\n**************************************************\n");
            	printf("\n编号\t\t书名\t\t作者\t\t出版社\t\t出版时间\t\t价格\t\t状态\n"); 
            	
	            printf("\n");
	        	printf("%s\t%s\t%s\t%s\t%s",t->number,t->bookname,t->author,t->publish,t->time);
	        	printf("\t\t%.2f",t->price);
	        	printf("\t\t%s",t->status);
	        	printf("\n");
	}
    
	 printf("请输入这本书的（除书名外）所有信息：\n");
     printf("\n**************************************************\n");
	 printf("\n编号\t\t作者\t\t出版社\t\t出版时间\t\t价格\t\t状态\n"); 
	 printf("\n");
	 scanf("%s%s%s%s",t->number,t->author,t->publish,t->time);
	 scanf("%f",&t->price);
	 scanf("%s",t->status);
	 printf("修改后图书信息为：");
	 printf("\n");
     printf("\n**************************************************\n");
 	 printf("\n编号\t\t书名\t\t作者\t\t出版社\t\t出版时间\t\t价格\t\t状态\n"); 
            	
     printf("\n");
 	 printf("%s\t%s\t%s\t%s\t%s",t->number,t->bookname,t->author,t->publish,t->time);
 	 printf("\t\t%.2f",t->price);
 	 printf("\t\t%s",t->status);
 	 printf("\n");
	 
	 return head;
    }
    

link *borrowbook(link *head)
{
	link *h,*p;
	char ch,ch1[100]="在库",ch2[100]="不在库";
	h=head;
	
	printf("\n**************************************************\n");
	printf("\t\t欢迎使用借书系统!!!\n");
	p=findboookname(h);
	if(p==NULL)
	printf("借书失败，书库中没有这本书！！！");
	else if(strcmp(p->status,ch2)==0)
	printf("借书失败，图书不在库！！！");
	else 
	{
	printf("确认借出？Y/N:");
	scanf("%c",&ch);
	getchar(); 
	if(ch=='Y'||ch=='y')
	{   
	    strcpy(p->status,ch2); 
		printf("借书成功，请返回上级菜单保存信息！！！");
	    
	}
	if(ch=='N'||ch=='n')
	{
		printf("你没有借任何书！！！"); 
	}
	
	} 
return head; 

} 

 link *returnbook(link *head)
 {
 	link *h,*p;
 	char ch,ch1[100]="在库",ch2[100]="不在库";
 	h=head;
 	printf("\n**************************************************\n");
	printf("\t\t欢迎使用还书系统!!!\n");
	p=findboookname(h);
	if(p==NULL)
	printf("还书失败，这不是本书库的书！！");
    else
    {
    	printf("确认还书？Y/N:");
    	scanf("%c",&ch);
	    getchar(); 
	   if(ch=='Y'||ch=='y')
	   {   
	    strcpy(p->status,ch1); 
		printf("还书成功，请返回上级菜单保存信息！！！");
	    
	   }
	      if(ch=='N'||ch=='n')
	  {
	    	printf("你没有还书！！！"); 
	  }
     }
 	return head;
 }

