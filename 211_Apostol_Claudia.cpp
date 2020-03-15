#include <iostream>
#include<string.h>
#include<stdlib.h>
#include<bits/stdc++.h>
using namespace std;
class nod
{
private:
    char info;
    nod* next;
public:
//    nod(char info='\0',nod *next=NULL)
//    {
//        this->info=info;
//        this->next=next;
//
//    }
    nod()
    {
        this->info='\0';
        this->next=NULL;
    }
    nod(char info, nod *next)
    {
         this->info=info;
       this->next=next;
    }
    ~nod()
    {
        this->info=NULL;
        this->next=NULL;
    }
    friend class stivac;
};
class stivac
{
    nod* tos;
public:
    stivac();
    stivac(nod *t);
    ~stivac();
    void push(int x);
    char top();
    void pop();
    int isempty();
    void afis(ostream &out);
    friend istream& operator>>(istream &in,stivac& s);
    friend ostream& operator<<(ostream &out,stivac& x);
    friend stivac& operator-(stivac& s1, stivac& s2);
};
stivac::stivac()
{
    tos=NULL;
}
stivac::stivac(nod *t)
{
    tos=t;
}
stivac::~stivac()
{
    while(!isempty())
    {
        pop();
    }
}
void stivac::push(int x)
{
    nod* aux=new nod;
    aux->info=x;
    aux->next=tos;
    tos=aux;
}
char stivac::top()
{
    char a;
    a=tos->info;
    return a;
}
void stivac::pop()
{

    if(isempty()==0)
    {
        nod* aux=tos;
        tos=aux->next;
        delete aux;
    }
    else
    {
        cout<<"Stiva este vida";
        return;
    }

}
int stivac::isempty()
{
    return (tos==NULL);
}
void stivac::afis(ostream &out)
{
    out<<endl;
    nod *aux=new nod;
    aux=tos;
    if (!isempty())
    {
        while(aux!=NULL)
        {
            out<<aux->info<<endl;
            aux=aux->next;
        }
    }
    else
        out<<"Stiva este vida"<<endl;
}

istream& operator>>(istream &in,stivac& s)
{
    int n,i;
    cout<<"Cate caractere citesc? ";
    in>>n;
    char nr;
    for(i=0; i<n; i++)
    {
        in>>nr;
        s.push(nr);
    }
    return in;
}
ostream& operator<<(ostream &out,stivac& s)
{
    s.afis(out);
    return out;
}
void invers(char sir[])
{
    stivac *st=new stivac;
    int i,nr=0;
    for(i=0; i<strlen(sir); i++)
    {
        st->push(sir[i]);
    }
    i=0;
    nr=strlen(sir);
    char nou[nr+1];
    while(nr!=0)
    {
        nou[i]=st->top();

        st->pop();
        i++;
        nr--;
    }
    nou[i]=NULL;
    strcpy(sir,nou);
}
stivac& operator-(stivac& s1, stivac& s2)
{
    stivac* sfin=new stivac;
    int i,j;
    char a1,a2;
    while(s1.isempty()==0  && s2.isempty()==0)
    {
        a1=s1.top();
        a2=s2.top();
        if(a1!=NULL and a2!=NULL)
        {
            i=int(a1);
            j=int(a2);

            if(i>j)
                sfin->push(a1);
            else
                sfin->push(a2);
            s1.pop();
            s2.pop();
        }
    }
    return *sfin;

}

