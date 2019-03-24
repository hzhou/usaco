/*
 * About 200m
 * 
 * NOT RUNNING
 * 
 * Traveled too far trying to get all possible splits of the figurine, making
 * combinations is always harder than I think :/
 * 
 * Algorithm represents grids as a list of coordinates with the grid being 
 * aligned to the top left. Then generates all combinations that the figurine 
 * could have been split into, aligning and cnverting those, and checking if the
 * parts are equal.
 */
// package bcs;

import java.util.*;
import java.io.*;

public class bcs {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = 4;
        int k = 3;
        char[] figure = "#####..##.##....".toCharArray();
        List<Integer[]> figureCoords = charToCoords(figure, n);
        char[][] grids = {
            ".#...#..##......".toCharArray(),
            "######..#..#####".toCharArray(),
            ".....###.#...#..".toCharArray()
        };
        List<List<Integer[]>> gridCoords = new ArrayList<>();
        for (int i = 0; i < grids.length; i++) {
            gridCoords.add(wrangle(charToCoords(grids[i], n), n));
        }

        int piece1i = -1;
        int piece2i = -1;

        for (int i = 0; i < figureCoords.size() / 2; i++) {
            piece1i = -1;
            piece2i = -1;
            List<List<Integer[]>> allCombos = genCombinations(i, figureCoords.size());
            /* Debug???!!!!!!!!!
            for (List<Integer[]> combo : allCombos) {
                System.out.println(listToStringInArr(combo));
            }
            */
            for (int j = 0; j < gridCoords.size(); j++) {
                for (int w = 0; w < allCombos.size(); w++) {
                    //System.out.println(listToStringInArr(allCombos.get(w)));
                    if (gridCoords.get(j).containsAll(wrangle(allCombos.get(w), n))) {
                        if (piece1i == -1) {
                            piece1i = j;
                        } else if (j != piece1i) {
                            piece2i = j;
                        }
                    }
                }
            }
        }
        System.out.println(piece1i + " " + piece2i);
    }
    
    public static String listToStringInArr(List<Integer[]> list) {
        String result = "[";
        for (Integer[] item : list) {
            result += Arrays.toString(item) + ", ";
        }
        return result + "]";
    }
    
    public static List<List<Integer[]>> genCombinations(int length, int max) {
        List<Integer> usable = new ArrayList<>();
        for (int i = 0; i < max; i++) {
            usable.add(i);
        }
        List<Integer[]> combinations = new ArrayList<>();
        List<Integer[]> matching = new ArrayList<>();
        Integer[] working = new Integer[length];
        for (int i = 0; i < length; i++) {
            working[i] = i;
        }
        combinations.add(working);
        matching.add(getRemaining(working, usable));
        boolean incrementable = true;
        while (incrementable) {
            int index = length - 1;
            while (index >= 0 && working.length - index + length == working[index]) {
                index--;
            }
            if (index < 0) {
                incrementable = false; // for not making me annoyed/readibility
                break;
            }
            working[index]++;
            index++;
            while (index < length) {
                working[index] = working[index - 1] + 1;
                index++;
            }
            combinations.add(working);
            matching.add(getRemaining(working, usable));
        }
        List<List<Integer[]>> finalreturn = new ArrayList<>();
        finalreturn.add(combinations);
        finalreturn.add(matching);
        return finalreturn;
    }

    public static Integer[] getRemaining(Integer[] used, List<Integer> usable) {
        List<Integer> usedList = Arrays.asList(used);
        Integer[] remaining = new Integer[usable.size() - used.length];
        int index = 0;
        for (Integer possible : usable) {
            if (usedList.contains(possible)) {
                remaining[index] = possible;
                index++;
            }
        }
        return remaining;
    }

    public static char[] scanChars(Scanner sc, int n) {
        String string = "";
        for (int i = 0; i < n; i++) {
            string += sc.nextLine();
        }
        return string.toCharArray();
    }

    public static List<Integer[]> charToCoords(char[] grid, int n) {
        List<Integer[]> coords = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i * n + j] == '#') {
                    //y, x format
                    coords.add(new Integer[]{i, j});
                }
            }
        }
        return coords;
    }

    //wrangles a # into 0,0 if possible
    public static char[] wrangle(char[] grid, int n) {
        while (rowIsEmpty(grid, n)) {
            for (int i = 1; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    grid[(i - 1) * n + j] = grid[i * n + j];
                    grid[i * n + j] = '.';
                }
            }
        }
        while (columnIsEmpty(grid, n)) {
            for (int i = 1; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    grid[j * n + (i - 1)] = grid[j * n + i];
                    grid[j * n + i] = '.';
                }
            }
        }
        return grid;
    }

    public static List<Integer[]> wrangle(List<Integer[]> coords, int n) {
        if (!coords.isEmpty()) {
            char[] grid = new char[n * n];
            int coordindex = 0;
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (coords.get(i)[0] == i && coords.get(i)[1] == j) {
                        grid[i * n + j] = '#';
                    } else {
                        grid[i * n + j] = '.';
                    }
                }
            }
            return charToCoords(wrangle(grid, n), n);
        }
        return coords;
    }

    public static boolean rowIsEmpty(char[] grid, int n) {
        boolean empty = true;
        for (int i = 0; i < n; i++) {
            if (grid[i] == '#') {
                empty = false;
            }
        }
        return empty;
    }

    public static boolean columnIsEmpty(char[] grid, int n) {
        boolean empty = true;
        for (int i = 0; i < n; i++) {
            if (grid[i * n] == '#') {
                empty = false;
            }
        }
        return empty;
    }
}
