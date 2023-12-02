import java.time.*;
import java.util.*;
class SelectionSort{
    Random rand = new Random();
    int arr[]=new int[10];
    void sort(){
        int min,n =10;

        //input of array elements
        for(int i=0;i<n;i++){
            arr[i]=rand.nextInt(100);
        }

        //unsorted array
        for(int i=0;i<n;i++){
            System.out.print(arr[i]+" ");
        }
        System.out.println("");

        //sorting of array
        for(int i=0;i<n-2;i++){
            min=i;
            for(int j=i+1;j<n;j++){
                if(arr[j]<arr[min]){
                    min=j;
                }
            }
            int temp=arr[i];
            arr[i]=arr[min];
            arr[min]=temp;
        }

        //sorted array
        for(int i=0;i<n;i++){
            System.out.print(arr[i]+" ");
        }

    }
    public static void main(String args[]){
      SelectionSort obj = new SelectionSort();
      long start1 = System.nanoTime();
      obj.sort();
      long end1 = System.nanoTime();      
      System.out.println("Elapsed Time in nano seconds: "+ (end1-start1));      
      long start2 = System.currentTimeMillis();
      obj.sort();
      long end2 = System.currentTimeMillis();      
      System.out.println("Elapsed Time in milli seconds: "+ (end2-start2));
       
    }
}
