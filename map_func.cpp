long int least_prime_div(long int val) {
	if(pr[val]==0){
		if(val==1){
			pr[val]=1;
			return 1;
		}
		for(long int i=2;i<=sqrt(val);i++){
			if(val%i==0){
				pr[val]=i;
				return i;
			}
		}
		pr[val]=val;
		return val;
	}
	else
		return pr[val];
}

