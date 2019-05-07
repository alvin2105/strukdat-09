/*
Nama	: Alvin
NPM		: 140810180013
kelas	: A
Materi	: Stack  list reversing a word
*/
#include <iostream>
#include<string.h>
using namespace std;

const int maxElmt=255;

struct elmtList{
	char isi;
	elmtList*next;
};

typedef elmtList* pointer;
typedef pointer list;

void createStack(list&top){
	top=NULL;
}

void createElmt(pointer&pBaru,char k){
	pBaru=new elmtList;
	pBaru->isi=k;
	cout<<pBaru->isi;
	pBaru->next=NULL;
}

void push(list&top, pointer pBaru){
	if (top==NULL)
		top=pBaru;
	else{
		pBaru->next=top;
		top=pBaru;
	}
}

void pop(list&top, pointer&pHapus){
	if (top==NULL){
		pHapus=NULL;
		cout<<"stack kosong, tidak ada yang dihapus"<<endl;
	}
	else if(top->next==NULL){
		pHapus=top;
		top=NULL;
	}
	else{
		pHapus=top;
		top=top->next;
		pHapus->next=NULL;
	}
	cout<<pHapus->isi;
}

main(){
	list top;
	pointer s,pHapus;
	char kata[maxElmt];

	cout<<"------------------------"<<endl;
	cout<<"STACK LIST PEMBALIK KATA"<<endl;
	cout<<"------------------------"<<endl;

	cout<<"Masukkan kata\t: ";
	cin>>kata;

	createStack(top);

	cout<<endl<<"Sebelum dibalik\t: ";
	for (int i=0; i<strlen(kata); i++){
		createElmt(s,kata[i]);
		push(top,s);
	}
	cout<<endl<<"Sesudah dibalik\t: ";
	for (int i=0; i<strlen(kata); i++){
		pop(top,pHapus);
	}
}
