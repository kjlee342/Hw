public class Rectangle {
	private int x1, x2, y1, y2;
	
	Rectangle(){
		this(0,0,0,0);
	}
	
	Rectangle(int x1, int y1, int x2, int y2) {
		this.x1 = x1;
		this.y1 = y1;
		this.x2 = x2;
		this.y2 = y2;
	}

	public void set(int x1, int y1, int x2, int y2) {
		this.x1 = x1;
		this.y1 = y1;
		this.x2 = x2;
		this.y2 = y2;
	}
	
	public int square() {
		int size = (x2-x1) * (y2-y1); // 면적 계산
		if (size <0)
			size = -size; // 면적이 음수인 경우 양수로 만들어 줌
		return size;
	}
	public void show() {
		System.out.print("사각형의 좌표는 (");
		System.out.print(x1 + "," + y1 + "), (");
		System.out.println(x2 + "," + y2 + ")입니다.");
	}
	public boolean equals(Rectangle x) {
		int width1 = Math.abs(x.x2 - x.x1); // x의 가로 길이
		int width2 = Math.abs(this.x2 - this.x1); // this의 가로 길이
		int height1 = Math.abs(x.y2 - x.y1); // x의 세로 길이
		int height2 = Math.abs(this.y2 - this.y1); // this의 세로 길이
		
		if (width1 == width2 && height1 == height2)
			return true;
		return false;
	}
}
