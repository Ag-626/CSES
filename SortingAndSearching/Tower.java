import java.io.IOException;
import java.io.InputStream;
import java.util.HashSet;
import java.util.Set;
import java.util.TreeMap;
import java.util.TreeSet;

public class Tower {
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

  private static int check(int[] tower, int n){
    TreeMap<Integer, Integer> tow = new TreeMap<>();
    int cnt=0;
    for(int i=0;i<n;i++){
      if(tow.isEmpty()){
        tow.put(tower[i], 1);
        cnt++;
      }else{
        Integer justGreater = tow.higherKey(tower[i]);
        if(justGreater==null){
          tow.put(tower[i], tow.getOrDefault(tower[i], 0)+1);
          cnt++;
        }
        else{
          if(tow.get(justGreater)==1)
          tow.remove(justGreater);
          else
            tow.put(justGreater, tow.get(justGreater)-1);
          tow.put(tower[i], tow.getOrDefault(tower[i], 0)+1);
        }
      }
    }
    return cnt;
  }

  public static void main(String[] args) throws IOException{
    FastScanner fs = new FastScanner(System.in);

    int n = fs.nextInt();
    int[] tower = new int[n];

    for(int i=0;i<n;i++){
      tower[i]= fs.nextInt();
    }

    int ans = check(tower, n);
    System.out.println(ans);
  }
}
