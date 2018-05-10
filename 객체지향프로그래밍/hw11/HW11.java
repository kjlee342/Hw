import java.util.*;
import java.io.*;

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
 
public class HW11 {
		
    // input is an array of frequencies, indexed by character code
    public static HuffmanTree buildTree(int[] charFreqs) {
        PriorityQueue<HuffmanTree> trees = new PriorityQueue<HuffmanTree>();
        // initially, we have a forest of leaves
        // one for each non-empty character
        for (int i = 0; i < charFreqs.length; i++)
            if (charFreqs[i] > 0)
                trees.offer(new HuffmanLeaf(charFreqs[i], (char)i));
 
        assert trees.size() > 0;
        // loop until there is only one tree left
        while (trees.size() > 1) {
            // two trees with least frequency
            HuffmanTree a = trees.poll();
            HuffmanTree b = trees.poll();
 
            // put into new node and re-insert into queue
            trees.offer(new HuffmanNode(a, b));
        }
        return trees.poll();
    }
 
    public static void printCodes(HuffmanTree tree, StringBuffer prefix, StringBuffer[] code) {
        assert tree != null;
        if (tree instanceof HuffmanLeaf) {
            HuffmanLeaf leaf = (HuffmanLeaf)tree;
            
            code[leaf.value].append(prefix);
 
            // print out character, frequency, and code for this leaf (which is just the prefix)
            System.out.println(leaf.value + "\t" + leaf.frequency + "\t" + prefix);
 
        } else if (tree instanceof HuffmanNode) {
            HuffmanNode node = (HuffmanNode)tree;
 
            // traverse left
            prefix.append('0');
            printCodes(node.left, prefix, code);
            prefix.deleteCharAt(prefix.length()-1);
 
            // traverse right
            prefix.append('1');
            printCodes(node.right, prefix, code);
            prefix.deleteCharAt(prefix.length()-1);
        }
    }

    public static void saveMetaFile(DataOutputStream denc, String orgfile, int filelength, int[] freqs) {
    	
		try {
			denc.writeChars(orgfile + "\n");
			denc.writeInt(filelength);
			for(int i=0; i<256; i++) denc.writeInt(freqs[i]);    
		} catch (IOException e) {
		System.out.println("스트림 오류");
		}		
		
    }
    
    public static int restoreMetaFile(DataInputStream denci, int[] charFreqs, String[] fileNames) {
		StringBuffer temp = new StringBuffer("");
		String fname;
    	char c;
    	int filelength = -1;
    	
		try {
				while((c = denci.readChar()) != '\n'){
					temp.append(c);
				}
			fileNames[0] = temp.toString();
			fname = temp.substring(0, temp.indexOf("."));
			fileNames[1] = new String(fname + "_unc" + temp.substring(temp.indexOf("."), temp.length()));
			
			filelength = denci.readInt();
			
			for(int i=0; i<256; i++)
				charFreqs[i] = denci.readInt();
				
// HW11-1			
			
		} catch (IOException e) {
			System.out.println("스트림 오류");
		}
		return filelength;
    }

    public static void encode(DataInputStream str, DataOutputStream codeStr, StringBuffer[] code) {
        int b;
		try {
			while((b=str.read()) != -1)
				codeStr.writeBytes(code[b].toString());
		} catch (IOException e) {
			System.out.println("스트림 오류");
		}
    }

    public static void decode(HuffmanTree tree, DataInputStream codeStr, DataOutputStream decodeStr) {
        assert tree != null;
        HuffmanTree btree = tree;
        int b;
		try {
			while((b=codeStr.read()) != -1)
	        {
	            HuffmanNode node = (HuffmanNode)btree;
	            if (b == '0') btree = node.left;
	            else btree = node.right;
	            if (btree instanceof HuffmanLeaf) {
	                HuffmanLeaf leaf = (HuffmanLeaf)btree;
	                decodeStr.writeByte(leaf.value);
	                btree = tree;
	            } 
	         }
		} catch (IOException e) {
			System.out.println("스트림 오류");
		}
    	if (btree != tree)  System.out.println("...garbage input");
    }
 
