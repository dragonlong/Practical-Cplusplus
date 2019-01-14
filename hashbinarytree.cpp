/*
C++ programming to implement hash tree
edit by Xiaolong Li
*/
#include<iostream>
#include<cstdlib>
#include<string>
#include<cstdio>

using namespace std;
template<class T>
class bstNode
{
private:
    T value;
    bstNode *left, *right;
public:
    bstNode(T value)
    {
        this->value = value;
        left = NULL;
        right = NULL;
    }
    //??????
    void add(T& value)
    {
        if(value < this->value)
        {
            if (left)
                left->add(value);
            else
                left = new bstNode(value);
        }
        else if (this->value < value)
        {
            if (right)
                right->add(value);
            else
                right = new bstNode(value);
        }
    }
    bool contains(T& value)
    {
        if (value<this->value)
        {
            if (left)
            {
                return left->contains(value);
            }
            else
                return false;
        }
        else if (this->value < value)
        {
            if (right)
                return right->contains(value);
            else
                return false;
        }
        else
        {
            return true;
        }
    }
    friend class bstHashtable;
};

/*
 * Table class
 */
class bstHashtable
{
private:
    int size;
    vector<bstNode<string>*>* bucket;
    int hash(string& s)
    {
        unsigned int hashVal = 0;
        for (unsigned int i=0; i<s.length(); i++)
        {
            hashVal ^= (hashVal << 5) + (hashVal)>>2 + s[i];
        }
        return hashVal % size;
    }
public:
    bstHashtable(int vectorSize)
    {
        size = vectorSize;
        bucket = new vector<bstNode<string>*>(size);
    }
    void add(string& s)
    {
        int index = hash(s);
        if (bucket->at(index) == NULL)
            bucket->at(index) = new bstHashtable<string>(s);
        else
            bucket->at(index)->add(s)
    }
    bool contains(string& s)
    {
        int index = hash(s);
        if (bucket->at(index) == NULL)
        {
            return false;
        }
        cout<<"string \""<<s<<"\" found at index: "<<index<<endl;
        return bucket->at(index)->contains(s);

    }

};

int main()
{
    bstHashtable table(10);
    string str;
    int choice;
    while (1)
    {

    }
}
