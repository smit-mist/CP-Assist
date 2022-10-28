package SegmentTree;

import java.io.*;
import java.util.*;


public class objectSegmentTree {

	
	static class segTree{
		
		int left,right;
		segTree lchild,rchild;
		long sum;
		
		public segTree(int left, int right, int a[]) {
			
			this.left = left;
			this.right= right;
			
			if(left==right) {
				sum =a[left];
			}
			else {
				int mid = left + (right-left)/2;
				
				lchild = new segTree(left,mid,a);
				rchild = new segTree(mid+1,right,a);
				calSum();
			}
		}
		
		public void calSum() {
			if(left==right) {
				return;
			}
			sum = lchild.sum+rchild.sum;
		}
		
		public void pointUpdate(int index, int val) {
			if(left==right) {
				sum = val;
				return;
			}
			
			if(index<=lchild.right) {
				lchild.pointUpdate(index,val);
			}
			else {
				rchild.pointUpdate(index,val);
			}
			calSum();
		}
		
		public long rangeQuery(int l, int r) {
			// Completely Disjoint 
			if(l>right || r<left) {
				return 0;
			}
			
			// I am completely within the queried range l r
			if(left>=l && right<=r) {
				return sum;
			}
			
			// We dont know , it intersects ?
			return lchild.rangeQuery(l, r)+rchild.rangeQuery(l, r);
		}
	}
	
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
