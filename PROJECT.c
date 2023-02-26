#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
void login();
void signin();
void admin();
void userenqhis(char*);
int userloginck(char*);
void carenq(char*);
void userprt(char*);
void randomcovid();
void queries();
void qr1();
void qr2();
void qr3();
void qr4();
void qr5();
void qr6();
int adminlogck(char* ,char*);
void addadmin();
void enqprt();
void userdetailsprt();
int cardetailsprt();
int check(char*);
int addcars();
//structures 
struct userdetails{
	char username[50];
	char password[50];
	char email[50]; 
	char age[4];
	char mobile[15];
	char state[15];
};

struct admindetails{
	char adminname[25];
	char adminpassword[25];
};

struct cars{
	char carname[25];
	char carmodel[25];
	char seating[5];
	char fuel[10];
	char body[10];
	char price[10];
	char trans[10];
	char sanitate[10];
	char purify[10];
	char bact[10];
};

struct enq{
	char username[30];
	char carname[30];
	char price[10];
	char seating[5];
	char body[10];
	char fuel[10];
	char trans[10];
	char sanitate[10];
	char purify[10];
	char bact[10];
};

int main(){
	int ch,key,sam;
	
	do {
		ch=0;
		printf("\n1) Login \n2) Sign In \n3) Admin \n4) Exit\nEnter Choice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				login();
				break;
			
			case 2:
				signin();
				break;
				
			case 3:
				admin();
				break;
		}
	}while(ch!=4);
	printf("THANK YOU. HAVE A NICE DAY");	
}

//this funtion is used to login USERS 
void login(){
	char user[25];
	int check;
	printf("Enter User Name: ");
	scanf("%s[^\n]",&user);
	check=userloginck(user);
	if(check==0){
			randomcovid();
			int ch;
			do{
			printf("\nEnter Choice: \n");
			printf("1) Car Enquiry\n");
			printf("2) User Details\n");
			printf("3) Enquiry History\n");
			printf("4) EXIT\n");
			scanf("%d",&ch);
			switch(ch)
			{
				case 1:
					carenq(user);
					break;
				
				case 2: 
					userprt(user);
					break;
				case 3:
					userenqhis(user);
					break;
			}
		}while(ch!=4);
	}
}

//this function is used to validated user login
int userloginck(char user[25]){
	int s=0,k=0,compare;
	struct userdetails var;
	FILE *fp;
	fp=fopen("user.txt","r");

	while(fread(&var,sizeof(struct userdetails),1,fp))
		{
			compare=strcmp(var.username,user);//compare===0 then only both will be same
			if(compare==0)
			{	
			    s=1;
			    char pass[25];
				printf("Enter Password : ");
				scanf("%s",&pass);
				compare=strcmp(var.password,pass);
				if(compare==0){
					s=2;
					k=1;
					printf("Hello %s ",user);
					fclose(fp);
					return 0;
				}
			}
		}
		fclose(fp);
		if(k!=1){	
		if(s==0)
			{
				printf("\nUser name doesnot exit.\n");
				return 1;
			}	
		else if(s==1)
			{ 	printf("\nUser name and password doesn't Match. Please Try again\n\n");
				printf("Forgot Password? Please enter following to retrive password\n");
				fp=fopen("user.txt","r");
				char email1[30],mobile1[30];
				printf("Enter Email : ");
				scanf("%s",&email1);
				printf("Enter mobile number : ");
				scanf("%s",&mobile1);
				int k=0;
				while(fread(&var,sizeof(struct userdetails),1,fp))
					{
						compare=strcmp(var.username,user);
						if(compare==0)
						{
							int comp;
							comp=strcmp(var.mobile,mobile1);
							compare=strcmp(var.email,email1);
							if(comp==0&&compare==0){
								k=1;
								printf("Password is : %s",var.password);
								break;
							}
						}
					}
					if(k!=1){
						printf("WRONG Email and Mobile Number");
					}
					fclose(fp);
					return 1;
			}
		}
}

