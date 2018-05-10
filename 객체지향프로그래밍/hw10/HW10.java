import java.util.*;
 
abstract class HuffmanTree implements Comparable<HuffmanTree> {
	public final int frequency; // the frequency of this tree
    public HuffmanTree(int freq) { frequency = freq; }
 
    // compares on the frequency
    public int compareTo(HuffmanTree tree) {
        return frequency - tree.frequency;
    }
}
 
class HuffmanLeaf extends HuffmanTree {
    public final char value; // the character this leaf represents
 
    public HuffmanLeaf(int freq, char val) {
        super(freq);
        value = val;
    }
}
 
class HuffmanNode extends HuffmanTree {
    public final HuffmanTree left, right; // subtrees
 
    public HuffmanNode(HuffmanTree l, HuffmanTree r) {
        super(l.frequency + r.frequency);
        left = l;
        right = r;
    }
}
 
public class HW10 {
		
    // input is an array of frequencies, indexed by character code
	// first, build priority queue. Then, from the queue, build Huffman Tree.
    public static HuffmanTree buildTree(int[] charFreqs) {
        // (Lab10-1)
    	PriorityQueue<HuffmanTree> t = new PriorityQueue<HuffmanTree>();
        for(int i=0; i<charFreqs.length; i++){
        	if(charFreqs[i]==0) continue;
        	else
        		t.offer(new HuffmanLeaf(charFreqs[i], (char)i));
        }
        while(t.size()>1)
        	t.offer(new HuffmanNode(t.poll(), t.poll()));

        return t.poll();
    }
 
    public static void printCodes(HuffmanTree tree, StringBuffer prefix, StringBuffer[] code) {
    	
        // (Lab10-2)
    	StringBuffer prefixLeft =  new StringBuffer();
    	StringBuffer prefixRight =  new StringBuffer();
    	if (tree instanceof HuffmanNode){
    		prefixLeft = prefix.append('0');
    		printCodes(((HuffmanNode) tree).left, prefixLeft, code);
    		prefix.setLength(prefix.length()-1);

    		prefixRight = prefix.append('1');
    		printCodes(((HuffmanNode) tree).right, prefixRight, code);
    		prefix.setLength(prefix.length()-1);
    	}
    	else {
    			code[((HuffmanLeaf)tree).value].append(prefix);
    			System.out.println(((HuffmanLeaf)tree).value + "\t" +tree.frequency + "\t" + code[((HuffmanLeaf)tree).value]);
    		}
    }
 
    public static void encode(String str, StringBuffer codeStr, StringBuffer[] code) {
    	
    // (HW10-1)
        for (int i=0; i<str.length(); i++)
            codeStr.append(code[(str.charAt(i))]);
        
    }
 
    public static void decode(HuffmanTree tree, StringBuffer codeStr, StringBuffer decodeStr) {

    // (HW10-2)
    	HuffmanTree temptree = tree;
    	for(int i=0; i<codeStr.length();){
    	if(temptree instanceof HuffmanNode) {
    		while (temptree instanceof HuffmanNode){
    			if(codeStr.charAt(i) == '0')
        			temptree = ((HuffmanNode)temptree).left;
        		else if(codeStr.charAt(i) == '1')
        			temptree = ((HuffmanNode)temptree).right;
        		i++;
    		}
    		if (temptree instanceof HuffmanLeaf)
    			decodeStr.append(((HuffmanLeaf) temptree).value);
    			temptree = tree;
    		}
    		if(i==(codeStr.length()-1))
    			decodeStr.append(((HuffmanLeaf) temptree).value);
    	}
    }
    public static void main(String[] args) {
        String test = "this is an example for huffman encoding";
   	    StringBuffer[] code = new  StringBuffer[256];
        StringBuffer codeStr = new StringBuffer();
        StringBuffer decodeStr = new StringBuffer();
        for(int i=0; i<256; i++) code[i] = new StringBuffer();
        
        // we will assume that all our characters will have
        // code less than 256, for simplicity
        int[] charFreqs = new int[256];
        // read each character and record the frequencies
        for (char c : test.toCharArray())
            charFreqs[c]++;

        // build tree
        HuffmanTree tree = buildTree(charFreqs);
 
        // print out results
        System.out.println("SYMBOL\tWEIGHT\tHUFFMAN CODE");
        printCodes(tree, new StringBuffer(), code);

        System.out.println("original:(" + test.length() + "bytes) "+ test);
        encode(test, codeStr, code);
        System.out.println("encoded: (" + codeStr.length() + "bits,compression-ratio=" + codeStr.length()/(8.0*test.length()) + ") " + codeStr);
        decode(tree, codeStr, decodeStr);
        System.out.println("decoded: (" + decodeStr.length() + "bytes) " + decodeStr);       
    }
    
/* (correct result)

SYMBOL	WEIGHT	HUFFMAN CODE
d	1	00000
t	1	00001
h	2	0001
s	2	0010
c	1	00110
x	1	00111
m	2	0100
o	2	0101
n	4	011
u	1	10000
l	1	10001
a	3	1001
r	1	10100
g	1	101010
p	1	101011
e	3	1011
i	3	1100
f	3	1101
 	6	111
original:(39bytes) this is an example for huffman encoding
encoded: (0bits,compression-ratio=0.0) 
decoded: (0bytes) 

 */
}