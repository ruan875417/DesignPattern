#include<iostream>
#include "Action.h"

using namespace std;
void Success::getManConclusion(Man* man){
    cout<<man->getSex()<<"�ɹ�ʱ����������һ��ΰ���Ů��"<<endl;
}
void Success::getWomanConclusion(Woman* woman){
    cout<<woman->getSex()<<"�ɹ�ʱ����������һ�����ɹ�������"<<endl;
}


void Failing::getManConclusion(Man* man){
    cout<<man->getSex()<<"ʧ��ʱ����ͷ�Ⱦƣ�˭Ҳ����Ȱ"<<endl;
}
void Failing::getWomanConclusion(Woman* woman){
    cout<<woman->getSex()<<"ʧ��ʱ������������˭ҲȰ����"<<endl;
}


void Loving::getManConclusion(Man* man){
     cout<<man->getSex()<<"����ʱ�����²���ҲҪװ��"<<endl;
}
void Loving::getWomanConclusion(Woman* woman){
     cout<<woman->getSex()<<"�ɹ�ʱ�����¶�Ҳװ������"<<endl;
}