//this funtion is for car enquiry 
void carenq(char user[25]){
	char carname[20]="",body[10]="",seating[5]="",price[7]="",fuel[10]="",trans[10]="",sanitate[7]="",purify[7]="",bact[7]="";
	int ch,ck,ch1,compare1,so=1;

	do{
		printf("\nEnter to apply filter\n");
		printf("1) Car Name      %s\n",carname);
		printf("2) Body Type     %s\n",body);
		printf("3) Fuel Type     %s\n",fuel);
		printf("4) Transmission  %s\n",trans);
		printf("5) Price Range   %s\n",price);
		printf("6) Seating       %s\n",seating);
		printf("7) Health Features : \n");
		compare1=strcmp(sanitate,"");
		if(compare1!=0){
			printf("\t \t  %d) In Built sanitation \n",so);
			so++;
		}
		compare1=strcmp(purify,"");
		if(compare1!=0){
			printf("\t \t  %d) Enhanced Air-Purification \n",so);
			so++;
		}
		compare1=strcmp(bact,"");
		if(compare1!=0){
			printf("\t \t  %d) Anti-Bacterial surface \n",so);
			so++;
		}
		printf("8) Apply Filter \n");
		scanf("%d",&ch);
		switch(ch){
			case 1:
					printf("\nEnter Car Name : ");
					scanf("%s[^\n]",&carname);
				break;
				
			case 2:
					do{
						printf("Select Body Type: \n1. SUV \n2. Sedan \n");
						scanf("%d",&ch);
						if(ch==1){
							strcpy(body,"SUV");
							ck=0;
							
						}
						else if(ch==2){
							strcpy(body,"SEDAN");
							ck=0;
						}
						else{
							printf("Wrong Input. \n");
							ck=1;
						}
					}while(ck==1);
			        break;
		
			case 3:
					do{
						printf("Select Fuel Type: \n1. Petrol \n2. Diesel \n3. Electric \n4. CNG \n");
						scanf("%d",&ch);
						if(ch==1){
							strcpy(fuel,"PETROL");
							ck=0;
						}
						else if(ch==2){
							strcpy(fuel,"DIESEL");
							ck=0;
						}
						else if(ch==3){
							strcpy(fuel,"ELECTRIC");
							ck=0;
						}
						else if(ch==4){
							strcpy(fuel,"CNG");
							ck=0;
						}
						else{
							printf("Wrong Input. \n");
							ck=1;
						}
					}while(ck==1);					
				    break;
		 
			case 4:
					do{
						printf("Select Transmission Type: \n1. Automatic \n2. Manual \n");
						scanf("%d",&ch);
						if(ch==1){
							strcpy(trans,"AUTOMATIC");
							ck=0;
						}
						else if(ch==2){
							strcpy(trans,"MANUAL");
							ck=0;
						}
						else{
							printf("Wrong Input. \n");
							ck=1;
						}
					}while(ck==1);
				    break;
		
			case 5:
					do{
						printf("Select Price Range: \n1. 8-12 Lakhs \n2. 12-18 Lakhs \n");
						scanf("%d",&ch);
						if(ch==1){
							strcpy(price,"8-12");
							ck=0;
						}
						else if(ch==2){
							strcpy(price,"12-18");
							ck=0;
						}
						else{
							printf("\nWrong Input. \n");
							ck=1;
						}
					}while(ck==1);
								
				    break;
		
			case 6:
					do{
						printf("Select seating capacity : \n1. 5 \n2. 7 \n3. 9 \n");
						scanf("%d",&ch);
						if(ch==1||ch==5){
							strcpy(seating,"5");
							ck=0;
						}
						else if(ch==2||ch==7){
							strcpy(seating,"7");
							ck=0;
						}
						else if(ch==3||ch==9){
							strcpy(seating,"9");
							ck=0;
						}
						else{
							printf("Wrong Input. \n");
							ck=1;
						}
					}while(ck==1);
				    break;
					
			
			case 7:
					do{
						printf("\nEnter choice :\n");
						printf("1) In Built sanitation          %s\n",sanitate);
						printf("2) Enhanced Air-Purification    %s\n",purify);
						printf("3) Anti-Bacterial surface       %s\n",bact);
						printf("4) EXIT\n");
						scanf("%d",&ch1);
						switch(ch1){
							case 1:
									do{
										printf("In Built sanitation: \n1. YES \n2. NO \n");
										scanf("%d",&ch);
										if(ch==1){
											strcpy(sanitate,"YES");
											ck=0;
										}
										else if(ch==2){
											strcpy(sanitate,"NO");
											ck=0;
										}
										else{
											printf("Wrong Input. \n");
											ck=1;
												}
									}while(ck==1);
									break;
							case 2:
									do{
										printf("Enhanced Air-Purification : \n1. YES \n2. NO \n");
										scanf("%d",&ch);
										if(ch==1){
											strcpy(purify,"YES");
											ck=0;
										}
										else if(ch==2){
											strcpy(purify,"NO");
											ck=0;
										}
										else{
											printf("Wrong Input. \n");
											ck=1;
										}
									}while(ck==1);
									break;
							case 3:
									do{
										printf("Anti-Bacterial surface : \n1. YES \n2. NO \n");
										scanf("%d",&ch);
										if(ch==1){
											strcpy(bact,"YES");
											ck=0;
										}
										else if(ch==2){
											strcpy(bact,"NO");
											ck=0;
										}
										else{
											printf("Wrong Input. \n");
											ck=1;
										}
									}while(ck==1);
							}
						}while(ch1!=4);
					    break;	    
		}
			if(ch==8){
						struct enq en;
						strcpy(en.bact,bact);
						strcpy(en.body,body);
						strcpy(en.carname,carname);
						strcpy(en.fuel,fuel);
						strcpy(en.price,price);
						strcpy(en.purify,purify);
						strcpy(en.sanitate,sanitate);
						strcpy(en.seating,seating);
						strcpy(en.trans,trans);
						strcpy(en.username,user);
						FILE *fp;
						fp=fopen("enq.txt","a");
						fwrite(&en,sizeof(struct enq),1,fp);
						fclose(fp);
						
						int set,compare,comp;
						struct cars var;
						FILE *tp;
						tp=fopen("cars.txt","r");
						printf("CAR_NAME        MODEL_NAME      BODY     FUEL       TRASNSMISSION      SEATING    PRICE   IB _SANITAION   EN_AIR-PURI   AB_SURFACE\n");
						while(fread(&var,sizeof(struct cars),1,tp))
						{	
							
							compare=strcmp(var.body,en.body);
							comp=strcmp(en.body,"");
							if(comp==0){
								compare=0;
							}
							if(compare==0){
								compare=strcmp(var.carname,en.carname);
								comp=strcmp(en.carname,"");
								if(comp==0){
									compare=0;
								}
								if(compare==0){
										compare=strcmp(var.fuel,en.fuel);
										comp=strcmp(en.fuel,"");
										if(comp==0){
											compare=0;
										}
										if(compare==0){
											compare=strcmp(var.trans,en.trans);
											comp=strcmp(en.trans,"");
											if(comp==0){
											compare=0;
											}
											if(compare==0){
												compare=strcmp(var.price,en.price);
												comp=strcmp(en.price,"");
												if(comp==0){
													compare=0;
												}
												if(compare==0){
													compare=strcmp(var.seating,en.seating);
													comp=strcmp(en.seating,"");
													if(comp==0){
													compare=0;
													}
													if(compare==0){
														compare=strcmp(var.sanitate,en.sanitate);
														comp=strcmp(en.sanitate,"");
														if(comp==0){
															compare=0;
														}
														if(compare==0){
															compare=strcmp(var.purify,en.purify);
															comp=strcmp(en.purify,"");
															if(comp==0){
																compare=0;
															}
															if(compare==0){
																	compare=strcmp(var.bact,en.bact);
																	comp=strcmp(en.bact,"");
																	if(comp==0){
																		compare=0;
																		}
																	if(compare==0){
																		printf("%-15s %-15s %-8s %-11s %-20s %-7s %-12s %-14s %-12s %-5s\n",var.carname,var.carmodel,var.body,var.fuel,var.trans,var.seating,var.price,var.sanitate,var.purify,var.bact);					
																	}
															}
														}
																														
													}
												}
											}	
								
										}
								}
							}
						
						}
						fclose(fp);
						
				}
		}while(ch!=8);
}

