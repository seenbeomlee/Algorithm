// Array -> List
String[] strArray = {"a", "b", "c"};
ArrayList<String> strList = new ArrayList<String>(Arrays.asList(strArray));
 
System.out.println(strList);

///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////
// List -> Array
List<String> strList = new ArrayList<String>();
strList.add("a");
strList.add("b");
strList.add("c");
 
String[] strArray = strList.toArray(new String[strList.size()]);
System.out.println(Arrays.toString(strArray));
