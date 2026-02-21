import java.io.*;
import java.util.*;

public class ConcertsTickets {

  // -------- Super fast input (byte buffer) --------
  static class FastScanner {
    private final InputStream in;
    private final byte[] buffer = new byte[1 << 16]; // 64KB
    private int ptr = 0, len = 0;

    FastScanner(InputStream is) {
      in = is;
    }

    private int readByte() throws IOException {
      if (ptr >= len) {
        len = in.read(buffer);
        ptr = 0;
        if (len <= 0) return -1;
      }
      return buffer[ptr++];
    }

    int nextInt() throws IOException {
      int c;
      do {
        c = readByte();
        if (c == -1) return Integer.MIN_VALUE;
      } while (c <= ' ');

      int sign = 1;
      if (c == '-') {
        sign = -1;
        c = readByte();
      }

      int val = 0;
      while (c > ' ') {
        val = val * 10 + (c - '0');
        c = readByte();
      }
      return val * sign;
    }
  }

  public static void main(String[] args) throws Exception {
    FastScanner fs = new FastScanner(System.in);

    int n = fs.nextInt();
    int m = fs.nextInt();

    TreeMap<Integer, Integer> freq = new TreeMap<>();
    for (int i = 0; i < n; i++) {
      int p = fs.nextInt();
      freq.put(p, freq.getOrDefault(p, 0) + 1);
    }

    StringBuilder sb = new StringBuilder(m * 3);

    for (int i = 0; i < m; i++) {
      int max = fs.nextInt();
      Integer val = freq.floorKey(max);

      if (val == null) {
        sb.append("-1\n");
      } else {
        sb.append(val).append('\n');
        int c = freq.get(val);
        if (c == 1) freq.remove(val);
        else freq.put(val, c - 1);
      }
    }

    System.out.print(sb); // faster than println(toString())
  }
}
