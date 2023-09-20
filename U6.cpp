#include"stdio.h"
#include"stdlib.h"
#include"string.h"

typedef struct Node{
	int data;
	struct Node *pLeft;
	struct Node *pRight;
}*PtrNode,Node;

// Khoi tao
void Init(PtrNode &t){
	t = NULL;
}

// Kiem tra rong
bool IsEmpty(PtrNode t){
	t == NULL;
}

// Kiem tra day
bool IsFull(PtrNode t){
	return(t == NULL);
}

// Them phan tu
void Insert(PtrNode &t,int x){
	if(t == NULL){
		PtrNode p = new Node;
		p->data = x;
		p->pLeft = NULL;
		p->pRight = NULL;
		t = p;
	}else{
		if(t->data>x){
			Insert(t->pLeft,x);
		}else if(t->data<x){
			Insert(t->pRight,x);
	    }
	}
}

void PreOder01(PtrNode t){
	// Duyet cay theo NLR
	if(t != NULL){
		printf("%4d",t->data);
		PreOder01(t->pLeft);
		PreOder01(t->pRight);
	}
}

void PreOder02(PtrNode t){
	// Duyet cay theo NRL
	if(t != NULL){
		printf("%4d",t->data);
		PreOder02(t->pRight);
		PreOder02(t->pLeft);
	}
}

void InOder01(PtrNode t){
	// Duyet cay theo LNR
	if(t != NULL){
		InOder01(t->pLeft);
		printf("%4d",t->data);
		InOder01(t->pRight);
	}
}

void InOder02(PtrNode t){
	// Duyet cay theo RNL
	if(t != NULL){
		InOder02(t->pRight);
		printf("%4d",t->data);
		InOder02(t->pLeft);
	}
}

void PostOder01(PtrNode t){
	// Duyet cay theo LRN
	if(t != NULL){
		PostOder01(t->pLeft);
		PostOder01(t->pRight);
		printf("%4d",t->data);
	}
}

void PostOder02(PtrNode t){
	// Duyet cay theo RLN
	if(t != NULL){
		PostOder02(t->pRight);
		PostOder02(t->pLeft);
		printf("%4d",t->data);
	}
}

// Tim kiem phan tu 
PtrNode TimKiem(PtrNode t, int x){
	// Kiem tra xem cay rong ko
	if(t == NULL){
		return NULL;
	}else{
		if(t->data>x){ // duyet sang trai
			TimKiem(t->pLeft,x);
		}else if(t->data<x){ // duyet sang phai
			TimKiem(t->pRight,x);
		}else{ // t->data == x
			return t; // tra ve node can tim
		}
	}
}

// Xuat node co 2 cay con
void Node_Co_2_Con(PtrNode t){
	if(t != NULL){
		if(t->pLeft != NULL && t->pRight != NULL)
			printf("%4d",t->data);

		Node_Co_2_Con(t->pLeft);
		Node_Co_2_Con(t->pRight);

	}
}

// Xuat node co 1 cay con
void Node_Co_1_Con(PtrNode t){
	if(t != NULL){
		if((t->pLeft != NULL && t->pRight == NULL) || (t->pLeft == NULL && t->pRight != NULL))
			printf("%4d",t->data);
		Node_Co_1_Con(t->pLeft);
		Node_Co_1_Con(t->pRight);
	}
}

// Xuat node(la) khong co cay con trai va phai
void Node_La(PtrNode t){
	if(t != NULL){
		if(t->pLeft == NULL  && t->pRight == NULL)
			printf("%4d",t->data);
		Node_La(t->pLeft);
		Node_La(t->pRight);
	}
}
/* Tim MAX THEO CACH 1 */
int MAX = INT_MIN;
int timMax01(PtrNode t){
	if(t != NULL){
	    if(MAX < t->data){
	        MAX = t->data;
	    }
	    timMax01(t->pLeft);
	    timMax01(t->pRight);
	}
}

