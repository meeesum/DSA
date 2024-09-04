#include<iostream>
using namespace std;
class Person{
    public:
    int age;
    string name;
    Person(int age, std::string name){
        this->age = age;
        this->name = name;
    }
};
// void quickSort(int arr[], int len, int mid);
void sortObjects(Person arr[], int len);
void insertionSort(int arr[], int len);
void selectionSort(int arr[], int len);
void bubbleSort(int arr[], int len);
int main(){
    int arr[] = {7,2,8,4,1,9,3,6,5};
    int len = sizeof(arr)/sizeof(arr[0]);
    int mid = len/2;
    bubbleSort(arr, len);

    
    for(int i = 0; i < len; i++){
        cout << arr[i] << " ";
    }

    // Person p1(24, "Aftab");
    // Person p4(21, "Hassan");
    // Person p2(25, "Ali");
    // Person p3(21, "Meesum");
    // Person p5(22, "Talha");

    // Person arr2[] = {p1, p2, p3, p4, p5};
    // int len2 = sizeof(arr2)/sizeof(arr2[0]);
    // sortObjects(arr2, len2);

    // for(int i = 0; i < len2; i++){
    //     cout << arr2[i].age << " " << arr2[i].name << endl;
    // }
    return 0;
}
// void quickSort(int arr[], int len, int mid){
//     int pivot = arr[mid];
//     int * arr2 = new int [len];
//     int i = 0;
//     int left = 0;
//     int right = mid+1;
    
    
// }
void insertionSort(int arr[] , int len){
    for(int i = 1; i < len; i++){
        int j = 0;
        while(j < i){
            if(arr[i] < arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
            j++;
        }
    }
}
void selectionSort(int arr[], int len){
    for(int i = 0; i < len; i++){
        int min = i;
        for(int j = i+1; j < len; j++){
            if(arr[j] < arr[min]){
                int temp = arr[j];
                arr[j] = arr[min];
                arr[min] = temp;
            }
        }
    }
}
void bubbleSort(int arr[], int len){
    for(int i = 0; i < len; i++){
        for(int j = 0; j < len; j++){
            if(arr[i] < arr[j]){
                int temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}
void sortObjects(Person arr[], int len){
for(int i = 0; i < len; i++){
    for(int j = 0; j < len; j++){
        if(arr[i].age < arr[j].age){
            Person temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        else if(arr[i].age == arr[j].age){
            if(arr[i].name > arr[j].name){
                Person temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}
}