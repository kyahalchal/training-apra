public class Array {
    public static void main(String[] args) {
        int arr[] = {1,2,3,4,5,6,7,8};
        int arrCopy[] = new int[arr.length];

        System.out.println("Old array");
        for (int i : arr) {
            System.out.print(i+" ");
        }

        System.arraycopy(arr, 0, arrCopy, 0, 8); //copying array into another array

        System.out.println("\nNew Array");
        for (int i : arrCopy) {
            System.out.print(i+" ");
        }

        System.out.println("\nCheck if both arrays are equal? ");
        System.out.println(arr==arrCopy);
        
        int arrClone[] = arr.clone();
        
        System.out.println("Check if both arrays (original and clone) are equal? ");
        System.out.println(arr==arrClone);
        
        int[][] arr2d = {{1,2},{3,4},{5,6}};
        int[][] arr2dClone = arr2d.clone();
        
        System.out.println("Check if both 2d arrays (original and clone) are equal? ");
        System.out.println(arr2d==arr2dClone);


    }
}
