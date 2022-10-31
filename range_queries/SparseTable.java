package RangeQueries;

import java.io.*;
import java.util.*;


// If you find it difficult in understanding the code

// Read this : http://adilet.org/blog/sparse-table/

// This blog helped me write this code. Great Blog.

public class SparseTable {

	static int st[][] = new int[25][500000];
	static int log2[] = new int[500000];
	
	static MyScanner sc = new MyScanner();
	
	public static void main(String[] args) {

		
		
	}
	
	static void buildTable(int a[]) {
		
		int n = a.length;
		
		for(int i = 0; i<=log2[n]; i++) {
			
			int curLen = 1<<i;
			
				for(int j = 0; j+curLen<=n; j++) {
					
					if(curLen==1) {
						st[i][j] = a[j];
					}
					else {
					st[i][j] = Math.min(st[i-1][j], st[i-1][j+(curLen/2)]);
					}
				}
		}
	}
	
	static int ansQuery(int l , int r) {
		
		int qLen = r-l+1;
		int pow = log2[qLen];
		int pLen = (1<<pow);
		
		int ans = Math.min(st[pow][l], st[pow][r-pLen+ 1]);
		
		return ans;
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
