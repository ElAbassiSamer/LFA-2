#include <iostream>
#include <fstream>
#include<bits/stdc++.h>
using namespace std;
ifstream f("date.in");
struct multime{int v[100];int k,viz;}m;
struct corespodenta{multime m1,m2;};
struct corespodenta1{int x1,y1;};
struct tranzi{corespodenta1 legatura[100];int n;}tranz[256],tranz1[256];
void afis_m(multime l)
{int j;
cout<<"{";
for (j=0;j<l.k-1;j++)
    cout<<l.v[j]<<",";
cout<<l.v[l.k-1];
cout<<"}";
}
bool areEqual(int arr1[], int arr2[], int n, int m)
{
    // If lengths of array are not equal means
    // array are not equal
    if (n != m)
        return false;

    // Sort both arrays
    sort(arr1, arr1+n);
    sort(arr2, arr2+m);

    // Linearly compare elements
    for (int i=0; i<n; i++)
         if (arr1[i] != arr2[i])
            return false;

    // If all elements were same.
    return true;
}
void sterge_dupicate(int h[100],int &  k)
{int i1,j1,b1;
 for (i1=0;i1<k-1;i1++)
    for (j1=i1;j1<k;j1++)
        if (h[j1]==h[i1])
            {for (b1=j1;b1<k;b1++)
                h[b1]=h[b1+1];
             k--;}
}
int main()
{   int nr_stari,stare[100],nr_litere,init,nr_finale,stari_finale[100],nr_tranzitii,x,y,conversie,i,j,ind_vector,l,copie;
    char caracter,litere[100];
    f>>nr_stari;
    for (i=0;i<nr_stari;i++)
        {f>>x;
         stare[i]=x;
        }
    f>>nr_litere;
    for (i=0;i<nr_litere;i++)
        {f>>caracter;
         litere[i]=caracter;
        }
    f>>init;
    f>>nr_finale;
    for (i=0;i<nr_finale;i++)
        {f>>x;
         stari_finale[i]=x;
        }
    f>>nr_tranzitii;
    for (i=0;i<=256;i++)
    tranz1[i].n=0;
    for (i=0;i<nr_tranzitii;i++)
        {f>>x;
         f>>caracter;
         f>>y;
         int conversie=int(caracter);
         //trebuie init cu 0 toate n-urile
         int dim=tranz1[conversie].n;
         tranz1[conversie].legatura[dim].x1=x;
         tranz1[conversie].legatura[dim].y1=y;
         tranz1[conversie].n++;
        }

       multime stari_noi[100];
       stari_noi[0].v[0]=init;
       stari_noi[0].k=1;
       stari_noi[0].viz=1;
       int index_stari=1;
       i=0;
       int intrat;
       while (i<256)
        {int dim=tranz1[i].n;
         int ind_vector=0;
         intrat=0;
         while (dim!=-1)
            {if (tranz1[i].legatura[dim].x1==init)
                {stari_noi[index_stari].v[ind_vector]=tranz1[i].legatura[dim].y1;
                 ind_vector++;
                 stari_noi[index_stari].k=ind_vector;intrat=1;}
                 dim--;}
             if (intrat==1) index_stari++;
        i++;}
        /*for (i=0;i<index_stari;i++)
            {cout<<i<<endl;
            afis_m(stari_noi[i]);
            cout<<endl;}*/
    j=0;

    while (j<256)
        {while (tranz1[j].n==0 && j<256)
            j++;
        if (tranz1[j].n!=0)
        {caracter=j;
        cout<<"            ";
        cout<<caracter<<"           | ";}
        j++;}
    cout<<endl<<"---------------------------------------------------"<<endl;
    cout<<"1           ";
    for (i=1;i<index_stari;i++)
        {afis_m(stari_noi[i]); cout<<"       |         ";}

    stari_noi[0].viz=1;
    i=1;
    cout<<endl;
    while(stari_noi[index_stari].viz!=1)
    {stari_noi[i].viz=1;
     afis_m(stari_noi[i]);
     cout<<endl;
     j=0;
     while (j<256)
        {while (tranz1[j].n==0 && j<256)
                j++;
         intrat=0;ind_vector=0;
         if (tranz1[j].n!=0 && j<256)         //am un caracter
            {         //initializez noua multime cu 0
             int dim=tranz1[j].n-1;
             while (dim!=-1)        //cat timp mai am legaturi in vectorul cu caracterul dat
                {   for (l=0;l<stari_noi[i].k;l++)
                    if (tranz1[j].legatura[dim].x1==stari_noi[i].v[l])
                        {   cout<<"Gasit o pereche:"<<stari_noi[i].v[l]<<"Pe index stare"<<index_stari;
                            int copie=index_stari;
                            stari_noi[copie].v[ind_vector]=tranz1[j].legatura[dim].y1;
                            ind_vector++;
                            stari_noi[copie].k=ind_vector;intrat=1;}

                 dim--;
                }


            }
        if(intrat==1)
                {   index_stari++;
                    for (int z=2;z<index_stari;z++)
                    if (areEqual(stari_noi[copie].v,stari_noi[z].v,ind_vector,stari_noi[z].k)) index_stari--; }
        j++;
        }
        i++;
    }
    cout<<endl;
    for (i=0;i<index_stari;i++)
        {cout<<"index stari este"<<index_stari;
        afis_m(stari_noi[i]);}
        cout<<endl;
    return 0;
}
