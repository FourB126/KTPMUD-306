#include<iostream>
#include<stack>
#include<string>
#include<queue>

using namespace std;

void Nhap(int arr[], int &n){
    cout <<"Nhap n: " ;
    cin>>n;
    cout << "Nhap mang: "<<endl;
        for(int i=0; i<n;i++){
            cin >> arr[i];
        }
}

/*

void bubble_sort(int arr[],int &n){ //o=n^2
    int k;
    for(int i=0; i<n-1; i++){
            for(int j=i; j<n; j++){
                if(arr[i]<arr[j]){
                    k=arr[i];
                    arr[i]=arr[j];
                    arr[j]=k;
                }
            }
        }
}

void insertionSort(int arr[],int &n) {//o=n^2
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void quickSort(int arr[], int left, int right) {//o=nlogn
    int i = left, j = right;
    int pivot = arr[(left + right) / 2];

    while (i <= j) {
        while (arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if (i <= j) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (left < j) quickSort(arr, left, j);
    if (i < right) quickSort(arr, i, right);
}
*/
void Xuat(int arr[],int &n) {
    cout<<"Mang sau do la: ";
    for(int i=0; i<n; i++){
        cout << arr[i]<<" ";
    }
}

// ********Linked list***********8
//Khai bao cau truc mot node
struct node{
    int data; // du lieu trong mot node
    struct node *pNext; // Con tro de lien ket giua cac node
};
typedef struct node NODE;// thay the struct node = NODE

// thay the cau truc linkedlist
struct list{
    NODE *pHead;// node quan ly dau list
    NODE *pTail;//node quan ly cuoi  list
};
typedef struct list LIST;// thay the struct list = LIST
//khoi tao linked list
void KhoiTao(LIST &l){
    // cho 2 node tro den null vi list chua co phan tu

    l.pHead = NULL;
    l.pTail = NULL;
}
// Ham khoi tao 1 cai node
NODE * KhoiTaoNODE(int x){
    NODE *p = new NODE;// cap phat vung nho cho NODE p
    if( p==NULL){
        cout << "Khong the cap phat bo nho";
        return NULL;
    }
    p->data = x;// truyen gia tri x vao data
    p->pNext = NULL;//dau tien khai bao node thi node do chua co lket node nao 
    return p;
}
//them node vao dau list
void ThemVaoDau(LIST &l,NODE*p){
    if(l.pHead==NULL){
        l.pHead=l.pTail =p;// node dau = node cuoi = p
    }
    else{
        p->pNext = l.pHead;//Cho con tro node can them la node p lket node dau - pHead
        l.pHead = p;//cap nhat lai pHead la node p
    }
}
//them node p vao cuoi list
void ThemVaoCuoi(LIST &l,NODE*p){
    if(l.pHead==NULL){
        l.pHead=l.pTail =p;// node dau = node cuoi = p
    }
    else{
       l.pTail -> pNext =p;//cho con tro pTail lien ket vs node p
       l.pTail = p;//cap nhat lai
    }
}
//Them node p vao sau node q
void Them_p_Vao_Sau_q(LIST &l,NODE*p){
    int x;
    cout<<"\nNhap q: ";
    cin>>x;
    NODE *q = KhoiTaoNODE(x);
    if(q->data==l.pHead->data && l.pHead ->pNext==NULL){
        ThemVaoCuoi(l,p);
    }
    else{
        //duyet list
        for(NODE*k=l.pHead;k != NULL; k= k-> pNext){
            if (q-> data== k-> data){
                NODE* h = KhoiTaoNODE(p->data);//khoi tao node h moi sau q
                NODE*g = k->pNext;//cho node g tro den node nam sau q
                h->pNext = g;// Tao moi lien ket cua h va g
                k->pNext = h;// Tao moi lien ket q toi h
            }
        }
    }
}

//Them node p vao truoc node q
void Them_p_Vao_Truoc_q(LIST&l,NODE *p){
    int x;
    cout <<"Nhap node q: ";
    cin >>x;
    NODE* q = KhoiTaoNODE(x);
    if(q->data==l.pHead->data && l.pHead ->pNext==NULL){
        ThemVaoDau(l,p);
    }
    else{
        NODE*g = new NODE;//la node giu lket vs cac node truoc q
        for( NODE*k=l.pHead; k!= NULL; k=k->pNext){
            if(q->data==k->data){
                NODE*h = KhoiTaoNODE(p->data);
                h->pNext = k;
                g->pNext = h;
            }
            g=k;//duy tri ket noi voi cac nut truoc q
        }
        if(q-> data == l.pHead->data){
            ThemVaoDau(l,p);
        }
    }
}

//Them Node p vao vi tri bat ki
void Them_p_Vao_Vtri(LIST &l, NODE* p, int vtri,int n){
    if(l.pHead == NULL|| vtri == 1){
        ThemVaoDau(l,p);
    }
    else if( vtri==n+1){
        ThemVaoCuoi(l,p);
    }
    else{
        int count=0;
        NODE* g = new NODE;//la node giu lket vs cac node truoc q
        for( NODE*k=l.pHead; k!= NULL; k=k->pNext){
            count++;
            if(count == vtri){
                NODE*h = KhoiTaoNODE(p->data);
                h->pNext = k;
                g->pNext = h;
                break;
            }
            g=k;//duy tri ket noi voi cac nut truoc q
        }
        
    }
}
//Tim Max
int Max(LIST l){
    int max = l.pHead->data;
    // Bat dau duyet tu Node 2
    for( NODE*k=l.pHead-> pNext; k != NULL; k=k->pNext){
        if( max < k->data){
            max = k-> data;
        }
    }
    return max;
}
//xuat ra list
void XuatList(LIST l){
    for(NODE *k =l.pHead;k!= NULL;k=k->pNext){
        cout<< k-> data<<" ";
    }
}

