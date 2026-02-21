import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;

public class StickLengths {

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

    Arrays.sort(arr);
    int num = arr[n/2];
    long ans=0;
    for(int i=0;i<n;i++){
      ans+=Math.abs(arr[i]-num);
    }
    System.out.print(ans);
  }
}
