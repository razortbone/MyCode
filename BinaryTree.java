import java.util.Stack;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Map;
import java.util.HashMap;
//import javafx.util.Pair; 
class Node
{
    int data;
    Node left;
    Node right;
    Node (int d)
    {
        data = d;
        left = right = null;
    }
}
class btree
{
   Node root;

   int sum (Node t)
   {
     if (t == null)
     return 0;

     return (t.data+sum(t.left)+sum(t.right));

   }
   boolean isLeaf(Node t)
   {
       if(t == null)
        return false;

       return (t.left == null && t.right == null); 
   }
   void printStartEndNodesOfLevel(Node t)
   {
        System.out.println(" Start and End Nodes are :");
        if (t==null) return;
        Node dummy = new Node(-555);
        Queue<Node> Q = new LinkedList<Node>();
        Q.add(t);
        Q.add(dummy);
        while (!Q.isEmpty())
        {
            Node temp = Q.peek();
            Q.remove();
            if (temp == dummy)
            {
                if (!Q.isEmpty())
                {
                    System.out.print(Q.peek().data+"->");
                    Q.add(dummy);
                }
            }
            else
            {
                //System.out.print(temp.data+" ");
                if(Q.peek()==dummy)
                System.out.println(temp.data);
                if(temp.left != null)
                    Q.add(temp.left);
                if(temp.right != null)
                    Q.add(temp.right);
            }
        }
        System.out.println();
   }

   void printRightView(Node t)
   {
        System.out.println(" Right View Of Tree :");
        if (t==null) return;
        Node dummy = new Node(-555);
        Map<Node,Integer> m = new HashMap<Node,Integer> ();
        Queue< Map<Node,Integer> > Q = new LinkedList< Map<Node,Integer> >();
        m.put(t,0);
        Q.add(m);
        while (!Q.isEmpty())
        {
            Map<Node,Integer> temp = Q.peek();
            Q.remove();

           /* else
            {
                //System.out.print(temp.data+" ");
                if(Q.peek()==dummy)
                System.out.println(temp.data);
                if(temp.left != null)
                    Q.add(temp.left);
                if(temp.right != null)
                    Q.add(temp.right);
            }*/
        }
        System.out.println();
   }
   void levelOrder(Node t)
   {
        System.out.println(" Level Order :");
        if (t==null) return;
        Queue<Node> Q = new LinkedList<Node>();
        Q.add(t);
        while (!Q.isEmpty())
        {
            Node temp = Q.peek();
            Q.remove();
            System.out.print(temp.data+" ");
            if(temp.left != null)
            Q.add(temp.left);
            if(temp.right != null)
            Q.add(temp.right);
        }
        System.out.println();
   }
   boolean isSumTree(Node t)
   {
        if(t == null || (t.left == null && t.right == null))
         return true;

         int lval = 0;
         int rval = 0;

        if (isSumTree(t.left) && isSumTree(t.right))
        {
            if(t.left == null )
            lval = 0;
            else if(isLeaf(t.left))
            lval = t.left.data;
            else
            lval = 2 * (t.left.data);
                
            if(t.right == null )
            rval = 0;
            else if(isLeaf(t.right))
            rval = t.right.data;
            else
            rval = 2 * (t.right.data);
            
            System.out.println(lval + " -> " +rval+ " -> "+t.data);
            return (t.data == lval + rval);
        } 
        return false;
   }
   int convertSumTree(Node t)
   {
    if (t == null) return 0; 
    int val = t.data;
    t.data = convertSumTree(t.left)+convertSumTree(t.right);
    return val; 
   }
   boolean isChildSumTree(Node t)
   {
      if(t == null || (t.left == null && t.right == null))
       return true;
     
      int lval = 0;
      int rval = 0;
      if (t.left != null)
      {
          lval = t.left.data;
      }
      if(t.right != null)
      {
          rval = t.right.data;
      }
      if ((t.data == (rval + lval)) && isChildSumTree(t.left) && isChildSumTree(t.right))
      return true;

      return false;
   }
   void modifychild (Node t, int val)
   { 
      if (t == null) return ;
      if (t.left != null)
      {
          t.left.data = t.left.data+ val;
          modifychild(t.left,val);
      }
      else if (t.right != null)
      {
          t.right.data = t.right.data + val;
          modifychild(t.right,val); 
      }

   }

   void convertChildSumTree(Node t)
   {
      if (t == null || (t.left==null && t.right == null))
       return ;
      
       convertChildSumTree(t.left);
       convertChildSumTree(t.right);
       int lval = 0;
       int rval = 0;
       if (t.left != null) 
        lval = t.left.data;
       if (t.right != null)
        rval = t.right.data;
       int diff = lval+rval-t.data;
       if (diff > 0)
       {
            t.data = t.data + diff;
       } 
       else if(diff < 0)
       {
            modifychild(t,-1*diff);
       }
   }

   void iterativePreorder(Node t)
   {
        if (t == null) return;  
        System.out.println(" Preorder is :");
        Stack<Node> S = new Stack<Node>();
        S.push(t);
        while (!S.isEmpty())
        {
            Node temp = S.peek();
            S.pop();
            System.out.print(temp.data+" ");
            if (temp.right != null)
            S.push(temp.right);
            if(temp.left != null)
            S.push(temp.left);

        }
        System.out.println();
   }


   void printPathUtil(Node t, int arr[],int len,String str)
   {
       if (t == null) return ;
       //arr[len++] = t.data;
       str = str + String.valueOf(t.data)+" ";
       if(t.left == null && t.right == null)
       {
           /*for(int i = 0;i<len;i++)
           {
               System.out.print(arr[i]+" ");
           }*/
           System.out.println(str);
           System.out.println();
       }
       printPathUtil(t.left,arr,len,str);
       printPathUtil(t.right,arr,len,str);
   }
   void printPath()
   {
       System.out.println(" Paths in tree :");
        int arr[] = new int[100];
        String str="";
       printPathUtil(root,arr,0,str);
   }

   

}
class BinaryTree 
{
   public static void main(String args[]) { 
   /* btree tree = new btree(); 
    tree.root = new Node(10); 
    tree.root.left = new Node(8); 
    tree.root.right = new Node(2); 
    tree.root.left.left = new Node(3); 
    tree.root.left.right = new Node(5); 
    tree.root.right.left = new Node(2); 
    tree.iterativePreorder(tree.root); 
    tree.printPath();*/

    btree tree = new btree(); 
    tree.root = new Node(50); 
    tree.root.left = new Node(7); 
    tree.root.right = new Node(2); 
    tree.root.left.left = new Node(3); 
    tree.root.left.right = new Node(5); 
    tree.root.right.left = new Node(1); 
    tree.root.right.right = new Node(30); 
    tree.iterativePreorder(tree.root);
    tree.printPath();
    System.out.println(" Is Tree adhering Child Sum Property : "+ tree.isChildSumTree(tree.root));
    tree.convertChildSumTree(tree.root);
    tree.iterativePreorder(tree.root);
    System.out.println(" Is Tree adhering Child Sum Property : "+ tree.isChildSumTree(tree.root));
    /*System.out.println(" Is Tree adhering Sum Tree Property : "+ tree.isSumTree(tree.root));
    tree.convertSumTree(tree.root);
    tree.iterativePreorder(tree.root);
    tree.printPath();
    System.out.println(" Is Tree adhering Sum Tree Property : "+ tree.isSumTree(tree.root));
    */
    tree.printRightView(tree.root);

    }

}
