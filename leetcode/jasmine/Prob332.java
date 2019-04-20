

import java.util.*;

import javafx.util.Pair;
class Prob332 {
    public List<String> findItinerary(String[][] tickets) {
            int air = 0;
            String current = "JFK";
            boolean [] b = new boolean [tickets.length];
            List <String> itinerary = new ArrayList <String> ();
            itinerary.add("JFK");
           // helper (itinerary, "JFK", tickets, b);
        return helper (itinerary, "JFK", tickets, b);
    }
    public List<String> helper (List <String> itinerary, String current, String [][] tickets, boolean [] used)     {
        //System.out.println(itinerary);
        //System.out.println(itinerary.size());
        //System.out.println(tickets.length);
        if (itinerary.size() == tickets.length+1) {
           // System.out.println(itinerary);
            return itinerary;
        }
        PriorityQueue<Pair<String, Integer>> pq = new PriorityQueue<>(new Comparator<Pair<String, Integer>>()           {
            @Override
            public int compare(Pair<String, Integer> p1, Pair<String, Integer> p2) {
                String key1 = p1.getKey();
                String key2 = p2.getKey();
                return key1.compareTo(key2);
            }
        });
        
        for (int i = 0; i < tickets.length; i++) {
            if (used[i] || !tickets[i][0].equals(current)) 
                continue;  
            else {
                pq.add(new Pair (tickets[i][1], i));
            }

        }
        //System.out.println(pq);
        while (!pq.isEmpty()) {
            Pair <String, Integer> p = pq.poll();
            itinerary.add(p.getKey());
            used[p.getValue()] = true;
            List <String> l = helper(itinerary, p.getKey(), tickets, used);
            if (l != null)
                return l;
            
            itinerary.remove(itinerary.size()-1);
            used[p.getValue()] = false;
        }
        return null;
    }
    /*
    public List<String> findItinerary2 (String[][] tickets) {
            int air = 0;
            String current = "JFK";
            boolean [] b = new boolean [tickets.length];
            List <String> itinerary = new ArrayList <String> ();
            itinerary.add("JFK");
            while (air < tickets.length) {
                String next = "";
                int nextIn = 0;
                for (int i = 0; i < tickets.length; i++) {
                    if (b[i] || !tickets[i][0].equals(current)) 
                        continue;  
                    else if (next == "" || next.compareTo(tickets[i][1]) > 0) {
                        next = tickets[i][1];
                        nextIn = i;
                    }
                   
                }
                itinerary.add(tickets[nextIn][1]);
                current = tickets[nextIn][1];
                b[nextIn] = true;
                air++;
                
            }
        return itinerary; 
    }
    */
}