import java.io.IOException;
import java.io.InputStream;
import java.util.HashSet;

public class Playlist {
  static class FastScanner{
    private final InputStream in;
    private final byte[] buffer = new byte[1<<16];
    private int ptr;
    private int len;

    FastScanner(InputStream is){
      in = is;
    }

    int readByte() throws IOException {
      if(ptr>=len){
        len = in.read(buffer);
        ptr=0;
        if(len<=0)
          return -1;
      }
      return buffer[ptr++];
    }

    int nextInt() throws IOException{
      int c;
      do{
        c=readByte();
        if(c==-1)
          return Integer.MIN_VALUE;
      }while(c<=' ');

      int sign=1;
      if(c=='-'){
        sign=-1;
        c=readByte();
      }
      int val=0;
      while(c>' '){
        val=val*10 + (c-'0');
        c=readByte();
      }
      return val*sign;
    }
  }

  public static void main(String[] args) throws IOException{
    FastScanner fs = new FastScanner(System.in);
    int n = fs.nextInt();
    int[] arr = new int[n];

    for(int i=0;i<n;i++){
      arr[i]= fs.nextInt();
    }
    HashSet<Integer> val = new HashSet<>();

    int l=0;
    int r=-1;
    int ans=0;
    while(l<n){
      while(((r+1)<n) && ((val.isEmpty()) || (!val.contains(arr[r+1])))){
        r++;
        val.add(arr[r]);
      }
      ans=Math.max(ans, r-l+1);
      if(l<=r){
        val.remove(arr[l]);
        l++;
      }
      else{
        l++;
        r=l-1;
      }
    }
    System.out.print(ans);
  }

}
