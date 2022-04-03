#include <iostream>
#include <windows.h>
#include <time.h>
#include <cstdlib>
#include <iomanip>

using namespace std;

void allocateMemory1D(int *&tab, int n);
void allocateMemory2D(int **&tab, int w, int k);
void fillArray1D(int *tab, int n, int a, int b);
void fillArray2D(int **tab, int w, int k, int a, int b);
void deleteArray1D(int *&tab);
void deleteArray2D(int **&tab, int w);
void display1D(int* tab, int n);
void display2D(int** tab, int w, int k);

void line(){cout<<"----------------------------------------------------\n";}
void lineD(){cout<<"===================================================\n";}

void menu(){
    cout<<"Menu\n"
        <<"1.Minimal element\n"
        <<"2.Count array elements(by value)\n"
        <<"3.Maximal element\n"
        <<"4.Array average\n"
        <<"5.End program process\n"
        <<"Choosing:";
}

int choose(){
    int a;
    menu();
    cin>>a;
    return a;
}

void minimalArray1D(int *array1D,int length){
    int min=array1D[0];
    int index=0;
    for(int a=0;a<length;a++){
        if(array1D[a]<min){
            min=array1D[a];
            index=a;
        }
    }
    cout<<"Minimal element for one dimnesional array is: array1D["<<index<<"]="<<min<<endl;
}
void minimalArray2D(int **array2D, int rows, int columns){
    int min=array2D[0][0];
    int indexA=0,indexB=0;
    for(int a=0;a<rows;a++){
        for(int b=0;b<columns;b++){
            if(array2D[a][b]<min){
                min=array2D[a][b];
                indexA=a;
                indexB=b;
            }
        }
    }
    cout<<"Minimal element for two dimnesional array is: array2D["<<indexA<<"]["<<indexB<<"]="<<min<<endl;
}

void countByValueArray1D(int *array1D,int length, int min, int max){
    cout<<"Elements counted by value in one dimensional array\n";
    int quantityCount[max-min+1];
    for(int a=0;a<sizeof(quantityCount)/sizeof(quantityCount[0]);a++){
        quantityCount[a]=0;
    }
    for(int a=0;a<length;a++){
        quantityCount[array1D[a]-min]++;
    }
    for(int a=0;a<sizeof(quantityCount)/sizeof(quantityCount[0]);a++){
        cout<<"\t["<<a+min<<"] is counted "<<quantityCount[a]<<" times\n";
    }
}

void countByValueArray2D(int **array2D, int rows, int columns, int min, int max){
    cout<<"Elements counted by value in one dimensional array\n";
    int quantityCount[max-min+1];
    for(int a=0;a<sizeof(quantityCount)/sizeof(quantityCount[0]);a++){
        quantityCount[a]=0;
    }
    for(int a=0;a<rows;a++){
        for(int b=0;b<columns;b++){
            quantityCount[array2D[a][b]-min]++;
        }
    }
    for(int a=0;a<sizeof(quantityCount)/sizeof(quantityCount[0]);a++){
        cout<<"\t["<<a+min<<"] is counted "<<quantityCount[a]<<" times\n";
    }
}

void findMaxArray1D(int *array1D,int length){
    int max=array1D[0];
    int index=0;
    for(int a=0;a<length;a++){
        if(array1D[a]>max){
            max=array1D[a];
            index=a;
        }
    }
    cout<<"Maximal element for one dimnesional array is: array1D["<<index<<"]="<<max<<endl;
}

void findMaxArray2D(int **array2D, int rows, int columns){
    int max=array2D[0][0];
    int indexA=0,indexB=0;
    for(int a=0;a<rows;a++){
        for(int b=0;b<columns;b++){
            if(array2D[a][b]>max){
                max=array2D[a][b];
                indexA=a;
                indexB=b;
            }
        }
    }
    cout<<"Maximal element for two dimnesional array is: array2D["<<indexA<<"]["<<indexB<<"]="<<max<<endl;
}

findAverageArray1D(int *array1D,int length){
    int sum=0;
    for(int a=0;a<length;a++){sum+=array1D[a];}
    cout<<"Average for one dimnesional array is: "<<float(sum)/float(length)<<endl;
}

