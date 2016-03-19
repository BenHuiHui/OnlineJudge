import java.util.ArrayList;
import java.util.List;

/**
 * Created by huihui on 19/3/16.
 */
public class P057_InsertInterval {

    public List<Interval> insert(List<Interval> intervals, Interval newInterval) {

        if (intervals.size() <= 0){
            intervals.add(newInterval);
            return intervals;
        }

        int start = 0, end = intervals.size()-1;

//Get insertion point
        while(start <= end){
            int mid = start + (end - start)/2;

            if(intervals.get(mid).end < newInterval.start)
                start = mid+1;
            else
                end = mid-1;
        }

        //start is intersection point
        if (start>=intervals.size() || notHasIntersection(intervals.get(start), newInterval)){
            intervals.add(start, newInterval);
        }
        else{
            Interval curr = intervals.get(start);
            curr.start = curr.start < newInterval.start ? curr.start : newInterval.start;
            curr.end = curr.end > newInterval.end ? curr.end : newInterval.end;

            //Merge subsequent intervals
            int index = start+1;
            while(index < intervals.size()){
                Interval endInterval = intervals.get(index);
                if (curr.end < endInterval.start) break;
                //Merge
                curr.end = curr.end > endInterval.end ? curr.end : endInterval.end;
                index++;
            }
            intervals.set(start, curr);

            //Copy the remaining
            for(int i=index; i<intervals.size(); i++){
                intervals.set(start+1-index+i, intervals.get(i));
            }

            //Remove the redundant
            intervals = intervals.subList(0, intervals.size() - (index - start)+1);
        }
        return intervals;
    }

    boolean notHasIntersection(Interval interval1, Interval interval2){
        return interval1.end < interval2.start || interval2.end < interval1.start;
    }

    public static void main(String[] args){
        P057_InsertInterval p = new P057_InsertInterval();
        ArrayList<Interval> inter = new ArrayList<Interval>();


        inter.add(new Interval(1, 5));
        /*
        inter.add(new Interval(3, 5));
        inter.add(new Interval(6, 7));
        inter.add(new Interval(8, 10));
        inter.add(new Interval(12, 16));
        */

        Interval newInterval = new Interval(0, 0);
        List<Interval> resutls = p.insert(inter, newInterval);

        for (int i = 0; i < resutls.size(); i++) {
            System.out.println(resutls.get(i).start+" "+resutls.get(i).end);
        }

    }

}
