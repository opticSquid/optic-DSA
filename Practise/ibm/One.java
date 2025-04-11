package Practise.ibm;

import java.util.List;
import java.util.stream.Collectors;

public class One {

    /*
     * Complete the 'optimizeServers' function below.
     *
     * The function is expected to return an INTEGER.
     * The function accepts following parameters:
     * 1. INTEGER_ARRAY power
     * 2. INTEGER_ARRAY cost
     */
    // Upper bound: index of first element > target
    private static int upperBound(int[] arr, int target) {
        int low = 0, high = arr.length;
        while (low < high) {
            int mid = (low + high) >>> 1;
            if (arr[mid] <= target)
                low = mid + 1;
            else
                high = mid;
        }
        return low;
    }

    public static List<Long> countMinimumOperations(List<Integer> distance, List<Integer> targetDistance) {
        int n = distance.size();

        // Sort the distance array
        int[] sorted = distance.stream().mapToInt(Integer::intValue).sorted().toArray();

        // Compute prefix sums
        long[] prefixSum = new long[n + 1]; // prefixSum[0] = 0
        for (int i = 0; i < n; i++) {
            prefixSum[i + 1] = prefixSum[i] + sorted[i];
        }

        // Binary search + prefix sum for each target
        return targetDistance.parallelStream()
                .map(target -> {
                    // Find index of first element > target (upper bound)
                    int idx = upperBound(sorted, target);

                    long leftSum = (long) target * idx - prefixSum[idx];
                    long rightSum = (prefixSum[n] - prefixSum[idx]) - (long) target * (n - idx);
                    return leftSum + rightSum;
                })
                .collect(Collectors.toList());
    }

    public static void main(String[] args) {
        List<Integer> d = List.of(50, 55, 60);
        List<Integer> t = List.of(60, 55, 50, 65);
        System.out.println(countMinimumOperations(d, t));
    }

}
