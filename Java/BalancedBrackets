public static boolean checkBalanced(String exp) {
      Stack<Character> st = new Stack<>();
      for(int i=0;i<exp.length();i++){
        if(exp.charAt(i)=='{'|| exp.charAt(i)=='['|| exp.charAt(i)=='('){
          st.push(exp.charAt(i));
        }
        if(exp.charAt(i)=='}'|| exp.charAt(i)==']'|| exp.charAt(i)==')'){
          if(st.isEmpty()){
            return false;
          }
          else if(!condition(st.pop(),exp.charAt(i))){
            return false;
          }
        }}
        if(st.isEmpty()){
          return true;
        }
                  else{
                    return false;
                  }
            
	}
    public static Boolean condition(char c1,char c2){
      if(c1=='{' && c2=='}'){
        return true;
      }
       if(c1=='(' && c2==')'){
        return true;}
          if(c1=='[' && c2==']'){
        return true;}
    return false;
	    
}
