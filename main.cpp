#include <iostream>
#include <cstdlib>
#include "stack.h"
#include "Merge.h"
using namespace std;
void menu();
int main()
{
    stack<char> current;
    int check(0),size(0);
    char value;
    while(check!=4){
        menu();
        cin>>check;
        while((!cin)||(check<1)||(check>4)){
            system("cls");
            cin.clear();
            cin.ignore(32767,'\n');
            menu();
            cin>>check;
        }
        if(check==1){
            system("cls");
            current.doEmpty();
            cout<<"Press size stack >>";
            cin>>size;
            while((!cin)||(size<1)){
                system("cls");
                cin.clear();
                cin.ignore(32767,'\n');
                cout<<"Press size stack >>";
                cin>>size;
            }
            for(size_t i=0;i<size;i++){
                system("cls");
                cout<<"press"<<i<<" elem >>";
                cin>>value;
                current.push(value);
            }
            check=0;
        }
        if(check==2){
            system("cls");
            if(current.empty())cout<<"stack is empty :("<<endl;
            else{
                stack<char> buff(current);
                while(!buff.empty()){
                    buff.pop(value);
                    cout<<value<<" ";
                }
            }
            cout<<endl;
            check=0;
        }
        if(check==3){
            system("cls");
            if(current.empty())cout<<"stack is empty :("<<endl;
            else{
                cout<<"Position >>";
                int position=0;
                cin>>position;
                while((!cin)||(position<0)||(position>current.getSize())){
                    system("cls");
                    cin.clear();
                    cin.ignore(32767,'\n');
                    cout<<"Position >>";
                    cin>>position;
                }
                unsigned checker=Merge(current,position);
                if(checker==0)cout<<"Sort"<<endl;
                if(checker==1)cout<<"stack is empty :("<<endl;
                if(checker==2)cout<<"incorrect data :("<<endl;
            }
            check=0;
        }
    }
    return 0;
}
void menu(){cout<<"===================<<"<<endl<<"1.fill stack"<<endl<<"2.see "<<endl<<"3.merge"<<endl<<"4.exit"<<endl;
}
