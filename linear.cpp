#include <iostream>
using namespace std;
int HashT[10];

void Insertion(int roll){
    int index = roll%10;
    if(HashT[index] == -1 || HashT[index] == 0){
        HashT[index] = roll;
    }
    else{
        while(HashT[index] != -1 || HashT[index] != 0){
            index++;
            if(index > 9){
                index-=10;
            }
        }
        HashT[index] = roll;
    }
}

void Searching(int roll){
    int index = roll%10;
    bool flag = 0;
    if(HashT[index] == roll){
        flag = 1;
    }
    else{
        while(HashT[++index] != -1){
            if(HashT[index] == roll){
                flag = 1;
                break;
            }
        }
    }
    if(flag){
        cout<<"Roll Number at Index : "<<index<<endl;
    }
    else{
        cout<<"Roll Number Not Found"<<endl; 
    }
}

void Deletion(int roll){
    int index = roll%10;
    bool flag = 0;
    if(HashT[index] == roll){
        flag = 1;
    }
    else{
        while(HashT[++index] != -1){
            if(HashT[index] == roll){
                flag = 1;
                break;
            }
        }
    }
    if(flag){
        HashT[index] = 0;
        cout<<"Roll Number is Deleted"<<endl;
    }
    else{
        cout<<"Roll Number Not Found"<<endl;
    }
}

int main()
{
    for(int i = 0; i < 10; i++){
        HashT[i] = -1;
    }
    int choice;
    char ch;
    int roll;
    do{
        cout<<"1. Insert Student"
            <<"\n2. Search Student"
            <<"\n3. Delete Student"<<endl;
        cout<<"Enter Your Choice : ";
        cin>>choice;
        for(int i = 0; i < 10; i++){
                cout<<HashT[i]<<endl;
        }
        switch(choice){
            case 1:cout<<"Enter Roll Number : ";
                cin>>roll;
                Insertion(roll);
                for(int i = 0; i < 10; i++){
                    cout<<HashT[i]<<endl;
                }
                break;
            case 2:cout<<"Enter Roll Number : ";
                cin>>roll;
                Searching(roll);
                break;
            case 3:cout<<"Enter Roll Number : ";
                cin>>roll;
                Deletion(roll);
                break;
        }
        cout<<"Do you want to continue?(Y/N)"<<endl;
        cin>>ch;
    }while(ch == 'Y' || ch == 'y');

    return 0;
}
