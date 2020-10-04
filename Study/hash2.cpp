#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

const int TABLE_SIZE =128;

class HashEntry
 {
    int key;
    char value[100];
    HashEntry *next;
   
    public:
    HashEntry(int key,char *value);
    char *getvalue();
    int getkey();
    HashEntry *getnext();
    void setnext(HashEntry *);
    void setvalue(char *value);
};

HashEntry :: HashEntry(int key,char *value)
 {
    this->key=key;
    strcpy(this->value,value);
    this->next=NULL;
 }

char * HashEntry :: getvalue()
 {
    return this->value;
 }

int HashEntry :: getkey()
 {
    return this->key;
 }

void HashEntry :: setvalue(char *value)
  {
     strcpy(this->value,value);
  }

HashEntry *HashEntry :: getnext()
 {
   return this->next;
 }
    
void HashEntry :: setnext(HashEntry *next)
 {
   this->next=next;
 }
     

class HashMap
 {
    private :
      HashEntry **table;
    public:
      HashMap();
      void put(int key,char *value);
      char *get(int key);
      void remove(int key);
      ~HashMap();
 };


HashMap :: HashMap()
 {
    table=new HashEntry *[TABLE_SIZE];
    for(int i=0;i<TABLE_SIZE;i++)
     table[i]=NULL;
 }

char *HashMap :: get(int key)
 {
    int hash=key%TABLE_SIZE;
    HashEntry *temp=table[hash];
    if(temp==NULL)
      return NULL;
    else
      {
         while(temp!=NULL && temp->getkey()!=key)
            temp=temp->getnext();
         if(temp==NULL)
            return NULL;
         else
             return temp->getvalue();
      }
 } 

void HashMap :: put(int key,char *value)
 {
     int hash=key%TABLE_SIZE;
     if(table[hash]==NULL)
         table[hash]=new HashEntry(key,value);
     else
       {
         HashEntry *temp=table[hash];
         while(temp->getnext()!=NULL )
                temp=temp->getnext();
         temp->setnext(new HashEntry(key,value));
       }
 }

void HashMap :: remove(int key)
 {
    int hash=key % TABLE_SIZE;
    if(table[hash]==NULL)
        return;
    else
     {
        HashEntry *prev,*old;
        prev=NULL;
     
        HashEntry *ptr=table[hash];
        
        while(ptr->getnext()!=NULL  && ptr->getkey()!=key)
           {
                prev=ptr;
                ptr=ptr->getnext();
           }
        if(ptr->getkey()==key)
          {
            if(prev==NULL)
              {
                prev=ptr;
                ptr=ptr->getnext();
                delete prev;
                table[hash]=ptr;
              }
            else
             {
               prev->setnext(ptr->getnext());
               delete ptr;
             }
         }  
      }
 }

HashMap :: ~HashMap()
 {
   for(int i=0;i<TABLE_SIZE;i++)
    {
       if(table[i]!=NULL)
         {
            HashEntry *temp=NULL;
            HashEntry *ptr=table[i];
            while(ptr!=NULL)
             {
                 temp=ptr;
                 ptr=ptr->getnext();
                 delete temp;
             }
        }
    }
   delete table;
 }

void menu()
{
   cout<<"1.Insert\t";
   cout<<"2.Remove \t";
   cout<<"3.Search \t";
   cout<<"4.Exit \n";
}

int main()
{
   HashMap hash;
   int key,choice;
   char *value=new char[100];
   do
   {
     menu();
     cout<<"enter the choice \t";
     cin>>choice;
     switch(choice)
     {
      case 1:
          cout<<"Enter the key and the value \n";
          cin>>key>>value;
          hash.put(key,value);
          break;
      case 2:
          cout<<"Enter the key to remove \n";
          cin>>key;
          hash.remove(key);
          break;
      case 3:
          cout<<"enter the key to search \n";
          cin>>key;
          value=hash.get(key);
          cout<<value<<"\n";
          break;
      case 4:
          cout<<"exiting\n";
          break;
      default :
          cout<<"invlid option,try again \n";
          break;
      }
 }while(choice!=4);
  return 0;
}
                
