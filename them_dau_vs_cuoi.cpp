/*
    bài toán: nhập danh sách liên kết đơn các số nguyên. Tìm số lớn nhất trong danh sách.
*/

#include <stdio.h>
#include <stdlib.h>

//=============KHAI BÁO===========
//khai báo cấu trúc
struct node{
    int data;// dữ liệu của 1 node
    struct node *pNext;// con trỏ liên kết các node
};

typedef struct node NODE;

//khai báo cấu trúc của danh sách liên kết
struct list{
    node *pHead;// node đầu danh sách
    node *pTail;// node cuối danh sách
};

typedef struct list LIST;

//=============KHỞI TẠO===========
void khoitao(LIST *l){
    l->pHead = NULL;
    l->pTail = NULL;
}

//tạo một node
NODE *khoitaonode(int a){
    NODE *p;
    p = (NODE*)malloc(sizeof(struct node));// cấp phát vùng nhớ cho node p
    p->data = a;// chuyền giá trị a cho node p
    p->pNext = NULL;// khi khai báo node thì chưa có node liên kiết => con trỏ trỏ tới null
    return p;
}

//thêm node vào đầu danh sách
void themvaodau(LIST *l, NODE *p){
    //danh sách rỗng
    if(l->pHead == NULL){
        l->pHead = l->pTail = p; //node đầu cũng là node cuối cũng là p
    }else{
        p->pNext = l->pHead; //cho con trỏ node thêm liên kết tới node đầu
        l->pHead = p; //cập nhập lại phead bằng p
    }
}

//thêm vào cuối
void themvaocuoi(LIST *l, NODE *p){
    //danh sách rỗng
    if(l->pHead == NULL){
        l->pHead = l->pTail = p;
    }else{
        l->pTail->pNext = p; //cho con trỏ của ptail liên kết với node p
        l->pTail = p; //cập nhập p làm node ptail
    }
}

//tìm số lớn nhất
int solonnhat(LIST l){
    int max = l.pHead->data; //giả sử node đầu là lớn nhất
    //bắt đầu duyệt từ số thứ 2
    for(NODE *k = l.pHead->pNext; k != NULL; k = k->pNext){
        if(max < k->data){
            max = k->data;
        }
    }
    return max;
}

void xuat(LIST l){
    for(NODE *k = l.pHead; k != NULL; k = k->pNext){
        printf("\t%d", k->data);
    }
}

void giai_phong_vung_nho(LIST &l){
    NODE *i = NULL;
    while(l.pHead != NULL){
        i = l.pHead;
        l.pHead = l.pHead->pNext;
        free(i);
    }
}

int main(){
    LIST l;
    khoitao(&l); //khơi tạo danh sách liên kết đơn

    int n;
    printf("\nnhap so luong node can nhap: ");
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int x;
        printf("\nnhap gia tri so nguyen: ");
        scanf("%d", &x);
        NODE *p = khoitaonode(x); //khởi tạo một node
        themvaocuoi(&l, p);
    }
    printf("\nso vua nhap la: ");
    xuat(l);
    
    printf("\nso lon nhat la: %d", solonnhat(l));

    giai_phong_vung_nho(l);
}
