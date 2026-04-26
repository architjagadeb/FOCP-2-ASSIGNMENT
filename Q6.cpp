#include<iostream>
using namespace std;

class MovieTicket{
    bool booked[10][10];
    int max_slots=100;
    public:
MovieTicket(){
    for(int i=0; i<10; i++)
        for(int j=0; j<10;j++)
            booked[i][j]=0;
}

bool AvailableTickets(int movieID){
    int c=0;
    for(int i=0; i<=10; i++)
        if(booked[movieID][i]==1)   
        c++;
    return(100-c);
}
bool Book( int customerID, int movieID){
    if(booked[movieID][customerID]==1) return false;
    if(AvailableTickets(movieID)==0)   return false;
    booked[movieID][customerID]=true;
    return true;
}
bool Cancel( int customerID, int movieID){
    if(booked[movieID][customerID]==false) return false;
    booked[movieID][customerID]= false;
    return true;
}
bool IsBooked(int customerID, int movieID) {
        return booked[movieID][customerID];
    }
};

int main() {
    MovieTicket m;
    int Q;
    cin>>Q;
    while (Q--){
        string query;
        cin>>query;
        if (query=="BOOK"){
            int x,y;
            cin>>x>>y;
            cout<<(m.Book(x, y) ?"true":"false")<<"\n";
        } 
        else if(query=="CANCEL"){
            int x, y;
            cin>>x>>y;
            cout<<(m.Cancel(x, y) ?"true":"false")<<"\n";
        } 
        else if(query=="ISBOOKED"){
            int x,y;
            cin>>x>>y;
            cout<<(m.IsBooked(x, y) ?"true":"false")<<"\n";
        } 
        else if(query=="AVAILABLETICKETS"){
            int y;
            cin>>y;
            cout<<m.AvailableTickets(y)<<"\n";
        }
    }
}