//this funtion is used to show the users enquiry history ( what ever enquiry a specific uer made)
void userenqhis(char user[25]){
	int compare;
	struct enq en;
	FILE *fp;
	fp=fopen("enq.txt","r");
	printf("USER_NAME        CAR_NAME      BODY     FUEL       TRASNSMISSION      SEATING    PRICE   IB _SANITAION   EN_AIR-PURI   AB_SURFACE\n");
	while(fread(&en,sizeof(struct enq),1,fp)){
		compare=strcmp(en.username,user);
		if(compare==0)
		{
			printf("%-15s %-15s %-8s %-11s %-20s %-7s %-12s %-14s %-12s %-5s\n",en.username,en.carname,en.body,en.fuel,en.trans,en.seating,en.price,en.sanitate,en.purify,en.bact);
		}
	}
	fclose(fp);
}

//when logged in the users will get a random message covid related
void randomcovid(){
		char *covidPtr[10]={"BE INFORMED. BE SAFE. BE SMART. BE SAFE.",
	   "SPREAD FACTS, NOT FEAR.",
	   "I PROTECT YOU, YOU PROTECT ME!",
	   "BE KIND TO SUPPORT LOVED ONES DURING #CORONAVIRUS",
	   "STAY ALERT, CONTROL THE VIRUS, SAVE LIVES",
	   "WEAR A MASK SAVE A LIFE",
	   "BE SMART. STAY 6 FEET APART.",
	   "LIMIT CONTACT TO 10 MIN, STOP THE SPREAD",
	   "WE ARE TOGETHER EVEN IF WE CAN'T HOLD HANDS RIGHT NOW",
	   "STAY HOME STAY SAFE"};
	    int c,ch;
	    srand(time(NULL));
	    ch=(rand() % 10);
		c=0;
	    while(*(covidPtr[ch] + c) != '\0') {
	      printf("%c", *(covidPtr[ch] + c));
	      c++;
	    }
	    printf("\n");
}

