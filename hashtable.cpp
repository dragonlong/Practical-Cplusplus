/*
C++ programming to implement hash tables
edit by Xiaolong Li
*/
#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>

using namespace std;
const int TABLE_SIZE = 128;

/*
 * HashEntry Class(base class)
 */
class HashEntry
{
  public:
    int key;
    int value;
    HashEntry(int key, int value)
    {
      this->key = key;
      this->value = value;
    }
};
/*
 * HashTable Class(for real use)
 */
class HashTable
{
private:
    HashEntry **table;
public:
    // init
    HashTable()
    {
        table = new HashEntry * [TABLE_SIZE];
        for (int i=0; i< TABLE_SIZE; i++)
        {
            table[i] = NULL;
        }
    }
    //
    int HashFunc(int key)
    {
        return key % TABLE_SIZE;
    }
    // insert method
    void insert(int key, int value)
    {
        int hash = HashFunc(key);
        while (table[hash]!=NULL && table[hash]->key !=key)
        {
            hash = HashFunc(hash+1);
        }
        if (table[hash] !=NULL)
            delete table[hash];
        table[hash] = new HashEntry(key, value);
    }
    // search method
    int search(int key)
    {
        int hash = HashFunc(key);
        while (table[hash]!=NULL && table[hash]->key !=key)
        {
            hash = HashFunc(hash + 1);
        }
        if (table[hash] == NULL)
            return -1;
        else
            return table[hash]->value;
    }
    // remove method
    void remove(int key)
    {
        int hash = HashFunc(key);
        while(table[hash] !=NULL)
        {
            if (table[hash]->key == key)
                break;
            hash = HashFunc(hash+1);
        }
        if (table[hash]==NULL)
        {
            cout<<"No element found at key "<<key<<endl;
            return;
        }
        else
        {
            delete table[hash];
        }
        cout<<"Element deleted"<<endl;
    }
};

//main function entry
int main()
{
  cout<<"\n------------Welcome to Xiaolong's Data structure-----------"<<endl;
  // A new instance of hash table
  HashTable hash;
  int key, value;
  int choice;
  while(1)
  {
      cout<<"\n----------------------"<<endl;
      cout<<"Operations on hash table"<<endl;
      cout<<"\n----------------------"<<endl;
      cout<<"1.Insert element into the table"<<endl;
      cout<<"2.Search element from the key"<<endl;
      cout<<"3.Delete element at a key"<<endl;
      cout<<"4.Exit"<<endl;
      cin>>choice;
      switch (choice)
      {
      case 1/* value */:
          cout<<"Entry element to be inserted: ";
          cin>>value;
          cout<<"Entry key at which element to be inserted: ";
          cin>>key;
          hash.insert(key, value);
          break;
      case 2:
          cout<<"Entry key to search from ";
          cin>>key;
          if (hash.search(key)==-1)
          {
              cout<<"No element found at key "<<key<<endl;
              continue;
          }
          else
          {
              cout<<"Element at key "<<key<<" : ";
              cout<<hash.search(key)<<endl;
          }
          break;
      case 3:
          cout<<"Enter key of the element to be deleted: ";
          cin>>key;
          hash.remove(key);
          break;
      case 4:
          exit(1);
      default:
          cout<< "/* message */" << '\n';
      }
  }
  return 0;
}
