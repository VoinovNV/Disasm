#include <iostream>
#include <string>


int main(int argc,char* argv[])
{
    if(argc!=2) {std::cout<<"usage: gen_name login\n"; return 1;}
    std::string arg2=argv[1],a={};
    auto arg1=&a; auto len =arg2.length();
    auto i = 0;
    for(int j=0;j<len;j++) if(!isalpha(arg2[j])) {std::cout<<"Only a-Z!\n"; return 1;}
    while (i < len) {
        auto S = arg2[i];
        auto v = ((i + 0x11) * len * 0xff + (int32_t)S)%0x4b + 0x30;
      a+=v;
      i = i + 1;
    }
    std::cout<<a<<'\n';
    return 0;
}
