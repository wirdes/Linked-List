#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

struct student{
	int  studentNotes;
	int  studentNumber;
	struct  student * next ;
};

typedef struct student Student;

Student * delSt(struct student * r,int number){
	Student *temp;
	Student *iter = r;
	if(r->studentNumber == number ){
		temp = r;
		r = r->next;
		free(temp);
		return r;
		
	}
	while(iter ->next !=NULL && iter -> next ->studentNumber !=number ){
		iter = iter ->next;
	}
	if(iter -> next == NULL){
		printf("��renci bulunamad�");
		return r;
	}
	
	temp = iter -> next;
	iter -> next = iter -> next ->next;
	free(temp);
	return r;
	
}
Student * addSt(struct student * r,int number,int note){
	if(r == NULL){
		//i�erisi bo� oldugunda buraya girer
		r = (Student * )malloc(sizeof(Student));
			r-> studentNumber = number;
			r-> studentNotes  = note;
			r-> next  = NULL;
			return r;	
	} 
	if(r->studentNotes < note ){ 
	// gelen eleman�n ilk elemandan b�y�k olma durumu
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
				//gelen verirnin oncekinden k�c�k olma duumunda buraya girer
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
	//kalan t�m durumlarda buraya girer
			Student * temp = (Student *)malloc(sizeof(Student));
			temp ->next = iter ->next;
			iter->next = temp;
			temp -> studentNotes = note;
			temp -> studentNumber = number;
			return r;			
}

void printSt (struct student * iter){
	while(iter != NULL){	
		printf( "Num:%-5d  Notes:%d\n", iter->studentNumber, iter->studentNotes);
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
	
	printf("--------------------------\n|Eklemek i�in:1          |\n|Silmek i�in:2           |\n|De�i�tirmek i�in:3      |\n|Yazd�rmak i�in:4        |\n|��kmak i�in:5           |\n--------------------------\n|L�tfen bir i�lem se�iniz|\n--------------------------");
	int no,number;
	int ch;
	 while(secim!=5)
    {
    	printf("\nSecim:");
		scanf("%d",&secim);
		switch (secim){
    	case 1:
    		
    		printf("��renci numaras�n�  giriniz:");
    		scanf("%d",&no);
    		printf("��renci notunu giriniz:");
    		scanf("%d",&number);
    		root = addSt(root,no,number);
      	break;

    	case 2:
    		printf("Silmek istedi�iniz��renci numaras�n�  giriniz:");
    		scanf("%d",&no);;
    		root = delSt(root,no);
    	  
      	break;
      	
      	case 3:
    	 	printf("Notunu de�i�tirmek istedi�iniz ��renci numaras�n�  giriniz:");
    		scanf("%d",&no);
    		printf("��rencinin yeni notunu giriniz:");
    		scanf("%d",&number);
    		root = delSt(root,no);
    		root = addSt(root,no,number);
      	break;
      	
      	case 4:
      		
    	 	printSt(root);
    	 	
      	break;
      	
      	case 5:
    	 
      	break;
  
   	    default:
   	    	
      		printf("L�tfen ge�erli bir i�lem se�iniz");
      		
			}
		
    }
    printf("Programdan ��k�l�yor\n");
	
}