//this is for user to print their data
void userprt(char user[25]){
			struct userdetails var;
			FILE *fp;
			int compare;
			fp=fopen("user.txt","r");
			printf("USER NAME            PASSWORD             EMAIL                MOBILE NUMBER       AGE     STATE\n\n");
			while(fread(&var,sizeof(struct userdetails),1,fp))
			{
				compare=strcmp(var.username,user);
				if(compare==0)
				{
					printf("%-20s %-20s %-20s %-20s %-6s %-15s\n",var.username,var.password,var.email,var.mobile,var.age,var.state);
				}
			}
			fclose(fp);
}

//this is used to sign in whic means new user can enter their data to enroll themselves
void signin(){
	int compare,same=0;
	char user[25],password[25],password1[25],email[30],number[15];   
	FILE *fp;
	struct userdetails var;
	fp=fopen("user.txt","a");
	do{
		printf("Enter the User Name : ");
		scanf("%s[^\n]",&user);
		same=check(user);
		
	}while(same==0);
	strcpy(var.username,user);

	do{
		printf("Enter Password : ");
		scanf("%s",&password);
		printf("Confirm Password: ");
		scanf("%s",&password1);
		compare=strcmp(password,password1);
		if(compare==0)
		{
			same=0;
			strcpy(var.password,password);
		}
		else
		{
			printf("Passwords doesn't Match, Please Enter Password Again.\n");
		}
	}while(same==1);
	
	printf("Enter Email ID: ");
	scanf("%s",&var.email);
	
	printf("Enter Mobile Number : ");
	scanf("%s",&var.mobile);
	
	printf("Enter Age : ");
	scanf("%s",&var.age);
	fflush(stdin);
	printf("Enter Name of State : ");
	scanf("%s",&var.state);
	fwrite(&var,sizeof(struct userdetails),1,fp);
	fclose(fp);
	printf("Account Created, You may Login.\n");
}

//this is used to check if username is already there for a person to sign in 
int check(char user[50]){
	int s,compare;
	FILE *fp;
	struct userdetails var;
	fp=fopen("user.txt","r");
	while(fread(&var,sizeof(struct userdetails),1,fp))
		{
			compare=strcmp(var.username,user);
			if(compare==0)
			{
				s=1;
			}
		}
		
		if(s==1)
		{
			printf("\nUSER NAME ALREADY TAKEN, PLEASE TRY AGAIN.\n");
			fclose(fp);
			return 0;
		} 
		else
		{
			fclose(fp);
			return 1;
		}
}

//this will redirect to add admin or if u r already a admin u can login to do various tasks
void admin(){
	char admin[20],pass[20];
	int ch,check=1;
	struct admindetails var;
	printf("Enter choice : \n1) Admin Login\n2) Add Admin \n");
	scanf("%d",&ch);
	
	if(ch==1)
	{	
		printf("Enter Admin Name : ");
		scanf("%s",&admin);
		printf("Enter Admin Password : ");
		scanf("%s",&pass);
		check=adminlogck(admin,pass);
		if(check==0)
		{		do{
				printf("Enter Choice : \n");
				printf("1) Display Car Details\n");
				printf("2) Display User Details\n");
				printf("3) Display Enquries \n");
				printf("4) Append New Car details\n");
				printf("5) Qurries\n");
				printf("6) Exit\n");
				scanf("%d",&ch);
				switch(ch){
					case 1:
						cardetailsprt();
						break;
					
					case 2: 
						userdetailsprt();
						break;
					
					case 3:
						enqprt();
						break;
					
					case 4:
						addcars();
						break;
					case 5:
						queries();
						break;
					}
			}while(ch!=6);
		}
	}
	else if(ch==2){
		int pin;
		printf("Enter Admin Pin : ");
		scanf("%d",&pin);
		if(pin==641668){
			addadmin();
			}
		else{
			printf("WRONG PIN\n");
		}
}}

