#include <iostream>
#include <malloc.h>
#include <stdio.h>
#include <memory.h>
#define MAXBUFFERSIZE 30
#define SPACESEPARATOR ' '
using namespace std;
class Solution {
public:
    void reverseWords(string &s) {
    int i,j;
    for (i=0;i<s.length();++i)
    {
        if (s[i]!=' ')
        break;
    }
    int len=s.length();
    for (j=s.length()-1;j>=0;--j)
    {
        if (s[j]!=' ')
        break;
    }
    
    if (i>=s.length())
    {
        s="";
    }
      else 
    {
         char *s1=(char *)malloc(sizeof(char)*(j-i+1));
         int k=0;
         int flag=0;
         for (;i<=j;++i)
         {
             if (s[i]==' ')
             {
                if (flag==0)
                {
                 flag=1;
                 s1[k++] =s[i];
                }
             }
             else if (s[i]!=' ')
             {
                 flag=0;
                 s1[k++]=s[i];
             }
         }
        //  s1[k]=NULL;
        // s1[k]='\0';
      void *resultArr=malloc(k+1);
      if (NULL==resultArr) {
       cout<<"error in the malloc process"<<endl;
       }
      memset(resultArr,0,k+1);
      memcpy(resultArr,s1,k);
      reverseWords(resultArr,k);
      s=string(static_cast<char *>(resultArr));
      free(resultArr);
    }
    }
    void *reverseWords(void *pMemory,const size_t memSize)
    {
        char *pStart=static_cast<char *>(pMemory);
        //check having space or not
        bool isHaveSpace=false;
        for(size_t i=0;i<memSize;++i)
        {
            if(SPACESEPARATOR==pStart[i])
            {
                isHaveSpace=true;
                break;
            }
        }
        if (isHaveSpace)
        {
            reverseMemory(pMemory,memSize);
            size_t index=0,istart=0;
            for(;index<=memSize;++index)
            {
                if (' '==pStart[index]||NULL==pStart[index])
                {
                    reverseMemory(pStart+istart,index-istart);
                    istart=index+1;
                }
            }
        }
        return pMemory;
    }
    void *reverseMemory(void* pMemory,const size_t memSize)
    {
        if (NULL==pMemory) return pMemory;
        if (memSize<2) return pMemory;
        
        char *beg=static_cast<char *>(pMemory);
        char *end=beg+memSize-1;
        for(;beg<end;++beg,--end)
        {
            char memTmp=*beg;
            *beg=*end;
            *end=memTmp;
        }
        return pMemory;
    }
};

int main(){
Solution solution;
string s1="123 456";
string &s=s1;
solution.reverseWords(s);
cout<<s<<endl;
}