/* Tim MAX THEO CACH 2*/
int timMax02(PtrNode t){
	if(t->pLeft == NULL && t->pRight == NULL)
		return t->data;
		
	int max = t->data; // gan gia tri max = data cua node cha
	
	// Neu node cha ton tai cay con trai
	if(t->pLeft != NULL){
		int left = timMax02(t->pLeft); // gia tri node ngoai cung nhat cua cay con trai
		if(max<left){
			max = left;
		}
	}
	// Neu code cha ton tai cay con phai
	if(t->pRight != NULL){
		int right = timMax02(t->pRight); // gia tri node ngoai cung nhat cau cay con phai 
		if(max<right){
			max = right;
		}
	}
	return max; // Tra ve gia tri lon nhat 
}

/* Tim MAX THEO CACH 3*/
int timMax03(PtrNode t){
	if(t->pLeft == NULL && t->pRight == NULL)
		return t->data;
	return timMax03(t->pRight);
}
/* Tim MIN THEO CACH 1*/
int MIN = INT_MAX;
int timMin01(PtrNode t){
	if(t != NULL){
		if(MIN > t->data){
			MIN = t->data;
		}
		timMin01(t->pLeft);
		timMin01(t->pRight);
	}
}

/* Tim MIN THEO CACH 2*/
int timMin02(PtrNode t){
	if(t->pLeft == NULL && t->pRight == NULL)
		return t->data;
	int min = t->data;
	if(t->pLeft != NULL){
		int left = timMin02(t->pLeft); //gia tri node ngoai cung nhat cua cay con trai
		if(min>left)
			min = left;
	}
	if(t->pRight != NULL){
		int right = timMin02(t); // gia tri node ngoai cung nhat cau cay con phai 
		if(min>right)
			min = right;
	}
	return min;
}
/* Tim MIN THEO CACH 3 */
int timMin03(PtrNode t){
	if(t->pLeft == NULL && t->pRight == NULL)
		return t->data;
	return timMin03(t->pLeft);
}

// Tim node the de xoa cay co 2 con
void NodeTam(PtrNode &temp,PtrNode &X){
//	// CACH 1: 
//	// Duyet sang node trai nhat cau cay con phai
//	if(X->pLeft != NULL){
//		NodeTam(temp,X->pLeft);
//	}else{
//		// Da tim ra node trai nhat
//		temp->data = X->data; // Cap nhat du lieu node can xoa cho node tam
//		temp = X; // node temp la node se xoa
//		X = X->pRight; // X->pRight: NULL
//	
//	}
// CACH 2: 
	// Duyet sang node phai nhat cau cay con trai
	if(X->pRight != NULL){
		NodeTam(temp,X->pRight);
	}else{
		// Da tim ra node trai nhat
		temp->data = X->data; // Cap nhat du lieu node can xoa cho node tam
		temp = X; // node temp la node se xoa
		X = X->pLeft; // X->pLeft: NULL
	
	}
}

// Xoa node o vi tri bat ky doi voi cay co 1 con
void XoaX(PtrNode &t,int value){
	// neu cay rong
	if(t == NULL){
		return; // ket thuc
	}else{
		// Neu value < node goc
		if(value<t->data){
			XoaX(t->pLeft,value); // duyet sang trai
		}else if(value>t->data){
			XoaX(t->pRight,value); // duyet sang phai
		}else{ // value == t->data
			PtrNode temp = t; // node temp dung de xoa
			if(t->pLeft == NULL){
				//  duyet Cay con phai
				t = t->pRight; // cap nhat
			}else if(t->pRight == NULL){
				// duyet Cay con trai
				t = t->pLeft;  // cap nhat
			}else{ // Tim duoc node trai nhat cua cay con phai(node co 2 con)
			
				// CACH 1: TIM NODE TRAI NHAT CUA CAY CON PHAI
				// node X la node tam cho node can xoa , dung de tim node trai nhat
				//NodeTam(temp,t->pRight);
				
				// CACH 2: TIM NODE PHAI NHAT CUA CAY CON TRAI
				NodeTam(temp,t->pLeft);
			}
			free(temp); // xoa node temp
		}	
		
	}
}



