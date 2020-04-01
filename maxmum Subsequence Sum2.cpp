#include<iostream>
using namespace std;
int fun1(int num,int *p){
	int max = 0;
	int cur = 0;
	int minpos = 0;
	int maxpos = 0;
	int flag = 1;
	for(int i = 0;i < num;i++){
		cur += p[i];
		if( cur > max){
			max = cur;
			maxpos = i;
		}else if(cur < 0){
			cur = 0;
		}
		if(p[i]>=0){
			flag = 0;
		}
	}
	int tmp = 0;
	for(int i = maxpos;i >= 0;i--){
		tmp = tmp + p[i];
		if(tmp == max){
			minpos = i;
		}
	}
	if(max > 0){
		cout<<max<<' '<<p[minpos]<<' '<<p[maxpos]<<endl;
	}
	else{
        if(flag)
        {
		    cout<<"0 0 0"<<endl;
	    }
		else{
            cout<<0<<' '<<p[0]<<' '<<p[num - 1]<<endl;
        }
	}
	return 0;
}
int main()
{	
	int num = 0;
	cin>>num;
	int *p = new int[num];
	for(int i=0;i<num;i++){
		cin>>p[i];
	}
	fun1(num,p);
	
	delete p;
	return 0;
}