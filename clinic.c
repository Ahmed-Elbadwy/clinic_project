#include<stdio.h>
#include<stdlib.h> 
#include <string.h>
#include"STD_TYPE.h"

#define MAX_STR_LEN 50
#define null 0 

typedef struct Data {	
	u8	    age       		    ;
	u8		slot				;
	u8 	    arr[MAX_STR_LEN]  	;
	u8		gen[10]				;
	u32     id 		 		    ;
	struct Data * next 			;	
}Mydata ;

Mydata * Head = null;

u8 flag0 = 0 ;
u8 flag3 = 0 ;
u8 flag4 = 0 ;
u8 flag5 = 0 ;
u8 flag6 = 0 ;
u8 flag7 = 0 ;
u8 AGE = 0 ;
u32 ID  ;

void check_password(void);
u8 check_id(Mydata* Head, u32 A);
void Add_patient( void );
void Edit(void);
void Reserve(void);
void Name_scan (Mydata*temp);
void Gender_scan (Mydata*temp);
void Gender_scan1 (Mydata*temp);
void Cancel_Reservation(void);
void ViewList(void);
void Patient_AGE (Mydata*temp);

void main (void){
	u8 choice , k;
	
while(1){	
printf("-------------------------------------------- \n");
printf("Hello \n 1- Admin \n 2- User \n ")	;
scanf("%d",&k);
if (k == 1){	
check_password();	
if ( flag0 == 1 ){
	
	printf("-------------------------------------------- \n");
	printf("Please choice from 1 to 4 .. \n");	
	printf("1 - Add new patient record .\n");	
	printf("2 - Edit patient record .\n");	
	printf("3 - Reserve a slot with the doctor .\n");	
	printf("4 - Cancel Reservation .\n");	
	printf("-------------------------------------------- \n");

	scanf("%d",&choice);
	switch(choice){
		case(1) : 	Add_patient(); 			 break;
		case(2) :	Edit(); 				 break;
		case(3) :	Reserve(); 				 break ;
		case(4) :	Cancel_Reservation();	 break;
	}
	}	
} 
else if (k == 2){
	ViewList();
}
else{
	printf("Wrong choice .. try again");
}
}
}
void check_password(void){
	u32 pass = 0 ;
	u8 i ;
	flag0 = 0 ;
	
	for(i = 0 ; i < 3 ; i++ ){
		printf("Please enter your password .. : ");
		scanf ("%d",&pass);
		if ( pass == 1234 ){
			printf("welcome .. ");
			flag0 = 1 ;
			break;
		}
		else {
			printf("Wrong password .. Try again \n");
		}
	}
	if (flag0 == 0)
	{
		printf("Incorrect password for 3 times, No more tries \n");
	}
}
void Add_patient( void ){	
	u8 flag1 , i ;	
	Mydata * ptr = (Mydata *)malloc( sizeof(Mydata) );	
    Name_scan(ptr)			  			;
	Gender_scan(ptr)		  			;
	printf("Enter the patient age : ")	;
	scanf("%d",&AGE)				    ;
	ptr -> age = AGE 		 		    ;
	printf("Enter the patient ID : ")	;
	scanf("%d",&ID)					    ;	
    flag1 = check_id(Head,ID)			;	

    if (flag1 == 1) {
        printf("This ID was taken .. try another one\n");
					}
	else{
		printf("Accepted ID ...") 			;	
		ptr -> next = Head    			    ;
		Head = ptr 					        ;		    
		ptr -> id = ID					    ;	
		printf(" New patient added ..  \n") ;
		} 	
}

u8 check_id(Mydata* Head, u32 A){ 
    Mydata* current = Head;  
    while (current != null) 
    { 
        if (current->id == A) 
            return 1; 
        current = current->next; 
    } 
    return 0 ; 
}

