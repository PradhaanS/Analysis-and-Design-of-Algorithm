import java.util.Random;

class QuickSort
{
    Random rand = new Random();
    int arr[]=new int[100];
    int n =100;

	int partition(int arr[], int low, int high)
	{
        
		int pivot = arr[high]; 
		int i = (low-1); // index of smaller element
		for (int j=low; j<high; j++)
		{
			// If current element is smaller than or
			// equal to pivot
			if (arr[j] <= pivot)
			{
				i++;

				// swap arr[i] and arr[j]
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}

		// swap arr[i+1] and arr[high] (or pivot)
		int temp = arr[i+1];
		arr[i+1] = arr[high];
		arr[high] = temp;

		return i+1;
	}

	void sort(int arr[], int low, int high)
	{
		if (low < high)
		{
			/* pi is partitioning index, arr[pi] is 
			now at right place */
			int pi = partition(arr, low, high);

			// Recursively sort elements before
			// partition and after partition
			sort(arr, low, pi-1);
			sort(arr, pi+1, high);
		}
	}

	static void printArray(int arr[])
	{
		int n = arr.length;
		for (int i=0; i<n; ++i)
			System.out.print(arr[i]+" ");
		System.out.println();
	}
	public static void main(String args[])
	{
        Random rand = new Random();
        int arr[]=new int[100];
        int n =100;
        for(int i=0;i<n;i++){
            arr[i]=rand.nextInt(100);
        }
        System.out.println("UNSORTED ARRAY:");
        for(int i=0;i<n;i++){
            System.out.print(arr[i]+" ");
        }
        System.out.println("");

        QuickSort ob = new QuickSort();
        long start1 = System.nanoTime();
	ob.sort(arr, 0, n-1);
        System.out.println("SORTED ARRAY");
	printArray(arr);
        long end1 = System.nanoTime();
        System.out.println("Elapsed Time in nano seconds: "+ (end1-start1));
        long start2 = System.currentTimeMillis();
        ob.sort(arr, 0, n-1);
        System.out.println("SORTED ARRAY");
	printArray(arr);
        long end2 = System.currentTimeMillis();
        System.out.println("Elapsed Time in milli seconds: "+ (end2-start2));
	}
}

