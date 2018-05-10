
public class HW7_2 {
	static class CPoint{
		public int x,y;
		public String s="";
		public CPoint(int x, int y){
			this.x = x;
			this.y = y;
		}
		void show(){
			System.out.println("("+x+","+y+")"+s);
		}
		
		public String toString(){
			return ("("+x+","+y+")입니다.");
		}
	}
	
	static class CColorPoint extends CPoint{
		CColorPoint(int x, int y, String s) {
			super(x, y);
			this.s = s;
		}
	}

	public static void main (String args[]) {
		CPoint a,b;
		a = new CPoint(1,2);
		b = new CColorPoint(3,4,"red");
		a.show();
		b.show();
		System.out.println(a);
		System.out.println(b);
	}
}
