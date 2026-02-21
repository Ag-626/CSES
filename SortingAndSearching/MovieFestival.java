import java.io.IOException;
import java.io.InputStream;
import java.util.Arrays;
import java.util.Comparator;

public class MovieFestival {

  static class FastScanner{
    private final InputStream in;
    private final byte[] buffer = new byte[1<<16];
    private int ptr=0;
    private int len=0;

    FastScanner(InputStream is){
      in=is;
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
        val = val*10 + (c-'0');
        c=readByte();
      }
      val=val*sign;
      return val;
    }

  }

  static class MovieTime{
    int sTime;
    int eTime;

    MovieTime(int sTime, int eTime){
      this.sTime = sTime;
      this.eTime = eTime;
    }
  }

  public static void main(String[] args) throws Exception{
    FastScanner fs = new FastScanner(System.in);

    int n = fs.nextInt();

    MovieTime[] movieTime = new MovieTime[n];

    for(int i=0;i<n;i++){
      int s = fs.nextInt();
      int e = fs.nextInt();
      movieTime[i] = new MovieTime(s, e);
    }

    Arrays.sort(movieTime, new Comparator<MovieTime>() {
      @Override
      public int compare(MovieTime o1, MovieTime o2) {
        if(o1.eTime != o2.eTime)
          return Integer.compare(o1.eTime, o2.eTime);
        return Integer.compare(o1.sTime, o2.sTime);
      }
    });

    int ans=0;
    int eTime=-1;
    for(int i=0;i<n;i++){
      if(movieTime[i].sTime>=eTime){
        ans++;
        eTime=movieTime[i].eTime;
      }
    }
    System.out.print(ans);

  }
}
