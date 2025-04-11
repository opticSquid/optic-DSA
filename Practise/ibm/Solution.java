package Practise.ibm;

import java.util.*;

class Solution {
    public int getMinTuningOperations(int[] queryTimes) {
        int operations = 0;
        Set<Integer> loookup = new TreeSet<>(Comparator.reverseOrder());
        for (int time : queryTimes) {
            if (time % 2 == 0) {
                loookup.add(time);
            }
        }
        while (!loookup.isEmpty()) {
            int node = loookup.iterator().next();
            loookup.remove(node);
            if (node % 2 == 0) {
                loookup.add(node / 2);
                operations++;
            }
        }
        return operations;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] queryTimes1 = { 2, 6, 8, 16 };
        System.out.println("Minimum operations for [2, 6, 8, 16]: " + sol.getMinTuningOperations(queryTimes1));
    }
}