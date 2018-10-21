#include <fstream>
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

///NU MERGE CU INTERVALE DESCARCATOARE ex: 11 - 2 ca pe ceas

class Interval
{
    int begining, ending;
public:
    int set(int beg=0,int endd=0)
    {
        if(beg==endd) return 0;
        else if(beg<endd)
        {
        begining=beg;
        ending=endd;
        }
        else
        {
        begining=endd;
        ending=beg;
        }
        return 1;
    }

    int durata()
    {
        return ending-begining;
    }

    int operator=(const Interval& I)
    {
        begining=I.begining;
        ending=I.ending;
    }

    Interval operator+(Interval I)
    {
        Interval sum;
        sum.begining=begining;
        sum.ending=I.ending;
        return sum;
    }

    Interval operator+=(Interval I)
    {
        *this=this->operator+(I);
        return *this;
    }

    bool operator< (Interval I)
    {
        if(begining<I.begining) return 1;
        if(begining==I.begining && durata()<I.durata()) return 1;
        return 0;
    }

    bool operator<=(Interval I)
    {
        if(ending<=I.begining) return 1;
        return 0;
    }

friend ifstream& operator>> (ifstream& fin, Interval& I);
friend ostream& operator<< (ostream& out, const Interval& I);
};

ifstream& operator>> (ifstream& fin, Interval& I)
{
    fin>>I.begining>>I.ending;
    return fin;
}

ostream& operator<< (ostream& out, const Interval& I)
{
    out<<"("<<I.begining<<" "<<I.ending<<")";
    return out;
}

void afisVectInterv(const vector<Interval>& I)
{
    for(int i=0;i<I.size();i++)
        cout<<I[i]<<"\n";
cout<<"\n";
}


class Aranjare
{
    int nrSali, nrEven;
    vector < vector <Interval> >  repart;
public:
    Aranjare()
    {
        nrSali=0;
        nrEven=0;
        repart.resize(1);
        Interval zero;
        repart[0].push_back(zero);
    }

    ~Aranjare()
    {
        for(int i=0;i<repart.size();i++)
            repart[i].clear();
        repart.clear();
        nrSali=0;
    }

    int operator+=(Interval I)
    {
        if(nrSali==0)
            {
            addInSalaNoua(I);
            return nrSali;
            }
        else
        {
            for(int i=1;i<=nrSali;i++)
                if(repart[0][i]<=I)
                {
                    addInSala(i,I);
                    return i;
                }
            addInSalaNoua(I);
            return nrSali;
        }
    }

    int addInSalaNoua(Interval I)
    {
        nrSali++;
        nrEven++;
        repart.resize(nrSali+1);
        repart[0].push_back(I);
        repart[nrSali].push_back(I);
    }

    int addInSala(int sala, Interval I)
    {
        if(sala>nrSali)
        {
            addInSalaNoua(I);
            return nrSali;
        }
        else
        {
            if(repart[0][sala]<=I==0) return 0;
            repart[0][sala]+=I;
            repart[sala].push_back(I);
            nrEven++;
            return sala;
        }
    }

void program()
{
    cout<<"Evenimente: "<<nrEven<<"\tSali: "<<nrSali<<"\n";
    for(int i=1;i<=nrSali;i++)
    {
        cout<<"-Sala "<<i<<"\t"<<repart[0][i]<<"\n";
        for(int j=0;j<repart[i].size();j++)
            cout<<repart[i][j]<<" ";
        cout<<"\n";
    }
}

};

int ProgramareSali(vector<Interval> ve, Aranjare& A)
{
    sort(ve.begin(),ve.end());
    for(int i=0;i<ve.size();i++)
        int sala = A+=ve[i];
}

int main()
{
ifstream f ("intervale.in");
int n;
vector<Interval> ve, rez;
f>>n;
ve.resize(n);
for(int i=0;i<n;i++) f>>ve[i];

Aranjare A;

ProgramareSali(ve,A);

A.program();

return 0;
}
