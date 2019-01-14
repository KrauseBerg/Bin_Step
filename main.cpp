#include <iostream>
#include <sstream>
#include <algorithm>
#include <math.h>
#include <ctime>

using namespace std;

int main(){
    while(true){
        cout<<"\n________BinaryStep_________\n\n";
        unsigned long long int otv,mod,num,step,ost,i,per;
        stringstream ss;
        string bin;
        string nm;
        int mas[3];
        i=0;
        cout<<"Number: ";
        cin>>num;
        otv=num;
        cout<<"Step: ";
        cin >> step;
        cout<<"Module: ";
        cin>>mod;
        clock_t t0 = clock();
        while(step){
            ost=step%2;
            step=step/2;
            if(ost==1){
                ss<<1;
            }
            if(ost==0)
                ss<<0;
            i++;
        }
        i=0;
        bin=ss.str();
        cout<<endl<<"Binari step: "<<bin<<endl;
        ss.str("");
        ss<<bin[i];
        nm=ss.str();
        ss.str("");
        per=atoi(nm.c_str());
        num=pow(otv,per);
        mas[0]=num%mod;
        mas[1]=otv;
        i++;
        while(i < bin.size()){
            ss.str("");
            ss<<bin[i];
            nm=ss.str();
            ss.str("");
            per=atoi(nm.c_str());
            num=(mas[1]*mas[1])%mod;
            if(per==0)
                mas[1]=num;
            else{
                mas[1]=num;
                mas[0]=(mas[0]*mas[1])%mod;
            }
            i++;
        }
        cout<<endl<<"Otvet: "<<mas[0]<<"!";
        clock_t t1 = clock();
        cout << endl << "time: " << (double)(t1 - t0) / CLOCKS_PER_SEC << endl;
    }
}