//this is where the random qurries are redirected
void queries(){
	int ch;
	do{
		
	printf("Enter CHOICE : ");
	printf("\n1) Enquries made of Health related features");
	printf("\n2) Percentage of Enquries on Automaic Vehicles");
	printf("\n3) Percentage of Enquries on CNG Vehicles");
	printf("\n4) Percentage of Enquries on Electric Vehicles");
	printf("\n5) Enquries on Electric Automaic Vehicles");
	printf("\n6) Total Enquries made today ");
	printf("\n7) Exit\n");
	scanf("%d",&ch);
	
	switch(ch){
		case 1:
			 qr1();
			 break;
		case 2:
			qr2();
			break;
		case 3:
			 qr3();
			 break;
		case 4:
			qr4();
			break;
		case 5:
			 qr5();
			 break;
		case 6:
			qr6();
			break;
		}
	}while(ch!=7);
}

void qr1(){
	int comp,set,tot=0;
	FILE *fp;
	fp=fopen("enq.txt","r");
	struct enq en;
	while(fread(&en,sizeof(struct enq),1,fp))
			{
				set=0;	
				comp=strcmp(en.bact,"YES");
				if(comp==0){
					set=1;
				}
				comp=strcmp(en.purify,"YES");
				if(comp==0){
					set=1;
				}
				comp=strcmp(en.sanitate,"YES");
				if(comp==0){
					set=1;
				}
				if(set==1){
					tot+=1;
				}
			}
			printf("\nTotal Enquries on Health related features : %d\n\n",tot);
			fclose(fp);
	
}

void qr2(){
	int comp;
	float percent,autotot=0,tot=0;
	FILE *fp;
	fp=fopen("enq.txt","r");
	struct enq en;
	while(fread(&en,sizeof(struct enq),1,fp))
			{
				comp=strcmp(en.trans,"AUTOMATIC");
				if(comp==0){
					autotot+=1;
				}
				tot+=1;
			}
			percent=((autotot/tot)*100);
			printf("\nPercentage of enquries made on Automatic Cars : %0.2f%%\n\n",percent);
			fclose(fp);
}

void qr3(){
	int comp;
	float percent,cngtot=0,tot=0;
	FILE *fp;
	fp=fopen("enq.txt","r");
	struct enq en;
	while(fread(&en,sizeof(struct enq),1,fp))
			{
				comp=strcmp(en.fuel,"CNG");
				if(comp==0){
					cngtot+=1;
				}
				tot+=1;
			}
			percent=((cngtot/tot)*100);
			printf("\nPercentage of enquries made on CNG Vehicles : %0.2f%%\n\n",percent);
			fclose(fp);
}

void qr4(){
	int comp;
	float percent,cngtot=0,tot=0,pettot=0,dietot=0,eletot=0;
	FILE *fp;
	fp=fopen("enq.txt","r");
	struct enq en;
	while(fread(&en,sizeof(struct enq),1,fp))
			{
				comp=strcmp(en.fuel,"PETROL");
				if(comp==0){
					pettot+=1;
				}
				comp=strcmp(en.fuel,"DIESEL");
				if(comp==0){
					dietot+=1;
				}
				comp=strcmp(en.fuel,"ELECTRIC");
				if(comp==0){
					eletot+=1;
				}
				comp=strcmp(en.fuel,"CNG");
				if(comp==0){
					cngtot+=1;
				}
			}
			percent=((eletot/(cngtot+eletot+pettot+dietot))*100);
			printf("\nPercentage of enquries made on Electric Vehicles compared to other types : %0.2f%%\n\n",percent);
			fclose(fp);
	
}