//Xoa Dau
void DeleteHead(LIST& l){
    if(l.pHead==NULL){
        return;
    }
    NODE* p = l.pHead;//p la node se xoa
    l.pHead = l.pHead->pNext;//Cap nhat lai pNext
    delete p;
}

//Xoa Cuoi
void DeleteTail(LIST& l){
	if(l.pHead==NULL){
		return;
	}
	for(NODE* k=l.pHead;k!=NULL;k=k->pNext){
		if(k->pNext == l.pTail){
			delete l.pTail;
			k->pNext = NULL;
			l.pTail = k;
			return;
		}
	}
}

//Xoa node sau q
void XoaSauNode_q(LIST &l,NODE *q)
{
    if(l.pHead->data == q->data && l.pHead->pNext == NULL) {
        return;
    }
    if(l.pTail->data == q->data){
        return;
    }
    for(NODE *k = l.pHead; k != NULL; k = k->pNext){
        if(k->data == q->data){
            NODE *g = k->pNext;
            if(g->pNext != NULL){
                k->pNext = g->pNext;
                delete g;
                
            }
            else{
                k->pNext = NULL;
                l.pTail = k;
                delete g;
                
            }
        }
    }
}

//Xoa NODE bat ki
void XoaNODE(LIST& l, int x){
    if(l.pHead->data == x){
        DeleteHead(l);
        return;
    }
    else if(l.pTail->data == x){
        DeleteTail(l);
        return;
    }
    else{
        NODE *g = new NODE;
        for(NODE *k=l.pHead; k != NULL; k = k->pNext){
            if(k->data ==x){
                g->pNext = k->pNext;
                delete k;
            }
            g=k;
        }
    }
}
void GiaiPhongList(LIST &l){
    NODE *k = NULL;
    while (l.pHead != NULL){
        k = l.pHead;
        l.pHead = l.pHead->pNext;
        delete k;
    }
}
void Menu(LIST &l){
    int choose;
    while(1){
        system("cls");
        cout << "1 Them node vao dau danh sach";
        cout<<" \n2 Them vao cuoi danh sach";
        cout<<" \n3 Xuat ";
        cout<<"\n4 Them p vao sau q";
        cout<<"\n5 Them p vao truoc q";
        cout<<"\n6 Them p vao bat ki";
        cout<<" \n7 Xoa Dau ";
        cout<<" \n8 Xoa Cuoi ";
        cout<<"\n9 Xoa node sau q";
        cout <<"\n10 Xoa node vi tri bat ki";
        cout<< "\n0 Exit";

        cout << "\n\nNhap:";
        cin >> choose;
        if (choose == 1){
            int x;
            cout<<"Nhap gia tri so nguyen: " ;
            cin>>x;
            NODE *p = KhoiTaoNODE(x);
            ThemVaoDau(l,p);
        }
        else if (choose == 2){
            int x;
            cout<<"Nhap gia tri so nguyen: " ;
            cin>>x;
            NODE *p = KhoiTaoNODE(x);
            ThemVaoCuoi(l,p);
        }
        else if(choose  ==3){
            XuatList(l);
            system("pause");
        }
        else if(choose == 4){
            int x;
            cout << "Nhap gia tri node p: ";
            cin >> x;
            NODE *p = KhoiTaoNODE(x);
            Them_p_Vao_Sau_q(l,p);
        }
        else if(choose == 5){
            int x;
            cout << "Nhap gia tri node p: ";
            cin >> x;
            NODE *p = KhoiTaoNODE(x);
            Them_p_Vao_Truoc_q(l,p);
        }
        else if(choose == 6){
            int n = 0;
            for(NODE* k= l.pHead;k!=NULL; k= k-> pNext){//lay so luong node
                n++;
            }
            int x;
            cout << "Nhap gia tri node p: ";
            cin >> x;
            NODE *p = KhoiTaoNODE(x);
            int vtri;
            do{
                cout<<"\nNhap vi tri can them: ";
                cin>>vtri;
                if(vtri <1 || vtri > n+1){
                    cout <<"\nVi tri khong hop le";
                }
            }while(vtri <1 || vtri > n+1);
            Them_p_Vao_Vtri(l,p,vtri,n);
        }
        else if(choose == 7){
            DeleteHead(l);
        }
        else if(choose ==8){
            DeleteTail(l);
        }
        else if(choose ==9){
            int x;
            cout<<"\nNhap q: ";
            cin>>x;
            NODE*q = KhoiTaoNODE(x);
            XoaSauNode_q(l,q);
        }
        else if (choose ==10){
            int x;
            cout <<"\nNhap node can xoa: ";
            cin >> x;
            XoaNODE(l,x);
        }
        else{
            break;
        }
    }
    system ("cls");
}
int main(){
    LIST l;
    KhoiTao(l);
	Menu(l);
    GiaiPhongList(l);
    system("pause");
    return 0;
}
