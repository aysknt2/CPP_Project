#include<iostream>
#include<string>
using namespace std;

class Hotel
{
    private:
        struct Node{
            int id,date;
            string name, roomtype;
            Node* next;
        };
    public:
        Node* head = NULL;
        void insert();
        void menu();
        void update();
        void search();
        void del();
        void sort();
        void show();
};
void Hotel::menu(){
    int choices;
    cout<<"\n";
    cout<<"\tWelcome to Hotel Management System Application\n";
    cout<<"\n\t________Hotel Management System________"<<endl;
    cout<<"\nS.No.     Function                       Description"<<endl;
    cout<<"\n1\tAllocate Room\t\t\tInsert New Room";
    cout<<"\n2\tSearch Room\t\t\tSearch Room Using Room ID";
    cout<<"\n3\tUpdate Room\t\t\tUpdate Room Record";
    cout<<"\n4\tDelete Room\t\t\tDelete Room Using Room ID";
    cout<<"\n5\tShow Room Record\t\tInsert New Room";
    cout<<"\n6\tExit";


    cout<<"\n\nEnter Your Choice"<<endl;
    cin>>choices;
    switch(choices){
        case 1:
        insert();
        menu();
        menu();
        case 2:
        search();
        menu();
        case 3:
        update();
        menu();
        case 4:
        del();
        menu();
        case 5:
        sort();
        show();
        menu();
        case 6:
        exit(0);
        default:
            cout<<"Invalid";
    }
}
void Hotel::insert(){
    cout<<"\n\t________Hotel Management System________";
    Node* newNode = new Node;
    cout<<"\nEnter Room ID "<<endl;
    cin>>newNode -> id;
    cout<<"\nEnter Customer Name "<<endl;
    cin>>newNode -> name;
    cout<<"\nEnter Allocated Date"<<endl;
    cin>>newNode -> date;
    cout<<"\nEnter Room Type (single/double/twin) "<<endl;
    cin>>newNode -> roomtype;

    if(head == nullptr){
        head = newNode;
    }
    else{
        Node* ptr = head;
        while(ptr->next != nullptr){
            ptr = ptr -> next;
        }
        ptr ->next = newNode;
    }
    cout<<"\n\nNew Room Inserted."<<endl;
}
void Hotel::search(){
    cout<<"\n\t________Hotel Management System________";
    int tID;
    if(head == nullptr){
        cout<<"\n\nNo registered Rooms"<<endl;
    }
    else{
        cout<<"\n\nEnter Room ID ";
        cin>>tID;
        Node* ptr = head;
        while(ptr != nullptr){
            if(tID == ptr-> id){
                cout<<"\n\nRoom ID: "<<ptr -> id;
                cout<<"\n\nCustomer Name: "<<ptr -> name;
                cout<<"\n\nDate Added: "<<ptr -> date;
                cout<<"\n\nRoom Type: "<<ptr -> roomtype;
            }
            ptr = ptr->next;
        }
    }
}
void Hotel::update(){
    cout<<"\n\t________Hotel Management System________";
    int tID;
    if(head == nullptr){
        cout<<"\n\nNo registered Rooms"<<endl;
    }
    else{
        cout<<"Enter Room ID ";
        cin>>tID;
        Node* ptr = head;
        while(ptr != nullptr){
            if(tID == ptr->id){
                cout<<"Enter the updated details"<<endl;
                cout<<"\nEnter ID ";
                cin>>ptr-> id;
                cout<<endl;
                cout<<"\nEnter Customer Name ";
                cin>>ptr-> name;
                cout<<endl;
                cout<<"\nEnter Date ";
                cin>>ptr-> date;
                cout<<endl;
                cout<<"\nEnter Room Type ";
                cin>>ptr-> roomtype;
                cout<<endl<<"Record Updated Successfully"<<endl;

            }
            ptr = ptr->next;
        }
    }
}
void Hotel::del(){
    cout<<"\n\t________Hotel Management System________";
    int tID;
    if(head == nullptr){
        cout<<"\n\nNo registered Rooms"<<endl;
    }
    else{
        cout<<"\n\nRoom ID";
        cin>>tID;
        if(tID == head->id){
            Node* ptr = head;
            head = head -> next;
            delete ptr;
            cout<<"Room Deleted Successfully"<<endl;
        }
        else{
            Node* pre = head;
            Node* ptr = head;
            while(ptr != nullptr){
                if(tID == ptr->id){
                    pre->next = ptr->next;
                    delete ptr;
                    cout<<"Room Deleted Successfully"<<endl;
                    break;
                }
                pre = ptr;
                ptr = ptr->next;
            }
        }
    }
}
void Hotel::show(){
    if(head == nullptr){
        cout<<"\n\nNo registered Rooms"<<endl;
    }
    Node* ptr = head;
    while(ptr != nullptr){
        cout<<"\n\nRoom ID: "<<ptr->id;
        cout<<"\n\nCustomer Name: "<<ptr->name;
        cout<<"\n\nAllocation Date: "<<ptr->date;
        cout<<"\n\nRoom Type: "<<ptr->roomtype;
        ptr = ptr->next;
    }
}
void Hotel::sort(){
    if(head == nullptr){
        cout<<"\n\nNo registered Rooms"<<endl;
        menu();
    }
    int count =0;
    int tDate,tID;
    string tName, tRoomtype;
    Node* ptr = head;
    while(ptr != nullptr){
        count++;
        ptr = ptr->next;
    }
    for(int i =1; i<count ; i++){
        Node*ptr =  head;
        for(int j =1; j< count; j++){
            if(ptr->id > ptr-> next-> id){
                tID = ptr->id;
                tDate = ptr->date;
                tName = ptr->name;
                tRoomtype = ptr->roomtype;

                ptr-> id = ptr->next->id;
                ptr-> name = ptr->next->name;
                ptr-> date = ptr->next->date;
                ptr-> roomtype = ptr->next->roomtype;

                ptr->next->id = tID;
                ptr->next->name = tName;
                ptr->next->date = tDate;
                ptr->next->roomtype = tRoomtype;
            }
            ptr = ptr->next;
        }
    }
}

int main(){

    Hotel h;
    h.menu();

    return 0;
}