findAverageArray2D(int **array2D, int rows, int columns){
    int sum=0;
    for(int a=0;a<rows;a++){
        for(int b=0;b<columns;b++){sum+=array2D[a][b];}
    }
    cout<<"Average for two dimnesional array is: "<<float(sum)/(float(rows)*float(columns))<<endl;
}

int main()
{
    srand(time(NULL));

    lineD();
        int *array1D;
        int **array2D;
            int length;     //1D array
            int rows;       //2D array
            int columns;    //2D array
            int lowerInterval;
            int upperInterval;
        cout<<"Enter one dimensional array length:";
            cin>>length;
    line();
        cout<<"Enter two dimensional array dimensions:\n\t-rows:";
            cin>>rows;
        cout<<"\t-columns:";
            cin>>columns;
        cout<<"Enter min and max value to fill arrays:\n\t-min:";
            cin>>lowerInterval;
        cout<<"\t-max:";
            cin>>upperInterval;
        //allocating memory
            allocateMemory1D(array1D,length);
            allocateMemory2D(array2D,rows,columns);
        //filling arrays with values
            fillArray1D(array1D,length,lowerInterval,upperInterval);
            fillArray2D(array2D,rows,columns,lowerInterval,upperInterval);
    line();
        //display created arrays:
        cout<<"\tOne dimensional array:\n";
            display1D(array1D,length);
        cout<<"\tTwo dimensional array:\n";
            display2D(array2D,rows,columns);
    lineD();


    int a=choose();
    while(a!=5){
        switch (a){
    case 1:
        lineD();
            //system("cls");
            cout<<"Minimal element in array:"<<endl;
                minimalArray1D(array1D,length);
                minimalArray2D(array2D,rows,columns);
        lineD();
        a=choose();
        break;
    case 2:
        lineD();
            //system("cls");
            cout<<"Count array elements (by value):"<<endl;
                    countByValueArray1D(array1D,length,lowerInterval,upperInterval);
                    countByValueArray2D(array2D,rows,columns,lowerInterval,upperInterval);
        lineD();
        a=choose();
        break;
    case 3:
        lineD();
        //system("cls");
            cout<<"Maximal element:"<<endl;
                findMaxArray1D(array1D,length);
                findMaxArray2D(array2D,rows,columns);
        lineD();
        a=choose();
        break;
    case 4:
        lineD();
        //system("cls");
            cout<<"Array average:"<<endl;
                findAverageArray1D(array1D,length);
                findAverageArray2D(array2D,rows,columns);
        lineD();
        a=choose();
        break;
        }

    }

lineD();
    cout<<"Memory release\n";
    deleteArray1D(array1D);
    deleteArray2D(array2D,rows);
    return 0;
}

void allocateMemory1D(int *&tab, int n){
    tab = new int[n];
}
void allocateMemory2D(int **&tab,int w, int k){
    tab = new int*[w];
    for(int i = 0; i < w;i++){
        tab[i] = new int[k];
    }
}
void fillArray1D(int *tab,int n, int a, int b){
    int liczba;
    for(int i = 0; i < n; i++){
        liczba = rand() % (b-a+1)+a;
        tab[i] = liczba;
    }
}
void fillArray2D(int **tab,int w, int k, int a, int b){
    int liczba;
    for(int i = 0; i < w; i++){
        for(int x = 0; x < k; x++){
            liczba = rand() % (b-a+1)+a;
            tab[i][x] = liczba;
        }
    }
}
void deleteArray1D(int *&tab){
    delete [] tab;
}
void deleteArray2D(int **&tab,int w){
    for(int i = 0; i < w; i++){
        delete [] tab[i];
    }
    delete [] tab;
}
void display1D(int* tab, int n){
    for(int i = 0; i< n; i++){
        cout<<setw(4)<<tab[i];
    }
    cout<<endl;
}

void display2D(int** tab, int w, int k){
    for(int i = 0; i < w; i++){
        for(int x = 0; x < k; x++){
            cout<<setw(4)<<tab[i][x];
        }
        cout<<endl;
    }
}

