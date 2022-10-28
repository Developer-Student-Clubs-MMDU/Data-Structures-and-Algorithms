#include <bits/stdc++.h>

using namespace std;

class person
{
    public:
   string name;
    string address;
    
    void display()
    {
        cout<<name<<" "<<address<<endl;
    }
};

int main() {
    //statically
    person p1;
  
    p1.name="Ram";
    p1.address="Gorakhpur";
    p1.display();
  
    //dynamically
    person *p3=new person;
    (*p3).name="Shyam";
    (*p3).address="Gorakhpur";
    (*p3).display();
}