void Edit(void){
	u8 flag2 = 0 ;
	u8 choice  ;
	printf("Enter the patient ID : ")	;
	scanf("%d",&ID)			  	 		;	
    Mydata* current1 = Head		 		;  	
	Mydata* current2 = Head		 		; 
    while (current1 != null) 
    { 
        if (current1->id == ID) {
            flag2 = 1	; 
			break		;
		}
		else{
			current1 = current1->next;
		}  
    }  
	if (flag2 == 1) {
		
        printf("Found\n");
		printf("This Patient name is : %s\n",current1->arr);
		printf("This Patient gender is : %s\n",current1->gen);
		printf("This patient ID : %d\n",current1->id);
		printf("This patient age : %d\n",current1->age);
		switch(current1->slot){
			case 1 : printf("This patient slot : 2:00 to 2:30 PM \n");		 break;
			case 2 : printf("This patient slot : 2:30 to 3:00 PM \n");		 break;
			case 3 : printf("This patient slot : 3:00 to 3:30 PM \n");		 break;			
			case 4 : printf("This patient slot : 4:00 to 4:30 PM \n");		 break;
			case 5 : printf("This patient slot : 4:30 to 5:00 PM \n");		 break;	
			default :break;
					}			
		printf("Please choice ... \n1- To Edit This patient Name \n");
		printf("2- To Edit This patient age\n")     ;
		printf("3- To Edit This patient gender\n")  ;
		scanf("%d",&choice)				  		    ;	
		
		switch(choice){			
			case 1 : Name_scan(current1)  	   ;  break ;
			case 2 : Patient_AGE (current1)    ;  break ;
			case 3 : Gender_scan1(current1)    ;  break ;
			default :printf("wrong choice .. ");  break ; 
		}
		printf("Done .... so the new data is .. \n ")		;
		printf("This Patient name is: %s\n",current1->arr)	;
		printf("This Patient gender is: %s\n",current1->gen);		
		printf("This patient ID : %d\n",current1->id)		;
		printf("This patient age : %d\n",current1->age)		;					
					}
	else{
		printf("Wrong ID .. Try again ...\n");	
		} 	
}

