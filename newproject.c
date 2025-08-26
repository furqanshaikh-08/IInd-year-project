#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<math.h>
#include <stdlib.h>
//function declaration
void Staff();void admin();void category();
void nexon();void bill();void billing();
void tigor();void altroz();void emi();
void cash();void free_acc();void extra_acc();
void quota();int details();void admin_cat();
void customer();
//static variables
struct node
{
  long int price;
  int rto;
  int ins;
  int acc;  
}s1,s2,s3;
struct car
{
   char cname[30];
   float arai;
   int ed,cd,crd;  
}e;
struct detail
{
  int cid;
  char cs[30],car[20];
  char adr[50],md[10];
   double mb;  
}h;
char another;
FILE *fp,*ftemp,*p;
int ch,cr;
char c;
long int pr;
char fuel[20],type[20],color[20];
//code start
int main()
{
   
    while(1)
   {
   printf("\n1.Staff  2.Admin  3.Exit");
   printf("\nEnter your choice:");
   scanf("%d",&ch);
   switch(ch)
   {
      case 1:system("cls");
      Staff();
	     break;
      case 2:system("cls");
      admin();
	     break;
      case 3:exit(1);
      default:printf("\nEnter correct choice");
   }
   }
}
void Staff()
{
  char us[20];
  int ps;
    printf("\nWelcome to Login");
    printf("\nEnter username:");
    scanf("%s",us);
    printf("Enter password:");
    scanf("%d",&ps);
    if(strcmp(us,"staff")==0 && ps==123)
    {
      printf("\n    Staff Login successful!!");
      category();
    }
    else
    {
      printf("\nInvalid Details!!\n");
    }
}
void admin()
{ 
    char us[20];
    int ps;
    printf("\nWelcome to Admin Login");
    printf("\nEnter username:");
    scanf("%s",us);
    printf("Enter password:");
    scanf("%d",&ps);
    if(strcmp(us,"admin")==0 && ps==123)
    {
      printf("\nAdmin Login successful!!\n");
      admin_cat();
    }
    else
    {
      printf("\nInvalid Details!!\n");
    }
}
void admin_cat()
{
 int recordsize=sizeof(e);
	int ch,found=0,eid;
  char another;
    there:
	printf("\nPerform Operations On:");
  printf("\n1.Car section  2.Customer section");
  printf("\nEnter your choice:");
  scanf("%d",&ch);
  switch(ch)
  {
   case 1:this:
         printf("\n1.Sedan   2.SUV  3.Hatchback");
       	printf("\nEnter your choice:");
	scanf("%d",&ch);
	if(ch==1)
	{
		fp=fopen("sedan.txt","ab+");//Opening the file in read binary mode
                	if(fp==NULL)//no records to read i.e., file is empty
		         {
		      fp=fopen("sedan.txt","ab+");//Opening file in write binary mode
		    if (fp==NULL)
			{
		    printf("\nProblems in opening file.... Exiting..");
			getch();
			exit(1);
			}
		}
	}
	else if(ch==2)
	{
		fp=fopen("suv.txt","ab+");//Opening the file in read binary mode
                	if(fp==NULL)//no records to read i.e., file is empty
		         {
		      fp=fopen("suv.txt","ab+");//Opening file in write binary mode
		    if (fp==NULL)
			{
		    printf("\nProblems in opening file.... Exiting..");
			getch();
			exit(1);
			}
		}
	}
	else if(ch==3)
	{
		fp=fopen("hatch.txt","ab+");//Opening the file in read binary mode
                	if(fp==NULL)//no records to read i.e., file is empty
		         {
		      fp=fopen("hatch.txt","ab+");//Opening file in write binary mode
		    if (fp==NULL)
			{
		    printf("\nProblems in opening file.... Exiting..");
			getch();
			exit(1);
			}
		} 
	}
	else
	{
		 printf("\nEnter correct choice");
     goto this;
		 return;
	}
	while(1)
	{
    here: 
    printf("\n\n1.Add  2.Update  3.Delete  4.close  5.Back to menu");
    printf("\nEnter your choice");
    scanf("%d",&ch);
    switch(ch)
    {
         case 1:another='y';
				 while(another=='y' || another=='Y')
					{
				  printf("\nEnter car id:");
          scanf("%d",&e.crd);
        	printf("\nEnter car name:");
				  scanf("%s",e.cname);
					printf("\nEnter car mileage:");
					scanf("%f",&e.arai);
         	printf("\nEnter Engine Displacement:");
					scanf("%d",&e.ed);
          printf("\nEnter No of Cylinders:");
					scanf("%d",&e.cd);
    				//storing data in file
					fwrite(&e,sizeof(e),1,fp);
					printf("\nAdd another record(y/n)?");
					another=getche();
					}
          goto here;
					break;
			case 2://Updating car details
				another='y';
				while(another=='y')
					{
					printf("\nEnter the car id to modify:");
					scanf("%d",eid);
					rewind(fp);
					while(fread(&e,sizeof(e),1,fp)==1)
						{
						if(eid==e.crd)//records match
							{
						    	printf("\nEnter car id:");
                  scanf("%d",&e.crd);
                  printf("\nEnter car name:");
				        	scanf("%s",e.cname);
				        	printf("\nEnter car mileage:");
				        	scanf("%f",&e.arai);
         	                printf("\nEnter Engine Displacement:");
				        	scanf("%d",&e.ed);
                 		    printf("\nEnter No of Cylinders:");
							scanf("%d",&e.cd);
							fseek(fp,-recordsize,1);//moving fp to current record
							fwrite(&e,recordsize,1,fp);
							break;
							}

						}
					printf("\nModify another record(y/n)?");
					another=getche();
					}
          goto here;
				break;
			case 3://delete car details
				another='y';
				while(another=='y')
					{
					printf("\nEnter name of car to delete:");
					scanf("%s",eid);
					ftemp=fopen("temp.txt","wb");
					rewind(fp);
					while(fread(&e,recordsize,1,fp))
						{
						if(eid==e.crd)
							{
							fwrite(&e,recordsize,1,ftemp);
							}
						 else
						    {
						       found=1;
						       printf("\nMatch found. Deleted");
						     }
						  }
					fclose(fp);
					fclose(ftemp);
					remove("suv.txt");
					rename("temp.txt","suv.txt");
					fp=fopen("suv.txt","rb+");
					printf("\nDelete another record(y/n)?");
					another=getche();
					}
          goto here;
					break;
				case 4:
					fclose(fp);
          goto here;
          break;
        case 5:return;  
				case 6:rewind(fp);
				while(fread(&e,sizeof(e),1,fp)==1)
					{
					        printf("\nCar Id:%d",e.crd);
                  printf("\nCar name:%s",e.cname);
				        	printf("\nCar mileage:%f",e.arai);
         	        printf("\nEngine Displacement:%d",e.ed);
                 	printf("\nNo of Cylinders:%d\n",e.cd);
					}
				getch();
        goto here;
				break;
    default:printf("\nEnter correct choice");
             goto here;
	}
  break;
  case 2:fp=fopen("cust.txt","rb");
      if(fp==NULL)
		  {
        printf("\nNo records present\n");
        goto there;
      }
      printf("\n\t\t   ---Customer Details---");
      printf("\nId\tName\t\tnumber\t\taddress\t\tcar name");
      printf("\n--------------------------------------------------------------------");
    while(fread(&h,sizeof(h),1,fp)==1)
	{
      printf("\n%d\t%s\t\t%.lf\t%s\t\t%s",h.cid,h.cs,h.mb,h.adr,h.car);
  }
  printf("\n--------------------------------------------------------------------\n");
  fclose(fp);
  goto there;
  break;
  case 3: return;
  default:printf("\nWrong choice");
          goto there;
  }
}
}
void category()
{
  printf("\n\n Please select category of cars");
  printf("\n    1.Sedan  2.SUV  3.Hatchback");
  printf("\n  ----Which one would you like----:");
  scanf("%d",&ch);
  switch(ch)
  {
    case 1:tigor();  
	         break;
    case 2:nexon();
	         break;
    case 3:altroz();
      	   break;
    case 4:return;
    default:printf("\nSelect correct category");
            category();
  }
}
//Second car
void nexon()
{
  cr=2;
  p=fopen("suv.txt","rb");
  if(p==NULL)
  {
     printf("\nCar is not Available\n");
     category();
  }
  else{
  rewind(p);//going to start of file
  
	while(fread(&e,sizeof(e),1,p)==1)//reading the file contents
	{
		 printf("\n ---------------------------------------");
     printf("\n|      Car Id:%d\t\t\t\t|",e.crd);
     printf("\n|    Car name:%s\t\t|",e.cname);
		 printf("\n|    Car mileage(kmpl):%f\t|",e.arai);
     printf("\n|    Engine Displacement(cc):%d\t|",e.ed);
     printf("\n|    No of Cylinders:%d\t\t\t|",e.cd);
     printf("\n ---------------------------------------");
	}
 fclose(p);
  t:
  printf("\n\n----Select Variant----");
  printf("\n1.Base model   2.Pro model :");
  scanf("%d",&ch);
  switch(ch)
  {
     case 1:s1.price+=4000;
             break;
     case 2:s1.price+=10000;
            break;
     default:printf("\nWrong Choice");
     goto t;
  }
  t1:
  printf("\n\n +++  Select fuel type  +++");
  printf("\n 1.EV  2.Diesel  3.Petrol :");
  scanf("%d",&ch);
  switch(ch)
  {
  case 1:s2.price+=50000;
  strcpy(fuel,"EV");
	 break;
  case 2:s2.price+=20000;
  strcpy(fuel,"Diesel");
	 break;
  case 3:s2.price+=30000;
  strcpy(fuel,"Petrol");
	 break;
  default:printf("\nEnter correct choice");
          goto t1;
  }
  t2:
  printf("\n  +++ Select Gear Type +++");
  printf("\n   1.Automatic  2.Manual :");
  scanf("%d",&ch);
  switch(ch)
  {
    case 1:s2.price+=40000;
          strcpy(type,"Automatic");
          break;
    case 2:s2.price+=4000;
           strcpy(type,"Manual");
          break;
    default:printf("\nEnter correct choice");
             goto t2;
  }
  t3:
  printf("\n  +++ Select color of car +++  ");
  printf("\n1.Red  2.Black  3.White  4.Grey :");
  scanf("%d",&ch);
  switch(ch)
  {
    case 1:s2.price+=5000;
           strcpy(color,"Red");
	         break;
    case 2:s2.price+=2000;
           strcpy(color,"Black");
	         break;
    case 3:s2.price+=3000;
           strcpy(color,"White");
	         break;
    case 4:s2.price+=4000;
           strcpy(color,"Grey");
	         break;
    default:printf("\nEnter correct option");
           goto t3;
  }
  }
  printf("\nGo to bill section(y/n):\n");
  c=getche();
  if(c=='y' || c=='Y')
  {
  bill();
  }
  else
  {
    category();
  }
}
//Third Car
void altroz()
{
  cr=3;
  p=fopen("hatch.txt","rb+");
  if(p==NULL)
  {
     printf("\nCar is not Available\n");
    category();
  }
  else{
  rewind(p);//going to start of file
	while(fread(&e,sizeof(e),1,p)==1)//reading the file contents
	{
		 printf("\n ---------------------------------------");
     printf("\n|      Car Id:%d\t\t\t\t|",e.crd);
     printf("\n|    Car name:%s\t\t|",e.cname);
		 printf("\n|    Car mileage(kmpl):%f\t|",e.arai);
     printf("\n|    Engine Displacement(cc):%d\t|",e.ed);
     printf("\n|    No of Cylinders:%d\t\t\t|",e.cd);
     printf("\n ---------------------------------------");
	}
  fclose(p);
  t:
  printf("\n\n----Select Variant----");
  printf("\n1.Base model   2.Pro model :");
  scanf("%d",&ch);
  switch(ch)
  {
     case 1:s1.price+=4000;
             break;
     case 2:s1.price+=10000;
            break;
     default:printf("\nWrong Choice");
     goto t;
  }
  t1:
  printf("\n +++Select fuel type+++");
  printf("\n 1.EV  2.Diesel  3.Petrol :");
  scanf("%d",&ch);
  switch(ch)
  {
  case 1:s1.price+=50000;
  strcpy(fuel,"EV");
	 break;
  case 2:s1.price+=20000;
  strcpy(fuel,"Diesel");
	 break;
  case 3:s1.price+=30000;
  strcpy(fuel,"Petrol");
	 break;
  default:printf("\nEnter correct choice");
       goto t1;
  }
  t2:
  printf("\n  +++ Select Gear Type +++");
  printf("\n   1.Automatic  2.Manual :");
  scanf("%d",&ch);
  switch(ch)
  {
    case 1:s3.price+=28000;
          strcpy(type,"Automatic"); 
          break;
    case 2:s3.price+=3000;
           strcpy(type,"Manual");
          break;
    default:printf("\nEnter correct choice");
          goto t2;
  }
  t3:
  printf("\n  +++ Select color of car +++");
  printf("\n1.Orange  2.Blue  3.Black  4.White :");
  scanf("%d",&ch);
  switch(ch)
  {
    case 1:s3.price+=5000;
           strcpy(color,"Orange");
	         break;
    case 2:s3.price+=2000;
           strcpy(color,"Blue");
	         break;
    case 3:s3.price+=3000;
           strcpy(color,"Black");
	         break;
    case 4:s3.price+=4000;
           strcpy(color,"White");
	         break;
    default:printf("\nEnter correct option");
                 goto t3;
  }
  printf("\nGo to bill section(y/n):\n");
  c=getche();
  if(c=='y' || c=='Y')
  {
  bill();
  }
  else
  {
    category();
  }
  }
}
//First car
void tigor()
{
  cr=1;
  p=fopen("sedan.txt","rb");
  if(p==NULL)
  {
     printf("\nCar is not Available\n");
     category(); 
  }
  else{
  rewind(p);//going to start of file
	while(fread(&e,sizeof(e),1,p)==1)//reading the file contents
	{
		printf("\n ---------------------------------------");
     printf("\n|      Car Id:%d\t\t\t\t|",e.crd);
     printf("\n|    Car name:%s\t\t|",e.cname);
		 printf("\n|    Car mileage(kmpl):%f\t|",e.arai);
     printf("\n|    Engine Displacement(cc):%d\t|",e.ed);
     printf("\n|    No of Cylinders:%d\t\t\t|",e.cd);
     printf("\n ---------------------------------------");
	}
  fclose(p);
  t:
  printf("\n\n----Select Variant----");
  printf("\n1.Base model   2.Pro model :");
  scanf("%d",&ch);
  switch(ch)
  {
     case 1:s1.price+=4000;
             break;
     case 2:s1.price+=10000;
            break;
     default:printf("\nWrong Choice");
     goto t;
  }
  t1:
  printf("\n\n +++  Select fuel type  +++");
  printf("\n 1.CNG  2.Diesel  3.Petrol :");
  scanf("%d",&ch);
  switch(ch)
  {
  case 1:s1.price+=23000;
  strcpy(fuel,"CNG");
	 break;
  case 2:s1.price+=18000;
  strcpy(fuel,"Diesel");
	 break;
  case 3:s1.price+=15000;
  strcpy(fuel,"Petrol");
	 break;
  default:printf("\nEnter correct choice");
          goto t1;
  }
  t2:
  printf("\n  +++ Select Gear Type +++");
  printf("\n   1.Automatic  2.Manual :");
  scanf("%d",&ch);
  switch(ch)
  {
    case 1:s1.price+=28000;
          strcpy(type,"Automatic"); 
          break;
    case 2:s1.price+=3000;
           strcpy(type,"Manual");
          break;
    default:printf("\nEnter correct choice");
           goto t2;
  }
  t3:
  printf("\n  +++ Select color of car +++");
  printf("\n1.Orange  2.Blue  3.Black  4.White :");
  scanf("%d",&ch);
  switch(ch)
  {
    case 1:s1.price+=5000;
           strcpy(color,"Orange");
	         break;
    case 2:s1.price+=2000;
           strcpy(color,"Blue");
	         break;
    case 3:s1.price+=3000;
           strcpy(color,"Black");
	         break;
    case 4:s1.price+=4000;
           strcpy(color,"White");
	         break;
    default:printf("\nEnter correct option");
            goto t3;
  }
  printf("\nGo to bill section(y/n):\n");
  c=getche();
  if(c=='y' || c=='Y')
  {
  bill();
  }
  else
  {
    category();
  }
  }
}
void bill()
{
   printf("\nEnter customer details\n");
   details(); 
   printf("\n\n+++Welcome to Billing Section+++");
   printf("\n    Choose a Payment option");
   printf("\n   <<<<< 1.Cash  2.EMI >>>>> :");
   scanf("%d",&ch);
   switch(ch)
   {
      case 1:cash();
	      break;
      case 2:emi();
	     break;
      case 3:exit(1);
      default:printf("\nPlease enter correct option");
   }
}
int details()
{
   fp=fopen("cust.txt","ab+");
   p=fopen("customer.txt","wb+");
   printf("          Customer Id:");
   scanf("%d",&h.cid);
   printf("        Customer name:");
   scanf("%s",h.cs);
   printf("   Customer mobile no:");
   scanf("%lf",&h.mb);
   printf("     Customer address:");
   scanf("%s",h.adr);
   printf("       Selected car:");
   scanf("%s",h.car);
   fwrite(&h,sizeof(h),1,p);
   fwrite(&h,sizeof(h),1,fp);
   fclose(fp);
   fclose(p);
}
void customer()
{
   fp=fopen("customer.txt","rb");
      if(fp==NULL)
		  {
        printf("\nNo records present\n");
      }
    while(fread(&h,sizeof(h),1,fp)==1)
	{
			
      printf("\n       Customer Id:%d",h.cid);
      printf("\n     Customer name:%s",h.cs);
			printf("\nCustomer mobile no:%.lf",h.mb);
      printf("\n  Customer address:%s\n",h.adr);
      printf("       Selected car:%s",h.car);
  }
  fclose(fp);
}
void cash()
{
  int tl;
  billing();
  printf("\nWant to display bill(y/n):\n");
  c=getche();
  if(c=='y' || c=='Y')
  {
  printf("\n\n-------------CASH--------------");
  if(cr==1)
  {
   customer();
  fp=fopen("cash.txt","rb");
  rewind(fp);
				while(fread(&s1,sizeof(s1),1,fp)==1)
					{
					   printf("\nEx-Showroom price:%d",s1.price);
             printf("\n              RTO:%d",s1.rto);
             printf("\n        Insurance:%d",s1.ins);
             printf("\n Accessories pack:%d",s1.acc);  
					}
          tl=s1.price+s1.acc+s1.ins+s1.rto;
          printf("\n      Total amount:%d\n",tl);
    fclose(fp);
  }
  else if(cr==2)
  {
    customer();
  fp=fopen("cash.txt","rb+");
  rewind(fp);
				while(fread(&s2,sizeof(s2),1,fp)==1)
					{
					   printf("\n  Ex-Showroom price:%d",s2.price);
             printf("\n                RTO:%d",s2.rto);
             printf("\n          Insurance:%d",s2.ins);
             printf("\n   Accessories pack:%d",s2.acc);  
					}
          tl=s2.price+s2.acc+s2.ins+s2.rto;
          printf("\n        Total amount:%d\n",tl);    
    fclose(fp);
  }
  else
  {
    customer();
  fp=fopen("cash.txt","rb+");
  rewind(fp);
				while(fread(&s3,sizeof(s3),1,fp)==1)
					{
					   printf("\n  Ex-Showroom price:%d",s3.price);
             printf("\n                RTO:%d",s3.rto);
             printf("\n          Insurance:%d",s3.ins);
             printf("\n   Accessories pack:%d",s3.acc);  
					}
          tl=s3.price+s3.acc+s3.ins+s3.rto;
          printf("\n        Total amount:%d\n",tl);
    fclose(fp);
  }
  }
  else{
    printf("\nThank You\n");
    category();
  }
}
void emi()
{
  float tt,tm,emi,rt=8.7;
  billing();
  printf("\nEnter time in year:");
  scanf("%f",&tm);
  rt=rt/(12*100);
  tm=tm*12;
  emi=(pr*rt*pow(1+rt,tm))/(pow(1+rt,tm)-1);
  tt=emi*tm;
  printf("\nWant to display bill(y/n):");
  c=getche();
  if(c=='y' || c=='Y')
  {
  printf("\n\n -------------EMI--------------");
  customer();
  printf("\n        Monthly EMI:%f",emi);
  printf("\nTotal amount with interest:%f\n",tt);
}
else{
  printf("\nThank You\n");
  category();
}
}
void billing()
{
  p=fopen("cash.txt","wb+");
  if(cr==1)
  {
   s1.price=800000;
   s1.rto=38928;
   s1.ins=27222;
   s1.acc=3500;
   pr=s1.price+s1.rto+s1.ins+s1.acc;
   fwrite(&s1,sizeof(s1),1,p);
  }
  else if(cr==2)
  {
   s2.price=600000;
   s2.rto=38928;
   s2.ins=27222;
   s2.acc=3500;
   fwrite(&s2,sizeof(s2),1,p);
   pr=s2.price+s2.rto+s2.ins+s2.acc;
  }
  else
  {
   s3.price=1000000;
   s3.rto=38928;
   s3.ins=27222;
   s3.acc=3500;
   pr=s3.price+s3.rto+s3.ins+s3.acc;
   fwrite(&s3,sizeof(s3),1,p);
  }
  fclose(p);
}
