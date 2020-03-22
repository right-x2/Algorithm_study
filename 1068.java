package javaBasic;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.Stack;

class Lf{
	int element;
	Lf prt = null;
	int cnt = 0;
	ArrayList<Lf> child = new ArrayList<Lf>();
	public Lf(int ele) {
		element = ele;
	}
	public void add(Lf lf) {
		child.add(lf);
	}
	public void remove(int ele) {
		int idx = 0;
		for(Lf item: child) {
			if(item.element==ele) {
				break;
			}
			idx++;
		}
		child.remove(idx);
	}
}
class LfTree{
	int root = 0;
	Lf []arr = new Lf[52];
	
	public LfTree() {
		for(int i = 0; i < 52; i++) {
			arr[i] = new Lf(0);
		}
	}
	public int cntCd() {
		int cnt = 0;
		Stack<Lf> stk = new Stack<>();
		stk.add(arr[root]);
		while(!stk.empty()) {
			Lf temp = stk.pop();
			if(temp.child.size()==0) cnt++;
			for(Lf item : temp.child) {
				stk.add(item);
			}
		}
		return cnt;
	}
	
}
public class Test020 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		LfTree tree = new LfTree();
		int n = sc.nextInt();
		int total = 0;
		for(int i = 0; i < n; i++) {
			int prt = sc.nextInt();
			if(prt==-1) {
				tree.arr[i].element = i;
				tree.root = i;
			}
			else {
				tree.arr[i].element = i;
				tree.arr[prt].add(tree.arr[i]);
				tree.arr[i].prt = tree.arr[prt];
			}
		}
		int rm = sc.nextInt();
		if(tree.arr[rm].prt==null)System.out.println(0);
		else {
			tree.arr[rm].prt.remove(rm);
			System.out.println(tree.cntCd());		
		}
	}
}
