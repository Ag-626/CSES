import java.io.IOException;
import java.io.InputStream;

public class CollectingNumbers {

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

  public static void main(String[] args) throws Exception{
    FastScanner fs = new FastScanner(System.in);
    int n = fs.nextInt();
    int[] arr = new int[n];
    int[] indx = new int[n+1];

    for(int i=0;i<n;i++){
      arr[i]= fs.nextInt();
      indx[arr[i]]=i;
    }
    int ans=1;
    for(int i=1;i<n;i++){
      if(indx[i]>indx[i+1])
        ans++;
    }
    System.out.println(ans);
  }

}
