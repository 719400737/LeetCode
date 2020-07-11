#include<iostream>
#include<cstring>
using namespace std;
class MyString{
    //string类自己实现，招商网银2面试题
friend ostream& operator<<(ostream& os,MyString s);
friend istream& operator>>(istream& is,MyString s);
public:
    MyString(const char* str);
    MyString(const MyString& ms);
    MyString& operator=(const MyString& ms);
    ~MyString();
private:
    char* data;
};
MyString::MyString(const char* str){
    if(str==nullptr){
        data=new char[1];
        *data='\0';
    }
    else{
        int len=strlen(str);
        data=new char[len+1];
        strcpy(data,str);
    }
}
MyString::MyString(const MyString& ms){
    int len=strlen(ms.data);
    data=new char[len+1];
    strcpy(data,ms.data);
}
MyString& MyString::operator=(const MyString& ms){
    if(this==&ms)
        return *this;
    if(data)
        delete[] data;
    int len=strlen(ms.data);
    data=new char[len+1];
    strcpy(data,ms.data);
    return *this;
}
MyString::~MyString(){
    delete[] data;
}
ostream& operator<<(ostream& os,MyString s){
    os<<s.data;
    return os;
}
istream& operator>>(istream& is,MyString s){
    is>>s.data;
    return is;
}

int main(){
    MyString s="12312";
    cout<<s<<endl;
    return 1;
}