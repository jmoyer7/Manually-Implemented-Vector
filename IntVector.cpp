/**
 *  Manually implements the functionality of a vector in C++.
 *  @author   Jeremy Moyer CS174
 *  April 15 2020
 */

#include <iostream>
#include "IntVector.h" 
#include <cmath>
#include <string> 
using namespace std;

 /**
 * Increases the size of the internal array by multiplying its size by expansion_factor.
 */ 
void IntVector::expandArray(){

  int* tempArr;   //an array that temporarily stores the values of the array
  
  if(array_size == 0){
    tempArr = new int[1];
    array_size = 1;
  }
  else{
    tempArr = new int[array_size * expansion_factor];
    array_size = array_size * expansion_factor;
  }
  for(int i = 0; i < array_size; i++){
    tempArr[i] = array[i];
  }
  delete[] array;
  array = tempArr;
}



/**
* Adds a user-given value to the end of the array
*
* @param val  a user-given integer to be added to the end of the array.
*/
void IntVector::add(int val){

  

  if(num_elements+1 > array_size){
    expandArray();
    array[num_elements] = val;
  }
  else{
    array[num_elements] = val;
  }
   num_elements++;
}
 /**
 * Removes the element at the user-given index and shifts elements to the left as nessesary
 *
 * @param  index  the location of the value to be removed.
 */
void IntVector::remove(int index){

  for(int i = 0; i < num_elements-index; i++){
    array[index + i] = array[index + i + 1];
  }  
  num_elements = num_elements - 1; 
  }

 /**
 * Returns the value at the given index.
 *
 * @param  index  the array index to be returned.
 */
int IntVector::get(int index) const{
  
    return array[index];
  }

/**
 * Removes element at the end of the array
 */
void IntVector::removeLast(){

  remove(num_elements);
  }

 /**
 * Sets the index at the variable index to be equal to the variable val.
 *
 * @param  index  the location in the array to be changed.
 * @param  val  the value that index is to be changed to.
 */
void IntVector::set(int index, int val){

    array[index] = val;
  }

/**
 * Overrides the toString() method and returns the array as a string.
 */
std::string IntVector::toString()const {

  int counter = 0;  //tracks the number of cyles the below for loop has gone through

  std::string toReturn = "";
  cout << "[";
  for(int i = 0; i < num_elements; i++){
    counter++;
    if(counter != num_elements){
    toReturn += std::to_string(array[i]) += ", ";
    }
    else{
      toReturn += std::to_string(array[i]) += "] ";
    }
  }
    return toReturn;
  }
/**
 * Initalizes the variables that the intvector utilizes and creates the array using the user-given size
 *
 * @param  initial_size  user-defined integer that determines the starting size of the array.
 */  
IntVector::IntVector(int initial_size){
  array = new int[initial_size];
  num_elements = 0;
  array_size = initial_size;
  expansion_factor = 2;
  }


IntVector::IntVector (const IntVector& p2) {
  array = p2.array;
  array_size = p2.array_size;
  num_elements = p2.num_elements;
  expansion_factor = p2.expansion_factor;
  
}



/**
 * Deletes the intvector from memory
 */
IntVector:: ~IntVector(){
}

int main(){
  IntVector v(0);
  IntVector p2(v);

  cout << ("Original Array: ");
  
  v.add(0);
  v.add(1); 
  v.add(2);
  v.add(3);
  v.add(4);
  v.add(5);
  v.add(6);
  v.add(7);
  v.add(8);
  v.add(9);
  v.add(10);
  v.set(0,5);
  v.set(1,1001);
  v.set(2,-1001);
  v.remove(0);
  v.remove(2);
  v.remove(4);
  v.add(27);
  v.remove(2); 
  cout << (v.toString())<<endl;
  

  cout << ("Copied Array: ");
  p2.add(1); 
  p2.add(2);
  p2.add(3);
  p2.remove(2);
  p2.set(0,7);
  cout << (p2.toString())<<endl;

  
}
