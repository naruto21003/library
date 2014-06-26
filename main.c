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
link *Cbook();
void mainmenu();
void menu1();
void glmenu();
void cxmenu();
void jhmenu();
void print(link *head);
void  hold(link *head);
void holdcx(link *t);
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
