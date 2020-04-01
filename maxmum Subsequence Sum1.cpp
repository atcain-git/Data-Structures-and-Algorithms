#include<iostream>
using namespace std;
int fun1(int num,int *p){
	int max = 0;
	int cur = 0;
	for(int i = 0;i < num;i++){
		cur += p[i];
		if( cur > max){
			max = cur;
		}else if(cur < 0){
			cur = 0;
		}
	}
	return max;
}
int main()
{	
	int num = 0;
	cin>>num;
	int *p = new int[num];
	for(int i=0;i<num;i++){
		cin>>p[i];
	}
	int result = fun1(num,p);
	cout<<result<<endl;
	delete p;
	return 0;
}