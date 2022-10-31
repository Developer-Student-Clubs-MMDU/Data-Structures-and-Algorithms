//  Function to check if brackets are balanced or not.

//  we use stack data structure to push parenthesis in it. 
//  and use bool function to return true or false which 


#include<bits/stdc++.h>
using namespace std;
class Solution{
	public:
bool ispar(string x)
    {
        stack<char>s;

        if(x.length()<1){

            return false;
        }

        for(int i=0;i<x.length();i++){

            if(x[i]=='(' || x[i]=='{' || x[i]=='['){

                s.push(x[i]);

            }

            else {

                if(s.empty()){

                return false;

                }

                

                if(x[i]==']' && s.top()=='['){

                    s.pop();

                }

                    else if (x[i]=='}' && s.top()=='{'){

                    s.pop();

                }

                else if( x[i]==')' && s.top()=='('){

                     s.pop();

                }

                else{

                    return false;

                }

            }

            

        }

        

        if(s.empty()){

            return true;

        }

        else {

            return false;

        }

    
    }
};
int main(){
    int t;
    string a;
    cin>>t;
    while(t--){
        cin>>a;
        Solution obj;
        if(obj.ispar(a))
            cout<<"balanced"<<endl;
        else
            cout<<"not balanced"<<endl;
        
    }
}


