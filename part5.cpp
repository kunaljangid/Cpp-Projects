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



	//DELETE FUNCTION BEGINS HERE
	void datadelete(string fname,string lname, int aage){
		DLLNode * cur = head;
		while(cur != NULL){
			if ((cur->person).age == aage && (cur->person).fname==fname && (cur->person).lname==lname){
				if (cur-> next == NULL && cur->prev == NULL)
				{
					head =NULL;
					tail = NULL;
					delete cur;
					return;

				}
				if (cur->next == NULL && cur->prev != NULL){
					cur->prev->next=NULL;
					tail = cur->prev;
					cur->prev = NULL;
				}
				else if (cur->prev == NULL && cur->next != NULL){
					cur->next->prev = NULL;
					head = cur->next;
					cur->next = NULL;
				} else
				{
					cur->next->prev = cur->prev;
					cur->prev->next = cur->next;
					cur->prev = NULL;
					cur->next = NULL;
				}
				delete cur;
				break;
			}
			cur = cur->next;
		}
	}
	//DELETE FUNCTIION ENDS HERE


	void datadisp(){
		DLLNode * cur = head;
		while(cur!=NULL){
			cout<<"name is"<<" "<<(cur->person).fname <<" " << (cur->person).lname<<" "<<"age is"<<" "<<(cur->person).age <<endl;		
			cur = cur->next;
		}
		delete cur;
	}
	//DELETE FUNCTION ENDS HERE




	// SEARCH FUNCTION BEGINS HERE


	void search(string fname,string lname, int aage){
		DLLNode * cur = head;
		int h=0;
		while(cur != NULL){
			if ((cur->person).age == aage && (cur->person).fname==fname && (cur->person).lname==lname){

				cout<<(cur->person).fname <<" "<<(cur->person).lname <<" "<<(cur->person).age <<"the person was at index"<<" "<<i<<endl;
				h=1;

			}


			cur = cur->left;
		}
		if(h!=1){
			cout<<"sorry the person you searched is not in the records"<<endl;
		}
	}
	//SEARCH FUNCTION ENDS HERE




	//SORT FUNCTION BEGINS HERE
	void sort(int t){
		DLLNode * cur = head;
		Person temp;
		for(int i=0;i<t;i++){
			for(int j=0;j<t-1;j++){
				if((cur->person).age > (cur->next->person).age){
					temp=cur->person;
					cur->person=cur->next->person;
					cur->next->person=temp;
							/*int tage;
							string tfname, tlname;
							tage=(cur->next->person).age;
							(cur->next->person).age=(cur->person).age;
							(cur->person).age=tage;


							tfname=(cur->next->person).fname;
							(cur->next->person).fname=(cur->person).fname;
							(cur->person).fname=tfname;


							tlname=(cur->next->person).lname;
							(cur->next->person).lname=(cur->person).lname;
							(cur->person).lname=tlname;
	*/
				}
				else if((cur->person).age == (cur->next->person).age){
					if((cur->person).fname > (cur->next->person).fname){
						temp=cur->person;
						cur->person=cur->next->person;
						cur->next->person=temp;

							/*	int tage;
							string tfname, tlname;
							tage=(cur->next->person).age;
							(cur->next->person).age=(cur->person).age;
							(cur->person).age=tage;


							tfname=(cur->next->person).fname;
							(cur->next->person).fname=(cur->person).fname;
							(cur->person).fname=tfname;


							tlname=(cur->next->person).lname;
							(cur->next->person).lname=(cur->person).lname;
							(cur->person).lname=tlname;
	*/
				}

			}
			cur=cur->next;
		}
			cur=head;
			
		}
		DLLNode * curr = head;
		while(curr!=NULL){
			cout<<"name is"<<" "<<(curr->person).fname <<" " << (curr->person).lname<<" "<<"age is"<<" "<<(curr->person).age <<endl;		
			curr = curr->next;
		}
		delete curr;
	}
	//SORT FUNCTION ENDS HERE
};	

int main(){
	int t;
	string fname,lname,str,fin,lin;
	int age,aage;
	cout<<"enter the number of inputs you want"<<endl;
	cin>>t;


	DLL * list = new DLL;
	bool first = true;

	Person a;
	for(int i=0;i<t;i++){
		cout<<"enter your first name"<<endl;
		cin>>fname;
		a.setfname(fname);
		cout<<"enter your last name"<<endl;
		cin>>lname;
		a.setlname(lname);
		cout<<"enter your age"<<endl;
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

	//SORT
	cout<<"the sorted list is as following"<<endl;
	list->sort(t);
		//list->datadisp();


	//SEARCH
	cout<<"enter the first name, last name and ageof person to be searched"<<endl;
	cin>>fin>>lin>>aage;
	list->search(fin,lin,aage);


	//DELETE
	cout<<"enter the first name, last name and age of person to be deleted"<<endl;
	cin>>fin>>lin>>aage;
	list->datadelete(fin,lin,aage);
	cout<<"the remaining list is as following"<<endl;
	list->datadisp();









}

