#include <iostream> 
#include <string>

using namespace std; 

int a,b,tongquediem=0;

int quediem(char kt){
    switch (kt)
    {
    case '0':
        return 6;
        break;
    case '1':
        return 2;
        break;
    case '2':
        return 5;
        break;
    case '3':
        return 5;
        break;
    case '4':
        return 4;
        break;
    case '5':
        return 5;
        break;
    case '6':
        return 6;
        break;
    case '7':
        return 3;
        break;
    case '8':
        return 7;
        break;
    case '9':
        return 6;
        break;
    default:
        return 0;
        break;
    }
}

int So_que_diem(int n){
    int tongque=0;
    string So_st=to_string(n);      //chuyển số n thành string
    for (int i=0;i<So_st.size();i++){
        tongque+=quediem(So_st[i]);
    }
    return tongque;
}

void xuli(){
    for (int i=a;i<=b;i++){
        tongquediem+=So_que_diem(i);
    }
    cout<<tongquediem;
}

void nhap(){
    cin>>a>>b;
}

int main(){
    nhap();
    xuli();
    return 0; 
}
// #include <iostream>
// using namespace std;

// int soque(int x)
// {
//     int que;
//     if(x==0||x==6||x==9)
//         que=6;
//     if(x==1)
//         que=2;
//     if(x==2||x==3||x==5)
//         que=5;
//     if(x==4)
//         que=4;
//     if(x==7)
//         que=3;
//     if(x==8)
//         que=7;
//     return que;
// }

// int main()
// {
//     int k;
//     int a,b;
//     int temp;
//     int sum1so;
//     cout << "Nhap so dau: ";
//     cin>>a;
//     cout << "Nhap so cuoi: ";
//     cin>>b;
//     int sum=0;
//     for(int x=a;x<=b;x++)
//     {
//         temp=x;
//         sum1so=0;
//         while(temp>0)
//         {
//             k=temp%10;
//             temp=temp/10;
//             sum1so=sum1so+soque(k);
//         }
//         if(x==0)
//             sum1so=6;
//         sum=sum+sum1so;
//     }
//     cout<<sum;
//     return 0;
// }