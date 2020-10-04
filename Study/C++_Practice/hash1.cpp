#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<cstring>
using namespace std;

const int TABLE_SIZE =128;

class HashEntry
{
   char value[100];
   int key;

   public:
   HashEntry(int key ,char *value);
   int getkey();
   char *getvalue();
};

HashEntry ::HashEntry(int key,char *value)
  {
     strcpy(this->value,value);
     this->key=key;
  }

int HashEntry :: getkey()
   {
      return this->key;
   }
  
char *HashEntry :: getvalue()
  {
      return this->value;
  }



class HashMap
 {
    private:
       HashEntry **table;
    public:
       HashMap();
       char *get(int key);
       void put(int key,char *value);
       ~HashMap();
};


HashMap :: HashMap()
  {
     table=new HashEntry* [TABLE_SIZE];
     for(int i=0;i<TABLE_SIZE;i++)
        table[i]=NULL;
  }


char *HashMap :: get(int key)
  {
       int hash=key % TABLE_SIZE;
       while((table[hash]!=NULL) && (table[hash]->getkey()!=key))
        {
             hash=(hash+1)%TABLE_SIZE;
        }
       if(table[hash]==NULL)
            return NULL;
       else
            return table[hash]->getvalue();
   }


void HashMap :: put(int key,char *value)
   {
       int hash=(key % TABLE_SIZE);
       while(table[hash]!=NULL && table[hash]->getkey()!=key)
        {
		hash=(hash+1)%TABLE_SIZE;
        }
        if(table[hash]!=NULL)
               delete table[hash];
        table[hash]=new HashEntry(key,value);
   }

HashMap :: ~HashMap()
  {
     for(int i=0;i<TABLE_SIZE;i++)
        if(table[i]!=NULL)
              delete table[i];
     delete []table;
  }

        
void menu()
 {
    cout<<"1.insert"<<"\t";
    cout<<"2.search"<<"\t";
    cout<<"3.exit"<<"\n";
 }

int main()
{
   HashMap hash;
   int choice,key;
   char *data=new char[100];
   do
   {
      menu();
      cout<<"Enter the choice \t";
      cin>>choice;
      switch(choice)
      {
        case 1:
           cout<<"enter the key and data\n";
           cin>>key>>data;
           hash.put(key,data);
           break;
        case 2:
           cout<<"enter the key \t";
           cin>>key;
           data=hash.get(key);
           if(data==NULL)
             cout<<"key not found\n";
           else
             cout<<data<<endl;
           break;
        case 3:
            cout<<"exiting\n";
            break;
        default:
            cout<<"Invalid option \n";
            break;
      }
  }while(choice !=3);
  return 0;
}
 
