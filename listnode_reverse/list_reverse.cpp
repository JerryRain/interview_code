#include<iostream>
#include<stdlib.h>
#include<stack>
using namespace std;


typedef struct Linklist{
	int n;
	struct Linklist *next;
	}Linklist;

Linklist * init(int &n){
	Linklist *L=(Linklist*)malloc(sizeof(Linklist));
	Linklist *q,*p;
	L->next=nullptr;
	q=L;
	int i;
	for(i=0;i<n;++i){
		p=(Linklist*)malloc(sizeof(Linklist));
		std::cout<<"请输入第" <<i+1<<"个值"<<std::endl;
		std::cin>>p->n;
		q->next=p;
		q=p;
	}
	p->next=nullptr;
	q=L;
	L=L->next;
	free(q);
	return L;
}

Linklist * reverse(Linklist *&l){
	Linklist *pre=nullptr,*pnext=nullptr;
	while(l!=nullptr){
		pnext=l->next;
		l->next=pre;
		pre=l;
		l=pnext;
	}
	return pre;
}

Linklist * printlist(Linklist *pNode)
{
    while(pNode!=NULL)
    {
        cout<<pNode->n<<" ";
        pNode=pNode->next;
    }
    cout<<endl;
}

int main(){
	Linklist *p;
	std::cout<<"请输入创建单链表数据元素个数:"<<std::endl;
	int n;
	std::cin>>n;
	p=init(n);
	cout << "原始链表：";
	printlist(p);

	p=reverse(p);
	cout << "反转链表为：";
	printlist(p);
	return 0;
} 
