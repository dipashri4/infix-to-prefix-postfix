

/*infix to prefix

@uthor Dipashri Shinde
*/

#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

int prec(char c){
	if(c=='^'){
		return 3;
	}
	else if(c=='/' || c=='*'){
		return 2;
	}
	else if(c=='+' || c=='-'){
		return 1;
	}
	else{
		return -1;
	}
}
string infix_to_prefix(string s){
	stack<char>st;
	string res;
	for(int i=s.length()-1;i>=0;i--){
		if(s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z'){
			res+=s[i];
		}
		else if(s[i]==')'){
			st.push(s[i]);
		}
		else if(s[i]=='('){
			while(!st.empty() && st.top()!=')'){
				res+=st.top();
				st.pop();
			}
			//if(!st.empty())  
			    st.pop();
		}
		else{
			while(!st.empty() && prec(st.top())>prec(s[i])){     //
				res+=st.top();
				st.pop();
			}
			st.push(s[i]);
		}
	}
	while(!st.empty()){
		res+=st.top();
		st.pop();
	}
	reverse(res.begin(),res.end());
	return res;
}

string infix_to_postfix(string s){
	stack<char>st;
	string re;
	for(int i=0;i<s.length();i++){
		if(s[i]>='a' && s[i]<='z' || s[i]>='A' && s[i]<='Z'){
			re+=s[i];
		}
		else if(s[i]=='('){
			st.push(s[i]);
		}
		else if(s[i]==')'){
			while(!st.empty() && st.top()!='('){
				re+=st.top();
				st.pop();
			}
			//if(!st.empty())  
			    st.pop();
		}
		else{
			while(!st.empty() && prec(st.top())>=prec(s[i])){     //
				re+=st.top();
				st.pop();
			}
			st.push(s[i]);
		}
	}
	while(!st.empty()){
		re+=st.top();
		st.pop();
	}
	return re;
}
int main(){
	string i;
	cout<<"enter your infix expression ";
	cin>>i;
	cout<<"prefix expression is "<<infix_to_prefix(i)<<endl;
	cout<<"postfix expression is "<<infix_to_postfix(i)<<endl;
	return 0;
}

