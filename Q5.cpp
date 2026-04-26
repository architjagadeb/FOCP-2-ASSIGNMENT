#include<iostream>
using namespace std;

class Bank{
    string userID[10];
    float balance[10];
    int total_users=0;

    public:
    int findUser(string x){
        for(int i=0; i<total_users;i++)
            if(userID[i]==x)    return i;
        return -1;
    }

    bool Create(string x, float y){
        int index=findUser(x);

        if(index != -1 ){
        balance[index]+=y;
        return false;
        }
        else{
        userID[total_users]=x;
        balance[total_users]=y;
        total_users++;
        return true;
        }
    }

    bool Debit(string x, float y){
        int index=findUser(x);
        if(index==-1)   return false;
        if(balance[index]<y)    return false;
        balance[index]-=y;
        return true;
    }

    bool Credit(string x, float y){
        int index=findUser(x);
        if(index==-1)   return false;
        balance[index] +=y;
        return true; 

    }

    int Balance(string x){
        int index=findUser(x);
        if(index==-1)   return -1;
        return balance[index];
    }
};

int main() {
    Bank b;
    int Q;
    cin>>Q;
    while (Q--){
        string query;
        cin>>query;
        if (query=="CREATE"){
            string id;
            float bal;
            cin>>id>>bal;
            cout<<(b.Create(id, bal) ?"true":"false")<<"\n";
        } 
        else if(query=="CREDIT"){
            string id;
            float bal;
            cin>>id>>bal;
            cout<<(b.Credit(id, bal) ?"true":"false")<<"\n";
        } 
        else if(query=="DEBIT"){
            string id;
            float bal;
            cin>>id>>bal;
            cout<<(b.Debit(id,bal) ?"true":"false")<<"\n";
        } 
        else if(query=="BALANCE"){
            string id;
            cin>>id;
            cout<<b.Balance(id)<<"\n";
        }
    }
}