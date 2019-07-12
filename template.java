
/*

*/
import java.math.*;
import java.io.*;

class b
{
    private static final BufferedReader buf =
            new BufferedReader(new InputStreamReader(System.in));

    public static void println(Object ...args){
        System.out.println(args);
    }

    public static void main(String args[]) throws IOException {
        int T = Integer.parseInt(buf.readLine());
        while(T-- > 0){
            long N = Long.parseLong(buf.readLine());
            BigInteger a = new BigInteger(buf.readLine());
            BigInteger b[] = a.divideAndRemainder(BigInteger.valueOf(N));
            long r = b[1].longValue();
            if(N > r*2){
                println(r*2);
            } else if(N == r*2){
                println(r*2-1);
            } else{
                println((N-r)*2);
            }
        }
    }
}
