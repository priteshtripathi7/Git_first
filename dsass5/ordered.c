#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
	int roll;
	char name[50];
	float cgpa;
	struct node *link;
};
struct node *insert(struct node *first,int r,char *a,float cg){
	struct node *new=(struct node *)malloc(sizeof(struct node));
	new->roll=r;
	strcpy(new->name,a);
	new->cgpa=cg;
	
	if(first==NULL){
		first=new;return(first);
	}
	if(first->roll>=r){
		new->link=first;
		return (new);
	}
	struct node *save=first;
	while(save->link!=NULL){
		if(save->link->roll>=r){
			new->link=save->link;
			save->link=new;
			return(first);
		}
		save=save->link;
	}
	save->link=new;
	return(first);
	
}
struct node *deleteb(struct node *first){
	if(first==NULL){
		printf("null list\n");
		return(first);
	}
	first=first->link;
	return(first);
}
struct node *deletee(struct node *first){
	if(first==NULL){
		printf("null list\n");
		return(first);
	}
	if(first->link==NULL){
		return(NULL);
	}
	struct node *save;save=first;
	while(save->link->link!=NULL){
		save=save->link;
	}
	save->link=NULL;
	return(first);
}
struct node *deleteat(struct node *first,int k){
	if(first==NULL){
		printf("null list\n");
		return(first);
	}
	struct node *save=first;
	if(k==1){
		return(deleteb(first));
	}
	int c=1;
	while(save->link!=NULL){
		if(c==k-1){
			save->link=save->link->link;
			return(first);
		}
		save=save->link;
		c++;
	}
	printf("invalid position\n");
	return(first);
}
void searchr(struct node *first,int r){
	if(first==NULL){
		printf("NULL\n");
	}
	struct node *save=first;
	while(save!=NULL){
		if(save->roll==r){
			printf("%d %s %f\n",save->roll,save->name,save->cgpa);
		}
		save=save->link;
	}
	if(save==NULL)printf("no match\n");
}
void searchc(struct node *first,float cg){
	if(first==NULL){
		printf("NULL\n");
	}
	struct node *save=first;
	while(save!=NULL){
		if(save->cgpa==cg){
			printf("%d %s %f\n",save->roll,save->name,save->cgpa);
		}
		save=save->link;
	}
	if(save==NULL)printf("no match\n");
}
void searchn(struct node *first,char *a){
	if(first==NULL){
		printf("NULL\n");
	}
	struct node *save=first;
	while(save!=NULL){
		if(strcmp(save->name,a)==0){
			printf("%d %s %f\n",save->roll,save->name,save->cgpa);
		}
		save=save->link;
	}
	if(save==NULL)printf("no match\n");
}
void display(struct node *first){
	if(first==NULL)printf("NULL\n");
	struct node *save;save=first;
	while(save!=NULL){
		printf("%d %s %f\n",save->roll,save->name,save->cgpa);
		save=save->link;
	}
}


void main(){
	struct node *fir;fir=NULL;
	int input;
	int inr;char ina[50];float incg;int ink;
	printf("1: insert at\n2: delete from beg\n3: delete from end\n4: delete from k pos\n5: search by roll\n6: search by name\n7: search by cgpa\n8: display\n-1:exit\n");
	while(1){
		printf("choice :");scanf("%d",&input);
		switch(input){
			case 1: printf("roll: ");scanf("%d",&inr);
				printf("name: ");scanf("%s",ina);
				printf("cgpa: ");scanf("%f",&incg);
				
				fir=insert(fir,inr,ina,incg);
				break;
			case 2: fir=deleteb(fir);
				break;
			case 3: fir=deletee(fir);
				break;
			case 4: printf("position: ");scanf("%d",&ink);
				fir=deleteat(fir,ink);
				break;
			case 5: printf("roll: ");scanf("%d",&inr);
				searchr(fir,inr);
				break;
			case 6: printf("name: ");scanf("%s",ina);
				searchn(fir,ina);
				break;
			case 7: printf("cgpa: ");scanf("%f",&incg);
				searchc(fir,incg);
				break;
			case 8:
				display(fir);
				break;
			default:exit(0);
		}
	}
}