void MENU(PtrNode &t){
	int choice;
	while(true){
		printf("\n*************** MENU ***************\n");
		printf("**  1. Nhap du lieu               **\n");
		printf("**  2. Xuat PreOder01(NLR):       **\n");
		printf("**  3. Xuat PreOder02(NRL):       **\n");
		printf("**  4. Xuat InOder02(LNR):        **\n");
		printf("**  5. Xuat InOder02(RNL):        **\n");
		printf("**  6. Xuat PostOder02(LRN):      **\n");
		printf("**  7. Xuat PostOder02(RLN):      **\n");
		printf("**  8. Tim Kiem                   **\n");
		printf("**  9. Xuat Node Co 2 Cay Con     **\n");
		printf("**  10. Xuat Node Co 1 Cay Con    **\n");
		printf("**  11. Xuat Node La              **\n");
		printf("**  12. Xuat Gia Tri Max Cach 1   **\n");
		printf("**  13. Xuat Gia Tri Max Cach 2   **\n");
		printf("**  14. Xuat Gia Tri Min Cach 1   **\n");
		printf("**  15. Xuat Gia Tri Min Cach 2   **\n");
		printf("**  16. Xoa Gia Node 1 Con        **\n");
		printf("**  0. Exit !                     **\n");
		printf("*************** MENU ***************\n");
		printf("\nNhap lua chon: ");
		scanf("%d",&choice);
		if(choice <0 || choice >16){
			printf("\nVui long nhap lai !");
		}
		else if(choice==1){
			int x;
			printf("\nNhap x can them(x = ): ");
			scanf("%d",&x);
			Insert(t,x);
		}else if(choice==2){
			printf("\n\n\tDUYET CAY THEO NLR:\n");
			PreOder01(t);
		}else if(choice == 3){
			printf("\n\n\tDUYET CAT THEO NRL:\n");
			PreOder02(t);
		}else if(choice == 4){
			printf("\n\n\tDUYET CAY THEO LNR:\n");
			InOder01(t);
		}else if(choice == 5){
			printf("\n\n\tDUYET CAY THEO RNL:\n");
			InOder02(t);
	    }else if(choice == 6){
	    	printf("\n\n\tDUYET CAY THEO LRN:\n");
	    	PostOder01(t);
		}else if(choice == 7){
			printf("\n\n\tDUYET CAY THEO RLN: \n");
			PostOder02(t);
		}else if(choice == 8){
			int x;
			printf("\nNhap x can tim = ");
			scanf("%d",&x);
			PtrNode p = TimKiem(t,x);
			if(p == NULL){
				printf("\nKhong tim thay x !");
			}else{
				printf("\nTim thay x !");
			}
		}else if(choice == 9){
			printf("\n\n\tCAC NODE CO 2 CAY CON LA: \n");
			Node_Co_2_Con(t);
		}else if(choice == 10){
			printf("\n\n\tCAC NODE CO 1 CAY CON LA: \n");
			Node_Co_1_Con(t);
		}else if(choice == 11){
			printf("\n\n\tCAC NODE LA : \n");
			Node_La(t);
		}else if(choice == 12){
			timMax01(t);
			printf("\n\n\tGIA TRI NODE MAX LA : %d\n",MAX);
		}else if(choice == 13){
			printf("\n\n\tGIA TRI NODE MAX LA : %d\n",timMax02(t));	
		}else if(choice == 14){
			timMin01(t);
			printf("\n\n\tGIA TRI NODE MIN LA : %d\n",MIN);		
		}else if(choice == 15){
			printf("\n\n\tGIA TRI NODE MIN LA: %d",timMin02(t));
		}else if(choice == 16){
			int value;
			printf("\nNhap value can xoa: ");
			scanf("%d",&value);
			printf("\n\n\tDELETE SUCCESSFULL");
			XoaX(t,value);	
		}else{
			break;
		}
	}
}
int main(){
	PtrNode t;
	Init(t);
	MENU(t);
}

