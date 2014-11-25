#include<iostream>
#include<map>
using namespace std;
//////////////////////////////
class Website{
    public:
        virtual void use()=0;
};
class ConcreteWebsite:public Website{
    private:
        string name;
    public:
        ConcreteWebsite(string name){
            this->name=name;
        }
        void use(){
            cout<<"��վ���ࣺ"<<name<<endl;
        }
};
class WebsiteFactory{
    private:
        map<string,Website*> websites;
    public:
        Website* getWebsite(string key){
           if(!websites.count(key)){
              websites[key]=new ConcreteWebsite(key);
           }
           return websites[key];
        }
        map<string,Website*>::size_type getWebsiteCount(){
           return websites.size();
        }
};
int main(){
    WebsiteFactory* websiteFactory=new WebsiteFactory;
    
    Website* wx=websiteFactory->getWebsite("��Ʒչʾ");
    wx->use(); 
    
    Website* wy=websiteFactory->getWebsite("��Ʒչʾ");
    wy->use(); 
    
    Website* wz=websiteFactory->getWebsite("��Ʒչʾ");
    wz->use(); 
    
    Website* bx=websiteFactory->getWebsite("blog");
    bx->use(); 
    
    Website* by=websiteFactory->getWebsite("blog");
    by->use(); 
    cout<<"��վ����������"<<websiteFactory->getWebsiteCount()<<endl;
    
    delete by;
    delete bx;
    delete wz;
    delete wy;
    delete wx;
    delete websiteFactory;
    
    system("pause");
    return 0;
}
