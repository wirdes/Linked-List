#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
struct student{
	int index;
	int studentNotes;
	int studentNumber;
	struct  student * next ;
};

typedef struct student Student;


Student * delSt(struct student * r,int number){
	Student *temp;
	Student *iter = r;
	if(r-> index == number ){
		temp = r;
		r = r->next;
		free(temp);
		return r;
	}
	while(iter ->next !=NULL && iter -> next ->index !=number ){
		iter = iter ->next;
	}
	if(iter -> next == NULL){
		printf("Student not found");
		return r;
	}
	temp = iter -> next;
	iter -> next = iter -> next ->next;
	free(temp);
	return r;
	
}
Student * addSt(struct student * r,int number,int note){
	if(r == NULL){
		
		r = (Student * )malloc(sizeof(Student));
		r-> index=0;
		r-> studentNumber = number;
		r-> studentNotes  = note;
		r-> next  = NULL;
		return r;	
	} 
	if(r->studentNotes < note ){ 
	
				Student * temp = (Student *)malloc(sizeof(Student));
				temp -> next = NULL;
				temp -> studentNotes = note;
				temp -> studentNumber = number;
				temp -> next = r;
				return  temp;
		} 			
	Student * iter = r;
	while(iter->next != NULL && iter -> next ->studentNotes >= note ){
		if(iter -> next ->studentNotes == note){
			//esit olma durumunda buraya girer
			if (iter -> next ->studentNumber > number){
				//gelen verirnin oncekinden kücük olma duumunda buraya girer
					Student * temp = (Student *)malloc(sizeof(Student));
					temp ->next = iter ->next;
					temp -> studentNotes = note;
					temp -> studentNumber = number;
					iter->next = temp;	
			return r;
			}else{
				iter = iter->next;
			}
			
		} else {
			iter = iter->next;
		}
	}
	
			Student * temp = (Student *)malloc(sizeof(Student));
			temp ->next = iter ->next;
			iter->next = temp;
			temp -> studentNotes = note;
			temp -> studentNumber = number;
			return r;			
}
int getIn(struct student * iter,int number){
	while(iter != NULL){
		if (iter->studentNumber == number){	
		return iter->index;
		}
		iter = iter -> next;
	}
	
}

void printSt (struct student * iter,int note){
	int index = 0;
	while(iter != NULL){
		if (iter->studentNotes > note){	
		iter -> index = index;
		printf( "Index:%-2d Num:%-5d  Notes:%d\n",iter -> index, iter->studentNumber, iter->studentNotes);
		index++;
		}
		iter = iter -> next;
	}
}
int main(void){
	setlocale(LC_ALL, "Turkish");
	int secim;
	Student * root;
	root = NULL;
	root = addSt(root,18060311,40);
	root = addSt(root,20060045,50);
	root = addSt(root,19061091,75);
	root = addSt(root,20060134,90);
	root = addSt(root,20060678,40);
	root = addSt(root,18061086,75);
	root = addSt(root,20060032,50);
	root = addSt(root,20060067,60);
	root = addSt(root,19060456,60);
	root = addSt(root,18060245,75);
	root = addSt(root,20060110,40);
	root = addSt(root,20060234,90);
	root = addSt(root,20060141,60);
	root = addSt(root,20060011,50);
	root = addSt(root,20060012,60);
	printf("--------------------------\n|To add:1                |\n|To delete:2             |\n|To change:3             |\n|To print:4              |\n|To exit:5               |\n--------------------------\n|Please select an action |");
  
	int no,number;
	int ch;
	 while(secim!=5)
    {
    	
  	printf("\n--------------------------\nAction:");
		scanf("%d",&secim);
		switch (secim){
    	case 1:
    		
    		printf("Enter student number:");
    		scanf("%d",&no);
    		printf("Enter student grade:");
    		scanf("%d",&number);
    		root = addSt(root,no,number);
      	break;

    	case 2:
    		printf("Enter the student index you want to delete:");
    		scanf("%d",&no);
    		root = delSt(root,no);
      	break;
      	
      	case 3:
    	 	printf("Enter the number of the student whose grade you want to change:");
    		scanf("%d",&number);
    		printf("Enter the student's new grade:");
    		scanf("%d",&no);
    		root = delSt(root,getIn(root,number));
    		root = addSt(root,number,no);
      	break;
      	
      	case 4:
      		printf("Enter the smallest note you want to see :");
    		scanf("%d",&no);;
      		
    	 	printSt(root,no);
    	 	
      	break;
      	
      	case 5:
    	 
      	break;  
  
   	    default:
   	    	
      		printf("Please select a valid transaction");
      		
			}	
    }
    printf("Exited program\n");
	
}
