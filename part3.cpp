	#include<string>
	#include<iostream>
using namespace std;
class Person{
private: 
public:
	int age;
	string fname;
	string lname;
	Person *fwd, *back;
	string getfname(){
		return fname;
	}
	string getlname(){
		return lname;
	}
	int getage(){
		return age;
	}
	void setfname(string a){
		fname=a;
	}
	void setlname(string a){
		lname=a;
	}
	void setage(int ag){
		age=ag;
	}


};

class DLLNode{
private:
public:
	Person person;
	DLLNode * next;
	DLLNode * prev;
};


class DLL{
private:
public:
	DLLNode * head;
	DLLNode * tail;
	void CreateNode(Person p){
		DLLNode *l= new DLLNode ;
		head = l;
		tail = l;
		l->person = p ;
		l->next = NULL;
		l->prev = NULL;
	}
	void insert(Person p){
		DLLNode * l = new DLLNode;
		tail->next = l;
		l->person = p;
		l->next = NULL;
		l->prev = tail;
		tail = l;
	}


	void datadisp(){
		DLLNode * cur = head;
		while(cur!=NULL){
			cout<<(cur->person).fname <<" " << (cur->person).lname<<"-"<<(cur->person).age <<endl;		
			cur = cur->next;
		}
		cout<<endl<<endl;
		delete cur;
	}
	







	DLLNode *merge(DLLNode *first, DLLNode *second)
{
    // If first linked list is empty
    datadisp();
    if (!first)
        return second;
 
    // If second linked list is empty
    if (!second)
        return first;
 
    // Pick the smaller value
    if ((first->person).age < (second->person).age)
    {
        first->next = merge(first->next,second);
        first->next->prev = first;
        first->prev = NULL;
        return first;
        datadisp();
    }
    else
    {
        second->next = merge(first,second->next);
        second->next->prev = second;
        second->prev = NULL;
        return second;
    }

    
}

 void mergesort(){
 	DLLNode *temp = mergeSort(head);
 }

DLLNode *mergeSort(DLLNode *head)
{
    if (!head || !head->next)
        return head;
    DLLNode *second = SPLIT(head);
 
    // Recur for left and right halves
    head = mergeSort(head);
    second = mergeSort(second);
 
    // Merge the two sorted halves
    return merge(head,second);
}

DLLNode *SPLIT(DLLNode *head)
{
    DLLNode *f1 = head,*fp = head;
    while (f1->next && f1->next->next)
    {
        f1 = f1->next->next;
        fp = fp->next;
    }
    DLLNode *temp = fp->next;
    fp->next = NULL;
    return temp;
}


void swap(Person *A, Person *B)
{
    Person temp = *A;
    *A = *B;
    *B = temp;
}

};


int main(){
	int t;
	string fname,lname,str,fin,lin;
	int age,aage;
	//cout<<"enter the number of inputs you want"<<endl;
	cin>>t;


	DLL * list = new DLL;
	bool first = true;

	Person a;
	for(int i=0;i<t;i++){
		//cout<<"enter your first name"<<endl;
		cin>>fname;
		a.setfname(fname);
		//cout<<"enter your last name"<<endl;
		cin>>lname;
		a.setlname(lname);
		//cout<<"enter your age"<<endl;
		cin>>age;
		a.setage(age);
		if(first == true){
			list->CreateNode(a);
			first = false;
		}
		else
			list->insert(a);

	}
	list->datadisp();
	cout<<endl;

	list->mergesort();
	list->datadisp();



}

