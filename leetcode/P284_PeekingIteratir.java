import java.util.Iterator;
import java.util.Stack;

/**
 * Created by huihui on 29/2/16.
 */

class PeekingIterator implements Iterator<Integer> {

    private Integer next;
    private Iterator<Integer> iterator;

    public PeekingIterator(Iterator<Integer> iterator) {
        // initialize any member here.
        this.iterator = iterator;
        next = this.iterator.next();
    }

    // Returns the next element in the iteration without advancing the iterator.
    public Integer peek() {
        return next;
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    @Override
    public Integer next() {
        Integer val = next;
        if (this.iterator.hasNext())
            next = this.iterator.next();
        else
            next = null;
        return val;
    }

    @Override
    public boolean hasNext() {
        return this.iterator.hasNext() || next != null;
    }
}