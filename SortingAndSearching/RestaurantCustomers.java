import java.io.IOException;
import java.io.InputStream;
import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.Comparator;

public class RestaurantCustomers {

  static class FastScanner{
    private final InputStream in;
    private final byte[] buffer = new byte[1<<16];
    private int ptr=0;
    private int len=0;

    FastScanner(InputStream is){
      in = is;
    }

    private int readByte() throws IOException{
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
        c = readByte();
        if(c==-1)
          return Integer.MIN_VALUE;
      }while (c<=' ');

      int sign=1;
      if(c=='-'){
        sign=-1;
        c=readByte();
      }
      int val=0;
      while(c>' '){
        val = val*10 + (c - '0');
        c=readByte();
      }
      return val*sign;
    }
  }

  record Pair(int first, int second){}

  public static void main(String[] args) throws Exception{
    FastScanner fs = new FastScanner(System.in);

    int n = fs.nextInt();
    Pair[] seTime = new Pair[2*n];
    int k=0;
    for(int i=0;i<n;i++){
      for(int j=0;j<2;j++){
        int num = fs.nextInt();
        if(j==1){
          seTime[k++]=new Pair(num, -1);
        }
        else{
          seTime[k++]=new Pair(num, 1);
        }
      }
    }
    Arrays.sort(seTime, Comparator.comparingInt(Pair::first).thenComparingInt(Pair::second));
    int ans=0;
    int val=0;
    for(int i=0;i<2*n;i++){
      if(seTime[i].second==-1)
        val--;
      else
        val++;
      ans=Math.max(ans, val);
    }
    System.out.print(ans);
  }

}
