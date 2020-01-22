public String getHint(String secret, String guess) {
        int[] bucket = new int[10];
        int bull = 0;
        int cow = 0;
        for(int i=0;i<secret.length();i++){
            if(secret.charAt(i)== guess.charAt(i)){
                bull++;
                continue;
            }
            bucket[secret.charAt(i) - '0'] += 1;
            bucket[guess.charAt(i) - '0'] -= 1;

        }
        //计算bucket中正值的个数
        for(int i=0;i<10;i++){
            if(bucket[i] > 0)
                cow+= bucket[i];
        }
        
        cow = secret.length() - cow - bull;
        String res = bull + "A" + cow + "B";
        return res;
    }