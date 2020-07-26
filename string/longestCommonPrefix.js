function sid(A){
       var minLength = A[0].length;
       var solution = A[0];
       for(var i=1;i<A.length;i++){
           if(minLength > A[i].length){
               minLength = A[i].length;
               solution = A[i];
           }
       }
       for(var i=0;i<A.length;i++){

           if(solution.length == 0){
               return solution;
           }

           if(solution != A[i].substring(0,solution.length)){
               solution = solution.substring(0,solution.length - 1);
               i--;
           }

       }

       return solution;
   }
sid([ "abcd", "aze" ]);
