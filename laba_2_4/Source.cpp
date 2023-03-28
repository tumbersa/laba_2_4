#include <iostream>
using namespace std;

const int n2 = 3, m2 = 4;
void CocktailSort(int* a, int n,bool f =true)//f= true по возрастанию
{
    bool swapped = true;
    int start = 0;
    int end = n - 1;

    while (swapped) {
        
        swapped = false;

        if (f)
         for (int i = start; i < end; ++i) {
                if (a[i] > a[i + 1]) {
                   swap(a[i], a[i + 1]);
                    swapped = true;
             }
         }
        else 
            for (int i = start; i < end; ++i) {
                if (a[i] < a[i + 1]) {
                    swap(a[i], a[i + 1]);
                    swapped = true;
                }
            }

       
        if (!swapped)
            break;

        
        swapped = false;

       
        --end;

       
        if (f)
        for (int i = end - 1; i >= start; --i) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                swapped = true;
            }
        }
        else
            for (int i = end - 1; i >= start; --i) {
                if (a[i] < a[i + 1]) {
                    swap(a[i], a[i + 1]);
                    swapped = true;
                }
            }

        
        ++start;
    }
}


void print(int* a, int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}
void print(int (*a)[m2], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j=0;j<m;j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}
bool isSorted(int a[],bool f=true) {//f= true по возрастанию
    int n = sizeof(a) / sizeof(a[0]);
    bool flag = true;
    if (n == 1) return flag;
    if (f)
        for (int i = 1; i < n; i++) {
            if (a[i] < a[i - 1]) flag = false;
        }
    else 
        for (int i = 1; i < n; i++) {
            if (a[i] > a[i - 1]) flag = false;
        }
    return flag;
}
bool SHAKER_SHAKER(int (*a)[m2], int n, int m, bool flag=true) {
    bool flag2 = true;
    if (n == 1) {
        CocktailSort(a[0], m,flag);
        return flag2;
    }



    int i1 = 0, j1 = 0;
    bool fAct = false, fState = true;
    for (int i = 0; i < n * m; i++) {
        cout << i1 << " " << j1 << endl;
        if (!fAct) {
            if (i1 != 0 || j1 != 0)i--;
            if (i1 < n - 1) i1++;
            else if (j1 < m - 1) j1++;

            fAct = true;
        }
        else
        {
            int i2 = i1, j2 = j1;
            int k = 0;
            while (i2 >= 0 && j2 <= m - 1) {
                i2--;
                j2++;
                k++;
            }
            i2 = i1; j2 = j1;
            int l = 0;
            int* temp = new int[k];
            while (i2 >= 0 && j2 <= m - 1) {
                temp[l] = a[i2][j2];
                i2--;
                j2++;
                l++;
            }
            CocktailSort(temp, k, fState);
            i2 = i1; j2 = j1;
            l = 0;
            while (i2 >= 0 && j2 <= m - 1) {
                a[i2][j2] = temp[l];
                i2--;
                j2++;
                l++;
                i++;
            }
            i--;
            fState = !fState;

            fAct = false;
        }

    }
    print(a, n, m);
    

    int* b = new int[n * m];
    i1=0,j1=0;
    fAct = false,fState = true;
    for (int i = 0; i < n * m; i++) {  
        cout << i1 << " " << j1<<endl;
        if (i1==0 && j1==0) b[i] = a[i1][j1];
        if (!fAct) {
            if (i1 != 0 || j1 != 0)i--;
            if (i1 < n - 1) i1++;
            else if (j1 < m - 1) j1++;
            
            fAct = true;
        }
        else
        {
            if (fState) {
                int i2 = i1, j2 = j1;
                while (i2 >= 0 && j2 <= m - 1) {
                    b[i] = a[i2][j2];
                    i2--;
                    j2++;
                    
                    i++;
                }
                i--;
                fState = false;
            }
            else
            {
                int i2 = i1, j2 = j1;
                while (i2 > 0 && j2 < m - 1) {
                    i2--;
                    j2++;
                }
                while (i2<=i1 && j2>=j1) {
                    
                    b[i] = a[i2][j2];
                    i++;
                    i2++;
                    j2--;
                }
                i--;
                fState = true;
            }
            
            fAct = false;
        }
        
    }
    print(b,n*m);
    flag2 = isSorted(b,flag);
    return flag2;
}
int main()
{
    
    /*int** b = new int*[n2];
    for (int i = 0; i < n2; i++) {
        b[i] = new int[m2];
    }*/
    int b[n2][m2] = {
        {1,2,6,7},
        {3,5,8,10},
        {4,9,11,12}
    };
    print(b, n2, m2);
    cout<<SHAKER_SHAKER(b, n2, m2, true)<<endl;
    

    

    /*for (int i = 0; i < n2; i++) {
        delete []b[i];
    }
    delete []b;*/
    return 0;
}