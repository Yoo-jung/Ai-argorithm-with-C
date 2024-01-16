#include <iostream>
#include <stdio.h>
#include <string.h>
/*struct Person{
	char name[50];
	int age;
	bool gender; //0 is man, 1 is woman
	char gender_1;
}Ps;

int setPerson{}
int showPerson{}
*/
class Person{
	private:
	char name[50];
	int age;
	bool gender; //0 is man, 1 is woman
	char gender_1;
	//privatde에 변수를 넣는 이유는 외부에서 구조체 변수를 
	//막 건들여 발생하는 문제를 방지하기 위함.->보안, 객체지향
	public:
	Person(); //생성자 class name과 동일
	~Person(); //소멸자 calss name+'~'
	void setPerson(char* name, int age, bool gender);
	void showPerson();
	//private은 위 두 함수에서만 사용 가능한 공간
	//public 공간은 모든 공간에서 사용 가능한 공간
};
Person::Person(){//Person class에 있는 Person()함수
	this->age=0;
	printf("생성자 작동\n");
}
Person::~Person(){
	printf("소멸자 작동\n");
}
void Person::setPerson(char* name, int age, bool gender){
	//this->name=name;
	strcpy(this->name,name);
	this->age=age;
	this->gender=gender;
	this->showPerson();
}
void Person::showPerson(){
	printf("name: %s  age: %d  gender: ",this->name, this->age);
	if (this->gender) printf("male\n");
	else printf("female\n");
	/*
	 * printf("name: %s  age: %d  gender: ",this->name, this->age);
	 * if (this->gender==ture){printf("male\n");
	 * else printf("female\n");
	 */
}

int main(){
	Person a;
	a.setPerson((char *)"문유정", 10, false);
	return 0;
}
