///* array 중복제거 */

  Integer[] temp_list = new Integer[N];
  ArrayList<Integer> index_list = new ArrayList<>();

  for(int data : temp_list) { // 중복 제거, duplicated array
    if(!index_list.contains(data)) index_list.add(data);
  }

  Collections.sort(index_list); // ArrayList sort asc
  Collections.reverse(index_list); // ArrayList sort asc -> ArrayList sort desc

  index_list.get(i) == temp_list[i] 처럼 값을 가져온다

///* string을 split하는 방법 -> StringTokenizer 이용 */

  String S = scn.nextLine();
  scn.close();

  // st 에 공백을 기준으로 나눈 토큰들을 st 에 저장한다
  StringTokenizer st = new StringTokenizer(S," ");
  
  // countTokens() 는 토큰의 개수를 반환한다
  System.out.println(st.countTokens());	

///* java 에서, array의 모든 element를 N으로 초기화하고 싶다면 */

  Arrays.fill(arr, N)을 사용한다