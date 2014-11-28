#include<iostream>
#include "Action.h"

using namespace std;
void Success::getManConclusion(Man* man){
    cout<<man->getSex()<<"成功时，背后多半有一个伟大的女人"<<endl;
}
void Success::getWomanConclusion(Woman* woman){
    cout<<woman->getSex()<<"成功时，背后大多有一个不成功的男人"<<endl;
}


void Failing::getManConclusion(Man* man){
    cout<<man->getSex()<<"失败时，闷头喝酒，谁也不用劝"<<endl;
}
void Failing::getWomanConclusion(Woman* woman){
    cout<<woman->getSex()<<"失败时，眼泪汪汪，谁也劝不了"<<endl;
}


void Loving::getManConclusion(Man* man){
     cout<<man->getSex()<<"恋爱时，凡事不懂也要装懂"<<endl;
}
void Loving::getWomanConclusion(Woman* woman){
     cout<<woman->getSex()<<"成功时，遇事懂也装作不懂"<<endl;
}