    public static boolean filecompare(File f1, File f2)  {
    	boolean eq = true;
        int b;
        
        if(f1.length() != f2.length()) return false;

		try {
			FileInputStream fi = new FileInputStream(f1);
			FileInputStream fj = new FileInputStream(f2);
			
			while (((b = fi.read()) != -1) && ((b=fj.read()) != -1))
				if(fi.read() != fj.read()) return false;
			
// HW11-2			
			
		} catch (IOException e) {
			System.out.println("스트림 오류");
		}

    	return eq;
    }
    
    public static void main(String[] args) {
   	    StringBuffer[] code = new  StringBuffer[256];
		String fname="", ext="", mode;
		String orgfile="";
		String encfile="";
		String resfile="";
		File org;
		File enc;
		File res;
		FileInputStream forg = null;
		FileOutputStream fenc = null;
		FileInputStream fenci = null;
		FileOutputStream fres = null;
		DataInputStream dorg = null;
		DataOutputStream denc = null;
		DataInputStream denci = null;
		DataOutputStream dres = null;
		int[] charFreqs = new int[256];
		int b;
		String inputMessage;
		BufferedReader keyin = null;
		int fsize;
		HuffmanTree tree = null;
		
		while(true)
		{
			keyin = new BufferedReader(new InputStreamReader(System.in));
			System.out.print("select mode: (1)copmress, (2)restore, (3)exit ? ");
			try {
				mode = keyin.readLine();
			} catch (IOException e) {
				System.out.print(e.getMessage());
				continue;
			} 
			if(!mode.equals("1") && !mode.equals("2") && !mode.equals("3")) continue;
			if(mode.equals("3")) System.exit(0);
			
			System.out.print("input file name ? ");  // (ex) "gulliver.txt", "Chrysanthemum.bmp"
			try {
				inputMessage = keyin.readLine();
			} catch (IOException e) {
				System.out.print(e.getMessage());
				continue;
			} 
			fname = inputMessage.substring(0, inputMessage.indexOf('.'));
			ext = inputMessage.substring(inputMessage.indexOf('.')+1, inputMessage.length());
			
			switch(mode) {
			case "1":	
				try {
					orgfile = fname + "." + ext;
					encfile = fname + ".huf";
					System.out.println("(compression) input-file=" + orgfile + "  -->>  compressed-file=" + encfile);
					org = new File(orgfile);
					enc = new File(encfile);
					forg = new FileInputStream(org);
					dorg = new DataInputStream(forg);
				
					for(int i=0; i<256; i++) code[i] = new StringBuffer();
					while((b=dorg.read()) != -1)
						charFreqs[b]++;
					tree = buildTree(charFreqs);
		        
					System.out.println("SYMBOL\tWEIGHT\tHUFFMAN CODE");
					printCodes(tree, new StringBuffer(), code);
				
					dorg.close();
					forg.close();
					
					forg = new FileInputStream(org);
					dorg = new DataInputStream(forg);
					fenc = new FileOutputStream(enc);
					denc = new DataOutputStream(fenc);
					System.out.println("original:(" + org.length() + "bytes) ");

					saveMetaFile(denc, orgfile, (int)org.length(), charFreqs);
			        
			        encode(dorg, denc, code);
					System.out.println("encoded: (" + enc.length() + "bits,compression-ratio=" + (double)enc.length()/(8*org.length()) + ") \n");
					
					dorg.close();
					forg.close();
					denc.close();
					fenc.close();  
				} catch (IOException e) {
					System.out.println("파일 복사 오류");
				}
				
				break;
				
			case "2":	
				try {
					encfile = fname + "." + ext;
					enc = new File(encfile);
			        fenci = new FileInputStream(enc);
					denci = new DataInputStream(fenci);
					
					String fileNames[]=new String[2];
					fsize = restoreMetaFile(denci, charFreqs, fileNames);
					tree = buildTree(charFreqs);
					orgfile = fileNames[0];
					resfile = fileNames[1];
					
					System.out.println("(restore) compressed-file=" + encfile + "  -->>  recovered-file=" + resfile);
					
					org = new File(orgfile);
					res = new File(resfile);
					fres = new FileOutputStream(res);
					dres = new DataOutputStream(fres);						
			        
					decode(tree, denci, dres);					
					System.out.println("decoded: (" + res.length() + "bytes) ");
					
					denci.close();
					fenci.close();   
					dres.close();
					fres.close();   
	            
					System.out.print("(compare) original-file=" + orgfile + " <--> recovered-file=" + resfile + "  ===>>> ");
			        if(filecompare(org, res))
			        	System.out.println(" uncompression success!\n");
			        else
			        	System.out.println(" uncompression failed!\n");
				} catch (IOException e) {
					System.out.println("파일 복사 오류");
				}
				
				break;
				
			}  // switch
				
		} // while()
			        
    }  // main()

}


