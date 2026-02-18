import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;
import java.util.StringTokenizer;

public class DistinctNumbers {

  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int n = Integer.parseInt(br.readLine().trim());

    HashSet<Integer> set = new HashSet<>(n * 2);

    StringTokenizer st = new StringTokenizer("");
    for (int i = 0; i < n; i++) {
      while (!st.hasMoreTokens()) st = new StringTokenizer(br.readLine());
      set.add(Integer.parseInt(st.nextToken()));
    }

    System.out.print(set.size());
  }

}
