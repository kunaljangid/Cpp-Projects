#include<iostream>
#include<string.h>
using namespace std;
class person{
private: 
public:
	int age;
	string fname;
	string lname;
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
	void setage(int agee){
		age=agee;
	}
	/*int comp(int a, int b){
		if(a>b){
			return 1;
		}
		else if (b>a){
			return 2;
		}
		return 3;

	}*/
};
class dll{
	private:
	public:


//DELETE FUNCTION STARTS HERE
	void dele(person *a, person *b, int n, int d){
	for(int i=0;i<n-1;i++){
		b[i]=a[i];
	}
		for(int i=n;i<d;i++){
			b[i-1]=a[i];
		}
	
		cout<<"the new list is as following"<<endl;
		for(int i=0;i<d-1;i++){
	cout<<b[i].getfname()<<" "<<b[i].getlname()<<" "<<b[i].getage()<<endl;
	}

	
}
//DELETE FUNCTION ENDS HERE


//SORT FUNCTION STARTS FROM HERE
void sort(person *a, int x){
	for(int i=0; i<x-1; i++){
	for(int j=0; j<x-1-i; j++){
		if(a[j].getage()>a[j+1].getage()){
			int temp1,temp2;
			string fn1,fn2;
			string ln1,ln2;
			temp1=a[j].getage();
			temp2=a[j+1].getage();
			a[j].setage(temp2);
			a[j+1].setage(temp1);

			fn1=a[j].getfname();
			fn2=a[j+1].getfname();
			a[j].setfname(fn2);
			a[j+1].setfname(fn1);

			ln1=a[j].getlname();
			ln2=a[j+1].getlname();
			a[j].setlname(ln2);
			a[j+1].setlname(ln1);
		}
		else if(a[j].getage()==a[j+1].getage()){
			if(a[j].getfname() > a[j+1].getfname()){
			int temp1,temp2;
			string fn1,fn2;
			string ln1,ln2;
			temp1=a[j].getage();
			temp2=a[j+1].getage();
			a[j].setage(temp2);
			a[j+1].setage(temp1);

			fn1=a[j].getfname();
			fn2=a[j+1].getfname();
			a[j].setfname(fn2);
			a[j+1].setfname(fn1);

			ln1=a[j].getlname();
			ln2=a[j+1].getlname();
			a[j].setlname(ln2);
			a[j+1].setlname(ln1);
			}
			
		}
	}
}
}
//SORT FUNCTION ENDS HERE


//SEARCH FUNCTION STARTS HERE
int search(string x, person *a, int t){
	for(int i=0;i<t;i++){
		if(x==a[i].getfname()){
			return i;
			break;
		}
	}
	return -1;
}
//SEARCH FUNCTION ENDS HERE



};

int main(){
	int t;
	string fname,lname;
	int age;
	cout<<"enter the number of inputs you want"<<endl;
	cin>>t;
	person *a=new person[t];
	dll *dl = new dll;
	for(int i=0;i<t;i++){
		cout<<"enter your first name"<<endl;
		cin>>fname;
		a[i].setfname(fname);
		cout<<"enter your last name"<<endl;
		cin>>lname;
		a[i].setlname(lname);
		cout<<"enter your age"<<endl;
		cin>>age;
		a[i].setage(age);
	}
	cout<<"this is the list of students"<<endl;
	for(int i=0;i<t;i++){
	cout<<a[i].getfname()<<" "<<a[i].getlname()<<" "<<a[i].getage()<<endl;
	}	


//SORT
	cout<<"the sorted list is as following"<<endl;
	dl->sort(a,t);
	for(int i=0;i<t;i++){
	cout<<a[i].getfname()<<" "<<a[i].getlname()<<" "<<a[i].getage()<<endl;
	}	

//SEARCH
	string temp;
	int ind=0;
	cout<<"enter the first name of person whose age you want to search"<<endl;
	cin>>temp;
	ind = dl->search(temp,a,t);
	if(ind==-1){
		cout<<"there is no such person in the records"<<endl;
	}
	else{
	cout<<"the age of person is"<<" "<< a[ind].getage()<<endl;
	}



//DELETE
	int deli;
	cout<<"enter the number of the input you want to delete"<<endl;
	cin>>deli;
	person *b= new person[t-1];
	dl->dele(a,b,deli,t);
	delete[] a ;	


//COMPARATOR
/*	cout<<"enterthe two index whose person you want to compare"<<endl;
	int q,w,x;
	string g=a[w].getfname();
	string y=a[q].getfname();
	person *n = new person;
	cin>>q>>w;
	w = n->comp(a[q].getage(),a[w].getage());
	if(w==1){
		cout<<y<<"is elder than"<<g<<endl;
	}
	else if (w==2){
		cout<<y<<"is smaller than"<<g<<endl;
	}
	else{
		cout<<y<<"is of same age as that of"<<g<<endl;
	}
*/





}
