package SegmentTree;
import java.io.*;
import java.util.*;


public class segmentTreeAlgoLive {

	interface QueryInterface{
		public void increment(int i, int j, int val);
		public int minimum(int i, int j);
	}
	
	class RangeSlow implements QueryInterface {
		int a[];
		
		public RangeSlow(int n) {
			a = new int[n];
		}
		
		public void increment(int i, int j, int val) {
			for(int k = i; k<=j; k++) {
				a[k]+=val;
			}
		}
		public int minimum(int i, int j) {
			int res = a[i];
			for(int k = i+1; k<=j; k++) {
				res = Math.min(res, a[k]);
			}
			return res;
		}
	}
	
	class SegmentTree implements QueryInterface {
		int n;
		int[] lo, hi, min, delta;
		
		public SegmentTree(int n) {
			this.n = n;
			lo = new int[4*n +1];
			hi = new int[4*n +1];
			min = new int[4*n +1];
			delta = new int[4*n +1];
			
			init(1,0,n-1);
		}
		
		public void increment(int a, int b, int val) {
			increment(1,a,b,val);
		}
		
		public int minimum(int a, int b) {
			return minimum(1,a,b);
		}
		
		void init(int i, int a, int b) {
			lo[i] = a;
			hi[i] = b;
			
			if(a==b) {
				return;
			}
			
			int m = (a+b)/2;
			init(2*i,a,m);
			init(2*i + 1, m+1, b);
		}
		
		void prop(int i) {
			delta[2*i] += delta[i];
			delta[2*i +1] += delta[i];
			delta[i] = 0;
		}
		
		void update(int i) {
			min[i]= Math.min(min[2*i]+delta[2*i], min[2*i+1]+delta[2*i+1]);
		}
		
		
		void increment(int i, int a, int b, int val) {
			
			// completely outside
			if(b<lo[i] || hi[i]<a) {
				return;
			}
			
			// we are completely inside the asked range
			if(a<=lo[i] && hi[i]<=b) {
				delta[i]+=val;
				return;
			}
			
			// Overlapping partially
			prop(i);
			
			increment(2*i,a,b,val);
			increment(2*i+1,a,b,val);
			
			update(i);
		}
		
		
		int minimum(int i, int a, int b) {
			if(b<lo[i] || hi[i]<a) {
				return Integer.MAX_VALUE;
			}
			
			if(a<=lo[i] && hi[i]<=b) {
				return min[i]+delta[i];
			}
			
			prop(i);
			
			int minLeft = minimum(2*i,a,b);
			int minRight = minimum(2*i +1,a,b);
			
			update(i);
			return Math.min(minLeft, minRight);
		}
	}
	public static void main(String[] args) {

		
	}
	
	public static class MyScanner {
		BufferedReader br;
		StringTokenizer st;

		public MyScanner() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() {
			return Integer.parseInt(next());
		}

		long nextLong() {
			return Long.parseLong(next());
		}

		double nextDouble() {
			return Double.parseDouble(next());
		}

		String nextLine() {
			String str = "";
			try {
				str = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}
	}

}
