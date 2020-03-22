package javaBasic;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.Stack;

class Lf{
	int ele = 0;
	int chk = 0;
	int cnt = 0;
	ArrayList<Lf> child = new ArrayList<Lf>();
	public Lf(int ele) {
		this.ele = ele;
	}
	public void add(Lf lf) {
		child.add(lf);
	}
}
class LfTree{
	int root = 0;
	Lf []arr = new Lf[501];
	
	public LfTree() {
		for(int i = 0; i < 501; i++) {
			arr[i] = new Lf(i);
		}
	}
	public int cntCd() {
		int cnt = 0;
		Stack<Lf> stk = new Stack<>();
		stk.add(arr[1]);
		while(!stk.empty()) {
			Lf temp = stk.pop();
			if(temp.chk==0) {
				temp.chk=1;
				for(Lf item : temp.child) {
					if(item.chk==0) {
						item.chk=1;
						item.cnt = temp.cnt+1;
						if(item.cnt<3) cnt++;
						if(item.cnt==1)stk.add(item);
					}
				}				
			}
		}
		return cnt;
	}
	
}
public class Test020 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		LfTree tree = new LfTree();
		int total = 0;
		ArrayList<Integer> lst = new ArrayList<>();
		int m = sc.nextInt();
		int n = sc.nextInt();
		for(int i = 0; i < n; i++) {
			int a = sc.nextInt();
			int b = sc.nextInt();
			if(a==1) {
				total++;
				lst.add(b);
				tree.arr[b].chk = 1;
			}else if(b==1) {
				total++;
				lst.add(a);
				tree.arr[a].chk = 1;
			} else {
				tree.arr[a].add(tree.arr[b]);
				tree.arr[b].add(tree.arr[a]);
			}
		}
		for(int i = 0; i < lst.size(); i++) {
			for(int j = 0; j < tree.arr[lst.get(i)].child.size(); j++) {
				if(tree.arr[lst.get(i)].child.get(j).chk==0) {
					tree.arr[lst.get(i)].child.get(j).chk=1;
					total++;
				}
			}
		}
		System.out.println(total);
	}
}