//file compare command ==>>  fc gulliver.txt gulliver_unc.txt
//if same, answer is "다른 점이 없습니다" ("both files have the same contents")


/* (sample script)

select mode: (1)copmress, (2)restore, (3)exit ? 1
input file name ? gulliver.txt
(compression) input-file=gulliver.txt  -->>  compressed-file=gulliver.huf
SYMBOL	WEIGHT	HUFFMAN CODE
s	27817	0000
n	30535	0001
E	386	0010000000
}	97	001000000100
^	97	001000000101
O	101	001000000110
7	48	0010000001110
Q	56	0010000001111
x	820	001000001
T	826	001000010
:	215	00100001100
R	108	001000011010
?	13	001000011011000
	1	00100001101100100
!	6	00100001101100101
X	8	0010000110110011
6	29	00100001101101
4	63	0010000110111
q	444	0010000111
P	254	00100010000
0	66	0010001000100
3	66	0010001000101
|	134	001000100011
'	271	00100010010
_	274	00100010011
j	550	0010001010
D	68	0010001011000
2	68	0010001011001
G	141	001000101101
S	148	001000101110
F	149	001000101111
;	1146	001000110
C	300	00100011100
-	305	00100011101
)	155	001000111100
z	156	001000111101
M	314	00100011111
p	8259	001001
l	16297	00101
g	8323	001100
,	8439	001101
y	8867	001110

	9081	001111
a	34937	0100
o	35158	0101

	9081	011000
w	10092	011001
d	19602	01101
t	40861	0111
v	4900	1000000
k	2485	10000010
B	315	10000011000
(	156	100000110010
J	39	10000011001100
8	20	100000110011010
9	20	100000110011011
U	40	10000011001110
V	42	10000011001111
H	663	1000001101
L	164	100000111000
1	165	100000111001
N	83	1000001110100
K	85	1000001110101
W	180	100000111011
A	363	10000011110
5	87	1000001111100
{	97	1000001111101
Y	191	100000111111
f	10858	100001
c	11830	100010
u	12655	100011
.	2725	10010000
I	3202	10010001
b	6798	1001001
m	12893	100101
h	27119	10011
r	27445	10100
i	27726	10101
e	57490	1011
 	221996	11
original:(708064bytes) 
encoded: (2867989bits,compression-ratio=0.5063082221381118) 

select mode: (1)copmress, (2)restore, (3)exit ? 2
input file name ? gulliver.huf
(restore) compressed-file=gulliver.huf  -->>  recovered-file=gulliver_unc.txt
decoded: (708064bytes) 
(compare) original-file=gulliver.txt <--> recovered-file=gulliver_unc.txt  ===>>>  uncompression success!

select mode: (1)copmress, (2)restore, (3)exit ? 1

*/
