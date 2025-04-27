//B-5
#include<iostream>
#include<string>

using namespace std;

struct Node{
    int Ccount;
    string label;
    Node* children[20];
};

class book
{
        Node* root=nullptr;
    public:
    
    
void create(){
    root=new Node;
    cout<<"enter the book name :";
    cin.ignore();
    getline(cin,root->label);
     
    
    cout<<"enter chapters :";
    cin>>root->Ccount;
    cin.ignore();
    
    
    for(int i=0;i<=root->Ccount;++i)
    {
        
        root->children[i]=new Node;
        cout<<"chapters "<<i+1<<" name :";
        getline(cin,root->children[i]->label);
        
        cout<<"enter section :";
        cin>>root->children[i]->Ccount;
        cin.ignore();
    
    
    for(int j=0;j<=root->children[i]->Ccount;++j)
        {
        
            root->children[i]->children[j]=new Node;
            cout<<"section "<<j+1<<" name :";
            getline(cin,root->children[i]->children[j]->label);
            
    
            cout<<"enter subsection :";
            cin>>root->children[i]->children[j]->Ccount;
            cin.ignore();
    
    
    for(int k=0;k<=root->children[i]->children[j]->Ccount;++k)
            {
        
                root->children[i]->children[j]->children[k]=new Node;
                cout<<"subsection "<<k+1<<" name :";
                getline(cin,root->children[i]->children[j]->children[k]->label);
                
            }

        }
    }
}


void displaytree(Node* cur,int depth=0)
        {
            if(!cur) return;
            cout<<string(depth *4, ' ')<<cur->label<<endl;
            for(int i=0;i<cur->Ccount;++i)
                displaytree(cur->children[i],depth+1);
        }
        
void display()
        {   cout<<"----Book Hirearchy----\n";
            displaytree(root);
        }
};
        
int main()
{
        book b;
        int ch;
        
        while(true)
        {
            cout<<"1.Add book\n2.display book\n3.exit\n";
            cout<<"enter choice :";
            cin>>ch;
            if(ch==1) b.create();
            else if(ch==2) b.display();
            else if(ch==3) break;
            else cout<<"invalid choice";
        }
        
}