void menu_output()
{
    cout<<endl<<"Apostol Claudia Grupa 211- tema 4- Stiva de caractere"<<endl;
    cout<<endl<<"MENIU:";
    cout<<endl<<"--------------------------------------------------"<<endl;
    cout<<endl;
    cout<<"1. Citire a n stive "<<endl;
    cout<<"2. Afisare a n stive"<<endl;
    cout<<"3. Verificare daca o stiva e vida"<<endl;
    cout<<"4. Afisarea varfului unei stivei"<<endl;
    cout<<"5. Inversarea unui sir de caractere"<<endl;
    cout<<"6. Stergerea unui caracter dintr-o stiva"<<endl;
    cout<<"7. Diferenta a doua stive "<<endl;
    cout<<"0. Iesire"<<endl;
}
void menu()
{
    int option;
    do
    {
        menu_output();
        cout<<endl;
        cout<<endl<<"Introduceti numarul actiunii: ";
        cin>>option;
        if(option==0)
            cout<<"EXIT"<<endl;
        if(option<0 || option>7)
            cout<<endl<<"Selectie invalida"<<endl;
        int nr,i,ok1;
        stivac *s;
        if(option==1)
        {
            cout<<"Numarul de stive citite: ";
            cin>>nr;
            try
            {
                s=new stivac[nr+2];
            }
            catch(bad_alloc xa)
            {
                cout<<"Nu s-a putut aloca memorie";
                exit(EXIT_FAILURE);
            }
            for(i=1; i<=nr; i++)
            {
                cout<<endl<<"STIVA "<<i<<endl;
                cin>>s[i];
            }
            ok1=1;
        }
        if(option==2)
        {
            if(ok1==1)
            {
                for(i=1; i<=nr; i++)
                {
                    cout<<endl<<"Stiva "<<i<<" contine:"<<endl;
                    cout<<s[i];
                    //cout<<s[i].isempty()<<endl;
                    //cout<<nr<<endl;
                    //s[i].afis();
                }

            }
            else
                cout<<"Trebuie efectuata mai intai citirea"<<endl;
        }
        cout<<endl;
        if(option==5)
        {
            char sir[100];
            cout<<"Cititi un sir"<<endl;
            cin.get();
            cin.get(sir,100);
            invers(sir);
            cout<<"Sirul inversat este: "<<endl;
            cout<<sir;
            cout<<endl;
        }
        if(option==4)
        {

            if(ok1==1)
            {
                cout<<"Afisez varful pentru stiva ";
                int o;
                cin>>o;
                if(o<0 || o>nr)
                    cout<<endl<<"Nu exista aceasta stiva"<<endl;
                else if(s[o].isempty()==0)
                    cout<<s[o].top()<<endl;
                else
                    cout<<"stiva este vida"<<endl;
            }
            else
                cout<<"Nu a fost efectuata citirea"<<endl;
        }
        if(option==3)
        {
            if(ok1!=1)
                cout<<"Nu a fost efectuata citirea"<<endl;
            else
            {
                cout<<"Ce stiva verific? ";
                int x;
                cin>>x;
                if(s[x].isempty()==0)
                {
                    if(x<=nr)
                        cout<<"Nu este vida"<<endl;
                    else
                        cout<<"Nu exista aceasta stiva"<<endl;
                }
                else
                    cout<<"Este vida"<<endl;

            }
        }
        if(option==6)
        {
            if(ok1==1)
            {
                cout<<"Sterg din stiva ";
                cin>>i;
                if(i<=nr &&i>0)
                {
                    if(s[i].isempty()==0)
                    {
                        s[i].pop();
                        cout<<endl<<"Stiva rezultata"<<endl;
                        cout<<s[i];
                        cout<<endl;
                    }
                    else
                        cout<<"Stiva este vida"<<endl;
                }
                else
                    cout<<"Nu exista aceasta stiva"<<endl;
            }
            else
                cout<<"Nu a fost efectuata citirea"<<endl;
        }

        if(option==7)
        {
            if(ok1==1)
            {
                cout<<"Se face diferenta intre stiva ";
                cin>>i;
                cout<<"si stiva ";
                int j;
                cin>>j;
                stivac *a=new stivac;

                if(i<=7 && j<=7 &&i>0 &&j>0)
                {

                        *a=s[i]-s[j];
                        cout<<*a;

                }
                else
                    cout<<"Nu exista aceasta stiva"<<endl;
            }

            else
                cout<<"Nu a fost efectuata citirea"<<endl;
        }
        system("pause");
        system("CLS");
    }
    while(option!=0);
}
int main()
{
    menu();
    return 0;


}
