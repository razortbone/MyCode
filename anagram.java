import java.util.*;

 class anagram
 {
    public static void printAnagramsTogether2(String arr[],int N)
    {
       Map<HashMap<Character,Integer>,List<String> > m = new HashMap< HashMap<Character,Integer>,List<String> > ();
       for(int i = 0;i <N;i++)
       {
           String y = (arr[i]);
           HashMap<Character,Integer> temp = new HashMap<Character,Integer>();
           for(int j = 0;j<y.length();j++)
           {
               if(temp.containsKey(y.charAt(j)))
               temp.put(y.charAt(j),temp.get(y.charAt(j))+1);
               else
               temp.put(y.charAt(j),1);
            }
          // char x[] = (y.toCharArray());
           //Arrays.sort(x);
           //String temp = new String(x);
           System.out.println(temp);
           if(m.containsKey(temp))
           m.get(temp).add(arr[i]);
           else
           {
               List<String> wlist = new ArrayList<String> ();
               wlist.add(arr[i]);
               m.put(temp,wlist);
           }
       }
       for(HashMap<Character,Integer> temp : m.keySet())
       {
          System.out.print(temp+":");
          System.out.println(m.get(temp));
       } 
       
    }
   public static void printAnagramsTogether(String arr[],int N)
   {
      Map<String,List<String> > m = new HashMap<String,List<String> > ();
      for(int i = 0;i <N;i++)
      {
          String y = (arr[i]);
          char x[] = (y.toCharArray());
          Arrays.sort(x);
          String temp = new String(x);
          System.out.println(temp);
          if(m.containsKey(temp))
          m.get(temp).add(arr[i]);
          else
          {
              List<String> wlist = new ArrayList<String> ();
              wlist.add(arr[i]);
              m.put(temp,wlist);
          }
      }
      for(String temp : m.keySet())
      {
         System.out.print(temp+":");
         System.out.println(m.get(temp));
      } 
   }
   public static void main(String args[]) 
    { 
        String wordArr[] = { "cat", "dog", "tac", "god", "act" }; 
        int size = wordArr.length; 
        printAnagramsTogether2(wordArr, size); 
    } 
 }
