#include<string>
#include<iostream>
#include <chrono>
#include <math.h>
#include<cmath>
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
		//	cout<<"name is"<<" "<<(cur->person).fname <<" " << (cur->person).lname<<" "<<"age is"<<" "<<(cur->person).age <<endl;		
			cur = cur->next;
		}
		delete cur;
	}
	




	void checki(long long int arr[],int x){
		long long int *arr2=arr;
		double err[3];
		double err2[3];
		double sum=0;
		double sum2=0;
		//cout << "Hi";
		for(int j=0;j<3;j++){
			
			err[j]=abs(10*arr[j]-arr[j+1]);

			err[j]=err[j]/(10*arr[j]);
		}
		for(int i=0;i<3;i++){
			sum=sum+err[i];
		}
		/*cout<<"the error is"<<" ";
		sum=sum/3;
		cout<<sum<<endl;
*/

		//cout << "Hi";
		for(int j=0;j<3;j++){
			
			err2[j]=abs(arr2[j]-arr2[j+1]);

			err2[j]=err2[j]/(arr2[j]);
		}
		for(int i=0;i<3;i++){
			sum2=sum2+err2[i];
		}
		/*cout<<"the from linear is"<<" ";
		sum2=sum2/3;
		cout<<sum2<<endl;
		*/
		if(x==2 ){
			cout<<"the function is of order O(nlogn) "<<endl;
		}
		if(x==1 ){
			cout<<"the function is of order O(1)"<<endl;
		}
	}



	DLLNode *merge(DLLNode *first, DLLNode *second)
{
    // If first linked list is empty
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
    DLLNode *second = split(head);
 
    // Recur for left and right halves
    head = mergeSort(head);
    second = mergeSort(second);
 
    // Merge the two sorted halves
    return merge(head,second);
}

DLLNode *split(DLLNode *head)
{
    DLLNode *fast = head,*slow = head;
    while (fast->next && fast->next->next)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    DLLNode *temp = slow->next;
    slow->next = NULL;
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
	int age,aage,sum,iter,y;
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
	//cout<<endl;

	list->mergesort();
	list->datadisp();





		//for imperical testing of merge function
		sum=0;
		cout<<endl;
			cout<<"the emperical time requuired for merge sort is"<<endl;
			long long int sumarr[4];
			for(int index=0; index<4;index++){
				int n = pow(10, index), iter = 100;
				long long int arr[n];
				for(int j = 1; j <= n; j++){
					//auto age1 = rand() % 100 + 1;
					auto start = chrono::steady_clock::now();
					for (int i = 1; i < n; i++) {
						age = rand() % 100 + 1;
						list->mergesort(); 
					}
					auto end = chrono::steady_clock::now();
					arr [j]= chrono::duration_cast<chrono::nanoseconds>(end - start).count();
				}
				
				for(int i=0;i<n;i++){
					sum = sum+ arr[n];
				}
				sum=sum/n;
				sumarr[index]=sum;
			}

			for(int index=0; index<4;index++){
				cout<<"input of"<<" "<<pow(10, index)<<" requires ";
				cout<<sumarr[index]<<" "<<endl;
			}
			y=2;
			cout<<endl;
			list->checki(sumarr,y);
			cout<<endl;



	// //for imperical testingof insert node
	// sum=0;
	// cout<<"the time for 1, 10, 100, 1000 input for insertnode is"<<endl;
	// long long int sumarr3[4];
	// for(int index=0; index<4;index++){
	// 	int n = pow(10, index), iter = 100;
	// 	long long int arr[n];
	// 	for(int j = 1; j <= n; j++){
	// 		auto age1 = rand() % 100 + 1;
	// 		Person person;
	// 		person.fname = "Kunal";
	// 		person.lname = "Jangid";
	// 		person.age = age1;
	// 		auto start = chrono::steady_clock::now();
	// 		list->CreateNode(person);
	// 		for (int i = 1; i < n; i++) {
	// 			age = rand() % 100 + 1;
	// 			list->insert(person); }
	// 			auto end = chrono::steady_clock::now();
	// 			arr [j]= chrono::duration_cast<chrono::nanoseconds>(end - start).count();
	// 		}
	// 		for(int i=0;i<n;i++){
	// 			sum = sum + arr[n];
	// 		}
	// 		sum=sum/n;
	// 		sumarr3[index]=sum;
	// 	}

	// 	for(int index=0; index<4;index++){
	// 		cout<<sumarr3[index]<<" ";
	// 	}
	// 	y=1;

	// 	list->checki(sumarr3,y);
	// 	cout<<endl;

}

