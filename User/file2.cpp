#include<iostream>
using namespace std;
class var {
private:
	int x;
	//defining member variable
public:
	//defining constructor
	var(int x)
	{
		this->x = x;
	}
	var()
	{
		this->x = 0;
	}
	var smallest(var obj)
	{
		if (obj.x > x) return *this;
		else return obj;
	}
	int get()
	{
		return x;
	}
};
int main()
{
	var *obj1 = new var(30);
	var *obj2 = new var(15);
	var obj = obj1->smallest(*obj2);
	cout << obj.get();
}