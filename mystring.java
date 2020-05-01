import java.util.HashMap;
import java.util.Map;
import java.lang.Math;

class mystring
{
    String findLongestSubstring(String str)
    {
        Map<Character,Integer> m = new HashMap<Character,Integer>();
        int st = 0;
        int end = 0;
        int len = -1;
        String res="";
        for(int i = 0;i<str.length();i++)
        {
           if (m.containsKey(str.charAt(i)))
           {
            if(m.get(str.charAt(i))>=st) 
            st = m.get(str.charAt(i))+1;
            m.put(str.charAt(i),i);
                
           }
           else
           {
               m.put(str.charAt(i),i);
           }
           if((i-st+1)>len)
           {
               System.out.println(m);
               
               len = i -st+1;
               res = str.substring(st,i+1);
              
               System.out.println(" len = "+len+" and st = "+st+" and i = "+i);
               System.out.println("   res = "+res);
              
           } 
             

        }
        return res;
    }

    public static void main(String args[])
    {
        mystring t = new mystring();
        String str = "GEEKSFORGEEKS"; 
        System.out.println(" Longest non repeating substring "+ t.findLongestSubstring(str)); 

    }
}
