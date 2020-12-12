import java.util.*;

class Map {
  public void Map() {
    Map<String, String> map = new HashMap<String, String>();
    map.put("a", "aaa");
    map.put("b", "bbb");
    map.put("c", "ccc");
    
    // 방법1)
    for ( String key : map.keySet() ) {
        System.out.println("방법1) key : " + key +" / value : " + map.get(key));
    }
    System.out.println("=======================");
    
    // 방법2)
    for ( Map.Entry<String, String> entry : map.entrySet() ) {
        System.out.println("방법2) key : " + entry.getKey() +" / value : " + entry.getKey());
    }
    System.out.println("=======================");
    
    // 방법3)
    Iterator<String> keys = map.keySet().iterator();
    while ( keys.hasNext() ) {
        String key = keys.next();
        System.out.println("방법3) key : " + key +" / value : " + map.get(key));
    }

    // 결과
    방법1) key : b / value : bbb
    방법1) key : c / value : ccc
    방법1) key : a / value : aaa
    ============================
    방법2) key : b / value : b
    방법2) key : c / value : c
    방법2) key : a / value : a
    ============================
    방법3) key : b / value : bbb
    방법3) key : c / value : ccc
    방법3) key : a / value : aaa
  }
}