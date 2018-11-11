#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>
using namespace std;

struct dogs
{
  int did;
  int age;
};
struct examine
{
  int vid;
  int did;
  int fee;
};

struct vet
{
  int vid;
  int eLevel;
};

struct found{
    int did;
    int age;
    int vid;
    int fee;
    int elevel;

};
int binary_search_dogs(const vector<dogs>& sorted_vec, int key) {
   size_t mid, left = 0 ;
   size_t right = sorted_vec.size(); // one position passed the right end
   while (left < right) {
      mid = left + (right - left)/2;
      if (key > sorted_vec[mid].did){
          left = mid+1;
      }
      else if (key < sorted_vec[mid].did){
        right = mid;
      }
      else {
        return sorted_vec[mid].age;
     }
   }
    return 0;
}

int binary_search_vets(const vector<vet>& sorted_vec, int key) {
   size_t mid, left = 0 ;
   size_t right = sorted_vec.size(); // one position passed the right end
   while (left < right) {
      mid = left + (right - left)/2;
      if (key > sorted_vec[mid].vid){
          left = mid+1;
      }
      else if (key < sorted_vec[mid].vid){
        right = mid;
      }
      else {
        return sorted_vec[mid].eLevel;
     }
   }
 return -1;
}
int binary_search_foundx(const vector<found>& s, int key) {
   size_t mid, left = 0 ;
   size_t right = s.size(); // one position passed the right end
   while (left < right) {
      mid = left + (right - left)/2;
      if (key > s[mid].did){
          left = mid+1;
      }
      else if (key < s[mid].did){
        right = mid;
      }
      else {
        return mid;
     }
   }
 return -1;
}
    bool compare_found(const found &a, const found &b){
        return a.did < b.did;
    }
    bool compare_dogs(const dogs &a, const dogs &b){

        return a.did < b.did;
    }
    bool compare_vets(const vet &a, const vet &b){

        return a.vid < b.vid;
    }

int main()
{
int start_s=clock();
	// the code you wish to time goes here
  vector<dogs> dog;
  vector<examine> examination;
  vector<vet> vets;
  vector<found> foundx;
  vector<int> unique_dogs;
  ifstream DF, EF, VF;
  int value1, value2, value3;





  DF.open("DFile.txt");
  EF.open("EFile.dms");
  VF.open("VFile.dms");

cout << "Collecting data from files....\n" << endl;

 while( DF >> value1 >> value2){

    if (value2 > 8){
    dogs x = {value1, value2};
    dog.push_back(x);
    }

 }
 int count0 = 0;
 sort(dog.begin(), dog.end(), compare_dogs);



  while(VF >> value1 >> value2){

    if(value2 > 0){
    vet x = {value1, value2};
    vets.push_back(x);
    }
 }
sort(vets.begin(), vets.end(), compare_vets);



 while(EF >> value1 >> value2 >> value3){

 int dogAge_Dogs = binary_search_dogs(dog, value2);
 int eLevel_Vets  = binary_search_vets(vets, value1);
  if (dogAge_Dogs > 8 && eLevel_Vets > -1){

        found v = {value2, dogAge_Dogs, value1, value3, eLevel_Vets};
        foundx.push_back(v);
}

     }
    sort(foundx.begin(), foundx.end(), compare_found);

    cout << "Calculating....\n" << endl;


 int unique_dog_1 =0, unique_dog_2 = 0, unique_dog_3 = 0, unique_dog_4 = 0;

    DF.close();
    EF.close();
    VF.close();
    dog.clear();
    vets.clear();


     float q =0, w=0, r =0, z=0;
     float avg_9 = 0, avg_10 = 0, avg_11 = 0, avg_12 = 0;
     for(int i=0; i < foundx.size(); i++){


           if(foundx[i].age== 9 ){
            q = q + foundx[i].elevel;
            unique_dog_1++;
            avg_9 = avg_9 + foundx[i].fee;
            }
           else if (foundx[i].age == 10){
            w = w + foundx[i].elevel;
             unique_dog_2 ++;
            avg_10 = avg_10 + foundx[i].fee;
            }
           else if (foundx[i].age== 11){
            r = r + foundx[i].elevel;
            unique_dog_3++;
            avg_11 = avg_11 + foundx[i].fee;
            }
           else if(foundx[i].age == 12){
             z = z + foundx[i].elevel;
             unique_dog_4++;
             avg_12 = avg_12 + foundx[i].fee;
             }



     }

      cout << "Age Group  " << "Count  " << " AVG Fee   " << "  AVG Elevel" << endl;
      cout << "9          " << unique_dog_1 << "  " << (avg_9 / unique_dog_1)<< "     " << (q / unique_dog_1)<< "  "<<endl;
      cout << "10         " << unique_dog_2 << "  "<< (avg_10 /unique_dog_2)<<  "      " << (w /unique_dog_2)<< "  "<<endl;
      cout << "11         " << unique_dog_3 << "  " << (avg_11 /unique_dog_3)<< "     " << (r /unique_dog_3)<< "  " << endl;
      cout << "12         " << unique_dog_4 << "  "<< (avg_12 / unique_dog_4)<< "     " << (z / unique_dog_4)<< "  "<<endl;


      int stop_s=clock();
      cout << "\n\nExecution time: " << (stop_s-start_s)/double(CLOCKS_PER_SEC) << endl;
  return 0;

}



