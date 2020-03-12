package javaBasic;
import java.util.ArrayList;
import java.util.Scanner;

class Shark{
	int a;
	int b;
	int speed;
	int direction;
	int size;
	boolean live;
	
	public Shark(int speed, int direction,int size,int a, int b) {
		this.speed= speed;
		this.direction = direction;
		this.size = size;
		this.a = a;
		this.b = b;
		live = true;
	}
	
	public Shark move(Shark arr[][],int r,int c) {
		arr[a][b] = null;
		int spd = speed;
		int cnt = 0;
		while(true) {
			if(direction==1) {
				if(cnt ==0) {
					a = a -speed;
					cnt = 1;
				} else {
					a = r-a;
				}
				if(a>=1) {
					return new Shark(spd,direction,size,a,b);
				}else {
					a = -1*(a-2);
					direction=2;
				}
			} else if(direction==2) {
				if(cnt ==0) {
					a = a +speed;
					cnt = 1;
				} 
				if(a<=r) {
					return new Shark(spd,direction,size,a,b);
				}else {
					a = a - r;
					direction=1;
				}
				
			} else if(direction==3) {
				if(cnt ==0) {
					b = b +speed;
					cnt = 1;
				} 
				if(b<=c) {
					return new Shark(spd,direction,size,a,b);
				}else {
					b = b - c;
					direction=4;
				}			
			} else {
				if(cnt ==0) {
					b = b -speed;
					cnt = 1;
				} else {
					b = c-b;
				}
				if(b>=1) {
					return new Shark(spd,direction,size,a,b);
				}else {
					b = -1*(b-2);
					direction=3;
				}			
			}
		}
	}
	
}
public class Test17143 {
	public static void main(String[] args) {
		int answer = 0;
		Scanner sc = new Scanner(System.in);
		Shark[][] arr = new Shark[101][101];
		ArrayList<Shark> list = new ArrayList<>();
		Shark temp;
		int r = sc.nextInt();
		int c = sc.nextInt();
		int m = sc.nextInt();
		
		for(int i = 0; i < m; i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			int speed = sc.nextInt();
			int direction = sc.nextInt();
			int size = sc.nextInt();
			temp = new Shark(speed,direction,size,a,b);
			arr[a][b] = temp;
			list.add(temp);
		}
		for(int i = 1; i <= c; i++) {
			for(int j = 1; j <=r; j++) {
				if(arr[j][i]!=null&&arr[j][i].live==true) {
					answer = answer + arr[j][i].size;
					arr[j][i].live = false;
					arr[j][i] = null;
					break;
				}
			}
			for(int j = 0; j < list.size(); j++) {
				temp = list.get(j);
				if(temp.live==false){
				} else {
					temp = temp.move(arr,r,c);
					list.set(j, temp);
				}
			}
			for(int j = 0; j < list.size(); j++) {
				temp = list.get(j);
				if(temp.live==true&&arr[temp.a][temp.b]==null) {
					arr[temp.a][temp.b] = temp;
				} else if(temp.live==true){
					if(temp.size>arr[temp.a][temp.b].size) {
						arr[temp.a][temp.b].live = false;
						arr[temp.a][temp.b] = temp;
					} else {
						temp.live=false;
					}
				}
			}
		}
		System.out.println(answer);
	}	
}
