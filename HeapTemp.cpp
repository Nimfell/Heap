
#include <stdio.h>

class Heap
{
  public:
    int* HeapArray; 
    int  size; 
		
    Heap() { HeapArray = NULL; }

    void MakeHeap(int* a, int depth)
    {
      size = (two_to_the_degree(depth + 1) - 1); // save heap size      
      for (int i = 0; i < size; i++) 
         Add(a[i]);                              // fill heap array by incoming array                                  
    }
	 
    int GetMax()  // get MAX and rebuild
    {
	   if (HeapArray == NULL)
	      return -1; // if heao is empty
      else
      {
         int max_item = HeapArray[0];
         for (int i = size-1; i >= 0 ; i--) // passing the array from 2nd item
            if (HeapArray[i] >= 0)
            {
               HeapArray[0] = HeapArray[i];
               HeapArray[i] = -1;
               break;
            }
         sifting_down(0);
         return max_item;
      }
    }

    bool Add(int key)
    {       
      if (HeapArray == NULL)
      {
         HeapArray = new int[size];  // create heap array
         HeapArray[0] = key;
         for (int i = 1; i < size; i++) 
            HeapArray[i] = -1;
         return true;
      }
      else
      {
         for (int i = 0; i < size ; i++) // passing the array from 2nd item
         {
            if (HeapArray[i] < 0)
            {
               HeapArray[i] = key; // add new item "key" to the heap
               sifting_up(i);    // rebuild the heap
               return true;
            }
         }
      }
      return false;
    } 

    static int two_to_the_degree(int D) 
    {  
       if (D == 0) 
          return 1;
       return (2 * two_to_the_degree(D-1));  
    }

  private:
    void sifting_down(int i)
    { 
      int* a = HeapArray;

      int tmp = a[i];       // Copy
      while (i <= size/2)   // the imem is not a list
      {
          int child = 2*i+1;  // left child
         
          if ( a[child] < a[child + 1] ) // choose max child
              child++; 
         
          if (tmp >= a[child]) 
             break; 
          
          a[i] = a[child]; // change 
          i = child;       // remember
      }     
      a[i] = tmp; // At the end, we restore the sifted element to its original value.
    }

    void sifting_up(int i)
    {
      int* a = HeapArray;

      int tmp = a[i];    
      while (i != 0)     // while have not reached the root
      {
          int parent = (i-1)/2;   
         
          if (tmp < a[parent]) break; 
          
          a[i] = a[parent]; 
          i = parent;
      }     
      a[i] = tmp; 
    }      
};

int test() 
{
   int test = 0;
   Heap heap;
   int arr[7] = {0,1,2,3,4,-3,-2};
   int* new_array = &arr[0];
   heap.MakeHeap(new_array, 2);

   if (heap.GetMax() != 4) test++;
   if (heap.Add(9) != true) test++;  
   if (heap.Add(7) != true) test++;

   if (heap.GetMax() != 9) test++;

   if (heap.Add(10) != true) test++;
   if (heap.Add(11) != true) test++;
   if (heap.Add(12) != false) test++;

   if (heap.GetMax() != 11) test++;
   if (heap.GetMax() != 10) test++;
   if (heap.GetMax() != 7) test++;
   if (heap.GetMax() != 3) test++;
   if (heap.GetMax() != 2) test++;
   if (heap.GetMax() != 1) test++;
   if (heap.GetMax() != 0) test++;
   if (heap.GetMax() != -1) test++;

   if (heap.Add(10) != true) test++;
   if (heap.Add(7) != true) test++;

   if (heap.GetMax() != 10) test++;
   if (heap.GetMax() != 7) test++;
   if (heap.GetMax() != -1) test++;   
}

