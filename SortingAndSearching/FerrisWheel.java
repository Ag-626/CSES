import java.io.*;
import java.util.*;

public class FerrisWheel {

  // ---------- FastReader ----------
  static class FastReader {
    private final BufferedReader br;
    private StringTokenizer st;

    FastReader() {
      br = new BufferedReader(new InputStreamReader(System.in));
    }

    String next() throws IOException {
      while (st == null || !st.hasMoreTokens()) {
        String line = br.readLine();
        if (line == null) return null;
        st = new StringTokenizer(line);
      }
      return st.nextToken();
    }

    int nextInt() throws IOException {
      String s = next();
      if (s == null) throw new EOFException("Unexpected end of input");
      return Integer.parseInt(s);
    }

    long nextLong() throws IOException {
      String s = next();
      if (s == null) throw new EOFException("Unexpected end of input");
      return Long.parseLong(s);
    }

    ArrayList<Long> nextLongArrayList(int n) throws IOException {
      ArrayList<Long> list = new ArrayList<>(n);
      for (int i = 0; i < n; i++) list.add(nextLong());
      return list;
    }
  }

  public static void main(String[] args) throws Exception {
    FastReader fr = new FastReader();

    int n = fr.nextInt();
    int x = fr.nextInt();
    ArrayList<Long> weight = fr.nextLongArrayList(n);

    Collections.sort(weight);
    int ans=0;
    int left=0;
    int right=n-1;
    while(left<=right){
      ans++;
      if((weight.get(left)+weight.get(right))<=x){
        left++;
      }
      right--;
    }

    System.out.println(ans);
  }
}
