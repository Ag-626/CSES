import java.io.*;
import java.util.*;

public class Apartments {

  static class FastReader {
    private final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    private StringTokenizer st;

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

    long[] nextLongArray(int n) throws IOException {
      long[] arr = new long[n];
      for (int i = 0; i < n; i++) arr[i] = nextLong();
      return arr;
    }
  }

  public static void main(String[] args) throws Exception {
    FastReader fr = new FastReader();

    int n = fr.nextInt();
    int m = fr.nextInt();
    long k = fr.nextLong();

    long[] applicants = fr.nextLongArray(n);
    long[] apartments = fr.nextLongArray(m);

    Arrays.sort(applicants);
    Arrays.sort(apartments);

    int i = 0, j = 0;
    int matches = 0;

    while (i < n && j < m) {
      long a = applicants[i];
      long b = apartments[j];

      if (b < a - k) {
        // apartment too small
        j++;
      } else if (b > a + k) {
        // apartment too large (try next applicant)
        i++;
      } else {
        // within range -> match
        matches++;
        i++;
        j++;
      }
    }

    System.out.println(matches);
  }
}
