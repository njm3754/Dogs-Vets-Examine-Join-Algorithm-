#include <ctime>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int binarySearch(vector<int>&, int);///function to search
 void quickSort(vector<int>&,vector<int>&,  int, int);

int main()
 {
 ifstream dogFile;
 ifstream xamineFile;
 ifstream vetnameFile;

int did,age,vvid,eLevel;
int vid, xdid, fee;
int index = 0;

vector<int> vidArray;
vector<int> vvidArray;
vector<int> fLevelArray;
vector<int> eLevelArray;
vector<int> didArray;
vector<int> idArray; // Vector to store did from Dfile
 vector<int> ageArray; // Vector to store age from Xfile
 vector<int> finalageArray; // Vector to store age info after comparison of did's
 vector<int> feeArray; // Vector to store fee from examine after comparison of did's

clock_t start, stop;

cout << "Reading the file and initializing the join algorithm\n";


    dogFile.open("Dfile.txt");
    xamineFile.open("Efile.dms");
    vetnameFile.open("Vfile.dms");

start=clock();

while (dogFile >> did >> age)
 {
       if(age>8){

        idArray.push_back(did);
        ageArray.push_back(age);
        index++;
                }
}
quickSort(idArray,ageArray,0,1);
int k=0;
while (vetnameFile >> vvid >> eLevel )
 {
       if(eLevel>0){

        vvidArray.push_back(vvid);
        eLevelArray.push_back(eLevel);
        index++;
                }
}
quickSort(vvidArray,eLevelArray,0,1);

int coun = 0;
int val, vall;
while (xamineFile >> vid >> xdid >> fee)
{
     val = binarySearch(idArray, xdid); //  if did of examine is on 'dog'
     vall = binarySearch(vvidArray, vid);
    cout << val << " " << vall << endl;
    if (val != -1 && val != -1) // if did matches, store age and corresponding fee to vectors
    {
    finalageArray.push_back(ageArray[val]);
    feeArray.push_back(fee);
    //vidArray.push_back(vid);
    k++;

    }
}
cout << k << endl;

dogFile.close();
xamineFile.close();
vetnameFile.close();


quickSort(finalageArray,feeArray ,0,k-1);
cout << "\nAge\t"<< "COUNT(*)" <<"AVG(x.fee)\t"<<"eLevel\n";

int n=0;
fee=0;

while (n < k)
 {
 eLevel=eLevelArray[n];
 age = finalageArray[n];
 fee = fee + feeArray[n];

 if (age != finalageArray[n+1])
 {
float average=(float)fee/(float)n;

 cout << age <<"\t"<<n<<"\t"<< average <<"\t\t"<<eLevel<<endl;
 fee = 0;}
n++;

}
// stopping the clock at this time
  stop = clock();
  cout<< "\ntime: "<<(double(stop-start)/CLOCKS_PER_SEC)<<" seconds"<<endl;
      return 0;
}

int binarySearch(vector<int>& V1, int num){

   int mid, first = 0; int last = V1.size();

while (first < last){
        mid = first + (last - first)/2;
        if (num > V1[mid])
          first = mid+1;
        else if (num < V1[mid]) last = mid;
        else return mid;
                    }
          return -1;
      }
 void quickSort(vector<int>& V1,vector<int>& V2,  int left, int right)
{
  int i = left, j = right;
  int tmp;
   int pivot = V1[(left + right) / 2];

  /* partition */
while (i <= j) {
     while (V1[i] < pivot)
         i++;
     while (V1[j] > pivot)
         j--;
      if (i <= j) {
          tmp = V1[i];
          V1[i] = V1[j];
          V1[j] = tmp;

          tmp = V2[i];
          V2[i] = V2[j];
          V2[j] = tmp;


             i++;
            j--;
       }
    };
       /* recursion */
     if (left < j)
         quickSort(V1, V2, left, j);
   if (i < right)
quickSort(V1, V2,i, right);
}

