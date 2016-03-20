import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;

/**
 * Created by huihui on 19/3/16.
 */
class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {

        //Take care of this line
        List<List<String>>anagrams = new ArrayList<List<String>>();
        HashMap<String, Integer>indexes = new HashMap<String, Integer>();

        Arrays.sort(strs);

        for(int i=0; i<strs.length; i++){

            //Convert to base form
            char[] chars = strs[i].toCharArray();
            Arrays.sort(chars);
            String baseString = new String(chars);

            Integer index = indexes.get(baseString);

            if (index == null){
                List<String> newColl = new ArrayList<String>();
                newColl.add(strs[i]);
                anagrams.add(newColl);
                indexes.put(baseString, anagrams.size()-1);
            }
            else{
                anagrams.get(index).add(strs[i]);
            }
        }

        return anagrams;
    }
}