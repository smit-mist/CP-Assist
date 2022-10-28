package SegmentTree;

import java.io.*;
import java.util.*;


public class CircularRMQ {


	interface QueryInterface{
		public void increment(int i, int j, long val);
		public long minimum(int i, int j);
	}
	
	class SegmentTree implements QueryInterface {
		int n;
		long[] lo, hi, min, delta;
		
		public SegmentTree(int n) {
			this.n = n;
			lo = new long[4*n +1];
			hi = new long[4*n +1];
			min = new long[4*n +1];
			delta = new long[4*n +1];
			
			init(1,0,n-1);
		}
		
		public void increment(int a, int b, long val) {
			increment(1,a,b,val);
		}
		
		public long minimum(int a, int b) {
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
		
		
		void increment(int i, int a, int b, long val) {
			
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
		
		
		long minimum(int i, int a, int b) {
			if(b<lo[i] || hi[i]<a) {
				return Long.MAX_VALUE;
			}
			
			if(a<=lo[i] && hi[i]<=b) {
				return (long)min[i]+(long)delta[i];
			}
			
			prop(i);
			
			long minLeft = minimum(2*i,a,b);
			long minRight = minimum(2*i +1,a,b);
			
			update(i);
			return Math.min(minLeft, minRight);
		}
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		 MyScanner sc = new MyScanner();
		 PrintWriter pw = new PrintWriter(System.out);
		
		 CircularRMQ cm = new CircularRMQ();
		int n  = sc.nextInt();
		SegmentTree st = cm.new SegmentTree(n);
		long a[] = new long[n];
		
		for(int i = 0; i<n; i++) {
			a[i] = sc.nextLong();
			st.increment(i, i, a[i]);
		}
		
		int q = sc.nextInt();
		
		while(q-->0) {
			
			String s = sc.nextLine();
			String ss[] = s.split(" ");
			
			if(ss.length==3) {
				int l = Integer.parseInt(ss[0]);
				int r = Integer.parseInt(ss[1]);
				long val = Long.parseLong(ss[2]);
				
				if(l<=r) {
					st.increment(l, r, val);
				}
				else {
					st.increment(0, r, val);
					st.increment(l, n-1, val);
				}
				
			}
			else {
				int l = Integer.parseInt(ss[0]);
				int r = Integer.parseInt(ss[1]);
				
				if(l<=r) {
					long ans = st.minimum(l, r);
					pw.println(ans);
				}
				else {
					long ans1= st.minimum(0, r);
					long ans2 = st.minimum(l, n-1);
					long ans = Math.min(ans1, ans2);
					pw.println(ans);
				}
			}
		}
		pw.close();
		
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
