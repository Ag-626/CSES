import java.io.IOException;
import java.io.InputStream;
import java.util.HashMap;

public class SumOfTwoValues {

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
    int x = fs.nextInt();
    HashMap<Integer, Integer> freq = new HashMap<>();
    for(int i=0;i<n;i++){
      int num = fs.nextInt();
      if(freq.isEmpty()){
        freq.put(num, Integer.valueOf(i+1));
      }
      else{
        if(freq.containsKey(x-num)){
          System.out.print(freq.get(x-num)+" "+(i+1));
          return;
        }
        freq.put(num, Integer.valueOf(i+1));
      }
    }
    System.out.print("IMPOSSIBLE");
  }

}
