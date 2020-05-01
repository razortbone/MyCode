import java.util.*;

public class abc
{
public static void main (String Args[])
{
//    System.out.println("Hello World");
 List<Integer> lis = new ArrayList<Integer>(Arrays.asList(new Integer[]{1,2,3,4}));
 List<Integer> lis2 = new ArrayList<Integer>(Arrays.asList(new Integer[]{2,4,6,8}));
 System.out.println(lis);
 System.out.println(lis2);
 Set<Integer> un = new HashSet<Integer> (lis);
 un.addAll(lis2);
 System.out.println(un);
 Set<Integer> in = new HashSet<Integer> (un);
 in.retainAll(lis2);
 in.retainAll(lis);
 System.out.println(in);
 un.retainAll(lis2);
 System.out.println(un);
}

};