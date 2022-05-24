#include <iostream>
using namespace std;
int HashT[10][2];

void Insertion(int roll){
    int index = roll%10;
    if(HashT[index][0] == -1){
        HashT[index][0] = roll;
    }
    else{
        while(HashT[index][0] != -1){
            index++;
            if(index > 9){
                index-=10;
            }
        }
        HashT[index][0] = roll;
        int i = index-1;
        if(i < 0){
            i = 11-i;
        }
        for(; HashT[i][0] != -1; i--){
            if(i < 0){
                i = 11-i;
            }
            if(roll%10 == (HashT[i][0]%10)){
                HashT[i][1] = index;
                break;
            }
        }
    }
}

void Searching(int roll){
    int index = roll%10;
    bool flag = 0;
    if(HashT[index][0] == roll){
        flag = 1;
    }
    else{
        while(true){
            index = HashT[index][1];
            if(HashT[index][0] == roll){
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

int main()
{
    for(int i = 0; i < 10; i++){
        HashT[i][0] = HashT[i][1] = -1;
    }
    int choice;
    char ch;
    int roll;
    do{
        cout<<"1. Insert Student"
            <<"\n2. Search Student"<<endl;
        cout<<"Enter Your Choice : ";
        cin>>choice;
        for(int i = 0; i < 10; i++){
                cout<<HashT[i][0]<<" "<<HashT[i][1]<<endl;
        }
        switch(choice){
            case 1:cout<<"Enter Roll Number : ";
                cin>>roll;
                Insertion(roll);
                for(int i = 0; i < 10; i++){
                    cout<<i<<" "<<HashT[i][0]<<" "<<HashT[i][1]<<endl;
                }
                break;
            case 2:cout<<"Enter Roll Number : ";
                cin>>roll;
                Searching(roll);
                break;
        }
        cout<<"Do you want to continue?(Y/N)"<<endl;
        cin>>ch;
    }while(ch == 'Y' || ch == 'y');

    return 0;
}
