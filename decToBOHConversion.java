import java.util.*;

class lowerUpperConversion {
    public String lowerUpperConversion(String s) {
      // 10진수 -> 2진수, 8진수, 16진수 string 변환
      int num = 77;
      String a2 = Integer.toBinaryString(num);  // 10진수 -> 2진수
      String a8= Integer.toOctalString(num);    // 10진수 -> 8진수
      String a16 = Integer.toHexString(num);    // 10진수 -> 16진수
      
      System.out.println("2 진수 : " + a2);
      System.out.println("8 진수 : " + a8);
      System.out.println("16 진수 : " + a16);
      
      // 결과
      2 진수 : 1001101
      8 진수 : 115
      16 진수 : 4d

      // 2진수, 8진수, 16진수 -> 10진수 string 변환
      int num = 77;
      String a2 = Integer.toBinaryString(num);
      String a8= Integer.toOctalString(num);
      String a16 = Integer.toHexString(num);
      
      int a2_2 = Integer.parseInt(a2, 2);
      int a8_8 = Integer.parseInt(a8, 8);
      int a16_16 = Integer.parseInt(a16, 16);
      
      System.out.println(a2_2);
      System.out.println(a8_8);
      System.out.println(a16_16);

      // 결과
      77
      77
      77
    }
}