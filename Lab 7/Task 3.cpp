#include <iostream>
using namespace std;

class Ticket {
    protected:
    int TicketID;
    string passengerName;
    double price;
    string date;
    string destination;
    public:
    Ticket(int ID,string N,double p,string d,string dest):TicketID(ID),passengerName(N),price(p),date(d),destination(dest){}
   virtual void reserve() {
        cout << "Ticket reserved for " << passengerName << " to " << destination << " on " << date << ""<<endl;
    }

   virtual void cancel(){
    cout<<"Ticket : "<<TicketID<<"Has been cancelled"<<endl;
   }

   virtual void displayTicketinfo(){
    cout<<"Ticket ID : "<<TicketID<<endl;
    cout<<"Passenger Name :"<<passengerName<<endl;
    cout<<"Price : "<<price<<endl;
    cout<<"DATE : "<< date <<endl;
    cout<<"Destination : "<<destination<<endl;
   }
};
class FlightTicket:public Ticket{
    protected:
    string AirlineName;
    string flightNumber;
    string seatclass;
    public:
    FlightTicket(int ID,string N,double p,string d,string dest,string airline,string flight,string sc):Ticket(ID,N,p,d,dest),AirlineName(airline),flightNumber(flight),seatclass(sc){}
    void displayTicketinfo()override{
        Ticket::displayTicketinfo();
        cout<<"Airline Name :"<<AirlineName<<endl;
        cout<<"Flight Number : "<<flightNumber<<endl;
        cout<<"Seas Class : "<<seatclass<<endl;
    }
};
class TrainTicket : public Ticket{
    protected:
    string TrainNumber;
    string CoachType;
    string DepartureTime;
    public:
    TrainTicket(int ID,string N,double p,string d,string dest,string train,string ct,string dt):Ticket(ID,N,p,d,dest),TrainNumber(train),CoachType(ct),DepartureTime(dt){}
    void reserve ()override{
        cout<<"Seats Assigned in " <<CoachType<<" of Train "<<TrainNumber<<" Departing at "<<DepartureTime<<endl;
    }
};
class Busticket : public Ticket{
    protected:
    string BusCompany;
    string SeatNumber;
    public:
    Busticket(int ID,string N,double p,string d,string dest,string bus,string sn):Ticket(ID,N,p,d,dest),BusCompany(bus),SeatNumber(sn){}
    void cancel()override{
        cout<<"Bus Ticket :"<<TicketID<<"\nCancelled  "<< SeatNumber <<endl;
    }
};
class Concert : public Ticket{
  protected:
  string artistName;
  string venue;
  string seatType;
  public:
  Concert(int ID,string N,double p,string d,string dest,string artist,string venue,string st):Ticket(ID,N,p,d,dest),artistName(artist),venue(venue),seatType(st){}
  void displayTicketinfo() override{
    Ticket::displayTicketinfo();
    cout<<"Artist Name :"<<artistName<<endl;
    cout<<"Venue : "<<venue<<endl;
    cout<<"Seat Type : "<<seatType<<endl;
  }  

};

int main(){
    FlightTicket F1(1,"Qazi",3000,"12-5-25","Lahore","Flyjinnah","A-312","Economy");
    TrainTicket T1(2,"Wajih",213,"25-7-25","Berlin","A-32","Metro","10:00 AM");
    Busticket B1(3,"Raahim",1500,"22-9-25","Barcelona","TeamBus","A-34");
    Concert C1(4,"Abdy",2123,"12-08-25","Paris","Jennie","Eiffel Tower","Vip");
     cout << "\nFlight Ticket:\n";
    F1.displayTicketinfo();
    
    cout << "\nTrain Ticket:\n";
    T1.reserve();
    T1.displayTicketinfo();
    
    cout << "\nBus Ticket:\n";
    B1.cancel();
    B1.displayTicketinfo();
    
    cout << "\nConcert Ticket:\n";
    C1.displayTicketinfo();
}
