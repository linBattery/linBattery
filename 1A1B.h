#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>

using namespace std;

bool is1a1b(int num){
    if(num/1000==0){
        return false;
    }
    if((num/100)%10==0){
        return false;
    }
    if((num/10)%10==0){
        return false;
    }
    if(num%10==0){
        return false;
    }
    if(num<=1000){
        return false;
    }
    else if(num/1000==(num/100)%10){
        return false;
    }
    else if(num/1000==(num/10)%10){
        return false;
    }
    else if(num/1000==(num%10)){
        return false;
    }
    else if((num/100)%10==(num/10)%10){
        return false;
    }
    else if((num/100)%10==(num%10)){
        return false;
    }
    else if((num/10)%10==(num%10)){
        return false;
    }
    else{
        return true;
    }
}
bool checknum(int num1,int num2){
    if((num1/1000)==(num2/1000)){
        if((num1/100)%10==(num2/100)%10){
            if((num1/10)%10==(num2/10)%10){
                if(num1%10==num2%10){
                    return true;
                }
                else{
                    return false;
                }
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }
    else{
        return false;
    }
}

int game_1A1B(){
    int num1,num2;
    srand(time(NULL));
    num2=rand()%9999+1;
    while(1){
        num2=rand()%9999+1;
        if(is1a1b(num2)){
            break;
        }
    }
    cout<<"****** Welcome to the 1A1B game *****"<<endl;
    cout<<"* Here are the rules of the game *"<<endl;
    cout<<"1. You must enter a 4-digit number, and the digits cannot be repeated."<<endl;
    cout<<"2. A represents correct position and correct digit, B represents correct digit but incorrect position."<<endl;
    cout<<"3. The four numbers assigned by the system will not be 0 (entering 0 will definitely be incorrect)."<<endl;
    cout<<"// Game starts //"<<endl;
    int i,j;
    int arr1[4]={};
    int arr2[4]={};
    arr2[0]=num2/1000;
    arr2[1]=(num2/100)%10;
    arr2[2]=(num2/10)%10;
    arr2[3]=num2%10;
    int A,B;
    int guesstimes=0;
    while(1){
        guesstimes+=1;
        cout<<"Enter a 4-digit number:";
        cin>>num1;
        arr1[0]=num1/1000;
        arr1[1]=(num1/100)%10;
        arr1[2]=(num1/10)%10;
        arr1[3]=num1%10;
        A=0;
        B=0;
        for(i=0;i<4;i++){
            for(j=0;j<4;j++){
                if(arr1[i]==arr2[j]){
                    B+=1;
                    break;
                }
            }
        }
        if(arr1[0]==arr2[0]){
            A+=1;
            B-=1;
        }
        if(arr1[1]==arr2[1]){
            A+=1;
            B-=1;
        }
        if(arr1[2]==arr2[2]){
            A+=1;
            B-=1;
        }
        if(arr1[3]==arr2[3]){
            A+=1;
            B-=1;
        }
        cout<<A<<"A"<<B<<"B"<<endl;
        if(checknum(num1,num2)){
            cout<<"Answer correct!!"<<endl;
            return 1;
        }
        else{
            continue;
        }
    }
    system("pause");
    return 0;
}
