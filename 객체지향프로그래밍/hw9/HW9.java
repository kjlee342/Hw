import java.util.*;
 
class HCode {
    char value; // the character
    int frequency; // the frequency of this character in the sentence
    String code;
    HCode(char val, int freq, String code) { value=val; frequency = freq; this.code = code; }
    void setCode(String code) { this.code = code; }
}
 
public class HW9 {
 	 
    public static void printCodes(HCode[] hcode) {
    	for(int i=0; i<256; i++)
    	{
    		if(hcode[i].frequency==0) continue;
            System.out.println(((hcode[i].value == ' ') ? "(space)" : hcode[i].value) + "\t" + hcode[i].frequency + "\t" + hcode[i].code);
    	}
    }
 
   public static void encode(HCode hcode[], String str, StringBuffer codeStr) {
        for (char c : str.toCharArray())
        	codeStr.append(hcode[c].code);
    }
 
    public static void decode(HCode hcode[], StringBuffer codeStr, StringBuffer decodeStr) {
    	
// HW9  
    	StringBuffer temp = new StringBuffer();
    	for(int i=0; i<codeStr.length(); i++){
    		temp.append(codeStr.charAt(i));
            for (int j=0; j<256; j++){
            	if(hcode[j].frequency==0) continue;
            	if(temp.toString().equals(hcode[j].code)){
            		decodeStr.append(hcode[j].value);
            		temp = new StringBuffer();
            	}
            }
    	}
    }
 
    public static void main(String[] args) {
        String test = "this is an example for huffman encoding";
        StringBuffer codeStr = new StringBuffer();
        StringBuffer decodeStr = new StringBuffer();
        int[] charFreqs = new int[256];
        HCode hcode[] = new HCode[256];
        
        for(int i=0; i<256; i++) charFreqs[i] = 0;
        for (char c : test.toCharArray())
            charFreqs[c]++;
        
        for(int i=0; i<256; i++) hcode[i] = new HCode((char) i, charFreqs[i], "");
        
        hcode['d'].setCode("00000");
        hcode['t'].setCode("00001");
        hcode['h'].setCode("0001");
        hcode['s'].setCode("0010");
        hcode['c'].setCode("00110");
        hcode['x'].setCode("00111");
        hcode['m'].setCode("0100");
        hcode['o'].setCode("0101");
        hcode['n'].setCode("011");
        hcode['u'].setCode("10000");
        hcode['l'].setCode("10001");
        hcode['a'].setCode("1001");
        hcode['r'].setCode("10100");
        hcode['g'].setCode("101010");
        hcode['p'].setCode("101011");
        hcode['e'].setCode("1011");
        hcode['i'].setCode("1100");
        hcode['f'].setCode("1101");
        hcode[' '].setCode("111");
        
        System.out.println("SYMBOL\tWEIGHT\tHUFFMAN CODE");
        printCodes(hcode);
        
        System.out.println("original:(" + test.length() + "bytes," + (test.length() * 8) + "bits) "+ test);
        // 	original:(39bytes,312bits) this is an example for huffman encoding

        encode(hcode, test, codeStr);
        System.out.println("encoded: (" + codeStr.length() + "bits,compression-ratio=" + codeStr.length()/(8.0*test.length()) + ") " + codeStr);
        //  encoded: (157bits,compression-ratio=0.5032051282051282) 0000100011100001011111000010111100101111110110011110010100101011100011011111110101011010011100011000011011101010010010111111011011001100101000001100011101010
        
        decode(hcode, codeStr, decodeStr);
        System.out.println("decoded: (" + decodeStr.length() + "bytes) " + decodeStr);
        System.out.println("result : " + ((decodeStr.toString().equals(test)) ? "success!" : "fail"));
        // 	decoded: (39bytes) this is an example for huffman encoding
		//	result : success!

        
        /* -------------------------------------------------       
        
        SYMBOL	WEIGHT	HUFFMAN CODE
        (space)	6	111
        a	3	1001
        c	1	00110
        d	1	00000
        e	3	1011
        f	3	1101
        g	1	101010
        h	2	0001
        i	3	1100
        l	1	10001
        m	2	0100
        n	4	011
        o	2	0101
        p	1	101011
        r	1	10100
        s	2	0010
        t	1	00001
        u	1	10000
        x	1	00111
		original:(39bytes,312bits) this is an example for huffman encoding
		encoded: (157bits,compression-ratio=0.5032051282051282) 0000100011100001011111000010111100101111110110011110010100101011100011011111110101011010011100011000011011101010010010111111011011001100101000001100011101010
		decoded: (39bytes) this is an example for huffman encoding
		result : success!

        ----------------------------------------------------- */
        
        
    }
}