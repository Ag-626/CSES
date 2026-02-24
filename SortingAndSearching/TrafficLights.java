import java.io.*;
import java.util.*;

public class TrafficLights {

  // -------------------- Fast IO --------------------
  static class FastScanner {
    private final InputStream in;
    private final byte[] buffer = new byte[1 << 16];
    private int ptr = 0, len = 0;

    FastScanner(InputStream is) { in = is; }

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
      if (c == '-') { sign = -1; c = readByte(); }

      int val = 0;
      while (c > ' ') {
        val = val * 10 + (c - '0');
        c = readByte();
      }
      return val * sign;
    }
  }

  static class FastOutput {
    private final OutputStream out;
    private final byte[] buf = new byte[1 << 16];
    private int ptr = 0;

    FastOutput(OutputStream os) { out = os; }

    void writeByte(int b) throws IOException {
      if (ptr == buf.length) flush();
      buf[ptr++] = (byte) b;
    }

    void writeInt(int x) throws IOException {
      if (x == 0) { writeByte('0'); return; }
      int n = x;
      if (n < 0) { writeByte('-'); n = -n; }
      int start = ptr;
      while (n > 0) {
        int d = n % 10;
        writeByte('0' + d);
        n /= 10;
      }
      // reverse digits written
      for (int i = start, j = ptr - 1; i < j; i++, j--) {
        byte tmp = buf[i];
        buf[i] = buf[j];
        buf[j] = tmp;
      }
    }

    void flush() throws IOException {
      out.write(buf, 0, ptr);
      ptr = 0;
    }
  }

  // -------------------- RNG --------------------
  static final class XorShift {
    private int x = 0x9E3779B9;
    int next() {
      x ^= (x << 13);
      x ^= (x >>> 17);
      x ^= (x << 5);
      return x;
    }
  }
  static final XorShift RNG = new XorShift();

  // -------------------- Treap Set (unique keys) --------------------
  static final class TreapSet {
    static final class Node {
      int key, pr;
      Node l, r;
      Node(int key) { this.key = key; this.pr = RNG.next(); }
    }

    Node root;

    boolean contains(int key) {
      Node cur = root;
      while (cur != null) {
        if (key == cur.key) return true;
        cur = (key < cur.key) ? cur.l : cur.r;
      }
      return false;
    }

    void insert(int key) {
      if (contains(key)) return;
      root = insert(root, new Node(key));
    }

    private Node insert(Node t, Node it) {
      if (t == null) return it;
      if (it.pr > t.pr) {
        NodePair sp = split(t, it.key);
        it.l = sp.a;
        it.r = sp.b;
        return it;
      }
      if (it.key < t.key) t.l = insert(t.l, it);
      else t.r = insert(t.r, it);
      return t;
    }

    // split by key: left has keys < key, right has keys >= key
    private NodePair split(Node t, int key) {
      if (t == null) return new NodePair(null, null);
      if (key <= t.key) {
        NodePair sp = split(t.l, key);
        t.l = sp.b;
        sp.b = t;
        return sp;
      } else {
        NodePair sp = split(t.r, key);
        t.r = sp.a;
        sp.a = t;
        return sp;
      }
    }

    static final class NodePair {
      Node a, b;
      NodePair(Node a, Node b) { this.a = a; this.b = b; }
    }

    // predecessor (max < key). Assumes exists.
    int lower(int key) {
      Node cur = root;
      int ans = Integer.MIN_VALUE;
      while (cur != null) {
        if (cur.key < key) {
          ans = cur.key;
          cur = cur.r;
        } else cur = cur.l;
      }
      return ans;
    }

    // successor (min > key). Assumes exists.
    int higher(int key) {
      Node cur = root;
      int ans = Integer.MAX_VALUE;
      while (cur != null) {
        if (cur.key > key) {
          ans = cur.key;
          cur = cur.l;
        } else cur = cur.r;
      }
      return ans;
    }
  }

  // -------------------- Treap Multiset (counts + max) --------------------
  static final class TreapMulti {
    static final class Node {
      int key, pr, cnt;
      Node l, r;
      Node(int key) { this.key = key; this.pr = RNG.next(); this.cnt = 1; }
    }

    Node root;

    void add(int key) { root = add(root, key); }

    private Node add(Node t, int key) {
      if (t == null) return new Node(key);
      if (key == t.key) { t.cnt++; return t; }
      if (t.pr < RNG.x) { /* no-op; keep compiler from being too clever */ }
      if (key < t.key) t.l = add(t.l, key);
      else t.r = add(t.r, key);
      // heap property fix via rotations
      if (key < t.key && t.l != null && t.l.pr > t.pr) t = rotR(t);
      else if (key > t.key && t.r != null && t.r.pr > t.pr) t = rotL(t);
      return t;
    }

    void remove(int key) { root = remove(root, key); }

    private Node remove(Node t, int key) {
      if (t == null) return null;
      if (key == t.key) {
        if (t.cnt > 1) { t.cnt--; return t; }
        return merge(t.l, t.r);
      }
      if (key < t.key) t.l = remove(t.l, key);
      else t.r = remove(t.r, key);
      return t;
    }

    int maxKey() {
      Node cur = root;
      while (cur.r != null) cur = cur.r;
      return cur.key;
    }

    private Node merge(Node a, Node b) {
      if (a == null) return b;
      if (b == null) return a;
      if (a.pr > b.pr) {
        a.r = merge(a.r, b);
        return a;
      } else {
        b.l = merge(a, b.l);
        return b;
      }
    }

    private Node rotR(Node t) {
      Node x = t.l;
      t.l = x.r;
      x.r = t;
      return x;
    }

    private Node rotL(Node t) {
      Node x = t.r;
      t.r = x.l;
      x.l = t;
      return x;
    }
  }

  // -------------------- Main --------------------
  public static void main(String[] args) throws Exception {
    FastScanner fs = new FastScanner(System.in);
    FastOutput fo = new FastOutput(System.out);

    int x = fs.nextInt();
    int n = fs.nextInt();

    TreapSet positions = new TreapSet();
    TreapMulti lengths = new TreapMulti();

    positions.insert(0);
    positions.insert(x);
    lengths.add(x);

    for (int i = 0; i < n; i++) {
      int p = fs.nextInt();

      int lo = positions.lower(p);
      int hi = positions.higher(p);

      // remove old segment, add two new ones
      lengths.remove(hi - lo);
      lengths.add(p - lo);
      lengths.add(hi - p);

      positions.insert(p);

      if (i > 0) fo.writeByte(' ');
      fo.writeInt(lengths.maxKey());
    }

    fo.flush();
  }
}
