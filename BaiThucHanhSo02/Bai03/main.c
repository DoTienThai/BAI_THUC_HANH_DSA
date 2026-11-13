#include<stdio.h>
#include<stdlib.h>
typedef struct    {
    	char hoten[30];
    	int masv;
    	float d1, d2, d3;
}Data;
typedef struct tagNode    {
    	Data infor;
    	struct tagNode *link;
}Node;
typedef struct    {
    	Node *pHead;  
    	Node *pTail;
    	int spt;
}LList;

void initList(LList *L)
    {
    	L->pHead = NULL; //L->pHead : giá trị của pHead, mà pHead là con trỏ nên giá trị ở đây là địa chỉ của nút mà pHead đang trỏ tới
    	L->pTail = NULL;
    	L->spt = 0;
    }

int emptyList(LList L)
 {
    	return (L.spt == 0); 
}

void insert_Head(LList *L, Data x)// thêm một nút vào đầu danh sách
    {
    	Node *pp;
    	pp = (Node*) malloc(sizeof(Node));
    	pp->infor = x;
    	pp->link = NULL;
    	if(emptyList(*L)){
    			L->pHead = pp;
    			L->pTail = pp;
    		}  	
        else {
    		pp->link = L->pHead;
    		L->pHead = pp;
    		}
    	L->spt++;
    }
void insert_Tail(LList *L, Data x)// thêm một nút vào cuối danh sách
{
	Node *pp;
	pp = (Node*) malloc(sizeof(Node));
	pp->infor = x;
	pp->link = NULL;
	if(emptyList(*L)){
		L->pHead=pp;
		L->pTail=pp;
	}
	else{
		L->pTail->link = pp;
		L->pTail =pp;
	}
	L->spt++;

}
void insert_After(LList *L,Data x,Node *q){ //Thêm một nút vào sau một nút q
	Node *pp;
	pp=(Node*)malloc(sizeof(Node));
	pp->infor=x;
	pp->link = q->link;
	q->link = pp;
	if(q==L->pTail) L->pTail=pp;
	L->spt++;
}
Node* timNut(LList L,int ma){
	Node *pp= L.pHead;
	while(pp != NULL){
		if(pp->infor.masv == ma) return pp;
		pp = pp->link;
	}
	return NULL;
}
void nhap(Data *x){
    printf("Nhap ma sv: ");
    scanf("%d", &(x->masv));
    if(x->masv > 0){
        printf("Nhap họ và tên: ");
        scanf("%s", (x->hoten));
        printf("Nhap diem mon 1: ");
        scanf("%f", &(x->d1));
        printf("Nhap diem mon 2: ");
        scanf("%f", &(x->d2));
        printf("Nhap diem mon 3: ");
        scanf("%f", &(x->d3));
    }
}
void in(Data x){
    printf("Ten: %s, Ma: %d, Diem 1: %.2f, Diem 2: %.2f, Diem 3: %.2f\n", 
            x.hoten, x.masv, x.d1, x.d2, x.d3);
}
void processList(LList L){
    Node *pp = L.pHead;
    while( pp != NULL ){
        	in(pp->infor); //in dữ liệu trong node 
        	pp = pp->link;
    	}
}


int main(){
    LList L;
	int kt = 0;
	Data x;
	initList(&L); 
	do{
	    printf("\nChuong trinh lam viec voi DSLK don SV\n");
	    printf("\n1: Them nut vao dau danh sach");
	    printf("\n2: Them nut vao cuoi danh sach");
	    printf("\n3: Them nut vao sau mot nut khac trong danh sach");
	    printf("\n9: Duyet ds");
	    printf("\n0: Thoat");
	    printf("\nMoi ban chon: ");
	    int chon;
	    scanf("%d", &chon);
	    switch(chon){
	        case 1: 
	            printf("Nhap thông tin sv can them\n");
	            nhap(&x);
	            if(x.masv > 0) 
                	insert_Head(&L, x);
            	break;
            case 2:	
	            printf("Nhap thong tin sinh vien can them\n");
				nhap(&x);
				if(x.masv>0){
					insert_Tail(&L,x);
				}
            	break;
            case 3:{
	            int ma;
				printf("Nhap mã sv của nút cần chèn phía sau: ");
				scanf("%d",&ma);
				Node *q = timNut(L,ma);
				if(q==NULL) printf("Khong tim thay sinh vien trong danh sach");
				else{
					printf("Nhap thong tin sinh vien can them\n");
					nhap(&x);
					if(x.masv>0){
						insert_After(&L,x,q);
					}
				}
			}

            	break;
            case 9: 
                processList(L);
                break;    
            case 0: 
                printf("Bye bye\n");
	            kt = 1;
        }
	}while(kt==0); 
}
