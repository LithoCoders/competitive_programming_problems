#include <iostream>

using namespace std;

int main(){
	char h1 ='0';
	char h2 ='0';
	char m1 ='0';
	char m2 ='0';
	cin>>h1>>h2>>m1>>m1>>m2; //skipe the ':' char

	auto tick = [&h1,&h2,&m1,&m2](){
		m2++;
		if(m2==(char)('9'+1)){
			m2='0';
			m1+=1;
			if(m1=='6'){
				m1='0';
				h2+=1;
				if((h1<'2' && h2=='9'+1) || (h1=='2' && h2=='4')){
					h2=0;
					h1+=1;
					if(h1=='3'){
						h1=0;
					}
				}
			}

		}
	};

	auto palindrome = [&](){
		return h1==m2 && h2==m1;
	}; 

	tick(); //skip the input if it is palindrome already
	while(!palindrome())
		tick();
	
	cout<<h1<<h2<<":"<<m1<<m2<<endl;
	return 0;
}