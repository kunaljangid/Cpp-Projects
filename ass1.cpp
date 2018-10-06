#include<iostream>
#include<string>
using namespace std;
class person{
private:
	string fname, lname;
	int age, age1, age2;
public:
	string getfname(){
		return fname;
	}
	string getlname(){
	return lname;
	 }
	 int getage(){
	 	return age;
	 }
	 void compareage(int age1,int age2){
	 	if(age1>age2){
	 		cout<<"first person is elder one";
	 	}
	 	else{
	 		cout<<"second person is elder one";
	 	}
	 }
	person(string afname,string alname,int aage){
		fname = afname;
		lname = alname;
		age = aage;
	}
	
};
int main(){
	string fnam1, lnam1, fnam2,lnam2;
	int number,age1, age2;
	cout<<"enter the first name, last name, age of 2 students";
	cin>>fnam1>>lnam1>>age1;
	cin>>fnam2>>lnam2>>age2;
	person *newperson  = new person(fnam1,lnam1,age1);
	cout<<newperson->getfname()<<endl;
	cout<<newperson->getlname()<<endl;
	cout<<newperson->getage()<<endl;
	person *newperson1  = new person(fnam2,lnam2,age2);
	cout<<newperson1->getfname()<<endl;
	cout<<newperson1->getlname()<<endl;
	cout<<newperson1->getage()<<endl;
	newperson-> compareage(age1,age2);
	return 0;
}
// person1 person 2 manually bnane hai dono
//  make pointers of each person store it in an array then do operations.
