class BinarySearch 
{ 
    int binarySearch(int arr[], int x) 
    { 
        int l = 0, r = arr.length - 1; 
        while (l <= r) 
        { 
            int m = l + (r-l)/2; 
            if (arr[m] == x) 
                return m;  
            if (arr[m] < x) 
                l = m + 1; 
            else
                r = m - 1; 
        } 
        return -1; 
    } 
    
    public static void main(String args[]) 
    { 
        BinarySearch obj = new BinarySearch(); 
        int arr[] = {2, 3, 4, 10, 12, 24, 53, 64, 65, 94}; 
        int n = arr.length; 
        int x = 12; 
        int result = obj.binarySearch(arr, x); 
        if (result == -1) 
            System.out.println("Element not present"); 
        else
            System.out.println("Element found at " +  
                                   "index " + result); 
    } 
} 

