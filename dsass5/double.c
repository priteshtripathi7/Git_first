#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{
	int roll;
	char name[50];
	float cgpa;
	struct node *rptr;
	struct node *lptr;
};

struct node *insertb(struct node *first,int r,char *a,float cg){
	struct node *new=(struct node *)malloc(sizeof(struct node));
	new->roll=r;new->lptr=NULL;
	strcpy(new->name,a);
	new->cgpa=cg;
	if(first==NULL){
		new->rptr=NULL;return(new);
	}
	else{
		new->rptr=first;
		first->lptr=new;
		return(new);
	}
}

struct node *inserte(struct node *first,int r,char *a,float cg){
	struct node *new;new=(struct node *)malloc(sizeof(struct node));
	new->roll=r;
	strcpy(new->name,a);
	new->cgpa=cg;new->rptr=NULL;
	if(first==NULL){
		new->lptr=NULL;return(new);
	}
	struct node *save=first;
	while(save->rptr!=NULL){
		save=save->rptr;
	}
	save->rptr=new;new->lptr=save;
	return(first);
}

struct node *insert(struct node *first,int k,int r,char *a,float cg){
	if(k==1){
		return(insertb(first,r,a,cg));
	}
	else if(first==NULL){
		printf("Invalid position\n");return(first);
	}
	struct node *new=(struct node *)malloc(sizeof(struct node));
	new->roll=r;
	strcpy(new->name,a);
	new->cgpa=cg;
	struct node *save=first;
	int c=1;
	while(save->rptr!=NULL){
		if(c==k-1){
			new->lptr=save;
			new->rptr=save->rptr;
			save->rptr->lptr=new;
			save->rptr=new;
			return(first);
		}
		save=save->rptr;
		c++;
	}
	if(k==c+1){
		save->rptr=new;
		new->lptr=save;
		return(first);
	}
	else{
		printf("invalid position\n");
		return(first);
	}
}

struct node *deleteb(struct node *first){
	if(first==NULL){
		printf("null list\n");
		return(first);
	}
	if(first->rptr==NULL)return(NULL);
	first=first->rptr;
	first->lptr=NULL;
	return(first);
}

struct node *deletee(struct node *first){
	if(first==NULL){
		printf("null list\n");
		return(first);
	}
	if(first->rptr==NULL){
		return(NULL);
	}
	struct node *save=first;
	while(save->rptr->rptr!=NULL){
		save=save->rptr;
	}
	save->rptr=NULL;
	return(first);
}

struct node *deleteat(struct node *first,int k){
	if(first==NULL){
		printf("null list\n");
		return(first);
	}
	if(k==1){
		return(deleteb(first));
	}
	struct node *save=first;
	int c=1;
	while(save->rptr!=NULL){
		if(c==k-1){
			save->rptr=save->rptr->rptr;
			if(save->rptr!=NULL)save->rptr->lptr=save;
			return(first);
		}
		save=save->rptr;
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
		save=save->rptr;
	}
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
		save=save->rptr;
	}
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
		save=save->rptr;
	}
}

void display(struct node *first){
	if(first==NULL)printf("NULL\n");
	struct node *save;save=first;
	while(save!=NULL){
		printf("%d %s %f\n",save->roll,save->name,save->cgpa);
		save=save->rptr;
	}
}

void main(){
	struct node *fir;fir=NULL;
	int input;
	int inr;char ina[50];float incg;int ink;
	printf("1: insert at beg\n2: insert at end\n3: insert at k pos\n4: delete from beg\n5: delete from end\n6: delete from k pos\n7: search by roll\n8: search by name\n9: search by cgpa\n10: display\n-1:exit\n");
	while(1){
		printf("choice :");scanf("%d",&input);
		switch(input){
			case 1: printf("roll: ");scanf("%d",&inr);
				printf("name: ");scanf("%s",ina);
				printf("cgpa: ");scanf("%f",&incg);
				fir=insertb(fir,inr,ina,incg);
				break;
			case 2: printf("roll: ");scanf("%d",&inr);
				printf("name: ");scanf("%s",ina);
				printf("cgpa: ");scanf("%f",&incg);
				fir=inserte(fir,inr,ina,incg);
				break;
			case 3: printf("roll: ");scanf("%d",&inr);
				printf("name: ");scanf("%s",ina);
				printf("cgpa: ");scanf("%f",&incg);
				printf("position: ");scanf("%d",&ink);
				fir=insert(fir,ink,inr,ina,incg);
				break;
			case 4: fir=deleteb(fir);
				break;
			case 5: fir=deletee(fir);
				break;
			case 6: printf("position: ");scanf("%d",&ink);
				fir=deleteat(fir,ink);
				break;
			case 7: printf("roll: ");scanf("%d",&inr);
				searchr(fir,inr);
				break;
			case 8: printf("name: ");scanf("%s",ina);
				searchn(fir,ina);
				break;
			case 9: printf("cgpa: ");scanf("%f",&incg);
				searchc(fir,incg);
				break;
			case 10:
				display(fir);
				break;
			default:exit(0);
		}
	}
}
