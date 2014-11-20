#ifndef HANDSETBRAND_H
#define HANDSETBRAND_H
#include "HandsetSoft.h"
class HandsetSoft;

class HandsetBrand{
    protected:
         HandsetSoft* pSoft;     
    public:
         void setHandsetSoft(HandsetSoft* pSoft){
             this->pSoft=pSoft;
         }
         virtual void run()=0; 
}; 
class HandsetBrandM:public HandsetBrand{ 
    public:
        void run(){
            cout<<"手机品牌M"<<endl;
            pSoft->run();
        } 
};
class HandsetBrandN:public HandsetBrand{ 
    public:
        void run(){
            cout<<"手机品牌N"<<endl;
            pSoft->run();
        } 
}; 
#endif
