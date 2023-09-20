#include"stdio.h"

typedef struct Node{
	int data;
	struct Node *pLeft;
	struct Node *pRight;
}*PtrNode,Node;

void Init(PtrNode &t){
	t = NULL;
}

void Insert(PtrNode &t, int x){
	if(t==NULL){
		PtrNode p = new Node;
		p->data = x;
		p->pLeft = NULL;
		p->pRight = NULL;
		t = p;
	}else{
		if(t->data>x){
		
			Insert(t->pLeft,x);
	    }
	    else if(t->data<x)
		{
		    Insert(t->pRight,x);
		}
	}
}

void NLR(PtrNode t){ // duyet theo NODE -> LEFT -> RIGHT
	if(t != NULL){
		printf("%4d",t->data);
		NLR(t->pLeft); // duyet qua trai
		NLR(t->pRight); // duyet qua phai
	}
}

void NRL(PtrNode t){
	if(t != NULL){
		printf("%4d",t->data);
		NRL(t->pRight);
		NRL(t->pLeft);
	}
}

// Gan giong sap xep tang 
void LNR(PtrNode t){
	if(t != NULL){
		LNR(t->pLeft);
		printf("%4d",t->data);
		LNR(t->pRight);
	}
}

// Gan giong sap xep giam
void RNL(PtrNode t){
	if(t != NULL){
		RNL(t->pRight);
		printf("%4d",t->data);
		RNL(t->pLeft);
	}
}

void LRN(PtrNode t){
	if(t!=NULL){
		LRN(t->pLeft);
		LRN(t->pRight);
		printf("%4d",t->data);
	}
}

void RLN(PtrNode t){
	if(t!=NULL){
		RLN(t->pRight);
		RLN(t->pLeft);
		printf("%4d",t->data);
	}
}

bool CheckSNT(int n){
	if(n<2){
		return false;
	}else{
		if(n==2){
			return true;
		}else{
			if(n%2==0){
				return false;
			}else{
				for(int i=2; i<n; i++){
					if(n%i==0){
						return false;
					}
				}
			}
		}
	}
	return true;
}

int CountSNT(PtrNode t,int &count){
//	int count =0;
	if(t!=NULL){
		 // Xu ly
		if(CheckSNT(t->data)==true){
			count++;
		}
		CountSNT(t->pLeft,count);
		CountSNT(t->pRight,count);
	}
}

void MENU(PtrNode &t){
	while(true){
		printf("\n\n\t\t==========MENU=========="); 
		printf("\n\t\t1. Nhap du lieu");
		printf("\n\t\t2. Xuat du lieu theo NLR");
		printf("\n\t\t3. Xuat du lieu theo NRL");
		printf("\n\t\t4. Xuat du lieu theo LNR");
		printf("\n\t\t5. Xuat du lieu theo RNL");
		printf("\n\t\t6. Xuat du lieu theo LRN");
		printf("\n\t\t7. Xuat du lieu theo RLN");
		printf("\n\t\t8. Count SNT");
		printf("\n\t\t0. Exit");
		printf("\n\n\t\t==========MENU==========");
		
		int choice;
		printf("\nNhap lua chon ");
		scanf("%d",&choice);
		if(choice<0 || choice>8){
			printf("\nVui long nhap lai");
		}
		else if(choice==1){
			int x;
			printf("\nNhap x can them: ");
			scanf("%d",&x);
			Insert(t,x);
		}
		else if(choice==2){
			printf("\n\n\tDUYET THEO NLR:\n");
			NLR(t);
		}
		else if(choice==3){
			printf("\n\n\tDUYET THEO NRL:\n");
			NRL(t);
		}
		else if(choice==4){
			printf("\n\n\tDUYET THEO LNR:\n");
			LNR(t);
		}
		else if(choice==5){
			printf("\n\n\tDUYET THEO RNL:\n");
			RNL(t);
		}
		else if(choice==6){
			printf("\n\n\tDUYET THEO LRN:\n");
			LRN(t);
		}
		else if(choice==7){
			printf("\n\n\tDUYET THEO RLN:\n");
			RLN(t);
		}
		else if(choice==8){
			int count =0;
			CountSNT(t,count);
			printf("\n\n\tSo luong SNT:%d\n",count);

		}
		else{
			break;
		}
	}
	
}

int main(){
	PtrNode t;
	Init(t);
	MENU(t);
	
	return 0;
}