void qr5(){
	int comp,set1,set2;
	float percent,eleautotot=0,tot=0;
	FILE *fp;
	fp=fopen("enq.txt","r");
	struct enq en;
	while(fread(&en,sizeof(struct enq),1,fp))
			{	
				set1=0;
				set2=0;
				comp=strcmp(en.fuel,"ELECTRIC");
				if(comp==0){
					set1=1;
				}
				comp=strcmp(en.trans,"AUTOMATIC");
				if(comp==0){
					set2=1;
				}
				if(set1==1&&set2==1){
					eleautotot+=1;
				}
				tot+=1;
			}
			percent=((eleautotot/tot)*100);
			printf("\nPercentage of enquries made on AUTOMATIC as well as ELECTRIC Vehicles : %0.2f%%\n\n",percent);
			fclose(fp);
	
}

void qr6(){
	int total=0;
	FILE *fp;
	fp=fopen("enq.txt","r");
	struct enq en;
	while(fread(&en,sizeof(struct enq),1,fp))
			{
				total+=1;
			}
			printf("\nTotal number of enquiries made today : %d\n\n",total);
			fclose(fp);
}

//this will check if the admin is present the check password
int adminlogck(char admin[20],char pass[20]){
	int s=0,compare;
	FILE *fp;
	struct admindetails var;
	fp=fopen("admin.txt","r");
	while(fread(&var,sizeof(struct admindetails),1,fp))
		{
			compare=strcmp(var.adminname,admin);
			if(compare==0)
			{
				s=1;
				compare=strcmp(var.adminpassword,pass);
				if(compare==0){
					s=2;
					printf("\nHello %s have a nice day\n",admin);
					fclose(fp);
					return 0;
				}
			}
		}
		
		if(s==1)
		{
				printf("\nAdmin name and password doesn't Match. Please Try again\n");
				fclose(fp);
				return 1;	
		}
		else if(s==0){
			printf("\nAdmin name doesnot exit.\n");
			fclose(fp);
			return 1;	
		}			
}

//adding of new admins
void addadmin(){ 
	FILE *fp;
	struct admindetails var;
	fp=fopen("admin.txt","a");
	printf("Enter the Admin Name : ");
	scanf("%s[^\n]",&var.adminname);
	printf("Enter the password : ");
	scanf("%s",&var.adminpassword);
	fwrite(&var,sizeof(struct admindetails),1,fp);
	fclose(fp);	
}

//this will print enquries made by all users
void enqprt(){
		struct enq var;
	FILE *fp;
	fp=fopen("enq.txt","r");
	printf("USER_NAME        CAR_NAME      BODY     FUEL       TRASNSMISSION      SEATING    PRICE   IB _SANITAION   EN_AIR-PURI   AB_SURFACE\n");
	while(fread(&var,sizeof(struct enq),1,fp)){

		printf("%-15s %-15s %-8s %-11s %-20s %-7s %-12s %-14s %-12s %-5s\n",var.username,var.carname,var.body,var.fuel,var.trans,var.seating,var.price,var.sanitate,var.purify,var.bact);
	}
	fclose(fp);
	
}

//this will display all userdetails
void userdetailsprt(){
	struct userdetails var;
	FILE *fp;
	fp=fopen("user.txt","r");
	printf("USER NAME            PASSWORD             EMAIL                MOBILE NUMBER       AGE     STATE\n\n");
	while(fread(&var,sizeof(struct userdetails),1,fp))
	{
			printf("%-20s %-20s %-25s %-20s %-6s %-15s\n",var.username,var.password,var.email,var.mobile,var.age,var.state);
	}
	fclose(fp);
}

//this will print all car details
int cardetailsprt(){
	struct cars var;
	FILE *fp;
	fp=fopen("cars.txt","r");
	printf("CAR_NAME        MODEL_NAME      BODY     FUEL       TRASNSMISSION      SEATING    PRICE   IB _SANITAION   EN_AIR-PURI   AB_SURFACE\n");
	while(fread(&var,sizeof(struct cars),1,fp))
	{
		printf("%-15s %-15s %-8s %-11s %-20s %-7s %-12s %-14s %-12s %-5s\n",var.carname,var.carmodel,var.body,var.fuel,var.trans,var.seating,var.price,var.sanitate,var.purify,var.bact);
	}
	fclose(fp);
	
}

