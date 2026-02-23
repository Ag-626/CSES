import java.io.*;
import java.util.*;

public class CollectingNumbersII {

  static class FastScanner {
    private final InputStream in;
    private final byte[] buffer = new byte[1 << 16];
    private int ptr = 0, len = 0;

    FastScanner(InputStream is) { in = is; }

    int readByte() throws IOException {
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
      if (c == '-') { sign = -1; c = readByte(); }

      int val = 0;
      while (c > ' ') {
        val = val * 10 + (c - '0');
        c = readByte();
      }
      return val * sign;
    }
  }

  static int breakCount(int i, int[] pos) {
    // i in [1..n-1]
    return pos[i] > pos[i + 1] ? 1 : 0;
  }

  public static void main(String[] args) throws Exception {
    FastScanner fs = new FastScanner(System.in);
    StringBuilder out = new StringBuilder();

    int n = fs.nextInt();
    int m = fs.nextInt();

    int[] arr = new int[n + 1]; // position -> value (1-indexed)
    int[] pos = new int[n + 1]; // value -> position (1-indexed)

    for (int i = 1; i <= n; i++) {
      arr[i] = fs.nextInt();
      pos[arr[i]] = i;
    }

    int rounds = 1;
    for (int i = 1; i <= n - 1; i++) rounds += breakCount(i, pos);

    int[] cand = new int[4];

    for (int q = 0; q < m; q++) {
      int a = fs.nextInt();
      int b = fs.nextInt();

      int x = arr[a];
      int y = arr[b];

      // affected break indices
      cand[0] = x - 1;
      cand[1] = x;
      cand[2] = y - 1;
      cand[3] = y;

      Arrays.sort(cand);

      // subtract old contributions (unique + in range)
      for (int i = 0; i < 4; i++) {
        int t = cand[i];
        if (t < 1 || t > n - 1) continue;
        if (i > 0 && cand[i] == cand[i - 1]) continue;
        rounds -= breakCount(t, pos);
      }

      // swap values in positions a and b, update pos
      arr[a] = y;
      arr[b] = x;
      pos[x] = b;
      pos[y] = a;

      // add new contributions (same cand indices, now with updated pos)
      for (int i = 0; i < 4; i++) {
        int t = cand[i];
        if (t < 1 || t > n - 1) continue;
        if (i > 0 && cand[i] == cand[i - 1]) continue;
        rounds += breakCount(t, pos);
      }

      out.append(rounds).append('\n');
    }

    System.out.print(out);
  }
}
