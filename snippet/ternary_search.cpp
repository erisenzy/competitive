int ternary_search(int from, int to){
    for(;to - from > 1;){
        int mid = (from + to) / 2;
        if(judge(mid) - judge(mid - 1)) from = mid;
        else to = mid;
    }
    return from;
}

double ternary_search(double l, double r, int iter){  
  for(int i=0;i<iter;i++){  
    if(judge((l * 2 + r) / 3) > judge((l + r * 2) / 3))  
      r = (l + r * 2 ) / 3;  
    else  
      l = (l * 2 + r) / 3;  
  }  
  return (l + r) / 2;
} 