//this will add new cars
int addcars(){
	FILE *fp;
	int n,i,j,ch,ck;
	struct cars *cr;
	printf("How many cars do u want to append?");
	scanf("%d",&n);
	
	//allocation of structure memory according to number of cars that is entered
	
	cr=(struct cars*)calloc(n,sizeof(struct cars));
	fp=fopen("cars.txt","a");
	
	for(i=0;i<n;i++)
	{	
		printf("Enter details of Car %d\n",i+1);
		fflush(stdin);
		printf("Enter Car Name : ");
		gets(cr[i].carname);
		fflush(stdin);
		printf("Enter Car Model : ");
		gets(cr[i].carmodel);
	    
		do{
			printf("Enter Price Range: \n1. 8-12 Lakhs \n2. 12-18 Lakhs \n");
			scanf("%d",&ch);
			if(ch==1){
				strcpy(cr[i].price,"8-12");
				ck=0;
			}
			else if(ch==2){
				strcpy(cr[i].price,"12-18");
				ck=0;
			}
			else{
				printf("\nWrong Input. \n");
				ck=1;
			}
		}while(ck==1);
		do{
			printf("Enter Transmission Type: \n1. Automatic \n2. Manual \n");
			scanf("%d",&ch);
			if(ch==1){
				strcpy(cr[i].trans,"AUTOMATIC");
				ck=0;
			}
			else if(ch==2){
				strcpy(cr[i].trans,"MANUAL");
				ck=0;
			}
			else{
				printf("Wrong Input. \n");
				ck=1;
			}
		}while(ck==1);
		do{
			printf("Enter Body Type: \n1. SUV \n2. Sedan \n");
			scanf("%d",&ch);
			if(ch==1){
				strcpy(cr[i].body,"SUV");
				ck=0;
				
			}
			else if(ch==2){
				strcpy(cr[i].body,"SEDAN");
				ck=0;
			}
			else{
				printf("Wrong Input. \n");
				ck=1;
			}
		}while(ck==1);
		do{
			printf("Enter Fuel Type: \n1. Petrol \n2. Diesel \n3. Electric \n4. CNG \n");
			scanf("%d",&ch);
			if(ch==1){
				strcpy(cr[i].fuel,"PETROL");
				ck=0;
			}
			else if(ch==2){
				strcpy(cr[i].fuel,"DIESEL");
				ck=0;
			}
			else if(ch==3){
				strcpy(cr[i].fuel,"ELECTRIC");
				ck=0;
			}
			else if(ch==4){
				strcpy(cr[i].fuel,"CNG");
				ck=0;
			}
			else{
				printf("Wrong Input. \n");
				ck=1;
			}
		}while(ck==1);
		do{
			printf("Enter seating capacity : \n1. 5 \n2. 7 \n3. 9 \n");
			scanf("%d",&ch);
			if(ch==1||ch==5){
				strcpy(cr[i].seating,"5");
				ck=0;
			}
			else if(ch==2||ch==7){
				strcpy(cr[i].seating,"7");
				ck=0;
			}
			else if(ch==3||ch==9){
				strcpy(cr[i].seating,"9");
				ck=0;
			}
			else{
				printf("Wrong Input. \n");
				ck=1;
			}
		}while(ck==1);
		do{
			printf("In Built sanitation: \n1. YES \n2. NO \n");
			scanf("%d",&ch);
			if(ch==1){
				strcpy(cr[i].sanitate,"YES");
				ck=0;
			}
			else if(ch==2){
				strcpy(cr[i].sanitate,"NO");
				ck=0;
			}
			else{
				printf("Wrong Input. \n");
				ck=1;
			}
		}while(ck==1);
		do{
			printf("Enhanced Air-Purification : \n1. YES \n2. NO \n");
			scanf("%d",&ch);
			if(ch==1){
				strcpy(cr[i].purify,"YES");
				ck=0;
			}
			else if(ch==2){
				strcpy(cr[i].purify,"NO");
				ck=0;
			}
			else{
				printf("Wrong Input. \n");
				ck=1;
			}
		}while(ck==1);
		do{
			printf("Anti-Bacterial surface : \n1. YES \n2. NO \n");
			scanf("%d",&ch);
			if(ch==1){
				strcpy(cr[i].bact,"YES");
				ck=0;
			}
			else if(ch==2){
				strcpy(cr[i].bact,"NO");
				ck=0;
			}
			else{
				printf("Wrong Input. \n");
				ck=1;
			}
		}while(ck==1);	
		
		fwrite(&cr[i],sizeof(struct cars),1,fp);
	}
	fclose(fp);
	
}
