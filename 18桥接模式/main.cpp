#include<iostream>
#include "HandsetBrand.h"
using namespace std;
/********************************************** 
* �Ž�ģʽԭ�� 
*   �����󲿷ֺ�����ʵ�ֲ��ַ��룬ʹ���Ƕ����Զ� 
* ���ر仯�� 
*   ����������ʵ�ַ��룬�Ⲣ����˵���ó��������� 
* ��������룬��Ϊ��û���κ����塣ʵ��ָ���ǳ��� 
* �����������������ʵ���Լ��Ķ��� 

* �ܽ᣺ 
*   1��ʵ��ϵͳ�����ж�Ƕȷ��࣬ÿһ�ַ��඼�п����б仯����ô�ð����ֶ� 
*      �Ƕȷ�����������Ƕ����仯����������֮�����ϡ� 
*   2��ֻҪ��������������ԭ�򣬺ܶ����ģʽ��ʵ����ԭ���Ӧ�ö��ѣ����� 
*      �ڲ�֪�����о���ʹ�����ģʽ�ˡ� 
*   3������ļ̳й�ϵ���ڱ���ʱ�Ͷ�����ˣ������޷�������ʱ�ı�Ӹ���̳� 
*      ��ʵ�֡������ʵ�������ĸ����зǳ����ܵ�������ϵ�������ڸ���ʵ���� 
*      ���κα仯��Ȼ�ᵼ�����෢���仯��������Ҫ��������ʱ������̳����� 
*      ��ʵ�ֲ��ʺϽ���µ����⣬���������д���������ʺϵ����滻���� 
*      ��������ϵ����������Բ����������˸����ԡ� 
************************************************************************/  
int main(){
    HandsetBrand* handsetBrand;
    handsetBrand=new HandsetBrandM;
    
    handsetBrand->setHandsetSoft(new HandsetGame);
    handsetBrand->run();
    
    handsetBrand->setHandsetSoft(new HandsetAddressList);
    handsetBrand->run();
    
    handsetBrand=new HandsetBrandN;
    handsetBrand->setHandsetSoft(new HandsetGame);
    handsetBrand->run();
    
    handsetBrand->setHandsetSoft(new HandsetAddressList);
    handsetBrand->run();
    
    system("pause");
    return 0;
}