void Reserve(void){
	u8 z = 0 ;
	u8 y = 0 ;
	u8 i = 0 ;
	Mydata* current1 = Head		 		;  	
	printf("Enter the patient ID : ");
	scanf("%d",&ID)			  ;	
    while (current1 != null) 
    { 
        if (current1->id == ID) {
            z = 1	; 
			break		;
		}
		else{
			current1 = current1->next;
		}  
    }
	if (z == 1){	
        if ((flag3 == 1) &&(flag4 == 0)&&(flag5 == 0)&&(flag6 == 0)&&(flag7 == 0)) {
			printf("The free slots ... \n");			
			printf("2- ( 2:30 to 3:00 PM )\n");		
			printf("3- ( 3:00 to 3:30 PM )\n");		
			printf("4- ( 4:00 to 4:30 PM )\n");		
			printf("5- ( 4:30 to 5:00 PM )\n");
			printf(" choise 2 or 3 or 4 or 5 \n");		
		}
		else if((flag3 == 1) &&(flag4 == 1)&&(flag5 == 0)&&(flag6 == 0)&&(flag7 == 0)) {
			printf("The free slots ... \n");								
			printf("3- ( 3:00 to 3:30 PM )\n");		
			printf("4- ( 4:00 to 4:30 PM )\n");
			printf("5- ( 4:30 to 5:00 PM )\n");
			printf(" choise  3 or 4 or 5 \n");			
		}
		else if((flag3 == 1) &&(flag4 == 0)&&(flag5 == 1)&&(flag6 == 0)&&(flag7 == 1)) {
			printf("The free slots ... \n");					
			printf("2- ( 2:30 to 3:00 PM )\n");				
			printf("4- ( 4:00 to 4:30 PM )\n");
			printf("5- ( 4:30 to 5:00 PM )\n");
			printf(" choise  2 or 4 or 5 \n");			
		}
		else if ((flag3 == 1) &&(flag4 == 0)&&(flag5 == 0)&&(flag6 == 1)&&(flag7 == 0)) {
			printf("The free slots ... \n");					
			printf("2- ( 2:30 to 3:00 PM )\n");			
			printf("3- ( 3:00 to 3:30 PM )\n");		
			printf("5- ( 4:30 to 5:00 PM )\n");
			printf(" choise  2 or 3 or 5 \n");
		}
		else if((flag3 == 1) &&(flag4 == 0)&&(flag5 == 0)&&(flag6 == 0)&&(flag7 == 1)) {
			printf("The free slots ... \n");					
			printf("2- ( 2:30 to 3:00 PM )\n");			
			printf("3- ( 3:00 to 3:30 PM )\n");		
			printf("4- ( 4:00 to 4:30 PM )\n");
			printf(" choise  2 or 3 or 4 \n");			
		}  
        else if ( (flag3 == 0) && (flag4 == 1)&&(flag5 == 0)&&(flag6 == 0)&&(flag7 == 0)) {
			printf("The free slots ... \n");			
			printf("1- ( 2:00 to 2:30 PM )\n");	
			printf("3- ( 3:00 to 3:30 PM )\n");		
			printf("4- ( 4:00 to 4:30 PM )\n");		
			printf("5- ( 4:30 to 5:00 PM )\n");
			printf(" choise 1 or 3 or 4 or 5 \n");		
		}
		else if((flag3 == 0) &&(flag4 == 1)&&(flag5 == 1)&&(flag6 == 0)&&(flag7 == 0)) {
			printf("The free slots ... \n");					
			printf("1- ( 2:00 to 2:30 PM )\n");				
			printf("4- ( 4:00 to 4:30 PM )\n");
			printf("5- ( 4:30 to 5:00 PM )\n");
			printf(" choise  1 or 4 or 5 \n");			
		}
		else if((flag3 == 0) &&(flag4 == 1)&&(flag5 == 0)&&(flag6 == 1)&&(flag7 == 0)) {
			printf("The free slots ... \n");					
			printf("1- ( 2:00 to 2:30 PM )\n");	
			printf("3- ( 3:00 to 3:30 PM )\n");				
			printf("5- ( 4:30 to 5:00 PM )\n");
			printf(" choise  1 or 3 or 5 \n");			
		}
		else if ((flag3 == 0) &&(flag4 == 1)&&(flag5 == 0)&&(flag6 == 0)&&(flag7 == 1)) {
			printf("The free slots ... \n");					
			printf("1- ( 2:00 to 2:30 PM )\n");				
			printf("3- ( 3:00 to 3:30 PM )\n");		
			printf("4- ( 4:00 to 4:30 PM )\n");
			printf(" choise  1 or 3 or 4 \n");
		}
		else if ((flag3 == 0) &&(flag4 == 0)&&(flag5 == 1)&&(flag6 == 0)&&(flag7 == 0)) {
			printf("The free slots ... \n");	
			printf("1- ( 2:00 to 2:30 PM )\n");				
			printf("2- ( 2:30 to 3:00 PM )\n");			
			printf("4- ( 4:00 to 4:30 PM )\n");	
			printf("5- ( 4:30 to 5:00 PM )\n");			
			printf(" choise 1 or 2 or 4 or 5 \n");	
		}
		else if((flag3 == 0) &&(flag4 == 0)&&(flag5 == 1)&&(flag6 == 1)&&(flag7 == 1)) {
			printf("The free slots ... \n");	
			printf("1- ( 2:00 to 2:30 PM )\n");				
			printf("2- ( 2:30 to 3:00 PM )\n");			
			printf("5- ( 4:30 to 5:00 PM )\n");
			printf(" choise  1 or 2 or 5 \n");			
		}
		else if ((flag3 == 0)&&(flag4 == 0)&&(flag5 == 1)&&(flag6 == 0)&&(flag7 == 1)) {
			printf("The free slots ... \n");
			printf("1- ( 2:00 to 2:30 PM )\n");				
			printf("2- ( 2:30 to 3:00 PM )\n");			
			printf("4- ( 4:00 to 4:30 PM )\n");		
			printf(" choise 1 or 2 or 4  \n");		
		}
		else if((flag3 == 0) &&(flag4 == 0)&&(flag5 == 0)&&(flag6 == 1)&&(flag7 == 1)) {
			printf("The free slots ... \n");	
			printf("1- ( 2:00 to 2:30 PM )\n");				
			printf("2- ( 2:30 to 3:00 PM )\n");			
			printf("3- ( 3:00 to 3:30 PM )\n");		
			printf(" choise  3 or 4 or 5 \n");			
		}     		
		else if ((flag3 == 0) &&(flag4 == 0)&&(flag5 == 0)&&(flag6 == 0)&&(flag7 == 0)){
			printf("The free slots ... \n");
			printf("1- ( 2:00 to 2:30 PM )\n");		
			printf("2- ( 2:30 to 3:00 PM )\n");		
			printf("3- ( 3:00 to 3:30 PM )\n");		
			printf("4- ( 4:00 to 4:30 PM )\n");		
			printf("5- ( 4:30 to 5:00 PM )\n");
		}
		scanf("%d",&current1->slot); 	
		switch(current1->slot){
			case 1 : printf("your choice is : 2:00 to 2:30 PM \n");	flag3 = 1 ;	 break;
			case 2 : printf("your choice is : 2:30 to 3:00 PM \n");	flag4 = 1 ;	 break;
			case 3 : printf("your choice is : 3:00 to 3:30 PM \n");	flag5 = 1 ;	 break;			
			case 4 : printf("your choice is : 4:00 to 4:30 PM \n");	flag6 = 1 ;	 break;
			case 5 : printf("your choice is : 4:30 to 5:00 PM \n");	flag7 = 1 ;	 break;	
			default :printf("Wrong choice\n");								 	 break;
		}
	}	
	else {
		printf("Wrong ID .. Try again ...\n");	
		}
}

