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
            cout<<"网站分类："<<name<<endl;
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
    
    Website* wx=websiteFactory->getWebsite("产品展示");
    wx->use(); 
    
    Website* wy=websiteFactory->getWebsite("产品展示");
    wy->use(); 
    
    Website* wz=websiteFactory->getWebsite("产品展示");
    wz->use(); 
    
    Website* bx=websiteFactory->getWebsite("blog");
    bx->use(); 
    
    Website* by=websiteFactory->getWebsite("blog");
    by->use(); 
    cout<<"网站分类总数："<<websiteFactory->getWebsiteCount()<<endl;
    
    delete by;
    delete bx;
    delete wz;
    delete wy;
    delete wx;
    delete websiteFactory;
    
    system("pause");
    return 0;
}
