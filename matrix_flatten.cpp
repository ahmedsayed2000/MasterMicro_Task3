# include <iostream>
using namespace std;

// global variables representing 3d matrix dimensions
int n, m, p;

// this function takes a 3d matrux and flattens it 
// to return a 1d array
int* flattenMatrix(int*** arr_3d) {
    int* arr_1d = new int[m * n * p];
    int counter = 0;
    for(int i=0 ; i<n; i++)
        for(int j=0 ; j<m; j++)
            for(int k=0 ; k<p; k++){
                arr_1d[counter++] =  arr_3d[i][j][k];
            }
    return arr_1d;

}

// this function get the flattened index (y) in the 1d array given
// the position {i, j, k}  in the 3d array by the following equation
int getIndexFlattened(int i, int j, int k, int*** arr_3d) {
    return i*m*n + j*p + k;
}


int main(){
    
    // reading the Dimensions of the 3f matrix 
    // any of them must be greater than 0

    // reading n
    cout<<"Enter the first dimension: ";
    cin>>n;
    while (n <= 0)
    {
        cout<<"Enter the first dimension again but not negative or zero: ";
        cin>>n;
    }

    // reading m
    cout<<endl;
    cout<<"Enter the second dimension: ";
    cin>>m;
      while (m <= 0)
    {
        cout<<"Enter the second dimension again but not negative or zero: ";
        cin>>m;
    }

    // reading p
    cout<<endl;
    cout<<"Enter the third dimension: ";
    cin>>p;
    while (p <= 0)
    {
        cout<<"Enter the third dimension again but not negative or zero: ";
        cin>>p;
    }
    cout<<endl;

    // initializing the 3d array
    int*** arr_3d = new int** [n];
    for(int i=0; i<n; i++){
        arr_3d[i] = new int* [m];
        for (int j=0; j<m; j++)
            arr_3d[i][j] = new int[p];
    }

    // getting the value from the user for the 3d array
    for(int i=0; i<n; i++)
        for (int j=0; j<m; j++)
            for(int k=0; k<p; k++){
                cout<<"Enter elment arr["<<i<<"]["<<j<<"]["<<k<<"] : ";
                cin>>arr_3d[i][j][k];
                cout<<endl;
            }


    // flattening the 3d matrix and store it in a 1d array
    int* arr_1d = flattenMatrix(arr_3d);

    int index = 0;
    bool testMode = true;
    int i,j,k;
    char out;

    // Entering the test mode
    cout<<"We are in Test mode"<<endl<<endl;
    while (testMode)
    {
        cout<<"Enter the positions of the Element in 3d_array"<<endl;
        cout<<"Enter i : ";    cin>>i;   cout<<endl;
        cout<<"Enter j : ";    cin>>j;   cout<<endl;
        cout<<"Enter k : ";    cin>>k;   cout<<endl;

        // calling the (getIndexFlattened) function to get the flattened index (y) 
        index = getIndexFlattened(i, j, k, arr_3d);
        
        // validating the index not out of range (m*n*p)
        if(index < m*n*p && index >= 0) {
            cout<<"the index in the flattened matrix ";
            cout<<"corresponding to "<<"["<<i<<"]["<<j<<"]["<<k<<"] is "<<index<<endl;
            cout<<"the elemet in the 1d array is : "<<arr_1d[index]<<endl;
        }
        else
            cout<<"the index is out of range or the position entered may be invalid"<<endl;

        // pressing (y) ---->  continue in the testing mode
        // pressing (n) ---->  get out of the test mode
         cout<<"Do you want to continue in the Test mode?? y/n : ";
         cin>>out;           cout<<endl;

         if(out == 'n')
            testMode = false;
    
    }

    cout<<"We are out of Test mode"<<endl<<endl;
    

   
    
    return 0;
}