void Cancel_Reservation(void){
	u8 z = 0 ;
	Mydata* current1 = Head		 	 ;  	
	printf("Enter the patient ID : ");
	scanf("%d",&ID)			  ;	
    while (current1 != null) 
    { 
        if (current1->id == ID) {
            z = 1	; 
			break	;
		}
		else{
			current1 = current1->next;
		}  
    }
	if (z == 1){	
		if(current1->slot == 1){
			flag3 = 0 ;
		}
		else if(current1->slot == 2){
			flag4 = 0 ;
		}
		else if(current1->slot == 3){
			flag5 = 0 ;
		}
		else if(current1->slot == 4){
			flag6 = 0 ;
		}
		else if(current1->slot == 5){
			flag7 = 0 ;
		}
		current1->slot = 0	;
		printf("Reservation canceled .. \n");
	}
	else {
		printf("Wrong ID .. Try again ...\n");	
		}	
}

void Name_scan (Mydata*temp){	
	printf("Enter the patient name: "); 
	fgets(temp->arr, MAX_STR_LEN , stdin);
	gets(temp->arr); 
    printf("Patient name is: %s\n", temp->arr);
}
void Gender_scan (Mydata*temp){	
	printf("Enter the patient gender: "); 
	//fgets(temp->gen, 10 , stdin);
	gets(temp->gen);
    printf("Patient gender is: %s\n", temp->gen);
}
void Gender_scan1 (Mydata*temp){	
	printf("Enter the patient gender: "); 
	fgets(temp->gen, 10 , stdin);
	gets(temp->gen);
    printf("Patient gender is: %s\n", temp->gen);
}

void ViewList(void){	

	if( Head != null ){		
		Mydata * temp = Head ;	
		do{			
		printf(" Name : %s\n",temp->arr)	;
		printf(" Gender is: %s\n",temp->gen);		
		printf(" Age : %d\n",temp->age)		;
		if(temp->slot == 1){
		printf("This patient slot : ( 2:00 to 2:30 PM ) \n")		;
		}
		else if(temp->slot == 2){
		printf("This patient slot : ( 3:00 to 3:30 PM ) \n")		;
		}
		else if(temp->slot == 3){
		printf("This patient slot : ( 2:30 to 3:00 PM ) \n")		;
		}
		else if(temp->slot == 4){
		printf("This patient slot : ( 4:00 to 4:30 PM ) \n")		;
		}
		else if(temp->slot == 5){
		printf("This patient slot : ( 4:30 to 5:00 PM ) \n")		;
		}
		printf("------------------------\n");
		temp = temp -> next ;		
		}while( temp != null );	
		}
	else{
		printf("Your List is Empty \n");
		}	
}

void Patient_AGE (Mydata*temp){
	u32 G = 0 ;
	temp -> age = G ;
	printf("Enter the new age : ")    ;		 
	scanf("%d",&G)				   ;
	temp -> age = G ;
}